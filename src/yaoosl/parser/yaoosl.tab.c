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
#  define YAOOSL_DEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined YAOOSL_DEBUG */
#if YAOOSL_DEBUG
extern int yaoosl_debug;
#endif
/* "%code requires" blocks.  */
#line 219 "yaoosl.y" /* yacc.c:355  */

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
#line 235 "yaoosl.y" /* yacc.c:355  */

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

#line 318 "yaoosl.tab.c" /* yacc.c:355  */

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

#line 452 "yaoosl.tab.c" /* yacc.c:355  */
};

typedef union YAOOSL_STYPE YAOOSL_STYPE;
# define YAOOSL_STYPE_IS_TRIVIAL 1
# define YAOOSL_STYPE_IS_DECLARED 1
#endif


extern YAOOSL_STYPE yaoosl_lval;

int yaoosl_parse (yyscan_t scanner, struct yaoosl_compilationunit* cu);

#endif /* !YY_YAOOSL_YAOOSL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 469 "yaoosl.tab.c" /* yacc.c:358  */

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
#define YYFINAL  102
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1355

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  106
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  253
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  418

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   360

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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105
};

#if YAOOSL_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   401,   401,   403,   404,   405,   406,   407,   408,   410,
     412,   413,   415,   416,   417,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   433,   434,
     435,   437,   439,   440,   441,   442,   444,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   465,   466,   467,   468,   470,
     471,   472,   473,   475,   477,   478,   479,   481,   482,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   514,   515,   516,
     518,   519,   521,   522,   523,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   536,   537,   539,   540,   542,
     543,   545,   546,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   564,   565,
     567,   568,   569,   570,   572,   573,   574,   575,   577,   579,
     580,   582,   583,   585,   586,   588,   590,   592,   594,   595,
     597,   598,   599,   600,   602,   604,   605,   607,   608,   610,
     611,   613,   614,   615,   617,   618,   620,   621,   622,   624,
     625,   626,   627,   628,   630,   631,   632,   634,   635,   636,
     638,   639,   640,   641,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   653,   654,   655,   657,   658,   659,   660,
     661,   662,   663,   665,   666,   667,   668,   669,   670,   672,
     673,   674,   675,   678,   680,   681,   682,   683,   684,   685,
     686,   688,   689,   691,   692,   693,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,   706,   708,   709,
     711,   712,   713,   714
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
  "\"class\"", "\":\"", "\"{\"", "\"}\"", "\"(\"", "\")\"", "\"[\"",
  "\"]\"", "\"void\"", "\"operator\"", "\"++\"", "\"--\"", "\"!\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"+=\"", "\"-=\"", "\"*=\"",
  "\"/=\"", "\"|\"", "\"||\"", "\"|=\"", "\"&\"", "\"&&\"", "\"&=\"",
  "\"^\"", "\"^=\"", "\"~\"", "\"~=\"", "\"%\"", "\"%=\"", "\"<\"",
  "\"<<\"", "\"<=\"", "\"<<=\"", "\">\"", "\">>\"", "\">=\"", "\">>=\"",
  "\"=\"", "\"==\"", "\"!=\"", "\"static\"", "\";\"", "\"return\"",
  "\"throw\"", "\"with\"", "\"try\"", "\"catch\"", "\"finally\"", "\"if\"",
  "\"else\"", "\"for\"", "\"while\"", "\"do\"", "\"switch\"", "\"case\"",
  "\"default\"", "\"continue\"", "\"break\"", "\"?\"", "\"is\"", "\"!is\"",
  "\"new\"", "\"typeof\"", "\"null\"", "\"this\"", "\"true\"", "\"false\"",
  "\"set\"", "\"get\"", "\"namespace\"", "\"base\"", "\"extern\"",
  "$accept", "yaoosl", "root", "nmspc", "identifier", "identlist",
  "stdtype", "vtype", "usingns", "encpsl", "classhead", "classbody",
  "classdef", "mthdargs", "mthd", "cnstmthd", "opmthd", "op0", "op1",
  "op2", "opargs0", "opargs1", "opargs2", "decl", "decllist", "property",
  "prop_set", "prop_get", "mthdbody", "stmntlist", "stmnt", "cntrl_if",
  "cntrl_try", "cntrl_catch", "cntrl_for", "cntrl_for1", "cntrl_for2",
  "cntrl_for3", "cntrl_while", "cntrl_dowhile", "cntrl_switch",
  "cntrl_case", "cntrl_switchbody", "exp", "exp01", "exp02", "exp03",
  "exp04", "exp05", "exp06", "exp07", "exp08", "exp09", "exp10", "exp11",
  "exp12", "cnstexp", "exp13", "exp14", "bexp", "refexp", "calllist",
  "expressionlist", "assign_post", "call_post", "call", YY_NULLPTR
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
     355,   356,   357,   358,   359,   360
};
# endif

#define YYPACT_NINF -329

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-329)))

