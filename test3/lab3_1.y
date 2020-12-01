%{
#include <stdio.h>
#include <stdlib.h>
#ifndef YYSTYPE
#define YYSTYPE double
#endif
int yylex();
extern int yyparse();
FILE* yyin;
void yyerror(const char* s);
%}

%token NUMBER
%token ADD
%token SUBTR
%token MULTI
%token DIVIS
%left ADD SUBTR
%left MULTI DIVIS
%right UMINUS


%%


lines   :   lines expr '=' {printf("%f\n",$2); }
        |   lines '='
        |
        ;

expr    :   expr ADD expr  { $$=$1+$3;}
        |   expr SUBTR expr  { $$=$1-$3; }
        |   expr MULTI expr  { $$=$1*$3; }
        |   expr DIVIS expr  { $$=$1/$3; }
        |   '('expr')'     { $$=$2; }
        |   SUBTR expr %prec UMINUS    { $$=-$2; }
        |   NUMBER      {$$=$1;}
        ;


%%

int yylex()
{
    int t;
    while(1)
    {
        t=getchar();
        if(t==' '||t=='\t'||t=='\n')
        {
            //do nothing
        }
        else if(t>='0'&&t<='9')
        {
            yylval=0;
            while(t>='0'&&t<='9')
            {
                yylval=yylval*10+t-'0';
                t=getchar();
            }
            ungetc(t,stdin);
            return NUMBER;
        }
        else if(t=='+')
        {
            return ADD;
        }
        else if(t=='-')
        {
            return SUBTR;
        }
        else if(t=='*')
        {
            return MULTI;
        }
        else if(t=='/')
        {
            return DIVIS;
        }
        else
        {
            return t;
        }
    }
}

int main(void)
{
    yyin=stdin;
    do{
        yyparse();
    }while(!feof(yyin));
    return 0;
}

void yyerror(const char* s)
{
    fprintf(stderr,"Parse error:%s\n",s);
    exit(1);
}