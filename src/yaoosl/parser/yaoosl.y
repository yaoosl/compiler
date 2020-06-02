
%code top {
    #include <malloc.h>
    #include <string.h>
    #include <stdio.h>
    
    #include "yaoosl_compilationunit.h"
    
    
    #if _WIN32
        // FU bloody configuration hell!
        // Force the macros to be defined already to avoid
        // "inconsistent dll linkage" with malloc and free.
        #define YYMALLOC
        #define YYFREE
    #endif

    #define CSTNODE(NODE)      ((yaoosl_cstnode){ NODE, cu->code_line, cu->code_column, cu->code_index, 0,   0, 0, 0 })
    #define CSTNODEV(NODE, VAL) ((yaoosl_cstnode){ NODE, cu->code_line, cu->code_column, cu->code_index, VAL, 0, 0, 0 })
    #define CSTPSH(P, C) yaoosl_cstnode_push_child(&P, C);
    #define CSTIMP(TO, FROM) { yaoosl_cstnode_transfer_to(&FROM, &TO); yaoosl_cstnode_invalidate(&FROM); }
}

%union {
    uint8_t uint8;
    int8_t int8;
    uint16_t uint16;
    int16_t int16;
    uint32_t uint32;
    int32_t int32;
    uint64_t uint64;
    int64_t int64;
    float f;
    double d;

    char* str;
    yaoosl_cstnode cst;
}

%define parse.error verbose
%define parse.lac full
%define api.prefix {yaoosl_}
%start yaoosl
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
%parse-param { struct yaoosl_compilationunit* cu };


%token <str> YST_NAME
%token <str> YST_NUMBER
%token <str> YST_HEXNUMBER
%token <str> YST_BINARYNUMBER
%token <str> YST_STRINGVAL
%token <str> YST_CHARVAL
%token YST_DOT "."
%token YST_COMMA ","
%token YST_BOOL "bool"
%token YST_STRING "string"
%token YST_CHAR "char"
%token YST_INT8 "int8"
%token YST_UINT8 "uint8"
%token YST_INT16 "int16"
%token YST_UINT16 "uint16"
%token YST_INT32 "int32"
%token YST_UINT32 "uint32"
%token YST_INT64 "int64"
%token YST_UINT64 "uint64"
%token YST_FLOAT "float"
%token YST_DOUBLE "double"
%token YST_AUTO "auto"
%token YST_USING "using"
%token YST_PUBLIC "public"
%token YST_INTERNAL "internal"
%token YST_DERIVED "derived"
%token YST_PRIVATE "private"
%token YST_CLASS "class"
%token YST_COLON ":"
%token YST_CURLYO "{"
%token YST_CURLYC "}"
%token YST_ROUNDO "("
%token YST_ROUNDC ")"
%token YST_VOID "void"
%token YST_OPERATOR "operator"
%token YST_PLUSPLUS "++"
%token YST_MINUSMINUS "--"
%token YST_EXCLAMATIONMARK "!"
%token YST_PLUS "+"
%token YST_MINUS "-"
%token YST_STAR "*"
%token YST_SLASH "/"
%token YST_PLUSEQUAL "+="
%token YST_MINUSEQUAL "-="
%token YST_STAREQUAL "*="
%token YST_SLASHEQUAL "/="
%token YST_VLINE "|"
%token YST_VLINEVLINE "||"
%token YST_VLINEEQUAL "|="
%token YST_AND "&"
%token YST_ANDAND "&&"
%token YST_ANDEQUAL "&="
%token YST_CIRCUMFLEX "^"
%token YST_CIRCUMFLEXEQUAL "^="
%token YST_TILDE "~"
%token YST_TILDEEQUAL "~="
%token YST_PERCENT "%"
%token YST_PERCENTEQUAL "%="
%token YST_LT "<"
%token YST_LTLT "<<"
%token YST_LTEQUAL "<="
%token YST_LTLTEQUAL "<<="
%token YST_GT ">"
%token YST_GTGT ">>"
%token YST_GTEQUAL ">="
%token YST_GTGTEQUAL ">>="
%token YST_EQUAL "="
%token YST_EQUALEQUAL "=="
%token YST_EXCLAMATIONMARKEQUAL "!="
%token YST_STATIC "static"
%token YST_SEMICOLON ";"
%token YST_RETURN "return"
%token YST_THROW "throw"
%token YST_WITH "with"
%token YST_TRY "try"
%token YST_CATCH "catch"
%token YST_FINALLY "finally"
%token YST_IF "if"
%token YST_ELSE "else"
%token YST_FOR "for"
%token YST_WHILE "while"
%token YST_DO "do"
%token YST_SWITCH "switch"
%token YST_CASE "case"
%token YST_DEFAULT "default"
%token YST_CONTINUE "continue"
%token YST_BREAK "break"
%token YST_QUESTIONMARK "?"
%token YST_IS "is"
%token YST_ISNOT "!is"
%token YST_NEW "new"
%token YST_TYPEOF "typeof"
%token YST_NULL "null"
%token YST_THIS "this"
%token YST_TRUE "true"
%token YST_FALSE "false"
%token YST_SET "set"
%token YST_GET "get"


