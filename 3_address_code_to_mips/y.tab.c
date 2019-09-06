/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "codegen.y" /* yacc.c:337  */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include<bits/stdc++.h>
#include <sstream>
using namespace std;
map <string,int> varmap;
int lookup(char *);
char* check(char* a);
int yylex(void);
#define YYSTYPE char *
void yyerror (char const *s) {
   		//fprintf (stderr, "%s\n", s);
 }
FILE *temp;
extern char *yytext;
int labelcount=0;
int kk=0;
int aa=0;
int ll=0;
int linenum=0;
string genLabel();

#line 96 "y.tab.c" /* yacc.c:337  */
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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    ID = 259,
    EQ = 260,
    OSB = 261,
    CSB = 262,
    BINARY_OPERATORS = 263,
    PLUS = 264,
    MINUS = 265,
    TIMES = 266,
    DIVIDE = 267,
    SMALLER = 268,
    SMALLEREQ = 269,
    GREATER = 270,
    GREATEREQ = 271,
    EQEQ = 272,
    IF = 273,
    GOTO = 274,
    param = 275,
    ret = 276,
    OPT = 277,
    FLOAT = 278,
    LABEL = 279,
    CALL = 280,
    COMMA = 281,
    LEFTSQPAR = 282,
    RIGSQPAR = 283,
    STAR = 284,
    ANDP = 285,
    UNARY_OPS = 286,
    PUSH = 287
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define EQ 260
#define OSB 261
#define CSB 262
#define BINARY_OPERATORS 263
#define PLUS 264
#define MINUS 265
#define TIMES 266
#define DIVIDE 267
#define SMALLER 268
#define SMALLEREQ 269
#define GREATER 270
#define GREATEREQ 271
#define EQEQ 272
#define IF 273
#define GOTO 274
#define param 275
#define ret 276
#define OPT 277
#define FLOAT 278
#define LABEL 279
#define CALL 280
#define COMMA 281
#define LEFTSQPAR 282
#define RIGSQPAR 283
#define STAR 284
#define ANDP 285
#define UNARY_OPS 286
#define PUSH 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   81

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  80

#define YYUNDEFTOK  2
#define YYMAXUTOK   287

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    39,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    56,    73,    92,
      93,    96,    98,   101,   103,   104,   107,   112,   385,   393,
     402,   414,   440,   462,   616,   644,   665,   693,   709,   710,
     712,   713,   713,   713,   713
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "EQ", "OSB", "CSB",
  "BINARY_OPERATORS", "PLUS", "MINUS", "TIMES", "DIVIDE", "SMALLER",
  "SMALLEREQ", "GREATER", "GREATEREQ", "EQEQ", "IF", "GOTO", "param",
  "ret", "OPT", "FLOAT", "LABEL", "CALL", "COMMA", "LEFTSQPAR", "RIGSQPAR",
  "STAR", "ANDP", "UNARY_OPS", "PUSH", "$accept", "lines", "line", "retur",
  "typechange", "identifiernum", "binary_ops", "identifier", "num",
  "label", "comma", "unary", "binary", "copy", "label1",
  "conditional_jump", "unconditional_jump", "function_call", "parameters",
  "indexed_copy", "address_pointer_assignment", YY_NULLPTR
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
     285,   286,   287
};
# endif

#define YYPACT_NINF -18

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-18)))

#define YYTABLE_NINF -21

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -18,     2,   -18,   -18,     1,   -17,     1,     1,   -18,   -17,
     -18,     8,     8,   -18,   -18,   -18,     3,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
       7,    -2,     5,   -18,   -18,   -18,   -18,   -18,   -10,    20,
      24,    33,   -18,     1,   -17,   -17,    27,     1,     8,     1,
     -17,     8,     8,     8,     7,     6,    26,    16,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,    13,   -18,   -18,   -18,     1,
       1,   -17,    38,   -18,    14,    15,   -18,   -18,   -18,   -18
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    22,     0,     0,     0,     0,    24,     0,
      25,     0,     0,     3,    14,    16,     0,    30,    15,     5,
       4,     6,    13,     7,     8,    10,     9,    11,    12,    23,
       0,    19,    20,    34,    37,    19,    20,    17,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,     0,    31,    32,
      35,    40,    44,    43,    18,     0,    41,    42,    26,     0,
       0,     0,     0,    27,     0,     0,    33,    36,    39,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -18,   -18,   -18,   -18,   -18,    12,    -9,    -1,    -3,     4,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    13,    14,    15,    30,    43,    35,    36,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      16,    32,     2,    31,    29,     3,     3,     8,    41,    33,
      39,    40,     3,    38,   -19,    42,    46,    44,    34,    37,
       4,     5,     6,     7,    45,    47,     8,     9,    10,    48,
      60,    11,    12,    70,   -20,    71,    29,     3,    56,    72,
      55,    77,    78,    79,    62,    69,    61,    63,    58,    59,
      66,    67,    68,    54,    65,    57,    49,     0,    50,     0,
       0,    64,    51,    52,    53,     0,     0,    75,     0,    74,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
       0,    73
};

