/*************************************************************
 *                  !!!!!IMPORTANT!!!!!                      *
 *                                                           *
 * Due to the complexity of the following code, whenever you *
 * modify it, ensure that you updated the comments according *
 * to your change too! Otherwise, the code might become      *
 * unmaintainable due to the sheere complexity going on!     *
 *************************************************************/

#include "parser.hpp"
#include "../logging/logger.hpp"

namespace msgs
{
    class syntax_error_generic : yaoosl::logging::message
    {
    public:
        syntax_error_generic(yaoosl::logging::position position) :
            yaoosl::logging::message(yaoosl::logging::severity::error, position) {}
        virtual std::string get_message() const
        {
            using namespace std::string_literals;
            return "Syntax Error"s;
        }
    };
}

constexpr yaoosl::compiler::parser::p_conversion_mod operator|(const yaoosl::compiler::parser::p_conversion_mod l, const yaoosl::compiler::parser::p_conversion_mod r) { return static_cast<yaoosl::compiler::parser::p_conversion_mod>(static_cast<uint8_t>(l) | static_cast<uint8_t>(r)); }
constexpr yaoosl::compiler::parser::p_conversion_mod operator&(const yaoosl::compiler::parser::p_conversion_mod l, const yaoosl::compiler::parser::p_conversion_mod r) { return static_cast<yaoosl::compiler::parser::p_conversion_mod>(static_cast<uint8_t>(l) & static_cast<uint8_t>(r)); }


yaoosl::logging::position to_position(yaoosl::compiler::tokenizer::token t)
{
    return { t.line, t.column, t.offset, t.contents.length(), t.path };
}

std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_start(bool require)
{
    return p_file_statements(require);
}

// p_code_statements = { p_conversion(false) | p_using ";" | p_if_else | p_for | p_try_catch_finally | p_while | p_switch | p_statements ";" | p_scope | p_value ";" | L_IDENT ":" | ";" }
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_code_statements(bool require, bool allow_instance)
{
    bool flag = false;
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_code_statements;
    // Parse nodes until we can no longer parse nodes
    do
    {
        auto __mark = mark();
        std::optional<cstnode> tmp;
        if ((tmp = p_conversion(false, p_conversion_mod::f_force_local)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_using(false)).has_value())
        {
            /* s_semicolon is required after using.                       *
             * However, this is a weak error and we can continue parsing. */
            if (look_ahead_token().type != tokenizer::etoken::s_semicolon)
            { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); }
            else { next_token(); }
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_if_else(false, allow_instance)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_for(false, allow_instance)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_try_catch_finally(false, allow_instance)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_while(false, allow_instance)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_switch(false, allow_instance)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_statements(false, allow_instance)).has_value())
        {
            /* s_semicolon is required after p_statements.                *
             * However, this is a weak error and we can continue parsing. */
            if (look_ahead_token().type != tokenizer::etoken::s_semicolon)
            { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); }
            else { next_token(); }
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_scope(false, allow_instance)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_value(false, allow_instance)).has_value())
        {
            /* s_semicolon is required after p_value.                     *
             * However, this is a weak error and we can continue parsing. */
            if (look_ahead_token().type != tokenizer::etoken::s_semicolon)
            { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); }
            else { next_token(); }
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if (look_ahead_token(1).type == tokenizer::etoken::l_ident && look_ahead_token(2).type == tokenizer::etoken::s_colon)
        {
            cstnode cur = { next_token() };
            cur.type = cstnode::kind::s_label;
            self_node.nodes.push_back(cur); // Consume L_IDENT
            next_token(); // Consume s_colon
            flag = true;
        }
        else if (look_ahead_token().type == tokenizer::etoken::s_semicolon)
        {
            next_token();
        }
        else if (!flag)
        {
            if (require)
            {
                log(msgs::syntax_error_generic(to_position(current_token())));
            }
            __mark.rollback();
            break;
        }
    } while (true);
    return flag ? self_node : std::optional<cstnode>();
}

// p_statements = { "break" | "continue" | "return" [ p_value ] | "throw" [ p_value ] | "delete" p_value | "goto" ( p_case | L_IDENT ) }
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_statements(bool require, bool allow_instance)
{
    bool flag = false;
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_code_statements;
    // Parse nodes until we can no longer parse nodes
    do
    {
        auto __mark = mark();
        std::optional<cstnode> tmp;
        if (look_ahead_token(1).type == tokenizer::etoken::t_break)
        {
            cstnode cur = {};
            cur.token = next_token();
            cur.type = cstnode::kind::s_statement_break;
            self_node.nodes.push_back(cur);
            flag = true;
        }
        else if (look_ahead_token(1).type == tokenizer::etoken::t_continue)
        {
            cstnode cur = {};
            cur.token = next_token();
            cur.type = cstnode::kind::s_statement_continue;
            self_node.nodes.push_back(cur);
            flag = true;
        }
        else if (look_ahead_token(1).type == tokenizer::etoken::t_return)
        {
            cstnode cur = {};
            cur.token = next_token();
            cur.type = cstnode::kind::s_statement_return;
            if ((tmp = p_value(false, allow_instance)).has_value())
            {
                cur.nodes.push_back(tmp.value());
            }
            self_node.nodes.push_back(cur);
            flag = true;
        }
        else if (look_ahead_token(1).type == tokenizer::etoken::t_throw)
        {
            cstnode cur = {};
            cur.token = next_token();
            cur.type = cstnode::kind::s_statement_throw;
            if ((tmp = p_value(false, allow_instance)).has_value())
            {
                cur.nodes.push_back(tmp.value());
            }
            flag = true;
        }
        else if (look_ahead_token(1).type == tokenizer::etoken::t_delete && (tmp = p_value(false, allow_instance)).has_value())
        {
            cstnode cur = {};
            cur.token = next_token();
            cur.type = cstnode::kind::s_statement_delete;
            cur.nodes.push_back(tmp.value());
            self_node.nodes.push_back(cur);
            flag = true;
        }
        else if (look_ahead_token(1).type == tokenizer::etoken::t_goto && (look_ahead_token(2).type == tokenizer::etoken::l_ident | (tmp = p_case(false, allow_instance)).has_value()))
        {
            cstnode cur = {};
            cur.token = next_token();
            cur.type = cstnode::kind::s_statement_goto;
            if (look_ahead_token().type == tokenizer::etoken::l_ident)
            {
                cur.nodes.push_back({ next_token() });
            }
            else
            {
                cur.nodes.push_back(tmp.value());
            }
            self_node.nodes.push_back(cur);
            flag = true;
        }
        else if (!flag)
        {
            if (require)
            {
                log(msgs::syntax_error_generic(to_position(current_token())));
            }
            __mark.rollback();
            break;
        }
    } while (true);
    return flag ? self_node : std::optional<cstnode>();
}

