/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "main.y"

    #include"common.h"
    extern TreeNode * root;
    int yylex();
    int yyerror( char const * );
    extern int lineno;
    extern symbol_table SymbolsTable;

#line 79 "main.tab.cc"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_MAIN_TAB_HH_INCLUDED
# define YY_YY_MAIN_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    INTEGER = 259,
    ConstStr = 260,
    ConstChar = 261,
    IF = 262,
    ELSE = 263,
    WHILE = 264,
    FOR = 265,
    SWITCH = 266,
    CASE = 267,
    MAIN = 268,
    CONTINUS = 269,
    BREAK = 270,
    RETURN = 271,
    INT = 272,
    VOID = 273,
    CHAR = 274,
    STRING = 275,
    BOOL = 276,
    CONST = 277,
    LPAREN = 278,
    RPAREN = 279,
    LBRACK = 280,
    RBRACK = 281,
    LBRACE = 282,
    RBRACE = 283,
    SEMICOLON = 284,
    COMMA = 285,
    DOT = 286,
    COLON = 287,
    POT = 288,
    TRUE = 289,
    FALSE = 290,
    ASSIGN = 291,
    AASSIGN = 292,
    SASSIGN = 293,
    MASSIGN = 294,
    ADD = 295,
    SUB = 296,
    MUL = 297,
    DIV = 298,
    MOD = 299,
    EQUAL = 300,
    NOTEQUAL = 301,
    GT = 302,
    GTE = 303,
    LT = 304,
    LTE = 305,
    LAND = 306,
    LOR = 307,
    NOT = 308,
    PRINTF = 309,
    SCANF = 310,
    INC = 311,
    DEC = 312,
    UMINUS = 313,
    ADDRO = 314,
    SADD = 315,
    LOWER_THEN_ELSE = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MAIN_TAB_HH_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   340

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

