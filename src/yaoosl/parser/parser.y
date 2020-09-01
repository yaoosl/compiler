
// %skeleton "lalr1.cc" /* -*- C++ -*- */
%language "c++"
%require "3.0"

%define api.value.type variant
%define api.token.constructor
%define api.namespace { sqf::sqc::bison }
%code top {
    #include "tokenizer.h"
    #include <string>
    #include <vector>
}

%code requires
{
     namespace sqf::sqc
     {
          class parser;
     }
     namespace sqf::sqc::bison
     {
          enum class astkind
          {
               __TOKEN = -1,
               NA = 0,
               RETURN,
               THROW,
               ASSIGNMENT,
               DECLARATION,
               FORWARD_DECLARATION,
               FUNCTION_DECLARATION,
               FUNCTION,
               ARGLIST,
               CODEBLOCK,
               IF,
               IFELSE,
               FOR,
               FORSTEP,
               FOREACH,
               WHILE,
               DOWHILE,
               TRYCATCH,
               SWITCH,
               CASE,
               CASE_DEFAULT,
               OP_TERNARY,
               OP_OR,
               OP_AND,
               OP_EQUALEXACT,
               OP_EQUAL,
               OP_NOTEQUALEXACT,
               OP_NOTEQUAL,
               OP_LESSTHAN,
               OP_GREATERTHAN,
               OP_LESSTHANEQUAL,
               OP_GREATERTHANEQUAL,
               OP_PLUS,
               OP_MINUS,
               OP_MULTIPLY,
               OP_DIVIDE,
               OP_REMAINDER,
               OP_NOT,
               OP_BINARY,
               OP_UNARY,
               OP_ARRAY_GET,
               OP_ARRAY_SET,
               VAL_STRING,
               VAL_ARRAY,
               VAL_NUMBER,
               VAL_TRUE,
               VAL_FALSE,
               VAL_NIL,
               GET_VARIABLE
          };
          struct astnode
          {
               sqf::sqc::tokenizer::token token;
               astkind kind;
               std::vector<astnode> children;

               astnode() : token(), kind(astkind::NA)
               {
               }
               astnode(astkind kind) : token(), kind(kind)
               {
               }
               astnode(sqf::sqc::tokenizer::token t) : token(t), kind(astkind::__TOKEN)
               {
               }
               astnode(astkind kind, sqf::sqc::tokenizer::token t) : token(t), kind(kind) {}

               void append(astnode node)
               {
                   children.push_back(node);
               }
               void append_children(const astnode& other)
               { 
                   for (auto node : other.children)
                   {
                       append(node); 
                   } 
               }
          };
     }
}
%code
{
     namespace sqf::sqc::bison
     {
          // Return the next token.
          parser::symbol_type yylex (sqf::sqc::tokenizer&);
     }
}

%lex-param { sqf::sqc::tokenizer &tokenizer }
%parse-param { sqf::sqc::tokenizer &tokenizer }
%parse-param { sqf::sqc::bison::astnode& result }
%parse-param { sqf::sqc::parser& actual }
%parse-param { std::string fpath }
%locations
%define parse.error verbose

%define api.token.prefix {}



/* Tokens */

%token NA 0
%token RETURN                    "return"
%token THROW                     "throw"
%token LET                       "let"
%token BE                        "be"
%token FUNCTION                  "function"
%token IF                        "if"
%token ELSE                      "else"
%token FROM                      "from"
%token TO                        "to"
%token STEP                      "step"
%token WHILE                     "while"
%token DO                        "do"
%token TRY                       "try"
%token CATCH                     "catch"
%token SWITCH                    "switch"
%token CASE                      "case"
%token DEFAULT                   "default"
%token NIL                       "nil"
%token TRUE                      "true"
%token FALSE                     "false"
%token FOR                       "for"
%token PRIVATE                   "private"
%token CURLYO                    "{"
%token CURLYC                    "}"
%token ROUNDO                    "("
%token ROUNDC                    ")"
%token SQUAREO                   "["
%token SQUAREC                   "]"
%token SEMICOLON                 ";"
%token COMMA                     ","
%token EQUAL                     "="
%token DOT                       "."
%token QUESTIONMARK              "?"

