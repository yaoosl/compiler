
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

%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
%parse-param { struct yaoosl_compilationunit* cu };

%type <str> ident
%type <i> propertynav
%type <i> expressionlist

%token <str> YST_NAME
%token YST_COLON
%token YST_CLASS
%token YST_WITH
%token YST_OPERATOR
%token YST_CURLYO
%token YST_CURLYC
%token YST_ROUNDO
%token YST_ROUNDC
%token YST_SQUAREO
%token YST_SQUAREC
%token YST_SC
%token YST_COMMA
%token YST_USING
%token YST_GET
%token YST_EXTERN
%token YST_SET
%token YST_THIS
%token YST_PLUSPLUS
%token YST_PLUS
%token YST_MINUSMINUS
%token YST_MINUS
%token YST_STAR
%token YST_SLASH
%token YST_LTLT
%token YST_LTEQ
%token YST_LT
%token YST_GTGT
%token YST_GTEQ
%token YST_GT
%token YST_EQEQ
%token YST_NOTEQ
%token YST_NOT
%token YST_INVERT
%token YST_MODULO
%token YST_TYPEOF
%token YST_VAR
%token YST_EQ
%token YST_EQXOR
%token YST_EQOR
%token YST_EQAND
%token YST_EQSLAH
%token YST_EQSTAR
%token YST_EQMINUS
%token YST_EQPLUS
%token YST_EQMODULO
%token YST_QUESTIONMARK
%token YST_LOGICAL_OR
%token YST_LOGICAL_AND
%token YST_ARITHMETICAL_OR
%token YST_ARITHMETICAL_AND
%token YST_AS
%token YST_IS
%token YST_IS_NOT
%token YST_TRUE
%token YST_FALSE
%token YST_DOT
%token <d> YST_NUMBER
%token <ll> YST_HEXNUMBER
%token <ll> YST_BINARYNUMBER
%token <str> YST_STRING
%token <str> YST_CHAR
%token YST_NEW
%token YST_PRIVATE
%token YST_PROTECTED
%token YST_INTERNAL
%token YST_PUBLIC
%token YST_STATIC
%token YST_IF
%token YST_ELSE
%token YST_FOR
%token YST_WHILE
%token YST_DO
%token YST_TRY
%token YST_CATCH
%token YST_THROW
%token YST_VOID
%token YST_NULL
%token YST_BREAK
%token YST_CONTINUE
%token YST_RETURN

%type <cst> yaoosl_prefix
%type <cst> yaoosl_prefix2
%type <cst> yaoosl_body
%type <cst> encapsulation
%type <cst> ys_class_head
%type <cst> ys_class_base
%type <cst> ys_class_body
%type <cst> ys_class
%type <cst> multicode
%type <cst> method
%type <cst> property


%code requires {
    enum yaoosl_cst_type
    {
        yscst_root,
        yscst_prefix,
        yscst_body,
        yscst_ident,
        yscst_encapsulation,
        yscst_classes,
        yscst_class_head,
        yscst_class_base,
        yscst_class_body,
        yscst_multicode,
        yscst_property,
        yscst_method,
        yscst_,
        yscst_,
        yscst_,
        yscst_,
    }
}

%%

yaoosl: %empty
| yaoosl_prefix
| yaoosl_prefix yaoosl_body
| yaoosl_body
;

yaoosl_prefix: YST_USING ident ';' yaoosl_prefix2 { $$ = CSTNODE(yscst_prefix); CSTPSH($$, $2); CSTIMP($$, $4); }
            ;
yaoosl_prefix2: %empty
            | YST_USING ident ';' yaoosl_prefix2 { $$ = CSTNODE(yscst_prefix); CSTPSH($$, $2); CSTIMP($$, $4); }
            ;
yaoosl_body: ys_class yaoosl_body  { $$ = CSTNODE(yscst_body); CSTPSH($$, $1); CSTIMP($$, $2); }
           | multicode yaoosl_body { $$ = CSTNODE(yscst_body); CSTPSH($$, $1); CSTIMP($$, $2); }
           | ys_class              { $$ = CSTNODE(yscst_body); CSTPSH($$, $1); }
           | multicode             { $$ = CSTNODE(yscst_body); CSTPSH($$, $1); }
           ;
ident: YST_NAME           { $$ = CSTNODE(yscst_ident, $1); }
     | YST_NAME '.' ident { $$ = CSTNODE(yscst_ident, $1); CSTIMP($$, $2); }
     ;
encapsulation: YST_PUBLIC    { $$ = CSTNODE(yscst_encapsulation, "public"); }
             | YST_INTERNAL  { $$ = CSTNODE(yscst_encapsulation, "internal"); }
             | YST_PROTECTED { $$ = CSTNODE(yscst_encapsulation, "protected"); }
             | YST_PRIVATE   { $$ = CSTNODE(yscst_encapsulation, "private"); }
             ;
ys_class_head: encapsulation YST_CLASS YST_NAME
               { $$ = CSTNODE(yscst_class_head); CSTPSH($$, $1); CSTPSH($$, $3); }
             | encapsulation YST_CLASS YST_NAME ':' ys_class_base
               { $$ = CSTNODE(yscst_class_head); CSTPSH($$, $1); CSTPSH($$, $3); CSTPSH($$, $5); }
ys_class_base: ident                    { $$ = CSTNODE(yscst_class_base); CSTPSH($$, $1); }
             | ident ',' ys_class_base; { $$ = CSTNODE(yscst_class_base); CSTPSH($$, $1); CSTIMP($$, $3); }
ys_class_body: method                 { $$ = CSTNODE(yscst_body); CSTPSH($$, $1); }
             | property               { $$ = CSTNODE(yscst_body); CSTPSH($$, $1); }
             | method ys_class_body   { $$ = CSTNODE(yscst_body); CSTPSH($$, $1); CSTIMP($$, $2); }
             | property ys_class_body { $$ = CSTNODE(yscst_body); CSTPSH($$, $1); CSTIMP($$, $2); }
             ;
ys_class: ys_class_head '{' ys_class_body '}'
        | ys_class_head '{' '}'
        ;
method:
property:
multicode: