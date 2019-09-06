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
#line 1 "semantics.y" /* yacc.c:337  */

	#include "TAC.h"
	#define YYDEBUG 1
	extern int yylex();
	extern char *yytext;
	void yyerror(const char *s);
	type_structure *T;
	int W;
	int diff;
	int flag = 0;
	extern int numtemp;					// count of temporary variable
	extern int next_instruction;				// stores the count of next instruction
	extern int int_width;
	extern int float_width;
	extern int char_width;
	extern int bool_width;
	extern int void_width;

#line 89 "semantics.tab.c" /* yacc.c:337  */
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
   by #include "semantics.tab.h".  */
#ifndef YY_YY_SEMANTICS_TAB_H_INCLUDED
# define YY_YY_SEMANTICS_TAB_H_INCLUDED
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
    INT_CONST = 259,
    FLOAT_CONST = 260,
    ZERO_CONST = 261,
    ARROW = 262,
    INC = 263,
    DEC = 264,
    LTE = 265,
    GTE = 266,
    EQ = 267,
    NEQ = 268,
    AND = 269,
    OR = 270,
    ADDC = 271,
    MODC = 272,
    MULC = 273,
    DIVC = 274,
    SUBC = 275,
    BOOL = 276,
    BREAK = 277,
    CASE = 278,
    CHAR = 279,
    CONTINUE = 280,
    DEFAULT = 281,
    DO = 282,
    IF = 283,
    ELSE = 284,
    FLOAT = 285,
    FOR = 286,
    GOTO = 287,
    INT = 288,
    RETURN = 289,
    SWITCH = 290,
    VOID = 291,
    WHILE = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "semantics.y" /* yacc.c:352  */

	type_attribute tspec;		// to store attributes of type-specifiers
	param_quad_list plist;	// to store attributes of argument-expression-quad_list
	identifier_struct idt;			// to store attributes of an identifier 
	int val_int;
	char val_char;
	string *word;
	initial ini;		// to store attributes of initializer
	expression_struct expr;		// to store attributes of an expression 			
	quad_list *after;		// to store attributes of statements
	float val_float;
	int dummy;

#line 184 "semantics.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SEMANTICS_TAB_H_INCLUDED  */



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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   369

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  242

#define YYUNDEFTOK  2
#define YYMAXUTOK   292

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
       2,     2,     2,     2,     2,     2,     2,    42,     2,     2,
      48,    49,    40,    38,    44,    39,    52,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    43,
      53,    45,    54,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    65,    75,    88,    89,    92,    93,    96,
     108,   121,   122,   126,   127,   130,   131,   138,   139,   142,
     149,   167,   173,   179,   183,   189,   193,   199,   234,   239,
     247,   250,   289,   291,   316,   318,   344,   347,   348,   351,
     353,   356,   357,   361,   381,   449,   468,   471,   476,   508,
     533,   549,   551,   582,   614,   616,   646,   676,   720,   721,
     722,   725,   751,   753,   797,   819,   842,   844,   868,   893,
     896,   898,   915,   932,   949,   967,   969,   986,  1004,  1007,
    1010,  1013,  1018,  1019,  1036,  1037,  1054,  1061,  1063,  1108,
    1110,  1135,  1136,  1137,  1138,  1139,  1140,  1143,  1144,  1147,
    1150,  1158,  1178,  1179,  1180,  1181,  1182,  1183,  1186,  1187,
    1190,  1191,  1194,  1196,  1203,  1204,  1207,  1208,  1211,  1217,
    1225,  1228,  1238,  1244,  1255,  1258,  1259,  1262,  1263,  1264,
    1265
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT_CONST", "FLOAT_CONST",
  "ZERO_CONST", "ARROW", "INC", "DEC", "LTE", "GTE", "EQ", "NEQ", "AND",
  "OR", "ADDC", "MODC", "MULC", "DIVC", "SUBC", "BOOL", "BREAK", "CASE",
  "CHAR", "CONTINUE", "DEFAULT", "DO", "IF", "ELSE", "FLOAT", "FOR",
  "GOTO", "INT", "RETURN", "SWITCH", "VOID", "WHILE", "'+'", "'-'", "'*'",
  "'/'", "'%'", "';'", "','", "'='", "'{'", "'}'", "'('", "')'", "'['",
  "']'", "'.'", "'<'", "'>'", "'?'", "':'", "$accept", "typespec",
  "transunit", "external_declaration", "funcdef", "declaration_list",
  "declaration", "declaration_type", "initial_declaration_list",
  "initial_declarator", "initializer", "initializerrowlist",
  "initializerrow", "declarator", "P", "direct_declarator",
  "paramtypelist", "param_quad_list", "parameter_declaration", "idlist",
  "primexp", "postexp", "unaryexp", "unaryop", "castexp", "multexp",
  "addexp", "shiftexp", "relexp", "eqexp", "andexp", "xorexp", "orexp",
  "M", "logandexp", "logorexp", "N", "condexp", "assignexp", "assignop",
  "exp", "constexp", "argexplist", "stmt", "labeled_statement", "compstmt",
  "blockitemlist", "blockitem", "expstmt", "selstmt",
  "iteration_statement", "expopt", "jumpstmt", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,    43,    45,
      42,    47,    37,    59,    44,    61,   123,   125,    40,    41,
      91,    93,    46,    60,    62,    63,    58
};
# endif

#define YYPACT_NINF -124

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-124)))

#define YYTABLE_NINF -87

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,  -124,  -124,  -124,    16,   117,  -124,  -124,  -124,    12,
    -124,  -124,  -124,  -124,  -124,    14,    -7,  -124,   302,   -24,
     -29,  -124,    14,   321,   180,   303,  -124,    12,  -124,    25,
      26,  -124,  -124,    52,  -124,  -124,  -124,   161,   161,  -124,
    -124,  -124,    86,   161,  -124,  -124,   104,   222,   161,  -124,
      81,    37,  -124,   109,    97,  -124,  -124,  -124,   128,     6,
    -124,  -124,   106,   161,   112,   101,  -124,   119,   124,   173,
     161,   130,  -124,  -124,  -124,  -124,  -124,    87,  -124,  -124,
    -124,   145,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
       8,     1,  -124,   153,  -124,  -124,   321,    42,     7,  -124,
    -124,    76,   161,   191,  -124,  -124,  -124,  -124,  -124,  -124,
     161,  -124,  -124,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,  -124,  -124,   161,  -124,  -124,   176,
    -124,   272,   272,   161,   283,   190,   192,   194,   161,   195,
    -124,   161,  -124,   226,  -124,    14,   196,   200,  -124,   243,
    -124,  -124,  -124,   133,   201,  -124,  -124,  -124,  -124,    19,
     -12,  -124,  -124,  -124,  -124,  -124,    81,    81,  -124,  -124,
    -124,  -124,   109,   109,   161,   161,   -31,   272,  -124,   213,
      23,   161,   212,  -124,  -124,    29,   161,  -124,  -124,  -124,
    -124,    16,  -124,   321,  -124,   321,   161,  -124,  -124,  -124,
     128,   161,  -124,   220,  -124,   227,  -124,   272,    85,  -124,
    -124,   143,  -124,  -124,   161,   272,   161,   161,  -124,  -124,
    -124,    96,   242,   224,   235,   272,   236,   253,   272,  -124,
    -124,  -124,  -124,  -124,   161,   272,  -124,  -124,   234,  -124,
     272,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     3,     2,    16,     0,     5,     7,     8,     0,
      15,     1,     6,    29,    14,     0,     0,    17,    19,    27,
       0,    13,     0,     0,     0,     0,    11,     0,    10,    28,
       0,    30,    18,    19,    44,    43,    45,     0,     0,    59,
      60,    58,     0,     0,    20,    47,    54,    61,     0,    62,
      66,    69,    70,    75,    78,    79,    80,    82,    84,    87,
      89,    21,     0,     0,     0,     0,    81,     0,     0,     0,
     125,     0,    81,   117,   110,   114,    97,     0,   115,   102,
     103,    81,   112,   104,   105,   106,   107,    12,     9,    41,
       0,     0,    32,     0,    55,    56,     0,     0,     0,    52,
      53,     0,     0,     0,    95,    94,    92,    93,    96,    91,
       0,    61,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    81,     0,   129,    99,     0,
     128,     0,     0,     0,   125,     0,   126,     0,     0,     0,
     116,     0,   111,     0,    35,    40,     0,    36,    37,     0,
      34,    31,    25,     0,     0,    22,    46,    50,   100,     0,
       0,    51,    90,    63,    64,    65,    67,    68,    73,    74,
      71,    72,    76,    77,     0,     0,     0,     0,   109,     0,
       0,   125,     0,   127,   130,     0,     0,    98,   113,    39,
      33,     0,    42,     0,    23,     0,     0,    49,    48,    83,
      85,     0,   108,     0,    81,     0,    81,     0,     0,    38,
      26,     0,   101,    88,     0,     0,   125,   125,   120,    81,
      24,     0,   118,     0,     0,     0,     0,     0,     0,    81,
     121,   122,    81,   124,   125,     0,    86,   119,     0,    81,
       0,   123
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,   279,  -124,  -124,    -6,     2,  -124,   263,
     -18,  -124,    94,    -1,  -124,  -124,  -124,  -124,    99,  -124,
    -124,  -124,   -15,  -124,   -44,   105,  -124,    77,   102,  -124,
    -124,  -124,   122,   -71,   118,  -124,    65,   -60,   -14,  -124,
     -43,  -124,  -124,   -89,  -124,    22,  -124,   159,  -124,  -124,
    -124,  -123,  -124
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    25,     8,    27,    16,    17,
     152,    97,   153,    33,    90,    19,   146,   147,   148,    91,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   132,    58,    59,   227,    60,    76,   110,
      77,   129,   159,    78,    79,    80,    81,    82,    83,    84,
      85,   137,    86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,   139,     9,   128,   112,    44,    10,     9,    18,    61,
     143,   182,    26,   141,    20,    13,    93,    13,    75,    87,
      31,   125,    94,    95,    29,   201,    30,   136,    89,    34,
      35,    36,   141,   111,    37,    38,    21,    22,     1,   198,
      28,     2,   178,   179,     3,   149,     1,    88,   111,     2,
     150,   141,     3,   174,   175,    14,   156,   144,   205,   160,
      15,   126,    15,   196,    39,    40,    41,   141,   197,   163,
     164,   165,   204,   141,    43,   116,   117,    92,   207,    34,
      35,    36,    61,   176,    37,    38,   154,   158,   202,   155,
     180,   136,   145,   223,   224,   185,   162,    23,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   122,
     123,   236,    99,   100,    39,    40,    41,    11,   218,   118,
     119,   113,   114,   115,    43,   157,   222,   187,   181,   141,
     140,   141,    96,   215,   219,   217,   230,    75,   136,   233,
     141,   213,   124,   208,   189,   226,   237,     1,   225,   127,
       2,   241,   101,     3,   102,   130,   103,   131,   234,   111,
     111,   235,   120,   121,    34,    35,    36,   133,   240,    37,
      38,   221,   134,   136,   136,   210,   135,   193,   138,    61,
     194,    61,   212,    34,    35,    36,   111,   193,    37,    38,
     220,   136,   142,   145,   161,   168,   169,   170,   171,    39,
      40,    41,    62,    63,   151,    64,    65,    66,    67,    43,
       1,    68,    69,     2,    70,    71,     3,    72,    39,    40,
      41,   166,   167,    73,   172,   173,    24,    74,    43,    34,
      35,    36,   177,   183,    37,    38,   141,   184,   104,   105,
     106,   107,   108,   186,   191,   190,   192,   195,    62,    63,
     203,    64,    65,    66,    67,   206,     1,    68,    69,     2,
      70,    71,     3,    72,    39,    40,    41,   109,   214,    73,
     216,   -86,    24,   228,    43,    34,    35,    36,   229,   231,
      37,    38,   232,   239,    12,    32,    34,    35,    36,   211,
     209,    37,    38,   200,    62,    63,   199,    64,    65,    66,
      67,   238,   188,    68,    69,     0,    70,    71,     0,    72,
      39,    40,    41,     1,     0,    73,     2,     0,    24,     3,
      43,    39,    40,    41,    34,    35,    36,     0,     0,    37,
      38,    43,     1,     1,     0,     2,     2,     0,     3,     3,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      40,    41,     0,     0,     0,     0,     0,    42,     0,    43
};