%type <cst> usingns
%type <cst> identifier
%type <cst> identlist
%type <cst> encpsl
%type <cst> classhead
%type <cst> classbody
%type <cst> classdef
%type <cst> stmntlist
%type <cst> mthd
%type <cst> mthdargs
%type <cst> mthdbody
%type <cst> opmthd
%type <cst> cnstmthd
%type <cst> op0
%type <cst> op1
%type <cst> op2
%type <cst> opargs0
%type <cst> opargs1
%type <cst> opargs2
%type <cst> decl
%type <cst> decllist
%type <cst> property
%type <cst> prop_set
%type <cst> prop_get
%type <cst> stmnt
%type <cst> stdtype
%type <cst> vtype
%type <cst> cntrl_if
%type <cst> cntrl_try
%type <cst> cntrl_catch
%type <cst> cntrl_for
%type <cst> cntrl_for1
%type <cst> cntrl_for2
%type <cst> cntrl_for3
%type <cst> cntrl_while
%type <cst> cntrl_dowhile
%type <cst> cntrl_switch
%type <cst> cntrl_case
%type <cst> cntrl_switchbody
%type <cst> exp
%type <cst> exp01
%type <cst> exp02
%type <cst> exp03
%type <cst> exp04
%type <cst> exp05
%type <cst> exp06
%type <cst> exp07
%type <cst> exp08
%type <cst> exp09
%type <cst> exp10
%type <cst> exp11
%type <cst> exp12
%type <cst> exp13
%type <cst> assign
%type <cst> assign_post
%type <cst> cnstexp
%type <cst> calllist
%type <cst> expressionlist
%type <cst> call
%type <cst> call_post
%type <cst> bexp
%type <cst> refexp

%code requires {
    #ifndef YY_TYPEDEF_YY_SCANNER_T
    #define YY_TYPEDEF_YY_SCANNER_T
    typedef void* yyscan_t;
    #endif
    #ifndef YY_EXTRA_TYPE
    #define YY_EXTRA_TYPE void *
    #endif
}
%code requires {
    #include <inttypes.h>
    #include "yaoosl_cstnode.h"
    enum yaoosl_cst_type
    {
        yscst_error,
        yscst_empty,
        yscst_root,
        yscst_using,
        yscst_body,
        yscst_ident,
        yscst_thisident,
        yscst_identlist,
        yscst_encapsulation_public,
        yscst_encapsulation_internal,
        yscst_encapsulation_derived,
        yscst_encapsulation_private,
        yscst_classdef,
        yscst_classhead,
        yscst_classbody,
        yscst_nav,
        yscst_multicode,
        yscst_property,
        yscst_property_set,
        yscst_property_get,
        yscst_cntrl_try,
        yscst_cntrl_if,
        yscst_cntrl_catch,
        yscst_cntrl_for,
        yscst_cntrl_for_arg,
        yscst_cntrl_while,
        yscst_cntrl_dowhile,
        yscst_cntrl_switch,
        yscst_mthd,
        yscst_smthd,
        yscst_opmthd,
        yscst_case,
        yscst_case_default,
        yscst_decl,
        yscst_decllist,
        yscst_cnstmthd,
        yscst_mthdargs,
        yscst_mthdbody,
        yscst_statementlist,
        yscst_statement,
        yscst_type,
        yscst_bool,
        yscst_string,
        yscst_char,
        yscst_int8,
        yscst_uint8,
        yscst_int16,
        yscst_uint16,
        yscst_int32,
        yscst_uint32,
        yscst_int64,
        yscst_uint64,
        yscst_float,
        yscst_double,
        yscst_auto,
        yscst_void,
        yscst_op_inc_r0,
        yscst_op_dec_r0,
        yscst_op_not_v1,
        yscst_op_add_v2,
        yscst_op_add_r1,
        yscst_op_sub_v2,
        yscst_op_sub_r1,
        yscst_op_mul_v2,
        yscst_op_mul_r1,
        yscst_op_div_v2,
        yscst_op_div_r1,
        yscst_op_bit_inv_v2,
        yscst_op_bit_inv_r1,
        yscst_op_bit_or_v2,
        yscst_op_bit_or_r1,
        yscst_op_bit_xor_v2,
        yscst_op_bit_xor_r1,
        yscst_op_bit_and_v2,
        yscst_op_bit_and_r1,
        yscst_op_log_or_v2,
        yscst_op_log_and_v2,
        yscst_op_log_equal_v2,
        yscst_op_log_notequal_v2,
        yscst_op_log_less_then_v2,
        yscst_op_log_greater_then_v2,
        yscst_op_mod_v2,
        yscst_op_lshift_v2,
        yscst_op_lshift_r1,
        yscst_op_rshift_v2,
        yscst_op_rshift_r1,
        yscst_exp_ternary,
        yscst_exp_log_or,
        yscst_exp_log_and,
        yscst_exp_bin_or,
        yscst_exp_bin_and,
        yscst_exp_bin_xor,
        yscst_exp_equal,
        yscst_exp_notequal,
        yscst_exp_less,
        yscst_exp_less_equal,
        yscst_exp_greater,
        yscst_exp_greater_equal,
        yscst_exp_lshift,
        yscst_exp_rshift,
        yscst_exp_add,
        yscst_exp_sub,
        yscst_exp_mul,
        yscst_exp_div,
        yscst_exp_mod,
        yscst_exp_pre_inc,
        yscst_exp_post_inc,
        yscst_exp_pre_dec,
        yscst_exp_post_dec,
        yscst_exp_is,
        yscst_exp_isnot,
        yscst_exp_log_not,
        yscst_exp_invert,
        yscst_typeof,
        yscst_new,
        yscst_null,
        yscst_call,
        yscst_getvar,
        yscst_setto,
        yscst_setto_auto,
        yscst_setto_type,
        yscst_valexp,
        yscst_this,
        yscst_valexp_var,
        yscst_setvar,
        yscst_setvar_add,
        yscst_setvar_sub,
        yscst_setvar_mul,
        yscst_setvar_div,
        yscst_setvar_mod,
        yscst_setvar_bin_or,
        yscst_setvar_bin_and,
        yscst_setvar_bin_xor,
        yscst_setvar_invert,
        yscst_setvar_rshift,
        yscst_setvar_lshift,
        yscst_val_true,
        yscst_val_false,
        yscst_val_number,
        yscst_val_number_hex,
        yscst_val_number_binary,
        yscst_val_string,
        yscst_val_char,
        yscst_calllist,
        yscst_callwith,
        yscst_expressionlist,
        yscst_return,
        yscst_continue,
        yscst_break,
        yscst_throw,
    };
}