#define YYUNDEFTOK  2
#define YYMAXUTOK   316


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    37,    37,    40,    41,    44,    45,    46,    47,    48,
      49,    52,    60,    67,    75,    85,    94,   103,   111,   121,
     124,   148,   151,   157,   162,   163,   166,   170,   173,   181,
     189,   190,   191,   192,   199,   206,   213,   220,   227,   234,
     240,   247,   254,   257,   263,   264,   265,   266,   267,   274,
     281,   288,   295,   302,   309,   315,   321,   327,   333,   339,
     346,   353,   360,   367,   370,   376,   382,   388,   394
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTEGER", "ConstStr", "ConstChar",
  "IF", "ELSE", "WHILE", "FOR", "SWITCH", "CASE", "MAIN", "CONTINUS",
  "BREAK", "RETURN", "INT", "VOID", "CHAR", "STRING", "BOOL", "CONST",
  "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "SEMICOLON",
  "COMMA", "DOT", "COLON", "POT", "TRUE", "FALSE", "ASSIGN", "AASSIGN",
  "SASSIGN", "MASSIGN", "ADD", "SUB", "MUL", "DIV", "MOD", "EQUAL",
  "NOTEQUAL", "GT", "GTE", "LT", "LTE", "LAND", "LOR", "NOT", "PRINTF",
  "SCANF", "INC", "DEC", "UMINUS", "ADDRO", "SADD", "LOWER_THEN_ELSE",
  "$accept", "program", "statements", "statement", "compound_stmt",
  "if_else", "while", "for", "for_statment", "bool_statment", "declare",
  "instruction", "id_list", "printf", "scanf", "bool_expr", "expr", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-44)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     165,    53,   -38,   -28,   -38,   -18,   -18,     4,    10,    14,
      23,   -38,   -38,   -38,    14,    14,    14,     6,    18,    40,
      46,   108,   -38,   -38,   -38,   -38,   -38,   -38,    34,    36,
      93,    14,    14,    14,    14,    14,   -38,   -38,    14,   207,
      25,    25,     7,   -38,   160,    49,   239,   -38,   -38,    14,
      14,   -38,   -38,   -38,   -38,   -38,   -38,    14,    14,    14,
      14,    14,    47,    55,    55,    55,    55,    55,    57,   207,
     -38,   -38,   193,    16,   290,   165,    80,   -38,   -38,    83,
     233,   285,   -38,    92,   -38,   247,   280,   -36,   -36,   -38,
     -38,   -38,   -38,    14,    27,   253,   -38,   -38,   193,   193,
      14,    14,    14,    14,    14,    14,   136,    -4,    25,    -7,
     233,    25,   -38,   -38,    55,   -38,    29,    29,    55,    55,
      55,    55,    55,    55,   -38,   -38,   -38,   -38,    14,    33,
     -38,    55,    14,    55
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      64,    44,    45,    46,    47,     0,     0,     0,     0,    64,
      65,    66,    67,    68,    64,    64,    64,     0,     0,     0,
       0,    64,     3,     7,     8,     9,     5,     6,     0,     0,
       0,    64,    64,    64,    64,    64,    57,    58,    64,    64,
       0,     0,    64,    23,     0,     0,     0,    54,    55,    64,
      64,    56,     1,     4,    24,    25,    21,    64,    64,    64,
      64,    64,     0,    27,    59,    60,    62,    61,    48,    64,
      30,    31,    64,     0,    32,    64,    12,    15,    65,     0,
      64,     0,    22,     0,    63,     0,     0,    49,    50,    51,
      52,    53,    20,    64,     0,    32,    39,    19,    64,    64,
      64,    64,    64,    64,    64,    64,    64,     0,     0,     0,
      64,     0,    28,    29,    26,    42,    40,    41,    33,    38,
      34,    35,    36,    37,    11,    13,    14,    16,    64,     0,
      10,    17,    64,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,    44,   -20,   -37,    13,   -38,   -38,   -38,   115,
      88,   -38,   100,   -38,   -38,   -16,     0,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    20,    21,    22,    76,    23,    24,    25,    79,    40,
      26,    27,    62,    28,    29,    73,    74,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    53,    38,     5,    77,    39,    59,    60,    61,    44,
       1,     2,     3,     4,    46,    47,    48,     1,     2,     3,
       4,    30,   128,    75,    78,    11,    12,    42,    13,    49,
      14,    63,    64,    65,    66,    67,    45,    14,    63,    43,
      97,    50,    81,    51,    98,    99,    52,    15,    16,    85,
      86,   115,    75,    94,    15,    16,    96,    87,    88,    89,
      90,    91,   132,    54,   109,    55,    19,    98,    99,    95,
     125,   127,    83,    19,   130,    30,    92,    93,    98,    99,
      98,    99,   116,   117,    98,    99,    53,    93,   107,    32,
      33,    34,    35,   114,   129,    57,    58,    59,    60,    61,
     118,   119,   120,   121,   122,   123,    30,   108,    -2,    36,
      37,     1,     2,     3,     4,     5,   111,     6,     7,   106,
     126,    41,    56,     8,     9,    10,    11,    12,   131,    13,
      80,    14,   133,    57,    58,    59,    60,    61,    68,     1,
       2,     3,     4,     5,     0,     6,     7,     0,    15,    16,
       0,     8,     9,    10,    11,    12,     0,    13,     0,    14,
       0,     0,    17,    18,   124,     0,     0,    19,     1,     2,
       3,     4,     5,     0,     6,     7,    15,    16,     0,     0,
       8,     9,    10,    11,    12,     0,    13,     0,    14,    82,
      17,    18,     0,     0,     0,    19,     1,     2,     3,     4,
      57,    58,    59,    60,    61,    15,    16,     0,     0,     0,
       1,     2,     3,     4,     0,     0,    69,   -43,     0,    17,
      18,     0,   -43,     0,    19,     0,     0,    70,    71,     0,
      69,   -43,     0,    15,    16,     0,     1,     2,     3,     4,
       0,    70,    71,     0,   -43,   -43,    72,    15,    16,     0,
       0,     0,    19,     0,     0,     0,    69,     0,   -43,   -43,
      72,     0,   -43,    84,     0,     0,    19,    70,    71,     0,
       0,   112,     0,    15,    16,     0,     0,    84,     0,    57,
      58,    59,    60,    61,   -43,   -43,    72,    57,    58,    59,
      60,    61,    19,    57,    58,    59,    60,    61,   100,   101,
     102,   103,   104,   105,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    57,    58,    59,    60,    61,
      57,    58,    59,    60,    61,   100,   101,   102,   103,   104,
     105
};

