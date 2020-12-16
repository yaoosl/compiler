#pragma once
#include "cstnode.hpp"
#include "tokenizer.hpp"
#include "../logging/logger.hpp"

#include <optional>
#include <queue>
#include <vector>

namespace yaoosl::compiler
{
    class parser : public yaoosl::logging::can_log
    {
    public:
        enum class p_conversion_mod : uint8_t
        {
            // Allows or disables the "unbound" possibility
            f_unbound = 0b0001,
            // Allows or disables the "class member" possibility
            f_class = 0b0010,
            // Allows or disables the ommiting of the encapsulation, forcing local
            f_force_local = 0b0100
        };
    private:



        class index_marker
        {
            parser& ref;
            size_t cur_indx;
        public:
            index_marker(parser& p) :
                ref(p),
                cur_indx(p.m_tokens_index)
            {}
            void rollback()
            {
                ref.m_tokens_index = cur_indx;
            }
            void set_here()
            {
                cur_indx = ref.m_tokens_index;
            }
        };
        tokenizer m_tokenizer;
        size_t m_tokens_index;
        std::vector<tokenizer::token> m_tokens;
        tokenizer::token next_token() {
            if (m_tokens_index == m_tokens.size())
            {
                auto token = m_tokenizer.next();
                m_tokens.push_back(token);
            }
            auto ret_token = m_tokens[m_tokens_index++];
            return ret_token;
        }
        tokenizer::token current_token() {
            auto ret_token = m_tokens[m_tokens_index];
            return ret_token;
        }
        tokenizer::token look_ahead_token(size_t len = 1) {
            auto index = m_tokens_index;
            tokenizer::token t;
            while (len-- > 0)
            {
                t = next_token();
            }
            m_tokens_index = index;
            return t;
        }
        void undo_token(size_t amount = 1) {
            if (m_tokens_index < amount)
            {
                m_tokens_index = 0;
            }
            else
            {
                m_tokens_index -= amount;
            }
        }
        index_marker mark()
        {
            return index_marker(*this);
        }
    public:
        parser(yaoosl::logging::logger&& logger, tokenizer&& tokenizer) :
            yaoosl::logging::can_log("parser", logger),
            m_tokenizer(tokenizer),
            m_tokens_index(0),
            m_tokens()
        {}

        std::optional<yaoosl::compiler::cstnode> p_start(bool require);
        std::optional<yaoosl::compiler::cstnode> p_code_statements(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_statements(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_file_statements(bool require);
        std::optional<yaoosl::compiler::cstnode> p_class(bool require);
        std::optional<yaoosl::compiler::cstnode> p_class_head(bool require, tokenizer::token* OUT_class_name_literal);
        std::optional<yaoosl::compiler::cstnode> p_class_body(bool require, tokenizer::token class_name_literal);
        std::optional<yaoosl::compiler::cstnode> p_class_statements(bool require, tokenizer::token class_name_literal);
        std::optional<yaoosl::compiler::cstnode> p_class_member_head(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_namespace(bool require);
        std::optional<yaoosl::compiler::cstnode> p_property(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_property_body(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_property_get(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_property_set(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_method(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_method_arg(bool require);
        std::optional<yaoosl::compiler::cstnode> p_method_arg_list(bool require);
        std::optional<yaoosl::compiler::cstnode> p_method_parameters(bool require);
        std::optional<yaoosl::compiler::cstnode> p_statement_body(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_method_body(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_conversion(bool require, p_conversion_mod mod);
        std::optional<yaoosl::compiler::cstnode> p_operator(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_operator_head(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_operator_parameters(bool require);
        std::optional<yaoosl::compiler::cstnode> p_constructor(bool require, tokenizer::token class_name_literal);
        std::optional<yaoosl::compiler::cstnode> p_copy_constructor(bool require, tokenizer::token class_name_literal);
        std::optional<yaoosl::compiler::cstnode> p_variable_declaration(bool require);
        std::optional<yaoosl::compiler::cstnode> p_destructor(bool require, tokenizer::token class_name_literal);
        std::optional<yaoosl::compiler::cstnode> p_using(bool require);
        std::optional<yaoosl::compiler::cstnode> p_if_else(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_for(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_for_step(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_for_each(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_try_catch_finally(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_try(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_catch(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_finally(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_while(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_while_do(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_do_while(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_switch(bool require, bool allow_instance) { return {}; }
        std::optional<yaoosl::compiler::cstnode> p_scope(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_case(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_enum(bool require);
        std::optional<yaoosl::compiler::cstnode> p_enum_head(bool require);
        std::optional<yaoosl::compiler::cstnode> p_enum_body(bool require);
        std::optional<yaoosl::compiler::cstnode> p_enum_statements(bool require);
        std::optional<yaoosl::compiler::cstnode> p_enum_value(bool require);
        std::optional<yaoosl::compiler::cstnode> p_template_definition(bool require);
        std::optional<yaoosl::compiler::cstnode> p_type_ident(bool require);
        std::optional<yaoosl::compiler::cstnode> p_type_list(bool require);
        std::optional<yaoosl::compiler::cstnode> p_type(bool require);
        std::optional<yaoosl::compiler::cstnode> p_encapsulation(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_value(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_value_constant(bool require);
        std::optional<yaoosl::compiler::cstnode> p_exp01(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp02(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp03(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp04(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp05(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp06(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp07(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp08(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp09(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp10(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp11(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp12(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp_primary(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp_call(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp_navigate(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp_array_index(bool require, bool allow_instance);
        std::optional<yaoosl::compiler::cstnode> p_exp_new(bool require, bool allow_instance);
    };
}