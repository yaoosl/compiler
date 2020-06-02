/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 2 "yaoosl.y" /* yacc.c:316  */

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

#line 85 "yaoosl.tab.c" /* yacc.c:316  */
/* Substitute the type names.  */
#define YYSTYPE         YAOOSL_STYPE
/* Substitute the variable and function names.  */
#define yyparse         yaoosl_parse
#define yylex           yaoosl_lex
#define yyerror         yaoosl_error
#define yydebug         yaoosl_debug
#define yynerrs         yaoosl_nerrs

#define yylval          yaoosl_lval
#define yychar          yaoosl_char

/* Copy the first part of user declarations.  */

#line 100 "yaoosl.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yaoosl.tab.h".  */
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
#  define YAOOSL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined YAOOSL_DEBUG */
#if YAOOSL_DEBUG
extern int yaoosl_debug;
#endif
/* "%code requires" blocks.  */
#line 208 "yaoosl.y" /* yacc.c:355  */

    #ifndef YY_TYPEDEF_YY_SCANNER_T
    #define YY_TYPEDEF_YY_SCANNER_T
    typedef void* yyscan_t;
    #endif
    #ifndef YY_EXTRA_TYPE
    #define YY_EXTRA_TYPE void *
    #endif
#line 217 "yaoosl.y" /* yacc.c:355  */

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

#line 305 "yaoosl.tab.c" /* yacc.c:355  */

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
    YST_VOID = 291,
    YST_OPERATOR = 292,
    YST_PLUSPLUS = 293,
    YST_MINUSMINUS = 294,
    YST_EXCLAMATIONMARK = 295,
    YST_PLUS = 296,
    YST_MINUS = 297,
    YST_STAR = 298,
    YST_SLASH = 299,
    YST_PLUSEQUAL = 300,
    YST_MINUSEQUAL = 301,
    YST_STAREQUAL = 302,
    YST_SLASHEQUAL = 303,
    YST_VLINE = 304,
    YST_VLINEVLINE = 305,
    YST_VLINEEQUAL = 306,
    YST_AND = 307,
    YST_ANDAND = 308,
    YST_ANDEQUAL = 309,
    YST_CIRCUMFLEX = 310,
    YST_CIRCUMFLEXEQUAL = 311,
    YST_TILDE = 312,
    YST_TILDEEQUAL = 313,
    YST_PERCENT = 314,
    YST_LT = 315,
    YST_LTLT = 316,
    YST_LTEQUAL = 317,
    YST_LTLTEQUAL = 318,
    YST_GT = 319,
    YST_GTGT = 320,
    YST_GTEQUAL = 321,
    YST_GTGTEQUAL = 322,
    YST_EQUALEQUAL = 323,
    YST_EXCLAMATIONMARKEQUAL = 324,
    YST_STATIC = 325,
    YST_SEMICOLON = 326,
    YST_RETURN = 327,
    YST_THROW = 328,
    YST_WITH = 329,
    YST_TRY = 330,
    YST_CATCH = 331,
    YST_FINALLY = 332,
    YST_IF = 333,
    YST_ELSE = 334,
    YST_FOR = 335,
    YST_WHILE = 336,
    YST_DO = 337,
    YST_SWITCH = 338,
    YST_CASE = 339,
    YST_DEFAULT = 340,
    YST_CONTINUE = 341,
    YST_BREAK = 342,
    YST_QUESTIONMARK = 343,
    YST_IS = 344,
    YST_ISNOT = 345,
    YST_NEW = 346,
    YST_TYPEOF = 347,
    YST_NULL = 348,
    YST_THIS = 349,
    YST_TRUE = 350,
    YST_FALSE = 351
  };
#endif

/* Value type.  */
#if ! defined YAOOSL_STYPE && ! defined YAOOSL_STYPE_IS_DECLARED

union YAOOSL_STYPE
{
#line 24 "yaoosl.y" /* yacc.c:355  */

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

#line 430 "yaoosl.tab.c" /* yacc.c:355  */
};

typedef union YAOOSL_STYPE YAOOSL_STYPE;
# define YAOOSL_STYPE_IS_TRIVIAL 1
# define YAOOSL_STYPE_IS_DECLARED 1
#endif


extern YAOOSL_STYPE yaoosl_lval;

int yaoosl_parse (yyscan_t scanner, struct yaoosl_compilationunit* cu);

#endif /* !YY_YAOOSL_YAOOSL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 447 "yaoosl.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YAOOSL_STYPE_IS_TRIVIAL && YAOOSL_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  106
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1246

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  237
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  397

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   355

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100
};

#if YAOOSL_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   377,   377,   378,   379,   380,   382,   383,   385,   386,
     387,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   403,   404,   405,   407,   409,   410,
     411,   412,   414,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   427,   428,   429,   430,   432,   433,   434,
     435,   437,   439,   440,   441,   443,   444,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   476,   477,   478,   480,   481,
     483,   484,   485,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   498,   499,   501,   502,   504,   505,   507,
     508,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   526,   527,   529,   530,
     531,   532,   534,   535,   536,   537,   539,   541,   542,   544,
     545,   547,   548,   550,   552,   554,   556,   557,   559,   560,
     561,   562,   564,   566,   567,   569,   570,   572,   573,   575,
     576,   577,   579,   580,   582,   583,   584,   586,   587,   588,
     589,   590,   592,   593,   594,   596,   597,   598,   600,   601,
     602,   603,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   615,   616,   617,   619,   620,   621,   622,   623,   624,
     625,   627,   629,   630,   631,   632,   633,   634,   636,   637,
     639,   640,   641,   643,   644,   645,   646,   647,   648,   649,
     650,   651,   652,   653,   654,   656,   657,   663,   664,   665,
     666,   668,   669,   670,   671,   672,   674,   675
};
#endif

#if YAOOSL_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "YST_NAME", "YST_NUMBER",
  "YST_HEXNUMBER", "YST_BINARYNUMBER", "YST_STRINGVAL", "YST_CHARVAL",
  "\".\"", "\",\"", "\"bool\"", "\"string\"", "\"char\"", "\"int8\"",
  "\"uint8\"", "\"int16\"", "\"uint16\"", "\"int32\"", "\"uint32\"",
  "\"int64\"", "\"uint64\"", "\"float\"", "\"double\"", "\"auto\"",
  "\"using\"", "\"public\"", "\"internal\"", "\"derived\"", "\"private\"",
  "\"class\"", "\":\"", "\"{\"", "\"}\"", "\"(\"", "\")\"", "\"void\"",
  "\"operator\"", "\"++\"", "\"--\"", "\"!\"", "\"+\"", "\"-\"", "\"*\"",
  "\"/\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"|\"", "\"||\"",
  "\"|=\"", "\"&\"", "\"&&\"", "\"&=\"", "\"^\"", "\"^=\"", "\"~\"",
  "\"~=\"", "\"%\"", "\"<\"", "\"<<\"", "\"<=\"", "\"<<=\"", "\">\"",
  "\">>\"", "\">=\"", "\">>=\"", "\"==\"", "\"!=\"", "\"static\"", "\";\"",
  "\"return\"", "\"throw\"", "\"with\"", "\"try\"", "\"catch\"",
  "\"finally\"", "\"if\"", "\"else\"", "\"for\"", "\"while\"", "\"do\"",
  "\"switch\"", "\"case\"", "\"default\"", "\"continue\"", "\"break\"",
  "\"?\"", "\"is\"", "\"!is\"", "\"new\"", "\"typeof\"", "\"null\"",
  "\"this\"", "\"true\"", "\"false\"", "\"set\"", "\"get\"", "\"=\"",
  "\"%=\"", "$accept", "yaoosl", "identifier", "identlist", "stdtype",
  "vtype", "usingns", "encpsl", "classhead", "classbody", "classdef",
  "mthdargs", "mthd", "cnstmthd", "opmthd", "op0", "op1", "op2", "opargs0",
  "opargs1", "opargs2", "decl", "decllist", "property", "prop_set",
  "prop_get", "mthdbody", "stmntlist", "stmnt", "cntrl_if", "cntrl_try",
  "cntrl_catch", "cntrl_for", "cntrl_for1", "cntrl_for2", "cntrl_for3",
  "cntrl_while", "cntrl_dowhile", "cntrl_switch", "cntrl_case",
  "cntrl_switchbody", "exp", "exp01", "exp02", "exp03", "exp04", "exp05",
  "exp06", "exp07", "exp08", "exp09", "exp10", "exp11", "exp12", "cnstexp",
  "bexp", "refexp", "calllist", "expressionlist", "assign_post",
  "call_post", "exp13", "assign", "call", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355
};
# endif

#define YYPACT_NINF -290

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-290)))

#define YYTABLE_NINF -43

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     351,    15,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
      27,    33,  -290,  -290,  -290,  -290,   539,  1056,  1103,  1103,
    1150,  1150,  -290,   915,  1056,   727,  1056,    16,  1056,   727,
    1056,   -13,    -4,    33,    45,  -290,  -290,  -290,  -290,    86,
       1,    88,   351,    64,    78,   351,   351,   727,  -290,  -290,
    -290,  -290,  -290,  -290,    25,  -290,    14,    76,    83,   -26,
     107,    63,   241,    43,   125,   117,    22,  -290,   160,  -290,
    -290,  -290,  -290,    33,   282,  -290,  -290,   166,   171,  -290,
    -290,  -290,  -290,  -290,   138,   154,    97,   727,  1056,   727,
     147,   204,  -290,  -290,   208,   384,  -290,   282,  1009,  1056,
    1056,  1056,  1056,  1056,  1056,  1056,  1056,  1056,  1056,  1056,
    1056,   174,  -290,  -290,   282,  -290,   250,    33,   167,  -290,
    -290,  -290,  -290,  1056,  1056,  1056,  1056,  1056,  1056,  1056,
    1056,  1056,  1056,  1056,  1056,  1056,  1056,  1056,  1056,  1056,
    1056,  1056,  -290,  -290,   384,   384,    33,  -290,  -290,  -290,
    -290,  -290,  -290,   821,   727,   178,   181,   191,  -290,  -290,
    1056,   445,  -290,   229,   234,  -290,  -290,   261,   237,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,    33,  -290,  -290,   263,   252,   383,  -290,   169,   249,
     392,   470,   479,   564,   254,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,   198,  1056,   213,
    -290,   727,   727,  1056,   220,     2,   262,   445,   445,   259,
    -290,  -290,  1056,  -290,  -290,    33,   573,  -290,    65,  -290,
     299,   291,   293,    68,   266,   270,   272,  -290,  -290,  -290,
    -290,  -290,  1056,  -290,  -290,   232,   305,   313,   289,  -290,
    -290,  -290,   255,  -290,  -290,   294,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,   301,   199,   307,  -290,  -290,    70,   -20,
      -5,   303,   630,   308,   307,   384,   307,   384,   307,  -290,
     282,   282,   384,   213,  1056,  -290,  -290,  -290,   339,   341,
     311,   633,  -290,   303,   728,    81,  -290,    81,  -290,   307,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,   315,  -290,   338,  -290,  -290,
    -290,   316,  -290,  -290,  -290,  -290,  -290,   319,   307,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,    -1,    21,   -17,   -12,
     -15,    -8,  -290,  -290,   384,   727,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,   327,  -290,   328,  -290,   353,  -290,   355,
     357,  -290,  -290,  -290,  -290,  -290,  -290
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     6,   196,   197,   198,   199,   200,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       0,     0,    28,    29,    30,    31,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   206,   194,   195,     0,
       0,     0,     2,     0,     0,     2,     2,   109,   120,   121,
     122,   123,   124,   125,     0,   152,   153,   155,   157,   159,
     162,   164,   167,   172,   175,   178,   182,   230,   207,   229,
     191,   227,   228,     0,     0,    27,   118,     0,     0,   185,
     186,   192,   193,   113,     0,     0,   128,     0,   137,     0,
       0,     0,   114,   115,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,   234,   237,     0,     3,     0,     0,     0,     4,
       5,   110,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,     0,     0,     0,     7,   232,   119,
     201,   112,   116,     0,     0,   129,   126,     0,   138,   143,
       0,     0,   204,     0,     0,   235,   208,   210,     0,   214,
     215,   216,   217,   219,   220,   221,   222,   224,   223,   213,
     218,     0,   233,    32,     8,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,   156,   158,   160,   161,   163,
     165,   166,   168,   169,   170,   171,   173,   174,   176,   177,
     179,   180,   181,   189,   187,   190,   188,     0,     0,   132,
     131,     0,     0,   139,     0,     0,     0,   150,   148,     0,
     203,   202,   211,   209,   226,     9,     0,    41,     6,    24,
       0,    26,    25,     0,     0,     0,     0,    44,    33,    35,
      37,    39,     0,   231,   236,     0,     0,    90,     0,   134,
     130,   127,     0,   140,   144,     0,   147,   151,   149,   145,
     212,    10,    45,     0,     0,     0,    26,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   154,
      89,    88,    91,   133,   141,   146,    43,    47,     0,     0,
       0,     0,    51,     0,     0,     0,    93,     0,    98,     0,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    85,    52,     0,    53,     0,    54,    92,
     135,     0,   142,    89,    88,    48,   108,     0,     0,    68,
      69,    70,    71,    72,    76,    73,    77,    74,    75,    78,
      79,    84,    80,    83,    81,    82,     0,     0,     0,     0,
       0,     0,    49,    86,     0,     0,   107,    50,   103,   104,
     105,   106,    97,     0,    95,     0,   102,     0,   100,     0,
       0,   136,    96,    94,   101,    99,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -290,   185,   -21,  -290,   -27,   144,  -290,    20,  -290,   -38,
    -290,  -257,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,  -284,  -258,  -290,  -289,  -275,  -279,   -24,   -34,  -290,
    -290,  -226,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
     -11,     5,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,   222,   179,  -290,  -290,   309,   173,   -70,
     190,   228,  -290,  -290
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    49,    50,   195,    51,   253,    52,   198,    54,   199,
      55,   285,   200,   201,   202,   254,   255,   256,   294,   296,
     298,   267,   268,   203,   368,   369,   312,    56,    57,    58,
      59,   165,    60,   167,   272,   341,    61,    62,    63,   238,
     239,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,   121,   178,   122,
     123,    80,    81,    82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,    96,    87,   269,   107,   100,     2,     3,     4,     5,
       6,   335,   315,   337,   158,   334,   382,   336,   386,   338,
      53,   384,   104,   136,    83,   388,   310,   317,   370,   137,
      84,   311,    88,   131,   319,   108,     1,   175,    94,    95,
     372,    97,   371,    99,   339,   101,   109,   110,   111,   112,
      98,   316,   113,   311,   192,   114,   348,   115,   102,   116,
     152,   153,   157,   166,   117,   169,   318,   103,   118,   377,
     378,   291,    53,   313,    83,    53,    53,   340,   174,   105,
     385,   367,   389,   367,   173,   366,   106,   379,   381,   366,
     390,   124,   380,   383,   126,   387,   132,    47,    48,   284,
     119,   120,   133,   168,   145,   292,   194,   314,   146,   127,
     128,   154,   155,   177,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   134,   224,   226,   229,
     230,   139,   140,   223,   225,   227,   135,   237,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   263,   247,   138,
     149,   150,   258,   259,   260,   261,   147,   148,   196,   156,
     244,   252,   248,   163,   164,   234,   151,   251,   366,   367,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    22,    23,    24,    25,   270,   271,   159,
     197,   266,     1,   237,   237,   249,   160,   265,   283,   161,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   287,   281,   162,   277,   278,   170,   286,
     175,   192,   108,    88,   307,   300,   171,   125,   273,   250,
     129,   130,   108,   109,   110,   111,   112,   177,   191,   113,
      89,    90,   114,   193,   115,   231,   116,   309,    91,    92,
     232,   117,   233,   308,   240,   118,   108,   299,   309,   241,
     309,   242,   243,   245,   308,   309,   308,   109,   110,   111,
     112,   308,   257,   113,   246,   262,   114,   347,   115,   163,
     116,   274,   279,   276,   289,   117,   290,   119,   120,   118,
     293,   141,     1,   142,   295,   143,   297,   144,   301,   342,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   302,   303,   305,   304,   109,   110,   111,
     112,   119,   120,   113,   306,   249,   114,   284,   115,   311,
     116,   391,   343,   333,   344,   117,   345,   309,   374,   118,
     373,   375,   376,   308,     1,     2,     3,     4,     5,     6,
     392,   393,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   119,   120,    26,   196,    27,   394,     1,   395,    28,
      29,    30,   396,   196,   288,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    31,    22,
      23,    24,    25,   172,   275,   280,   -42,   264,    22,    23,
      24,    25,    32,    33,    34,   -34,    35,     0,     0,    36,
       0,    37,    38,    39,    40,     0,     0,    41,    42,     0,
       0,     0,    43,    44,    45,    46,    47,    48,     1,     2,
       3,     4,     5,     6,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,   196,     0,     0,     0,     0,     0,    26,     0,    27,
     196,     0,     0,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,    24,    25,
       0,     0,    31,   -36,     0,    22,    23,    24,    25,     0,
       0,     0,   -38,     0,     0,     0,    32,    33,    34,     0,
      35,     0,     0,    36,     0,    37,    38,    39,    40,   235,
     236,    41,    42,     0,     0,     0,    43,    44,    45,    46,
      47,    48,     1,     2,     3,     4,     5,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,   196,     0,     0,     0,     0,
       0,    26,    86,    27,   196,     0,     0,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,    24,    25,     0,     0,    31,   -40,     0,    22,
      23,    24,    25,     0,     0,     0,   282,     0,     0,     0,
      32,    33,    34,     0,    35,     0,     0,    36,     0,    37,
      38,    39,    40,     0,     0,    41,    42,     0,     0,     0,
      43,    44,    45,    46,    47,    48,     1,     2,     3,     4,
       5,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,    26,   346,    27,   320,   321,
     322,    28,    29,    30,     0,   323,   324,   325,   326,     0,
       0,   327,     0,     0,   328,     0,   329,     0,   330,     0,
      31,     0,     0,   331,     0,     0,     0,   332,     0,     0,
       0,     0,     0,     0,    32,    33,    34,     0,    35,     0,
       0,    36,     0,    37,    38,    39,    40,     0,     0,    41,
      42,     0,     0,     0,    43,    44,    45,    46,    47,    48,
       1,     2,     3,     4,     5,     6,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,     0,     0,    28,    29,    30,     0,   349,
     350,   351,   352,     0,     0,     0,     0,   353,   354,     0,
     355,   356,     0,   357,    31,   358,     0,   359,     0,   360,
     361,     0,     0,   362,   363,     0,   364,   365,    32,    33,
      34,     0,    35,     0,     0,    36,     0,    37,    38,    39,
      40,     0,     0,    41,    42,     0,     0,     0,    43,    44,
      45,    46,    47,    48,     1,     2,     3,     4,     5,     6,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,    26,     0,   228,     0,     0,     0,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,    34,     0,    35,     0,     0,    36,
       0,    37,    38,    39,    40,     0,     0,    41,    42,     0,
       0,     0,    43,    44,    45,    46,    47,    48,     1,     2,
       3,     4,     5,     6,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    44,    45,    46,
      47,    48,     1,     2,     3,     4,     5,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,   176,     0,     0,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     0,    31,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,     0,    28,    29,    30,     0,     0,     0,
      43,    44,    45,    46,    47,    48,     1,     2,     3,     4,
       5,     6,     0,    31,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,    30,     0,     0,     0,    43,    44,    45,
      46,    47,    48,     1,     2,     3,     4,     5,     6,     0,
      31,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,    45,    46,    47,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    44,    45,    46,    47,    48
};

