/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse boot_yyparse
#define yylex   boot_yylex
#define yyerror boot_yyerror
#define yylval  boot_yylval
#define yychar  boot_yychar
#define yydebug boot_yydebug
#define yynerrs boot_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     COMMA = 259,
     EQUALS = 260,
     LPAREN = 261,
     RPAREN = 262,
     NULLVAL = 263,
     OPEN = 264,
     XCLOSE = 265,
     XCREATE = 266,
     INSERT_TUPLE = 267,
     XDECLARE = 268,
     INDEX = 269,
     ON = 270,
     USING = 271,
     XBUILD = 272,
     INDICES = 273,
     UNIQUE = 274,
     XTOAST = 275,
     OBJ_ID = 276,
     XBOOTSTRAP = 277,
     XSHARED_RELATION = 278,
     XWITHOUT_OIDS = 279,
     XROWTYPE_OID = 280,
     XFORCE = 281,
     XNOT = 282,
     XNULL = 283
   };
#endif
/* Tokens.  */
#define ID 258
#define COMMA 259
#define EQUALS 260
#define LPAREN 261
#define RPAREN 262
#define NULLVAL 263
#define OPEN 264
#define XCLOSE 265
#define XCREATE 266
#define INSERT_TUPLE 267
#define XDECLARE 268
#define INDEX 269
#define ON 270
#define USING 271
#define XBUILD 272
#define INDICES 273
#define UNIQUE 274
#define XTOAST 275
#define OBJ_ID 276
#define XBOOTSTRAP 277
#define XSHARED_RELATION 278
#define XWITHOUT_OIDS 279
#define XROWTYPE_OID 280
#define XFORCE 281
#define XNOT 282
#define XNULL 283




/* Copy the first part of user declarations.  */
#line 1 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"

/*-------------------------------------------------------------------------
 *
 * bootparse.y
 *	  yacc grammar for the "bootstrap" mode (BKI file format)
 *
 * Portions Copyright (c) 1996-2018, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *	  src/backend/bootstrap/bootparse.y
 *
 *-------------------------------------------------------------------------
 */

#include "zql.h"

#include <unistd.h>

#include "access/attnum.h"
#include "access/htup.h"
#include "access/itup.h"
#include "access/tupdesc.h"
#include "bootstrap/bootstrap.h"
#include "catalog/catalog.h"
#include "catalog/heap.h"
#include "catalog/namespace.h"
#include "catalog/pg_am.h"
#include "catalog/pg_attribute.h"
#include "catalog/pg_authid.h"
#include "catalog/pg_class.h"
#include "catalog/pg_namespace.h"
#include "catalog/pg_tablespace.h"
#include "catalog/toasting.h"
#include "commands/defrem.h"
#include "miscadmin.h"
#include "nodes/makefuncs.h"
#include "nodes/nodes.h"
#include "nodes/parsenodes.h"
#include "nodes/pg_list.h"
#include "nodes/primnodes.h"
#include "rewrite/prs2lock.h"
#include "storage/block.h"
#include "storage/fd.h"
#include "storage/ipc.h"
#include "storage/itemptr.h"
#include "storage/off.h"
#include "storage/smgr.h"
#include "tcop/dest.h"
#include "utils/memutils.h"
#include "utils/rel.h"


/*
 * Bison doesn't allocate anything that needs to live across parser calls,
 * so we can easily have it use palloc instead of malloc.  This prevents
 * memory leaks if we error out during parsing.  Note this only works with
 * bison >= 2.0.  However, in bison 1.875 the default is to use alloca()
 * if possible, so there's not really much problem anyhow, at least if
 * you're building with gcc.
 */
#define YYMALLOC palloc
#define YYFREE   pfree

static MemoryContext per_line_ctx = NULL;