%token <tokenizer::token> ANDAND                    "&&"
%token <tokenizer::token> SLASH                     "/"
%token <tokenizer::token> STAR                      "*"
%token <tokenizer::token> PERCENT                   "%"
%token <tokenizer::token> VLINEVLINE                "||"
%token <tokenizer::token> COLON                     ":"
%token <tokenizer::token> PLUS                      "+"
%token <tokenizer::token> MINUS                     "-"
%token <tokenizer::token> LTEQUAL                   "<="
%token <tokenizer::token> LT                        "<"
%token <tokenizer::token> GTEQUAL                   ">="
%token <tokenizer::token> GT                        ">"
%token <tokenizer::token> EQUALEQUALEQUAL           "==="
%token <tokenizer::token> EQUALEQUAL                "=="
%token <tokenizer::token> EXCLAMATIONMARKEQUALEQUAL "!=="
%token <tokenizer::token> EXCLAMATIONMARKEQUAL      "!="
%token <tokenizer::token> EXCLAMATIONMARK           "!"
%token <tokenizer::token> NUMBER 
%token <tokenizer::token> IDENT  
%token <tokenizer::token> STRING 

%type <sqf::sqc::bison::astnode> statements statement assignment vardecl funcdecl function
%type <sqf::sqc::bison::astnode> funchead arglist codeblock if for while trycatch switch
%type <sqf::sqc::bison::astnode> caselist case exp01 exp02 exp03 exp04 exp05 exp06 exp07
%type <sqf::sqc::bison::astnode> exp08 exp09 expp value array explist

%start start

%%

/*** BEGIN - Change the grammar rules below ***/
/*** BEGIN - Change the grammar rules below ***/
/*** BEGIN - Change the grammar rules below ***/
start       : statements                                   { result = sqf::sqc::bison::astnode{}; result.append_children($1); }
            ;

statements  : %empty                                        {  }
            | statement                                     {  }
            | statement statements                          {  }
            ;

type        : IDENT                                         {  }
            | IDENT "." type                                {  }
            ;

cblock      : statement                                     {  }
            | scope                                         {  }
            ;

scope       : "{" statements "}"                            {  }
            ;

statement   : scope                                         {  }
            | if                                            {  }
            | for                                           {  }
            | while                                         {  }
            | try                                           {  }
            | switch                                        {  }
            | frwd_decl ";"                                 {  }
            | exp01 ";"                                     {  }
            | error                                         {  }
            ;

if          : "if" "(" exp01 ")" cblock                     {  }
            | "if" "(" exp01 ")" cblock "else" cblock       {  }
            ;

for         : "for" "(" frarg_c ")" cblock                  {  }
            | "for" "(" frarg_each ")" cblock               {  }
            | "for" "(" frarg_range ")" cblock              {  }
            ;

frarg_c     : exp01 ";" exp01 ";" exp01                     {  }
            ;

frarg_range : frwd_decl ":" INTEGER ".." INTEGER            {  }
            ;

frarg_each  : frwd_decl ":" exp01                           {  }
            ;
while       : "while" "(" exp01 ")" cblock                  {  }
            | "do" cblock "while" "(" exp01 ")" ";"         {  }
            ;

try         : "try" cblock catch                            {  }
            | "try" cblock catch "finally" cblock           {  }
            ;

catch       : "catch" cblock                                {  }
            | catch "(" frwd_decl ")" cblock                {  }
            | "catch" cblock catch                          {  }
            | catch "(" frwd_decl ")" cblock catch          {  }
            ;

switch      : "switch" "(" exp01 ")" "{" caselist "}"       {  }
            ;

case        : "case" const ":"                              {  }
            | "case" const ":" cblock                       {  }
            | "default" ":"                                 {  }
            | "default" ":" cblock                          {  }

caselist    : case                                          {  }
            | case caselist                                 {  }
            ;

frwd_decl   : type IDENT                                    {  }
            ;

var_defntn  : type assign                                   {  }
            ;
assign      : IDENT "=" exp01                               {  }
            ;

exp01       :
const       :
%%

