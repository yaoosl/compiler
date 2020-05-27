
%code top {
    #include <malloc.h>
    #include <string.h>
    #include <stdio.h>
    #include "yaoosl_emit.h"
    #include "yaoosl_operators.h"
    #include "string_op.h"
    #define YSSTR(IN) #IN
    #define YSEMIT(MTHD) yaoosl_emit_ ## MTHD
    #define YSEMITC(MTHD) YSEMIT(create_ ## MTHD)
    #define YSEMITCC(MTHD) YSEMITC(class_ ## MTHD)
    #define YSEMITCM(MTHD) YSEMITC(method_ ## MTHD)
    #define YSEMITCP(MTHD) YSEMITC(property_ ## MTHD)
    
    
    #define ERRMSG_EXPECTED_NO_VALUE "Expected no value."
    #define ERRMSG_EXPECTED_VALUE "Expected value."
    #define ERRMSG_EXPECTED_CONSTRUCTOR "Expected constructor."
    #define ERRMSG_UNEXPECTED_BREAK "Encountered unexpected break."
    #define ERRMSG_STATIC_VARIABLE_NOT_SUPPORTED "Static variables are not (yet) supported."
    
    
    #if _WIN32
        // FU bloody configuration hell!
        // Force the macros to be defined already to avoid
        // "inconsistent dll linkage" with malloc and free.
        #define YYMALLOC
        #define YYFREE
    #endif

    #define CSTNODE(NODE)      { NODE, code_line, code_column, code_index, 0,   0, 0, 0 }
    #define CSTNODE(NODE, VAL) { NODE, code_line, code_column, code_index, VAL, 0, 0, 0 }
    #define CSTPSH(P, C) yaoosl_cstnode_push_child(&(P, C);
    #define CSTIMP(TO, FROM) { yaoosl_cstnode_transfer_to(&FROM, &TO); yaoosl_cstnode_invalidate(&FROM); }
}

%union {
    short s;
    int i;
    long l;
    long long ll;
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
%token YST_LT "<"
%token YST_LTLT "<<"
%token YST_LTEQUAL "<="
%token YST_LTLTEQUAL "<<="
%token YST_GT ">"
%token YST_GTGT ">>"
%token YST_GTEQUAL ">="
%token YST_GTGTEQUAL ">>="
%token YST_EQUALEQUAL "=="
%token YST_EXCLAMATIONMARKEQUAL "!="
%token YST_STATIC "static"


%type <cst> usingns
%type <cst> ident
%type <cst> identlist
%type <cst> encapsulation
%type <cst> classhead
%type <cst> classbody
%type <cst> classdef
%type <cst> multicode
%type <cst> mthd
%type <cst> mthdbody
%type <cst> opmthd
%type <cst> cnstmthd
%type <cst> op0
%type <cst> op1
%type <cst> op2
%type <cst> opargs0
%type <cst> opargs1
%type <cst> opargs2
%type <cst> property
%type <cst> type
%type <cst> voidabletype
%type <cst> autoabletype


%code requires {
    enum yaoosl_cst_type
    {
        yscst_error,
        yscst_root,
        yscst_using,
        yscst_body,
        yscst_ident,
        yscst_identlist,
        yscst_encapsulation_public,
        yscst_encapsulation_internal,
        yscst_encapsulation_derived,
        yscst_encapsulation_private,
        ysct_classdef,
        yscst_classhead,
        yscst_classbody,
        yscst_multicode,
        yscst_property,
        yscst_mthd,
        yscst_opmthd,
        yscst_cnstmthd,
        yscst_mthdargs,
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
    }
}

%%

yaoosl: %empty
      | usingns yaoosl
      | classdef yaoosl
      | multicode yaoosl
      ;
ident: YST_NAME           { $$ = CSTNODE(yscst_ident, $1); }
     | YST_NAME "." ident { $$ = CSTNODE(yscst_ident, $1); CSTIMP($$, $2); }
     ;
identlist: ident               { $$ = CSTNODE(yscst_identlist); CSTPSH($$, $1); }
         | ident "."           { $$ = CSTNODE(yscst_identlist); CSTPSH($$, $1); }
         | ident "." identlist { $$ = CSTNODE(yscst_identlist); CSTPSH($$, $1); CSTIMP($$, $3); }
         ;
type: ident    { $$ = CSTNODE(yscst_type); CSTPSH($$, $1); }
    | "bool"   { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_bool)); }
    | "string" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_string)); }
    | "char"   { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_char)); }
    | "int8"   { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int8)); }
    | "uint8"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint8)); }
    | "int16"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int16)); }
    | "uint16" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint16)); }
    | "int32"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int32)); }
    | "uint32" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint32)); }
    | "int64"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int64)); }
    | "uint64" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint64)); }
    | "float"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_float)); }
    | "double" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_double)); }
    ;