static const yytype_int16 yycheck[] =
{
      43,    72,     0,    63,    48,    23,     4,     5,     9,    23,
      81,   134,    18,    44,    15,     3,    30,     3,    24,    25,
      49,    15,    37,    38,    48,    56,    50,    70,     3,     3,
       4,     5,    44,    48,     8,     9,    43,    44,    30,    51,
      18,    33,   131,   132,    36,    44,    30,    25,    63,    33,
      49,    44,    36,   124,   125,    43,    49,    49,   181,   102,
      48,    55,    48,    44,    38,    39,    40,    44,    49,   113,
     114,   115,    49,    44,    48,    38,    39,    51,    49,     3,
       4,     5,    96,   126,     8,     9,    44,   101,   177,    47,
     133,   134,    90,   216,   217,   138,   110,    45,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,    12,
      13,   234,     8,     9,    38,    39,    40,     0,   207,    10,
      11,    40,    41,    42,    48,    49,   215,   141,   134,    44,
      43,    44,    46,   204,    49,   206,   225,   143,   181,   228,
      44,   201,    14,   186,   145,    49,   235,    30,   219,    43,
      33,   240,    48,    36,    50,    43,    52,    56,   229,   174,
     175,   232,    53,    54,     3,     4,     5,    48,   239,     8,
       9,   214,    48,   216,   217,   193,     3,    44,    48,   193,
      47,   195,   196,     3,     4,     5,   201,    44,     8,     9,
      47,   234,    47,   191,     3,   118,   119,   120,   121,    38,
      39,    40,    22,    23,    51,    25,    26,    27,    28,    48,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,   116,   117,    43,   122,   123,    46,    47,    48,     3,
       4,     5,    56,    43,     8,     9,    44,    43,    16,    17,
      18,    19,    20,    48,    44,    49,     3,    46,    22,    23,
      37,    25,    26,    27,    28,    43,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    45,    48,    43,
      43,    29,    46,    49,    48,     3,     4,     5,    43,    43,
       8,     9,    29,    49,     5,    22,     3,     4,     5,   195,
     191,     8,     9,   175,    22,    23,   174,    25,    26,    27,
      28,   236,   143,    31,    32,    -1,    34,    35,    -1,    37,
      38,    39,    40,    30,    -1,    43,    33,    -1,    46,    36,
      48,    38,    39,    40,     3,     4,     5,    -1,    -1,     8,
       9,    48,    30,    30,    -1,    33,    33,    -1,    36,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    33,    36,    58,    59,    60,    61,    63,    64,
      64,     0,    60,     3,    43,    48,    65,    66,    70,    72,
      70,    43,    44,    45,    46,    62,    63,    64,   102,    48,
      50,    49,    66,    70,     3,     4,     5,     8,     9,    38,
      39,    40,    46,    48,    67,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    91,    92,
      94,    95,    22,    23,    25,    26,    27,    28,    31,    32,
      34,    35,    37,    43,    47,    63,    95,    97,   100,   101,
     102,   103,   104,   105,   106,   107,   109,    63,   102,     3,
      71,    76,    51,    95,    79,    79,    46,    68,    97,     8,
       9,    48,    50,    52,    16,    17,    18,    19,    20,    45,
      96,    79,    81,    40,    41,    42,    38,    39,    10,    11,
      53,    54,    12,    13,    14,    15,    55,    43,    94,    98,
      43,    56,    90,    48,    48,     3,    97,   108,    48,    90,
      43,    44,    47,    90,    49,    64,    73,    74,    75,    44,
      49,    51,    67,    69,    44,    47,    49,    49,    95,    99,
      97,     3,    95,    81,    81,    81,    82,    82,    84,    84,
      84,    84,    85,    85,    90,    90,    97,    56,   100,   100,
      97,    63,   108,    43,    43,    97,    48,    95,   104,    70,
      49,    44,     3,    44,    47,    46,    44,    49,    51,    89,
      91,    56,   100,    37,    49,   108,    43,    49,    97,    75,
      67,    69,    95,    94,    48,    90,    43,    90,   100,    49,
      47,    97,   100,   108,   108,    90,    49,    93,    49,    43,
     100,    43,    29,   100,    90,    90,   108,   100,    93,    49,
      90,   100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    71,    72,
      72,    72,    72,    72,    72,    72,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    77,    77,    78,    78,    78,
      78,    78,    78,    78,    79,    79,    79,    79,    80,    80,
      80,    81,    82,    82,    82,    82,    83,    83,    83,    84,
      85,    85,    85,    85,    85,    86,    86,    86,    87,    88,
      89,    90,    91,    91,    92,    92,    93,    94,    94,    95,
      95,    96,    96,    96,    96,    96,    96,    97,    97,    98,
      99,    99,   100,   100,   100,   100,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     106,   107,   107,   107,   107,   108,   108,   109,   109,   109,
     109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     1,     1,     4,
       3,     1,     2,     3,     2,     2,     1,     1,     3,     1,
       3,     1,     3,     3,     5,     1,     3,     1,     0,     1,
       3,     4,     3,     5,     4,     4,     1,     1,     3,     2,
       1,     1,     3,     1,     1,     1,     3,     1,     4,     4,
       3,     3,     2,     2,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     3,     3,     3,     1,     3,     3,     1,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     1,
       1,     0,     1,     4,     1,     4,     0,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     4,     3,
       2,     3,     1,     3,     1,     1,     2,     1,     6,    10,
       5,     7,     8,    13,     8,     0,     1,     3,     2,     2,
       3
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
        case 2:
#line 55 "semantics.y" /* yacc.c:1652  */
    {
							(yyval.tspec).type = new type_structure();			
							((yyval.tspec).type)->type_name = "void";		
							((yyval.tspec).type)->isarr = 0;			// set type attribute
							((yyval.tspec).type)->type_size = void_width;			
							((yyval.tspec).type)->next = NULL;			
							
							(yyval.tspec).type_size = void_width;		
						}
#line 1490 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 65 "semantics.y" /* yacc.c:1652  */
    {
							(yyval.tspec).type = new type_structure();
							((yyval.tspec).type)->type_name = "int";			// set type attribute
							((yyval.tspec).type)->isarr = 0;
							((yyval.tspec).type)->type_size = int_width;
							((yyval.tspec).type)->next = NULL;	
							
							(yyval.tspec).type_size = int_width;
						}
#line 1504 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 75 "semantics.y" /* yacc.c:1652  */
    {
							(yyval.tspec).type = new type_structure();
							((yyval.tspec).type)->type_name = "float";
							((yyval.tspec).type)->isarr = 0;					// set type attribute
							((yyval.tspec).type)->type_size = float_width;
							((yyval.tspec).type)->next = NULL;	
							
							(yyval.tspec).type_size = float_width;
						}
#line 1518 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 88 "semantics.y" /* yacc.c:1652  */
    {}
#line 1524 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 89 "semantics.y" /* yacc.c:1652  */
    {}
#line 1530 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 92 "semantics.y" /* yacc.c:1652  */
    {}
#line 1536 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 93 "semantics.y" /* yacc.c:1652  */
    {}
#line 1542 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 96 "semantics.y" /* yacc.c:1652  */
    {
															((yyvsp[-2].expr).type)->type_size = symtab_current->offset;
															((yyvsp[-2].expr).address_pointer)->type = (yyvsp[-2].expr).type;
															((yyvsp[-2].expr).address_pointer)->initial_value = "---";
															diff = ((yyvsp[-2].expr).type)->type_size - ((yyvsp[-2].expr).address_pointer)->sym_size;
															//($2.address_pointer)->sym_size = ($2.type)->type_size;
															((yyvsp[-2].expr).address_pointer)->func_next = symtab_current;		// save symbol table of this function
															symtab_current = symtab_global;			// restore old symbol table
															
															if((yyvsp[0].after))backpatch((yyvsp[0].after),next_instruction);
														}
#line 1558 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 108 "semantics.y" /* yacc.c:1652  */
    {
															((yyvsp[-1].expr).type)->type_size = symtab_current->offset;
															((yyvsp[-1].expr).address_pointer)->type = (yyvsp[-1].expr).type;
															((yyvsp[-1].expr).address_pointer)->initial_value = "---";
															diff = ((yyvsp[-1].expr).type)->type_size - ((yyvsp[-1].expr).address_pointer)->sym_size;
															//($2.address_pointer)->sym_size = ($2.type)->type_size;
															((yyvsp[-1].expr).address_pointer)->func_next = symtab_current;		// save symbol table of this function
															symtab_current = symtab_global;			// restore old symbol table
															
															if((yyvsp[0].after))backpatch((yyvsp[0].after),next_instruction);		// backpatch last statement of compound statement to next instruction
														}
#line 1574 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 121 "semantics.y" /* yacc.c:1652  */
    {}
#line 1580 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 122 "semantics.y" /* yacc.c:1652  */
    {}
#line 1586 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 126 "semantics.y" /* yacc.c:1652  */
    {}
#line 1592 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 127 "semantics.y" /* yacc.c:1652  */
    {}
#line 1598 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 130 "semantics.y" /* yacc.c:1652  */
    {}
#line 1604 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 131 "semantics.y" /* yacc.c:1652  */
    {
												(yyval.tspec) = (yyvsp[0].tspec);
												T = (yyvsp[0].tspec).type;	// store the type
												W = (yyvsp[0].tspec).type_size;	// store type_size of the type
											}
#line 1614 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 138 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1620 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 139 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[-2].expr);}
#line 1626 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 142 "semantics.y" /* yacc.c:1652  */
    {
												(yyval.expr) = (yyvsp[0].expr);	
												if(((yyvsp[0].expr).type)->type_name=="function"){
													symtab_current = symtab_global;		// restore global symbol table
												}
											}
#line 1637 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 150 "semantics.y" /* yacc.c:1652  */
    {
												if(((yyvsp[-2].expr).type)->isarr==0){
													if((*((yyvsp[0].ini).val))!="")((yyvsp[-2].expr).address_pointer)->initial_value = *((yyvsp[0].ini).val);		// set initial_value in symbol table
													Quadruples::emit(((yyvsp[0].ini).express.address_pointer)->sym_name,((yyvsp[-2].expr).address_pointer)->sym_name);
												}
												else{
													((yyvsp[-2].expr).array)->initial_value = *((yyvsp[0].ini).val);		// set initial_value in symbol table
													if((yyvsp[0].ini).express.top_val==1)Quadruples::emit(((yyvsp[0].ini).express.array)->sym_name,((yyvsp[-2].expr).array)->sym_name);
												}
																					
												(yyval.expr) = (yyvsp[-2].expr);
												if(((yyvsp[-2].expr).type)->type_name=="function"){
													symtab_current = symtab_global;	// restore global symbol table if $1 is of type function
												}	
											}
#line 1657 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 167 "semantics.y" /* yacc.c:1652  */
    {
										if(((yyvsp[0].expr).type)->isarr==0)(yyval.ini).val = new string(((yyvsp[0].expr).address_pointer)->initial_value);		// saving the initial value
										else (yyval.ini).val = new string(((yyvsp[0].expr).array)->initial_value);
										(yyval.ini).express = (yyvsp[0].expr);
									}
#line 1667 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 173 "semantics.y" /* yacc.c:1652  */
    {
										(yyval.ini).express = (yyvsp[-1].ini).express;
										(yyval.ini).val = new string("{"+(*((yyvsp[-1].ini).val))+"}");		// saving the initial value
									}
#line 1676 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 179 "semantics.y" /* yacc.c:1652  */
    {
													(yyval.ini).val = new string(*((yyvsp[-1].ini).val));		// saving the initial value
													(yyval.ini).express = (yyvsp[-1].ini).express;
												}
#line 1685 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 183 "semantics.y" /* yacc.c:1652  */
    {
													(yyval.ini).val = new string((*((yyvsp[-4].ini).val)) + ";" + (*((yyvsp[-1].ini).val)));	// saving the initial value
													(yyval.ini).express = (yyvsp[-4].ini).express;	
												}
#line 1694 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 189 "semantics.y" /* yacc.c:1652  */
    {
													(yyval.ini).val = new string(*((yyvsp[0].ini).val));			// saving the initial value
													(yyval.ini).express = (yyvsp[0].ini).express;
												}
#line 1703 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 193 "semantics.y" /* yacc.c:1652  */
    {
													(yyval.ini).val = new string((*((yyvsp[-2].ini).val)) + "," + (*((yyvsp[0].ini).val)));		// saving the initial value
													(yyval.ini).express = (yyvsp[-2].ini).express;
												}
#line 1712 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 199 "semantics.y" /* yacc.c:1652  */
    {
									(yyval.expr) = (yyvsp[0].expr);
									
									if(((yyval.expr).type)->type_name!="function"){
										if(((yyval.expr).type)->isarr==0){
											// declarator i.e. $1 is a simple declarator
											((yyval.expr).address_pointer)->type = (yyval.expr).type;
											((yyval.expr).address_pointer)->initial_value = "---"; 					// update symbol table entry
											((yyval.expr).address_pointer)->sym_size = ((yyval.expr).type)->type_size;
											symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;
										}
										else{
											// declarator i.e. $1 is of type matrix
											((yyval.expr).array)->type = (yyval.expr).type;
											((yyval.expr).array)->initial_value = "---";					// update symbol table entry
											((yyval.expr).array)->sym_size = ((yyval.expr).type)->type_size;
											symtab_current->offset += ((yyval.expr).array)->sym_size + (2*int_width);
										}
									}
									else{
										// declarator i.e. $1 is of type function
										if(((yyval.expr).address_pointer)->func_next==NULL){
											// function is declared for the first time
											((yyval.expr).address_pointer)->type = (yyval.expr).type;
											((yyval.expr).address_pointer)->initial_value = "---";						// update symbol table entry
											((yyval.expr).address_pointer)->sym_size = 0;	
											((yyval.expr).address_pointer)->func_next = symtab_current;
											symtab_global->offset += ((yyval.expr).address_pointer)->sym_size;
										}
									}
								}
#line 1748 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 234 "semantics.y" /* yacc.c:1652  */
    {
				symtab_current = new symbol_table();	/*create new symbol table*/	
			}
#line 1756 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 239 "semantics.y" /* yacc.c:1652  */
    {
												(yyvsp[0].idt).address_pointer = symtab_current->lookup(*((yyvsp[0].idt).lexeme)); 	// create symbol table entry for identifier
												(yyval.expr).address_pointer = (yyvsp[0].idt).address_pointer;		//
												(yyval.expr).type = T;			//	
												(yyval.expr).array = NULL;		//	set the attributes
												(yyval.expr).point = 0; 			//
											}
#line 1768 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 247 "semantics.y" /* yacc.c:1652  */
    {
												(yyval.expr) = (yyvsp[-1].expr);	
											}
#line 1776 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 250 "semantics.y" /* yacc.c:1652  */
    {
												if(((yyvsp[-3].expr).type)->isarr==1){
													// if $1 is already an array
													type_structure *p = (yyvsp[-3].expr).type->next;
													type_structure *q = (yyvsp[-3].expr).type;
													while(p->next){
														q->type_size *= atoi(((yyvsp[-1].expr).address_pointer)->initial_value.c_str());
														q = p;
														p = p->next;
													}
													q->type_size *= atoi(((yyvsp[-1].expr).address_pointer)->initial_value.c_str());		// update the type of array variable
													
													type_structure *r = new type_structure();
													r->type_name = "array";
													r->arr_num = atoi(((yyvsp[-1].expr).address_pointer)->initial_value.c_str());
													
													r->type_size = r->arr_num * p->type_size;
													r->isarr = 1;
													r->next = p;
													q->next = r;
													(yyval.expr) = (yyvsp[-3].expr);	
												}
												else{
													// if $1 is not an array
													(yyval.expr).type = new type_structure();
													((yyval.expr).type)->type_name = "array";
													((yyval.expr).type)->arr_num = atoi(((yyvsp[-1].expr).address_pointer)->initial_value.c_str());
													
													((yyval.expr).type)->type_size = ((yyval.expr).type)->arr_num * ((yyvsp[-3].expr).type)->type_size;
													((yyval.expr).type)->isarr = 1;
													((yyval.expr).type)->next = (yyvsp[-3].expr).type;			// make the variable of type array
													(yyval.expr).array = (yyvsp[-3].expr).address_pointer;
													(yyvsp[-3].expr).array = (yyvsp[-3].expr).address_pointer;	
													(yyvsp[-3].expr).type = (yyval.expr).type;
												}
												
												symtab_current->deltemp(((yyvsp[-1].expr).address_pointer)->sym_name);	
											}
#line 1819 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 289 "semantics.y" /* yacc.c:1652  */
    {}
#line 1825 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 292 "semantics.y" /* yacc.c:1652  */
    {
												if(((yyvsp[-4].expr).type)->type_name!="function"){
													symtab_current->sym_name = ((yyvsp[-4].expr).address_pointer)->sym_name;	// sym_name of symbol table of this function
													((yyvsp[-4].expr).type)->return_type = new type_structure();
													((yyvsp[-4].expr).type)->return_type->type_name = ((yyvsp[-4].expr).type)->type_name;
													((yyvsp[-4].expr).type)->return_type->type_size = ((yyvsp[-4].expr).type)->type_size;
													((yyvsp[-4].expr).type)->return_type->isarr = ((yyvsp[-4].expr).type)->isarr;
													((yyvsp[-4].expr).type)->return_type->next = ((yyvsp[-4].expr).type)->next;
													
													((yyvsp[-4].expr).type)->type_name = "function";			//
													((yyvsp[-4].expr).type)->type_size = symtab_current->offset;	//
													((yyvsp[-4].expr).type)->isarr = 0;					// set type of this function in global symbol table
													((yyvsp[-4].expr).type)->next = NULL;					//
													
													(yyval.expr) = (yyvsp[-4].expr);
													Quadruples::emit("func","",((yyvsp[-4].expr).address_pointer)->sym_name);
												}
												else{
													symtab_current = ((yyvsp[-4].expr).address_pointer)->func_next;
													(yyval.expr) = (yyvsp[-4].expr);	
													Quadruples::emit("func","",((yyvsp[-4].expr).address_pointer)->sym_name);
												}
											}
#line 1853 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 316 "semantics.y" /* yacc.c:1652  */
    {}
#line 1859 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 319 "semantics.y" /* yacc.c:1652  */
    {
												if(((yyvsp[-3].expr).type)->type_name!="function"){
													symtab_current->sym_name = ((yyvsp[-3].expr).address_pointer)->sym_name;	// sym_name of symbol table of this function
													((yyvsp[-3].expr).type)->return_type = new type_structure();
													((yyvsp[-3].expr).type)->return_type->type_name = ((yyvsp[-3].expr).type)->type_name;
													((yyvsp[-3].expr).type)->return_type->type_size = ((yyvsp[-3].expr).type)->type_size;
													((yyvsp[-3].expr).type)->return_type->isarr = ((yyvsp[-3].expr).type)->isarr;
													((yyvsp[-3].expr).type)->return_type->next = ((yyvsp[-3].expr).type)->next;
													((yyvsp[-3].expr).type)->type_name = "function";			//
													((yyvsp[-3].expr).type)->type_size = symtab_current->offset;	//
													((yyvsp[-3].expr).type)->isarr = 0;					// set type of function in global symbol table
													((yyvsp[-3].expr).type)->next = NULL;					//
												
													(yyval.expr) = (yyvsp[-3].expr);
													Quadruples::emit("func","",((yyvsp[-3].expr).address_pointer)->sym_name);
												}
												else{
													symtab_current = ((yyvsp[-3].expr).address_pointer)->func_next;
													(yyval.expr) = (yyvsp[-3].expr);	
													Quadruples::emit("func","",((yyvsp[-3].expr).address_pointer)->sym_name);
												}
												
											}
#line 1887 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 344 "semantics.y" /* yacc.c:1652  */
    {}
#line 1893 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 347 "semantics.y" /* yacc.c:1652  */
    {}
#line 1899 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 348 "semantics.y" /* yacc.c:1652  */
    {}
#line 1905 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 351 "semantics.y" /* yacc.c:1652  */
    {}
#line 1911 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 353 "semantics.y" /* yacc.c:1652  */
    {}
#line 1917 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 356 "semantics.y" /* yacc.c:1652  */
    {}
#line 1923 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 357 "semantics.y" /* yacc.c:1652  */
    {}
#line 1929 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 361 "semantics.y" /* yacc.c:1652  */
    {	
						(yyval.expr).address_pointer = symbol_table::gentemp();							// generate temporary
						((yyval.expr).address_pointer)->type = new type_structure();							//
						((yyval.expr).address_pointer)->type->type_name = "int";							//
						((yyval.expr).address_pointer)->type->isarr = 0;								// set the type
						((yyval.expr).address_pointer)->type->type_size = int_width;						//
						((yyval.expr).address_pointer)->type->next = NULL;							//
						char str[10];
						sprintf(str,"%d",(yyvsp[0].val_int));									// set initial value
						string str1(str);
						((yyval.expr).address_pointer)->initial_value = str1;
						((yyval.expr).address_pointer)->sym_size = ((yyval.expr).address_pointer)->type->type_size;				// set sym_size
						symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;					// update total offset of the symbol table
						Quadruples::emit(((yyval.expr).address_pointer)->initial_value,((yyval.expr).address_pointer)->sym_name);	// emit Quadruple that represents initialization instruction
						(yyval.expr).type = ((yyval.expr).address_pointer)->type;								// 
						(yyval.expr).array = NULL;										// set the attributes of $$
						(yyval.expr).point = 0;											//
						(yyval.expr).top_val = 0;											//
					}
#line 1953 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 381 "semantics.y" /* yacc.c:1652  */
    {	
						// Check if it is a global variable/function
						symbol_struct *p = symtab_current->find(*((yyvsp[0].idt).lexeme));
						if(p){
							if(p->type->isarr==1){
								//It is an array
								(yyval.expr).array = p;
								(yyval.expr).type = p->type;
								(yyval.expr).address_pointer = symbol_table::gentemp();  		// Temporary for offset of array
								type_structure *t;
								t = new type_structure();
								t->type_name = "int";
								t->isarr = 0;
								t->type_size = int_width;
								t->next = NULL;
								((yyval.expr).address_pointer)->type = t;					// $$.address_pointer stores offset of array
								((yyval.expr).address_pointer)->initial_value = "0";
								((yyval.expr).address_pointer)->sym_size = int_width; 
								symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;	
								Quadruples::emit(((yyval.expr).address_pointer)->initial_value,((yyval.expr).address_pointer)->sym_name);   // Copy instruction for array offset 
							}
							else{
								// Not an array. 
								(yyval.expr).type = p->type;        // Set the attributes of primexp i.e. $$
								(yyval.expr).address_pointer = p;			
								(yyval.expr).array = NULL;
							}
						}
						else{
							// it is a global variable/function
							p = symtab_global->find(*((yyvsp[0].idt).lexeme));
							if(p->type->type_name!="function"){
								if(p->type->isarr==1){
									//It is an array
									(yyval.expr).array = p;
									(yyval.expr).type = p->type;
									(yyval.expr).address_pointer = symbol_table::gentemp();  		// Temporary for offset of array
									type_structure *t;
									t = new type_structure();
									t->type_name = "int";
									t->isarr = 0;
									t->type_size = int_width;
									t->next = NULL;
									((yyval.expr).address_pointer)->type = t;					// $$.address_pointer stores offset of array
									((yyval.expr).address_pointer)->initial_value = "0";
									((yyval.expr).address_pointer)->sym_size = int_width; 
									symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;	
									Quadruples::emit(((yyval.expr).address_pointer)->initial_value,((yyval.expr).address_pointer)->sym_name);   // Copy instruction for array offset 
								}
								else{
									// Not an array. 
									(yyval.expr).address_pointer = p;			
									(yyval.expr).type = p->type;        // Set the attributes of primexp i.e. $$
									(yyval.expr).array = NULL;
								}
							}
							else{
								//Set the attributes of primexp i.e. $$
								(yyval.expr).address_pointer = p;  
								(yyval.expr).type = p->type;
								(yyval.expr).array = NULL;
							}
						}
						
						(yyval.expr).point = 0;
						(yyval.expr).top_val = 0;
					}
#line 2025 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 449 "semantics.y" /* yacc.c:1652  */
    {	
						(yyval.expr).address_pointer = symbol_table::gentemp();							// generate temporary
						((yyval.expr).address_pointer)->type = new type_structure();							//
						((yyval.expr).address_pointer)->type->type_name = "float";						//
						((yyval.expr).address_pointer)->type->isarr = 0;								// set the type
						((yyval.expr).address_pointer)->type->type_size = float_width;					//
						((yyval.expr).address_pointer)->type->next = NULL;							//
						char str[50];
						sprintf(str,"%.3f",(yyvsp[0].val_float));									// set initial value
						string str1(str);
						((yyval.expr).address_pointer)->initial_value = str1;
						((yyval.expr).address_pointer)->sym_size = ((yyval.expr).address_pointer)->type->type_size;				// set sym_size
						symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;					// update total offset of the symbol table
						Quadruples::emit(((yyval.expr).address_pointer)->initial_value,((yyval.expr).address_pointer)->sym_name);	// emit Quadruple that represents initialization instruction
						(yyval.expr).type = ((yyval.expr).address_pointer)->type;								//
						(yyval.expr).array = NULL;										// set the attributes of $$
						(yyval.expr).point = 0;											//
						(yyval.expr).top_val = 0;											//
					}
#line 2049 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 468 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[-1].expr);}
#line 2055 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 471 "semantics.y" /* yacc.c:1652  */
    {
										(yyval.expr) = (yyvsp[0].expr);
										if((yyval.expr).array)(yyval.expr).top_val = 1;			// a matrix operation may be performed
									}
#line 2064 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 476 "semantics.y" /* yacc.c:1652  */
    {	
										(yyval.expr).array = (yyvsp[-3].expr).array;				// set base address of array
										(yyval.expr).type = (yyvsp[-3].expr).type->next;			// set type
										(yyval.expr).point = (yyvsp[-3].expr).point;
										(yyval.expr).top_val = 0;						// matrix operation is not being performed
										(yyvsp[-3].expr).top_val = 0;
										
										(yyval.expr).address_pointer = symbol_table::gentemp();						// generate temporary for offset of array	
										((yyval.expr).address_pointer)->type = new type_structure();						//
										((yyval.expr).address_pointer)->type->type_name = "int";						//
										((yyval.expr).address_pointer)->type->isarr = 0;							// set type
										((yyval.expr).address_pointer)->type->type_size = int_width;					//
										((yyval.expr).address_pointer)->type->next = NULL;						//
										((yyval.expr).address_pointer)->sym_size = int_width;						// set sym_size
										symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;				// update total offset of symbol table

										symbol_struct *t = symbol_table::gentemp();					// generate temporary
										t->type = new type_structure();								//
										t->type->type_name = "int";								//
										t->type->isarr = 0;									// set type
										t->type->type_size = int_width;							//
										t->type->next = NULL;								//
										t->sym_size = int_width;								// set sym_size
										symtab_current->offset += t->sym_size;						// update total offset of symbol table
										
										char str[10];
										sprintf(str,"%d",((yyval.expr).type)->type_size);
										
										Quadruples::emit("*",str,((yyvsp[-1].expr).address_pointer)->sym_name,t->sym_name);				// Quadruple to set the value
										Quadruples::emit("+",((yyvsp[-3].expr).address_pointer)->sym_name,t->sym_name,((yyval.expr).address_pointer)->sym_name); // of array offset					
									}
#line 2100 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 508 "semantics.y" /* yacc.c:1652  */
    {	
										(yyval.expr).address_pointer = symbol_table::gentemp();					// generate temporary
										((yyval.expr).address_pointer)->type = ((yyvsp[-3].expr).type)->return_type;				// set type
										((yyval.expr).address_pointer)->sym_size = ((yyvsp[-3].expr).type)->return_type->type_size;		// set sym_size
										(yyval.expr).type = ((yyvsp[-3].expr).type)->return_type;						// 			
										(yyval.expr).array = NULL;								// set attributes of $$ 
										(yyval.expr).point = (yyvsp[-3].expr).point;							//
										(yyval.expr).top_val = 0;									// matrix operation is not being performed
										(yyvsp[-3].expr).top_val = 0;									//
										
										// update total offset of symbol table
										if(((yyval.expr).address_pointer)->sym_size>=0)symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;			
										
										param_list *p = (yyvsp[-1].plist).head;
										
										while(p){
											Quadruples::emit("param","",p->express.address_pointer->sym_name);	// emit quads of function parameters
											p = p->next;
										}
										
										char str[10];
										sprintf(str,"%d",(yyvsp[-1].plist).pnum);
										Quadruples::emit("call",((yyvsp[-3].expr).address_pointer)->sym_name,str,((yyval.expr).address_pointer)->sym_name);	// emit Quadruple of function call
									}
#line 2129 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 533 "semantics.y" /* yacc.c:1652  */
    {	
										(yyval.expr).address_pointer = symbol_table::gentemp();					// generate temporary
										((yyval.expr).address_pointer)->type = ((yyvsp[-2].expr).type)->return_type;				// set type
										((yyval.expr).address_pointer)->sym_size = ((yyvsp[-2].expr).type)->return_type->type_size;		// set sym_size
										(yyval.expr).type = ((yyvsp[-2].expr).type)->return_type;						//
										(yyval.expr).array = NULL;								// set attributes
										(yyval.expr).point = (yyvsp[-2].expr).point;							//
										(yyval.expr).top_val = 0;									// matrix operation is not being performed
										(yyvsp[-2].expr).top_val = 0;									//
										
										// update total offset of symbol table
										if(((yyval.expr).address_pointer)->sym_size>=0)symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;			
										
										Quadruples::emit("call",((yyvsp[-2].expr).address_pointer)->sym_name,"0",((yyval.expr).address_pointer)->sym_name);	// emit Quadruple of function call
									}
#line 2149 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 549 "semantics.y" /* yacc.c:1652  */
    {}
#line 2155 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 551 "semantics.y" /* yacc.c:1652  */
    {	
										(yyval.expr).address_pointer = symbol_table::gentemp();					// generate temporary
										((yyval.expr).address_pointer)->type = (yyvsp[-1].expr).type;						// set type
										((yyval.expr).address_pointer)->sym_size = ((yyvsp[-1].expr).type)->type_size;				// set sym_size
										(yyval.expr).type = (yyvsp[-1].expr).type;								//
										(yyval.expr).array = NULL;								// set attributes
										(yyval.expr).point = (yyvsp[-1].expr).point;							//
										(yyval.expr).top_val = 0;									// matrix operation is not being performed
										(yyvsp[-1].expr).top_val = 0;									//
										symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;
										
										symbol_struct *t = symbol_table::gentemp();
										t->type = (yyvsp[-1].expr).type;	
										t->sym_size = ((yyvsp[-1].expr).type)->type_size;	
										symtab_current->offset += t->sym_size;
										
										if((yyvsp[-1].expr).array){
											// emit quads of indexed copy and arithmetic instructions
											Quadruples::emit("rindexed",((yyvsp[-1].expr).array)->sym_name,((yyvsp[-1].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);
											Quadruples::emit("rindexed",((yyvsp[-1].expr).array)->sym_name,((yyvsp[-1].expr).address_pointer)->sym_name,t->sym_name);
											Quadruples::emit("+",t->sym_name,"1",t->sym_name);
											Quadruples::emit("lindexed",((yyvsp[-1].expr).address_pointer)->sym_name,t->sym_name,((yyvsp[-1].expr).array)->sym_name);
										}
										else{
											// emit quads of arithmetic and copy instructions
											Quadruples::emit(((yyvsp[-1].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);
											Quadruples::emit("+",((yyvsp[-1].expr).address_pointer)->sym_name,"1",t->sym_name);
											Quadruples::emit(t->sym_name,((yyvsp[-1].expr).address_pointer)->sym_name);
										}																	
									}
#line 2190 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 582 "semantics.y" /* yacc.c:1652  */
    {	
										(yyval.expr).address_pointer = symbol_table::gentemp();
										((yyval.expr).address_pointer)->type = (yyvsp[-1].expr).type;	
										((yyval.expr).address_pointer)->sym_size = ((yyvsp[-1].expr).type)->type_size;
										(yyval.expr).type = (yyvsp[-1].expr).type;
										(yyval.expr).array = NULL;
										(yyval.expr).point = (yyvsp[-1].expr).point;	
										(yyval.expr).top_val = 0;									// matrix operation is not being performed
										(yyvsp[-1].expr).top_val = 0;									//
										symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;
										
										symbol_struct *t = symbol_table::gentemp();
										t->type = (yyvsp[-1].expr).type;	
										t->sym_size = ((yyvsp[-1].expr).type)->type_size;	
										symtab_current->offset += t->sym_size;
										
										if((yyvsp[-1].expr).array){
											// emit quads of indexed copy and arithmetic instructions
											Quadruples::emit("rindexed",((yyvsp[-1].expr).array)->sym_name,((yyvsp[-1].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);
											Quadruples::emit("rindexed",((yyvsp[-1].expr).array)->sym_name,((yyvsp[-1].expr).address_pointer)->sym_name,t->sym_name);
											Quadruples::emit("-",t->sym_name,"1",t->sym_name);
											Quadruples::emit("lindexed",((yyvsp[-1].expr).address_pointer)->sym_name,t->sym_name,((yyvsp[-1].expr).array)->sym_name);
										}
										else{
											// emit quads of arithmetic and copy instructions
											Quadruples::emit(((yyvsp[-1].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);
											Quadruples::emit("-",((yyvsp[-1].expr).address_pointer)->sym_name,"1",t->sym_name);
											Quadruples::emit(t->sym_name,((yyvsp[-1].expr).address_pointer)->sym_name);
										}
									}
#line 2225 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 614 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2231 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 616 "semantics.y" /* yacc.c:1652  */
    {	
										(yyval.expr).address_pointer = symbol_table::gentemp();				// generate temporary
										((yyval.expr).address_pointer)->type = (yyvsp[0].expr).type;					// set type in the symbol table
										((yyval.expr).address_pointer)->sym_size = ((yyvsp[0].expr).type)->type_size;			// set sym_size in the symbol table
										(yyval.expr).type = (yyvsp[0].expr).type;							//
										(yyval.expr).array = NULL;							// set attributes of $$
										(yyval.expr).point = (yyvsp[0].expr).point;						//
										(yyval.expr).top_val = (yyvsp[0].expr).top_val;						//
										symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;		// update total offset in symbol table
										
										symbol_struct *t = symbol_table::gentemp();
										t->type = (yyvsp[0].expr).type;	
										t->sym_size = ((yyvsp[0].expr).type)->type_size;	
										symtab_current->offset += t->sym_size;
										
										if((yyvsp[0].expr).array){
											// emit quads of indexed copy and arithmetic instructions
											Quadruples::emit("rindexed",((yyvsp[0].expr).array)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,t->sym_name);
											Quadruples::emit("+",t->sym_name,"1",t->sym_name);
											Quadruples::emit("lindexed",((yyvsp[0].expr).address_pointer)->sym_name,t->sym_name,((yyvsp[0].expr).array)->sym_name);
											Quadruples::emit(t->sym_name,((yyval.expr).address_pointer)->sym_name);
										}
										else{
											// emit quads of arithmetic and copy instructions
											Quadruples::emit("+",((yyvsp[0].expr).address_pointer)->sym_name,"1",t->sym_name);
											Quadruples::emit(t->sym_name,((yyvsp[0].expr).address_pointer)->sym_name);
											Quadruples::emit(t->sym_name,((yyval.expr).address_pointer)->sym_name);
										}
									}
#line 2265 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 646 "semantics.y" /* yacc.c:1652  */
    {	
										(yyval.expr).address_pointer = symbol_table::gentemp();				// generate temporary
										((yyval.expr).address_pointer)->type = (yyvsp[0].expr).type;					// set type in the symbol table
										((yyval.expr).address_pointer)->sym_size = ((yyvsp[0].expr).type)->type_size;			// set sym_size in the symbol table
										(yyval.expr).type = (yyvsp[0].expr).type;							//
										(yyval.expr).array = NULL;							// set attributes of $$
										(yyval.expr).point = (yyvsp[0].expr).point;						//
										(yyval.expr).top_val = (yyvsp[0].expr).top_val;						//
										symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;		// update total offset in symbol table
										
										symbol_struct *t = symbol_table::gentemp();
										t->type = (yyvsp[0].expr).type;	
										t->sym_size = ((yyvsp[0].expr).type)->type_size;	
										symtab_current->offset += t->sym_size;
										
										if((yyvsp[0].expr).array){
											// emit quads of indexed copy and arithmetic instructions
											Quadruples::emit("rindexed",((yyvsp[0].expr).array)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,t->sym_name);
											Quadruples::emit("-",t->sym_name,"1",t->sym_name);
											Quadruples::emit("lindexed",((yyvsp[0].expr).address_pointer)->sym_name,t->sym_name,((yyvsp[0].expr).array)->sym_name);
											Quadruples::emit(t->sym_name,((yyval.expr).address_pointer)->sym_name);
										}
										else{
											// emit quads of arithmetic and copy instructions
											Quadruples::emit("-",((yyvsp[0].expr).address_pointer)->sym_name,"1",t->sym_name);
											Quadruples::emit(t->sym_name,((yyvsp[0].expr).address_pointer)->sym_name);
											Quadruples::emit(t->sym_name,((yyval.expr).address_pointer)->sym_name);
										}
									}
#line 2299 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 676 "semantics.y" /* yacc.c:1652  */
    {	
										switch((yyvsp[-1].val_char)){
											case '+':
												(yyval.expr).address_pointer = symbol_table::gentemp();	// generate temporary 
												((yyval.expr).address_pointer)->type = (yyvsp[0].expr).type;		// set the address attribute
												((yyval.expr).address_pointer)->sym_size = ((yyvsp[0].expr).type)->type_size;		//
												if(((yyvsp[0].expr).address_pointer)->initial_value!="")((yyval.expr).address_pointer)->initial_value = "+" + ((yyvsp[0].expr).address_pointer)->initial_value;
												symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;		// update total offset of symbol table
												
												(yyval.expr).array = NULL;		//
												(yyval.expr).type = (yyvsp[0].expr).type;      // set other attributes
												(yyval.expr).point = (yyvsp[0].expr).point;	//
												(yyval.expr).top_val = (yyvsp[0].expr).top_val;	//
												
												Quadruples::emit("+",((yyvsp[0].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);	// emit Quadruple for unary plus
												break;
											
																								
											case '-':
												(yyval.expr).address_pointer = symbol_table::gentemp();	// generate temporary 
												((yyval.expr).address_pointer)->type = (yyvsp[0].expr).type;		// set the address attribute
												((yyval.expr).address_pointer)->sym_size = ((yyvsp[0].expr).type)->type_size;	//
												if(((yyvsp[0].expr).address_pointer)->initial_value!="")((yyval.expr).address_pointer)->initial_value = "-" + ((yyvsp[0].expr).address_pointer)->initial_value;
												symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;	// update total offset of symbol table
												
												(yyval.expr).array = NULL;		//
												(yyval.expr).type = (yyvsp[0].expr).type;		// set other attributes
												(yyval.expr).point = (yyvsp[0].expr).point;	//
												(yyval.expr).top_val = (yyvsp[0].expr).top_val;	//
												
												Quadruples::emit("-",((yyvsp[0].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);	// emit Quadruple for unary minus
												break;
												
											case '*':
												(yyval.expr).address_pointer = (yyvsp[0].expr).address_pointer;				// set address_pointer attribute						
												(yyval.expr).array = NULL;				// set array attribute	
												(yyval.expr).type = ((yyvsp[0].expr).type)->next;		// set type attribute
												(yyval.expr).point = 1;					// set point attribute
												(yyval.expr).top_val = (yyvsp[0].expr).top_val;			//
												break;
										}
									}
#line 2346 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 720 "semantics.y" /* yacc.c:1652  */
    {(yyval.val_char) = '*';}
#line 2352 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 721 "semantics.y" /* yacc.c:1652  */
    {(yyval.val_char) = '+';}
#line 2358 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 722 "semantics.y" /* yacc.c:1652  */
    {(yyval.val_char) = '-';}
#line 2364 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 725 "semantics.y" /* yacc.c:1652  */
    {	
										if((yyvsp[0].expr).array){
											if((yyvsp[0].expr).top_val==0){
												// if unaryexp is an array
												(yyval.expr).address_pointer = symbol_table::gentemp();
												((yyval.expr).address_pointer)->type = (yyvsp[0].expr).type;
												((yyval.expr).address_pointer)->sym_size = ((yyvsp[0].expr).type)->type_size;
												symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;
											
												(yyval.expr).array = NULL;
												(yyval.expr).type = (yyvsp[0].expr).type;
												(yyval.expr).point = (yyvsp[0].expr).point;
												(yyval.expr).top_val = (yyvsp[0].expr).top_val;
											
												// emit Quadruple of right indexed copy instruction
												Quadruples::emit("rindexed",((yyvsp[0].expr).array)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);
											}
											else (yyval.expr) = (yyvsp[0].expr);
										}
										else{
												(yyval.expr) = (yyvsp[0].expr);
											}
										}
#line 2392 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 751 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2398 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 753 "semantics.y" /* yacc.c:1652  */
    {
										typecheck(&((yyvsp[-2].expr)),&((yyvsp[0].expr)));					// check the types
										(yyval.expr).address_pointer = symbol_table::gentemp();
										((yyval.expr).address_pointer)->type = (yyvsp[-2].expr).type;
										((yyval.expr).address_pointer)->sym_size = ((yyvsp[-2].expr).type)->type_size;
										symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;
										
										(yyval.expr).type = (yyvsp[-2].expr).type;			//
										(yyval.expr).array = (yyvsp[-2].expr).array;		// set other attributes
										(yyval.expr).point = (yyvsp[-2].expr).point;		//
										(yyval.expr).top_val = (yyvsp[-2].expr).top_val;		//
										
										if((yyvsp[-2].expr).top_val==1 && (yyvsp[0].expr).top_val==1){
											(yyval.expr).array = (yyval.expr).address_pointer;
											(yyval.expr).type = new type_structure();			// set type of transpose of postexp i.e. $1
											((yyval.expr).type)->type_name = "array";
											((yyval.expr).type)->type_size = ((yyvsp[-2].expr).type)->arr_num * ((yyvsp[0].expr).type)->next->arr_num * ((yyvsp[0].expr).type)->next->next->type_size;
											((yyval.expr).type)->isarr = 1;
											((yyval.expr).type)->arr_num = ((yyvsp[-2].expr).type)->arr_num; 		// row number of $$ matrix is same as $1 matrix
											((yyval.expr).type)->next = new type_structure();						
											((yyval.expr).type)->next->type_name = "array"; 
											((yyval.expr).type)->next->arr_num = ((yyvsp[0].expr).type)->next->arr_num;		// col number of $$ matrix is same as $3 matrix
											((yyval.expr).type)->next->type_size = ((yyval.expr).type)->next->arr_num * ((yyvsp[-2].expr).type)->next->next->type_size;
											((yyval.expr).type)->next->isarr = 1;
											((yyval.expr).type)->next->next = new type_structure();
											((yyval.expr).type)->next->next->type_name = ((yyvsp[-2].expr).type)->next->next->type_name;
											((yyval.expr).type)->next->next->type_size = ((yyvsp[-2].expr).type)->next->next->type_size;
											((yyval.expr).type)->next->next->next = NULL;
											((yyval.expr).type)->next->next->isarr = 0;
										
											((yyval.expr).array)->type = (yyval.expr).type;						//
											symtab_current->offset -= ((yyval.expr).array)->sym_size;		// subtract old sym_size
											((yyval.expr).array)->sym_size = ((yyval.expr).type)->type_size;			// set new sym_size
											symtab_current->offset += ((yyval.expr).array)->sym_size;		// add new sym_size
											
											// emit Quadruple of matrix multiplication instruction 
											Quadruples::emit("*",((yyvsp[-2].expr).array)->sym_name,((yyvsp[0].expr).array)->sym_name,((yyval.expr).array)->sym_name);
										}
										else{
											// emit Quadruple of multiplication instruction 
											Quadruples::emit("*",((yyvsp[-2].expr).address_pointer)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);
										}
									}
#line 2446 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 797 "semantics.y" /* yacc.c:1652  */
    {
										typecheck(&(yyvsp[-2].expr),&(yyvsp[0].expr));					// check the types
										(yyval.expr).address_pointer = symbol_table::gentemp();
										((yyval.expr).address_pointer)->type = (yyvsp[-2].expr).type;
										((yyval.expr).address_pointer)->sym_size = ((yyvsp[-2].expr).type)->type_size;
										symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;
										
										(yyval.expr).type = (yyvsp[-2].expr).type;			//
										(yyval.expr).array = (yyvsp[-2].expr).array;		// set other attributes
										(yyval.expr).point = (yyvsp[-2].expr).point;		//
										(yyval.expr).top_val = (yyvsp[-2].expr).top_val;		//
										
										if((yyvsp[-2].expr).top_val==1 && (yyvsp[0].expr).top_val==1){
											(yyval.expr).array = (yyval.expr).address_pointer; 
											Quadruples::emit("/",((yyvsp[-2].expr).array)->sym_name,((yyvsp[0].expr).array)->sym_name,((yyval.expr).array)->sym_name);
										}
										else{
											// emit Quadruple of division instruction
											Quadruples::emit("/",((yyvsp[-2].expr).address_pointer)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);
										}	
									}
#line 2472 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 819 "semantics.y" /* yacc.c:1652  */
    {
										typecheck(&(yyvsp[-2].expr),&(yyvsp[0].expr));					// check the types
										(yyval.expr).address_pointer = symbol_table::gentemp();
										((yyval.expr).address_pointer)->type = (yyvsp[-2].expr).type;
										((yyval.expr).address_pointer)->sym_size = ((yyvsp[-2].expr).type)->type_size;
										symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;
										
										(yyval.expr).type = (yyvsp[-2].expr).type;			//
										(yyval.expr).array = (yyvsp[-2].expr).array;		// set other attributes
										(yyval.expr).point = (yyvsp[-2].expr).point;		//
										(yyval.expr).top_val = (yyvsp[-2].expr).top_val;		//
										
										if((yyvsp[-2].expr).top_val==1 && (yyvsp[0].expr).top_val==1){
											(yyval.expr).array = (yyval.expr).address_pointer;
											Quadruples::emit("%",((yyvsp[-2].expr).array)->sym_name,((yyvsp[0].expr).array)->sym_name,((yyval.expr).array)->sym_name);
										}
										else{
											// emit Quadruple of modulo instruction
											Quadruples::emit("%",((yyvsp[-2].expr).address_pointer)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);
										}	
									}
#line 2498 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 842 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2504 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 844 "semantics.y" /* yacc.c:1652  */
    {
										typecheck(&(yyvsp[-2].expr),&(yyvsp[0].expr));					// check the types
										(yyval.expr).address_pointer = symbol_table::gentemp();
										((yyval.expr).address_pointer)->type = (yyvsp[-2].expr).type;
										((yyval.expr).address_pointer)->sym_size = ((yyvsp[-2].expr).type)->type_size;
										symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;
										
										(yyval.expr).type = (yyvsp[-2].expr).type;			//
										(yyval.expr).array = (yyvsp[-2].expr).array;		// set other attributes
										(yyval.expr).point = (yyvsp[-2].expr).point;		//
										(yyval.expr).top_val = (yyvsp[-2].expr).top_val;		//
										
										if((yyvsp[-2].expr).top_val==1 && (yyvsp[0].expr).top_val==1){
											(yyval.expr).array = (yyval.expr).address_pointer;
											
											// emit Quadruple of matrix addition instruction
											Quadruples::emit("+",((yyvsp[-2].expr).array)->sym_name,((yyvsp[0].expr).array)->sym_name,((yyval.expr).array)->sym_name);
										}
										else{
											// emit Quadruple of addition instruction
											Quadruples::emit("+",((yyvsp[-2].expr).address_pointer)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);
										}	
									}
#line 2532 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 868 "semantics.y" /* yacc.c:1652  */
    {
										typecheck(&(yyvsp[-2].expr),&(yyvsp[0].expr));					// check the types
										(yyval.expr).address_pointer = symbol_table::gentemp();
										((yyval.expr).address_pointer)->type = (yyvsp[-2].expr).type;
										((yyval.expr).address_pointer)->sym_size = ((yyvsp[-2].expr).type)->type_size;
										symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;
										
										(yyval.expr).type = (yyvsp[-2].expr).type;			//
										(yyval.expr).array = (yyvsp[-2].expr).array;		// set other attributes
										(yyval.expr).point = (yyvsp[-2].expr).point;		//
										(yyval.expr).top_val = (yyvsp[-2].expr).top_val;		//
										
										if((yyvsp[-2].expr).top_val==1 && (yyvsp[0].expr).top_val==1){
											(yyval.expr).array = (yyval.expr).address_pointer;
											
											// emit Quadruple of matrix subtraction instruction
											Quadruples::emit("-",((yyvsp[-2].expr).array)->sym_name,((yyvsp[0].expr).array)->sym_name,((yyval.expr).array)->sym_name);
										}
										else{
											// emit Quadruple of subtraction instruction
											Quadruples::emit("-",((yyvsp[-2].expr).address_pointer)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);
										}
									}
#line 2560 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 893 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2566 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 896 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2572 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 898 "semantics.y" /* yacc.c:1652  */
    {
										typecheck(&(yyvsp[-2].expr),&(yyvsp[0].expr));					// check the types
										(yyval.expr).type = new type_structure();
										((yyval.expr).type)->type_name = "bool";
										((yyval.expr).type)->type_size = bool_width;
										((yyval.expr).type)->next = NULL;
										((yyval.expr).type)->isarr = 0;
										
										(yyval.expr).true_list = makelist(next_instruction);			// generate true_list of $$
										
										// emit Quadruple of if x<y goto _ instruction
										Quadruples::emit("iflt",((yyvsp[-2].expr).address_pointer)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,"_");
										
										(yyval.expr).false_list = makelist(next_instruction);		// generate false_list of $$
										Quadruples::emit("_");	
									}
#line 2593 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 915 "semantics.y" /* yacc.c:1652  */
    {
										typecheck(&(yyvsp[-2].expr),&(yyvsp[0].expr));					// check the types
										(yyval.expr).type = new type_structure();
										((yyval.expr).type)->type_name = "bool";
										((yyval.expr).type)->type_size = bool_width;
										((yyval.expr).type)->next = NULL;
										((yyval.expr).type)->isarr = 0;
										
										(yyval.expr).true_list = makelist(next_instruction);			// generate true_list of $$
										
										// emit Quadruple of if x>y goto _ instruction
										Quadruples::emit("ifgt",((yyvsp[-2].expr).address_pointer)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,"_");
										
										(yyval.expr).false_list = makelist(next_instruction);		// generate false_list of $$
										Quadruples::emit("_");	
									}
#line 2614 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 932 "semantics.y" /* yacc.c:1652  */
    {
										typecheck(&(yyvsp[-2].expr),&(yyvsp[0].expr));					// check the types
										(yyval.expr).type = new type_structure();
										((yyval.expr).type)->type_name = "bool";
										((yyval.expr).type)->type_size = bool_width;
										((yyval.expr).type)->next = NULL;
										((yyval.expr).type)->isarr = 0;
										
										(yyval.expr).true_list = makelist(next_instruction);			// generate true_list of $$
										
										// emit Quadruple of if x<=y goto _ instruction
										Quadruples::emit("iflte",((yyvsp[-2].expr).address_pointer)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,"_");
										
										(yyval.expr).false_list = makelist(next_instruction);		// generate false_list of $$
										Quadruples::emit("_");	
									}
#line 2635 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 949 "semantics.y" /* yacc.c:1652  */
    {
										typecheck(&(yyvsp[-2].expr),&(yyvsp[0].expr));						// check the types
										(yyval.expr).type = new type_structure();
										((yyval.expr).type)->type_name = "bool";
										((yyval.expr).type)->type_size = bool_width;
										((yyval.expr).type)->next = NULL;
										((yyval.expr).type)->isarr = 0;
										
										(yyval.expr).true_list = makelist(next_instruction);			// generate true_list of $$
										
										// emit Quadruple of if x>=y goto _ instruction
										Quadruples::emit("ifgte",((yyvsp[-2].expr).address_pointer)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,"_");
										
										(yyval.expr).false_list = makelist(next_instruction);		// generate false_list of $$
										Quadruples::emit("_");	
									}
#line 2656 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 967 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2662 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 969 "semantics.y" /* yacc.c:1652  */
    {
										typecheck(&(yyvsp[-2].expr),&(yyvsp[0].expr));						// check the types
										(yyval.expr).type = new type_structure();
										((yyval.expr).type)->type_name = "bool";
										((yyval.expr).type)->type_size = bool_width;
										((yyval.expr).type)->next = NULL;
										((yyval.expr).type)->isarr = 0;
										
										(yyval.expr).true_list = makelist(next_instruction);			// generate true_list of $$
										
										// emit Quadruple of if x==y goto _ instruction
										Quadruples::emit("ifeq",((yyvsp[-2].expr).address_pointer)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,"_");
										
										(yyval.expr).false_list = makelist(next_instruction);		// generate false_list of $$
										Quadruples::emit("_");	
									}
#line 2683 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 986 "semantics.y" /* yacc.c:1652  */
    {
										typecheck(&(yyvsp[-2].expr),&(yyvsp[0].expr));						// check the types
										(yyval.expr).type = new type_structure();
										((yyval.expr).type)->type_name = "bool";
										((yyval.expr).type)->type_size = bool_width;
										((yyval.expr).type)->next = NULL;
										((yyval.expr).type)->isarr = 0;
										
										(yyval.expr).true_list = makelist(next_instruction);			// generate true_list of $$
										
										// emit Quadruple of if x!=y goto _ instruction
										Quadruples::emit("ifneq",((yyvsp[-2].expr).address_pointer)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,"_");
										
										(yyval.expr).false_list = makelist(next_instruction);		// generate false_list of $$
										Quadruples::emit("_");	
									}
#line 2704 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 1004 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2710 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 1007 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2716 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 1010 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2722 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 1013 "semantics.y" /* yacc.c:1652  */
    {
										(yyval.dummy) = next_instruction; // store the quad_val of next instruction
									}
#line 2730 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 1018 "semantics.y" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2736 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 1020 "semantics.y" /* yacc.c:1652  */
    {
										convtobool(&(yyvsp[0].expr));			// convert expression to boolean
										convtobool(&(yyvsp[-3].expr));			// convert expression to boolean
										
										(yyval.expr).type = new type_structure();
										((yyval.expr).type)->type_name = "bool";
										((yyval.expr).type)->type_size = bool_width;
										((yyval.expr).type)->next = NULL;
										((yyval.expr).type)->isarr = 0;	
										
										backpatch((yyvsp[-3].expr).true_list,(yyvsp[-1].dummy));	
										(yyval.expr).true_list = (yyvsp[0].expr).true_list;							// generate true_list of $$
										(yyval.expr).false_list = merge((yyvsp[-3].expr).false_list,(yyvsp[0].expr).false_list);	// generate false_list of $$
									}
#line 2755 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 1036 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2761 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 1038 "semantics.y" /* yacc.c:1652  */
    {
										convtobool(&(yyvsp[0].expr));				// convert expression to boolean
										convtobool(&(yyvsp[-3].expr));				// convert expression to boolean
										
										(yyval.expr).type = new type_structure();
										((yyval.expr).type)->type_name = "bool";
										((yyval.expr).type)->type_size = bool_width;
										((yyval.expr).type)->next = NULL;
										((yyval.expr).type)->isarr = 0;	
										
										backpatch((yyvsp[-3].expr).false_list,(yyvsp[-1].dummy));
										(yyval.expr).false_list = (yyvsp[0].expr).false_list;						// generate false_list of $$
										(yyval.expr).true_list = merge((yyvsp[-3].expr).true_list,(yyvsp[0].expr).true_list);		// generate true_list of $$
									}
#line 2780 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 1054 "semantics.y" /* yacc.c:1652  */
    {
										// generates goto instruction to jump to some specific Quadruple. Mostly used in if-else statements
										(yyval.after) = makelist(next_instruction); 
										Quadruples::emit("_");
									}
#line 2790 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 1061 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2796 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 1064 "semantics.y" /* yacc.c:1652  */
    {
											convtobool(&(yyvsp[-4].expr));				// convert expression to boolean
											(yyval.expr).address_pointer = symbol_table::gentemp();
											((yyval.expr).address_pointer)->type = (yyvsp[-2].expr).type;
											((yyval.expr).address_pointer)->sym_size = ((yyvsp[-2].expr).type)->type_size;
											symtab_current->offset += ((yyval.expr).address_pointer)->sym_size;
											
											(yyval.expr).type = (yyvsp[-2].expr).type;			//
											(yyval.expr).array = (yyvsp[-2].expr).array;		// set other attributes
											(yyval.expr).point = (yyvsp[-2].expr).point;		//
											(yyval.expr).top_val = (yyvsp[-2].expr).top_val;		//
											
											backpatch((yyvsp[-4].expr).true_list,next_instruction);		// if $1 is true jump to [t = exp (i.e. $4)]
											backpatch((yyvsp[-4].expr).false_list,next_instruction+2);	// if $1 is false jump to [t = condexp (i.e. $7)]		
											
											if((yyvsp[-2].expr).top_val==1 && (yyvsp[0].expr).top_val==1){
												(yyval.expr).array = (yyval.expr).address_pointer;
											
												// emit Quadruple of matrix copy instruction
												Quadruples::emit(((yyvsp[-2].expr).array)->sym_name,((yyval.expr).array)->sym_name);
											}
											else{
												// emit Quadruple of copy instruction
												Quadruples::emit(((yyvsp[-2].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);
											}
											
											char str[10];
											sprintf(str,"%d",next_instruction+2);
											string str1(str);
											Quadruples::emit(str);		// jump to instruction at next_instruction+1 if $$ is assigned to $3
											
											if((yyvsp[-2].expr).top_val==1 && (yyvsp[0].expr).top_val==1){
												(yyval.expr).array = (yyval.expr).address_pointer;
											
												// emit Quadruple of matrix copy instruction
												Quadruples::emit(((yyvsp[0].expr).array)->sym_name,((yyval.expr).array)->sym_name);
											}
											else{
												// emit Quadruple of copy instruction
												Quadruples::emit(((yyvsp[0].expr).address_pointer)->sym_name,((yyval.expr).address_pointer)->sym_name);
											}
										}
#line 2843 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 1108 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2849 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 1110 "semantics.y" /* yacc.c:1652  */
    {
										if((yyvsp[-2].expr).point==0){
											
											if((yyvsp[-2].expr).array){
												typecheck(&(yyvsp[-2].expr),&(yyvsp[0].expr));
												// emit Quadruple of matrix copy instruction
												if((yyvsp[-2].expr).top_val==1 && (yyvsp[0].expr).top_val==1)Quadruples::emit(((yyvsp[0].expr).array)->sym_name,((yyvsp[-2].expr).array)->sym_name);
												// emit Quadruple of left indexed copy instruction
												else Quadruples::emit("lindexed",((yyvsp[-2].expr).address_pointer)->sym_name,((yyvsp[0].expr).address_pointer)->sym_name,((yyvsp[-2].expr).array)->sym_name);
											}
											else{
												typecheck(&(yyvsp[-2].expr),&(yyvsp[0].expr));
												// emit Quadruple of copy instruction
												Quadruples::emit(((yyvsp[0].expr).address_pointer)->sym_name,((yyvsp[-2].expr).address_pointer)->sym_name);
											}
										}
										else{
											// emit Quadruple of left dereference instruction
											Quadruples::emit("ldref",((yyvsp[0].expr).address_pointer)->sym_name,((yyvsp[-2].expr).address_pointer)->sym_name);
										}
										
										(yyval.expr) = (yyvsp[-2].expr);
									}
#line 2877 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 1135 "semantics.y" /* yacc.c:1652  */
    {}
#line 2883 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 1136 "semantics.y" /* yacc.c:1652  */
    {}
#line 2889 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 1137 "semantics.y" /* yacc.c:1652  */
    {}
#line 2895 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 1138 "semantics.y" /* yacc.c:1652  */
    {}
#line 2901 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 1139 "semantics.y" /* yacc.c:1652  */
    {}
#line 2907 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 1140 "semantics.y" /* yacc.c:1652  */
    {}
#line 2913 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 1143 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2919 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 1144 "semantics.y" /* yacc.c:1652  */
    {}
#line 2925 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 1147 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2931 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 1150 "semantics.y" /* yacc.c:1652  */
    {	
										// Insertion of $1 in quad_list of expressions in $$
										(yyval.plist).head = new param_list();
										((yyval.plist).head)->express = (yyvsp[0].expr);
										((yyval.plist).head)->next = NULL;
										(yyval.plist).pnum = 1;
									}
#line 2943 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 1158 "semantics.y" /* yacc.c:1652  */
    {	
										// Insertion of $3 at the end of quad_list of expressions in $$
										param_list *p,*q;	
										p = (yyvsp[-2].plist).head;	
										q = p;		
										while(p){
											q = p;
											p = p->next;
										}	
										
										p = new param_list();
										p->express = (yyvsp[0].expr);
										p->next = NULL;
										q->next = p;
										(yyvsp[-2].plist).pnum = (yyvsp[-2].plist).pnum + 1;
										(yyval.plist) = (yyvsp[-2].plist);
									}
#line 2965 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 1178 "semantics.y" /* yacc.c:1652  */
    {}
#line 2971 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 1179 "semantics.y" /* yacc.c:1652  */
    {(yyval.after) = (yyvsp[0].after);}
#line 2977 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 104:
#line 1180 "semantics.y" /* yacc.c:1652  */
    {(yyval.after) = NULL;}
#line 2983 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 105:
#line 1181 "semantics.y" /* yacc.c:1652  */
    {(yyval.after) = (yyvsp[0].after);}
#line 2989 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 106:
#line 1182 "semantics.y" /* yacc.c:1652  */
    {(yyval.after) = (yyvsp[0].after);}
#line 2995 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 107:
#line 1183 "semantics.y" /* yacc.c:1652  */
    {(yyval.after) = (yyvsp[0].after);}
#line 3001 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 108:
#line 1186 "semantics.y" /* yacc.c:1652  */
    {}
#line 3007 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 109:
#line 1187 "semantics.y" /* yacc.c:1652  */
    {}
#line 3013 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 110:
#line 1190 "semantics.y" /* yacc.c:1652  */
    {(yyval.after) = NULL;}
#line 3019 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 111:
#line 1191 "semantics.y" /* yacc.c:1652  */
    {(yyval.after) = (yyvsp[-1].after);}
#line 3025 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 112:
#line 1194 "semantics.y" /* yacc.c:1652  */
    {(yyval.after) = (yyvsp[0].after);}
#line 3031 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 113:
#line 1197 "semantics.y" /* yacc.c:1652  */
    {
										backpatch((yyvsp[-2].after),(yyvsp[-1].dummy));
										(yyval.after) = (yyvsp[0].after);
									}
#line 3040 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 114:
#line 1203 "semantics.y" /* yacc.c:1652  */
    {(yyval.after) = NULL;}
#line 3046 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 115:
#line 1204 "semantics.y" /* yacc.c:1652  */
    {(yyval.after) = (yyvsp[0].after);}
#line 3052 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 116:
#line 1207 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[-1].expr);}
#line 3058 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 117:
#line 1208 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr).address_pointer = NULL;}
#line 3064 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 118:
#line 1212 "semantics.y" /* yacc.c:1652  */
    {
												backpatch((yyvsp[-3].expr).true_list,(yyvsp[-1].dummy));
												(yyval.after) = merge((yyvsp[-3].expr).false_list,(yyvsp[0].after));	
											}
#line 3073 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 119:
#line 1218 "semantics.y" /* yacc.c:1652  */
    {
												backpatch((yyvsp[-7].expr).true_list,(yyvsp[-5].dummy));	
												backpatch((yyvsp[-7].expr).false_list,(yyvsp[-1].dummy));
												quad_list *tep = merge((yyvsp[-4].after),(yyvsp[-3].after)); 	
												(yyval.after) = merge(tep,(yyvsp[0].after));
											}
#line 3084 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 120:
#line 1225 "semantics.y" /* yacc.c:1652  */
    {}
#line 3090 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 121:
#line 1229 "semantics.y" /* yacc.c:1652  */
    {
											backpatch((yyvsp[-3].expr).true_list,(yyvsp[-1].dummy));
											backpatch((yyvsp[0].after),(yyvsp[-5].dummy));
											(yyval.after) = (yyvsp[-3].expr).false_list;
											char str[10];
											sprintf(str,"%d",(yyvsp[-5].dummy));
											Quadruples::emit(str);	// emit Quadruple of goto instruction
										}
#line 3103 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 122:
#line 1239 "semantics.y" /* yacc.c:1652  */
    {
											backpatch((yyvsp[-2].expr).true_list,(yyvsp[-6].dummy));
											(yyval.after) = (yyvsp[-2].expr).false_list;	
										}
#line 3112 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 123:
#line 1245 "semantics.y" /* yacc.c:1652  */
    {
																backpatch((yyvsp[0].after),(yyvsp[-5].dummy));
																backpatch((yyvsp[-3].after),(yyvsp[-8].dummy));
																backpatch((yyvsp[-7].expr).true_list,(yyvsp[-1].dummy));
																(yyval.after) = (yyvsp[-7].expr).false_list;
																char str[10];
																sprintf(str,"%d",(yyvsp[-5].dummy));
																Quadruples::emit(str);	// emit Quadruple of goto instruction
															}
#line 3126 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 124:
#line 1255 "semantics.y" /* yacc.c:1652  */
    {}
#line 3132 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 125:
#line 1258 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr).address_pointer = NULL;}
#line 3138 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 126:
#line 1259 "semantics.y" /* yacc.c:1652  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 3144 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 127:
#line 1262 "semantics.y" /* yacc.c:1652  */
    {}
#line 3150 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 128:
#line 1263 "semantics.y" /* yacc.c:1652  */
    {}
#line 3156 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 129:
#line 1264 "semantics.y" /* yacc.c:1652  */
    {}
#line 3162 "semantics.tab.c" /* yacc.c:1652  */
    break;

  case 130:
#line 1265 "semantics.y" /* yacc.c:1652  */
    {
								if((yyvsp[-1].expr).address_pointer){
									Quadruples::emit("return","",((yyvsp[-1].expr).address_pointer)->sym_name);	// emit Quadruple of return statement instruction
								}	
								(yyval.after) = NULL;
							}
#line 3173 "semantics.tab.c" /* yacc.c:1652  */
    break;


#line 3177 "semantics.tab.c" /* yacc.c:1652  */
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
#line 1273 "semantics.y" /* yacc.c:1918  */


void yyerror(const char *s){
	printf("%s at %s \n",s,yytext);
}
