/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>

#include "parser_runtime.h"

int yylex(void);
int yyerror(const char *s);
extern int yylineno;
extern FILE *yyin;

#line 82 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FUNCTION = 3,                   /* FUNCTION  */
  YYSYMBOL_WHEN = 4,                       /* WHEN  */
  YYSYMBOL_OTHERWISE = 5,                  /* OTHERWISE  */
  YYSYMBOL_LOOP = 6,                       /* LOOP  */
  YYSYMBOL_REPLY = 7,                      /* REPLY  */
  YYSYMBOL_STOP = 8,                       /* STOP  */
  YYSYMBOL_MOVEON = 9,                     /* MOVEON  */
  YYSYMBOL_TAKE = 10,                      /* TAKE  */
  YYSYMBOL_SHOW = 11,                      /* SHOW  */
  YYSYMBOL_TRUE = 12,                      /* TRUE  */
  YYSYMBOL_FALSE = 13,                     /* FALSE  */
  YYSYMBOL_INT_LITERAL = 14,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 15,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 16,            /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 17,                /* IDENTIFIER  */
  YYSYMBOL_INT_ID = 18,                    /* INT_ID  */
  YYSYMBOL_FLOAT_ID = 19,                  /* FLOAT_ID  */
  YYSYMBOL_STRING_ID = 20,                 /* STRING_ID  */
  YYSYMBOL_BOOL_ID = 21,                   /* BOOL_ID  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_MUL = 24,                       /* MUL  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_MOD = 26,                       /* MOD  */
  YYSYMBOL_ASSIGN = 27,                    /* ASSIGN  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NEQ = 29,                       /* NEQ  */
  YYSYMBOL_GT = 30,                        /* GT  */
  YYSYMBOL_LT = 31,                        /* LT  */
  YYSYMBOL_GTE = 32,                       /* GTE  */
  YYSYMBOL_LTE = 33,                       /* LTE  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_INC = 37,                       /* INC  */
  YYSYMBOL_DEC = 38,                       /* DEC  */
  YYSYMBOL_LPAREN = 39,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 40,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 41,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 42,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 43,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 44,                     /* COMMA  */
  YYSYMBOL_UMINUS = 45,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_stmt_list = 48,                 /* stmt_list  */
  YYSYMBOL_statement = 49,                 /* statement  */
  YYSYMBOL_simple_stmt = 50,               /* simple_stmt  */
  YYSYMBOL_name_token = 51,                /* name_token  */
  YYSYMBOL_literal = 52,                   /* literal  */
  YYSYMBOL_block = 53,                     /* block  */
  YYSYMBOL_declaration_stmt = 54,          /* declaration_stmt  */
  YYSYMBOL_declaration_core = 55,          /* declaration_core  */
  YYSYMBOL_assignment_stmt = 56,           /* assignment_stmt  */
  YYSYMBOL_assignment_core = 57,           /* assignment_core  */
  YYSYMBOL_show_stmt = 58,                 /* show_stmt  */
  YYSYMBOL_take_stmt = 59,                 /* take_stmt  */
  YYSYMBOL_if_stmt = 60,                   /* if_stmt  */
  YYSYMBOL_else_tail = 61,                 /* else_tail  */
  YYSYMBOL_loop_stmt = 62,                 /* loop_stmt  */
  YYSYMBOL_loop_init_opt = 63,             /* loop_init_opt  */
  YYSYMBOL_loop_update_opt = 64,           /* loop_update_opt  */
  YYSYMBOL_update_core = 65,               /* update_core  */
  YYSYMBOL_function_def = 66,              /* function_def  */
  YYSYMBOL_param_list_opt = 67,            /* param_list_opt  */
  YYSYMBOL_param_list = 68,                /* param_list  */
  YYSYMBOL_param_decl = 69,                /* param_decl  */
  YYSYMBOL_function_call_stmt = 70,        /* function_call_stmt  */
  YYSYMBOL_return_stmt = 71,               /* return_stmt  */
  YYSYMBOL_break_stmt = 72,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 73,             /* continue_stmt  */
  YYSYMBOL_arg_list_opt = 74,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 75,                  /* arg_list  */
  YYSYMBOL_function_call = 76,             /* function_call  */
  YYSYMBOL_var_ref = 77,                   /* var_ref  */
  YYSYMBOL_expr = 78                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   335

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    57,    58,    61,    61,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    77,    77,
      77,    77,    77,    80,    81,    82,    83,    84,    87,    89,
      92,    93,    94,    95,    96,    97,    98,    99,   102,   104,
     106,   108,   110,   113,   114,   115,   119,   120,   124,   124,
     124,   125,   125,   125,   128,   129,   133,   137,   137,   140,
     141,   145,   146,   147,   148,   151,   152,   153,   154,   156,
     156,   159,   160,   163,   164,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FUNCTION", "WHEN",
  "OTHERWISE", "LOOP", "REPLY", "STOP", "MOVEON", "TAKE", "SHOW", "TRUE",
  "FALSE", "INT_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "IDENTIFIER",
  "INT_ID", "FLOAT_ID", "STRING_ID", "BOOL_ID", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "ASSIGN", "EQ", "NEQ", "GT", "LT", "GTE", "LTE", "AND",
  "OR", "NOT", "INC", "DEC", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "SEMICOLON", "COMMA", "UMINUS", "$accept", "program", "stmt_list",
  "statement", "simple_stmt", "name_token", "literal", "block",
  "declaration_stmt", "declaration_core", "assignment_stmt",
  "assignment_core", "show_stmt", "take_stmt", "if_stmt", "else_tail",
  "loop_stmt", "loop_init_opt", "loop_update_opt", "update_core",
  "function_def", "param_list_opt", "param_list", "param_decl",
  "function_call_stmt", "return_stmt", "break_stmt", "continue_stmt",
  "arg_list_opt", "arg_list", "function_call", "var_ref", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-37)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -105,     7,   122,  -105,    -7,   -27,   -26,   133,   -28,   -23,
      -8,    -3,    -1,   -25,   -24,   -22,   -19,  -105,  -105,  -105,
    -105,  -105,  -105,   -11,  -105,    -4,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,    11,    15,    16,   133,   161,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   133,
     133,   133,  -105,  -105,  -105,   179,  -105,  -105,     8,   133,
     133,   133,   133,   133,   133,    82,  -105,  -105,  -105,   133,
      60,   211,  -105,  -105,    19,    15,   230,  -105,  -105,   249,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,  -105,  -105,    42,   268,    43,    40,   287,
     287,   287,   287,   287,  -105,   287,  -105,  -105,  -105,  -105,
      47,    50,  -105,    54,   133,    54,  -105,    26,    26,  -105,
    -105,  -105,    88,    88,    35,    35,    35,    35,   163,   301,
      53,    61,  -105,   133,    54,    60,    92,   195,  -105,  -105,
    -105,   287,  -105,  -105,     0,  -105,     8,  -105,  -105,  -105,
      65,  -105,   -21,    54,  -105,  -105,  -105
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,     4,     3,     5,
      74,     6,     7,     0,     8,     0,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     0,     0,     0,     0,    50,
      26,    27,    23,    24,    25,    19,    20,    21,    22,     0,
       0,     0,    75,    77,    76,     0,    67,    68,     0,     0,
      70,     0,     0,     0,     0,     0,    29,    38,    65,     0,
      58,     0,    48,    49,     0,    76,     0,    92,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    18,     0,     0,     0,    69,    72,
      31,    33,    35,    37,    28,    39,    61,    62,    63,    64,
       0,    57,    60,     0,     0,     0,    93,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,     0,    73,     0,     0,     0,    45,     0,    46,    41,
      40,    71,    56,    59,     0,    42,    53,    44,    43,    51,
       0,    52,     0,     0,    54,    55,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -105,  -105,    89,  -105,  -105,  -105,  -105,  -104,  -105,    68,
    -105,   -38,  -105,  -105,   -35,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,   -20,  -105,  -105,  -105,  -105,  -105,  -105,
      12,    -2,   -16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    18,    19,    20,    52,    21,    22,    23,
      24,    25,    26,    27,    28,   145,    29,    74,   150,   151,
      30,   110,   111,   112,    31,    32,    33,    34,    97,    98,
      53,    54,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    73,    61,    62,     5,    63,    69,     3,    64,   136,
      37,   138,    38,    39,    35,    56,   154,   155,   -30,   -32,
      57,   -34,    71,    76,   -36,    94,    45,    46,    47,    48,
     142,    58,    66,    77,    78,    79,    59,    75,    60,    67,
     147,    17,    69,    96,    99,   100,   101,   102,   103,   156,
      82,    83,    84,   105,    68,    70,    95,    80,    81,    82,
      83,    84,   114,    36,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    35,   106,   107,
     108,   109,   130,   132,   133,     4,     5,   134,     6,     7,
       8,     9,    10,    11,   135,    17,   139,   144,   137,    12,
      13,    14,    15,    16,   140,   153,    65,    72,   149,   148,
      80,    81,    82,    83,    84,   143,     0,   141,    87,    88,
      89,    90,     0,    17,   104,     4,     5,     0,     6,     7,
       8,     9,    10,    11,     0,     0,     0,     0,     0,    12,
      13,    14,    15,    16,   152,    40,    41,    42,    43,    44,
      12,    45,    46,    47,    48,     0,    49,     0,     0,     0,
       0,     0,     0,    17,     0,     0,     0,     0,     0,    50,
       0,     0,    51,    40,    41,    42,    43,    44,    12,    13,
      14,    15,    16,     0,    49,    80,    81,    82,    83,    84,
       0,    85,    86,    87,    88,    89,    90,    50,     0,     0,
      51,    80,    81,    82,    83,    84,     0,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,    80,    81,    82,
      83,    84,    93,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,    80,    81,    82,    83,    84,   146,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
       0,   113,    80,    81,    82,    83,    84,     0,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,     0,
     115,    80,    81,    82,    83,    84,     0,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,     0,   116,
      80,    81,    82,    83,    84,     0,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,     0,     0,   131,    80,
      81,    82,    83,    84,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    80,    81,    82,    83,    84,     0,    85,
      86,    87,    88,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
       2,    39,    27,    27,     4,    27,    27,     0,    27,   113,
      17,   115,    39,    39,     2,    43,    37,    38,    43,    43,
      43,    43,    38,    39,    43,    17,    18,    19,    20,    21,
     134,    39,    43,    49,    50,    51,    39,    39,    39,    43,
     144,    41,    27,    59,    60,    61,    62,    63,    64,   153,
      24,    25,    26,    69,    43,    39,    58,    22,    23,    24,
      25,    26,    43,    65,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    65,    18,    19,
      20,    21,    40,    40,    44,     3,     4,    40,     6,     7,
       8,     9,    10,    11,    44,    41,    43,     5,   114,    17,
      18,    19,    20,    21,    43,    40,    17,    39,   146,   144,
      22,    23,    24,    25,    26,   135,    -1,   133,    30,    31,
      32,    33,    -1,    41,    42,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,   146,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    39,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    36,    -1,    -1,
      39,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    22,    23,    24,
      25,    26,    43,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    22,    23,    24,    25,    26,    43,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    40,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      40,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    22,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    48,     0,     3,     4,     6,     7,     8,     9,
      10,    11,    17,    18,    19,    20,    21,    41,    49,    50,
      51,    53,    54,    55,    56,    57,    58,    59,    60,    62,
      66,    70,    71,    72,    73,    76,    77,    17,    39,    39,
      12,    13,    14,    15,    16,    18,    19,    20,    21,    23,
      36,    39,    52,    76,    77,    78,    43,    43,    39,    39,
      39,    27,    27,    27,    27,    48,    43,    43,    43,    27,
      39,    78,    55,    57,    63,    77,    78,    78,    78,    78,
      22,    23,    24,    25,    26,    28,    29,    30,    31,    32,
      33,    34,    35,    43,    17,    77,    78,    74,    75,    78,
      78,    78,    78,    78,    42,    78,    18,    19,    20,    21,
      67,    68,    69,    40,    43,    40,    40,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      40,    40,    40,    44,    40,    44,    53,    78,    53,    43,
      43,    78,    53,    69,     5,    61,    43,    53,    60,    57,
      64,    65,    77,    40,    37,    38,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      51,    51,    51,    52,    52,    52,    52,    52,    53,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    57,
      58,    59,    60,    61,    61,    61,    62,    62,    63,    63,
      63,    64,    64,    64,    65,    65,    66,    67,    67,    68,
      68,    69,    69,    69,    69,    70,    71,    72,    73,    74,
      74,    75,    75,    76,    77,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     3,
       5,     5,     6,     2,     2,     0,     5,     9,     1,     1,
       0,     1,     1,     0,     2,     2,     6,     1,     0,     3,
       1,     1,     1,     1,     1,     2,     3,     2,     2,     1,
       0,     3,     1,     4,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  switch (yyn)
    {
  case 2: /* program: stmt_list  */
#line 53 "parser.y"
                { root = make_block((yyvsp[0].ptr)); (yyval.ptr) = root; }
#line 1294 "parser.tab.c"
    break;

  case 3: /* stmt_list: stmt_list statement  */
#line 57 "parser.y"
                          { (yyval.ptr) = append_statement((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 1300 "parser.tab.c"
    break;

  case 4: /* stmt_list: %empty  */
#line 58 "parser.y"
      { (yyval.ptr) = NULL; }
#line 1306 "parser.tab.c"
    break;

  case 23: /* literal: INT_LITERAL  */
#line 80 "parser.y"
                  { (yyval.ptr) = make_literal_node(make_int_value((long long)(yyvsp[0].num))); }
#line 1312 "parser.tab.c"
    break;

  case 24: /* literal: FLOAT_LITERAL  */
#line 81 "parser.y"
                    { (yyval.ptr) = make_literal_node(make_float_value((yyvsp[0].num))); }
#line 1318 "parser.tab.c"
    break;

  case 25: /* literal: STRING_LITERAL  */
#line 82 "parser.y"
                     { (yyval.ptr) = make_string_literal_node((yyvsp[0].str)); }
#line 1324 "parser.tab.c"
    break;

  case 26: /* literal: TRUE  */
#line 83 "parser.y"
           { (yyval.ptr) = make_literal_node(make_bool_value(1)); }
#line 1330 "parser.tab.c"
    break;

  case 27: /* literal: FALSE  */
#line 84 "parser.y"
            { (yyval.ptr) = make_literal_node(make_bool_value(0)); }
#line 1336 "parser.tab.c"
    break;

  case 28: /* block: LBRACE stmt_list RBRACE  */
#line 87 "parser.y"
                                { (yyval.ptr) = make_block((yyvsp[-1].ptr)); }
#line 1342 "parser.tab.c"
    break;

  case 29: /* declaration_stmt: declaration_core SEMICOLON  */
#line 89 "parser.y"
                                              { (yyval.ptr) = (yyvsp[-1].ptr); }
#line 1348 "parser.tab.c"
    break;

  case 30: /* declaration_core: INT_ID  */
#line 92 "parser.y"
             { (yyval.ptr) = make_decl_from_raw((yyvsp[0].str), TYPE_INT, NULL); }
#line 1354 "parser.tab.c"
    break;

  case 31: /* declaration_core: INT_ID ASSIGN expr  */
#line 93 "parser.y"
                         { (yyval.ptr) = make_decl_from_raw((yyvsp[-2].str), TYPE_INT, (yyvsp[0].ptr)); }
#line 1360 "parser.tab.c"
    break;

  case 32: /* declaration_core: FLOAT_ID  */
#line 94 "parser.y"
               { (yyval.ptr) = make_decl_from_raw((yyvsp[0].str), TYPE_FLOAT, NULL); }
#line 1366 "parser.tab.c"
    break;

  case 33: /* declaration_core: FLOAT_ID ASSIGN expr  */
#line 95 "parser.y"
                           { (yyval.ptr) = make_decl_from_raw((yyvsp[-2].str), TYPE_FLOAT, (yyvsp[0].ptr)); }
#line 1372 "parser.tab.c"
    break;

  case 34: /* declaration_core: STRING_ID  */
#line 96 "parser.y"
                { (yyval.ptr) = make_decl_from_raw((yyvsp[0].str), TYPE_STRING, NULL); }
#line 1378 "parser.tab.c"
    break;

  case 35: /* declaration_core: STRING_ID ASSIGN expr  */
#line 97 "parser.y"
                            { (yyval.ptr) = make_decl_from_raw((yyvsp[-2].str), TYPE_STRING, (yyvsp[0].ptr)); }
#line 1384 "parser.tab.c"
    break;

  case 36: /* declaration_core: BOOL_ID  */
#line 98 "parser.y"
              { (yyval.ptr) = make_decl_from_raw((yyvsp[0].str), TYPE_BOOL, NULL); }
#line 1390 "parser.tab.c"
    break;

  case 37: /* declaration_core: BOOL_ID ASSIGN expr  */
#line 99 "parser.y"
                          { (yyval.ptr) = make_decl_from_raw((yyvsp[-2].str), TYPE_BOOL, (yyvsp[0].ptr)); }
#line 1396 "parser.tab.c"
    break;

  case 38: /* assignment_stmt: assignment_core SEMICOLON  */
#line 102 "parser.y"
                                            { (yyval.ptr) = (yyvsp[-1].ptr); }
#line 1402 "parser.tab.c"
    break;

  case 39: /* assignment_core: var_ref ASSIGN expr  */
#line 104 "parser.y"
                                      { (yyval.ptr) = make_assign_node((yyvsp[-2].str), (yyvsp[0].ptr)); }
#line 1408 "parser.tab.c"
    break;

  case 40: /* show_stmt: SHOW LPAREN expr RPAREN SEMICOLON  */
#line 106 "parser.y"
                                              { (yyval.ptr) = make_show_node((yyvsp[-2].ptr)); }
#line 1414 "parser.tab.c"
    break;

  case 41: /* take_stmt: TAKE LPAREN var_ref RPAREN SEMICOLON  */
#line 108 "parser.y"
                                                 { (yyval.ptr) = make_take_node((yyvsp[-2].str)); }
#line 1420 "parser.tab.c"
    break;

  case 42: /* if_stmt: WHEN LPAREN expr RPAREN block else_tail  */
#line 110 "parser.y"
                                                  { (yyval.ptr) = make_if_node((yyvsp[-3].ptr), (yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 1426 "parser.tab.c"
    break;

  case 43: /* else_tail: OTHERWISE if_stmt  */
#line 113 "parser.y"
                        { (yyval.ptr) = (yyvsp[0].ptr); }
#line 1432 "parser.tab.c"
    break;

  case 44: /* else_tail: OTHERWISE block  */
#line 114 "parser.y"
                      { (yyval.ptr) = (yyvsp[0].ptr); }
#line 1438 "parser.tab.c"
    break;

  case 45: /* else_tail: %empty  */
#line 115 "parser.y"
      { (yyval.ptr) = NULL; }
#line 1444 "parser.tab.c"
    break;

  case 46: /* loop_stmt: LOOP LPAREN expr RPAREN block  */
#line 119 "parser.y"
                                    { (yyval.ptr) = make_while_node((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1450 "parser.tab.c"
    break;

  case 47: /* loop_stmt: LOOP LPAREN loop_init_opt SEMICOLON expr SEMICOLON loop_update_opt RPAREN block  */
#line 121 "parser.y"
        { (yyval.ptr) = make_for_node((yyvsp[-6].ptr), (yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1456 "parser.tab.c"
    break;

  case 50: /* loop_init_opt: %empty  */
#line 124 "parser.y"
                                                     { (yyval.ptr) = NULL; }
#line 1462 "parser.tab.c"
    break;

  case 53: /* loop_update_opt: %empty  */
#line 125 "parser.y"
                                                  { (yyval.ptr) = NULL; }
#line 1468 "parser.tab.c"
    break;

  case 54: /* update_core: var_ref INC  */
#line 128 "parser.y"
                  { (yyval.ptr) = make_update_node((yyvsp[-1].str), OP_INC); }
#line 1474 "parser.tab.c"
    break;

  case 55: /* update_core: var_ref DEC  */
#line 129 "parser.y"
                  { (yyval.ptr) = make_update_node((yyvsp[-1].str), OP_DEC); }
#line 1480 "parser.tab.c"
    break;

  case 56: /* function_def: FUNCTION IDENTIFIER LPAREN param_list_opt RPAREN block  */
#line 134 "parser.y"
        { (yyval.ptr) = make_function_def_node((yyvsp[-4].str), (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1486 "parser.tab.c"
    break;

  case 58: /* param_list_opt: %empty  */
#line 137 "parser.y"
                              { (yyval.ptr) = NULL; }
#line 1492 "parser.tab.c"
    break;

  case 59: /* param_list: param_list COMMA param_decl  */
#line 140 "parser.y"
                                  { (yyval.ptr) = append_param((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1498 "parser.tab.c"
    break;

  case 60: /* param_list: param_decl  */
#line 141 "parser.y"
                 { (yyval.ptr) = (yyvsp[0].ptr); }
#line 1504 "parser.tab.c"
    break;

  case 61: /* param_decl: INT_ID  */
#line 145 "parser.y"
             { (yyval.ptr) = make_param_from_raw((yyvsp[0].str), TYPE_INT); }
#line 1510 "parser.tab.c"
    break;

  case 62: /* param_decl: FLOAT_ID  */
#line 146 "parser.y"
               { (yyval.ptr) = make_param_from_raw((yyvsp[0].str), TYPE_FLOAT); }
#line 1516 "parser.tab.c"
    break;

  case 63: /* param_decl: STRING_ID  */
#line 147 "parser.y"
                { (yyval.ptr) = make_param_from_raw((yyvsp[0].str), TYPE_STRING); }
#line 1522 "parser.tab.c"
    break;

  case 64: /* param_decl: BOOL_ID  */
#line 148 "parser.y"
              { (yyval.ptr) = make_param_from_raw((yyvsp[0].str), TYPE_BOOL); }
#line 1528 "parser.tab.c"
    break;

  case 65: /* function_call_stmt: function_call SEMICOLON  */
#line 151 "parser.y"
                                             { (yyval.ptr) = make_expr_stmt_node((yyvsp[-1].ptr)); }
#line 1534 "parser.tab.c"
    break;

  case 66: /* return_stmt: REPLY expr SEMICOLON  */
#line 152 "parser.y"
                                   { (yyval.ptr) = make_return_node((yyvsp[-1].ptr)); }
#line 1540 "parser.tab.c"
    break;

  case 67: /* break_stmt: STOP SEMICOLON  */
#line 153 "parser.y"
                            { (yyval.ptr) = make_flow_node(NODE_BREAK); }
#line 1546 "parser.tab.c"
    break;

  case 68: /* continue_stmt: MOVEON SEMICOLON  */
#line 154 "parser.y"
                                 { (yyval.ptr) = make_flow_node(NODE_CONTINUE); }
#line 1552 "parser.tab.c"
    break;

  case 70: /* arg_list_opt: %empty  */
#line 156 "parser.y"
                          { (yyval.ptr) = NULL; }
#line 1558 "parser.tab.c"
    break;

  case 71: /* arg_list: arg_list COMMA expr  */
#line 159 "parser.y"
                          { (yyval.ptr) = append_arg((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1564 "parser.tab.c"
    break;

  case 72: /* arg_list: expr  */
#line 160 "parser.y"
           { (yyval.ptr) = make_arg((yyvsp[0].ptr)); }
#line 1570 "parser.tab.c"
    break;

  case 73: /* function_call: IDENTIFIER LPAREN arg_list_opt RPAREN  */
#line 163 "parser.y"
                                                      { (yyval.ptr) = make_function_call_node((yyvsp[-3].str), (yyvsp[-1].ptr)); }
#line 1576 "parser.tab.c"
    break;

  case 74: /* var_ref: name_token  */
#line 164 "parser.y"
                     { (yyval.str) = normalize_name_take((yyvsp[0].str)); }
#line 1582 "parser.tab.c"
    break;

  case 76: /* expr: var_ref  */
#line 168 "parser.y"
              { (yyval.ptr) = make_var_node((yyvsp[0].str)); }
#line 1588 "parser.tab.c"
    break;

  case 77: /* expr: function_call  */
#line 169 "parser.y"
                    { (yyval.ptr) = (yyvsp[0].ptr); }
#line 1594 "parser.tab.c"
    break;

  case 78: /* expr: expr PLUS expr  */
#line 170 "parser.y"
                     { (yyval.ptr) = make_binary_node(OP_ADD, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1600 "parser.tab.c"
    break;

  case 79: /* expr: expr MINUS expr  */
#line 171 "parser.y"
                      { (yyval.ptr) = make_binary_node(OP_SUB, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1606 "parser.tab.c"
    break;

  case 80: /* expr: expr MUL expr  */
#line 172 "parser.y"
                    { (yyval.ptr) = make_binary_node(OP_MUL, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1612 "parser.tab.c"
    break;

  case 81: /* expr: expr DIV expr  */
#line 173 "parser.y"
                    { (yyval.ptr) = make_binary_node(OP_DIV, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1618 "parser.tab.c"
    break;

  case 82: /* expr: expr MOD expr  */
#line 174 "parser.y"
                    { (yyval.ptr) = make_binary_node(OP_MOD, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1624 "parser.tab.c"
    break;

  case 83: /* expr: expr EQ expr  */
#line 175 "parser.y"
                   { (yyval.ptr) = make_binary_node(OP_EQ, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1630 "parser.tab.c"
    break;

  case 84: /* expr: expr NEQ expr  */
#line 176 "parser.y"
                    { (yyval.ptr) = make_binary_node(OP_NEQ, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1636 "parser.tab.c"
    break;

  case 85: /* expr: expr GT expr  */
#line 177 "parser.y"
                   { (yyval.ptr) = make_binary_node(OP_GT, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1642 "parser.tab.c"
    break;

  case 86: /* expr: expr LT expr  */
#line 178 "parser.y"
                   { (yyval.ptr) = make_binary_node(OP_LT, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1648 "parser.tab.c"
    break;

  case 87: /* expr: expr GTE expr  */
#line 179 "parser.y"
                    { (yyval.ptr) = make_binary_node(OP_GTE, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1654 "parser.tab.c"
    break;

  case 88: /* expr: expr LTE expr  */
#line 180 "parser.y"
                    { (yyval.ptr) = make_binary_node(OP_LTE, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1660 "parser.tab.c"
    break;

  case 89: /* expr: expr AND expr  */
#line 181 "parser.y"
                    { (yyval.ptr) = make_binary_node(OP_AND, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1666 "parser.tab.c"
    break;

  case 90: /* expr: expr OR expr  */
#line 182 "parser.y"
                   { (yyval.ptr) = make_binary_node(OP_OR, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1672 "parser.tab.c"
    break;

  case 91: /* expr: NOT expr  */
#line 183 "parser.y"
               { (yyval.ptr) = make_unary_node(OP_NOT, (yyvsp[0].ptr)); }
#line 1678 "parser.tab.c"
    break;

  case 92: /* expr: MINUS expr  */
#line 184 "parser.y"
                              { (yyval.ptr) = make_unary_node(OP_NEG, (yyvsp[0].ptr)); }
#line 1684 "parser.tab.c"
    break;

  case 93: /* expr: LPAREN expr RPAREN  */
#line 185 "parser.y"
                         { (yyval.ptr) = (yyvsp[-1].ptr); }
#line 1690 "parser.tab.c"
    break;


#line 1694 "parser.tab.c"

      default: break;
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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 188 "parser.y"


int main(void)
{
    int choice;
    char filename[256];

    printf("Mini Compiler\n");
    printf("1) Type code\n");
    printf("2) Read file\n");
    printf("Choose: ");

    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Invalid choice\n");
        return 1;
    }
    getchar();

    if (choice == 2) {
        printf("File name: ");
        if (scanf("%255s", filename) != 1) {
            fprintf(stderr, "Invalid file name\n");
            return 1;
        }
        getchar();

        yyin = fopen(filename, "r");
        if (yyin == NULL) {
            fprintf(stderr, "Cannot open file\n");
            return 1;
        }

        outFile = fopen("output.txt", "w");
        if (outFile == NULL) {
            fclose(yyin);
            fprintf(stderr, "Cannot open output.txt\n");
            return 1;
        }
    } else {
        yyin = stdin;
        outFile = stdout;
    }

    runtime_init();
    yyparse();
    runtime_execute_root();

    if (choice == 2) {
        fclose(yyin);
        fclose(outFile);
        printf("Output saved in output.txt\n");
    }

    return runtime_has_errors() ? 1 : 0;
}

int yyerror(const char *s)
{
    FILE *target = outFile ? outFile : stderr;
    fprintf(target, "Syntax Error at line %d: %s\n", yylineno, s);
    return 0;
}
