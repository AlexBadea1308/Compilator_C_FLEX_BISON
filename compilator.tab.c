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
#line 1 "compilator.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compilator.tab.h"

#define INT_TYPE 1
#define DOUBLE_TYPE 2
#define FLOAT_TYPE 3

extern FILE* yyin;
extern int lineNo;
extern int colNo;
int hasError = 0;
int yyerror(const char* s);
void yyrestart  (FILE * input_file );
extern int yylex();

class Symbol 
{
    char name[128];
    double value;
    int type;
    Symbol* next;

    Symbol* head;
    Symbol* tail;

public:
    Symbol();
    ~Symbol();
    bool exists(const char* n);
    void add(const char* n, int t);
    void setValue(const char* n, double v);
    double getValue(const char* n);
    int getType(const char* n);
    void printSymbols();
    void freeSymbols();
};

Symbol::Symbol() 
{
    head = nullptr;
    tail = nullptr;
}

Symbol::~Symbol() 
{
    freeSymbols();
}

bool Symbol::exists(const char* n) 
{
    Symbol* current = head;
    while (current != nullptr) 
    {
        if (strcmp(current->name, n) == 0) 
            return true;
        current = current->next;
    }
    return false;
}

void Symbol::add(const char* n, int t) 
{
    if (exists(n)) 
    {
        yyerror("Variable already declared");
        return;
    }
    Symbol* sym = new Symbol();
    strncpy(sym->name, n, sizeof(sym->name) - 1);
    sym->value = 0;
    sym->type = t;
    sym->next = nullptr;

    if (head == nullptr) 
    {
        head = tail = sym;
    } 
    else 
    {
        tail->next = sym;
        tail = sym;
    }
}

void Symbol::setValue(const char* n, double v) 
{
    Symbol* current = head;
    while (current != nullptr) 
    {
        if (strcmp(current->name, n) == 0) 
        {
            current->value = v;
            return;
        }
        current = current->next;
    }
    yyerror("Variable not declared");
}

double Symbol::getValue(const char* n) 
{
    Symbol* current = head;
    while (current != nullptr) 
    {
        if (strcmp(current->name, n) == 0) 
        {
            return current->value;
        }
        current = current->next;
    }
    yyerror("Variable not declared");
    return 0;
}

int Symbol::getType(const char* n) 
{
    Symbol* current = head;
    while (current != nullptr) 
    {
        if (strcmp(current->name, n) == 0) 
        {
            return current->type;
        }
        current = current->next;
    }
    yyerror("Variable not declared");
    return 0;
}

void Symbol::printSymbols() 
{
    Symbol* current = head;
    printf("\nSymbol Table:\n");
    while (current != nullptr) 
    {
        printf("Name: %s Type: %s Value: %f\n", current->name, 
               (current->type == INT_TYPE ? "int" : 
                current->type == DOUBLE_TYPE ? "double" : "float"),
               current->value);
        current = current->next;
    }
}

void Symbol::freeSymbols() 
{
    Symbol* current = head;
    while (current != nullptr) 
    {
        Symbol* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

Symbol* symbolTable=nullptr;

#line 233 "compilator.tab.c"

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

#include "compilator.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_DECLARE_INT = 3,            /* TOK_DECLARE_INT  */
  YYSYMBOL_TOK_DECLARE_DOUBLE = 4,         /* TOK_DECLARE_DOUBLE  */
  YYSYMBOL_TOK_DECLARE_FLOAT = 5,          /* TOK_DECLARE_FLOAT  */
  YYSYMBOL_TOK_LPAREN = 6,                 /* TOK_LPAREN  */
  YYSYMBOL_TOK_RPAREN = 7,                 /* TOK_RPAREN  */
  YYSYMBOL_TOK_MULTIPLY = 8,               /* TOK_MULTIPLY  */
  YYSYMBOL_TOK_DIVIDE = 9,                 /* TOK_DIVIDE  */
  YYSYMBOL_TOK_PLUS = 10,                  /* TOK_PLUS  */
  YYSYMBOL_TOK_MINUS = 11,                 /* TOK_MINUS  */
  YYSYMBOL_TOK_ASSIGN = 12,                /* TOK_ASSIGN  */
  YYSYMBOL_TOK_SEMICOLON = 13,             /* TOK_SEMICOLON  */
  YYSYMBOL_TOK_IF = 14,                    /* TOK_IF  */
  YYSYMBOL_TOK_ELSE = 15,                  /* TOK_ELSE  */
  YYSYMBOL_TOK_EQUAL = 16,                 /* TOK_EQUAL  */
  YYSYMBOL_TOK_GREATER = 17,               /* TOK_GREATER  */
  YYSYMBOL_TOK_LESS = 18,                  /* TOK_LESS  */
  YYSYMBOL_TOK_LESS_EQUAL = 19,            /* TOK_LESS_EQUAL  */
  YYSYMBOL_TOK_GREATER_EQUAL = 20,         /* TOK_GREATER_EQUAL  */
  YYSYMBOL_TOK_NOT_EQUAL = 21,             /* TOK_NOT_EQUAL  */
  YYSYMBOL_TOK_LBRACE = 22,                /* TOK_LBRACE  */
  YYSYMBOL_TOK_RBRACE = 23,                /* TOK_RBRACE  */
  YYSYMBOL_TOK_INT = 24,                   /* TOK_INT  */
  YYSYMBOL_TOK_DOUBLE = 25,                /* TOK_DOUBLE  */
  YYSYMBOL_TOK_FLOAT = 26,                 /* TOK_FLOAT  */
  YYSYMBOL_TOK_ID = 27,                    /* TOK_ID  */
  YYSYMBOL_TOK_PRINT = 28,                 /* TOK_PRINT  */
  YYSYMBOL_TOK_SCANF = 29,                 /* TOK_SCANF  */
  YYSYMBOL_TOK_COMMA = 30,                 /* TOK_COMMA  */
  YYSYMBOL_TOK_STRING = 31,                /* TOK_STRING  */
  YYSYMBOL_TOK_AMPERSAND = 32,             /* TOK_AMPERSAND  */
  YYSYMBOL_UMINUS = 33,                    /* UMINUS  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_statements = 37,                /* statements  */
  YYSYMBOL_statement = 38,                 /* statement  */
  YYSYMBOL_declaration = 39,               /* declaration  */
  YYSYMBOL_assignment = 40,                /* assignment  */
  YYSYMBOL_condition = 41,                 /* condition  */
  YYSYMBOL_expr = 42                       /* expr  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  100

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
       2,     2,     2,     2,     2,    34,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   193,   193,   198,   206,   210,   218,   222,   226,   235,
     243,   248,   292,   326,   340,   353,   366,   380,   394,   412,
     448,   449,   450,   451,   452,   453,   454,   458,   459,   460,
     461,   465,   469,   473,   474,   475,   476,   477,   487,   488,
     492,   496,   500
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
  "\"end of file\"", "error", "\"invalid token\"", "TOK_DECLARE_INT",
  "TOK_DECLARE_DOUBLE", "TOK_DECLARE_FLOAT", "TOK_LPAREN", "TOK_RPAREN",
  "TOK_MULTIPLY", "TOK_DIVIDE", "TOK_PLUS", "TOK_MINUS", "TOK_ASSIGN",
  "TOK_SEMICOLON", "TOK_IF", "TOK_ELSE", "TOK_EQUAL", "TOK_GREATER",
  "TOK_LESS", "TOK_LESS_EQUAL", "TOK_GREATER_EQUAL", "TOK_NOT_EQUAL",
  "TOK_LBRACE", "TOK_RBRACE", "TOK_INT", "TOK_DOUBLE", "TOK_FLOAT",
  "TOK_ID", "TOK_PRINT", "TOK_SCANF", "TOK_COMMA", "TOK_STRING",
  "TOK_AMPERSAND", "UMINUS", "'-'", "$accept", "program", "statements",
  "statement", "declaration", "assignment", "condition", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   -20,   -18,   -14,     5,     8,    47,    49,    56,     0,
     -68,   -68,   -68,     3,     6,    13,    40,    40,    31,    41,
     -68,   -68,    40,   -68,    40,   -68,    40,   -68,    18,   -68,
     -68,   -68,   -68,    40,    79,   123,    60,    24,    58,   100,
     112,   137,    80,    83,    88,   144,   -68,    74,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,   -68,   106,
      75,    69,   -68,   -68,   -68,    51,    57,    73,   -68,     0,
     -68,   -68,    39,    39,    50,    50,    50,    50,    50,    50,
     -68,   107,    99,   -68,   -68,   -68,   -68,   -68,   -68,    89,
     114,   128,   121,   -68,   124,   116,   -68,     0,   101,   -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       5,     6,     7,     0,     0,     0,     0,     0,     0,     0,
       1,     4,     0,    13,     0,    14,     0,    15,     0,    27,
      28,    29,    33,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
       0,     0,    16,    17,    18,     0,     0,     0,    38,     0,
      36,    37,    34,    35,    22,    20,    21,    25,    24,    23,
      10,     0,     0,    30,    39,    31,    40,    32,    41,     0,
       0,     0,     9,    11,     0,     0,    12,     0,     0,     8
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,   -67,    -9,   -68,   -68,   -68,   -16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,    34,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      21,    36,    89,     1,     2,     3,    39,    13,    40,    14,
      41,    16,    45,    15,     4,    22,    23,    46,    24,    25,
      17,    42,    43,    44,    28,    26,    27,     5,     6,     7,
      98,    59,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    29,    30,    31,    32,    28,    48,    49,    84,
      86,    88,    33,    18,    60,    19,    20,    28,    48,    49,
      50,    51,    37,    28,    29,    30,    31,    32,    48,    49,
      50,    51,    38,    58,    33,    29,    30,    31,    83,    28,
      21,    29,    30,    31,    85,    33,    47,    65,    61,    21,
      66,    33,     1,     2,     3,    67,    69,    29,    30,    31,
      87,    82,    81,     4,     1,     2,     3,    33,    48,    49,
      50,    51,    92,    62,    90,     4,     5,     6,     7,    80,
      48,    49,    50,    51,    99,    63,    91,    93,     5,     6,
       7,    48,    49,    50,    51,    94,    95,    96,    97,    52,
      53,    54,    55,    56,    57,    48,    49,    50,    51,     0,
      64,    68,    48,    49,    50,    51
};

static const yytype_int8 yycheck[] =
{
       9,    17,    69,     3,     4,     5,    22,    27,    24,    27,
      26,     6,    28,    27,    14,    12,    13,    33,    12,    13,
      12,     3,     4,     5,     6,    12,    13,    27,    28,    29,
      97,     7,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    24,    25,    26,    27,     6,     8,     9,    65,
      66,    67,    34,     6,    30,     6,     0,     6,     8,     9,
      10,    11,    31,     6,    24,    25,    26,    27,     8,     9,
      10,    11,    31,    13,    34,    24,    25,    26,    27,     6,
      89,    24,    25,    26,    27,    34,     7,     7,    30,    98,
       7,    34,     3,     4,     5,     7,    22,    24,    25,    26,
      27,    32,    27,    14,     3,     4,     5,    34,     8,     9,
      10,    11,    23,    13,     7,    14,    27,    28,    29,    13,
       8,     9,    10,    11,    23,    13,    27,    13,    27,    28,
      29,     8,     9,    10,    11,     7,    15,    13,    22,    16,
      17,    18,    19,    20,    21,     8,     9,    10,    11,    -1,
      13,     7,     8,     9,    10,    11
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    14,    27,    28,    29,    36,    37,
      38,    39,    40,    27,    27,    27,     6,    12,     6,     6,
       0,    38,    12,    13,    12,    13,    12,    13,     6,    24,
      25,    26,    27,    34,    41,    42,    42,    31,    31,    42,
      42,    42,     3,     4,     5,    42,    42,     7,     8,     9,
      10,    11,    16,    17,    18,    19,    20,    21,    13,     7,
      30,    30,    13,    13,    13,     7,     7,     7,     7,    22,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      13,    27,    32,    27,    42,    27,    42,    27,    42,    37,
       7,    27,    23,    13,     7,    15,    13,    22,    37,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    38,    38,    38,    38,
      38,    38,    38,    39,    39,    39,    39,    39,    39,    40,
      41,    41,    41,    41,    41,    41,    41,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,    11,     7,
       5,     7,     8,     3,     3,     3,     5,     5,     5,     4,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       4,     4,     4,     1,     3,     3,     3,     3,     3,     4,
       4,     4,     2
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
  case 2: /* program: statements  */
#line 194 "compilator.y"
    {
        if (hasError)  YYABORT;
    }
#line 1329 "compilator.tab.c"
    break;

  case 3: /* program: %empty  */
#line 198 "compilator.y"
    {
        if (hasError)  YYABORT;
    }
#line 1337 "compilator.tab.c"
    break;

  case 4: /* statements: statements statement  */
#line 207 "compilator.y"
    {
        if (hasError)  YYABORT;
    }
#line 1345 "compilator.tab.c"
    break;

  case 5: /* statements: statement  */
#line 211 "compilator.y"
    {
        if (hasError)  YYABORT;
    }
#line 1353 "compilator.tab.c"
    break;

  case 6: /* statement: declaration  */
#line 219 "compilator.y"
    {
        if (hasError)  YYABORT;
    }
#line 1361 "compilator.tab.c"
    break;

  case 7: /* statement: assignment  */
#line 223 "compilator.y"
    {
        if (hasError)  YYABORT;
    }
#line 1369 "compilator.tab.c"
    break;

  case 8: /* statement: TOK_IF TOK_LPAREN condition TOK_RPAREN TOK_LBRACE statements TOK_RBRACE TOK_ELSE TOK_LBRACE statements TOK_RBRACE  */
#line 227 "compilator.y"
    {
        if ((yyvsp[-8].double_val)) 
        {
            printf("DEBUG: Executing 'if' block\n");
        } else {
            printf("DEBUG: Executing 'else' block\n");
        }
    }
#line 1382 "compilator.tab.c"
    break;

  case 9: /* statement: TOK_IF TOK_LPAREN condition TOK_RPAREN TOK_LBRACE statements TOK_RBRACE  */
#line 236 "compilator.y"
    {
        if ((yyvsp[-4].double_val)) 
        {
            printf("DEBUG: Executing 'if' block\n");
        }
    }
#line 1393 "compilator.tab.c"
    break;

  case 10: /* statement: TOK_PRINT TOK_LPAREN TOK_STRING TOK_RPAREN TOK_SEMICOLON  */
#line 244 "compilator.y"
    {
         if (hasError) YYABORT;
        printf("%s\n", (yyvsp[-2].str_val));
    }
#line 1402 "compilator.tab.c"
    break;

  case 11: /* statement: TOK_PRINT TOK_LPAREN TOK_STRING TOK_COMMA TOK_ID TOK_RPAREN TOK_SEMICOLON  */
#line 249 "compilator.y"
    {
        if (hasError)  YYABORT;
        if (!symbolTable->exists((yyvsp[-2].str_val))) 
        {
            yyerror("Variable not declared");
            YYABORT;
        } 
        else 
        {
            int type = symbolTable->getType((yyvsp[-2].str_val));
            double value = symbolTable->getValue((yyvsp[-2].str_val));
            char result[1024];
            char* temp = (yyvsp[-4].str_val);

            if ((strcmp(temp, "%d") == 0 && type == INT_TYPE)) 
            {
                printf("%d\n", (int)value);
            } 
            else if 
            ((strcmp(temp, "%f") == 0 || strcmp(temp, "%lf") == 0) && 
                       (type == DOUBLE_TYPE || type == FLOAT_TYPE))
            {
                printf("%f\n", value);
            } 
            else if (strstr(temp, "%d") && type == INT_TYPE) 
            {
                snprintf(result, sizeof(result), temp, (int)value);
                printf("%s\n", result);
            } 
            else if 
            ((strstr(temp, "%f") || strstr(temp, "%lf")) && 
                       (type == DOUBLE_TYPE || type == FLOAT_TYPE)) 
            {
                snprintf(result, sizeof(result), temp, value);
                printf("%s\n", result);
            } 
            else 
            {
                yyerror("Tip de variabila incompatibil cu formatul din printf!");
                YYABORT;
            }
        }
    }
#line 1450 "compilator.tab.c"
    break;

  case 12: /* statement: TOK_SCANF TOK_LPAREN TOK_STRING TOK_COMMA TOK_AMPERSAND TOK_ID TOK_RPAREN TOK_SEMICOLON  */
#line 293 "compilator.y"
    {   
        if(strcmp((yyvsp[-3].str_val),"&"))
        {
            yyerror("Use & if you want to assign a value!\n");
            YYABORT;
        }
        else
        if (!symbolTable->exists((yyvsp[-2].str_val))) 
        {
            yyerror("Variable not declared!\n");
            YYABORT;
        } else 
        {
            int type = symbolTable->getType((yyvsp[-2].str_val));
            if ((strcmp((yyvsp[-5].str_val), "%d") == 0 && type != INT_TYPE) ||
                (strcmp((yyvsp[-5].str_val), "%f") == 0 && type != FLOAT_TYPE) ||
                (strcmp((yyvsp[-5].str_val), "%lf") == 0 && type != DOUBLE_TYPE)) 
                {
                yyerror("Format does not match variable type!\n");
                YYABORT;
                } 
                else 
                {
                    double value;
                    printf("Introduce value for  %s: ", (yyvsp[-2].str_val));
                    scanf("%lf", &value);
                    symbolTable->setValue((yyvsp[-2].str_val),value);
                }
            }
        }
#line 1485 "compilator.tab.c"
    break;

  case 13: /* declaration: TOK_DECLARE_INT TOK_ID TOK_SEMICOLON  */
#line 327 "compilator.y"
    {
        if (symbolTable->exists((yyvsp[-1].str_val))) 
        {
            yyerror("Redeclaration of variable");
            yyin=NULL;
            YYABORT;
        } 
        else 
        {
            symbolTable->add((yyvsp[-1].str_val), INT_TYPE);
            printf("Declaratie: int %s\n", (yyvsp[-1].str_val));
        }
    }
#line 1503 "compilator.tab.c"
    break;

  case 14: /* declaration: TOK_DECLARE_DOUBLE TOK_ID TOK_SEMICOLON  */
#line 341 "compilator.y"
    {
        if (symbolTable->exists((yyvsp[-1].str_val))) 
        {
            yyerror("Redeclaration of variable");
            YYABORT;
        } 
        else 
        {
            symbolTable->add((yyvsp[-1].str_val), DOUBLE_TYPE);
            printf("Declaratie: double %s\n", (yyvsp[-1].str_val));
        }
    }
#line 1520 "compilator.tab.c"
    break;

  case 15: /* declaration: TOK_DECLARE_FLOAT TOK_ID TOK_SEMICOLON  */
#line 354 "compilator.y"
    {
        if (symbolTable->exists((yyvsp[-1].str_val))) 
        {
            yyerror("Redeclaration of variable");
            YYABORT;
        } 
        else
        {
            symbolTable->add((yyvsp[-1].str_val), FLOAT_TYPE);
            printf("Declaratie: float %s\n", (yyvsp[-1].str_val));
        }
    }
#line 1537 "compilator.tab.c"
    break;

  case 16: /* declaration: TOK_DECLARE_INT TOK_ID TOK_ASSIGN expr TOK_SEMICOLON  */
#line 367 "compilator.y"
    {
        if (symbolTable->exists((yyvsp[-3].str_val))) 
        {
            yyerror("Redeclaration of variable");
            YYABORT;
        } 
        else 
        {
            symbolTable->add((yyvsp[-3].str_val), INT_TYPE);
            symbolTable->setValue((yyvsp[-3].str_val), (yyvsp[-1].double_val));
            printf("Declaratie: int %s = %d\n", (yyvsp[-3].str_val), (int)(yyvsp[-1].double_val));
        }
    }
#line 1555 "compilator.tab.c"
    break;

  case 17: /* declaration: TOK_DECLARE_DOUBLE TOK_ID TOK_ASSIGN expr TOK_SEMICOLON  */
#line 381 "compilator.y"
    {
        if (symbolTable->exists((yyvsp[-3].str_val))) 
        {
            yyerror("Redeclaration of variable");
            YYABORT;
        } 
        else 
        {
            symbolTable->add((yyvsp[-3].str_val), DOUBLE_TYPE);
            symbolTable->setValue((yyvsp[-3].str_val), (yyvsp[-1].double_val));
            printf("Declaratie: double %s = %lf\n", (yyvsp[-3].str_val), (yyvsp[-1].double_val));
        }
    }
#line 1573 "compilator.tab.c"
    break;

  case 18: /* declaration: TOK_DECLARE_FLOAT TOK_ID TOK_ASSIGN expr TOK_SEMICOLON  */
#line 395 "compilator.y"
    {
        if (symbolTable->exists((yyvsp[-3].str_val))) 
        {
            yyerror("Redeclaration of variable");
            YYABORT;
        } 
        else 
        {
            symbolTable->add((yyvsp[-3].str_val), FLOAT_TYPE);
            symbolTable->setValue((yyvsp[-3].str_val), (yyvsp[-1].double_val));
            printf("Declaratie: float %s = %lf\n", (yyvsp[-3].str_val), (yyvsp[-1].double_val));
        }
    }
#line 1591 "compilator.tab.c"
    break;

  case 19: /* assignment: TOK_ID TOK_ASSIGN expr TOK_SEMICOLON  */
#line 413 "compilator.y"
    {
        if (!symbolTable->exists((yyvsp[-3].str_val))) 
        {
            yyerror("Variable not declared");
        }

        if (hasError)  YYABORT;

        int type = symbolTable->getType((yyvsp[-3].str_val));

        if ((type == INT_TYPE && (yyvsp[-1].double_val) != (int)(yyvsp[-1].double_val)) ||
            (type == FLOAT_TYPE && (float)(yyvsp[-1].double_val) != (yyvsp[-1].double_val))) 
        {
            yyerror("Type mismatch in assignment");
        }

        if (hasError)  YYABORT;
        symbolTable->setValue((yyvsp[-3].str_val), (yyvsp[-1].double_val));

        if (type == INT_TYPE) 
        {
            printf("Atribuire: %s = %d\n", (yyvsp[-3].str_val), (int)(yyvsp[-1].double_val));
        } 
        else if (type == FLOAT_TYPE) 
        {
            printf("Atribuire: %s = %f\n", (yyvsp[-3].str_val), (float)(yyvsp[-1].double_val));
        } 
        else 
        {
            printf("Atribuire: %s = %lf\n", (yyvsp[-3].str_val), (yyvsp[-1].double_val));
        }
    }
#line 1628 "compilator.tab.c"
    break;

  case 20: /* condition: expr TOK_GREATER expr  */
#line 448 "compilator.y"
                                 { (yyval.double_val) = (yyvsp[-2].double_val) > (yyvsp[0].double_val) ? 1 : 0; }
#line 1634 "compilator.tab.c"
    break;

  case 21: /* condition: expr TOK_LESS expr  */
#line 449 "compilator.y"
                                 { (yyval.double_val) = (yyvsp[-2].double_val) < (yyvsp[0].double_val) ? 1 : 0; }
#line 1640 "compilator.tab.c"
    break;

  case 22: /* condition: expr TOK_EQUAL expr  */
#line 450 "compilator.y"
                                 { (yyval.double_val) = (yyvsp[-2].double_val) == (yyvsp[0].double_val) ? 1 : 0; }
#line 1646 "compilator.tab.c"
    break;

  case 23: /* condition: expr TOK_NOT_EQUAL expr  */
#line 451 "compilator.y"
                                 { (yyval.double_val) = (yyvsp[-2].double_val) != (yyvsp[0].double_val) ? 1 : 0; }
#line 1652 "compilator.tab.c"
    break;

  case 24: /* condition: expr TOK_GREATER_EQUAL expr  */
#line 452 "compilator.y"
                                  { (yyval.double_val) = (yyvsp[-2].double_val) >= (yyvsp[0].double_val) ? 1 : 0; }
#line 1658 "compilator.tab.c"
    break;

  case 25: /* condition: expr TOK_LESS_EQUAL expr  */
#line 453 "compilator.y"
                                 { (yyval.double_val) = (yyvsp[-2].double_val) <= (yyvsp[0].double_val) ? 1 : 0; }
#line 1664 "compilator.tab.c"
    break;

  case 26: /* condition: expr  */
#line 454 "compilator.y"
                                 { (yyval.double_val) = (yyvsp[0].double_val) != 0 ? 1 : 0; }
#line 1670 "compilator.tab.c"
    break;

  case 27: /* expr: TOK_INT  */
#line 458 "compilator.y"
                                { (yyval.double_val) = (yyvsp[0].int_val); }
#line 1676 "compilator.tab.c"
    break;

  case 28: /* expr: TOK_DOUBLE  */
#line 459 "compilator.y"
                                { (yyval.double_val) = (yyvsp[0].double_val); }
#line 1682 "compilator.tab.c"
    break;

  case 29: /* expr: TOK_FLOAT  */
#line 460 "compilator.y"
                                { (yyval.double_val) = atof((yyvsp[0].str_val)); }
#line 1688 "compilator.tab.c"
    break;

  case 30: /* expr: TOK_LPAREN TOK_DECLARE_INT TOK_RPAREN TOK_ID  */
#line 462 "compilator.y"
    {
        (yyval.double_val) = (double)((int)symbolTable->getValue((yyvsp[0].str_val)));
    }
#line 1696 "compilator.tab.c"
    break;

  case 31: /* expr: TOK_LPAREN TOK_DECLARE_DOUBLE TOK_RPAREN TOK_ID  */
#line 466 "compilator.y"
    {
        (yyval.double_val) = symbolTable->getValue((yyvsp[0].str_val));
    }
#line 1704 "compilator.tab.c"
    break;

  case 32: /* expr: TOK_LPAREN TOK_DECLARE_FLOAT TOK_RPAREN TOK_ID  */
#line 470 "compilator.y"
    {
        (yyval.double_val) = (double)((float)symbolTable->getValue((yyvsp[0].str_val)));
    }
#line 1712 "compilator.tab.c"
    break;

  case 33: /* expr: TOK_ID  */
#line 473 "compilator.y"
                                { (yyval.double_val) = symbolTable->getValue((yyvsp[0].str_val)); }
#line 1718 "compilator.tab.c"
    break;

  case 34: /* expr: expr TOK_PLUS expr  */
#line 474 "compilator.y"
                                { (yyval.double_val) = (yyvsp[-2].double_val) + (yyvsp[0].double_val); }
#line 1724 "compilator.tab.c"
    break;

  case 35: /* expr: expr TOK_MINUS expr  */
#line 475 "compilator.y"
                                { (yyval.double_val) = (yyvsp[-2].double_val) - (yyvsp[0].double_val); }
#line 1730 "compilator.tab.c"
    break;

  case 36: /* expr: expr TOK_MULTIPLY expr  */
#line 476 "compilator.y"
                                { (yyval.double_val) = (yyvsp[-2].double_val) * (yyvsp[0].double_val); }
#line 1736 "compilator.tab.c"
    break;

  case 37: /* expr: expr TOK_DIVIDE expr  */
#line 478 "compilator.y"
    {
        if ((yyvsp[0].double_val) == 0) {
            yyerror("Divizare la zero!");
            YYABORT;
            (yyval.double_val) = 0;
        } else {
            (yyval.double_val) = (yyvsp[-2].double_val) / (yyvsp[0].double_val);
        }
    }
#line 1750 "compilator.tab.c"
    break;

  case 38: /* expr: TOK_LPAREN expr TOK_RPAREN  */
#line 487 "compilator.y"
                                 { (yyval.double_val) = (yyvsp[-1].double_val); }
#line 1756 "compilator.tab.c"
    break;

  case 39: /* expr: TOK_LPAREN TOK_DECLARE_INT TOK_RPAREN expr  */
#line 489 "compilator.y"
    {
        (yyval.double_val) = (double)((int)(yyvsp[0].double_val));
    }
#line 1764 "compilator.tab.c"
    break;

  case 40: /* expr: TOK_LPAREN TOK_DECLARE_DOUBLE TOK_RPAREN expr  */
#line 493 "compilator.y"
    {
        (yyval.double_val) = (yyvsp[0].double_val);
    }
#line 1772 "compilator.tab.c"
    break;

  case 41: /* expr: TOK_LPAREN TOK_DECLARE_FLOAT TOK_RPAREN expr  */
#line 497 "compilator.y"
    {
        (yyval.double_val) = (double)((float)(yyvsp[0].double_val));
    }
#line 1780 "compilator.tab.c"
    break;

  case 42: /* expr: '-' expr  */
#line 500 "compilator.y"
                                { (yyval.double_val) = -(yyvsp[0].double_val); }
#line 1786 "compilator.tab.c"
    break;


#line 1790 "compilator.tab.c"

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

#line 504 "compilator.y"


int yyerror(const char* s) 
{
    fprintf(stderr, "Eroare at line %d, column %d: %s\n", lineNo, colNo, s);
    hasError = 1;
    return 1;
}


int main(int argc, char* argv[]) 
{
    char line[1024];          

    printf("Tasteaza comenzi:\nRuleaza scripturi folosind comanda 'run nume_script':\n'exit' pentru a iesi.\n");

    while (1) 
    {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) 
            break;

        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "exit") == 0) 
        {
            printf("Iesire...\n");
            if (symbolTable != nullptr) {
                symbolTable->freeSymbols();
                delete symbolTable;
                symbolTable = nullptr;
            }
            break;
        }

        if (strncmp(line, "run ", 4) == 0) 
        {   
            if (symbolTable != nullptr) 
            {
                symbolTable->freeSymbols();
                delete symbolTable;
                symbolTable = nullptr;
            }

            symbolTable = new Symbol();

            char* filename = line + 4;
            FILE* file = fopen(filename, "r");
            if (!file) {
                perror("Eroare la deschiderea fisierului");
                continue;
            }

            lineNo = 1;
            colNo = 1;

            printf("Executam scriptul: %s\n", filename);
            yyin = file;

            yyparse();
            yyrestart(yyin);
            fclose(file);

            if (hasError) 
            {
                printf("Scriptul contine erori. Revenire la prompt.\n");
                symbolTable->freeSymbols();
                delete symbolTable;
                symbolTable=nullptr;
                hasError = 0;
                continue;
            }

            printf("Scriptul a fost executat cu succes.\n");
            symbolTable->freeSymbols();
            delete symbolTable;
            symbolTable=nullptr;
        } 
        else 
        {   
            if(symbolTable==nullptr)
                {
                    symbolTable = new Symbol();
                    lineNo = 1;
                    colNo = 1;
                }

            FILE* cmdFile = fmemopen(line, strlen(line), "r");
            if (!cmdFile) 
            {
                perror("Eroare la procesarea comenzii");
                continue;
            }

            yyin = cmdFile;
            yyparse();
            fclose(cmdFile);

            if (hasError) 
            {
                printf("Comanda contine erori. Revenire la prompt.\n");
                hasError = 0;
                symbolTable->freeSymbols();
                delete symbolTable;
                symbolTable=nullptr;
                continue;
            }

            printf("Comanda a fost executata cu succes.\n");
            lineNo++;
            colNo=1;
        }
    }
    return 0;
}