autoabletype: ident    { $$ = CSTNODE(yscst_type); CSTPSH($$, $1); }
            | "bool"   { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_bool)); }
            | "string" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_string)); }
            | "char"   { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_char)); }
            | "int8"   { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int8)); }
            | "uint8"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint8)); }
            | "int16"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int16)); }
            | "uint16" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint16)); }
            | "int32"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int32)); }
            | "uint32" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint32)); }
            | "int64"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int64)); }
            | "uint64" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint64)); }
            | "float"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_float)); }
            | "double" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_double)); }
            | "auto"   { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_auto)); }
            ;
voidabletype: ident    { $$ = CSTNODE(yscst_type); CSTPSH($$, $1); }
            | "bool"   { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_bool)); }
            | "string" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_string)); }
            | "char"   { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_char)); }
            | "int8"   { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int8)); }
            | "uint8"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint8)); }
            | "int16"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int16)); }
            | "uint16" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint16)); }
            | "int32"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int32)); }
            | "uint32" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint32)); }
            | "int64"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_int64)); }
            | "uint64" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_uint64)); }
            | "float"  { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_float)); }
            | "double" { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_double)); }
            | "void"   { $$ = CSTNODE(yscst_type); CSTPSH($$, CSTNODE(yscst_void)); }
            ;
usingns: "using" ident { $$ = CSTNODE(yscst_using); CSTPSH($$, $2); }
       ;
encapsulation: "public"   { $$ = CSTNODE(yscst_encapsulation_public); }
             | "internal" { $$ = CSTNODE(yscst_encapsulation_internal); }
             | "derived"  { $$ = CSTNODE(yscst_encapsulation_derived); }
             | "private"  { $$ = CSTNODE(yscst_encapsulation_private); }
             ;
classhead: encapsulation "class" YST_NAME { $$ = CSTNODE(yscst_classhead); CSTPSH($$, $1); CSTPSH($$, $3); }
         ;
classbody: mthd classbody     { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); CSTIMP($$, $2); }
         | mthd               { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); }
         | cnstmthd classbody { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); CSTIMP($$, $2); }
         | cnstmthd           { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); }
         | opmthd classbody   { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); CSTIMP($$, $2); }
         | opmthd             { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); }
         | property classbody { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); CSTIMP($$, $2); }
         | property           { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); }
         | error classbody    { $$ = CSTNODE(yscst_error); CSTIMP($$, $1); }
         | error              { $$ = CSTNODE(yscst_error); }
         ;
classdef: classhead ":" identlist "{" classbody "}" { $$ = CSTNODE(ysct_classdef); CSTPSH($$, $1); CSTPSH($$, 3); CSTPSH($$, 5); }
        | classhead "{" classbody "}"               { $$ = CSTNODE(ysct_classdef); CSTPSH($$, $1); CSTPSH($$, 3); }
        | classhead ":" identlist "{" "}"           { $$ = CSTNODE(ysct_classdef); CSTPSH($$, $1); CSTPSH($$, 3); }
        | classhead "{" "}"                         { $$ = CSTNODE(ysct_classdef); CSTPSH($$, $1); }
        ;