// p_file_statements = { p_namespace | p_method | p_conversion | p_enum | p_using ";" }
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_file_statements(bool require)
{
    bool flag = false;
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_file_statements;
    // Parse nodes until we can no longer parse nodes
    do
    {
        auto __mark = mark();
        std::optional<cstnode> tmp;
        if ((tmp = p_class(false)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_namespace(false)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_method(false, false)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_conversion(false, p_conversion_mod::f_unbound)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_enum(false)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_using(false)).has_value())
        {
            /* s_semicolon is required after using.                       *
             * However, this is a weak error and we can continue parsing. */
            if (look_ahead_token().type != tokenizer::etoken::s_semicolon)
            { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); }
            else { next_token(); }
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if (!flag)
        {
            if (require)
            {
                log(msgs::syntax_error_generic(to_position(current_token())));
            }
            __mark.rollback();
            break;
        }
    } while (true);
    return flag ? self_node : std::optional<cstnode>();
}

// p_class = p_class_head [ p_template_definition ] [ ":" p_type_list ] p_class_body
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_class(bool require)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_class;
    tokenizer::token class_name_literal;
    
    /* If this is a class can be determined in p_class_head so pass require down */
    // p_class_head ...
    auto node_class_head = p_class_head(require, &class_name_literal);
    if (!node_class_head.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_class_head.value()); }

    /* Optional feature does not need require */
    // ... [ p_template_definition ] ...
    auto node_template_definition = p_template_definition(false);
    if (node_template_definition.has_value()) { self_node.nodes.push_back(node_template_definition.value()); }

    // ... [ ":" p_type_list ] ...
    if (look_ahead_token().type == tokenizer::etoken::s_colon)
    {
        // ... ":" ...
        next_token();

        /* next is required after colon */
        // ... p_type_list ...
        auto node_type_list = p_type_list(true);
        if (!node_type_list.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(node_type_list.value()); }
    }

    /* next is required after p_class_head was successfull */
    // ... p_class_body
    auto node_class_body = p_class_body(true, class_name_literal);
    if (!node_class_body.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_class_body.value()); }

    return self_node;
}

// p_class_head = p_encapsulation(false) "class" L_IDENT
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_class_head(bool require, tokenizer::token* OUT_class_name_literal)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_class_head;

    /* it is possible that we are not a p_class_head. Pass require down. */
    // p_encapsulation(false) ...
    auto node_encapsulation = p_encapsulation(require, false);
    if (!node_encapsulation.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_encapsulation.value()); }

    /* if require, fail here if not "class" token. */
    // ... "class" ...
    auto token_class = next_token();
    if (token_class.type != tokenizer::etoken::t_class) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.token = token_class; }

    /* we are sure now that we are a p_class_head. Next has to be a L_IDENT token. */
    // ... L_IDENT
    auto literal_ident = next_token();
    if (literal_ident.type != tokenizer::etoken::l_ident) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(literal_ident); *OUT_class_name_literal = literal_ident; }

    return self_node;
}

// p_class_body = "{" p_class_statements "}"
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_class_body(bool require, tokenizer::token class_name_literal)
{
    auto __mark = mark();

    /* unless we are required, this determines a possible body-start. */
    // "{" ...
    auto token_curlyo = next_token();
    if (token_curlyo.type != tokenizer::etoken::s_curlyo) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }

    /* unless we are required, the following is just a possible set. Pass down require as that only can tell wether we are or not. */
    // ... p_class_statements ...
    auto node_class_statements = p_class_statements(require, class_name_literal);
    if (!node_class_statements.has_value()) { __mark.rollback(); return {}; }

    /* as we got to here, next token has to be s_curlyc. */
    // ... "}"
    auto token_curlyc = next_token();
    if (token_curlyc.type != tokenizer::etoken::s_curlyc) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }

    return node_class_statements.value();
}

// p_class_statements { p_constructor | p_destructor | p_method | p_operator | p_conversion | p_property | p_class | p_using | p_enum }
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_class_statements(bool require, tokenizer::token class_name_literal)
{
    bool flag = false;
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_file_statements;
    // Parse nodes until we can no longer parse nodes
    bool has_destructor = false;
    do
    {
        auto __mark = mark();
        std::optional<cstnode> tmp;
        if ((tmp = p_constructor(false, class_name_literal)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else 
        if ((tmp = p_copy_constructor(false, class_name_literal)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if (!has_destructor && (tmp = p_destructor(false, class_name_literal)).has_value())
        {
            has_destructor = true;
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_method(false, true)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_operator(false, true)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_conversion(false, p_conversion_mod::f_class | p_conversion_mod::f_unbound)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_property(false, true)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_class(false)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_using(false)).has_value())
        {
            /* s_semicolon is required after using.                       *
             * However, this is a weak error and we can continue parsing. */
            if (next_token().type != tokenizer::etoken::s_semicolon)
            {
                log(msgs::syntax_error_generic(to_position(current_token())));
            }
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if ((tmp = p_enum(false)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if (!flag)
        {
            if (require)
            {
                log(msgs::syntax_error_generic(to_position(current_token())));
            }
            __mark.rollback();
            break;
        }
    } while (true);
    return flag ? self_node : std::optional<cstnode>();
}

// p_class_member_head = p_encapsulation [ "unbound" ] p_type L_IDENT
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_class_member_head(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_class_member_head;

    /* it is possible that we are not a p_class_member_head. Pass require down. */
    // p_encapsulation(false) ...
    auto node_encapsulation = p_encapsulation(require, allow_instance);
    if (!node_encapsulation.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_encapsulation.value()); }

    /* Optional token */
    // ... [ "unbound" ] ...
    auto token_unbound = look_ahead_token();
    if (token_unbound.type == tokenizer::etoken::t_unbound) { self_node.nodes.push_back(next_token()); }

    /* we still cannot know duh... so rense and repeat. */
    // ... p_type ...
    auto node_type = p_type(require);
    if (!node_type.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_type.value()); }

    /* still unknown. This is highly ambigous. "Pass require down" a last time. */
    // ... L_IDENT
    auto literal_ident = next_token();
    if (literal_ident.type != tokenizer::etoken::l_ident) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.token = literal_ident; }

    return self_node;
}

// p_namespace = "namespace" p_type_ident "{" p_file_statements "}"
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_namespace(bool require)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_namespace;

    /* if require, fail here if next token is not t_namespace. */
    // "namespace" ...
    auto token_namespace = next_token();
    if (token_namespace.type != tokenizer::etoken::t_namespace) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.token = token_namespace; }

    /* we are sure now that we are a p_namespace. Next has to be p_type_ident. */
    // ... p_type_ident ...
    auto node_type_ident = p_type_ident(true);
    if (!node_type_ident.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_type_ident.value()); }

    /* we are sure now that we are a p_namespace. Next has to be s_curlyo. */
    // ... "{" ...
    auto token_curlyo = next_token();
    if (token_curlyo.type != tokenizer::etoken::s_curlyo) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }

    /* we are sure now that we are a p_namespace. Next has to be p_file_statements. */
    // ... p_file_statements ...
    auto node_file_statements = p_file_statements(true);
    if (!node_file_statements.has_value()) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_file_statements.value()); }

    /* we are sure now that we are a p_namespace. Next has to be s_curlyc. */
    // ... "}"
    auto token_curlyc = next_token();
    if (token_curlyc.type != tokenizer::etoken::s_curlyc) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }

    return self_node;
}