%%

yaoosl: %empty
      | usingns yaoosl
      | classdef yaoosl
      | stmntlist yaoosl
      ;
identifier: YST_NAME                         { $$ = CSTNODEV(yscst_ident, $1); }
          | YST_NAME "." identifier          { $$ = CSTNODEV(yscst_ident, $1); CSTIMP($$, $3); }
          ;
identlist: identifier                        { $$ = CSTNODE(yscst_identlist); CSTPSH($$, $1); }
         | identifier ","                    { $$ = CSTNODE(yscst_identlist); CSTPSH($$, $1); }
         | identifier "," identifier         { $$ = CSTNODE(yscst_identlist); CSTPSH($$, $1); CSTIMP($$, $3); }
         ;
stdtype: "bool"                              { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_bool)); }
       | "string"                            { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_string)); }
       | "char"                              { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_char)); }
       | "int8"                              { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int8)); }
       | "uint8"                             { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint8)); }
       | "int16"                             { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int16)); }
       | "uint16"                            { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint16)); }
       | "int32"                             { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int32)); }
       | "uint32"                            { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint32)); }
       | "int64"                             { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int64)); }
       | "uint64"                            { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint64)); }
       | "float"                             { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_float)); }
       | "double"                            { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_double)); }
       ;
vtype: "void"                                { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_void)); }
     | stdtype                               { $$ = $1; }
     | identifier
     ;
usingns: "using" identifier                  { $$ = CSTNODE(yscst_using); CSTPSH($$, $2); }
       ;
encpsl: "public"                             { $$ = CSTNODE(yscst_encapsulation_public); }
             | "internal"                    { $$ = CSTNODE(yscst_encapsulation_internal); }
             | "derived"                     { $$ = CSTNODE(yscst_encapsulation_derived); }
             | "private"                     { $$ = CSTNODE(yscst_encapsulation_private); }
             ;
classhead: encpsl "class" YST_NAME           { $$ = CSTNODE(yscst_classhead); CSTPSH($$, $1); CSTPSH($$, CSTNODEV(yscst_ident, $3)); }
         ;
classbody: mthd classbody                    { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); CSTIMP($$, $2); }
         | mthd                              { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); }
         | cnstmthd classbody                { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); CSTIMP($$, $2); }
         | cnstmthd                          { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); }
         | opmthd classbody                  { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); CSTIMP($$, $2); }
         | opmthd                            { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); }
         | property classbody                { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); CSTIMP($$, $2); }
         | property                          { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); }
         | error classbody                   { $$ = CSTNODE(yscst_error); CSTIMP($$, $2); }
         | error                             { $$ = CSTNODE(yscst_error); }
         ;