static const yytype_int8 yycheck[] =
{
       1,     4,     0,     4,     3,     4,     4,    24,     5,     5,
      11,    12,     4,     9,     8,     8,    26,    19,     6,     7,
      18,    19,    20,    21,    19,     5,    24,    25,    26,     5,
       3,    29,    30,    27,     8,    19,     3,     4,    41,    26,
      41,     3,    28,    28,    47,    54,    47,    48,    44,    45,
      51,    52,    53,    41,    50,    43,    23,    -1,    25,    -1,
      -1,    49,    29,    30,    31,    -1,    -1,    70,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    69
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,     0,     4,    18,    19,    20,    21,    24,    25,
      26,    29,    30,    35,    36,    37,    40,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     3,
      38,    40,    41,    42,    38,    40,    41,    38,    42,    40,
      40,     5,     8,    39,    19,    19,    26,     5,     5,    23,
      25,    29,    30,    31,    38,    40,    41,    38,    42,    42,
       3,    40,    41,    40,    38,    42,    40,    40,    40,    39,
      27,    19,    26,    38,    40,    41,    42,     3,    28,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    34,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    36,    37,    38,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    46,
      47,    48,    48,    48,    49,    50,    50,    51,    52,    52,
      53,    53,    53,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     3,     3,
       1,     4,     4,     6,     2,     4,     6,     2,     6,     6,
       4,     4,     4,     4,     4
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
  YYUSE (yytype);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
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

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

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
        case 10:
#line 47 "codegen.y" /* yacc.c:1652  */
    {ll++;}
#line 1343 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 57 "codegen.y" /* yacc.c:1652  */
    {
				fprintf(temp, "l%d: ", ++ll);
				printf("ret\n");
				int k=lookup(yyvsp[0]);
				if(k==-1)
							{
								fprintf(temp,"li.s $f15, %s\n",check(yyvsp[0]));
							}
							else
							{
								fprintf(temp,"lwc1 $f15, %d($sp)\n",8*k - 8);
							}
							fprintf(temp,"jr $ra\n");

				}
#line 1363 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 73 "codegen.y" /* yacc.c:1652  */
    {
					fprintf(temp, "l%d: ", ++ll);
                    printf("converting into float\n");
	                int k=lookup(yyvsp[0]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",yyvsp[-1]);
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							
						k=lookup(yyvsp[-3]);
						fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);

				}
#line 1386 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 92 "codegen.y" /* yacc.c:1652  */
    {yyval = yyvsp[0];}
#line 1392 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 93 "codegen.y" /* yacc.c:1652  */
    {yyval = yyvsp[0];}
#line 1398 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 96 "codegen.y" /* yacc.c:1652  */
    { yyval = strdup(yytext); }
#line 1404 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 98 "codegen.y" /* yacc.c:1652  */
    { yyval = strdup(yytext); }
#line 1410 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 101 "codegen.y" /* yacc.c:1652  */
    {yyval = strdup(yytext);}
#line 1416 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 103 "codegen.y" /* yacc.c:1652  */
    {yyval = strdup(yytext);}
#line 1422 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 104 "codegen.y" /* yacc.c:1652  */
    {yyval = strdup(yytext);}
#line 1428 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 107 "codegen.y" /* yacc.c:1652  */
    {
			fprintf(temp, "l%d: ", ++ll);
}
#line 1436 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 112 "codegen.y" /* yacc.c:1652  */
    {
						fprintf(temp, "l%d: ", ++ll);
						
						
						cout<<check(yyvsp[-2])<<endl;
						printf("%s\n",check(yyvsp[-2]));
						if(strcmp(yyvsp[-1],"+")==0)
						{
							printf("binaryyyy\n");

							int k=lookup(yyvsp[-2]);
							int k2 = lookup(yyvsp[-2]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-2]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							//pushing into stack first arg
							
							
							


							k=lookup(yyvsp[0]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check(yyvsp[0]));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}

							
							
							fprintf(temp,"add.s $f0, $f0, $f1\n");
							k=lookup(yyvsp[-4]);
							
							fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);
									
						}else if(strcmp(yyvsp[-1],"-")==0){
							cout<<"MINUS"<<endl;
							int k=lookup(yyvsp[-2]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-2]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							


							k=lookup(yyvsp[0]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check(yyvsp[0]));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}
							
							fprintf(temp,"sub.s $f0, $f0, $f1\n");
							k=lookup(yyvsp[-4]);
							
							fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);
									
						}else if(strcmp(yyvsp[-1],"*")==0){
							int k=lookup(yyvsp[-2]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-2]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							
							k=lookup(yyvsp[0]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check(yyvsp[0]));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}
							
							fprintf(temp,"mul.s $f0, $f0, $f1\n");
							k=lookup(yyvsp[-4]);
							
							fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);
									
						}else if(strcmp(yyvsp[-1],"/")==0){
							int k=lookup(yyvsp[-2]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-2]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							


							k=lookup(yyvsp[0]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check(yyvsp[0]));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}
							
							fprintf(temp,"div.s $f0, $f0, $f1\n");
							k=lookup(yyvsp[-4]);
							
							fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);
									
						}else if(strcmp(yyvsp[-1],"<")==0){
							
							int k=lookup(yyvsp[-2]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-2]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							//pushing into stack first arg
							fprintf(temp,"swc1 $f0, 0($sp)\n");
							fprintf(temp,"addiu $sp, $sp, -8\n");


							k=lookup(yyvsp[0]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[0]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
							fprintf(temp,"lwc1 $f1, 8($sp)\n");
							fprintf(temp,"addiu $sp, $sp, 8\n");
							fprintf(temp,"sub.s $f0, $f0, $f1\n");

							string l1 = genLabel();
							string l2 = genLabel();

							cout<<"l1 "<<l1<<endl;
							cout<<"l2 "<<l2<<endl;

							fprintf(temp, "bgtz $f0 %s\n", l1.c_str() );
							fprintf(temp, "li.s $f0, 0\n" );
							fprintf(temp, "b %s\n",l2.c_str() );
							fprintf(temp, "%s:",l1.c_str() );
							fprintf(temp, "li.s $f0, 1\n" );
							fprintf(temp, "%s:",l2.c_str() );
							k=lookup(yyvsp[-4]);
							
							fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);
									
						}else if(strcmp(yyvsp[-1],">")==0){
							
							int k=lookup(yyvsp[-2]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-2]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							//pushing into stack first arg
							fprintf(temp,"swc1 $f0, 0($sp)\n");
							fprintf(temp,"addiu $sp, $sp, -8\n");


							k=lookup(yyvsp[0]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[0]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
							fprintf(temp,"lwc1 $f1, 8($sp)\n");
							fprintf(temp,"addiu $sp, $sp, 8\n");
							fprintf(temp,"sub.s $f0, $f1, $f0\n");

							string l1 = genLabel();
							string l2 = genLabel();

							cout<<"l1 "<<l1<<endl;
							cout<<"l2 "<<l2<<endl;

							fprintf(temp, "bgtz $f0 %s\n", l1.c_str() );
							fprintf(temp, "li.s $f0, 0.0\n" );
							fprintf(temp, "b %s\n",l2.c_str() );
							fprintf(temp, "%s:",l1.c_str() );
							fprintf(temp, "li.s $f0, 1\n" );
							fprintf(temp, "%s:",l2.c_str() );
							k=lookup(yyvsp[-4]);
							
							fprintf(temp,"swc1 $f0, %d($t0)\n",8*k - 8);
									
						}else if(strcmp(yyvsp[-1],"==")==0){
							
							int k=lookup(yyvsp[-2]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-2]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							//pushing into stack first arg
							fprintf(temp,"sw $f0, 0($sp)\n");
							fprintf(temp,"addiu $sp, $sp, -8\n");


							k=lookup(yyvsp[0]);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[0]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
							fprintf(temp,"lwc1 $f1, 8($sp)\n");
							fprintf(temp,"addiu $sp, $sp, 8\n");
							

							string l1 = genLabel();
							string l2 = genLabel();

							cout<<"l1 "<<l1<<endl;
							cout<<"l2 "<<l2<<endl;

							fprintf(temp, "beq $f0 $f1 %s\n", l1.c_str() );
							fprintf(temp, "li.s $f0, 0\n" );
							fprintf(temp, "b %s\n",l2.c_str() );
							fprintf(temp, "%s:",l1.c_str() );
							fprintf(temp, "li.s $f0, 1\n" );
							fprintf(temp, "%s:",l2.c_str() );
							k=lookup(yyvsp[-4]);
							
							fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);
									
						}
					}