// p_property = p_class_member_head p_property_body
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_property(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_property;

    /* pass down require to p_class_member_head. */
    // p_class_member_head ...
    auto node_class_member_head = p_class_member_head(require, allow_instance);
    if (!node_class_member_head.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_class_member_head.value()); }

    /* p_property_head is ambigous. So pass down require to p_property_body. */
    // ... p_property_body
    auto node_property_body = p_property_body(require, allow_instance);
    if (!node_property_body.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_property_body.value()); }

    return self_node;
}

// p_property_body = ( ";" | "{" ( ( p_property_get p_property_set ) | ( p_property_get ) | ( p_property_set ) | ( p_property_set p_property_get ) ) "}" )
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_property_body(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_property_body;

    { // ";"

        /* if next is semicolon, we are done. */
        // ";"
        auto token_namespace = next_token();
        if (token_namespace.type != tokenizer::etoken::t_namespace) {}
        else { self_node.token = token_namespace; return self_node; }
    }
    { // "{" ( ( p_property_get p_property_set ) | ( p_property_get ) | ( p_property_set ) | ( p_property_set p_property_get ) ) "}"

        /* following approach works by:               *
         * 1. test p_property_get                     *
         * 2. test p_property_set                     *
         * 3. if 1) failed, test p_property_get again */

        /* attempt p_property_get. */
        // 'p_property_get'
        auto node_property_get = p_property_get(false, allow_instance);
        if (!node_property_get.has_value()) {}
        else { self_node.nodes.push_back(node_property_get.value()); }

        /* if require and p_property_get failed, require p_property_set. */
        // 'p_property_get'
        auto node_property_set = p_property_set(require && !node_property_get.has_value(), allow_instance);
        if (!node_property_set.has_value()) { if (require && !node_property_get.has_value()) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; } }
        else { self_node.nodes.push_back(node_property_set.value()); }

        /* repeat p_property_get if prior p_property_get has failed. */
        if (!node_property_get.has_value())
        {
            // 'p_property_get'
            node_property_get = p_property_get(false, allow_instance);
            if (!node_property_get.has_value()) {}
            else { self_node.nodes.push_back(node_property_get.value()); }
        }
    }

    return self_node;
}

// p_property_get = [ p_encapsulation ] "get" p_method_body
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_property_get(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_property_get;

    /* optional p_encapsulation. */
    // [ p_encapsulation ] ...
    auto node_encapsulation = p_encapsulation(false, allow_instance);
    if (!node_encapsulation.has_value()) { }
    else { self_node.nodes.push_back(node_encapsulation.value()); }

    /* following token denotes if we are indeed a p_property_get. */
    // ... "get" ...
    auto token_using = next_token();
    if (token_using.type != tokenizer::etoken::t_get) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.token = token_using; }

    /* we know we are a p_property_get here. Require p_method_body */
    // ... p_method_body
    auto node_method_body = p_method_body(true, allow_instance);
    if (!node_method_body.has_value()) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_method_body.value()); }

    return self_node;
}

// p_property_set = [ p_encapsulation ] "set" [ "(" L_IDENT ")" ] p_method_body
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_property_set(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_property_set;

    /* optional p_encapsulation. */
    // [ p_encapsulation ] ...
    auto node_encapsulation = p_encapsulation(false, allow_instance);
    if (!node_encapsulation.has_value()) {}
    else { self_node.nodes.push_back(node_encapsulation.value()); }

    /* following token denotes if we are indeed a p_property_set. */
    // ... "set" ...
    auto token_using = next_token();
    if (token_using.type != tokenizer::etoken::t_get) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.token = token_using; }

    // [ "(" L_IDENT ")" ]
    if (look_ahead_token().type == tokenizer::etoken::s_roundo)
    {
        // "(" ...
        next_token();

        /* next is required after s_roundo */
        // ... L_IDENT ...
        auto token_using = next_token();
        if (token_using.type != tokenizer::etoken::l_ident) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } else { __mark.rollback(); return {}; } }
        else { self_node.nodes.push_back(token_using); }

        /* following has to be s_roundc or we are no valid p_property_set. * 
         * If in require, emit syntax error and continue parsing.          *
         * If not, exit parsing.                                           */
        // ")"
        auto token_using = next_token();
        if (token_using.type != tokenizer::etoken::s_roundc) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } else { __mark.rollback(); return {}; } }
    }

    /* we know we are a p_property_set here. Require p_method_body */
    // ... p_method_body
    auto node_method_body = p_method_body(true, allow_instance);
    if (!node_method_body.has_value()) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_method_body.value()); }

    return self_node;
}

// p_method = p_class_member_head [ p_template_definition ] p_method_parameters p_method_body
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_method(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_method;

    /* pass down require to p_class_member_head. */
    // p_class_member_head ...
    auto node_class_member_head = p_class_member_head(require, allow_instance);
    if (!node_class_member_head.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_class_member_head.value()); }

    /* p_template_definition is optional. So pass down require to p_property_body. */
    // ... [ p_template_definition ] ...
    auto node_template_definition = p_template_definition(false);
    if (!node_template_definition.has_value()) { }
    else { self_node.nodes.push_back(node_template_definition.value()); }

    /* pass down require to p_method_parameters. */
    // ... p_method_parameters ...
    auto node_method_parameters = p_method_parameters(require);
    if (!node_method_parameters.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_method_parameters.value()); }

    /* pass down require to p_method_body. */
    // ... p_method_body
    auto node_method_body = p_method_body(true, allow_instance);
    if (!node_method_body.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_method_body.value()); }

    return self_node;
}

// p_method_arg = p_type L_IDENT [ "=" p_value_constant ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_method_arg(bool require)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_enum;

    // p_type ...
    auto node_type = p_type(require);
    if (!node_type.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_type.value()); }

    // ... L_IDENT ...
    auto literal_ident = next_token();
    if (literal_ident.type != tokenizer::etoken::l_ident) { log(msgs::syntax_error_generic(to_position(current_token()))); }
    else { self_node.nodes.push_back(literal_ident); }

    // ... [ "=" p_value_constant ]
    if (look_ahead_token().type == tokenizer::etoken::s_equal)
    {
        // ... "=" ...
        next_token();

        /* pass down require to p_value_constant as this is ambigous with assignment */
        // ... p_value_constant
        auto node_value_constant = p_value_constant(require);
        if (!node_value_constant.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(node_value_constant.value()); }
    }

    return self_node;
}