classdef: classhead ":" identlist "{" classbody "}"    { $$ = CSTNODE(yscst_classdef); CSTPSH($$, $1); CSTPSH($$, $3); CSTPSH($$, $5); }
        | classhead "{" classbody "}"                  { $$ = CSTNODE(yscst_classdef); CSTPSH($$, $1); CSTPSH($$, $3); }
        | classhead ":" identlist "{" "}"              { $$ = CSTNODE(yscst_classdef); CSTPSH($$, $1); CSTPSH($$, $3); }
        | classhead "{" "}"                            { $$ = CSTNODE(yscst_classdef); CSTPSH($$, $1); }
        ;
mthdargs: "(" ")"                                      { $$ = CSTNODE(yscst_mthdargs); }
        | "(" decllist ")"                             { $$ = CSTNODE(yscst_mthdargs); CSTPSH($$, $2); }
mthd: encpsl vtype YST_NAME mthdargs mthdbody          { $$ = CSTNODE(yscst_mthd); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, CSTNODEV(yscst_ident, $3)); CSTPSH($$, $4); CSTPSH($$, $5); }
    | encpsl "static" vtype YST_NAME mthdargs mthdbody { $$ = CSTNODE(yscst_smthd); CSTPSH($$, $1); CSTPSH($$, $3); CSTPSH($$, CSTNODEV(yscst_ident, $4)); CSTPSH($$, $5); CSTPSH($$, $6); }
    ;
cnstmthd: encpsl YST_NAME mthdargs mthdbody            { $$ = CSTNODE(yscst_cnstmthd); CSTPSH($$, $1); CSTPSH($$, CSTNODEV(yscst_ident, $2)); CSTPSH($$, $3); CSTPSH($$, $4); }
        ;
opmthd: encpsl op0 opargs0 mthdbody   { $$ = CSTNODE(yscst_opmthd); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, $3); CSTPSH($$, $4); }
      | encpsl op1 opargs1 mthdbody   { $$ = CSTNODE(yscst_opmthd); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, $3); CSTPSH($$, $4); }
      | encpsl op2 opargs2 mthdbody   { $$ = CSTNODE(yscst_opmthd); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, $3); CSTPSH($$, $4); }
      ;
op0: vtype "operator" "++"            { $$ = CSTNODE(yscst_op_inc_r0); }
   | vtype "operator" "--"            { $$ = CSTNODE(yscst_op_dec_r0); }
   ;
op1: vtype "operator" "!"             { $$ = CSTNODE(yscst_op_not_v1); }
   | vtype "operator" "+="            { $$ = CSTNODE(yscst_op_add_r1); }
   | vtype "operator" "-="            { $$ = CSTNODE(yscst_op_sub_r1); }
   | vtype "operator" "*="            { $$ = CSTNODE(yscst_op_mul_r1); }
   | vtype "operator" "/="            { $$ = CSTNODE(yscst_op_div_r1); }
   | vtype "operator" "|="            { $$ = CSTNODE(yscst_op_bit_or_r1); }
   | vtype "operator" "&="            { $$ = CSTNODE(yscst_op_bit_and_r1); }
   | vtype "operator" "^="            { $$ = CSTNODE(yscst_op_bit_xor_r1); }
   | vtype "operator" "~="            { $$ = CSTNODE(yscst_op_bit_inv_r1); }
   | vtype "operator" "<<="           { $$ = CSTNODE(yscst_op_lshift_r1); }
   | vtype "operator" ">>="           { $$ = CSTNODE(yscst_op_rshift_r1); }
   ;
op2: "static" vtype "operator" "+"    { $$ = CSTNODE(yscst_op_add_v2); }
   | "static" vtype "operator" "-"    { $$ = CSTNODE(yscst_op_sub_v2); }
   | "static" vtype "operator" "*"    { $$ = CSTNODE(yscst_op_mul_v2); }
   | "static" vtype "operator" "/"    { $$ = CSTNODE(yscst_op_div_v2); }
   | "static" vtype "operator" "|"    { $$ = CSTNODE(yscst_op_bit_or_v2); }
   | "static" vtype "operator" "&"    { $$ = CSTNODE(yscst_op_bit_and_v2); }
   | "static" vtype "operator" "^"    { $$ = CSTNODE(yscst_op_bit_xor_v2); }
   | "static" vtype "operator" "~"    { $$ = CSTNODE(yscst_op_bit_inv_v2); }
   | "static" vtype "operator" "||"   { $$ = CSTNODE(yscst_op_log_or_v2); }
   | "static" vtype "operator" "&&"   { $$ = CSTNODE(yscst_op_log_and_v2); }
   | "static" vtype "operator" "%"    { $$ = CSTNODE(yscst_op_mod_v2); }
   | "static" vtype "operator" "<<"   { $$ = CSTNODE(yscst_op_lshift_v2); }
   | "static" vtype "operator" ">>"   { $$ = CSTNODE(yscst_op_rshift_v2); }
   | "static" vtype "operator" "=="   { $$ = CSTNODE(yscst_op_log_equal_v2); }
   | "static" vtype "operator" "!="   { $$ = CSTNODE(yscst_op_log_notequal_v2); }
   | "static" vtype "operator" ">="   { $$ = CSTNODE(yscst_op_log_greater_then_v2); }
   | "static" vtype "operator" "<="   { $$ = CSTNODE(yscst_op_log_less_then_v2); }
   ;