#line 1711 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 385 "codegen.y" /* yacc.c:1652  */
    {
										fprintf(temp, "l%d: ", ++ll);
										printf("inden1 %s\n",check(yyvsp[0]));
										int k = lookup(yyvsp[0]);
										fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k-8);
										k = lookup(yyvsp[-2]);
										fprintf(temp,"swc1 $f0, %d($sp)\n",8*k-8);
									}
#line 1724 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 393 "codegen.y" /* yacc.c:1652  */
    {
										fprintf(temp, "l%d: ", ++ll);
										printf("inden %s %s\n",yyvsp[0], check(yyvsp[0]));
										int k = lookup(yyvsp[-2]);
										fprintf(temp,"li.s $f0, %s\n",check(yyvsp[0]));
									
										fprintf(temp,"swc1 $f0, %d($sp)\n",8*k-8);
									
									}
#line 1738 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 404 "codegen.y" /* yacc.c:1652  */
    {	if(aa==1) {
				aa=0;
				fprintf(temp,"li $v0,10\nsyscall\n\n");
				
			}
			else if(strcmp(yyvsp[0],"main:")==0) aa=1;
			printf("level %s\n",yyvsp[0]);
			fprintf(temp,"%s\n",yyvsp[0]);
			ll++;
		}
#line 1753 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 415 "codegen.y" /* yacc.c:1652  */
    {
					 fprintf(temp, "l%d: ", ++ll);
					 	//remove : from label:
					 	int l=strlen(yyvsp[0]);
					 	yyvsp[0][l-1]=0;
                        
                        int r = strlen(yyvsp[0]);
                        char nst[25];
                        int i=0;
                        while(yyvsp[0][i] !=':')
                        {
                          nst[i] = yyvsp[0][i];
                          i++;
                        }

					 	cout<<"yes1"<<endl;
					 	int k=lookup(yyvsp[-2]);
					 	fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k-8);
				   	 	fprintf(temp,"li.s $f1, 0\n");
				   	 	fprintf(temp,"c.eq.s $f0, $f1\n");
						fprintf(temp,"bc1f %s\n",nst);		

											
					 }
