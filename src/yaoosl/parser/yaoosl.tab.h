/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YAOOSL_YAOOSL_TAB_H_INCLUDED
# define YY_YAOOSL_YAOOSL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YAOOSL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define YAOOSL_DEBUG 1
#  else
#   define YAOOSL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define YAOOSL_DEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined YAOOSL_DEBUG */
#if YAOOSL_DEBUG
extern int yaoosl_debug;
#endif
/* "%code requires" blocks.  */
#line 219 "yaoosl.y" /* yacc.c:1909  */

    #ifndef YY_TYPEDEF_YY_SCANNER_T
    #define YY_TYPEDEF_YY_SCANNER_T
    typedef void* yyscan_t;
    #endif
    #ifndef YY_EXTRA_TYPE
    #define YY_EXTRA_TYPE void *
    #endif
    
     YY_EXTRA_TYPE yaoosl_get_extra(yyscan_t yyscanner);
     void yaoosl_set_extra(YY_EXTRA_TYPE user_defined, yyscan_t yyscanner);
     
     int yaoosl_lex_init (yyscan_t* scanner);
     void yaoosl_yyscan_string(const char* str, yyscan_t yyscanner);
     int yaoosl_lex_destroy(yyscan_t yyscanner);
#line 235 "yaoosl.y" /* yacc.c:1909  */

    #include <inttypes.h>
    #include "yaoosl_cstnode.h"
    void yaoosl_yycstnode_printf(yaoosl_cstnode node);
    enum yaoosl_cst_type
    {
        yscst_error,
        yscst_empty,
        yscst_root,
        yscst_namespace,
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
        yscst_array,
        yscst_extern,
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
        yscst_base,
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
        yscst_setto_exp,
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
        yscst_name,
    };

#line 232 "yaoosl.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YAOOSL_TOKENTYPE
# define YAOOSL_TOKENTYPE
  enum yaoosl_tokentype
  {
    YST_NAME = 258,
    YST_NUMBER = 259,
    YST_HEXNUMBER = 260,
    YST_BINARYNUMBER = 261,
    YST_STRINGVAL = 262,
    YST_CHARVAL = 263,
    YST_DOT = 264,
    YST_COMMA = 265,
    YST_BOOL = 266,
    YST_STRING = 267,
    YST_CHAR = 268,
    YST_INT8 = 269,
    YST_UINT8 = 270,
    YST_INT16 = 271,
    YST_UINT16 = 272,
    YST_INT32 = 273,
    YST_UINT32 = 274,
    YST_INT64 = 275,
    YST_UINT64 = 276,
    YST_FLOAT = 277,
    YST_DOUBLE = 278,
    YST_AUTO = 279,
    YST_USING = 280,
    YST_PUBLIC = 281,
    YST_INTERNAL = 282,
    YST_DERIVED = 283,
    YST_PRIVATE = 284,
    YST_CLASS = 285,
    YST_COLON = 286,
    YST_CURLYO = 287,
    YST_CURLYC = 288,
    YST_ROUNDO = 289,
    YST_ROUNDC = 290,
    YST_SQUAREO = 291,
    YST_SQUAREC = 292,
    YST_VOID = 293,
    YST_OPERATOR = 294,
    YST_PLUSPLUS = 295,
    YST_MINUSMINUS = 296,
    YST_EXCLAMATIONMARK = 297,
    YST_PLUS = 298,
    YST_MINUS = 299,
    YST_STAR = 300,
    YST_SLASH = 301,
    YST_PLUSEQUAL = 302,
    YST_MINUSEQUAL = 303,
    YST_STAREQUAL = 304,
    YST_SLASHEQUAL = 305,
    YST_VLINE = 306,
    YST_VLINEVLINE = 307,
    YST_VLINEEQUAL = 308,
    YST_AND = 309,
    YST_ANDAND = 310,
    YST_ANDEQUAL = 311,
    YST_CIRCUMFLEX = 312,
    YST_CIRCUMFLEXEQUAL = 313,
    YST_TILDE = 314,
    YST_TILDEEQUAL = 315,
    YST_PERCENT = 316,
    YST_PERCENTEQUAL = 317,
    YST_LT = 318,
    YST_LTLT = 319,
    YST_LTEQUAL = 320,
    YST_LTLTEQUAL = 321,
    YST_GT = 322,
    YST_GTGT = 323,
    YST_GTEQUAL = 324,
    YST_GTGTEQUAL = 325,
    YST_EQUAL = 326,
    YST_EQUALEQUAL = 327,
    YST_EXCLAMATIONMARKEQUAL = 328,
    YST_STATIC = 329,
    YST_SEMICOLON = 330,
    YST_RETURN = 331,
    YST_THROW = 332,
    YST_WITH = 333,
    YST_TRY = 334,
    YST_CATCH = 335,
    YST_FINALLY = 336,
    YST_IF = 337,
    YST_ELSE = 338,
    YST_FOR = 339,
    YST_WHILE = 340,
    YST_DO = 341,
    YST_SWITCH = 342,
    YST_CASE = 343,
    YST_DEFAULT = 344,
    YST_CONTINUE = 345,
    YST_BREAK = 346,
    YST_QUESTIONMARK = 347,
    YST_IS = 348,
    YST_ISNOT = 349,
    YST_NEW = 350,
    YST_TYPEOF = 351,
    YST_NULL = 352,
    YST_THIS = 353,
    YST_TRUE = 354,
    YST_FALSE = 355,
    YST_SET = 356,
    YST_GET = 357,
    YST_NAMESPACE = 358,
    YST_BASE = 359,
    YST_EXTERN = 360
  };
#endif

/* Value type.  */
#if ! defined YAOOSL_STYPE && ! defined YAOOSL_STYPE_IS_DECLARED

union YAOOSL_STYPE
{
#line 24 "yaoosl.y" /* yacc.c:1909  */

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

#line 366 "yaoosl.tab.h" /* yacc.c:1909  */
};

typedef union YAOOSL_STYPE YAOOSL_STYPE;
# define YAOOSL_STYPE_IS_TRIVIAL 1
# define YAOOSL_STYPE_IS_DECLARED 1
#endif


extern YAOOSL_STYPE yaoosl_lval;

int yaoosl_parse (yyscan_t scanner, struct yaoosl_compilationunit* cu);

#endif /* !YY_YAOOSL_YAOOSL_TAB_H_INCLUDED  */