opargs0: "(" ")"                      {  $$ = CSTNODE(yscst_mthdargs); };
opargs1: "(" decl ")"                 {  $$ = CSTNODE(yscst_mthdargs); CSTPSH($$, $2); };
opargs2: "(" decl "," decl ")"        {  $$ = CSTNODE(yscst_mthdargs); CSTPSH($$, $2); CSTPSH($$, $4); };

decl: stdtype YST_NAME                { $$ = CSTNODEV(yscst_decl, $2); CSTPSH($$, $1); }
    | identifier YST_NAME             { $$ = CSTNODEV(yscst_decl, $2); CSTPSH($$, $1); }
    ;
decllist: decl                        { $$ = CSTNODE(yscst_decllist); CSTPSH($$, $1); }
        | decl ","                    { $$ = CSTNODE(yscst_decllist); CSTPSH($$, $1); }
        | decl "," decllist           { $$ = CSTNODE(yscst_decllist); CSTPSH($$, $1); CSTIMP($$, $3); }
        ;
property: encpsl identifier YST_NAME ";"                       {  $$ = CSTNODE(yscst_property); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, CSTNODEV(yscst_ident, $3)); };
        | encpsl identifier YST_NAME "{" prop_get prop_set "}" {  $$ = CSTNODE(yscst_property); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, CSTNODEV(yscst_ident, $3)); CSTPSH($$, $5); CSTPSH($$, $6); };
        | encpsl identifier YST_NAME "{" prop_get "}"          {  $$ = CSTNODE(yscst_property); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, CSTNODEV(yscst_ident, $3)); CSTPSH($$, $5); };
        | encpsl identifier YST_NAME "{" prop_set prop_get "}" {  $$ = CSTNODE(yscst_property); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, CSTNODEV(yscst_ident, $3)); CSTPSH($$, $5); CSTPSH($$, $6); };
        | encpsl identifier YST_NAME "{" prop_set "}"          {  $$ = CSTNODE(yscst_property); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, CSTNODEV(yscst_ident, $3)); CSTPSH($$, $5); };
        | encpsl stdtype YST_NAME ";"                          {  $$ = CSTNODE(yscst_property); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, CSTNODEV(yscst_ident, $3)); };
        | encpsl stdtype YST_NAME "{" prop_get prop_set "}"    {  $$ = CSTNODE(yscst_property); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, CSTNODEV(yscst_ident, $3)); CSTPSH($$, $5); CSTPSH($$, $6); };
        | encpsl stdtype YST_NAME "{" prop_get "}"             {  $$ = CSTNODE(yscst_property); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, CSTNODEV(yscst_ident, $3)); CSTPSH($$, $5); };
        | encpsl stdtype YST_NAME "{" prop_set prop_get "}"    {  $$ = CSTNODE(yscst_property); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, CSTNODEV(yscst_ident, $3)); CSTPSH($$, $5); CSTPSH($$, $6); };
        | encpsl stdtype YST_NAME "{" prop_set "}"             {  $$ = CSTNODE(yscst_property); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, CSTNODEV(yscst_ident, $3)); CSTPSH($$, $5); };
        ;
prop_set: "set" ";"                     {  $$ = CSTNODE(yscst_property_set); }
        | "set" mthdbody                {  $$ = CSTNODE(yscst_property_set); CSTPSH($$, $2); }
        ;
prop_get: "get" ";"                     {  $$ = CSTNODE(yscst_property_get); }
        | "get" mthdbody                {  $$ = CSTNODE(yscst_property_get); CSTPSH($$, $2); }
        ;
mthdbody: "{" stmntlist "}"             {  $$ = CSTNODE(yscst_mthdbody); CSTIMP($$, $2); }
        | "{" "}"                       {  $$ = CSTNODE(yscst_mthdbody); }
        ;
stmntlist: stmnt                        { $$ = CSTNODE(yscst_statementlist); CSTPSH($$, $1); }
         | stmnt stmntlist              { $$ = CSTNODE(yscst_statementlist); CSTPSH($$, $1); CSTIMP($$, $2); }
         ;
