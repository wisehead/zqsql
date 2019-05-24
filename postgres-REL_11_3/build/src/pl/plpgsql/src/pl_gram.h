/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     FCONST = 259,
     SCONST = 260,
     BCONST = 261,
     XCONST = 262,
     Op = 263,
     ICONST = 264,
     PARAM = 265,
     TYPECAST = 266,
     DOT_DOT = 267,
     COLON_EQUALS = 268,
     EQUALS_GREATER = 269,
     LESS_EQUALS = 270,
     GREATER_EQUALS = 271,
     NOT_EQUALS = 272,
     T_WORD = 273,
     T_CWORD = 274,
     T_DATUM = 275,
     LESS_LESS = 276,
     GREATER_GREATER = 277,
     K_ABSOLUTE = 278,
     K_ALIAS = 279,
     K_ALL = 280,
     K_ARRAY = 281,
     K_ASSERT = 282,
     K_BACKWARD = 283,
     K_BEGIN = 284,
     K_BY = 285,
     K_CALL = 286,
     K_CASE = 287,
     K_CLOSE = 288,
     K_COLLATE = 289,
     K_COLUMN = 290,
     K_COLUMN_NAME = 291,
     K_COMMIT = 292,
     K_CONSTANT = 293,
     K_CONSTRAINT = 294,
     K_CONSTRAINT_NAME = 295,
     K_CONTINUE = 296,
     K_CURRENT = 297,
     K_CURSOR = 298,
     K_DATATYPE = 299,
     K_DEBUG = 300,
     K_DECLARE = 301,
     K_DEFAULT = 302,
     K_DETAIL = 303,
     K_DIAGNOSTICS = 304,
     K_DO = 305,
     K_DUMP = 306,
     K_ELSE = 307,
     K_ELSIF = 308,
     K_END = 309,
     K_ERRCODE = 310,
     K_ERROR = 311,
     K_EXCEPTION = 312,
     K_EXECUTE = 313,
     K_EXIT = 314,
     K_FETCH = 315,
     K_FIRST = 316,
     K_FOR = 317,
     K_FOREACH = 318,
     K_FORWARD = 319,
     K_FROM = 320,
     K_GET = 321,
     K_HINT = 322,
     K_IF = 323,
     K_IMPORT = 324,
     K_IN = 325,
     K_INFO = 326,
     K_INSERT = 327,
     K_INTO = 328,
     K_IS = 329,
     K_LAST = 330,
     K_LOG = 331,
     K_LOOP = 332,
     K_MESSAGE = 333,
     K_MESSAGE_TEXT = 334,
     K_MOVE = 335,
     K_NEXT = 336,
     K_NO = 337,
     K_NOT = 338,
     K_NOTICE = 339,
     K_NULL = 340,
     K_OPEN = 341,
     K_OPTION = 342,
     K_OR = 343,
     K_PERFORM = 344,
     K_PG_CONTEXT = 345,
     K_PG_DATATYPE_NAME = 346,
     K_PG_EXCEPTION_CONTEXT = 347,
     K_PG_EXCEPTION_DETAIL = 348,
     K_PG_EXCEPTION_HINT = 349,
     K_PRINT_STRICT_PARAMS = 350,
     K_PRIOR = 351,
     K_QUERY = 352,
     K_RAISE = 353,
     K_RELATIVE = 354,
     K_RESET = 355,
     K_RESULT_OID = 356,
     K_RETURN = 357,
     K_RETURNED_SQLSTATE = 358,
     K_REVERSE = 359,
     K_ROLLBACK = 360,
     K_ROW_COUNT = 361,
     K_ROWTYPE = 362,
     K_SCHEMA = 363,
     K_SCHEMA_NAME = 364,
     K_SCROLL = 365,
     K_SET = 366,
     K_SLICE = 367,
     K_SQLSTATE = 368,
     K_STACKED = 369,
     K_STRICT = 370,
     K_TABLE = 371,
     K_TABLE_NAME = 372,
     K_THEN = 373,
     K_TO = 374,
     K_TYPE = 375,
     K_USE_COLUMN = 376,
     K_USE_VARIABLE = 377,
     K_USING = 378,
     K_VARIABLE_CONFLICT = 379,
     K_WARNING = 380,
     K_WHEN = 381,
     K_WHILE = 382
   };