#define YYTABLE_NINF -55

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     424,   319,    15,  -329,  -329,  -329,  -329,  -329,    28,    35,
    -329,  -329,  -329,  -329,   732,  1207,   587,   587,   689,   689,
    -329,  1093,  1207,   978,  1207,    13,  1207,   978,  1207,   -34,
      29,    35,    78,  -329,  -329,  -329,  -329,    35,    81,   136,
    -329,   319,    91,   319,   112,     3,   319,   319,   978,  -329,
    -329,  -329,  -329,  -329,  -329,    69,  -329,    56,    99,   116,
     -30,   119,    38,   118,   -38,    97,    63,    41,  -329,   980,
    -329,    86,  -329,  -329,  -329,    35,   697,  -329,  -329,   145,
     147,  -329,  -329,   980,   980,  -329,   111,   121,    83,   978,
    1207,   978,   106,   162,  -329,  -329,    81,  1332,   166,  1195,
     128,  -329,  -329,  -329,   697,  -329,  -329,   207,    35,    16,
    -329,  -329,  -329,  -329,  1207,  1207,  1207,  1207,  1207,  1207,
    1207,  1207,  1207,  1207,  1207,  1207,  1207,  1207,  1207,  1207,
    1207,  1207,  1207,  -329,  -329,  1332,  1332,    35,  1207,  1207,
    1207,  1207,  1207,  1207,  1207,  1207,  1207,  1207,  1207,  1207,
    1207,  -329,    35,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
    1080,   978,   130,   129,   138,  -329,  -329,  1207,   630,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,   182,   189,   528,  -329,   216,   195,    35,
    -329,  -329,   217,   199,    45,  -329,   131,   474,   200,    57,
      74,    90,   104,   203,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,   198,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
      81,   834,   157,  -329,   978,   978,  1207,   163,   148,   212,
     630,   630,   211,  -329,  -329,   219,  1207,  -329,  -329,    35,
     174,  -329,   192,   213,   279,   302,    88,  -329,   560,   246,
     250,    17,   220,   221,   222,  -329,  -329,  -329,  -329,  -329,
    1207,  -329,  -329,    95,   254,   248,   247,  -329,  -329,  -329,
     206,  -329,  -329,   252,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,   266,  -329,  -329,  -329,  -329,  1261,   268,  -329,
    -329,    26,   -16,     1,   267,   603,   269,   268,  1332,   268,
    1332,   268,  -329,   697,  -329,  1332,   157,  1207,  -329,  -329,
    -329,   299,   275,   876,  -329,   267,  1269,    64,  -329,    64,
    -329,   268,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,   280,  -329,   304,
    -329,  -329,  -329,   282,  -329,  -329,  -329,  -329,   300,   268,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,     5,    31,   -23,
     -24,   -10,    -8,  -329,  -329,  1332,   978,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,   301,  -329,   303,  -329,   305,  -329,
     306,   297,  -329,  -329,  -329,  -329,  -329,  -329
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    10,   208,   209,   210,   211,   212,     0,     0,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   206,   207,     0,   229,     0,
       2,     0,   222,     0,     0,     0,     0,     0,   121,   132,
     133,   134,   135,   136,   137,     0,   164,   165,   167,   169,
     171,   174,   176,   179,   184,   187,   190,   194,   221,   203,
     213,   230,   220,   219,     8,     0,     0,    31,   130,     0,
       0,   197,   198,   204,   205,   125,     0,     0,   140,     0,
     149,     0,     0,     0,   126,   127,     0,     0,     0,     0,
     248,   253,     1,     7,     0,   252,     4,     0,     0,     0,
       5,     6,   122,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   195,   196,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   216,     0,   251,    11,   218,   131,   223,   124,   128,
       0,     0,   141,   138,     0,   150,   155,     0,     0,   226,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,     0,     0,   231,   233,     0,     0,
     217,    36,    12,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   170,   172,   173,   175,   177,
     178,   180,   181,   182,   183,   185,   186,   188,   189,   191,
     192,   193,   201,   199,   202,   200,   215,     0,   237,   238,
     239,   240,   242,   243,   244,   245,   241,   247,   246,   236,
       0,     0,   144,   143,     0,     0,   151,     0,     0,     0,
     162,   160,     0,   225,   224,     0,   234,   232,   249,    13,
       0,    53,     0,     0,     0,     0,    10,    28,     0,    30,
      29,     0,     0,     0,     0,    56,    37,    39,    41,    43,
       0,   214,   250,   222,     0,   102,     0,   146,   142,   139,
       0,   152,   156,     0,   159,   163,   161,   157,     9,   235,
      14,    57,     0,    45,    47,    49,    51,     0,     0,    30,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,   101,   100,   103,   145,   153,   158,    55,
      59,     0,     0,     0,    63,     0,     0,     0,   105,     0,
     110,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    97,    64,     0,    65,     0,
      66,   104,   147,     0,   154,   101,    60,   120,     0,     0,
      80,    81,    82,    83,    84,    88,    85,    89,    86,    87,
      90,    91,    96,    92,    95,    93,    94,     0,     0,     0,
       0,     0,     0,    61,    98,     0,     0,   119,    62,   115,
     116,   117,   118,   109,     0,   107,     0,   114,     0,   112,
       0,     0,   148,   108,   106,   113,   111,    99
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -329,  -329,    14,  -329,    -9,  -329,   -84,    72,  -329,     7,
    -329,   181,  -329,  -295,   141,   153,   154,  -329,  -329,  -329,
    -329,  -329,  -329,  -306,  -211,   158,  -328,  -321,  -172,   -12,
     -22,  -329,  -329,  -239,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,   -74,   146,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,   173,    93,   186,  -329,  -329,
    -329,   259,   100,   -72,   -32,  -329
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    39,    40,    41,    42,   193,   284,   271,    43,   197,
      45,   198,    46,   308,   199,   200,   201,   272,   273,   274,
     317,   319,   321,   285,   286,   202,   389,   390,   334,    47,
      48,    49,    50,   162,    51,   164,   290,   363,    52,    53,
      54,   251,   252,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   100,   188,   151,   105,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    88,    79,   287,   155,    92,   101,    44,    44,   405,
     403,   391,   357,   184,   359,    74,   337,   194,   392,   341,
     314,   117,    96,   407,    75,   409,   126,   118,    98,   335,
     127,    76,   190,   339,   108,   109,   112,   333,     2,   153,
     369,    94,    10,    11,    12,    13,   194,    90,    44,   195,
      44,   223,   225,    44,    44,   103,   315,   106,   194,   338,
     110,   111,   406,   333,   410,   336,   154,   163,   404,   166,
     408,    10,    11,    12,    13,   194,   340,   387,   -54,   388,
     399,   133,   134,    10,    11,    12,    13,   362,   183,   411,
     -38,   194,   388,   387,   104,   152,   332,    75,   323,   192,
      10,    11,    12,    13,    95,   194,   401,   -40,   130,   131,
     120,   121,    97,   270,   361,    99,    10,    11,    12,    13,
      99,   196,   307,   -42,   132,    99,   222,   224,   226,    99,
      10,    11,    12,    13,   135,   136,   102,   -44,   242,   243,
     128,   129,   107,   240,   113,   356,   250,   358,   114,   360,
     196,   115,     3,     4,     5,     6,     7,    10,    11,    12,
      13,    80,   196,   160,   161,   387,   388,    86,    87,   393,
      89,   116,    91,   119,    93,   194,   295,   296,   156,   196,
     258,   122,   157,   123,   310,   124,   158,   125,   269,    81,
      82,   167,    44,   194,   168,   196,   159,   398,   185,   255,
      10,    11,    12,    13,    83,    84,   189,   301,   282,   196,
     191,   244,   245,   246,   194,   400,   402,   253,    10,    11,
      12,    13,   288,   289,   254,   -46,   256,   259,   250,   250,
     257,   260,   283,   275,   280,   281,   165,   160,   292,    10,
      11,    12,    13,   294,   297,   187,   -48,    35,    36,   312,
     300,   190,   298,   313,   316,   318,   320,   324,   325,   309,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   196,
     194,   327,   326,   328,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   196,   331,   329,
     333,   307,   365,   194,   355,    10,    11,    12,    13,   331,
     366,   331,   -50,   247,   395,   394,   331,   396,   196,    -3,
       1,   368,     2,     3,     4,     5,     6,     7,    10,    11,
      12,    13,   417,   397,   413,   -52,   414,   262,   415,   416,
     311,   293,     0,     8,     9,    10,    11,    12,    13,   263,
     264,    14,    -3,    15,   265,   169,   299,     0,     0,    16,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   412,   261,     0,     0,    19,     0,
     276,   277,   278,   279,   196,     0,   331,    80,     0,     0,
       0,     0,   291,     0,    20,    21,    22,     0,    23,     0,
       0,    24,   187,    25,    26,    27,    28,   196,     0,    29,
      30,     0,     0,     0,    31,    32,    33,    34,    35,    36,
       0,     0,    37,    38,    -3,     1,   322,     2,     3,     4,
       5,     6,     7,     0,     0,     0,     0,     0,     0,     0,
       0,   302,     0,   303,   304,   305,   306,     0,     8,     9,
      10,    11,    12,    13,     0,     0,    14,     0,    15,     0,
       0,     0,     0,     0,    16,    17,    18,     0,     0,     0,
       0,     0,     0,   364,     0,     0,     0,   266,     0,     0,
       0,     0,     0,    19,     0,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,     0,    20,
      21,    22,     0,    23,     0,     0,    24,     0,    25,    26,
      27,    28,   267,     0,    29,    30,     0,     0,     0,    31,
      32,    33,    34,    35,    36,     0,     0,    37,    38,     1,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,     0,
       0,     0,     8,     9,    10,    11,    12,    13,     0,     0,
      14,    -3,    15,     2,     0,     0,     0,     0,    16,    17,
      18,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,     0,     0,     0,    19,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,   267,     0,
       0,     0,     0,    20,    21,    22,     0,    23,     0,     0,
      24,     8,    25,    26,    27,    28,     0,     0,    29,    30,
       0,    15,     0,    31,    32,    33,    34,    35,    36,    18,
       0,    37,    38,     2,     3,     4,     5,     6,     7,     0,
       0,     0,     0,   342,   343,   344,    19,     0,     0,     0,
     345,   346,   347,   348,     8,     0,   349,     0,     0,   350,
       0,   351,    14,   352,    15,     0,     0,     0,     0,   353,
      16,    17,    18,   354,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,     0,    19,
       0,    38,     2,     3,     4,     5,     6,     7,     0,     0,
       0,     0,     0,     0,     0,    20,    21,    22,     0,    23,
       0,     0,    24,     8,    25,    26,    27,    28,   248,   249,
      29,    30,     0,    15,     0,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    38,     2,     3,     4,     5,     6,
       7,     0,     0,     0,   139,   140,   141,   142,     0,     0,
     143,     0,     0,   144,     0,   145,     8,   146,     0,   147,
       0,     0,     0,   148,    14,    78,    15,   149,   150,     0,
       0,     0,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    32,    33,    34,    35,    36,
       0,    19,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,    22,
       0,    23,     0,     0,    24,     0,    25,    26,    27,    28,
       0,     0,    29,    30,     0,     0,     0,    31,    32,    33,
      34,    35,    36,     0,     0,     0,    38,     2,     3,     4,
       5,     6,     7,     0,     0,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,     0,    16,    17,    18,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       8,     0,     0,     0,     0,     0,     0,     0,    14,   367,
      15,     0,     0,     0,     0,     0,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,    19,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,    22,     0,    23,     0,     0,    24,     0,
      25,    26,    27,    28,     0,     0,    29,    30,     0,     0,
       0,    31,    32,    33,    34,    35,    36,     0,     0,     0,
      38,     2,     3,     4,     5,     6,     7,     0,     0,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0,
      14,     0,    15,     0,     0,     0,   138,     0,    16,    17,
      18,     0,     0,     0,     0,     0,     0,   139,   140,   141,
     142,     0,     0,   143,     0,     0,   144,    19,   145,     0,
     146,     0,   147,     0,     0,     0,   148,     0,     0,     0,
     149,   150,     0,    20,    21,    22,     0,    23,     0,     0,
      24,     0,    25,    26,    27,    28,     0,     0,    29,    30,
       0,     0,     0,    31,    32,    33,    34,    35,    36,     0,
       0,     0,    38,     2,     3,     4,     5,     6,     7,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,    14,     0,   241,     0,     0,     8,     0,     0,
      16,    17,    18,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,    16,    17,    18,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,    20,    21,    22,     0,    23,
       0,     0,    24,     0,    25,    26,    27,    28,    85,     0,
      29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    38,     0,     0,     0,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    38,     2,     3,
       4,     5,     6,     7,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
     186,     8,     0,     0,     0,    16,    17,    18,     0,     0,
       0,    15,     0,     0,     0,     0,     0,    16,    17,    18,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,    19,     0,     0,     0,
       0,     0,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,     0,     0,     0,     0,     0,
      31,    32,    33,    34,    35,    36,   330,     0,     0,    38,
       0,     0,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    38,   370,   371,   372,   373,     0,     0,     0,     0,
     374,   375,     0,   376,   377,     0,   378,     0,   379,     0,
     380,     0,     0,   381,   382,     2,     0,   383,   384,     0,
       0,   385,   386,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182
};

static const yytype_int16 yycheck[] =
{
       9,    23,    14,   242,    76,    27,    38,     0,     1,    33,
      33,   339,   318,    97,   320,     1,    32,     1,   339,   314,
       3,    51,    31,    33,     9,    33,    64,    57,    37,     3,
      68,     3,   104,    32,    31,    32,    48,    32,     3,    71,
     335,    75,    26,    27,    28,    29,     1,    34,    41,    33,
      43,   135,   136,    46,    47,    41,    39,    43,     1,    75,
      46,    47,   390,    32,   392,    39,    75,    89,   389,    91,
     391,    26,    27,    28,    29,     1,    75,   101,    33,   102,
      75,    40,    41,    26,    27,    28,    29,   326,    97,   395,
      33,     1,   102,   101,     3,     9,   307,     9,     3,   108,
      26,    27,    28,    29,    75,     1,    75,    33,    45,    46,
      72,    73,    34,   197,   325,    34,    26,    27,    28,    29,
      34,   105,    34,    33,    61,    34,   135,   136,   137,    34,
      26,    27,    28,    29,    93,    94,     0,    33,   160,   161,
      43,    44,    30,   152,    75,   317,   168,   319,    92,   321,
     105,    52,     4,     5,     6,     7,     8,    26,    27,    28,
      29,    15,   105,    80,    81,   101,   102,    21,    22,   341,
      24,    55,    26,    54,    28,     1,   250,   251,    33,   105,
     189,    63,    35,    65,   268,    67,    75,    69,   197,    16,
      17,    85,   185,     1,    32,   105,    75,   369,    32,   185,
      26,    27,    28,    29,    18,    19,    78,    33,   240,   105,
       3,    81,    83,    75,     1,   387,   388,    35,    26,    27,
      28,    29,   244,   245,    35,    33,    10,    10,   250,   251,
      35,    32,   241,    33,    31,    37,    90,    80,    75,    26,
      27,    28,    29,    31,    33,    99,    33,    99,   100,     3,
     259,   323,    33,     3,    34,    34,    34,     3,    10,   268,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   105,
       1,    75,    35,    31,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   105,   307,    33,
      32,    34,     3,     1,    35,    26,    27,    28,    29,   318,
      35,   320,    33,   167,    10,    35,   325,    35,   105,     0,
       1,   333,     3,     4,     5,     6,     7,     8,    26,    27,
      28,    29,    35,    33,    33,    33,    33,   196,    33,    33,
     268,   248,    -1,    24,    25,    26,    27,    28,    29,   196,
     196,    32,    33,    34,   196,    96,   256,    -1,    -1,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   396,   194,    -1,    -1,    59,    -1,
     199,   200,   201,   202,   105,    -1,   395,   241,    -1,    -1,
      -1,    -1,   246,    -1,    75,    76,    77,    -1,    79,    -1,
      -1,    82,   256,    84,    85,    86,    87,   105,    -1,    90,
      91,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
      -1,    -1,   103,   104,     0,     1,   280,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   260,    -1,   262,   263,   264,   265,    -1,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,   327,    -1,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    75,
      76,    77,    -1,    79,    -1,    -1,    82,    -1,    84,    85,
      86,    87,    38,    -1,    90,    91,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,    -1,    -1,   103,   104,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,     3,    -1,    -1,    -1,    -1,    40,    41,
      42,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    59,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    79,    -1,    -1,
      82,    24,    84,    85,    86,    87,    -1,    -1,    90,    91,
      -1,    34,    -1,    95,    96,    97,    98,    99,   100,    42,
      -1,   103,   104,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    40,    41,    42,    59,    -1,    -1,    -1,
      47,    48,    49,    50,    24,    -1,    53,    -1,    -1,    56,
      -1,    58,    32,    60,    34,    -1,    -1,    -1,    -1,    66,
      40,    41,    42,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,    -1,    59,
      -1,   104,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    79,
      -1,    -1,    82,    24,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    34,    -1,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,   104,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    47,    48,    49,    50,    -1,    -1,
      53,    -1,    -1,    56,    -1,    58,    24,    60,    -1,    62,
      -1,    -1,    -1,    66,    32,    33,    34,    70,    71,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
      -1,    59,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    79,    -1,    -1,    82,    -1,    84,    85,    86,    87,
      -1,    -1,    90,    91,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,    -1,    -1,    -1,   104,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,    59,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    79,    -1,    -1,    82,    -1,
      84,    85,    86,    87,    -1,    -1,    90,    91,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
     104,     3,     4,     5,     6,     7,     8,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    34,    -1,    -1,    -1,    36,    -1,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    -1,    -1,    53,    -1,    -1,    56,    59,    58,    -1,
      60,    -1,    62,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      70,    71,    -1,    75,    76,    77,    -1,    79,    -1,    -1,
      82,    -1,    84,    85,    86,    87,    -1,    -1,    90,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,   104,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    -1,    24,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    75,    76,    77,    -1,    79,
      -1,    -1,    82,    -1,    84,    85,    86,    87,    75,    -1,
      90,    91,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,   104,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,   104,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    24,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,    35,    -1,    -1,   104,
      -1,    -1,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,   104,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      51,    52,    -1,    54,    55,    -1,    57,    -1,    59,    -1,
      61,    -1,    -1,    64,    65,     3,    -1,    68,    69,    -1,
      -1,    72,    73,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    24,    25,
      26,    27,    28,    29,    32,    34,    40,    41,    42,    59,
      75,    76,    77,    79,    82,    84,    85,    86,    87,    90,
      91,    95,    96,    97,    98,    99,   100,   103,   104,   107,
     108,   109,   110,   114,   115,   116,   118,   135,   136,   137,
     138,   140,   144,   145,   146,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   171,   108,     9,     3,   110,    33,   135,
     149,   161,   161,   163,   163,    75,   149,   149,   136,   149,
      34,   149,   136,   149,    75,    75,   110,    34,   110,    34,
     167,   170,     0,   108,     3,   170,   108,    30,    31,    32,
     108,   108,   135,    75,    92,    52,    55,    51,    57,    54,
      72,    73,    63,    65,    67,    69,    64,    68,    43,    44,
      45,    46,    61,    40,    41,    93,    94,     9,    36,    47,
      48,    49,    50,    53,    56,    58,    60,    62,    66,    70,
      71,   169,     9,   170,   110,   169,    33,    35,    75,    75,
      80,    81,   139,   136,   141,   149,   136,    85,    32,   167,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   110,   112,    32,    35,   149,   168,    78,
     169,     3,   110,   111,     1,    33,   105,   115,   117,   120,
     121,   122,   131,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   110,   112,   110,   112,   110,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     110,    34,   136,   136,    81,    83,    75,   149,    88,    89,
     136,   147,   148,    35,    35,   108,    10,    35,   110,    10,
      32,   117,   120,   121,   122,   131,     3,    38,    74,   110,
     112,   113,   123,   124,   125,    33,   117,   117,   117,   117,
      31,    37,   170,   110,   112,   129,   130,   139,   136,   136,
     142,   149,    75,   162,    31,   148,   148,    33,    33,   168,
     110,    33,   117,   117,   117,   117,   117,    34,   119,   110,
     112,   113,     3,     3,     3,    39,    34,   126,    34,   127,
      34,   128,   149,     3,     3,    10,    35,    75,    31,    33,
      35,   110,   130,    32,   134,     3,    39,    32,    75,    32,
      75,   119,    40,    41,    42,    47,    48,    49,    50,    53,
      56,    58,    60,    66,    70,    35,   134,   129,   134,   129,
     134,   130,   139,   143,   149,     3,    35,    33,   135,   119,
      43,    44,    45,    46,    51,    52,    54,    55,    57,    59,
      61,    64,    65,    68,    69,    72,    73,   101,   102,   132,
     133,   132,   133,   134,    35,    10,    35,    33,   134,    75,
     134,    75,   134,    33,   133,    33,   132,    33,   133,    33,
     132,   129,   136,    33,    33,    33,    33,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   106,   107,   108,   108,   108,   108,   108,   108,   109,
     110,   110,   111,   111,   111,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     113,   114,   115,   115,   115,   115,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   118,   118,   118,   118,   119,
     119,   120,   120,   121,   122,   122,   122,   123,   123,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   126,   127,   128,
     129,   129,   130,   130,   130,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   132,   132,   133,   133,   134,
     134,   135,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   137,   137,
     138,   138,   138,   138,   139,   139,   139,   139,   140,   141,
     141,   142,   142,   143,   143,   144,   145,   146,   147,   147,
     148,   148,   148,   148,   149,   150,   150,   151,   151,   152,
     152,   153,   153,   153,   154,   154,   155,   155,   155,   156,
     156,   156,   156,   156,   157,   157,   157,   158,   158,   158,
     159,   159,   159,   159,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   161,   161,   161,   162,   162,   162,   162,
     162,   162,   162,   163,   163,   163,   163,   163,   163,   164,
     164,   164,   164,   165,   166,   166,   166,   166,   166,   166,
     166,   167,   167,   168,   168,   168,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   170,   170,
     171,   171,   171,   171
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     2,     2,     5,
       1,     3,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     3,     2,     1,     2,
       1,     2,     1,     2,     1,     3,     2,     3,     2,     3,
       2,     3,     2,     2,     1,     6,     4,     5,     3,     2,
       3,     5,     6,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     2,     3,     5,
       2,     2,     1,     2,     3,     4,     7,     6,     7,     6,
       4,     7,     6,     7,     6,     2,     2,     2,     2,     3,
       2,     1,     2,     1,     3,     2,     2,     2,     3,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     3,     5,
       2,     3,     5,     4,     2,     4,     3,     5,     9,     0,
       1,     0,     1,     0,     1,     3,     5,     5,     3,     2,
       1,     2,     1,     2,     1,     1,     5,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     2,     2,     3,
       3,     3,     3,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     2,     3,     3,     1,
       1,     1,     1,     3,     4,     4,     3,     1,     1,     1,
       1,     2,     3,     1,     2,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     3,
       4,     2,     2,     2
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
          case 2:
#line 401 "yaoosl.y" /* yacc.c:1646  */
    { cu->parse_0 = (yyvsp[0].cst); }
#line 2299 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 403 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_empty); }
#line 2305 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 404 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_root); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2311 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 405 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_root); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2317 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 406 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_root); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2323 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 407 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_root); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2329 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 408 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 2335 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 410 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_namespace); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2341 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 412 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_ident); CSTPSH((yyval.cst), CSTNODEV(yscst_name, (yyvsp[0].str))); }
#line 2347 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 413 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_ident); CSTPSH((yyval.cst), CSTNODEV(yscst_name, (yyvsp[-2].str))); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2353 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 415 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_identlist); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2359 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 416 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_identlist); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2365 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 417 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_identlist); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2371 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 419 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_bool)); }
#line 2377 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 420 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_string)); }
#line 2383 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 421 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_char)); }
#line 2389 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 422 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_int8)); }
#line 2395 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 423 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_uint8)); }
#line 2401 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 424 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_int16)); }
#line 2407 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 425 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_uint16)); }
#line 2413 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 426 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_int32)); }
#line 2419 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 427 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_uint32)); }
#line 2425 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 428 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_int64)); }
#line 2431 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 429 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_uint64)); }
#line 2437 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 430 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_float)); }
#line 2443 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 431 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_double)); }
#line 2449 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 433 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_type); CSTPSH((yyval.cst), CSTNODE(yscst_void)); }
#line 2455 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 434 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 2461 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 437 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_using); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2467 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 439 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_encapsulation_public); }
#line 2473 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 440 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_encapsulation_internal); }
#line 2479 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 441 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_encapsulation_derived); }
#line 2485 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 442 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_encapsulation_private); }
#line 2491 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 444 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classhead); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[0].str))); }
#line 2497 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 446 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2503 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 447 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2509 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 448 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2515 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 449 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2521 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 450 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2527 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 451 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2533 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 452 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2539 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 453 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2545 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 454 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), CSTNODE(yscst_extern)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2551 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 455 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), CSTNODE(yscst_extern)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2557 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 456 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), CSTNODE(yscst_extern)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2563 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 457 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), CSTNODE(yscst_extern)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2569 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 458 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), CSTNODE(yscst_extern)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2575 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 459 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), CSTNODE(yscst_extern)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2581 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 460 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), CSTNODE(yscst_extern)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2587 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 461 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classbody); CSTPSH((yyval.cst), CSTNODE(yscst_extern)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2593 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 462 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_error); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2599 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 463 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_error); }
#line 2605 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 465 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classdef); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2611 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 466 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classdef); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2617 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 467 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classdef); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); }
#line 2623 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 468 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_classdef); CSTPSH((yyval.cst), (yyvsp[-2].cst)); }
#line 2629 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 470 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_mthdargs); }
#line 2635 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 471 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_mthdargs); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2641 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 472 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_mthd); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-2].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2647 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 473 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_smthd); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-2].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2653 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 475 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cnstmthd); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-2].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2659 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 477 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_opmthd); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2665 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 478 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_opmthd); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2671 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 479 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_opmthd); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2677 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 481 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_inc_r0); }
#line 2683 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 482 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_dec_r0); }
#line 2689 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 484 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_not_v1); }
#line 2695 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 485 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_add_r1); }
#line 2701 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 486 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_sub_r1); }
#line 2707 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 487 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_mul_r1); }
#line 2713 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 488 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_div_r1); }
#line 2719 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 489 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_or_r1); }
#line 2725 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 490 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_and_r1); }
#line 2731 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 491 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_xor_r1); }
#line 2737 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 492 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_inv_r1); }
#line 2743 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 493 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_lshift_r1); }
#line 2749 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 494 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_rshift_r1); }
#line 2755 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 496 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_add_v2); }
#line 2761 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 497 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_sub_v2); }
#line 2767 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 498 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_mul_v2); }
#line 2773 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 499 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_div_v2); }
#line 2779 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 500 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_or_v2); }
#line 2785 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 501 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_and_v2); }
#line 2791 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 502 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_xor_v2); }
#line 2797 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 503 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_bit_inv_v2); }
#line 2803 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 504 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_log_or_v2); }
#line 2809 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 505 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_log_and_v2); }
#line 2815 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 506 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_mod_v2); }
#line 2821 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 507 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_lshift_v2); }
#line 2827 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 508 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_rshift_v2); }
#line 2833 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 509 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_log_equal_v2); }
#line 2839 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 510 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_log_notequal_v2); }
#line 2845 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 511 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_log_greater_then_v2); }
#line 2851 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 512 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_op_log_less_then_v2); }
#line 2857 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 514 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_mthdargs); }
#line 2863 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 515 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_mthdargs); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2869 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 516 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_mthdargs); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2875 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 518 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_decl, (yyvsp[0].str)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2881 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 519 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_decl, (yyvsp[0].str)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2887 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 521 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_decllist); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2893 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 522 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_decllist); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2899 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 523 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_decllist); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 2905 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 525 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-1].str))); }
#line 2911 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 526 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-6].cst)); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-4].str))); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2917 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 527 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-3].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2923 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 528 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-6].cst)); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-4].str))); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2929 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 529 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-3].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2935 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 530 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-1].str))); }
#line 2941 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 531 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-6].cst)); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-4].str))); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2947 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 532 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-3].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2953 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 533 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-6].cst)); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-4].str))); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2959 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 534 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property); CSTPSH((yyval.cst), (yyvsp[-5].cst)); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), CSTNODEV(yscst_ident, (yyvsp[-3].str))); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 2965 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 536 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property_set); }
#line 2971 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 537 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property_set); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2977 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 539 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property_get); }
#line 2983 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 540 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_property_get); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 2989 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 542 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_mthdbody); CSTIMP((yyval.cst), (yyvsp[-1].cst)); }
#line 2995 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 543 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_mthdbody); }
#line 3001 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 545 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_statementlist); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3007 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 546 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_statementlist); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 3013 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 548 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_empty); }
#line 3019 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 549 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_return); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3025 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 550 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_return); }
#line 3031 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 551 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_continue); }
#line 3037 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 552 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_break); }
#line 3043 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 553 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_throw); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3049 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 554 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[-1].cst); }
#line 3055 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 555 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_empty); }
#line 3061 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 556 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[-1].cst); }
#line 3067 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 557 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3073 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 558 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3079 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 559 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3085 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 560 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3091 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 561 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3097 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 562 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3103 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 564 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_if); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3109 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 565 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_if); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3115 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 567 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_try); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3121 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 568 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_try); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3127 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 569 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_try); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3133 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 570 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_try); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3139 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 572 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_catch); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3145 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 573 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_catch); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3151 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 574 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_catch); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 3157 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 575 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_catch); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 3163 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 577 "yaoosl.y" /* yacc.c:1646  */
    {  (yyval.cst) = CSTNODE(yscst_cntrl_for); CSTPSH((yyval.cst), (yyvsp[-6].cst)); CSTPSH((yyval.cst), (yyvsp[-4].cst)) ;CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3169 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 579 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_for_arg); }
#line 3175 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 580 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_for_arg); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3181 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 582 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_for_arg); }
#line 3187 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 583 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_for_arg); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3193 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 585 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_for_arg); }
#line 3199 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 586 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_for_arg); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3205 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 588 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_while); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3211 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 590 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_dowhile); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3217 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 592 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_cntrl_switch); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3223 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 594 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_case); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3229 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 595 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_case_default); }
#line 3235 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 597 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_statementlist); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3241 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 598 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_statementlist); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 3247 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 599 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_statementlist); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3253 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 600 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_statementlist); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 3259 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 602 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3265 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 604 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3271 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 605 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_ternary); CSTPSH((yyval.cst), (yyvsp[-4].cst)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3277 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 607 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3283 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 608 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_log_or); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3289 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 610 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3295 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 611 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_log_and); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3301 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 613 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3307 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 614 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_bin_or); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3313 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 615 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_bin_xor); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3319 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 617 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3325 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 618 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_bin_and); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3331 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 620 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3337 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 621 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_equal); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3343 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 622 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_notequal); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3349 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 624 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3355 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 625 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_less); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3361 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 626 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_less_equal); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3367 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 627 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_greater); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3373 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 628 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_greater_equal); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3379 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 630 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3385 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 631 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_lshift); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3391 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 632 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_rshift); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3397 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 634 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3403 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 635 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_add); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3409 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 636 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_sub); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3415 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 638 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3421 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 639 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_mul); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3427 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 640 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_div); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3433 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 641 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_mod); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3439 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 643 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3445 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 644 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_post_inc); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3451 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 645 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_post_dec); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3457 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 646 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_pre_inc); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3463 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 647 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_pre_dec); CSTPSH((yyval.cst), (yyvsp[0].cst));}
#line 3469 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 648 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_is); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3475 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 649 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_isnot); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3481 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 650 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_is); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3487 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 651 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_isnot); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3493 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 653 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3499 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 654 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_log_not); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3505 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 655 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_exp_invert); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3511 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 657 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_val_true); }
#line 3517 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 658 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_val_false); }
#line 3523 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 659 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_val_number, (yyvsp[0].str)); }
#line 3529 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 660 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_val_number_hex, (yyvsp[0].str)); }
#line 3535 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 661 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_val_number_binary, (yyvsp[0].str)); }
#line 3541 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 662 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_val_string, (yyvsp[0].str)); }
#line 3547 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 663 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_val_char, (yyvsp[0].str)); }
#line 3553 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 665 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3559 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 666 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_array); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3565 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 667 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_nav); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3571 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 668 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setto_exp); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3577 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 669 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_setto_type, (yyvsp[-1].str)); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3583 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 670 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODEV(yscst_setto_auto, (yyvsp[-1].str)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3589 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 672 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3595 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 673 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3601 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 674 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3607 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 675 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3613 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 678 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_valexp); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3619 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 680 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_typeof); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3625 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 681 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_typeof); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3631 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 682 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_new); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3637 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 683 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_null); }
#line 3643 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 684 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_this); }
#line 3649 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 685 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_base); }
#line 3655 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 686 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3661 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 688 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_calllist); }
#line 3667 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 689 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_calllist); CSTIMP((yyval.cst), (yyvsp[-1].cst)); }
#line 3673 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 691 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_expressionlist); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3679 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 692 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_expressionlist); CSTPSH((yyval.cst), (yyvsp[-1].cst)); }
#line 3685 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 693 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_expressionlist); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTIMP((yyval.cst), (yyvsp[0].cst)); }
#line 3691 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 695 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3697 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 696 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_add); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3703 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 697 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_sub); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3709 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 698 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_mul); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3715 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 699 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_div); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3721 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 700 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_mod); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3727 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 701 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_bin_or); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3733 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 702 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_bin_and); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3739 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 703 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_bin_xor); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3745 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 704 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_invert); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3751 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 705 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_rshift); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3757 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 706 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_setvar_lshift); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3763 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 708 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = (yyvsp[0].cst); }
#line 3769 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 709 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_callwith); CSTPSH((yyval.cst), (yyvsp[-2].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3775 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 711 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_call); CSTPSH((yyval.cst), (yyvsp[-3].cst)); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst));}
#line 3781 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 712 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_call); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3787 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 713 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_call); CSTPSH((yyval.cst), (yyvsp[-1].cst)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3793 "yaoosl.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 714 "yaoosl.y" /* yacc.c:1646  */
    { (yyval.cst) = CSTNODE(yscst_call); CSTPSH((yyval.cst), CSTNODE(yscst_base)); CSTPSH((yyval.cst), (yyvsp[0].cst)); }
#line 3799 "yaoosl.tab.c" /* yacc.c:1646  */
    break;


#line 3803 "yaoosl.tab.c" /* yacc.c:1646  */
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
#line 717 "yaoosl.y" /* yacc.c:1906  */


static int yaoosl_error(yyscan_t scanner, struct yaoosl_compilationunit *ycu, const char* msg)
{
    size_t start, end, i, max_len = 0;

    // Find line start
    max_len += 50;
    for (i = ycu->code_index - 1; i != ~(size_t)0 && max_len > 0; i--, max_len--)
    {
        if (ycu->code[i] == '\n')
        {
            break;
        }
    }
    start = i + 1;

    // Find line end
    max_len += 50;
    for (i = ycu->code_index; i != SIZE_MAX && max_len > 0; i++, max_len--)
    {
        if (ycu->code[i] == '\n' || ycu->code[i] == '\0')
        {
            break;
        }
    }
    end = i;

    printf("%.*s\n", (unsigned int)(end - start), ycu->code + start);
    // if (end == ycu->code_index)
    // { // We probably errored on new-line, find first non-whitespace char and mark
    //     for (i = end; i > start; i--)
    //     {
    //         switch (ycu->code[i])
    //         {
    //         case ' ':
    //         case '\t':
    //         case '\r':
    //         case '\n':
    //             break;
    //         default:
    //             for (; i > start; i--)
    //             {
    //                 printf(" ");
    //             }
    //             printf("^");
    //             goto end;
    //         }
    //     }
    // }
    // else
    // {
     for (i = start; i < end; i++)
     {
          if (i == ycu->code_index - 2)
          {
               printf("^");
          }
          else if (ycu->code[i] == '\t')
          {
               printf("\t");
          }
          else
          {
               printf(" ");
          }
     }
    //}
end:

    printf("\n[L%lld|C%lld] %s\n", ycu->code_line + 1, ycu->code_column + 1, msg);
    ycu->errored = true;
    return 0;
}