stmnt: ";"                              { $$ = CSTNODE(yscst_empty); }
     | "return" exp ";"                 { $$ = CSTNODE(yscst_return); CSTPSH($$, $2); }
     | "return" ";"                     { $$ = CSTNODE(yscst_return); }
     | "continue" ";"                   { $$ = CSTNODE(yscst_continue); }
     | "break" ";"                      { $$ = CSTNODE(yscst_break); }
     | "throw" exp ";"                  { $$ = CSTNODE(yscst_throw); CSTPSH($$, $2); }
     | exp ";"                          { $$ = $1; }
     | "{" "}"                          { $$ = CSTNODE(yscst_empty); }
     | "{" stmntlist "}"                { $$ = $2; }
     | cntrl_if                         { $$ = $1; }
     | cntrl_try                        { $$ = $1; }
     | cntrl_for                        { $$ = $1; }
     | cntrl_while                      { $$ = $1; }
     | cntrl_dowhile                    { $$ = $1; }
     | cntrl_switch                     { $$ = $1; }
     ;
cntrl_if: "if" exp stmnt                {  $$ = CSTNODE(yscst_cntrl_if); CSTPSH($$, $2); CSTPSH($$, $3); }
        | "if" exp stmnt "else" stmnt   {  $$ = CSTNODE(yscst_cntrl_if); CSTPSH($$, $2); CSTPSH($$, $3); CSTPSH($$, $5); }
        ;
cntrl_try: "try" stmnt                             {  $$ = CSTNODE(yscst_cntrl_try); CSTPSH($$, $2); }
         | "try" stmnt cntrl_catch                 {  $$ = CSTNODE(yscst_cntrl_try); CSTPSH($$, $2); CSTPSH($$, $3); }
         | "try" stmnt cntrl_catch "finally" stmnt {  $$ = CSTNODE(yscst_cntrl_try); CSTPSH($$, $2); CSTPSH($$, $3); CSTPSH($$, $5); }
         | "try" stmnt "finally" stmnt             {  $$ = CSTNODE(yscst_cntrl_try); CSTPSH($$, $2); CSTPSH($$, $4); }
         ;
cntrl_catch: "catch" stmnt                         {  $$ = CSTNODE(yscst_cntrl_catch); CSTPSH($$, $2); }
           | "catch" "(" decllist ")"              {  $$ = CSTNODE(yscst_cntrl_catch); CSTPSH($$, $3); }
           | "catch" stmnt cntrl_catch             {  $$ = CSTNODE(yscst_cntrl_catch); CSTPSH($$, $2); CSTIMP($$, $3); }
           | "catch" "(" decllist ")" cntrl_catch  {  $$ = CSTNODE(yscst_cntrl_catch); CSTPSH($$, $3); CSTIMP($$, $5); }
           ;
cntrl_for: "for" "(" cntrl_for1 ";" cntrl_for2 ";" cntrl_for3 ")" stmnt {  $$ = CSTNODE(yscst_cntrl_for); CSTPSH($$, $3); CSTPSH($$, $5) ;CSTPSH($$, $7); CSTPSH($$, $9); }
         ;
cntrl_for1: %empty                     { $$ = CSTNODE(yscst_cntrl_for_arg); }
          | exp                        { $$ = CSTNODE(yscst_cntrl_for_arg); CSTPSH($$, $1); }
          ;
cntrl_for2: %empty                     { $$ = CSTNODE(yscst_cntrl_for_arg); }
          | exp                        { $$ = CSTNODE(yscst_cntrl_for_arg); CSTPSH($$, $1); }
          ;
cntrl_for3: %empty                     { $$ = CSTNODE(yscst_cntrl_for_arg); }
          | exp                        { $$ = CSTNODE(yscst_cntrl_for_arg); CSTPSH($$, $1); }
          ;
cntrl_while: "while" exp stmnt         { $$ = CSTNODE(yscst_cntrl_while); CSTPSH($$, $2); CSTPSH($$, $3); }
           ;
cntrl_dowhile: "do" stmnt "while" exp ";" { $$ = CSTNODE(yscst_cntrl_dowhile); CSTPSH($$, $2); CSTPSH($$, $4); }
             ;
cntrl_switch: "switch" exp "{" cntrl_switchbody "}" { $$ = CSTNODE(yscst_cntrl_switch); CSTPSH($$, $2); CSTPSH($$, $4); }
            ;
cntrl_case: "case" cnstexp ":"                        { $$ = CSTNODE(yscst_case); CSTPSH($$, $2); }
          | "default" ":"                            { $$ = CSTNODE(yscst_case_default); }
          ;            
cntrl_switchbody: cntrl_case                         { $$ = CSTNODE(yscst_statementlist); CSTPSH($$, $1); }
                | cntrl_case cntrl_switchbody        { $$ = CSTNODE(yscst_statementlist); CSTPSH($$, $1); CSTIMP($$, $2); }
                | stmnt                              { $$ = CSTNODE(yscst_statementlist); CSTPSH($$, $1); }
                | stmnt cntrl_switchbody             { $$ = CSTNODE(yscst_statementlist); CSTPSH($$, $1); CSTIMP($$, $2); }
                ;
