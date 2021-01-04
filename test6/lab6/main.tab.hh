/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