static const yytype_int16 yycheck[] =
{
      21,    35,    26,   229,     3,    39,     4,     5,     6,     7,
       8,   295,    32,   297,    84,   294,    33,   296,    33,   298,
       0,    33,    43,    49,     9,    33,   284,    32,   317,    55,
       3,    32,    27,    57,   291,    34,     3,   107,    33,    34,
     319,    36,   317,    38,   302,    40,    45,    46,    47,    48,
      34,    71,    51,    32,   124,    54,   313,    56,    71,    58,
      38,    39,    83,    97,    63,    99,    71,    71,    67,   348,
      71,     3,    52,     3,     9,    55,    56,   303,   105,    34,
     369,    98,   371,    98,   105,    97,     0,   366,   367,    97,
     374,     3,    71,   368,    30,   370,    71,    95,    96,    34,
      99,   100,    88,    98,    61,    37,   127,    37,    65,    31,
      32,    89,    90,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    50,   154,   155,   163,
     164,    68,    69,   154,   155,   156,    53,   171,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   227,   196,    52,
      43,    44,   200,   201,   202,   203,    41,    42,     1,     9,
     191,   198,     3,    76,    77,   170,    59,   198,    97,    98,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    26,    27,    28,    29,   231,   232,    33,
      33,   228,     3,   237,   238,    36,    35,   228,   246,    71,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   250,   245,    71,   237,   238,    81,   250,
     300,   301,    34,   228,    35,     3,    32,    52,   233,    70,
      55,    56,    34,    45,    46,    47,    48,   242,    74,    51,
      28,    29,    54,     3,    56,    77,    58,   284,    30,    31,
      79,    63,    71,   284,    35,    67,    34,   262,   295,    35,
     297,    10,    35,    10,   295,   302,   297,    45,    46,    47,
      48,   302,    33,    51,    32,    31,    54,   311,    56,    76,
      58,    71,    33,    31,     3,    63,     3,    99,   100,    67,
      34,    60,     3,    62,    34,    64,    34,    66,     3,   304,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    10,    35,    31,    71,    45,    46,    47,
      48,    99,   100,    51,    33,    36,    54,    34,    56,    32,
      58,   375,     3,    35,     3,    63,    35,   374,    10,    67,
      35,    35,    33,   374,     3,     4,     5,     6,     7,     8,
      33,    33,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    99,   100,    32,     1,    34,    33,     3,    33,    38,
      39,    40,    35,     1,   250,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    57,    26,
      27,    28,    29,   104,   235,   242,    33,   227,    26,    27,
      28,    29,    71,    72,    73,    33,    75,    -1,    -1,    78,
      -1,    80,    81,    82,    83,    -1,    -1,    86,    87,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
       1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    57,    33,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    71,    72,    73,    -1,
      75,    -1,    -1,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,     1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    -1,    -1,    57,    33,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      71,    72,    73,    -1,    75,    -1,    -1,    78,    -1,    80,
      81,    82,    83,    -1,    -1,    86,    87,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    38,    39,
      40,    38,    39,    40,    -1,    45,    46,    47,    48,    -1,
      -1,    51,    -1,    -1,    54,    -1,    56,    -1,    58,    -1,
      57,    -1,    -1,    63,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    -1,    75,    -1,
      -1,    78,    -1,    80,    81,    82,    83,    -1,    -1,    86,
      87,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    49,    50,    -1,
      52,    53,    -1,    55,    57,    57,    -1,    59,    -1,    61,
      62,    -1,    -1,    65,    66,    -1,    68,    69,    71,    72,
      73,    -1,    75,    -1,    -1,    78,    -1,    80,    81,    82,
      83,    -1,    -1,    86,    87,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    -1,    75,    -1,    -1,    78,
      -1,    80,    81,    82,    83,    -1,    -1,    86,    87,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    57,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,     3,     4,     5,     6,
       7,     8,    -1,    57,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,     3,     4,     5,     6,     7,     8,    -1,
      57,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    32,    34,    38,    39,
      40,    57,    71,    72,    73,    75,    78,    80,    81,    82,
      83,    86,    87,    91,    92,    93,    94,    95,    96,   102,
     103,   105,   107,   108,   109,   111,   128,   129,   130,   131,
     133,   137,   138,   139,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     162,   163,   164,     9,     3,   103,    33,   128,   142,   154,
     154,   162,   162,    71,   142,   142,   129,   142,    34,   142,
     129,   142,    71,    71,   103,    34,     0,     3,    34,    45,
      46,    47,    48,    51,    54,    56,    58,    63,    67,    99,
     100,   158,   160,   161,     3,   102,    30,    31,    32,   102,
     102,   128,    71,    88,    50,    53,    49,    55,    52,    68,
      69,    60,    62,    64,    66,    61,    65,    41,    42,    43,
      44,    59,    38,    39,    89,    90,     9,   103,   160,    33,
      35,    71,    71,    76,    77,   132,   129,   134,   142,   129,
      81,    32,   158,   103,   105,   160,    35,   142,   159,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,    74,   160,     3,   103,   104,     1,    33,   108,   110,
     113,   114,   115,   124,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   103,   105,   103,   105,   103,    34,   129,
     129,    77,    79,    71,   142,    84,    85,   129,   140,   141,
      35,    35,    10,    35,   103,    10,    32,   110,     3,    36,
      70,   103,   105,   106,   116,   117,   118,    33,   110,   110,
     110,   110,    31,   160,   161,   103,   105,   122,   123,   132,
     129,   129,   135,   142,    71,   155,    31,   141,   141,    33,
     159,   103,    33,   110,    34,   112,   103,   105,   106,     3,
       3,     3,    37,    34,   119,    34,   120,    34,   121,   142,
       3,     3,    10,    35,    71,    31,    33,    35,   103,   105,
     123,    32,   127,     3,    37,    32,    71,    32,    71,   112,
      38,    39,    40,    45,    46,    47,    48,    51,    54,    56,
      58,    63,    67,    35,   127,   122,   127,   122,   127,   123,
     132,   136,   142,     3,     3,    35,    33,   128,   112,    41,
      42,    43,    44,    49,    50,    52,    53,    55,    57,    59,
      61,    62,    65,    66,    68,    69,    97,    98,   125,   126,
     125,   126,   127,    35,    10,    35,    33,   127,    71,   127,
      71,   127,    33,   126,    33,   125,    33,   126,    33,   125,
     122,   129,    33,    33,    33,    33,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   102,   102,   102,   103,   103,   104,   104,
     104,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   106,   106,   106,   107,   108,   108,
     108,   108,   109,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   111,   111,   112,   112,   113,
     113,   114,   115,   115,   115,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   120,   121,   122,   122,
     123,   123,   123,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   130,   130,   131,   131,
     131,   131,   132,   132,   132,   132,   133,   134,   134,   135,
     135,   136,   136,   137,   138,   139,   140,   140,   141,   141,
     141,   141,   142,   143,   143,   144,   144,   145,   145,   146,
     146,   146,   147,   147,   148,   148,   148,   149,   149,   149,
     149,   149,   150,   150,   150,   151,   151,   151,   152,   152,
     152,   152,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   154,   154,   154,   155,   155,   155,   155,   155,   155,
     155,   156,   157,   157,   157,   157,   157,   157,   158,   158,
     159,   159,   159,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   161,   161,   162,   162,   162,
     162,   163,   163,   163,   163,   163,   164,   164
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     1,     3,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     3,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     6,     4,     5,     3,     2,     3,     5,
       6,     4,     4,     4,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     3,     5,     2,     2,
       1,     2,     3,     4,     7,     6,     7,     6,     4,     7,
       6,     7,     6,     2,     2,     2,     2,     3,     2,     1,
       2,     1,     3,     2,     2,     2,     3,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     3,     5,     2,     3,
       5,     4,     2,     4,     3,     5,     9,     0,     1,     0,
       1,     0,     1,     3,     5,     5,     3,     2,     1,     2,
       1,     2,     1,     1,     5,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     2,     2,     3,     3,     3,
       3,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     3,     1,     1,     1,     2,     3,
       1,     2,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     3,     1,     1,     1,
       1,     4,     3,     3,     2,     3,     4,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      YY_LAC_DISCARD ("YYBACKUP");                              \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (scanner, cu, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YAOOSL_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, scanner, cu); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner, struct yaoosl_compilationunit* cu)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (scanner);
  YYUSE (cu);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner, struct yaoosl_compilationunit* cu)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner, cu);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, yyscan_t scanner, struct yaoosl_compilationunit* cu)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , scanner, cu);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner, cu); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YAOOSL_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YAOOSL_DEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YAOOSL_DEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YAOOSL_DEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YAOOSL_DEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