mthd:
cnstmthd:
opmthd: encapsulation op0 opargs0 mthdbody { $$ = CSTNODE(yscst_opmthd); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, $3); CSTPSH($$, $4); }
      | encapsulation op1 opargs1 mthdbody { $$ = CSTNODE(yscst_opmthd); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, $3); CSTPSH($$, $4); }
      | encapsulation op2 opargs2 mthdbody { $$ = CSTNODE(yscst_opmthd); CSTPSH($$, $1); CSTPSH($$, $2); CSTPSH($$, $3); CSTPSH($$, $4); }
      ;
op0: "void" "operator" "++"  { $$ = CSTNODE(yscst_op_inc_r0); }
   | "void" "operator" "--"  { $$ = CSTNODE(yscst_op_dec_r0); }
   ;
op1:  type  "operator" "!"   { $$ = CSTNODE(yscst_op_not_v1); }
   | "void" "operator" "+="  { $$ = CSTNODE(yscst_op_add_r1); }
   | "void" "operator" "-="  { $$ = CSTNODE(yscst_op_sub_r1); }
   | "void" "operator" "*="  { $$ = CSTNODE(yscst_op_mul_r1); }
   | "void" "operator" "/="  { $$ = CSTNODE(yscst_op_div_r1); }
   | "void" "operator" "|="  { $$ = CSTNODE(yscst_op_bit_or_r1); }
   | "void" "operator" "&="  { $$ = CSTNODE(yscst_op_bit_and_r1); }
   | "void" "operator" "^="  { $$ = CSTNODE(yscst_op_bit_xor_r1); }
   | "void" "operator" "~="  { $$ = CSTNODE(yscst_op_bit_inv_r1); }
   | "void" "operator" "<<=" { $$ = CSTNODE(yscst_op_lshift_r1); }
   | "void" "operator" ">>=" { $$ = CSTNODE(yscst_op_rshift_r1); }
   ;
op2: "static"  type  "operator" "+"   { $$ = CSTNODE(yscst_op_add_v2); }
   | "static"  type  "operator" "-"   { $$ = CSTNODE(yscst_op_sub_v2); }
   | "static"  type  "operator" "*"   { $$ = CSTNODE(yscst_op_mul_v2); }
   | "static"  type  "operator" "/"   { $$ = CSTNODE(yscst_op_div_v2); }
   | "static"  type  "operator" "|"   { $$ = CSTNODE(yscst_op_bit_or_v2); }
   | "static"  type  "operator" "&"   { $$ = CSTNODE(yscst_op_bit_and_v2); }
   | "static"  type  "operator" "^"   { $$ = CSTNODE(yscst_op_bit_xor_v2); }
   | "static"  type  "operator" "~"   { $$ = CSTNODE(yscst_op_bit_inv_v2); }
   | "static" "bool" "operator" "||"  { $$ = CSTNODE(yscst_op_log_or_v2); }
   | "static" "bool" "operator" "&&"  { $$ = CSTNODE(yscst_op_log_and_v2); }
   | "static"  type  "operator" "%"   { $$ = CSTNODE(yscst_op_mod_v2); }
   | "static"  type  "operator" "<<"  { $$ = CSTNODE(yscst_op_lshift_v2); }
   | "static"  type  "operator" ">>"  { $$ = CSTNODE(yscst_op_rshift_v2); }
   | "static" "bool" "operator" "=="  { $$ = CSTNODE(yscst_op_log_equal_v2); }
   | "static" "bool" "operator" "!="  { $$ = CSTNODE(yscst_op_log_notequal_v2); }
   | "static" "bool" "operator" ">="  { $$ = CSTNODE(yscst_op_log_greater_then_v2); }
   | "static" "bool" "operator" "<="  { $$ = CSTNODE(yscst_op_log_less_then_v2); }
   ;
opargs0: "(" ")" {  $$ = CSTNODE(yscst_mthdargs); };
opargs1: "(" declaration ")" {  $$ = CSTNODE(yscst_mthdargs); CSTPSH($$, $2); };
opargs2: "(" declaration "," declaration ")" {  $$ = CSTNODE(yscst_mthdargs); CSTPSH($$, $2); CSTPSH($$, $4); };

property:
multicode:
declaration: type YST_NAME;
mthdbody: