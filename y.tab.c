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
#line 1 "uccompiler.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include "y.tab.h"
    extern char *yytext;
    int type;

    int flag1 = 0; 	//tokens encontrados
	int flag2 = 0; 	//return
	int lex_erros = 0;
    int yydebug = 1;
    #define MAX 512
    int yylex();
    int yylex_destroy();
    
    extern int yywrap();
    

    int printtree = 1;
    extern int linha;
    extern int yyleng;
    extern int coluna;
    
    void yyerror (char *s);
    
    //int flag2 = 0; //flag return


    typedef struct node{
        char* type; 
        char* value;
        struct node *dad;
        struct node *bros;
        struct node *childs[MAX];
        int indexc;
    }node;

    struct node *head = NULL;
    struct node* createnode(char *type, char *value);
    struct node* addchild(node *dad, node *child);
    struct node* addbro(node *n1, node *n2);
    void print_tree(node *head, int depth);



#line 118 "y.tab.c"

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
    CHAR = 258,
    ELSE = 259,
    WHILE = 260,
    IF = 261,
    INT = 262,
    SHORT = 263,
    DOUBLE = 264,
    RETURN = 265,
    VOID = 266,
    BITWISEAND = 267,
    BITWISEOR = 268,
    BITWISEXOR = 269,
    AND = 270,
    ASSIGN = 271,
    MUL = 272,
    COMMA = 273,
    DIV = 274,
    EQ = 275,
    GE = 276,
    GT = 277,
    LBRACE = 278,
    LE = 279,
    LPAR = 280,
    LT = 281,
    MINUS = 282,
    MOD = 283,
    NE = 284,
    NOT = 285,
    OR = 286,
    PLUS = 287,
    RBRACE = 288,
    RPAR = 289,
    SEMI = 290,
    RESERVED = 291,
    CHRLIT = 292,
    ID = 293,
    REALLIT = 294,
    INTLIT = 295,
    THEN = 296
  };
#endif
/* Tokens.  */
#define CHAR 258
#define ELSE 259
#define WHILE 260
#define IF 261
#define INT 262
#define SHORT 263
#define DOUBLE 264
#define RETURN 265
#define VOID 266
#define BITWISEAND 267
#define BITWISEOR 268
#define BITWISEXOR 269
#define AND 270
#define ASSIGN 271
#define MUL 272
#define COMMA 273
#define DIV 274
#define EQ 275
#define GE 276
#define GT 277
#define LBRACE 278
#define LE 279
#define LPAR 280
#define LT 281
#define MINUS 282
#define MOD 283
#define NE 284
#define NOT 285
#define OR 286
#define PLUS 287
#define RBRACE 288
#define RPAR 289
#define SEMI 290
#define RESERVED 291
#define CHRLIT 292
#define ID 293
#define REALLIT 294
#define INTLIT 295
#define THEN 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 80 "uccompiler.y"

    char *str;
    struct node *node;

#line 257 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   523

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    94,   100,   107,   119,   121,   124,   134,
     139,   140,   143,   150,   153,   155,   159,   167,   173,   182,
     188,   192,   197,   208,   219,   225,   250,   254,   257,   260,
     263,   266,   272,   274,   280,   282,   291,   294,   299,   301,
     304,   316,   318,   338,   354,   368,   373,   379,   387,   393,
     400,   406,   412,   418,   424,   430,   436,   442,   448,   454,
     460,   466,   472,   477,   483,   488,   495,   498,   501,   505,
     513,   515,   517,   519,   521,   523,   526,   532,   534,   535
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "ELSE", "WHILE", "IF", "INT",
  "SHORT", "DOUBLE", "RETURN", "VOID", "BITWISEAND", "BITWISEOR",
  "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ", "GE", "GT",
  "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS",
  "RBRACE", "RPAR", "SEMI", "RESERVED", "CHRLIT", "ID", "REALLIT",
  "INTLIT", "THEN", "$accept", "Program", "FunctionsAndDeclarations",
  "FunctionsAndDeclarationsOP", "FunctionDefinition", "FunctionBody",
  "DeclarationsAndStatementsOp", "DeclarationsAndStatements",
  "FunctionDeclaration", "FunctionDeclarator", "ParameterList",
  "ParameterListOp", "ParameterDeclaration", "Declaration",
  "DeclarationOp", "TypeSpec", "Declarator", "StatementAux",
  "StatementError", "Statement", "Expr", "ExprOp4", YY_NULLPTR
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
     295,   296
};
# endif

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     505,   -16,  -123,  -123,  -123,  -123,  -123,    15,  -123,   117,
     117,   117,    -9,  -123,  -123,  -123,  -123,  -123,  -123,    61,
     -18,    17,   465,   512,    62,  -123,  -123,    -1,    22,   121,
     465,   465,   465,  -123,    33,  -123,  -123,   386,    26,    58,
      40,    56,    59,    -7,   144,  -123,    50,   104,  -123,    -1,
    -123,   269,    72,    17,  -123,    64,   317,  -123,  -123,  -123,
     240,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,  -123,
     512,  -123,  -123,   465,   465,  -123,   293,     1,  -123,    57,
     184,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    69,
     386,   -12,   216,   447,   176,   428,   386,  -123,   386,  -123,
     461,    47,    47,    47,    47,    63,  -123,   461,   407,    63,
      58,   340,   363,  -123,  -123,  -123,  -123,    71,  -123,  -123,
     465,  -123,  -123,   224,   224,   386,  -123,    89,   224,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    27,    28,    30,    31,    29,     0,     2,     0,
       0,     0,     0,    24,     1,     6,     3,     4,     5,    32,
       0,    26,     0,     0,     0,    16,     8,     0,     0,     0,
       0,     0,     0,    72,    70,    73,    71,    33,     0,    20,
      21,     0,     0,     0,     0,    38,     0,     0,    15,     0,
      14,     0,    32,    26,    23,     0,     0,    67,    68,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,    18,    22,     0,     0,    45,     0,     0,    41,     0,
       0,    36,     9,    13,    12,    39,    25,    76,    74,     0,
      78,     0,    57,    58,    59,    56,    48,    52,    49,    53,
      60,    63,    65,    62,    64,    51,    54,    61,    55,    50,
      20,     0,     0,    46,    47,    37,    40,     0,    35,    75,
       0,    69,    19,     0,     0,    77,    44,    42,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -123,  -123,    96,     3,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,    -4,    24,   -23,    66,   -21,    94,    42,  -122,   -20,
     -22,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,    15,    16,     9,    26,    46,    47,    10,    20,
      38,    81,    39,    11,    28,    12,    21,    89,    90,    91,
      51,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    48,    40,    49,    50,    24,   130,    56,    57,    58,
      59,   136,   137,    17,    18,    14,   139,    25,    29,    13,
      30,    86,   131,    31,    93,    32,    49,    94,    85,    19,
      33,    34,    35,    36,   124,    27,   125,    52,   100,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    54,    60,    40,
      79,   121,   122,     1,    66,     2,    68,    41,    42,     3,
       4,     5,    43,     6,    74,    75,    80,    22,    82,    78,
      66,    83,    68,    92,    84,    44,    23,    29,    22,    30,
     126,    75,    31,   138,    32,   -11,     8,    45,    97,    33,
      34,    35,    36,   129,   120,     1,   125,     2,   135,    41,
      42,     3,     4,     5,    43,     6,   132,    -7,     1,    96,
       2,    53,    55,     0,     3,     4,     5,    44,     6,    29,
       0,    30,   128,     0,    31,     0,    32,   -10,     0,    45,
       0,    33,    34,    35,    36,    87,    29,     0,    30,    41,
      42,    31,     0,    32,    43,     0,     0,     0,    33,    34,
      35,    36,     0,     0,     0,     0,     0,    44,     0,    29,
       0,    30,     0,     0,    31,     0,    32,    88,     0,    45,
       0,    33,    34,    35,    36,   127,     0,     0,    61,    41,
      42,     0,     0,    66,    43,    68,    69,    70,    71,     0,
      72,     0,    73,    74,    75,    76,     0,    44,    78,    29,
       0,    30,     0,     0,    31,     0,    32,   -34,     0,    45,
       0,    33,    34,    35,    36,   127,     0,     0,     0,    41,
      42,     0,     0,    66,    43,    68,    69,    70,    71,     0,
      72,    99,    73,    74,    75,    76,     0,    44,    78,    29,
       0,    30,     0,     0,    31,     0,    32,     0,   -79,    45,
       0,    33,    34,    35,    36,    29,     0,    30,     0,     0,
      31,     0,    32,     0,   -79,     0,     0,    33,    34,    35,
      36,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,     0,    73,    74,    75,    76,     0,
      77,    78,     0,     0,    95,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,     0,    73,
      74,    75,    76,     0,    77,    78,     0,     0,   123,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,     0,    73,    74,    75,    76,     0,    77,    78,
       0,    98,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,     0,    73,    74,    75,    76,
       0,    77,    78,     0,   133,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,     0,    73,
      74,    75,    76,     0,    77,    78,     0,   134,    61,    62,
      63,    64,    65,    66,     0,    68,    69,    70,    71,     0,
      72,     0,    73,    74,    75,    76,     0,    77,    78,    61,
      62,    63,    64,     0,    66,     0,    68,    69,    70,    71,
       0,    72,     0,    73,    74,    75,    76,     0,     0,    78,
      61,    62,    63,     0,     0,    66,     0,    68,    69,    70,
      71,     0,    72,     0,    73,    74,    75,    76,     0,    61,
      78,    63,     0,     0,    66,     0,    68,    69,    70,    71,
       0,    72,     0,    73,    74,    75,    76,     0,    66,    78,
      68,     0,    70,    71,     0,    72,     0,    73,    74,    75,
      29,     0,    30,    78,     0,    31,     0,    32,     0,     0,
       0,     0,    33,    34,    35,    36,     1,     0,     2,     0,
       0,     0,     3,     4,     5,     2,     6,     0,     0,     3,
       4,     5,     0,     6
};

static const yytype_int16 yycheck[] =
{
      22,    24,    23,    24,    24,    23,    18,    29,    30,    31,
      32,   133,   134,    10,    11,     0,   138,    35,    25,    35,
      27,    43,    34,    30,    47,    32,    47,    47,    35,    38,
      37,    38,    39,    40,    33,    18,    35,    38,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    35,    25,    80,
      34,    83,    84,     1,    17,     3,    19,     5,     6,     7,
       8,     9,    10,    11,    27,    28,    18,    16,    38,    32,
      17,    25,    19,    33,    25,    23,    25,    25,    16,    27,
      33,    28,    30,     4,    32,    33,     0,    35,    34,    37,
      38,    39,    40,    34,    80,     1,    35,     3,   130,     5,
       6,     7,     8,     9,    10,    11,   120,     0,     1,    53,
       3,    27,     1,    -1,     7,     8,     9,    23,    11,    25,
      -1,    27,    90,    -1,    30,    -1,    32,    33,    -1,    35,
      -1,    37,    38,    39,    40,     1,    25,    -1,    27,     5,
       6,    30,    -1,    32,    10,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,
      -1,    27,    -1,    -1,    30,    -1,    32,    33,    -1,    35,
      -1,    37,    38,    39,    40,     1,    -1,    -1,    12,     5,
       6,    -1,    -1,    17,    10,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,    23,    32,    25,
      -1,    27,    -1,    -1,    30,    -1,    32,    33,    -1,    35,
      -1,    37,    38,    39,    40,     1,    -1,    -1,    -1,     5,
       6,    -1,    -1,    17,    10,    19,    20,    21,    22,    -1,
      24,     1,    26,    27,    28,    29,    -1,    23,    32,    25,
      -1,    27,    -1,    -1,    30,    -1,    32,    -1,    18,    35,
      -1,    37,    38,    39,    40,    25,    -1,    27,    -1,    -1,
      30,    -1,    32,    -1,    34,    -1,    -1,    37,    38,    39,
      40,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    29,    -1,
      31,    32,    -1,    -1,    35,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    31,    32,    -1,    -1,    35,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    -1,    31,    32,
      -1,    34,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    -1,    34,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    31,    32,    -1,    34,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,    31,    32,    12,
      13,    14,    15,    -1,    17,    -1,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    -1,    -1,    32,
      12,    13,    14,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    -1,    12,
      32,    14,    -1,    -1,    17,    -1,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    -1,    17,    32,
      19,    -1,    21,    22,    -1,    24,    -1,    26,    27,    28,
      25,    -1,    27,    32,    -1,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,     1,    -1,     3,    -1,
      -1,    -1,     7,     8,     9,     3,    11,    -1,    -1,     7,
       8,     9,    -1,    11
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    11,    43,    44,    46,
      50,    55,    57,    35,     0,    44,    45,    45,    45,    38,
      51,    58,    16,    25,    23,    35,    47,    18,    56,    25,
      27,    30,    32,    37,    38,    39,    40,    62,    52,    54,
      57,     5,     6,    10,    23,    35,    48,    49,    55,    57,
      61,    62,    38,    58,    35,     1,    62,    62,    62,    62,
      25,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    24,    26,    27,    28,    29,    31,    32,    34,
      18,    53,    38,    25,    25,    35,    62,     1,    33,    59,
      60,    61,    33,    55,    61,    35,    56,    34,    34,     1,
      62,    63,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      54,    62,    62,    35,    33,    35,    33,     1,    59,    34,
      18,    34,    53,    34,    34,    62,    60,    60,     4,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    45,    45,    46,    47,
      48,    48,    49,    49,    49,    49,    50,    51,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    58,    58,    59,    59,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     0,     3,     3,
       1,     0,     2,     2,     1,     1,     3,     4,     2,     3,
       0,     1,     2,     4,     2,     3,     0,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     1,     2,     1,     2,
       3,     2,     5,     7,     5,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     4,
       1,     1,     1,     1,     3,     4,     3,     3,     1,     0
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
#line 87 "uccompiler.y"
                                                                            {head = createnode("Program","");
																			addchild(head,(yyvsp[0].node));
                                                                            (yyval.node) = head;}
#line 1607 "y.tab.c"
    break;

  case 3:
#line 94 "uccompiler.y"
                                                                                {
                                                                            if((yyvsp[0].node)!=NULL){
                                                                                addbro((yyvsp[-1].node), (yyvsp[0].node));
                                                                                }
                                                                            (yyval.node) = (yyvsp[-1].node);}
#line 1617 "y.tab.c"
    break;

  case 4:
#line 100 "uccompiler.y"
                                                                               {
                                                                             if((yyvsp[0].node)!=NULL){
                                                                                addbro((yyvsp[-1].node), (yyvsp[0].node));
                                                                                }
                                                                            (yyval.node) = (yyvsp[-1].node);
                                                                            }
#line 1628 "y.tab.c"
    break;

  case 5:
#line 107 "uccompiler.y"
                                                                              {
                                                                            if((yyvsp[0].node)!=NULL){
                                                                                addbro((yyvsp[-1].node), (yyvsp[0].node));
                                                                                }
                                                                            (yyval.node) = (yyvsp[-1].node);
                                                                            }
#line 1639 "y.tab.c"
    break;

  case 6:
#line 119 "uccompiler.y"
                                                                            {(yyval.node)=(yyvsp[0].node);}
#line 1645 "y.tab.c"
    break;

  case 7:
#line 121 "uccompiler.y"
                                                                            {(yyval.node)=NULL;}
#line 1651 "y.tab.c"
    break;

  case 8:
#line 124 "uccompiler.y"
                                                                            {struct node *functiondef = createnode("FuncDefinition", "");
                                                                           
                                                                            addchild(functiondef, (yyvsp[-2].node));
                                                                            addchild(functiondef, (yyvsp[-1].node));
                                                                            addchild(functiondef, (yyvsp[0].node));
                                                                            addbro((yyvsp[-2].node), (yyvsp[-1].node));
                                                                            addbro((yyvsp[-1].node), (yyvsp[0].node));
                                                                            (yyval.node) = functiondef;}
#line 1664 "y.tab.c"
    break;

  case 9:
#line 134 "uccompiler.y"
                                                                            {struct node *funcbody = createnode("FuncBody", "");
                                                                            addchild(funcbody, (yyvsp[-1].node));
                                                                            (yyval.node) = funcbody;}
#line 1672 "y.tab.c"
    break;

  case 10:
#line 139 "uccompiler.y"
                                                                            {(yyval.node)=(yyvsp[0].node);}
#line 1678 "y.tab.c"
    break;

  case 11:
#line 140 "uccompiler.y"
                                                                            {(yyval.node) = NULL;}
#line 1684 "y.tab.c"
    break;

  case 12:
#line 143 "uccompiler.y"
                                                                            {

                                                                            addbro((yyvsp[-1].node),(yyvsp[0].node));
                                                                            (yyval.node) = (yyvsp[-1].node);
                                                                            
                                                                            }
#line 1695 "y.tab.c"
    break;

  case 13:
#line 150 "uccompiler.y"
                                                                             {addbro((yyvsp[-1].node), (yyvsp[0].node));
                                                                            (yyval.node)=(yyvsp[-1].node);}
#line 1702 "y.tab.c"
    break;

  case 14:
#line 153 "uccompiler.y"
                                                                            {(yyval.node) = (yyvsp[0].node);}
#line 1708 "y.tab.c"
    break;

  case 15:
#line 155 "uccompiler.y"
                                                                            {(yyval.node) = (yyvsp[0].node);}
#line 1714 "y.tab.c"
    break;

  case 16:
#line 159 "uccompiler.y"
                                                                            {struct node *funcdeclaration = createnode("FuncDeclaration", "");
                                                                            addchild(funcdeclaration, (yyvsp[-2].node));
                                                                            addchild(funcdeclaration, (yyvsp[-1].node));
                                                                            addbro((yyvsp[-2].node), (yyvsp[-1].node));
                                                                            (yyval.node) = funcdeclaration;}
#line 1724 "y.tab.c"
    break;

  case 17:
#line 167 "uccompiler.y"
                                                                            {struct node *id1 = createnode("Id",(yyvsp[-3].str));
                                                                            addbro(id1, (yyvsp[-1].node));
                                                                            (yyval.node) = id1;
                                                                            }
#line 1733 "y.tab.c"
    break;

  case 18:
#line 173 "uccompiler.y"
                                                                            {struct node *paramlist = createnode("ParamList", "");
                                                                            addchild(paramlist, (yyvsp[-1].node));
                                                                            if((yyvsp[0].node)!=NULL){
                                                                                addchild(paramlist, (yyvsp[0].node));
                                                                                addbro((yyvsp[-1].node), (yyvsp[0].node));}
                                                                            (yyval.node)=paramlist;
                                                                            }
#line 1745 "y.tab.c"
    break;

  case 19:
#line 182 "uccompiler.y"
                                                                            {
                                                                            if((yyvsp[0].node)!=NULL){
                                                                                addbro((yyvsp[-1].node),(yyvsp[0].node));
                                                                                }
                                                                            (yyval.node) = (yyvsp[-1].node);
                                                                            }
#line 1756 "y.tab.c"
    break;

  case 20:
#line 188 "uccompiler.y"
                                                                            {(yyval.node) = NULL;}
#line 1762 "y.tab.c"
    break;

  case 21:
#line 192 "uccompiler.y"
                                                                            {struct node *paramdeclaration = createnode("ParamDeclaration", "");
                                                                            addchild(paramdeclaration, (yyvsp[0].node));
                                                                            (yyval.node) = paramdeclaration;
                                                                            }
#line 1771 "y.tab.c"
    break;

  case 22:
#line 197 "uccompiler.y"
                                                                            {struct node *paramdeclaration = createnode("ParamDeclaration", "");
                                                                            addchild(paramdeclaration, (yyvsp[-1].node));
                                                                            struct node *id1 = createnode("Id", (yyvsp[0].str));
                                                                            addchild(paramdeclaration, id1);
                                                                            addbro((yyvsp[-1].node), id1);
                                                                            
                                                                            (yyval.node) = paramdeclaration;}
#line 1783 "y.tab.c"
    break;

  case 23:
#line 208 "uccompiler.y"
                                                                            {struct node *declaration = createnode("Declaration","");                                                                            
                                                                            addchild(declaration, (yyvsp[-3].node));
                                                                            addchild(declaration, (yyvsp[-2].node));
                                                                            addbro((yyvsp[-3].node), (yyvsp[-2].node));
                                                                            if((yyvsp[-1].node)!=NULL){
                                                                                addbro(declaration,  (yyvsp[-1].node));
                                                                                }

                                                                            (yyval.node) = declaration;}
#line 1797 "y.tab.c"
    break;

  case 24:
#line 219 "uccompiler.y"
                                                                            {struct node *null = createnode("Null","");
                                                                            (yyval.node) = null;}
#line 1804 "y.tab.c"
    break;

  case 25:
#line 225 "uccompiler.y"
                                                                            {struct node *declaration = createnode("Declaration", "");
                                                                            if(type == 0){
                                                                                addchild(declaration,createnode("Char",""));                                                                                
                                                                            }
                                                                            if(type == 1){
                                                                                addchild(declaration,createnode("Int",""));
                                                                            }
                                                                            if(type == 2){
                                                                                addchild(declaration,createnode("Void",""));
                                                                            }
                                                                            if(type == 3){
                                                                                addchild(declaration,createnode("Short",""));
                                                                            }
                                                                            if(type == 4){
                                                                                addchild(declaration,createnode("Double",""));
                                                                            }
                                                                            addchild(declaration, (yyvsp[-1].node));
                                                                            addbro(declaration->childs[0], (yyvsp[-1].node));                                                                            
                                                                            

                                                                            if((yyvsp[0].node)!=NULL){                                                                    
                                                                                addbro(declaration,(yyvsp[0].node));
                                                                                }
                                                                            (yyval.node) = declaration;
                                                                            }
#line 1834 "y.tab.c"
    break;

  case 26:
#line 250 "uccompiler.y"
                                                                            {(yyval.node) = NULL;}
#line 1840 "y.tab.c"
    break;

  case 27:
#line 254 "uccompiler.y"
                                                                            {(yyval.node) = createnode("Char","");
                                                                            type = 0;}
#line 1847 "y.tab.c"
    break;

  case 28:
#line 257 "uccompiler.y"
                                                                            {(yyval.node) = createnode("Int","");
                                                                            type = 1;}
#line 1854 "y.tab.c"
    break;

  case 29:
#line 260 "uccompiler.y"
                                                                            {(yyval.node) = createnode("Void","");
                                                                            type = 2;}
#line 1861 "y.tab.c"
    break;

  case 30:
#line 263 "uccompiler.y"
                                                                            {(yyval.node) = createnode("Short","");
                                                                            type = 3;}
#line 1868 "y.tab.c"
    break;

  case 31:
#line 266 "uccompiler.y"
                                                                            {(yyval.node) = createnode("Double","");
                                                                            type = 4;}
#line 1875 "y.tab.c"
    break;

  case 32:
#line 272 "uccompiler.y"
                                                                            {(yyval.node) = createnode("Id", (yyvsp[0].str));}
#line 1881 "y.tab.c"
    break;

  case 33:
#line 274 "uccompiler.y"
                                                                            {struct node *id1 = createnode("Id", (yyvsp[-2].str));
                                                                                 addbro(id1, (yyvsp[0].node));
                                                                                 (yyval.node) = id1;}
#line 1889 "y.tab.c"
    break;

  case 34:
#line 280 "uccompiler.y"
                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1895 "y.tab.c"
    break;

  case 35:
#line 282 "uccompiler.y"
                                                                                {addbro((yyvsp[-1].node), (yyvsp[0].node)); 
                                                                                if((yyvsp[-1].node)!=NULL){
                                                                                    (yyval.node) = (yyvsp[-1].node);
                                                                                }
                                                                                else{
                                                                                    (yyval.node) = (yyvsp[0].node);}}
#line 1906 "y.tab.c"
    break;

  case 36:
#line 291 "uccompiler.y"
                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 1912 "y.tab.c"
    break;

  case 37:
#line 294 "uccompiler.y"
                                                                                 {struct node *null = createnode("Null", ""); (yyval.node)=null;}
#line 1918 "y.tab.c"
    break;

  case 38:
#line 299 "uccompiler.y"
                                                                                {(yyval.node) = NULL;}
#line 1924 "y.tab.c"
    break;

  case 39:
#line 301 "uccompiler.y"
                                                                                {(yyval.node) = (yyvsp[-1].node);}
#line 1930 "y.tab.c"
    break;

  case 40:
#line 304 "uccompiler.y"
                                                                                {if((yyvsp[-1].node)!=NULL && (yyvsp[-1].node)->bros != NULL){
                                                                                struct node *statlist = createnode("StatList", "");
                                                                                addchild(statlist, (yyvsp[-1].node));
                                                                                (yyval.node) = statlist;

                                                                                }
                                                                                else if((yyvsp[-1].node)!=NULL && (yyvsp[-1].node)->bros == NULL){
                                                                                    (yyval.node) = (yyvsp[-1].node);
                                                                                }
                                                                                else{(yyval.node) = NULL;}
                                                                                }
#line 1946 "y.tab.c"
    break;

  case 41:
#line 316 "uccompiler.y"
                                                                                {struct node *null = createnode("Null", ""); (yyval.node)=null;}
#line 1952 "y.tab.c"
    break;

  case 42:
#line 318 "uccompiler.y"
                                                                                     {struct node *if1 = createnode("If","");
                                                                                addchild(if1, (yyvsp[-2].node));
                                                                                if((yyvsp[0].node) == NULL){
                                                                                    struct node *null = createnode("Null", ""); 
                                                                                    addchild(if1, null); 
                                                                                    addbro((yyvsp[-2].node), null);
                                                                                    struct node *null1 = createnode("Null", ""); 
                                                                                    addchild(if1, null1);
                                                                                    addbro(null, null1);
                                                                                    }
                                                                                else{
                                                                                    addchild(if1, (yyvsp[0].node));
                                                                                    addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                    struct node *null1 = createnode("Null", ""); 
                                                                                    addchild(if1, null1);
                                                                                    addbro((yyvsp[0].node), null1);
                                                                                    }
                                                                                (yyval.node) = if1;}
#line 1975 "y.tab.c"
    break;

  case 43:
#line 338 "uccompiler.y"
                                                                                        {struct node *if2 = createnode("If", "");

                                                                                addchild(if2, (yyvsp[-4].node));
                                                                                if((yyvsp[-2].node) == NULL){
                                                                                    struct node *null = createnode("Null", ""); addchild(if2, null);}
                                                                                else{addchild(if2, (yyvsp[-2].node));}
                                                                                if((yyvsp[0].node) == NULL){
                                                                                    
                                                                                    struct node *null = createnode("Null", "");addchild(if2, null); }
                                                                                else{addchild(if2, (yyvsp[0].node));}
                                                                                addbro((yyvsp[-4].node), if2->childs[1]);
                                                                                addbro(if2->childs[1], if2->childs[2]);
                                                                                
                                                                                (yyval.node) = if2;}
#line 1994 "y.tab.c"
    break;

  case 44:
#line 354 "uccompiler.y"
                                                                                {struct node *while1 = createnode("While", "");
                                                                                addchild(while1, (yyvsp[-2].node));
                                                                                if((yyvsp[0].node) == NULL){
                                                                                    struct node *null = createnode("Null", ""); 
                                                                                    addchild(while1, null); 
                                                                                    addbro((yyvsp[-2].node), null);
                                                                                    }
                                                                                else{
                                                                                    addchild(while1, (yyvsp[0].node));
                                                                                    addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                    }
                                                                                (yyval.node) = while1;}
#line 2011 "y.tab.c"
    break;

  case 45:
#line 368 "uccompiler.y"
                                                                                {struct node *return1 = createnode("Return", "");
                                                                                struct node *null = createnode("Null","");
                                                                                addchild(return1, null);
                                                                                (yyval.node)=return1;}
#line 2020 "y.tab.c"
    break;

  case 46:
#line 373 "uccompiler.y"
                                                                                                                                {struct node *return1 = createnode("Return","");
																				addchild(return1, (yyvsp[-1].node));
                                                                                (yyval.node)=return1;}
#line 2028 "y.tab.c"
    break;

  case 47:
#line 379 "uccompiler.y"
                                                                                {struct node *null = createnode("Null","");
                                                                                 (yyval.node) = null;}
#line 2035 "y.tab.c"
    break;

  case 48:
#line 387 "uccompiler.y"
                                                                                {struct node *store = createnode("Store","");
                                                                                 addchild(store, (yyvsp[-2].node));
                                                                                 addchild(store, (yyvsp[0].node));
                                                                                 addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                 (yyval.node) = store;}
#line 2045 "y.tab.c"
    break;

  case 49:
#line 393 "uccompiler.y"
                                                                       {struct node *comma = createnode("Comma","");
                                                                                 addchild(comma, (yyvsp[-2].node));
                                                                                 addchild(comma, (yyvsp[0].node));
                                                                                 addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                 (yyval.node) = comma;}
#line 2055 "y.tab.c"
    break;

  case 50:
#line 400 "uccompiler.y"
                                                                       {struct node *add = createnode("Add","");
                                                                                addchild(add, (yyvsp[-2].node));
                                                                                    addchild(add, (yyvsp[0].node));
                                                                                 addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                 (yyval.node) = add;}
#line 2065 "y.tab.c"
    break;

  case 51:
#line 406 "uccompiler.y"
                                                                               {struct node *sub = createnode("Sub","");
                                                                                addchild(sub, (yyvsp[-2].node));
                                                                                addchild(sub, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = sub;}
#line 2075 "y.tab.c"
    break;

  case 52:
#line 412 "uccompiler.y"
                                                                           {struct node *mul = createnode("Mul","");
                                                                                addchild(mul, (yyvsp[-2].node));
                                                                                addchild(mul, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = mul;}
#line 2085 "y.tab.c"
    break;

  case 53:
#line 418 "uccompiler.y"
                                                                             {struct node *div = createnode("Div","");
                                                                                addchild(div, (yyvsp[-2].node));
                                                                                addchild(div, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = div;}
#line 2095 "y.tab.c"
    break;

  case 54:
#line 424 "uccompiler.y"
                                                                             {struct node *mod = createnode("Mod","");
                                                                                addchild(mod, (yyvsp[-2].node));
                                                                                addchild(mod, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = mod;}
#line 2105 "y.tab.c"
    break;

  case 55:
#line 430 "uccompiler.y"
                                                                           {struct node *or = createnode("Or","");
                                                                                addchild(or, (yyvsp[-2].node));
                                                                                addchild(or, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = or;}
#line 2115 "y.tab.c"
    break;

  case 56:
#line 436 "uccompiler.y"
                                                                            {struct node *and = createnode("And","");
                                                                                addchild(and, (yyvsp[-2].node));
                                                                                addchild(and, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = and;}
#line 2125 "y.tab.c"
    break;

  case 57:
#line 442 "uccompiler.y"
                                                                                {struct node *bitewiseand = createnode("BitWiseAnd","");
                                                                                addchild(bitewiseand, (yyvsp[-2].node));
                                                                                addchild(bitewiseand, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = bitewiseand;}
#line 2135 "y.tab.c"
    break;

  case 58:
#line 448 "uccompiler.y"
                                                                                  {struct node *bitewiseor = createnode("BitWiseOr","");
                                                                                addchild(bitewiseor, (yyvsp[-2].node));
                                                                                addchild(bitewiseor, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = bitewiseor;}
#line 2145 "y.tab.c"
    break;

  case 59:
#line 454 "uccompiler.y"
                                                                                   {struct node *bitewisexor = createnode("BitWiseXor","");
                                                                                addchild(bitewisexor, (yyvsp[-2].node));
                                                                                addchild(bitewisexor, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = bitewisexor;}
#line 2155 "y.tab.c"
    break;

  case 60:
#line 460 "uccompiler.y"
                                                                            {struct node *eq = createnode("Eq","");
                                                                                addchild(eq, (yyvsp[-2].node));
                                                                                addchild(eq, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = eq;}
#line 2165 "y.tab.c"
    break;

  case 61:
#line 466 "uccompiler.y"
                                                                            {struct node *ne = createnode("Ne","");
                                                                                addchild(ne, (yyvsp[-2].node));
                                                                                addchild(ne, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = ne;}
#line 2175 "y.tab.c"
    break;

  case 62:
#line 472 "uccompiler.y"
                                                                            {struct node *le = createnode("Le","");
                                                                                addchild(le, (yyvsp[-2].node));
                                                                                addchild(le, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = le;}
#line 2185 "y.tab.c"
    break;

  case 63:
#line 477 "uccompiler.y"
                                                                            {struct node *ge = createnode("Ge","");
                                                                                addchild(ge, (yyvsp[-2].node));
                                                                                addchild(ge, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = ge;}
#line 2195 "y.tab.c"
    break;

  case 64:
#line 483 "uccompiler.y"
                                                                            {struct node *lt = createnode("Lt","");
                                                                                addchild(lt, (yyvsp[-2].node));
                                                                                addchild(lt, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = lt;}
#line 2205 "y.tab.c"
    break;

  case 65:
#line 488 "uccompiler.y"
                                                                            {struct node *gt = createnode("Gt","");
                                                                                addchild(gt, (yyvsp[-2].node));
                                                                                addchild(gt, (yyvsp[0].node));
                                                                                addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                (yyval.node) = gt;}
#line 2215 "y.tab.c"
    break;

  case 66:
#line 495 "uccompiler.y"
                                                                                         {struct node *plus = createnode("Plus","");
                                                                                    (yyval.node) = addchild(plus,(yyvsp[0].node));}
#line 2222 "y.tab.c"
    break;

  case 67:
#line 498 "uccompiler.y"
                                                                                          {struct node *minus = createnode("Minus","");
                                                                                    (yyval.node) = addchild(minus,(yyvsp[0].node));}
#line 2229 "y.tab.c"
    break;

  case 68:
#line 501 "uccompiler.y"
                                                                                {struct node *not = createnode("Not","");
                                                                                    (yyval.node) = addchild(not,(yyvsp[0].node));}
#line 2236 "y.tab.c"
    break;

  case 69:
#line 505 "uccompiler.y"
                                                                                {struct node *id1 = createnode("Id",(yyvsp[-3].str));
                                                                                struct node *call = createnode("Call","");
                                                                                addchild(call, id1);
                                                                                addchild(call, (yyvsp[-1].node));
                                                                                addbro(id1, (yyvsp[-1].node)); 
                                                                                (yyval.node) = call;}
#line 2247 "y.tab.c"
    break;

  case 70:
#line 513 "uccompiler.y"
                                                                                {(yyval.node) = createnode("Id", (yyvsp[0].str));}
#line 2253 "y.tab.c"
    break;

  case 71:
#line 515 "uccompiler.y"
                                                                                {(yyval.node) = createnode("IntLit", (yyvsp[0].str));}
#line 2259 "y.tab.c"
    break;

  case 72:
#line 517 "uccompiler.y"
                                                                                {(yyval.node) = createnode("ChrLit", (yyvsp[0].str));}
#line 2265 "y.tab.c"
    break;

  case 73:
#line 519 "uccompiler.y"
                                                                                {(yyval.node) = createnode("RealLit", (yyvsp[0].str));}
#line 2271 "y.tab.c"
    break;

  case 74:
#line 521 "uccompiler.y"
                                                                                {(yyval.node) = (yyvsp[-1].node);}
#line 2277 "y.tab.c"
    break;

  case 75:
#line 523 "uccompiler.y"
                                                                                {struct node *null = createnode("Null","");
                                                                                 (yyval.node) = null;}
#line 2284 "y.tab.c"
    break;

  case 76:
#line 526 "uccompiler.y"
                                                                                {struct node *null = createnode("Null","");
                                                                                 (yyval.node) = null;}
#line 2291 "y.tab.c"
    break;

  case 77:
#line 532 "uccompiler.y"
                                                                                {addbro((yyvsp[-2].node), (yyvsp[0].node));
                                                                                 (yyval.node) = (yyvsp[-2].node);}
#line 2298 "y.tab.c"
    break;

  case 78:
#line 534 "uccompiler.y"
                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2304 "y.tab.c"
    break;

  case 79:
#line 535 "uccompiler.y"
                                                                                {(yyval.node) = NULL; }
#line 2310 "y.tab.c"
    break;


#line 2314 "y.tab.c"

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
#line 539 "uccompiler.y"

struct node* createnode(char *type, char *value){
    node *new = (node *)malloc(sizeof(node));

    if(new==NULL){
        return NULL;
    }
    new->type = type;
    new->value = value;
    new->indexc = 0;
    new->dad = NULL;
    new->bros = NULL;
    return new;
}

struct node* addchild(struct node* dad, struct node* child){
    if (dad == NULL || child == NULL){
       return NULL;
    }

    dad->childs[dad->indexc] = child;
    dad->indexc++;
    child->dad = dad;

    node *aux = child->bros;

    while (aux != NULL){
        aux->dad = dad;
        dad->childs[dad->indexc] = aux;
        dad->indexc++;
        aux = aux->bros;
    }

    return dad;
}

struct node *addbro(struct node* n1, struct node* n2){
    struct node* aux= n1;
    if(aux!=NULL){
        while (aux->bros!=NULL){
            aux = aux->bros;
        }
        aux->bros = n2;
    }
    return n1;
}

void print_tree(struct node *head, int depth){
    if (head == NULL){
        return;
    }

    for (int i = 0; i < depth; i++){
        printf("..");
    }

    if (strcmp(head->value, "") == 0){
        printf("%s\n", head->type);
    }
    else{
        printf("%s(%s)\n", head->type, head->value);
    }
    for (int j = 0; j < head->indexc; j++){
        print_tree(head->childs[j], depth + 1);
    }

    free(head);
}

int main(int argc, char **argv){
    if (argc > 1){
        if (strcmp(argv[1], "-l") == 0){
            //lex completo
            flag1 = 1;
            yylex();
        }
        else if (strcmp(argv[1], "-e1") == 0){
            //lex erros
            yylex();
        }

        else if (strcmp(argv[1], "-t") == 0){
            //árvore
            flag2 = 1;
            yyparse();
            if(printtree == 1){
            print_tree(head, 0);
            }
        }

        else if (strcmp(argv[1], "-e2") == 0){
            // erros lex e sintaxe
            flag2 = 1;
            yyparse();
        }

        else{
        	return 0;
        }
	}
	if (argc == 1){

        //erros lex e sintaxe
        flag2 = 1;
        yyparse();
	}

	return 0;
}


void yyerror(char *msg) {
    printtree = 0;
    printf("Line %d, col %d: %s: %s\n", linha , (int)(coluna-strlen(yytext)) , msg , yytext);
}