static const yytype_int16 yycheck[] =
{
       0,    21,    30,     7,    41,    23,    42,    43,    44,     9,
       3,     4,     5,     6,    14,    15,    16,     3,     4,     5,
       6,    21,    29,    27,    17,    18,    19,    23,    21,    23,
      23,    31,    32,    33,    34,    35,    13,    23,    38,    29,
      24,    23,    42,     3,    51,    52,     0,    40,    41,    49,
      50,    24,    27,    69,    40,    41,    72,    57,    58,    59,
      60,    61,    29,    29,    80,    29,    59,    51,    52,    69,
     107,   108,    23,    59,   111,    75,    29,    30,    51,    52,
      51,    52,    98,    99,    51,    52,   106,    30,     8,    36,
      37,    38,    39,    93,   110,    40,    41,    42,    43,    44,
     100,   101,   102,   103,   104,   105,   106,    24,     0,    56,
      57,     3,     4,     5,     6,     7,    24,     9,    10,    75,
     107,     6,    29,    15,    16,    17,    18,    19,   128,    21,
      42,    23,   132,    40,    41,    42,    43,    44,    38,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    40,    41,
      -1,    15,    16,    17,    18,    19,    -1,    21,    -1,    23,
      -1,    -1,    54,    55,    28,    -1,    -1,    59,     3,     4,
       5,     6,     7,    -1,     9,    10,    40,    41,    -1,    -1,
      15,    16,    17,    18,    19,    -1,    21,    -1,    23,    29,
      54,    55,    -1,    -1,    -1,    59,     3,     4,     5,     6,
      40,    41,    42,    43,    44,    40,    41,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,    23,    24,    -1,    54,
      55,    -1,    29,    -1,    59,    -1,    -1,    34,    35,    -1,
      23,    24,    -1,    40,    41,    -1,     3,     4,     5,     6,
      -1,    34,    35,    -1,    51,    52,    53,    40,    41,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    23,    -1,    51,    52,
      53,    -1,    29,    24,    -1,    -1,    59,    34,    35,    -1,
      -1,    24,    -1,    40,    41,    -1,    -1,    24,    -1,    40,
      41,    42,    43,    44,    51,    52,    53,    40,    41,    42,
      43,    44,    59,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    40,    41,    42,    43,    44,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    15,    16,
      17,    18,    19,    21,    23,    40,    41,    54,    55,    59,
      63,    64,    65,    67,    68,    69,    72,    73,    75,    76,
      78,    79,    36,    37,    38,    39,    56,    57,    30,    23,
      71,    71,    23,    29,    78,    13,    78,    78,    78,    23,
      23,     3,     0,    65,    29,    29,    29,    40,    41,    42,
      43,    44,    74,    78,    78,    78,    78,    78,    74,    23,
      34,    35,    53,    77,    78,    27,    66,    66,    17,    70,
      72,    78,    29,    23,    24,    78,    78,    78,    78,    78,
      78,    78,    29,    30,    77,    78,    77,    24,    51,    52,
      45,    46,    47,    48,    49,    50,    64,     8,    24,    77,
      29,    24,    24,    24,    78,    24,    77,    77,    78,    78,
      78,    78,    78,    78,    28,    66,    67,    66,    29,    77,
      66,    78,    29,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    65,    65,    65,
      65,    66,    67,    67,    67,    68,    69,    70,    70,    71,
      72,    73,    73,    73,    73,    73,    74,    74,    75,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    79,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       5,     3,     3,     5,     5,     3,     5,     4,     5,     3,
       3,     2,     3,     2,     2,     2,     3,     1,     4,     4,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     0,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     0,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
  case 2:
#line 37 "main.y"
                 {root=new TreeNode(NODE_PROG, yyvsp[0]->line);root->addChild(yyvsp[0]);}
#line 1498 "main.tab.cc"
    break;

  case 3:
#line 40 "main.y"
                {yyval=yyvsp[0];}
#line 1504 "main.tab.cc"
    break;

  case 4:
#line 41 "main.y"
                          {yyval=yyvsp[-1];yyval->addSibling(yyvsp[0]);}
#line 1510 "main.tab.cc"
    break;

  case 5:
#line 44 "main.y"
              {yyval=yyvsp[0];}
#line 1516 "main.tab.cc"
    break;

  case 6:
#line 45 "main.y"
                  {yyval=yyvsp[0];}
#line 1522 "main.tab.cc"
    break;

  case 7:
#line 46 "main.y"
              {yyval=yyvsp[0];}
#line 1528 "main.tab.cc"
    break;

  case 8:
#line 47 "main.y"
            {yyval=yyvsp[0];}
#line 1534 "main.tab.cc"
    break;

  case 9:
#line 48 "main.y"
          {yyval=yyvsp[0];}
#line 1540 "main.tab.cc"
    break;

  case 10:
#line 49 "main.y"
                                           {yyval=yyvsp[0];}
#line 1546 "main.tab.cc"
    break;

  case 11:
#line 52 "main.y"
                               {
        TreeNode *node=new TreeNode(NODE_STMT, yyvsp[-1]->line);
        node->stmtType=STMT_COMPOUND;
        node->addChild(yyvsp[-1]);
        yyval=node;
    }
#line 1557 "main.tab.cc"
    break;

  case 12:
#line 60 "main.y"
                                                           {
        TreeNode *node=new TreeNode(NODE_STMT, yyvsp[-1]->line);
        node->stmtType=STMT_IF;
        node->addChild(yyvsp[-1]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1569 "main.tab.cc"
    break;

  case 13:
#line 67 "main.y"
                                                        {
        TreeNode *node=new TreeNode(NODE_STMT, yyvsp[-3]->line);
        node->stmtType=STMT_IF;
        node->addChild(yyvsp[-3]);
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1582 "main.tab.cc"
    break;

  case 14:
#line 75 "main.y"
                                                  {
        TreeNode *node=new TreeNode(NODE_STMT, yyvsp[-3]->line);
        node->stmtType=STMT_IF;
        node->addChild(yyvsp[-3]);
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1595 "main.tab.cc"
    break;

  case 15:
#line 85 "main.y"
                                        {
        TreeNode *node=new TreeNode(NODE_STMT, yyvsp[-1]->line);
        node->stmtType=STMT_WHILE;
        node->addChild(yyvsp[-1]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1607 "main.tab.cc"
    break;

  case 16:
#line 94 "main.y"
                                                   {
        TreeNode *node=new TreeNode(NODE_STMT, yyvsp[-2]->line);
        node->stmtType=STMT_FOR;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1619 "main.tab.cc"
    break;

  case 17:
#line 103 "main.y"
                                       {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_FORCONDITION;
        node->addChild(yyvsp[-3]);
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1632 "main.tab.cc"
    break;

  case 18:
#line 111 "main.y"
                                             {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_FORCONDITION;
            node->addChild(yyvsp[-4]);
            node->addChild(yyvsp[-2]);
            node->addChild(yyvsp[0]);
            yyval=node;
    }
#line 1645 "main.tab.cc"
    break;

  case 19:
#line 121 "main.y"
                              {yyval=yyvsp[-1];}
#line 1651 "main.tab.cc"
    break;

  case 20:
#line 124 "main.y"
                             {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_DECL;
        TreeNode *t=yyvsp[-1];
        while(t){
            if(t->nodeType==NODE_EXPR){// 声明变量且带有赋值表达式
                t->child[0]->varType=yyvsp[-2]->varType;
                t->child[0]->type=yyvsp[-2]->type;
                if(SymbolsTable.lookup(t->child[0]->var_name)==-1)
                    SymbolsTable.insert(t->child[0]->var_name, t->child[0]->varType);
            }else{// 声明变量不带有赋值表达式
                t->varType=yyvsp[-2]->varType;
                t->type=yyvsp[-2]->type;
                if(SymbolsTable.lookup(t->var_name)==-1)
                    SymbolsTable.insert(t->var_name, t->varType);
            }
            t=t->sibling;
        }
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[-1]);
        yyval=node;
    }
#line 1678 "main.tab.cc"
    break;

  case 21:
#line 148 "main.y"
                     {
        yyval=yyvsp[-1];  
    }
#line 1686 "main.tab.cc"
    break;

  case 22:
#line 151 "main.y"
                            {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_RETURN;
        node->addChild(yyvsp[-1]);
        yyval=node;
    }
#line 1697 "main.tab.cc"
    break;

  case 23:
#line 157 "main.y"
                      {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_BREAK;
        yyval=node;
    }
#line 1707 "main.tab.cc"
    break;

  case 24:
#line 162 "main.y"
                       {yyval=yyvsp[-1];}
#line 1713 "main.tab.cc"
    break;

  case 25:
#line 163 "main.y"
                      {yyval=yyvsp[-1];}
#line 1719 "main.tab.cc"
    break;

  case 26:
#line 166 "main.y"
                         {
        yyval=yyvsp[-2];
        yyval->addSibling(yyvsp[0]);
    }
#line 1728 "main.tab.cc"
    break;

  case 27:
#line 170 "main.y"
           {yyval=yyvsp[0];}
#line 1734 "main.tab.cc"
    break;

  case 28:
#line 173 "main.y"
                                {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_PRINTF;
        node->addChild(yyvsp[-1]);
        yyval=node;
    }
#line 1745 "main.tab.cc"
    break;

  case 29:
#line 181 "main.y"
                               {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_SCANF;
        node->addChild(yyvsp[-1]);
        yyval=node;
    }
#line 1756 "main.tab.cc"
    break;

  case 30:
#line 189 "main.y"
           {yyval=yyvsp[0];}
#line 1762 "main.tab.cc"
    break;

  case 31:
#line 190 "main.y"
            {yyval=yyvsp[0];}
#line 1768 "main.tab.cc"
    break;

  case 32:
#line 191 "main.y"
           {yyval=yyvsp[0];}
#line 1774 "main.tab.cc"
    break;

  case 33:
#line 192 "main.y"
                      {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_EQUAL;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1786 "main.tab.cc"
    break;

  case 34:
#line 199 "main.y"
                   {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_GT;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1798 "main.tab.cc"
    break;

  case 35:
#line 206 "main.y"
                    {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_GTE;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1810 "main.tab.cc"
    break;

  case 36:
#line 213 "main.y"
                   {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_LT;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1822 "main.tab.cc"
    break;

  case 37:
#line 220 "main.y"
                    {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_LTE;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1834 "main.tab.cc"
    break;

  case 38:
#line 227 "main.y"
                         {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_NOTEQUAL;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1846 "main.tab.cc"
    break;

  case 39:
#line 234 "main.y"
                    {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_NOT;
        node->addChild(yyvsp[0]);
        yyval=node;        
    }
#line 1857 "main.tab.cc"
    break;

  case 40:
#line 240 "main.y"
                               {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_LAND;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1869 "main.tab.cc"
    break;

  case 41:
#line 247 "main.y"
                              {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_LOR;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1881 "main.tab.cc"
    break;

  case 42:
#line 254 "main.y"
                             {
        yyval=yyvsp[-1];
    }
#line 1889 "main.tab.cc"
    break;

  case 43:
#line 257 "main.y"
       {
        TreeNode *node=new TreeNode(NODE_NULL, lineno);
        yyval=node;
    }
#line 1898 "main.tab.cc"
    break;

  case 44:
#line 263 "main.y"
         {yyval=yyvsp[0];}
#line 1904 "main.tab.cc"
    break;

  case 45:
#line 264 "main.y"
              {yyval=yyvsp[0];}
#line 1910 "main.tab.cc"
    break;

  case 46:
#line 265 "main.y"
               {yyval=yyvsp[0];}
#line 1916 "main.tab.cc"
    break;

  case 47:
#line 266 "main.y"
                {yyval=yyvsp[0];}
#line 1922 "main.tab.cc"
    break;

  case 48:
#line 267 "main.y"
                             {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_COMMA;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 1934 "main.tab.cc"
    break;

  case 49:
#line 274 "main.y"
                    {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_ADD;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;   
    }
#line 1946 "main.tab.cc"
    break;

  case 50:
#line 281 "main.y"
                    {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_SUB;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;   
    }
#line 1958 "main.tab.cc"
    break;

  case 51:
#line 288 "main.y"
                    {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_MUL;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;   
    }
#line 1970 "main.tab.cc"
    break;

  case 52:
#line 295 "main.y"
                    {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_DIV;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;   
    }
#line 1982 "main.tab.cc"
    break;

  case 53:
#line 302 "main.y"
                    {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_MOD;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;   
    }
#line 1994 "main.tab.cc"
    break;

  case 54:
#line 309 "main.y"
                          {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_SADD;
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 2005 "main.tab.cc"
    break;

  case 55:
#line 315 "main.y"
                            {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_UMINUS;
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 2016 "main.tab.cc"
    break;

  case 56:
#line 321 "main.y"
               {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_ADDRO;
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 2027 "main.tab.cc"
    break;

  case 57:
#line 327 "main.y"
             {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_INC;
        node->addChild(yyvsp[-1]);
        yyval=node;
    }
#line 2038 "main.tab.cc"
    break;

  case 58:
#line 333 "main.y"
             {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_DEC;
        node->addChild(yyvsp[-1]);
        yyval=node;
    }
#line 2049 "main.tab.cc"
    break;

  case 59:
#line 339 "main.y"
                     {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_ASSIGN;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;
    }
#line 2061 "main.tab.cc"
    break;

  case 60:
#line 346 "main.y"
                      {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_AASSIGN;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;  
    }
#line 2073 "main.tab.cc"
    break;

  case 61:
#line 353 "main.y"
                      {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_MASSIGN;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;  
    }
#line 2085 "main.tab.cc"
    break;

  case 62:
#line 360 "main.y"
                      {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_SASSIGN;
        node->addChild(yyvsp[-2]);
        node->addChild(yyvsp[0]);
        yyval=node;  
    }
#line 2097 "main.tab.cc"
    break;

  case 63:
#line 367 "main.y"
                        {
        yyval=yyvsp[-1];
    }
#line 2105 "main.tab.cc"
    break;

  case 64:
#line 370 "main.y"
       {
        TreeNode *node=new TreeNode(NODE_NULL, lineno);
        yyval=node;
    }
#line 2114 "main.tab.cc"
    break;

  case 65:
#line 376 "main.y"
          {
        TreeNode *node=new TreeNode(NODE_TYPE, lineno);
        node->varType=VAR_INTEGER;
        node->type=VAR_INTEGER;
        yyval=node;
    }
#line 2125 "main.tab.cc"
    break;

  case 66:
#line 382 "main.y"
           {
        TreeNode *node=new TreeNode(NODE_TYPE, lineno);
        node->varType=VAR_VOID;
        node->type=VAR_VOID;
        yyval=node;         
    }
#line 2136 "main.tab.cc"
    break;

  case 67:
#line 388 "main.y"
           {
        TreeNode *node=new TreeNode(NODE_TYPE, lineno);
        node->varType=VAR_CHAR;
        node->type=VAR_CHAR;
        yyval=node;   
    }
#line 2147 "main.tab.cc"
    break;

  case 68:
#line 394 "main.y"
           {
        TreeNode *node=new TreeNode(NODE_TYPE, lineno);
        node->varType=VAR_BOOL;
        node->type=VAR_BOOL;
        yyval=node;   
    }
#line 2158 "main.tab.cc"
    break;


#line 2162 "main.tab.cc"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (yymsgp);
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 402 "main.y"
