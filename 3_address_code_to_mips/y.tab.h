/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