// p_method_parameters = "(" p_method_arg_list ")"
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_method_parameters(bool require)
{
    auto __mark = mark();

    /* unless we are required, this determines a possible body-start. */
    // "(" ...
    auto token_curlyo = look_ahead_token();
    if (token_curlyo.type != tokenizer::etoken::s_roundo) { if (require) { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); } else { __mark.rollback(); return {}; } }
    else { next_token(); }

    /* unless we are required, the following is just a possible set. Pass down require as that only can tell wether we are or not. */
    // ... p_method_arg_list ...
    auto node_method_arg_list = p_method_arg_list(require);
    if (!node_method_arg_list.has_value()) { __mark.rollback(); return {}; }

    /* as we got to here, next token has to be s_curlyc. */
    // ... ")"
    auto token_curlyc = look_ahead_token();
    if (token_curlyo.type != tokenizer::etoken::s_roundo) { if (require) { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); } else { __mark.rollback(); return {}; } }
    else { next_token(); }

    return node_method_arg_list.value();
}

// p_method_body = "{" p_code_statements "}"
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_method_body(bool require, bool allow_instance)
{
    auto __mark = mark();

    /* unless we are required, this determines a possible body-start. */
    // "{" ...
    auto token_curlyo = next_token();
    if (token_curlyo.type != tokenizer::etoken::s_curlyo) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }

    /* unless we are required, the following is just a possible set. Pass down require as that only can tell wether we are or not. */
    // ... p_code_statements ...
    auto node_code_statements = p_code_statements(require, allow_instance);
    if (!node_code_statements.has_value()) { __mark.rollback(); return {}; }

    /* as we got to here, next token has to be s_curlyc. */
    // ... "}"
    auto token_curlyc = next_token();
    if (token_curlyc.type != tokenizer::etoken::s_curlyc) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }

    return node_code_statements.value();
}

// p_statement_body = [ p_statements ] ";" | "{" p_code_statements "}"
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_statement_body(bool require, bool allow_instance)
{
    auto __mark = mark();

    // "{" ...
    if (look_ahead_token().type == tokenizer::etoken::s_curlyo)
    {
        next_token();

        /* unless we are required, the following is just a possible set. Pass down require as that only can tell wether we are or not. */
        // ... p_code_statements ...
        auto node_code_statements = p_code_statements(require, allow_instance);
        if (!node_code_statements.has_value()) { __mark.rollback(); return {}; }

        /* as we got to here, next token has to be s_curlyc. */
        // ... "}"
        auto token_curlyc = next_token();
        if (token_curlyc.type != tokenizer::etoken::s_curlyc) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }
        return node_code_statements;
    }
    // ";"
    else if (look_ahead_token().type == tokenizer::etoken::s_semicolon)
    {
        return next_token();
    }
    else
    {
        // p_statements ...
        auto node_code_statement = p_statements(true, allow_instance);
        if (!node_code_statement.has_value()) { __mark.rollback(); return {}; }

        /* as we got to here, next token has to be s_curlyc. */
        // ... ";"
        auto token_curlyc = next_token();
        if (token_curlyc.type != tokenizer::etoken::s_semicolon) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } else { __mark.rollback(); return {}; } }

        return node_code_statement;
    }
}

// p_operator_head = p_encapsulation [ "unbound" ] p_type "operator"
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_operator_head(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_operator_head;

    /* it is possible that we are not a p_class_member_head. Pass require down. */
    // p_encapsulation(false) ...
    auto node_encapsulation = p_encapsulation(require, allow_instance);
    if (!node_encapsulation.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_encapsulation.value()); }

    /* Optional token */
    // ... [ "unbound" ] ...
    auto token_unbound = look_ahead_token();
    if (token_unbound.type == tokenizer::etoken::t_unbound) { self_node.nodes.push_back(next_token()); }

    /* we still cannot know duh... so rense and repeat. */
    // ... p_type ...
    auto node_type = p_type(require);
    if (!node_type.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_type.value()); }

    /* still unknown. This is highly ambigous. "Pass require down" a last time. */
    // ... "operator"
    auto token_operator = next_token();
    if (token_operator.type != tokenizer::etoken::t_operator) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(token_operator); }

    return self_node;
}

// p_operator_parameters = ( ( "!" | "~" | "-" | "+" | "--" | "++" ) p_method_arg ) | ( p_method_arg ( "+" | "-" | "*" | "/" | ">" | ">=" | ">>" | ">>>" | "<" | "<=" | "<<" | "<<<" | "==" | ".." | "&" | "&&" | "|" | "||" | "^" | "%" ) p_method_arg )
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_operator_parameters(bool require)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_operator_parameters;

    auto token_la = look_ahead_token();
    switch (token_la.type)
    {
    case tokenizer::etoken::s_exclamationmark:
    case tokenizer::etoken::s_tilde:
    case tokenizer::etoken::s_minus:
    case tokenizer::etoken::s_minusminus:
    case tokenizer::etoken::s_plus:
    case tokenizer::etoken::s_plusplus:
    {
        // Consume token
        next_token();
        self_node.token = token_la;

        // get corresponding p_method_arg
        auto node_method_arg = p_method_arg(require);
        if (!node_method_arg.has_value()) { __mark.rollback(); return {}; }
        self_node.nodes.push_back(node_method_arg.value());

    } break;
    default:
    {
        // Get starting p_method_arg
        auto node_method_arg = p_method_arg(require);
        if (!node_method_arg.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
        self_node.nodes.push_back(node_method_arg.value());

        // Get symbol and validate it is in the list of supported symbols
        self_node.token = next_token();
        switch (self_node.token.type)
        {
        case tokenizer::etoken::s_plus:
        case tokenizer::etoken::s_minus:
        case tokenizer::etoken::s_star:
        case tokenizer::etoken::s_slash:
        case tokenizer::etoken::s_gt:
        case tokenizer::etoken::s_gtequal:
        case tokenizer::etoken::s_gtgt:
        case tokenizer::etoken::s_gtgtgt:
        case tokenizer::etoken::s_lt:
        case tokenizer::etoken::s_ltequal:
        case tokenizer::etoken::s_ltlt:
        case tokenizer::etoken::s_ltltlt:
        case tokenizer::etoken::s_equalequal:
        case tokenizer::etoken::s_dotdot:
        case tokenizer::etoken::s_and:
        case tokenizer::etoken::s_andand:
        case tokenizer::etoken::s_vline:
        case tokenizer::etoken::s_vlinevline:
        case tokenizer::etoken::s_circumflex:
        case tokenizer::etoken::s_percent:
            break;
        default:
            if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); }
            __mark.rollback();
            return {};
        }

        // Get ending p_method_arg
        auto node_method_arg = p_method_arg(require);
        if (!node_method_arg.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
        self_node.nodes.push_back(node_method_arg.value());
    } break;
    }

    /* unless we are required, this determines a possible body-start. */
    // "(" ...
    auto token_curlyo = next_token();
    if (token_curlyo.type != tokenizer::etoken::s_roundo) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }

    /* unless we are required, the following is just a possible set. Pass down require as that only can tell wether we are or not. */
    // ... p_method_arg_list ...
    auto node_method_arg_list = p_method_arg_list(require);
    if (!node_method_arg_list.has_value()) { __mark.rollback(); return {}; }

    /* as we got to here, next token has to be s_curlyc. */
    // ... ")"
    auto token_curlyc = next_token();
    if (token_curlyc.type != tokenizer::etoken::s_roundc) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }

    return node_method_arg_list.value();
}

// p_constructor = [ p_encapsulation ] L_IDENT m_method_parameters m_method_body
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_constructor(bool require, tokenizer::token class_name_literal)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_constructor;

    /* optional p_encapsulation. */
    // [ p_encapsulation ] ...
    auto node_encapsulation = p_encapsulation(false, true);
    if (!node_encapsulation.has_value()) {}
    else { self_node.nodes.push_back(node_encapsulation.value()); }


    /* not sure if we are required yet */
    // ... L_IDENT ...
    auto token_using = next_token();
    if (token_using.type != tokenizer::etoken::l_ident || token_using.contents != class_name_literal.contents)
    { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } else { __mark.rollback(); return {}; } }
    else { self_node.token = token_using; }


    /* We are sure from here onwards, that we are indeed a constructor. */


    // ... p_method_parameters ...
    auto node_method_parameters = p_method_parameters(true);
    if (!node_method_parameters.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_method_parameters.value()); }

    /* pass down require to p_method_body. */
    // ... p_method_body
    auto node_method_body = p_method_body(true, true);
    if (!node_method_body.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_method_body.value()); }

    return self_node;
}

// p_copy_constructor = [ p_encapsulation ] "+" L_IDENT "(" L_IDENT ")" m_method_body
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_copy_constructor(bool require, tokenizer::token class_name_literal)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_constructor_copy;

    /* optional p_encapsulation. */
    // [ p_encapsulation ] ...
    auto node_encapsulation = p_encapsulation(false, true);
    if (!node_encapsulation.has_value()) {}
    else { self_node.nodes.push_back(node_encapsulation.value()); }

    /* not sure if we are required yet */
    // ... "+" ...
    auto token_prefix = look_ahead_token();
    if (token_prefix.type != tokenizer::etoken::s_plus) { if (require) { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); } else { __mark.rollback(); return {}; } }
    else { next_token(); }

    /* not sure if we are required yet */
    // ... L_IDENT ...
    auto token_ident = next_token();
    if (token_ident.type != tokenizer::etoken::l_ident || token_ident.contents != class_name_literal.contents)
    {
        if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); }
        else { __mark.rollback(); return {}; }
    }
    else { self_node.token = token_ident; }


    /* We are sure from here onwards, that we are indeed a copy constructor. */



    // .. "(" ...
    auto token_curlyo = look_ahead_token();
    if (token_curlyo.type != tokenizer::etoken::s_roundo) { if (require) { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); } else { __mark.rollback(); return {}; } }
    else { next_token(); }

    // ... L_IDENT ...
    auto token_copy_name = look_ahead_token(require);
    if (token_copy_name.type != tokenizer::etoken::l_ident) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(next_token()); }

    // ... ")" ...
    auto token_curlyc = look_ahead_token();
    if (token_curlyo.type != tokenizer::etoken::s_roundo) { if (require) { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); } else { __mark.rollback(); return {}; } }
    else { next_token(); }

    // ... p_method_body
    auto node_method_body = p_method_body(true, true);
    if (!node_method_body.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_method_body.value()); }

    return self_node;
}

// p_destructor = [ p_encapsulation ] "~" L_IDENT "(" ")" m_method_body
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_destructor(bool require, tokenizer::token class_name_literal)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_destructor;

    /* optional p_encapsulation. */
    // [ p_encapsulation ] ...
    auto node_encapsulation = p_encapsulation(false, true);
    if (!node_encapsulation.has_value()) {}
    else { self_node.nodes.push_back(node_encapsulation.value()); }

    /* not sure if we are required yet */
    // ... "~" ...
    auto token_prefix = look_ahead_token();
    if (token_prefix.type != tokenizer::etoken::s_tilde) { if (require) { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); } else { __mark.rollback(); return {}; } }
    else { next_token(); }

    /* not sure if we are required yet */
    // ... L_IDENT ...
    auto token_ident = next_token();
    if (token_ident.type != tokenizer::etoken::l_ident || token_ident.contents != class_name_literal.contents)
    {
        if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); }
        else { __mark.rollback(); return {}; }
    }
    else { self_node.token = token_ident; }


    /* We are sure from here onwards, that we are indeed a destructor. */



    // .. "(" ...
    auto token_curlyo = look_ahead_token();
    if (token_curlyo.type != tokenizer::etoken::s_roundo) { if (require) { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); } else { __mark.rollback(); return {}; } }
    else { next_token(); }

    // ... ")" ...
    auto token_curlyc = look_ahead_token();
    if (token_curlyo.type != tokenizer::etoken::s_roundo) { if (require) { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); } else { __mark.rollback(); return {}; } }
    else { next_token(); }

    // ... p_method_body
    auto node_method_body = p_method_body(true, true);
    if (!node_method_body.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_method_body.value()); }

    return self_node;
}

// p_operator = p_operator_head [ p_template_definition ] p_operator_parameters p_method_body
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_operator(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_operator;

    /* pass down require to p_operator_head. */
    // p_operator_head ...
    auto node_operator_head = p_operator_head(require, allow_instance);
    if (!node_operator_head.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_operator_head.value()); }
    /* we are sure that we are an opertor from here onwards. */

    /* p_template_definition is optional. So pass down require to p_property_body. */
    // ... [ p_template_definition ] ...
    auto node_template_definition = p_template_definition(false);
    if (!node_template_definition.has_value()) {}
    else { self_node.nodes.push_back(node_template_definition.value()); }

    // ... p_operator_parameters ...
    auto node_operator_parameters = p_operator_parameters(true);
    if (!node_operator_parameters.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_operator_parameters.value()); }

    /* pass down require to p_method_body. */
    // ... p_method_body
    auto node_method_body = p_method_body(true, allow_instance);
    if (!node_method_body.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_method_body.value()); }

    return self_node;
}

// p_conversion = [? p_encapsulation ?] ( [? "unbound" "conversion" p_type "(" p_method_arg ")" ?] | "conversion" p_type ) p_method_body
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_conversion(bool require, p_conversion_mod mod)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_class_member_head;

    if ((mod & p_conversion_mod::f_force_local) != p_conversion_mod::f_force_local)
    {
        /* it is possible that we are not a p_conversion. Pass require down. */
        // p_encapsulation ...
        auto node_encapsulation = p_encapsulation(require, (mod & p_conversion_mod::f_class) == p_conversion_mod::f_class);
        if (!node_encapsulation.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(node_encapsulation.value()); }
    }

    /* If following matches, use 1. Otherwise use 2. */
    /* 1: "unbound" "conversion" p_type "(" p_method_arg ")" */
    /* 2: "conversion" p_type */
    // "unbound" ...
    auto token_unbound = look_ahead_token();
    if (token_unbound.type == tokenizer::etoken::t_unbound)
    { // 1
        if ((mod & p_conversion_mod::f_unbound) != p_conversion_mod::f_unbound) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
        self_node.nodes.push_back(next_token());

        // ... "conversion" ...
        auto token_conversion = next_token();
        if (token_conversion.type != tokenizer::etoken::t_conversion) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
        else { self_node.token = token_conversion; }

        /* We are sure, we are a conversion now. Require from here onwards */
        // ... p_type ...
        auto node_type = p_type(true);
        if (!node_type.has_value()) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(node_type.value()); }
        

        // "(" ...
        auto token_curlyo = next_token();
        if (token_curlyo.type != tokenizer::etoken::s_roundo) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }

        // ... p_method_arg ...
        auto node_method_arg = p_method_arg(true);
        if (!node_method_arg.has_value()) { __mark.rollback(); return {}; }

        // ... ")" ...
        auto token_curlyc = next_token();
        if (token_curlyc.type != tokenizer::etoken::s_roundc) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }


        // ... p_method_body
        auto node_method_body = p_method_body(true, false);
        if (!node_method_body.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(node_method_body.value()); }
    }
    else
    { // 2

        // ... "conversion" ...
        auto token_conversion = next_token();
        if (token_conversion.type != tokenizer::etoken::t_conversion) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
        else { self_node.token = token_conversion; }

        /* We are sure, we are a conversion now. Require from here onwards */
        // ... p_type ...
        auto node_type = p_type(true);
        if (!node_type.has_value()) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(node_type.value()); }

        // ... p_method_body
        auto node_method_body = p_method_body(true, true);
        if (!node_method_body.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(node_method_body.value()); }
    }

    return self_node;
}

// p_method_arg_list = [ p_method_arg { "," p_method_arg } [ "," ] ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_method_arg_list(bool require)
{
    bool flag = false;
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_method_arg_list;
    // Parse nodes until we can no longer parse nodes
    bool had_comma = true; // set to true to prevent initial comma-check
    do
    {
        if (!had_comma)
        {
            log(msgs::syntax_error_generic(to_position(current_token())));
        }
        std::optional<cstnode> tmp;
        if ((tmp = p_enum_value(require)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if (!flag)
        {
            if (require)
            {
                log(msgs::syntax_error_generic(to_position(current_token())));
            }
            break;
        }

        // Check if next token is comma.
        if (!(had_comma = next_token().type == tokenizer::etoken::s_comma))
        {
            undo_token();
        }
    } while (true);
    return flag ? self_node : std::optional<cstnode>();
}

// p_using = "using" p_type [ "=" L_IDENT ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_using(bool require)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_using;

    /* following token denotes if we are indeed a p_using. */
    // "using" ...
    auto token_using = next_token();
    if (token_using.type != tokenizer::etoken::t_using) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.token = token_using; }
    
    /* Required as we already determined that we are a p_using. */
    // ... p_type ...
    auto node_type = p_type(true);
    if (!node_type.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_type.value()); }

    // ... [ "=" L_IDENT ]
    if (look_ahead_token().type == tokenizer::etoken::s_equal)
    {
        // ... "=" ...
        next_token();

        /* next is required after s_equal */
        // ... L_IDENT
        auto literal_ident = next_token();
        if (literal_ident.type != tokenizer::etoken::l_ident) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } else { __mark.rollback(); return {}; } }
        else { self_node.nodes.push_back(literal_ident); }
    }

    return self_node;
}

// p_if_else = "if" "(" p_value ")" p_statement_body [ "else" p_statement_body ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_if_else(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_using;

    /* following token denotes if we are indeed a p_if_else. */
    // "if" ...
    auto token_if = next_token();
    if (token_if.type != tokenizer::etoken::t_if) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.token = token_if; }

    /* We are sure, we are an if from here onwards*/
    require = true;

    // .. "(" ...
    auto token_curlyo = look_ahead_token();
    if (token_curlyo.type != tokenizer::etoken::s_roundo) { if (require) { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); } else { __mark.rollback(); return {}; } }
    else { next_token(); }

    // ... p_value ...
    auto node_value = p_value(require, allow_instance);
    if (!node_value.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_value.value()); }

    // ... ")" ...
    auto token_curlyc = look_ahead_token();
    if (token_curlyo.type != tokenizer::etoken::s_roundo) { if (require) { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); } else { __mark.rollback(); return {}; } }
    else { next_token(); }

    // ... p_statement_body ...
    auto node_statement_a = p_statement_body(require, allow_instance);
    if (!node_statement_a.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_statement_a.value()); }

    // ... [ "else" ...
    auto token_curlyc = look_ahead_token();
    if (token_curlyo.type != tokenizer::etoken::t_else) { if (require) { log(msgs::syntax_error_generic(to_position(look_ahead_token()))); } else { __mark.rollback(); return {}; } }
    else
    {
        next_token();

        // ... p_statement_body ]
        auto node_statement_b = p_statement_body(require, allow_instance);
        if (!node_statement_b.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(node_statement_b.value()); }
    }
}

// p_scope = "{" p_code_statements "}"
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_scope(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_scope;

    /* unless we are required, this determines a possible body-start. */
    // "{" ...
    auto token_curlyo = next_token();
    if (token_curlyo.type != tokenizer::etoken::s_curlyo) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }

    /* unless we are required, the following is just a possible set. Pass down require as that only can tell wether we are or not. */
    // ... p_code_statements ...
    auto node_code_statements = p_code_statements(require, allow_instance);
    if (!node_code_statements.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_code_statements.value()); }

    /* as we got to here, next token has to be s_curlyc. */
    // ... "}"
    auto token_curlyc = next_token();
    if (token_curlyc.type != tokenizer::etoken::s_curlyc) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }

    return self_node;
}

// p_case = "case" p_value_constant
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_case(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_case;

    // "case" ...
    auto token_case = next_token();
    if (token_case.type != tokenizer::etoken::t_case) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.token = token_case; }

    // ... p_value_constant
    auto node_value_constant = p_value_constant(true);
    if (!node_value_constant.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_value_constant.value()); }

    return self_node;
}

// p_enum = p_enum_head p_enum_body
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_enum(bool require)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_enum;

    // p_enum_head ...
    auto node_enum_head = p_enum_head(require);
    if (!node_enum_head.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_enum_head.value()); }

    // ... p_enum_body
    auto node_enum_body = p_enum_body(true);
    if (!node_enum_body.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_enum_body.value()); }

    return self_node;
}