static void
do_start(void)
{
	Assert(CurrentMemoryContext == CurTransactionContext);
	/* First time through, create the per-line working context */
	if (per_line_ctx == NULL)
		per_line_ctx = AllocSetContextCreate(CurTransactionContext,
											 "bootstrap per-line processing",
											 ALLOCSET_DEFAULT_SIZES);
	MemoryContextSwitchTo(per_line_ctx);
}


static void
do_end(void)
{
	/* Reclaim memory allocated while processing this line */
	MemoryContextSwitchTo(CurTransactionContext);
	MemoryContextReset(per_line_ctx);
	CHECK_FOR_INTERRUPTS();		/* allow SIGINT to kill bootstrap run */
	if (isatty(0))
	{
		printf("bootstrap> ");
		fflush(stdout);
	}
}


static int num_columns_read = 0;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 104 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
{
	List		*list;
	IndexElem	*ielem;
	char		*str;
	const char	*kw;
	int			ival;
	Oid			oidval;
}
/* Line 193 of yacc.c.  */
#line 268 "bootparse.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 281 "bootparse.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    30,    33,    34,    35,    48,
      49,    56,    68,    81,    88,    91,    95,    97,   100,   102,
     103,   105,   106,   108,   109,   112,   113,   115,   119,   124,
     128,   131,   132,   134,   138,   139,   141,   144,   148,   150,
     152,   154,   156,   158,   160,   162,   164,   166,   168,   170,
     172,   174,   176,   178,   180,   182,   184,   186,   188,   190,
     192
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      30,     0,    -1,    31,    -1,    -1,    32,    -1,    31,    32,
      -1,    33,    -1,    34,    -1,    35,    -1,    38,    -1,    40,
      -1,    41,    -1,    42,    -1,    43,    -1,     9,    57,    -1,
      10,    57,    -1,    -1,    -1,    11,    57,    53,    46,    47,
      48,    49,     6,    36,    50,    37,     7,    -1,    -1,    12,
      54,    39,     6,    55,     7,    -1,    13,    14,    57,    53,
      15,    57,    16,    57,     6,    44,     7,    -1,    13,    19,
      14,    57,    53,    15,    57,    16,    57,     6,    44,     7,
      -1,    13,    20,    53,    53,    15,    57,    -1,    17,    18,
      -1,    44,     4,    45,    -1,    45,    -1,    57,    57,    -1,
      22,    -1,    -1,    23,    -1,    -1,    24,    -1,    -1,    25,
      53,    -1,    -1,    51,    -1,    50,     4,    51,    -1,    57,
       5,    57,    52,    -1,    26,    27,    28,    -1,    26,    28,
      -1,    -1,    57,    -1,    21,     5,    53,    -1,    -1,    56,
      -1,    55,    56,    -1,    55,     4,    56,    -1,    57,    -1,
       8,    -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,
      12,    -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,
      17,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,    28,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   135,   139,   140,   144,   145,   146,   147,
     148,   149,   150,   151,   155,   164,   174,   184,   173,   265,
     264,   286,   335,   384,   396,   406,   407,   411,   426,   427,
     431,   432,   436,   437,   441,   442,   446,   447,   451,   460,
     461,   462,   466,   470,   471,   475,   476,   477,   481,   483,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "COMMA", "EQUALS", "LPAREN",
  "RPAREN", "NULLVAL", "OPEN", "XCLOSE", "XCREATE", "INSERT_TUPLE",
  "XDECLARE", "INDEX", "ON", "USING", "XBUILD", "INDICES", "UNIQUE",
  "XTOAST", "OBJ_ID", "XBOOTSTRAP", "XSHARED_RELATION", "XWITHOUT_OIDS",
  "XROWTYPE_OID", "XFORCE", "XNOT", "XNULL", "$accept", "TopLevel",
  "Boot_Queries", "Boot_Query", "Boot_OpenStmt", "Boot_CloseStmt",
  "Boot_CreateStmt", "@1", "@2", "Boot_InsertStmt", "@3",
  "Boot_DeclareIndexStmt", "Boot_DeclareUniqueIndexStmt",
  "Boot_DeclareToastStmt", "Boot_BuildIndsStmt", "boot_index_params",
  "boot_index_param", "optbootstrap", "optsharedrelation",
  "optwithoutoids", "optrowtypeoid", "boot_column_list", "boot_column_def",
  "boot_column_nullness", "oidspec", "optoideq", "boot_column_val_list",
  "boot_column_val", "boot_ident", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    30,    31,    31,    32,    32,    32,    32,
      32,    32,    32,    32,    33,    34,    36,    37,    35,    39,
      38,    40,    41,    42,    43,    44,    44,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    52,
      52,    52,    53,    54,    54,    55,    55,    55,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     0,    12,     0,
       6,    11,    12,     6,     2,     3,     1,     2,     1,     0,
       1,     0,     1,     0,     2,     0,     1,     3,     4,     3,
       2,     0,     1,     3,     0,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,    44,     0,     0,     0,     2,     4,
       6,     7,     8,     9,    10,    11,    12,    13,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    14,
      15,     0,     0,    19,     0,     0,     0,    24,     1,     5,
      29,    42,     0,     0,     0,     0,     0,    28,    31,    43,
       0,     0,     0,     0,    30,    33,    49,     0,    45,    48,
       0,     0,     0,    32,    35,     0,    20,    46,     0,     0,
      23,     0,     0,    47,     0,     0,    34,    16,     0,     0,
       0,     0,     0,    17,    36,     0,     0,    26,     0,     0,
       0,     0,     0,     0,    21,    27,     0,    37,    18,    41,
      25,    22,     0,    38,     0,    40,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    12,    90,   101,    13,
      53,    14,    15,    16,    17,    96,    97,    58,    65,    74,
      82,    93,    94,   113,    50,    43,    67,    68,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int16 yypact[] =
{
      -5,   152,   152,   152,     5,     1,    -2,    27,    -5,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   152,    23,   -58,   152,    15,   152,   -58,   -58,   -58,
       8,   -58,   152,    25,   152,   152,   152,   -58,     9,   -58,
     126,    19,   152,    20,   -58,    12,   -58,   100,   -58,   -58,
     152,    22,   152,   -58,    14,   126,   -58,   -58,    17,   152,
     -58,   152,    34,   -58,   152,    26,   -58,   -58,    35,   152,
     152,   152,    38,    41,   -58,    42,    10,   -58,   152,   152,
     152,    39,   152,   152,   -58,   -58,    18,   -58,   -58,    24,
     -58,   -58,    -4,   -58,    21,   -58,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,    40,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -48,   -51,   -58,   -58,   -58,
     -58,   -58,   -47,   -58,   -43,   -58,   -58,   -57,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,    40,    41,    56,     1,     2,     3,     4,     5,    59,
      77,    61,     6,    63,   103,    44,    47,   104,    83,    71,
      45,    46,   103,   114,   115,   111,    42,    48,    52,    55,
      57,    60,    64,    84,    70,    72,    73,    79,    86,    81,
      87,    91,    89,    54,    99,   100,   108,   102,    49,   116,
     112,   106,   110,   107,    62,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,     0,    69,     0,     0,    78,
       0,    80,     0,     0,    69,     0,     0,     0,    85,     0,
       0,     0,     0,    88,     0,     0,     0,     0,    92,    95,
      98,     0,     0,     0,     0,     0,     0,   105,    98,    95,
       0,   109,    98,    18,    75,     0,     0,    76,    66,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    18,
       0,     0,     0,     0,    66,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    18,     0,     0,     0,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38
};