exp: exp01                              { $$ = $1; }
   ;
exp01: exp02                            { $$ = $1; }
     | exp02 "?" exp ":" exp            { $$ = CSTNODE(yscst_exp_ternary); CSTPSH($$, $1); CSTPSH($$, $3); CSTPSH($$, $5); }
     ;
exp02: exp03                            { $$ = $1; }
     | exp03 "||" exp                   { $$ = CSTNODE(yscst_exp_log_or); CSTPSH($$, $1); CSTPSH($$, $3); }
     ;
exp03: exp04                            { $$ = $1; }
     | exp04 "&&" exp                   { $$ = CSTNODE(yscst_exp_log_and); CSTPSH($$, $1); CSTPSH($$, $3); }
     ;
exp04: exp05                            { $$ = $1; }
     | exp05 "|" exp                    { $$ = CSTNODE(yscst_exp_bin_or); CSTPSH($$, $1); CSTPSH($$, $3); }
     | exp05 "^" exp                    { $$ = CSTNODE(yscst_exp_bin_xor); CSTPSH($$, $1); CSTPSH($$, $3); }
     ;
exp05: exp06                            { $$ = $1; }
     | exp06 "&" exp                    { $$ = CSTNODE(yscst_exp_bin_and); CSTPSH($$, $1); CSTPSH($$, $3); }
     ;
exp06: exp07                            { $$ = $1; }
     | exp07 "==" exp                   { $$ = CSTNODE(yscst_exp_equal); CSTPSH($$, $1); CSTPSH($$, $3); }
     | exp07 "!=" exp                   { $$ = CSTNODE(yscst_exp_notequal); CSTPSH($$, $1); CSTPSH($$, $3); }
     ;
exp07: exp08                            { $$ = $1; }
     | exp08 "<"  exp                   { $$ = CSTNODE(yscst_exp_less); CSTPSH($$, $1); CSTPSH($$, $3); }
     | exp08 "<=" exp                   { $$ = CSTNODE(yscst_exp_less_equal); CSTPSH($$, $1); CSTPSH($$, $3); }
     | exp08 ">"  exp                   { $$ = CSTNODE(yscst_exp_greater); CSTPSH($$, $1); CSTPSH($$, $3); }
     | exp08 ">=" exp                   { $$ = CSTNODE(yscst_exp_greater_equal); CSTPSH($$, $1); CSTPSH($$, $3); }
     ;
exp08: exp09                            { $$ = $1; }
     | exp09 "<<" exp                   { $$ = CSTNODE(yscst_exp_lshift); CSTPSH($$, $1); CSTPSH($$, $3); }
     | exp09 ">>" exp                   { $$ = CSTNODE(yscst_exp_rshift); CSTPSH($$, $1); CSTPSH($$, $3); }
     ;
exp09: exp10                            { $$ = $1; }
     | exp10 "+" exp                    { $$ = CSTNODE(yscst_exp_add); CSTPSH($$, $1); CSTPSH($$, $3); }
     | exp10 "-" exp                    { $$ = CSTNODE(yscst_exp_sub); CSTPSH($$, $1); CSTPSH($$, $3); }
     ;
exp10: exp11                            { $$ = $1; }
     | exp11 "*" exp                    { $$ = CSTNODE(yscst_exp_mul); CSTPSH($$, $1); CSTPSH($$, $3); }
     | exp11 "/" exp                    { $$ = CSTNODE(yscst_exp_div); CSTPSH($$, $1); CSTPSH($$, $3); }
     | exp11 "%" exp                    { $$ = CSTNODE(yscst_exp_mod); CSTPSH($$, $1); CSTPSH($$, $3); }
     ;
exp11: exp12                            { $$ = $1; }
     | exp12 "++"                       { $$ = CSTNODE(yscst_exp_post_inc); CSTPSH($$, $1); }
     | exp12 "--"                       { $$ = CSTNODE(yscst_exp_post_dec); CSTPSH($$, $1); }
     | "++" exp12                       { $$ = CSTNODE(yscst_exp_pre_inc); CSTPSH($$, $2); }
     | "--" exp12                       { $$ = CSTNODE(yscst_exp_pre_dec); CSTPSH($$, $2);}
     | exp12 "is"  stdtype              { $$ = CSTNODE(yscst_exp_is); CSTPSH($$, $1); CSTPSH($$, $3); }
     | exp12 "!is" stdtype              { $$ = CSTNODE(yscst_exp_isnot); CSTPSH($$, $1); CSTPSH($$, $3); }
     | exp12 "is"  identifier           { $$ = CSTNODE(yscst_exp_is); CSTPSH($$, $1); CSTPSH($$, $3); }
     | exp12 "!is" identifier           { $$ = CSTNODE(yscst_exp_isnot); CSTPSH($$, $1); CSTPSH($$, $3); }
     ;