// p_enum_head = p_encapsulation(false) "enum" L_IDENT
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_enum_head(bool require)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_enum_head;

    /* it is possible that we are not a p_enum_head. Pass require down. */
    // p_encapsulation(false) ...
    auto node_encapsulation = p_encapsulation(require, false);
    if (!node_encapsulation.has_value()) { __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(node_encapsulation.value()); }

    /* if require, fail here if next token is not t_enum. */
    // ... "enum" ...
    auto token_class = next_token();
    if (token_class.type != tokenizer::etoken::t_enum) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.token = token_class; }

    /* we know for sure we are an enum here. Next is required to be L_IDENT. */
    // ... L_IDENT
    auto literal_ident = next_token();
    if (literal_ident.type != tokenizer::etoken::l_ident) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(literal_ident); }

    return self_node;
}

// p_enum_body = "{" p_enum_statements "}"
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_enum_body(bool require)
{
    auto __mark = mark();

    /* unless we are required, this determines a possible body-start. */
    // "{" ...
    auto token_curlyo = next_token();
    if (token_curlyo.type != tokenizer::etoken::s_curlyo) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }

    /* unless we are required, the following is just a possible set. Pass down require as that only can tell wether we are or not. */
    // ... p_enum_statements ...
    auto node_enum_statements = p_enum_statements(require);
    if (!node_enum_statements.has_value()) { __mark.rollback(); return {}; }

    /* as we got to here, next token has to be s_curlyc. */
    // ... "}"
    auto token_curlyc = next_token();
    if (token_curlyc.type != tokenizer::etoken::s_curlyc) { log(msgs::syntax_error_generic(to_position(current_token()))); __mark.rollback(); return {}; }

    return node_enum_statements.value();
}

// p_enum_statements = [ p_enum_value { "," p_enum_value } [ "," ] ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_enum_statements(bool require)
{
    bool flag = false;
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_enum_statements;
    // Parse nodes until we can no longer parse nodes
    bool had_comma = true; // set to true to prevent initial comma-check
    do
    {
        if (!had_comma)
        {
            log(msgs::syntax_error_generic(to_position(current_token())));
        }
        std::optional<cstnode> tmp;
        if ((tmp = p_enum_value(require)).has_value())
        {
            self_node.nodes.push_back(tmp.value());
            flag = true;
        }
        else if (!flag)
        {
            if (require)
            {
                log(msgs::syntax_error_generic(to_position(current_token())));
            }
            break;
        }

        // Check if next token is comma.
        if (!(had_comma = next_token().type == tokenizer::etoken::s_comma))
        {
            undo_token();
        }
    } while (true);
    return flag ? self_node : std::optional<cstnode>();
}

// p_enum_value = L_IDENT [ "=" p_value_constant ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_enum_value(bool require)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_enum_value;

    /* we cannot know for sure ever if we are indeed a p_enum_value. Use require to determine if mandatory. */
    // L_IDENT ...
    auto literal_ident = next_token();
    if (literal_ident.type != tokenizer::etoken::l_ident) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.token = literal_ident; }

    // ... [ "=" p_value_constant ]
    if (look_ahead_token().type == tokenizer::etoken::s_equal)
    {
        // ... "=" ...
        next_token();

        /* pass down require to p_value_constant as this is ambigous with assignment */
        // ... p_value_constant
        auto node_value_constant = p_value_constant(require);
        if (!node_value_constant.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(node_value_constant.value()); }
    }

    return self_node;
}

// @allow_instance = true:  p_encapsulation = "derived" | "private" | "public" | "local"
// @allow_instance = false: p_encapsulation = "public" | "local"
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_encapsulation(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_encapsulation;

    auto token_mid = next_token();
    if (token_mid.type == tokenizer::etoken::t_public) { self_node.token = token_mid; }
    else if (token_mid.type == tokenizer::etoken::t_local) { self_node.token = token_mid; }
    else if (allow_instance && token_mid.type == tokenizer::etoken::t_derived) { self_node.token = token_mid; }
    else if (allow_instance && token_mid.type == tokenizer::etoken::t_private) { self_node.token = token_mid; }
    else { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }

    return self_node;
}

// p_value = p_exp01 [ "=" p_value ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_value(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_value;

    auto lexp = p_exp01(require, allow_instance);
    if (!lexp.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(lexp.value()); }


    switch (look_ahead_token().type)
    {
    case tokenizer::etoken::s_equal:
    {
        self_node.token = next_token();

        auto rexp = p_value(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(rexp.value()); }
    } break;
    }

    return self_node;
}

// p_value_constant = L_NUMBER | L_STRING | L_CHAR | "true" | "false" | "default" | p_type
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_value_constant(bool require)
{
    std::optional<yaoosl::compiler::cstnode> tmp;
    if (look_ahead_token().type == tokenizer::etoken::l_number)
    {
        yaoosl::compiler::cstnode node(cstnode::kind::s_number, next_token());
        return { node };
    }
    else if (look_ahead_token().type == tokenizer::etoken::l_string)
    {
        yaoosl::compiler::cstnode node(cstnode::kind::s_string, next_token());
        return { node };
    }
    else if (look_ahead_token().type == tokenizer::etoken::l_number)
    {
        yaoosl::compiler::cstnode node(cstnode::kind::s_char, next_token());
        return { node };
    }
    else if (look_ahead_token().type == tokenizer::etoken::t_true || look_ahead_token().type == tokenizer::etoken::t_false)
    {
        yaoosl::compiler::cstnode node(cstnode::kind::s_boolean, next_token());
        return { node };
    }
    else if (look_ahead_token().type == tokenizer::etoken::t_default)
    {
        yaoosl::compiler::cstnode node(cstnode::kind::s_default, next_token());
        return { node };
    }
    else if ((tmp = p_type(require)).has_value())
    {
        return tmp;
    }
    else
    {
        if (require)
        {
            log(msgs::syntax_error_generic(to_position(current_token())));
        }
        return {};
    }
}

// p_exp01 = p_exp02 [ "?" p_exp01 ":" p_exp01 ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_exp01(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_exp01;

    auto lexp = p_exp02(require, allow_instance);
    if (!lexp.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(lexp.value()); }


    switch (look_ahead_token().type)
    {
    case tokenizer::etoken::s_questionmark:
    { // [ "?" p_value ":" p_value ]
        self_node.token = next_token();

        auto mexp = p_exp01(require, allow_instance);
        if (!mexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(mexp.value()); }

        auto token_colon = look_ahead_token();
        if (token_colon.type != tokenizer::etoken::s_colon) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
        else { next_token();; }

        auto rexp = p_exp01(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(rexp.value()); }
    } break;
    default: return self_node.nodes[0];
    }

    return self_node;
}