# if YAOOSL_DEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, yyscan_t scanner, struct yaoosl_compilationunit* cu)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  YYUSE (cu);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner, struct yaoosl_compilationunit* cu)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 6:
#line 382 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_ident, (yyvsp[0].str)); }
#line 2241 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 383 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_ident, (yyvsp[-2].str)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2247 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 385 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_identlist); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2253 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 386 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_identlist); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2259 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 387 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_identlist); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2265 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 389 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_bool)); }
#line 2271 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 390 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_string)); }
#line 2277 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 391 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_char)); }
#line 2283 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 392 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_int8)); }
#line 2289 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 393 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_uint8)); }
#line 2295 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 394 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_int16)); }
#line 2301 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 395 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_uint16)); }
#line 2307 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 396 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_int32)); }
#line 2313 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 397 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_uint32)); }
#line 2319 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 398 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_int64)); }
#line 2325 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 399 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_uint64)); }
#line 2331 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 400 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_float)); }
#line 2337 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 401 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_double)); }
#line 2343 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 403 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_void)); }
#line 2349 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 404 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 2355 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 407 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_using); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2361 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 409 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_encapsulation_public); }
#line 2367 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 410 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_encapsulation_internal); }
#line 2373 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 411 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_encapsulation_derived); }
#line 2379 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 412 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_encapsulation_private); }
#line 2385 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 414 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classhead); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[0].str))); }
#line 2391 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 416 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2397 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2403 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 418 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2409 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 419 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2415 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 420 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2421 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 421 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2427 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 422 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2433 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 423 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2439 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 424 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_error); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2445 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 425 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_error); }
#line 2451 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 427 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classdef); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2457 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 428 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classdef); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2463 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 429 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classdef); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); }
#line 2469 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 430 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classdef); CSTPSH((yyval.cst), (yyvsp[-2].cst)); }
#line 2475 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 432 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_mthdargs); }
#line 2481 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 433 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_mthdargs); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2487 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 434 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_mthd); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-2].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2493 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 435 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_smthd); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-2].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2499 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 437 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cnstmthd); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-2].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2505 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 439 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_opmthd); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2511 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 440 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_opmthd); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2517 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 441 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_opmthd); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2523 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 443 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_inc_r0); }
#line 2529 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 444 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_dec_r0); }
#line 2535 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 446 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_not_v1); }
#line 2541 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 447 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_add_r1); }
#line 2547 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 448 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_sub_r1); }
#line 2553 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 449 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_mul_r1); }
#line 2559 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 450 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_div_r1); }
#line 2565 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 451 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_or_r1); }
#line 2571 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 452 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_and_r1); }
#line 2577 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 453 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_xor_r1); }
#line 2583 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 454 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_inv_r1); }
#line 2589 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 455 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_lshift_r1); }
#line 2595 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 456 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_rshift_r1); }
#line 2601 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 458 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_add_v2); }
#line 2607 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 459 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_sub_v2); }
#line 2613 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 460 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_mul_v2); }
#line 2619 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 461 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_div_v2); }
#line 2625 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 462 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_or_v2); }
#line 2631 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 463 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_and_v2); }
#line 2637 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 464 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_xor_v2); }
#line 2643 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 465 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_inv_v2); }
#line 2649 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 466 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_log_or_v2); }
#line 2655 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 467 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_log_and_v2); }
#line 2661 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 468 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_mod_v2); }
#line 2667 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 469 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_lshift_v2); }
#line 2673 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 470 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_rshift_v2); }
#line 2679 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 471 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_log_equal_v2); }
#line 2685 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 472 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_log_notequal_v2); }
#line 2691 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 473 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_log_greater_then_v2); }
#line 2697 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 474 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_log_less_then_v2); }
#line 2703 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 476 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_mthdargs); }
#line 2709 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 477 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_mthdargs); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2715 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 478 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_mthdargs); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2721 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 480 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_decl, (yyvsp[0].str)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2727 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 481 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_decl, (yyvsp[0].str)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2733 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 483 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_decllist); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2739 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 484 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_decllist); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2745 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 485 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_decllist); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2751 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 487 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-1].str))); }
#line 2757 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 488 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-6].cst)); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-4].str))); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2763 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 489 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-3].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2769 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 490 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-6].cst)); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-4].str))); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2775 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 491 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-3].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2781 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 492 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-1].str))); }
#line 2787 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 493 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-6].cst)); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-4].str))); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2793 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 494 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-3].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2799 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 495 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-6].cst)); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-4].str))); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2805 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 496 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-3].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2811 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 498 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property_set); }
#line 2817 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 499 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property_set); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2823 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 501 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property_get); }
#line 2829 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 502 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property_get); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2835 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 504 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_mthdbody); CSTIMP((yyval.cst), (yyvsp[-1].cst)); }
#line 2841 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 505 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_mthdbody); }
#line 2847 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 507 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_statementlist); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2853 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 508 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_statementlist); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2859 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 510 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_empty); }
#line 2865 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 511 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_return); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2871 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 512 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_return); }
#line 2877 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 513 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_continue); }
#line 2883 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 514 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_break); }
#line 2889 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 515 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_throw); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2895 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 516 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[-1].cst); }
#line 2901 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 517 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_empty); }
#line 2907 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 518 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[-1].cst); }
#line 2913 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 519 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 2919 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 520 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 2925 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 521 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 2931 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 522 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 2937 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 523 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 2943 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 524 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 2949 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 526 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_if); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2955 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 527 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_if); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2961 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 529 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_try); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2967 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 530 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_try); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2973 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 531 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_try); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2979 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 532 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_try); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2985 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 534 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_catch); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2991 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 535 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_catch); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2997 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 536 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_catch); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 3003 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 537 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_catch); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 3009 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 539 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_for); CSTPSH((yyval.cst), (yyvsp[-6].cst)); CSTPSH((yyval.cst), (yyvsp[-4].cst)) ;CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3015 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 541 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_for_arg); }
#line 3021 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 542 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_for_arg); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3027 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 544 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_for_arg); }
#line 3033 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 545 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_for_arg); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3039 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 547 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_for_arg); }
#line 3045 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 548 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_for_arg); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3051 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 550 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_while); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3057 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 552 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_dowhile); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3063 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 554 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_switch); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3069 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 556 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_case); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3075 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 557 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_case_default); }
#line 3081 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 559 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_statementlist); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3087 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 560 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_statementlist); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 3093 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 561 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_statementlist); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3099 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 562 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_statementlist); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 3105 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 564 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3111 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 566 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3117 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 567 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_ternary); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3123 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 569 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3129 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 570 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_log_or); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3135 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 572 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3141 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 573 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_log_and); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3147 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 575 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3153 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 576 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_bin_or); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3159 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 577 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_bin_xor); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3165 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 579 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3171 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 580 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_bin_and); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3177 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 582 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3183 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 583 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_equal); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3189 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 584 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_notequal); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3195 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 586 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3201 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 587 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_less); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3207 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 588 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_less_equal); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3213 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 589 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_greater); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3219 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 590 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_greater_equal); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3225 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 592 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3231 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 593 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_lshift); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3237 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 594 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_rshift); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3243 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 596 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3249 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 597 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_add); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3255 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 598 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_sub); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3261 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 600 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3267 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 601 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_mul); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3273 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 602 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_div); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3279 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 603 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_mod); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3285 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 605 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3291 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 606 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_post_inc); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3297 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 607 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_post_dec); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3303 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 608 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_pre_inc); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3309 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 609 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_pre_dec); CSTPSH((yyval.cst), (yyvsp[0].cst));}
#line 3315 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 610 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_is); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3321 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 611 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_isnot); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3327 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 612 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_is); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3333 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 613 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_isnot); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3339 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 615 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3345 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 616 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_log_not); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3351 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 617 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_invert); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3357 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 619 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_val_true); }
#line 3363 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 620 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_val_false); }
#line 3369 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 621 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_val_number, (yyvsp[0].str)); }
#line 3375 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 622 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_val_number_hex, (yyvsp[0].str)); }
#line 3381 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 623 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_val_number_binary, (yyvsp[0].str)); }
#line 3387 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 624 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_val_string, (yyvsp[0].str)); }
#line 3393 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 625 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_val_char, (yyvsp[0].str)); }
#line 3399 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 627 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_valexp); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3405 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 629 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_typeof); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3411 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 630 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_typeof); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3417 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 631 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_new); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3423 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 632 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_null); }
#line 3429 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 633 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_this); }
#line 3435 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 634 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3441 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 636 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_calllist); }
#line 3447 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 637 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_calllist); CSTIMP((yyval.cst), (yyvsp[-1].cst)); }
#line 3453 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 639 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_expressionlist); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3459 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 640 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_expressionlist); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3465 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 641 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_expressionlist); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 3471 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 643 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3477 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 644 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_add); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3483 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 645 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_sub); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3489 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 646 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_mul); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3495 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 647 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_div); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3501 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 648 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_mod); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3507 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 649 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_bin_or); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3513 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 650 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_bin_and); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3519 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 651 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_bin_xor); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3525 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 652 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_invert); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3531 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 653 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_rshift); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3537 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 654 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_lshift); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3543 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 656 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3549 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 657 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_callwith); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3555 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 663 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3561 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 664 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3567 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 665 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3573 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 666 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3579 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 668 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setto); }
#line 3585 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 669 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setto_auto); }
#line 3591 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 670 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setto_type); }
#line 3597 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 671 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setto); }
#line 3603 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 672 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setto_type); }
#line 3609 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 674 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_call); }
#line 3615 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 675 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_call); }
#line 3621 "yaoosl.tab.c" /* yacc.c:1646  */
    break;


#line 3625 "yaoosl.tab.c" /* yacc.c:1646  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (scanner, cu, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (scanner, cu, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, scanner, cu);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, scanner, cu);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, cu, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner, cu);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, scanner, cu);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