#line 1782 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 441 "codegen.y" /* yacc.c:1652  */
    {
				   	 	//remove : from label:
				   	 	fprintf(temp, "l%d: ", ++ll);
				   	 	int l=strlen(yyvsp[0]);
					 	yyvsp[0][l-1]=0;
					 	int r = strlen(yyvsp[0]);
                        char nst[25];
                        int i=0;
                        while(yyvsp[0][i] !=':')
                        {
                          nst[i] = yyvsp[0][i];
                          i++;
                        }

				   	 	cout<<"yes2"<<endl;
				   	 	fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-3]));
				   	 	fprintf(temp,"li.s $f1, 0.0\n");
				   	 	fprintf(temp,"c.eq.s $f0, $f1\n");
						fprintf(temp,"bc1t %s\n",nst);		

				   	 }
#line 1808 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 463 "codegen.y" /* yacc.c:1652  */
    {
				   fprintf(temp, "l%d: ", ++ll);
				     printf("a something b %s\n",yyvsp[-3]);
				     int r = strlen(yyvsp[0]);
                        char nst[25];
                        int i=0;
                        while(yyvsp[0][i] !=':')
                        {
                          nst[i] = yyvsp[0][i];
                          i++;
                        }

                        while(i<25)
                        {
                           nst[i] = '\0';
                           i++;
                        }

				     if(strcmp(yyvsp[-3],"==")==0)
				     {
				        int k=lookup(yyvsp[-4]);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-4]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
						 k=lookup(yyvsp[-2]);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check(yyvsp[-2]));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}

						fprintf(temp,"c.eq.s $f0, $f1\n");
						fprintf(temp,"bc1t %s\n",nst);		

				     }

				     if(strcmp(yyvsp[-3],">=")==0)
				     {
				        int k=lookup(yyvsp[-4]);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-4]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
						 k=lookup(yyvsp[-2]);
				        if(k==-1)
							{	
								fprintf(temp,"li.s $f1, %s\n",check(yyvsp[-2]));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}
						fprintf(temp,"c.lt.s $f0, $f1\n");
						fprintf(temp,"bc1f %s\n",nst);		

				     }

				     if(strcmp(yyvsp[-3],">")==0)
				     {
				        int k=lookup(yyvsp[-4]);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-4]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
						 k=lookup(yyvsp[-2]);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check(yyvsp[-2]));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}

	
						fprintf(temp,"c.le.s $f0, $f1\n");
						fprintf(temp,"bc1f %s\n",nst);		
	

				     }

				     if(strcmp(yyvsp[-3],"<=")==0)
				     {
				        int k=lookup(yyvsp[-4]);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-4]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
						 k=lookup(yyvsp[-2]);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check(yyvsp[-2]));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}
						fprintf(temp,"c.le.s $f0, $f1\n");
						fprintf(temp,"bc1t %s\n",nst);		
		

				     }
				     if(strcmp(yyvsp[-3],"<")==0)
				     {
				        int k=lookup(yyvsp[-4]);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check(yyvsp[-4]));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
						 k=lookup(yyvsp[-2]);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check(yyvsp[-2]));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}
						fprintf(temp,"c.lt.s $f0, $f1\n");
						fprintf(temp,"bc1t %s\n",nst);		


				     }


				   }
#line 1963 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 617 "codegen.y" /* yacc.c:1652  */
    {
					 	fprintf(temp, "l%d: ", ++ll);
					 	//remove : from label:
					 	
					 	char nst[25];
                        int i=0;
                        while(yyvsp[0][i] !=':')
                        {
                          nst[i] = yyvsp[0][i];
                          i++;
                        }

                        while(i<25)
                        {
                           nst[i] = '\0';
                           i++;
                        }
					 	
                         


					 	cout<<"yes3"<<endl;
					 	fprintf(temp,"j %s\n",nst);
					 }