// p_exp02 = p_exp03 [ "||" p_exp02 ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_exp02(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_exp02;

    auto lexp = p_exp03(require, allow_instance);
    if (!lexp.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(lexp.value()); }


    switch (look_ahead_token().type)
    {
    case tokenizer::etoken::s_vlinevline:
    {
        self_node.token = next_token();

        auto rexp = p_exp02(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(rexp.value()); }
    } break;
    default: return self_node.nodes[0];
    }

    return self_node;
}

// p_exp03 = p_exp04 [ "&&" p_exp03 ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_exp03(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_exp03;

    auto lexp = p_exp04(require, allow_instance);
    if (!lexp.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(lexp.value()); }


    switch (look_ahead_token().type)
    {
    case tokenizer::etoken::s_andand:
    {
        self_node.token = next_token();

        auto rexp = p_exp03(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(rexp.value()); }
    } break;
    default: return self_node.nodes[0];
    }

    return self_node;
}

// p_exp04 = p_exp05 [ ( "==" | "!=" ) p_exp04 ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_exp04(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_exp04;

    auto lexp = p_exp05(require, allow_instance);
    if (!lexp.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(lexp.value()); }


    switch (look_ahead_token().type)
    {
    case tokenizer::etoken::s_equalequal:
    case tokenizer::etoken::s_exclamationmarkequal:
    {
        self_node.token = next_token();

        auto rexp = p_exp04(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(rexp.value()); }
    } break;
    default: return self_node.nodes[0];
    }

    return self_node;
}

// p_exp05 = p_exp06 [ ( "<" | "<=" | ">" | ">=" ) p_exp05 ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_exp05(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_exp05;

    auto lexp = p_exp06(require, allow_instance);
    if (!lexp.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(lexp.value()); }


    switch (look_ahead_token().type)
    {
    case tokenizer::etoken::s_lt:
    case tokenizer::etoken::s_ltequal:
    case tokenizer::etoken::s_gt:
    case tokenizer::etoken::s_gtequal:
    {
        self_node.token = next_token();

        auto rexp = p_exp05(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(rexp.value()); }
    } break;
    default: return self_node.nodes[0];
    }

    return self_node;
}

// p_exp06 = p_exp07 [ ( "+" | "-" ) p_exp06 ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_exp06(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_exp06;

    auto lexp = p_exp07(require, allow_instance);
    if (!lexp.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(lexp.value()); }


    switch (look_ahead_token().type)
    {
    case tokenizer::etoken::s_plus:
    case tokenizer::etoken::s_minus:
    {
        self_node.token = next_token();

        auto rexp = p_exp06(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(rexp.value()); }
    } break;
    default: return self_node.nodes[0];
    }

    return self_node;
}

// p_exp07 = p_exp08 [ ( "*" | "/" | "%" ) p_exp07 ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_exp07(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_exp07;

    auto lexp = p_exp08(require, allow_instance);
    if (!lexp.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(lexp.value()); }


    switch (look_ahead_token().type)
    {
    case tokenizer::etoken::s_star:
    case tokenizer::etoken::s_slash:
    case tokenizer::etoken::s_percent:
    {
        self_node.token = next_token();

        auto rexp = p_exp07(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(rexp.value()); }
    } break;
    default: return self_node.nodes[0];
    }

    return self_node;
}

// p_exp08 = p_exp09 [ ( "<<" | "<<<" | ">>" | ">>>" ) p_exp08 ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_exp08(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_exp08;

    auto lexp = p_exp09(require, allow_instance);
    if (!lexp.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(lexp.value()); }


    switch (look_ahead_token().type)
    {
    case tokenizer::etoken::s_ltlt:
    case tokenizer::etoken::s_ltltlt:
    case tokenizer::etoken::s_gtgt:
    case tokenizer::etoken::s_gtgtgt:
    {
        self_node.token = next_token();

        auto rexp = p_exp08(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(rexp.value()); }
    } break;
    default: return self_node.nodes[0];
    }

    return self_node;
}

// p_exp09 = p_exp10 [ ( "^" | "|" ) p_exp09 ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_exp09(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_exp09;

    auto lexp = p_exp10(require, allow_instance);
    if (!lexp.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(lexp.value()); }


    switch (look_ahead_token().type)
    {
    case tokenizer::etoken::s_circumflex:
    case tokenizer::etoken::s_vline:
    {
        self_node.token = next_token();

        auto rexp = p_exp09(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(rexp.value()); }
    } break;
    default: return self_node.nodes[0];
    }

    return self_node;
}

// p_exp10 = p_exp11 [ ( "&" ) p_exp10 ]
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_exp10(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_exp10;

    auto lexp = p_exp11(require, allow_instance);
    if (!lexp.has_value()) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
    else { self_node.nodes.push_back(lexp.value()); }


    switch (look_ahead_token().type)
    {
    case tokenizer::etoken::s_and:
    {
        self_node.token = next_token();

        auto rexp = p_exp10(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(rexp.value()); }
    } break;
    default: return self_node.nodes[0];
    }

    return self_node;
}

// p_exp11 = "!" p_value | "~" p_value | "(" p_value ")" | p_exp11
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_exp11(bool require, bool allow_instance)
{
    auto __mark = mark();
    cstnode self_node = {};
    self_node.type = cstnode::kind::s_exp11;

    switch (look_ahead_token().type)
    {
    case tokenizer::etoken::s_exclamationmark:
    case tokenizer::etoken::s_tilde:
    {
        self_node.token = next_token();

        auto rexp = p_exp11(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        else { self_node.nodes.push_back(rexp.value()); }
        return self_node;
    }
    case tokenizer::etoken::s_roundo:
    {
        self_node.token = next_token();

        auto rexp = p_value(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }

        auto literal_ident = next_token();
        if (literal_ident.type != tokenizer::etoken::s_roundc) { if (require) { log(msgs::syntax_error_generic(to_position(current_token()))); } __mark.rollback(); return {}; }
        return rexp;
    }
    default:
    {
        auto rexp = p_value(require, allow_instance);
        if (!rexp.has_value()) { __mark.rollback(); return {}; }
        return rexp;
    }
    }
}

// p_exp12 = p_exp_primary | p_exp_call | p_exp_navigate | p_exp_array_index
std::optional<yaoosl::compiler::cstnode> yaoosl::compiler::parser::p_exp12(bool require, bool allow_instance)
{
    std::optional<yaoosl::compiler::cstnode> tmp;
    if ((tmp = p_exp_primary(require, allow_instance)).has_value())
    {
        return tmp;
    }
    else if ((tmp = p_exp_call(require, allow_instance)).has_value())
    {
        return tmp;
    }
    else if ((tmp = p_exp_navigate(require, allow_instance)).has_value())
    {
        return tmp;
    }
    else if ((tmp = p_exp_array_index(require, allow_instance)).has_value())
    {
        return tmp;
    }
    else
    {
        return {};
    }
}