#endif
/* Tokens.  */
#define IDENT 258
#define FCONST 259
#define SCONST 260
#define BCONST 261
#define XCONST 262
#define Op 263
#define ICONST 264
#define PARAM 265
#define TYPECAST 266
#define DOT_DOT 267
#define COLON_EQUALS 268
#define EQUALS_GREATER 269
#define LESS_EQUALS 270
#define GREATER_EQUALS 271
#define NOT_EQUALS 272
#define T_WORD 273
#define T_CWORD 274
#define T_DATUM 275
#define LESS_LESS 276
#define GREATER_GREATER 277
#define K_ABSOLUTE 278
#define K_ALIAS 279
#define K_ALL 280
#define K_ARRAY 281
#define K_ASSERT 282
#define K_BACKWARD 283
#define K_BEGIN 284
#define K_BY 285
#define K_CALL 286
#define K_CASE 287
#define K_CLOSE 288
#define K_COLLATE 289
#define K_COLUMN 290
#define K_COLUMN_NAME 291
#define K_COMMIT 292
#define K_CONSTANT 293
#define K_CONSTRAINT 294
#define K_CONSTRAINT_NAME 295
#define K_CONTINUE 296
#define K_CURRENT 297
#define K_CURSOR 298
#define K_DATATYPE 299
#define K_DEBUG 300
#define K_DECLARE 301
#define K_DEFAULT 302
#define K_DETAIL 303
#define K_DIAGNOSTICS 304
#define K_DO 305
#define K_DUMP 306
#define K_ELSE 307
#define K_ELSIF 308
#define K_END 309
#define K_ERRCODE 310
#define K_ERROR 311
#define K_EXCEPTION 312
#define K_EXECUTE 313
#define K_EXIT 314
#define K_FETCH 315
#define K_FIRST 316
#define K_FOR 317
#define K_FOREACH 318
#define K_FORWARD 319
#define K_FROM 320
#define K_GET 321
#define K_HINT 322
#define K_IF 323
#define K_IMPORT 324
#define K_IN 325
#define K_INFO 326
#define K_INSERT 327
#define K_INTO 328
#define K_IS 329
#define K_LAST 330
#define K_LOG 331
#define K_LOOP 332
#define K_MESSAGE 333
#define K_MESSAGE_TEXT 334
#define K_MOVE 335
#define K_NEXT 336
#define K_NO 337
#define K_NOT 338
#define K_NOTICE 339
#define K_NULL 340
#define K_OPEN 341
#define K_OPTION 342
#define K_OR 343
#define K_PERFORM 344
#define K_PG_CONTEXT 345
#define K_PG_DATATYPE_NAME 346
#define K_PG_EXCEPTION_CONTEXT 347
#define K_PG_EXCEPTION_DETAIL 348
#define K_PG_EXCEPTION_HINT 349
#define K_PRINT_STRICT_PARAMS 350
#define K_PRIOR 351
#define K_QUERY 352
#define K_RAISE 353
#define K_RELATIVE 354
#define K_RESET 355
#define K_RESULT_OID 356
#define K_RETURN 357
#define K_RETURNED_SQLSTATE 358
#define K_REVERSE 359
#define K_ROLLBACK 360
#define K_ROW_COUNT 361
#define K_ROWTYPE 362
#define K_SCHEMA 363
#define K_SCHEMA_NAME 364
#define K_SCROLL 365
#define K_SET 366
#define K_SLICE 367
#define K_SQLSTATE 368
#define K_STACKED 369
#define K_STRICT 370
#define K_TABLE 371
#define K_TABLE_NAME 372
#define K_THEN 373
#define K_TO 374
#define K_TYPE 375
#define K_USE_COLUMN 376
#define K_USE_VARIABLE 377
#define K_USING 378
#define K_VARIABLE_CONFLICT 379
#define K_WARNING 380
#define K_WHEN 381
#define K_WHILE 382




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 120 "/Users/chenhui13/github/postgreSQL.bak/postgres-REL_11_3/build/../src/pl/plpgsql/src/pl_gram.y"
{
		core_YYSTYPE			core_yystype;
		/* these fields must match core_YYSTYPE: */
		int						ival;
		char					*str;
		const char				*keyword;

		PLword					word;
		PLcword					cword;
		PLwdatum				wdatum;
		bool					boolean;
		Oid						oid;
		struct
		{
			char *name;
			int  lineno;
		}						varname;
		struct
		{
			char *name;
			int  lineno;
			PLpgSQL_datum   *scalar;
			PLpgSQL_datum   *row;
		}						forvariable;
		struct
		{
			char *label;
			int  n_initvars;
			int  *initvarnos;
		}						declhdr;
		struct
		{
			List *stmts;
			char *end_label;
			int   end_label_location;
		}						loop_body;
		List					*list;
		PLpgSQL_type			*dtype;
		PLpgSQL_datum			*datum;
		PLpgSQL_var				*var;
		PLpgSQL_expr			*expr;
		PLpgSQL_stmt			*stmt;
		PLpgSQL_condition		*condition;
		PLpgSQL_exception		*exception;
		PLpgSQL_exception_block	*exception_block;
		PLpgSQL_nsitem			*nsitem;
		PLpgSQL_diag_item		*diagitem;
		PLpgSQL_stmt_fetch		*fetch;
		PLpgSQL_case_when		*casewhen;
}
/* Line 1529 of yacc.c.  */
#line 354 "pl_gram.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE plpgsql_yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE plpgsql_yylloc;