#line 1992 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 644 "codegen.y" /* yacc.c:1652  */
    {
				kk=0;
				int size = strlen(yyvsp[-2]);
				char str[25];
				int i=0;
				while(yyvsp[-2][i] != ':')
				{
					str[i] = yyvsp[-2][i];
					i++;
				}

				while(i<25)
				{
				  str[i] = '\0';
				  i++;
				}

				printf("function call\n");
				fprintf(temp,"jal %s\n", str);
				cout<<"yes7"<<endl;
				}
#line 2018 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 665 "codegen.y" /* yacc.c:1652  */
    {


				kk=0;
				int size = strlen(yyvsp[-2]);
				char str[25];
				int i=0;
				while(yyvsp[-2][i] != ':')
				{
					str[i] = yyvsp[-2][i];
					i++;
				}

				while(i<25)
				{
				  str[i] = '\0';
				  i++;
				}

				printf("function call\n");
				fprintf(temp,"jal %s\n", str);
				int k=lookup(yyvsp[-5]);
				fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
				fprintf(temp,"mov.s , $f0, $f15\n");
				fprintf(temp,"swc1 $f0, %d($sp)\n",8*k-8);

				}
#line 2050 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 693 "codegen.y" /* yacc.c:1652  */
    {
					fprintf(temp, "l%d: ", ++ll);
					printf("param\n");
									int k = lookup(yyvsp[0]);
									if(k==-1){
									   fprintf(temp,"li.s $f%d, %s\n",kk,check(yyvsp[0]));
									}
									else
									{
									fprintf(temp,"lwc1 $f%d, %d($sp)\n",kk,8*k - 8);
									}
									kk++;

							   }
#line 2069 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 710 "codegen.y" /* yacc.c:1652  */
    {cout<<"yes8"<<endl;}
#line 2075 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 714 "codegen.y" /* yacc.c:1652  */
    {cout<<"yes9"<<endl;}
#line 2081 "y.tab.c" /* yacc.c:1652  */
    break;


#line 2085 "y.tab.c" /* yacc.c:1652  */
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
                  yystos[*yyssp], yyvsp);
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
#line 715 "codegen.y" /* yacc.c:1918  */



string genLabel(){
	string l = "_lb";
	stringstream ss;
	ss<<labelcount;
	labelcount++;
	cout<<labelcount<<endl;
	
	return l+ss.str();
}


char* check(char* a)
{
	int n=0;
	for(int r=0;a[r] !='\0';r++)
	n++;
	for(int i=0;i<n;i++)
	{
	  if(a[i]=='.')
	  return a;
	}
	char *k;
	k = (char *)malloc(25);
	
	int i=0;
	for(i=0; i<n; i++) k[i]=a[i];
	k[i++]='.';
	k[i++]='0';
	while(i<25){
	k[i]='\0';
	i++;
	}

	
	return (char *)k;
}


int lookup(char * a)
{
	string x(a);
	if(varmap.find(x)!=varmap.end())return varmap[x];
	else return -1;
}




int main (void) {
	//printf("yes\n");
	char a[1000];
	temp=fopen("mid.txt","r");
	int k=1;
	
	while(fscanf(temp,"%s",a)!=EOF)
	{
		string b(a);
		//cout<<a<<endl;
		//fscanf(temp,"%d",&k);
		if(varmap.find(b)==varmap.end()){varmap[b]=k++;}
	}
	fclose(temp);
	//printf("yes\n");
	temp=fopen("out.s","w+");
	
	
	fprintf(temp,".data\n .text\n j main\n");
	yyparse ();
	if(aa==1)
	{
	  fprintf(temp,"li $v0, 10\n syscall\n");
	}

	fclose(temp);
	
	return 0;
}


int yyerror (char *s) {fprintf (stderr, "%s\n", s); return 1;}