#include "sqc_parser.h"
namespace sqf::sqc::bison
{
     void parser::error (const location_type& loc, const std::string& msg)
     {
          actual.__log(logmessage::sqf::ParseError({ fpath, loc.begin.line, loc.begin.column }, msg));
     }
     inline parser::symbol_type yylex (sqf::sqc::tokenizer& tokenizer)
     {
         auto token = tokenizer.next();
         parser::location_type loc;
         loc.begin.line = token.line;
         loc.begin.column = token.column;
         loc.end.line = token.line;
         loc.end.column = token.column + token.contents.length();

         switch (token.type)
         {
         case tokenizer::etoken::eof: return parser::make_NA(loc);
         case tokenizer::etoken::invalid: return parser::make_NA(loc);
         case tokenizer::etoken::m_line: return yylex(tokenizer);
         case tokenizer::etoken::i_comment_line: return yylex(tokenizer);
         case tokenizer::etoken::i_comment_block: return yylex(tokenizer);
         case tokenizer::etoken::i_whitespace: return yylex(tokenizer);

         case tokenizer::etoken::t_return: return parser::make_RETURN(loc);
         case tokenizer::etoken::t_throw: return parser::make_THROW(loc);
         case tokenizer::etoken::t_let: return parser::make_LET(loc);
         case tokenizer::etoken::t_be: return parser::make_BE(loc);
         case tokenizer::etoken::t_function: return parser::make_FUNCTION(loc);
         case tokenizer::etoken::t_if: return parser::make_IF(loc);
         case tokenizer::etoken::t_else: return parser::make_ELSE(loc);
         case tokenizer::etoken::t_from: return parser::make_FROM(loc);
         case tokenizer::etoken::t_to: return parser::make_TO(loc);
         case tokenizer::etoken::t_step: return parser::make_STEP(loc);
         case tokenizer::etoken::t_while: return parser::make_WHILE(loc);
         case tokenizer::etoken::t_do: return parser::make_DO(loc);
         case tokenizer::etoken::t_try: return parser::make_TRY(loc);
         case tokenizer::etoken::t_catch: return parser::make_CATCH(loc);
         case tokenizer::etoken::t_switch: return parser::make_SWITCH(loc);
         case tokenizer::etoken::t_case: return parser::make_CASE(loc);
         case tokenizer::etoken::t_default: return parser::make_DEFAULT(loc);
         case tokenizer::etoken::t_nil: return parser::make_NIL(loc);
         case tokenizer::etoken::t_true: return parser::make_TRUE(loc);
         case tokenizer::etoken::t_false: return parser::make_FALSE(loc);
         case tokenizer::etoken::t_for: return parser::make_FOR(loc);
         case tokenizer::etoken::t_private: return parser::make_PRIVATE(loc);

         case tokenizer::etoken::s_curlyo: return parser::make_CURLYO(loc);
         case tokenizer::etoken::s_curlyc: return parser::make_CURLYC(loc);
         case tokenizer::etoken::s_roundo: return parser::make_ROUNDO(loc);
         case tokenizer::etoken::s_roundc: return parser::make_ROUNDC(loc);
         case tokenizer::etoken::s_edgeo: return parser::make_SQUAREO(loc);
         case tokenizer::etoken::s_edgec: return parser::make_SQUAREC(loc);
         case tokenizer::etoken::s_equalequalequal: return parser::make_EQUALEQUALEQUAL(token, loc);
         case tokenizer::etoken::s_equalequal: return parser::make_EQUALEQUAL(token, loc);
         case tokenizer::etoken::s_equal: return parser::make_EQUAL(loc);
         case tokenizer::etoken::s_greaterthenequal: return parser::make_GTEQUAL(token, loc);
         case tokenizer::etoken::s_greaterthen: return parser::make_GT(token, loc);
         case tokenizer::etoken::s_lessthenequal: return parser::make_LTEQUAL(token, loc);
         case tokenizer::etoken::s_lessthen: return parser::make_LT(token, loc);
         case tokenizer::etoken::s_plus: return parser::make_PLUS(token, loc);
         case tokenizer::etoken::s_minus: return parser::make_MINUS(token, loc);
         case tokenizer::etoken::s_notequalequal: return parser::make_EXCLAMATIONMARKEQUALEQUAL(token, loc);
         case tokenizer::etoken::s_notequal: return parser::make_EXCLAMATIONMARKEQUAL(token, loc);
         case tokenizer::etoken::s_exclamationmark: return parser::make_EXCLAMATIONMARK(token, loc);
         case tokenizer::etoken::s_percent: return parser::make_PERCENT(token, loc);
         case tokenizer::etoken::s_star: return parser::make_STAR(token, loc);
         case tokenizer::etoken::s_slash: return parser::make_SLASH(token, loc);
         case tokenizer::etoken::s_andand: return parser::make_ANDAND(token, loc);
         case tokenizer::etoken::s_oror: return parser::make_VLINEVLINE(token, loc);
         case tokenizer::etoken::s_questionmark: return parser::make_QUESTIONMARK(loc);
         case tokenizer::etoken::s_colon: return parser::make_COLON(token, loc);
         case tokenizer::etoken::s_semicolon: return parser::make_SEMICOLON(loc);
         case tokenizer::etoken::s_comma: return parser::make_COMMA(loc);
         case tokenizer::etoken::s_dot: return parser::make_DOT(loc);

         case tokenizer::etoken::t_string: return parser::make_STRING(token, loc);
         case tokenizer::etoken::t_ident: return parser::make_IDENT(token, loc);
         case tokenizer::etoken::t_number: return parser::make_NUMBER(token, loc);
         default:
             return parser::make_NA(loc);
         }
     }
}