int yaoosl_yylex_get_next_char(struct yaoosl_compilationunit* ycu, char* buffer, int max_buffer)
{
    char c = ycu->code[ycu->code_index];
    if (c == 0) { return 0; }
    ycu->code_index++;
    buffer[0] = c;
    switch (c)
    {
        case '\n':
            ycu->code_line++;
            ycu->code_column = 0;
            break;
        default:
            ycu->code_column++;
            break;
    }
    return c == 0 ? 0 : 1;
}


static void yaoosl_yycstnode_printf_helper(yaoosl_cstnode node, unsigned short offset)
{
#define SPACES10 "          "
#define SPACES20 SPACES10 SPACES10
#define SPACES100 SPACES20 SPACES20 SPACES20 SPACES20 SPACES20
#define SPACES300 SPACES100 SPACES100 SPACES100
#define SPACES1000 SPACES100 SPACES300 SPACES300 SPACES300
    size_t i;
        enum yaoosl_cst_type csttype = node.type;
        switch (csttype)
        {
        case yscst_error: printf("%.*syscst_error", (unsigned int)offset, SPACES1000); break;
        case yscst_empty: printf("%.*syscst_empty", (unsigned int)offset, SPACES1000); break;
        case yscst_root: printf("%.*syscst_root", (unsigned int)offset, SPACES1000); break;
        case yscst_namespace: printf("%.*syscst_namespace", (unsigned int)offset, SPACES1000); break;
        case yscst_using: printf("%.*syscst_using", (unsigned int)offset, SPACES1000); break;
        case yscst_body: printf("%.*syscst_body", (unsigned int)offset, SPACES1000); break;
        case yscst_ident: printf("%.*syscst_ident", (unsigned int)offset, SPACES1000); break;
        case yscst_thisident: printf("%.*syscst_thisident", (unsigned int)offset, SPACES1000); break;
        case yscst_identlist: printf("%.*syscst_identlist", (unsigned int)offset, SPACES1000); break;
        case yscst_encapsulation_public: printf("%.*syscst_encapsulation_public", (unsigned int)offset, SPACES1000); break;
        case yscst_encapsulation_internal: printf("%.*syscst_encapsulation_internal", (unsigned int)offset, SPACES1000); break;
        case yscst_encapsulation_derived: printf("%.*syscst_encapsulation_derived", (unsigned int)offset, SPACES1000); break;
        case yscst_encapsulation_private: printf("%.*syscst_encapsulation_private", (unsigned int)offset, SPACES1000); break;
        case yscst_classdef: printf("%.*syscst_classdef", (unsigned int)offset, SPACES1000); break;
        case yscst_classhead: printf("%.*syscst_classhead", (unsigned int)offset, SPACES1000); break;
        case yscst_classbody: printf("%.*syscst_classbody", (unsigned int)offset, SPACES1000); break;
        case yscst_nav: printf("%.*syscst_nav", (unsigned int)offset, SPACES1000); break;
        case yscst_multicode: printf("%.*syscst_multicode", (unsigned int)offset, SPACES1000); break;
        case yscst_property: printf("%.*syscst_property", (unsigned int)offset, SPACES1000); break;
        case yscst_property_set: printf("%.*syscst_property_set", (unsigned int)offset, SPACES1000); break;
        case yscst_property_get: printf("%.*syscst_property_get", (unsigned int)offset, SPACES1000); break;
        case yscst_cntrl_try: printf("%.*syscst_cntrl_try", (unsigned int)offset, SPACES1000); break;
        case yscst_cntrl_if: printf("%.*syscst_cntrl_if", (unsigned int)offset, SPACES1000); break;
        case yscst_cntrl_catch: printf("%.*syscst_cntrl_catch", (unsigned int)offset, SPACES1000); break;
        case yscst_cntrl_for: printf("%.*syscst_cntrl_for", (unsigned int)offset, SPACES1000); break;
        case yscst_cntrl_for_arg: printf("%.*syscst_cntrl_for_arg", (unsigned int)offset, SPACES1000); break;
        case yscst_cntrl_while: printf("%.*syscst_cntrl_while", (unsigned int)offset, SPACES1000); break;
        case yscst_cntrl_dowhile: printf("%.*syscst_cntrl_dowhile", (unsigned int)offset, SPACES1000); break;
        case yscst_cntrl_switch: printf("%.*syscst_cntrl_switch", (unsigned int)offset, SPACES1000); break;
        case yscst_mthd: printf("%.*syscst_mthd", (unsigned int)offset, SPACES1000); break;
        case yscst_smthd: printf("%.*syscst_smthd", (unsigned int)offset, SPACES1000); break;
        case yscst_opmthd: printf("%.*syscst_opmthd", (unsigned int)offset, SPACES1000); break;
        case yscst_case: printf("%.*syscst_case", (unsigned int)offset, SPACES1000); break;
        case yscst_case_default: printf("%.*syscst_case_default", (unsigned int)offset, SPACES1000); break;
        case yscst_decl: printf("%.*syscst_decl", (unsigned int)offset, SPACES1000); break;
        case yscst_decllist: printf("%.*syscst_decllist", (unsigned int)offset, SPACES1000); break;
        case yscst_cnstmthd: printf("%.*syscst_cnstmthd", (unsigned int)offset, SPACES1000); break;
        case yscst_mthdargs: printf("%.*syscst_mthdargs", (unsigned int)offset, SPACES1000); break;
        case yscst_mthdbody: printf("%.*syscst_mthdbody", (unsigned int)offset, SPACES1000); break;
        case yscst_statementlist: printf("%.*syscst_statementlist", (unsigned int)offset, SPACES1000); break;
        case yscst_statement: printf("%.*syscst_statement", (unsigned int)offset, SPACES1000); break;
        case yscst_type: printf("%.*syscst_type", (unsigned int)offset, SPACES1000); break;
        case yscst_bool: printf("%.*syscst_bool", (unsigned int)offset, SPACES1000); break;
        case yscst_string: printf("%.*syscst_string", (unsigned int)offset, SPACES1000); break;
        case yscst_char: printf("%.*syscst_char", (unsigned int)offset, SPACES1000); break;
        case yscst_int8: printf("%.*syscst_int8", (unsigned int)offset, SPACES1000); break;
        case yscst_uint8: printf("%.*syscst_uint8", (unsigned int)offset, SPACES1000); break;
        case yscst_int16: printf("%.*syscst_int16", (unsigned int)offset, SPACES1000); break;
        case yscst_uint16: printf("%.*syscst_uint16", (unsigned int)offset, SPACES1000); break;
        case yscst_int32: printf("%.*syscst_int32", (unsigned int)offset, SPACES1000); break;
        case yscst_uint32: printf("%.*syscst_uint32", (unsigned int)offset, SPACES1000); break;
        case yscst_int64: printf("%.*syscst_int64", (unsigned int)offset, SPACES1000); break;
        case yscst_uint64: printf("%.*syscst_uint64", (unsigned int)offset, SPACES1000); break;
        case yscst_float: printf("%.*syscst_float", (unsigned int)offset, SPACES1000); break;
        case yscst_double: printf("%.*syscst_double", (unsigned int)offset, SPACES1000); break;
        case yscst_auto: printf("%.*syscst_auto", (unsigned int)offset, SPACES1000); break;
        case yscst_void: printf("%.*syscst_void", (unsigned int)offset, SPACES1000); break;
        case yscst_op_inc_r0: printf("%.*syscst_op_inc_r0", (unsigned int)offset, SPACES1000); break;
        case yscst_op_dec_r0: printf("%.*syscst_op_dec_r0", (unsigned int)offset, SPACES1000); break;
        case yscst_op_not_v1: printf("%.*syscst_op_not_v1", (unsigned int)offset, SPACES1000); break;
        case yscst_op_add_v2: printf("%.*syscst_op_add_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_add_r1: printf("%.*syscst_op_add_r1", (unsigned int)offset, SPACES1000); break;
        case yscst_op_sub_v2: printf("%.*syscst_op_sub_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_sub_r1: printf("%.*syscst_op_sub_r1", (unsigned int)offset, SPACES1000); break;
        case yscst_op_mul_v2: printf("%.*syscst_op_mul_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_mul_r1: printf("%.*syscst_op_mul_r1", (unsigned int)offset, SPACES1000); break;
        case yscst_op_div_v2: printf("%.*syscst_op_div_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_div_r1: printf("%.*syscst_op_div_r1", (unsigned int)offset, SPACES1000); break;
        case yscst_op_bit_inv_v2: printf("%.*syscst_op_bit_inv_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_bit_inv_r1: printf("%.*syscst_op_bit_inv_r1", (unsigned int)offset, SPACES1000); break;
        case yscst_op_bit_or_v2: printf("%.*syscst_op_bit_or_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_bit_or_r1: printf("%.*syscst_op_bit_or_r1", (unsigned int)offset, SPACES1000); break;
        case yscst_op_bit_xor_v2: printf("%.*syscst_op_bit_xor_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_bit_xor_r1: printf("%.*syscst_op_bit_xor_r1", (unsigned int)offset, SPACES1000); break;
        case yscst_op_bit_and_v2: printf("%.*syscst_op_bit_and_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_bit_and_r1: printf("%.*syscst_op_bit_and_r1", (unsigned int)offset, SPACES1000); break;
        case yscst_op_log_or_v2: printf("%.*syscst_op_log_or_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_log_and_v2: printf("%.*syscst_op_log_and_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_log_equal_v2: printf("%.*syscst_op_log_equal_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_log_notequal_v2: printf("%.*syscst_op_log_notequal_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_log_less_then_v2: printf("%.*syscst_op_log_less_then_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_log_greater_then_v2: printf("%.*syscst_op_log_greater_then_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_mod_v2: printf("%.*syscst_op_mod_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_lshift_v2: printf("%.*syscst_op_lshift_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_lshift_r1: printf("%.*syscst_op_lshift_r1", (unsigned int)offset, SPACES1000); break;
        case yscst_op_rshift_v2: printf("%.*syscst_op_rshift_v2", (unsigned int)offset, SPACES1000); break;
        case yscst_op_rshift_r1: printf("%.*syscst_op_rshift_r1", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_ternary: printf("%.*syscst_exp_ternary", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_log_or: printf("%.*syscst_exp_log_or", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_log_and: printf("%.*syscst_exp_log_and", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_bin_or: printf("%.*syscst_exp_bin_or", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_bin_and: printf("%.*syscst_exp_bin_and", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_bin_xor: printf("%.*syscst_exp_bin_xor", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_equal: printf("%.*syscst_exp_equal", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_notequal: printf("%.*syscst_exp_notequal", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_less: printf("%.*syscst_exp_less", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_less_equal: printf("%.*syscst_exp_less_equal", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_greater: printf("%.*syscst_exp_greater", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_greater_equal: printf("%.*syscst_exp_greater_equal", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_lshift: printf("%.*syscst_exp_lshift", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_rshift: printf("%.*syscst_exp_rshift", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_add: printf("%.*syscst_exp_add", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_sub: printf("%.*syscst_exp_sub", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_mul: printf("%.*syscst_exp_mul", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_div: printf("%.*syscst_exp_div", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_mod: printf("%.*syscst_exp_mod", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_pre_inc: printf("%.*syscst_exp_pre_inc", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_post_inc: printf("%.*syscst_exp_post_inc", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_pre_dec: printf("%.*syscst_exp_pre_dec", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_post_dec: printf("%.*syscst_exp_post_dec", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_is: printf("%.*syscst_exp_is", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_isnot: printf("%.*syscst_exp_isnot", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_log_not: printf("%.*syscst_exp_log_not", (unsigned int)offset, SPACES1000); break;
        case yscst_exp_invert: printf("%.*syscst_exp_invert", (unsigned int)offset, SPACES1000); break;
        case yscst_typeof: printf("%.*syscst_typeof", (unsigned int)offset, SPACES1000); break;
        case yscst_new: printf("%.*syscst_new", (unsigned int)offset, SPACES1000); break;
        case yscst_null: printf("%.*syscst_null", (unsigned int)offset, SPACES1000); break;
        case yscst_call: printf("%.*syscst_call", (unsigned int)offset, SPACES1000); break;
        case yscst_getvar: printf("%.*syscst_getvar", (unsigned int)offset, SPACES1000); break;
        case yscst_setto_exp: printf("%.*syscst_setto_exp", (unsigned int)offset, SPACES1000); break;
        case yscst_setto_auto: printf("%.*syscst_setto_auto", (unsigned int)offset, SPACES1000); break;
        case yscst_setto_type: printf("%.*syscst_setto_type", (unsigned int)offset, SPACES1000); break;
        case yscst_valexp: printf("%.*syscst_valexp", (unsigned int)offset, SPACES1000); break;
        case yscst_this: printf("%.*syscst_this", (unsigned int)offset, SPACES1000); break;
        case yscst_valexp_var: printf("%.*syscst_valexp_var", (unsigned int)offset, SPACES1000); break;
        case yscst_setvar: printf("%.*syscst_setvar", (unsigned int)offset, SPACES1000); break;
        case yscst_setvar_add: printf("%.*syscst_setvar_add", (unsigned int)offset, SPACES1000); break;
        case yscst_setvar_sub: printf("%.*syscst_setvar_sub", (unsigned int)offset, SPACES1000); break;
        case yscst_setvar_mul: printf("%.*syscst_setvar_mul", (unsigned int)offset, SPACES1000); break;
        case yscst_setvar_div: printf("%.*syscst_setvar_div", (unsigned int)offset, SPACES1000); break;
        case yscst_setvar_mod: printf("%.*syscst_setvar_mod", (unsigned int)offset, SPACES1000); break;
        case yscst_setvar_bin_or: printf("%.*syscst_setvar_bin_or", (unsigned int)offset, SPACES1000); break;
        case yscst_setvar_bin_and: printf("%.*syscst_setvar_bin_and", (unsigned int)offset, SPACES1000); break;
        case yscst_setvar_bin_xor: printf("%.*syscst_setvar_bin_xor", (unsigned int)offset, SPACES1000); break;
        case yscst_setvar_invert: printf("%.*syscst_setvar_invert", (unsigned int)offset, SPACES1000); break;
        case yscst_setvar_rshift: printf("%.*syscst_setvar_rshift", (unsigned int)offset, SPACES1000); break;
        case yscst_setvar_lshift: printf("%.*syscst_setvar_lshift", (unsigned int)offset, SPACES1000); break;
        case yscst_val_true: printf("%.*syscst_val_true", (unsigned int)offset, SPACES1000); break;
        case yscst_val_false: printf("%.*syscst_val_false", (unsigned int)offset, SPACES1000); break;
        case yscst_val_number: printf("%.*syscst_val_number", (unsigned int)offset, SPACES1000); break;
        case yscst_val_number_hex: printf("%.*syscst_val_number_hex", (unsigned int)offset, SPACES1000); break;
        case yscst_val_number_binary: printf("%.*syscst_val_number_binary", (unsigned int)offset, SPACES1000); break;
        case yscst_val_string: printf("%.*syscst_val_string", (unsigned int)offset, SPACES1000); break;
        case yscst_val_char: printf("%.*syscst_val_char", (unsigned int)offset, SPACES1000); break;
        case yscst_calllist: printf("%.*syscst_calllist", (unsigned int)offset, SPACES1000); break;
        case yscst_callwith: printf("%.*syscst_callwith", (unsigned int)offset, SPACES1000); break;
        case yscst_expressionlist: printf("%.*syscst_expressionlist", (unsigned int)offset, SPACES1000); break;
        case yscst_return: printf("%.*syscst_return", (unsigned int)offset, SPACES1000); break;
        case yscst_continue: printf("%.*syscst_continue", (unsigned int)offset, SPACES1000); break;
        case yscst_break: printf("%.*syscst_break", (unsigned int)offset, SPACES1000); break;
        case yscst_throw: printf("%.*syscst_throw", (unsigned int)offset, SPACES1000); break;
        case yscst_extern: printf("%.*syscst_extern", (unsigned int)offset, SPACES1000); break;
        case yscst_base: printf("%.*syscst_base", (unsigned int)offset, SPACES1000); break;
        default: printf("%.*sUNKNOWN", (unsigned int)offset, SPACES1000); break;

        }
        if (node.value)
        {
            printf("  (%s)", node.value);
        }
        printf("\n");
    for (i = 0; i < node.children_size; i++)
    {
        yaoosl_yycstnode_printf_helper(node.children[i], offset + 1);
    }
}
void yaoosl_yycstnode_printf(yaoosl_cstnode node)
{
    yaoosl_yycstnode_printf_helper(node, 0);
}
