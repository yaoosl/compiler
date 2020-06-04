/* Start declarations and option settings */

%option prefix="yaoosl_"
%option nounistd
%option never-interactive
%option noyywrap
%option nounput
%option noinput
%option reentrant


/* Include bison file at the very top */
%top {
    #include "yaoosl.tab.h"
    #include <stdarg.h>
    #include <stdio.h>
    #define YY_DECL int yylex(struct yaoosl_compilationunit* yyscanner)
    #define YY_INPUT(buf,result,max_size)  {\
        result = yaoosl_yylex_get_next_char(yyget_extra(yyscanner), buf, max_size); \
        if (result <= 0) { result = YY_NULL; }\
    }
}


%s CCOMMENT

%%


"//".*                                 ;
"/*"                                   { BEGIN(CCOMMENT); }
<CCOMMENT>{
    "*/"                               { BEGIN(INITIAL); }
    "*"                                ; // eat the lone star
    \n                                 { yylineno++; }
    [^*\n]+                            ; // eat comment in chunks 
}
":"                                    { return YST_COLON; }
"using"                                { return YST_USING; }
"with"                                 { return YST_WITH; }
"class"                                { return YST_CLASS; }
"operator"                             { return YST_OPERATOR; }
"new"                                  { return YST_NEW; }
"private"                              { return YST_PRIVATE; }
"internal"                             { return YST_INTERNAL; }
"derived"                              { return YST_DERIVED; }
"public"                               { return YST_PUBLIC; }
"static"                               { return YST_STATIC; }
"if"                                   { return YST_IF; }
"else"                                 { return YST_ELSE; }
"for"                                  { return YST_FOR; }
"while"                                { return YST_WHILE; }
"do"                                   { return YST_DO; }
"try"                                  { return YST_TRY; }
"catch"                                { return YST_CATCH; }
"throw"                                { return YST_THROW; }
"void"                                 { return YST_VOID; }
"null"                                 { return YST_NULL; }
"break"                                { return YST_BREAK; }
"continue"                             { return YST_CONTINUE; }
"return"                               { return YST_RETURN; }
"namespace"                            { return YST_NAMESPACE; }
"extern"                               { return YST_EXTERN; }
"base"                                 { return YST_BASE; }

"bool"                                 { return YST_BOOL; }
"string"                               { return YST_STRING; }
"char"                                 { return YST_CHAR; }
"int8"                                 { return YST_INT8; }
"uint8"                                { return YST_UINT8; }
"int16"                                { return YST_INT16; }
"uint16"                               { return YST_UINT16; }
"int32"                                { return YST_INT32; }
"uint32"                               { return YST_UINT32; }
"int64"                                { return YST_INT64; }
"uint64"                               { return YST_UINT64; }
"float"                                { return YST_FLOAT; }
"double"                               { return YST_DOUBLE; }

"{"                                    { return YST_CURLYO; }
"}"                                    { return YST_CURLYC; }
"("                                    { return YST_ROUNDO; }
")"                                    { return YST_ROUNDC; }
"["                                    { return YST_SQUAREO; }
"]"                                    { return YST_SQUAREC; }
";"                                    { return YST_SEMICOLON; }
","                                    { return YST_COMMA; }
"get"                                  { return YST_GET; }
"set"                                  { return YST_SET; }
"this"                                 { return YST_THIS; }
"++"                                   { return YST_PLUSPLUS; }
"+"                                    { return YST_PLUS; }
"--"                                   { return YST_MINUSMINUS; }
"-"                                    { return YST_MINUS; }
"*"                                    { return YST_STAR; }
"/"                                    { return YST_SLASH; }
"<<"                                   { return YST_LTLT; }
"<="                                   { return YST_LTEQUAL; }
"<"                                    { return YST_LT; }
">>"                                   { return YST_GTGT; }
">="                                   { return YST_GTEQUAL; }
">"                                    { return YST_GT; }
"=="                                   { return YST_EQUALEQUAL; }
"!="                                   { return YST_EXCLAMATIONMARKEQUAL; }
"!is"                                  { return YST_ISNOT; }
"!"                                    { return YST_EXCLAMATIONMARK; }
"typeof"                               { return YST_TYPEOF; }
"auto"                                 { return YST_AUTO; }
"="                                    { return YST_EQUAL; }
"~="                                   { return YST_TILDEEQUAL; }
"~"                                    { return YST_TILDE; }
"^="                                   { return YST_CIRCUMFLEXEQUAL; }
"^"                                    { return YST_CIRCUMFLEX; }
"&="                                   { return YST_ANDEQUAL; }
"&&"                                   { return YST_ANDAND; }
"&"                                    { return YST_AND; }
"/="                                   { return YST_SLASHEQUAL; }
"*="                                   { return YST_STAREQUAL; }
"-="                                   { return YST_MINUSEQUAL; }
"+="                                   { return YST_PLUSEQUAL; }
"%="                                   { return YST_PERCENTEQUAL; }
"%"                                    { return YST_PERCENT; }
"?"                                    { return YST_QUESTIONMARK; }
"|="                                   { return YST_VLINEEQUAL; }
"||"                                   { return YST_VLINEVLINE; }
"|"                                    { return YST_VLINE; }
"is"                                   { return YST_IS; }
"true"                                 { return YST_TRUE; }
"false"                                { return YST_FALSE; }
"."                                    { return YST_DOT; }
[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)? { yaoosl_lval.str = strdup(yytext); return YST_NUMBER; }
0[xX][a-zA-Z0-9]+                      { yaoosl_lval.str = strdup(yytext); return YST_HEXNUMBER; }
0[bB][01_]+                            { yaoosl_lval.str = strdup(yytext); return YST_BINARYNUMBER; }
\"(([^\"]|\\\")*[^\\])?\"              { yaoosl_lval.str = strdup(yytext); return YST_STRINGVAL; }
\'(([^']|\\\')*[^\\])?\'               { yaoosl_lval.str = strdup(yytext); return YST_CHARVAL; }
[ \t\r\n]                              ;

[a-zA-Z_][a-zA-Z0-9_]*                 { yaoosl_lval.str = strdup(yytext); return YST_NAME; }

%%

/* Start code copied to scanner output */

void yaoosl_yyscan_string(const char* str, yyscan_t yyscanner)
{
    yy_scan_string(str, yyscanner);
}

/* End code copied to scanner output */