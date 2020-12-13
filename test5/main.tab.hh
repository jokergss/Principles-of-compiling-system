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
    CONSTRING = 260,
    CONSTCHAR = 261,
    IF = 262,
    ELSE = 263,
    WHILE = 264,
    FOR = 265,
    MAIN = 266,
    RETURN = 267,
    INT = 268,
    CHAR = 269,
    VOID = 270,
    STRING = 271,
    BOOL = 272,
    CONST = 273,
    LPAREN = 274,
    RPAREN = 275,
    LBRACK = 276,
    RBRACK = 277,
    LBRACE = 278,
    RBRACE = 279,
    SEMICOLON = 280,
    COMMA = 281,
    DOT = 282,
    COLON = 283,
    POINT = 284,
    TRUE = 285,
    FALSE = 286,
    ASSIGN = 287,
    ADDASS = 288,
    SUBASS = 289,
    ADD = 290,
    SUB = 291,
    MUL = 292,
    DIV = 293,
    MOD = 294,
    EQUAL = 295,
    NOTEQ = 296,
    GREATER = 297,
    LESS = 298,
    GREEQ = 299,
    LESEQ = 300,
    OR = 301,
    AND = 302,
    NOT = 303,
    PRINTF = 304,
    SCANF = 305,
    UMINUS = 306,
    UPLUS = 307,
    DUOADD = 308,
    DUOSUB = 309,
    QUOTE = 310,
    LOWER_THEN_ELSE = 311
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
