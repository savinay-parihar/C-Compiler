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
#line 20 "semantics.y" /* yacc.c:1921  */

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

#line 110 "semantics.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SEMANTICS_TAB_H_INCLUDED  */