static const yytype_int8 yycheck[] =
{
       1,     2,     3,    46,     9,    10,    11,    12,    13,    52,
      67,    54,    17,    56,     4,    14,    18,     7,    75,    62,
      19,    20,     4,    27,    28,     7,    21,     0,     5,    14,
      22,     6,    23,    16,    15,    15,    24,    15,    81,    25,
       6,     6,    16,    44,     6,     4,     7,     5,     8,    28,
      26,    99,   103,   100,    55,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    72,    -1,    -1,    75,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    90,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,
      -1,   102,   103,     3,     4,    -1,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     3,
      -1,    -1,    -1,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     3,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    11,    12,    13,    17,    30,    31,    32,
      33,    34,    35,    38,    40,    41,    42,    43,     3,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    57,
      57,    57,    21,    54,    14,    19,    20,    18,     0,    32,
      53,    57,     5,    39,    57,    14,    53,    22,    46,    53,
       6,    53,    57,    53,    23,    47,     8,    55,    56,    57,
      15,    53,    15,    24,    48,     4,     7,    56,    57,    15,
      57,    25,    49,    56,    16,    57,    53,     6,    57,    16,
      36,     6,    57,    50,    51,    57,    44,    45,    57,     6,
       4,    37,     5,     4,     7,    57,    44,    51,     7,    57,
      45,     7,    26,    52,    27,    28,    28
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 14:
#line 156 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
					do_start();
					boot_openrel((yyvsp[(2) - (2)].str));
					do_end();
				;}
    break;

  case 15:
#line 165 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
					do_start();
					closerel((yyvsp[(2) - (2)].str));
					do_end();
				;}
    break;

  case 16:
#line 174 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
					do_start();
					numattr = 0;
					elog(DEBUG4, "creating%s%s relation %s %u",
						 (yyvsp[(4) - (8)].ival) ? " bootstrap" : "",
						 (yyvsp[(5) - (8)].ival) ? " shared" : "",
						 (yyvsp[(2) - (8)].str),
						 (yyvsp[(3) - (8)].oidval));
				;}
    break;

  case 17:
#line 184 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
					do_end();
				;}
    break;

  case 18:
#line 188 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
					TupleDesc tupdesc;
					bool	shared_relation;
					bool	mapped_relation;

					do_start();

					tupdesc = CreateTupleDesc(numattr, !((yyvsp[(6) - (12)].ival)), attrtypes);

					shared_relation = (yyvsp[(5) - (12)].ival);

					/*
					 * The catalogs that use the relation mapper are the
					 * bootstrap catalogs plus the shared catalogs.  If this
					 * ever gets more complicated, we should invent a BKI
					 * keyword to mark the mapped catalogs, but for now a
					 * quick hack seems the most appropriate thing.  Note in
					 * particular that all "nailed" heap rels (see formrdesc
					 * in relcache.c) must be mapped.
					 */
					mapped_relation = ((yyvsp[(4) - (12)].ival) || shared_relation);

					if ((yyvsp[(4) - (12)].ival))
					{
						if (boot_reldesc)
						{
							elog(DEBUG4, "create bootstrap: warning, open relation exists, closing first");
							closerel(NULL);
						}

						boot_reldesc = heap_create((yyvsp[(2) - (12)].str),
												   PG_CATALOG_NAMESPACE,
												   shared_relation ? GLOBALTABLESPACE_OID : 0,
												   (yyvsp[(3) - (12)].oidval),
												   InvalidOid,
												   tupdesc,
												   RELKIND_RELATION,
												   RELPERSISTENCE_PERMANENT,
												   shared_relation,
												   mapped_relation,
												   true);
						elog(DEBUG4, "bootstrap relation created");
					}
					else
					{
						Oid id;

						id = heap_create_with_catalog((yyvsp[(2) - (12)].str),
													  PG_CATALOG_NAMESPACE,
													  shared_relation ? GLOBALTABLESPACE_OID : 0,
													  (yyvsp[(3) - (12)].oidval),
													  (yyvsp[(7) - (12)].oidval),
													  InvalidOid,
													  BOOTSTRAP_SUPERUSERID,
													  tupdesc,
													  NIL,
													  RELKIND_RELATION,
													  RELPERSISTENCE_PERMANENT,
													  shared_relation,
													  mapped_relation,
													  true,
													  0,
													  ONCOMMIT_NOOP,
													  (Datum) 0,
													  false,
													  true,
													  false,
													  InvalidOid,
													  NULL);
						elog(DEBUG4, "relation created with OID %u", id);
					}
					do_end();
				;}
    break;

  case 19:
#line 265 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
					do_start();
					if ((yyvsp[(2) - (2)].oidval))
						elog(DEBUG4, "inserting row with oid %u", (yyvsp[(2) - (2)].oidval));
					else
						elog(DEBUG4, "inserting row");
					num_columns_read = 0;
				;}
    break;

  case 20:
#line 274 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
					if (num_columns_read != numattr)
						elog(ERROR, "incorrect number of columns in row (expected %d, got %d)",
							 numattr, num_columns_read);
					if (boot_reldesc == NULL)
						elog(FATAL, "relation not open");
					InsertOneTuple((yyvsp[(2) - (6)].oidval));
					do_end();
				;}
    break;

  case 21:
#line 287 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
					IndexStmt *stmt = makeNode(IndexStmt);
					Oid		relationId;

					elog(DEBUG4, "creating index \"%s\"", (yyvsp[(3) - (11)].str));

					do_start();

					stmt->idxname = (yyvsp[(3) - (11)].str);
					stmt->relation = makeRangeVar(NULL, (yyvsp[(6) - (11)].str), -1);
					stmt->accessMethod = (yyvsp[(8) - (11)].str);
					stmt->tableSpace = NULL;
					stmt->indexParams = (yyvsp[(10) - (11)].list);
					stmt->indexIncludingParams = NIL;
					stmt->options = NIL;
					stmt->whereClause = NULL;
					stmt->excludeOpNames = NIL;
					stmt->idxcomment = NULL;
					stmt->indexOid = InvalidOid;
					stmt->oldNode = InvalidOid;
					stmt->unique = false;
					stmt->primary = false;
					stmt->isconstraint = false;
					stmt->deferrable = false;
					stmt->initdeferred = false;
					stmt->transformed = false;
					stmt->concurrent = false;
					stmt->if_not_exists = false;

					/* locks and races need not concern us in bootstrap mode */
					relationId = RangeVarGetRelid(stmt->relation, NoLock,
												  false);

					DefineIndex(relationId,
								stmt,
								(yyvsp[(4) - (11)].oidval),
								InvalidOid,
								InvalidOid,
								false,
								false,
								false,
								true, /* skip_build */
								false);
					do_end();
				;}
    break;

  case 22:
#line 336 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
					IndexStmt *stmt = makeNode(IndexStmt);
					Oid		relationId;

					elog(DEBUG4, "creating unique index \"%s\"", (yyvsp[(4) - (12)].str));

					do_start();

					stmt->idxname = (yyvsp[(4) - (12)].str);
					stmt->relation = makeRangeVar(NULL, (yyvsp[(7) - (12)].str), -1);
					stmt->accessMethod = (yyvsp[(9) - (12)].str);
					stmt->tableSpace = NULL;
					stmt->indexParams = (yyvsp[(11) - (12)].list);
					stmt->indexIncludingParams = NIL;
					stmt->options = NIL;
					stmt->whereClause = NULL;
					stmt->excludeOpNames = NIL;
					stmt->idxcomment = NULL;
					stmt->indexOid = InvalidOid;
					stmt->oldNode = InvalidOid;
					stmt->unique = true;
					stmt->primary = false;
					stmt->isconstraint = false;
					stmt->deferrable = false;
					stmt->initdeferred = false;
					stmt->transformed = false;
					stmt->concurrent = false;
					stmt->if_not_exists = false;

					/* locks and races need not concern us in bootstrap mode */
					relationId = RangeVarGetRelid(stmt->relation, NoLock,
												  false);

					DefineIndex(relationId,
								stmt,
								(yyvsp[(5) - (12)].oidval),
								InvalidOid,
								InvalidOid,
								false,
								false,
								false,
								true, /* skip_build */
								false);
					do_end();
				;}
    break;

  case 23:
#line 385 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
					elog(DEBUG4, "creating toast table for table \"%s\"", (yyvsp[(6) - (6)].str));

					do_start();

					BootstrapToastTable((yyvsp[(6) - (6)].str), (yyvsp[(3) - (6)].oidval), (yyvsp[(4) - (6)].oidval));
					do_end();
				;}
    break;

  case 24:
#line 397 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
					do_start();
					build_indices();
					do_end();
				;}
    break;

  case 25:
#line 406 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.list) = lappend((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].ielem)); ;}
    break;

  case 26:
#line 407 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.list) = list_make1((yyvsp[(1) - (1)].ielem)); ;}
    break;

  case 27:
#line 412 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
					IndexElem *n = makeNode(IndexElem);
					n->name = (yyvsp[(1) - (2)].str);
					n->expr = NULL;
					n->indexcolname = NULL;
					n->collation = NIL;
					n->opclass = list_make1(makeString((yyvsp[(2) - (2)].str)));
					n->ordering = SORTBY_DEFAULT;
					n->nulls_ordering = SORTBY_NULLS_DEFAULT;
					(yyval.ielem) = n;
				;}
    break;

  case 28:
#line 426 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.ival) = 1; ;}
    break;

  case 29:
#line 427 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.ival) = 0; ;}
    break;

  case 30:
#line 431 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.ival) = 1; ;}
    break;

  case 31:
#line 432 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.ival) = 0; ;}
    break;

  case 32:
#line 436 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.ival) = 1; ;}
    break;

  case 33:
#line 437 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.ival) = 0; ;}
    break;

  case 34:
#line 441 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.oidval) = (yyvsp[(2) - (2)].oidval); ;}
    break;

  case 35:
#line 442 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.oidval) = InvalidOid; ;}
    break;

  case 38:
#line 452 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {
				   if (++numattr > MAXATTR)
						elog(FATAL, "too many columns");
				   DefineAttr((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].str), numattr-1, (yyvsp[(4) - (4)].ival));
				;}
    break;

  case 39:
#line 460 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.ival) = BOOTCOL_NULL_FORCE_NOT_NULL; ;}
    break;

  case 40:
#line 461 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    {  (yyval.ival) = BOOTCOL_NULL_FORCE_NULL; ;}
    break;

  case 41:
#line 462 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.ival) = BOOTCOL_NULL_AUTO; ;}
    break;

  case 42:
#line 466 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.oidval) = atooid((yyvsp[(1) - (1)].str)); ;}
    break;

  case 43:
#line 470 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.oidval) = (yyvsp[(3) - (3)].oidval); ;}
    break;

  case 44:
#line 471 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.oidval) = InvalidOid; ;}
    break;

  case 48:
#line 482 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { InsertOneValue((yyvsp[(1) - (1)].str), num_columns_read++); ;}
    break;

  case 49:
#line 484 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { InsertOneNull(num_columns_read++); ;}
    break;

  case 50:
#line 488 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 51:
#line 489 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 52:
#line 490 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 53:
#line 491 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 54:
#line 492 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 55:
#line 493 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 56:
#line 494 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 57:
#line 495 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 58:
#line 496 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 59:
#line 497 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 60:
#line 498 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 61:
#line 499 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 62:
#line 500 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 63:
#line 501 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 64:
#line 502 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 65:
#line 503 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 66:
#line 504 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 67:
#line 505 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 68:
#line 506 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 69:
#line 507 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;

  case 70:
#line 508 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"
    { (yyval.str) = pstrdup((yyvsp[(1) - (1)].kw)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2074 "bootparse.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 510 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/backend/bootstrap/bootparse.y"


#include "bootscanner.c"

