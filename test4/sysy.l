%option noyywrap
%top{
#include<map>
#include<iomanip>
}
%{
    int chars=0,words=0,lines=0,nums=0;
    char buffer[20][10];        //store ID
    int IDs=0;                 //give ID a num to differentiate ID
%}

DIV "\/"
MUL "\*"
SUB "\-"
PLUS "\+"
EQ "\=\="
ASSIGN "\="
SEMICOLON ";"
LPAREN "("
RPAREN ")"
LBRACE "{"
RBRACE "}"
INT int
<<<<<<< HEAD
MAIN main
IF if
while while
RETURN return
=======
IF if
while while
>>>>>>> 7e86b995808bd6e9769b554746efdb21d4ba16ff
number  [0-9]+
ID  [a-z]+[a-zA-Z0-9]+
line \n
char    .
commentbegin "/*"
commentelement .|\n
commentend "*/"
%x COMMENT

%%
{DIV}       {std::cout<<std::setw(8)<<"DIV"<<std::setw(8)<<"/"<<std::endl;chars++;}
{MUL}       {std::cout<<std::setw(8)<<"MUL"<<std::setw(8)<<"*"<<std::endl;chars++;}
{SUB}       {std::cout<<std::setw(8)<<"SUB"<<std::setw(8)<<"-"<<std::endl;chars++;}
{PLUS}      {std::cout<<std::setw(8)<<"PLUS"<<std::setw(8)<<"+"<<std::endl;chars++;}
{EQ}        {std::cout<<std::setw(8)<<"EQ"<<std::setw(8)<<"=="<<std::endl;chars++;}
{ASSIGN}    {std::cout<<std::setw(8)<<"ASSIGN"<<std::setw(8)<<yytext<<std::endl;chars++;}
{SEMICOLON} {std::cout<<std::setw(8)<<"SEMICOLON"<<std::setw(8)<<yytext<<std::endl;chars++;}
{LPAREN}    {std::cout<<std::setw(8)<<"LPAREN"<<std::setw(8)<<yytext<<std::endl;chars++;}
{RPAREN}    {std::cout<<std::setw(8)<<"RPAREN"<<std::setw(8)<<yytext<<std::endl;chars++;}
{LBRACE}    {std::cout<<std::setw(8)<<"LBRACE"<<std::setw(8)<<yytext<<std::endl;chars++;}
{RBRACE}    {std::cout<<std::setw(8)<<"RBRACE"<<std::setw(8)<<yytext<<std::endl;chars++;}
<<<<<<< HEAD
{RETURN}    {std::cout<<std::setw(8)<<"RETURN"<<std::setw(8)<<yytext<<std::endl;chars++;}
{INT}       {std::cout<<std::setw(8)<<"INT"<<std::setw(8)<<"int"<<std::endl;words++;chars=chars+3;}
{MAIN}      {std::cout<<std::setw(8)<<"MAIN"<<std::setw(8)<<"main"<<std::endl;words++;chars=chars+4;}
{IF}        {std::cout<<std::setw(8)<<"IF"<<std::setw(8)<<"if"<<std::endl;words++;chars=chars+2;}
=======
{INT}       {std::cout<<std::setw(8)<<"INT"<<std::setw(8)<<"int"<<std::endl;words++;chars=chars+3;}
{IF}        {std::cout<<std::setw(8)<<"IF"<<std::setw(8)<<"if"<<std::endl;words++;chars=cahrs+2;}
>>>>>>> 7e86b995808bd6e9769b554746efdb21d4ba16ff
{while}     {std::cout<<std::setw(8)<<"WHILE"<<std::setw(8)<<"while"<<std::endl;words++;chars=chars+5;}
{number}    {std::cout<<std::setw(8)<<"NUMBER"<<std::setw(8)<<yytext<<std::setw(8)<<nums<<std::endl;words++;chars+=strlen(yytext);nums++;}
{ID}        {
    int temp=0;
    for(temp;temp<20;temp++)
    {
        if(strcmp(buffer[temp],yytext)==0)
        {
            std::cout<<std::setw(8)<<"ID"<<std::setw(8)<<yytext<<std::setw(8)<<temp<<std::endl;
            IDs--;
            break;
        }
    }
    if(temp==20)
    {
        strcpy(buffer[IDs],yytext);
        std::cout<<std::setw(8)<<"ID"<<std::setw(8)<<yytext<<std::setw(8)<<IDs<<std::endl;
    }
    words++;
    chars+=strlen(yytext);
    IDs++;
}
{line}      {lines++;}
{char}      {chars++;}
{commentbegin}  {BEGIN COMMENT;}
<COMMENT>{commentelement}   {}
<COMMENT>{commentend}   {BEGIN INITIAL;}
%%

int main(){
    yyFlexLexer lexer;
    lexer.yylex();
    std::cout<<std::setw(8)<<lines<<std::setw(8)<<words<<std::setw(8)<<chars<<std::setw(8)<<nums<<std::endl;
<<<<<<< HEAD
    std::cout<<std::setw(8)<<IDs;
=======
    std::cout<<std::setw(8)<<IDs
>>>>>>> 7e86b995808bd6e9769b554746efdb21d4ba16ff
    return 0;
}