exp12: exp13                            { $$ = $1; }
     | "!" exp13                        { $$ = CSTNODE(yscst_exp_log_not); CSTPSH($$, $2); }
     | "~" exp13                        { $$ = CSTNODE(yscst_exp_invert); CSTPSH($$, $2); }
     ;
cnstexp: "true"                         { $$ = CSTNODE(yscst_val_true); }
       | "false"                        { $$ = CSTNODE(yscst_val_false); }
       | YST_NUMBER                     { $$ = CSTNODEV(yscst_val_number, $1); }
       | YST_HEXNUMBER                  { $$ = CSTNODEV(yscst_val_number_hex, $1); }
       | YST_BINARYNUMBER               { $$ = CSTNODEV(yscst_val_number_binary, $1); }
       | YST_STRINGVAL                  { $$ = CSTNODEV(yscst_val_string, $1); }
       | YST_CHARVAL                    { $$ = CSTNODEV(yscst_val_char, $1); }
       ;
bexp: "(" exp ")"                       { $$ = CSTNODE(yscst_valexp); CSTPSH($$, $2); }
    ;
refexp: "typeof" "(" stdtype ")"        { $$ = CSTNODE(yscst_typeof); CSTPSH($$, $3); }
      | "typeof" "(" identifier ")"     { $$ = CSTNODE(yscst_typeof); CSTPSH($$, $3); }
      | "new" identifier calllist       { $$ = CSTNODE(yscst_new); CSTPSH($$, $2); CSTPSH($$, $3); }
      | "null"                          { $$ = CSTNODE(yscst_null); }
      | "this"                          { $$ = CSTNODE(yscst_this); }
      | bexp                            { $$ = $1; }
      ;
calllist: "(" ")"                       { $$ = CSTNODE(yscst_calllist); }
        | "(" expressionlist ")"        { $$ = CSTNODE(yscst_calllist); CSTIMP($$, $2); }
        ;
expressionlist: exp                     { $$ = CSTNODE(yscst_expressionlist); CSTPSH($$, $1); }
              | exp ","                 { $$ = CSTNODE(yscst_expressionlist); CSTPSH($$, $1); }
              | exp "," expressionlist  { $$ = CSTNODE(yscst_expressionlist); CSTPSH($$, $1); CSTIMP($$, $3); }
              ;
assign_post: "="   exp                  { $$ = CSTNODE(yscst_setvar); CSTPSH($$, $2); }
           | "+="  exp                  { $$ = CSTNODE(yscst_setvar_add); CSTPSH($$, $2); }
           | "-="  exp                  { $$ = CSTNODE(yscst_setvar_sub); CSTPSH($$, $2); }
           | "*="  exp                  { $$ = CSTNODE(yscst_setvar_mul); CSTPSH($$, $2); }
           | "/="  exp                  { $$ = CSTNODE(yscst_setvar_div); CSTPSH($$, $2); }
           | "%="  exp                  { $$ = CSTNODE(yscst_setvar_mod); CSTPSH($$, $2); }
           | "|="  exp                  { $$ = CSTNODE(yscst_setvar_bin_or); CSTPSH($$, $2); }
           | "&="  exp                  { $$ = CSTNODE(yscst_setvar_bin_and); CSTPSH($$, $2); }
           | "^="  exp                  { $$ = CSTNODE(yscst_setvar_bin_xor); CSTPSH($$, $2); }
           | "~="  exp                  { $$ = CSTNODE(yscst_setvar_invert); CSTPSH($$, $2); }
           | ">>=" exp                  { $$ = CSTNODE(yscst_setvar_rshift); CSTPSH($$, $2); }
           | "<<=" exp                  { $$ = CSTNODE(yscst_setvar_lshift); CSTPSH($$, $2); }
           ;
call_post: calllist                     { $$ = $1; }
         | calllist "with" identifier   { $$ = CSTNODE(yscst_callwith); CSTPSH($$, $1); CSTPSH($$, $3); }
         ;



              
exp13: assign                           { $$ = $1; }
     | call                             { $$ = $1; }
     | refexp                           { $$ = $1; }
     | cnstexp                          { $$ = $1; }
     ;
assign: bexp "." identifier assign_post { $$ = CSTNODE(yscst_setto); }
      | "auto" YST_NAME assign_post     { $$ = CSTNODE(yscst_setto_auto); }
      | stdtype YST_NAME assign_post    { $$ = CSTNODE(yscst_setto_type); }
      | identifier assign_post          { $$ = CSTNODE(yscst_setto); }
      | identifier YST_NAME assign_post { $$ = CSTNODE(yscst_setto_type); }
      ;
call: bexp "." identifier call_post     { $$ = CSTNODE(yscst_call); }
    | identifier call_post              { $$ = CSTNODE(yscst_call); }
    ;