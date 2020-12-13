%option noyywrap
%{
    #include"common.h"
    #include"main.tab.hh"
    int lineno=0;
    vector <IDAttributes> SymbolsTable;
    int flag;
    bool for_flag=false;
%}

INTEGER (0|[1-9][0-9]*)
ID [[:alpha:]_][[:alpha:][:digit:]_]*

EOL (\r\n|\n)
WHITE [\t ]
EXEGESIS (\/\/.*\n)|(\/\*(\n|.)*?\*\/)
NOTE (\/\/.*\n?)
CONSTRING (\".*\")
CONSTCHAR (\'.?\')
%%

"true" {
    TreeNode *node = new TreeNode(NODE_BOOL,lineno);
    node->bool_val = true;
    node->str_val = "true";
    yylval = node;
    return TRUE;
}
"false" {
    TreeNode *node = new TreeNode(NODE_BOOL,lineno);
    node->bool_val = false;
    node->str_val = "false";
    yylval = node;
    return FALSE;
}

"int" return INT;
"char" return CHAR;
"void" return VOID;
"string" return STRING;
"bool" return BOOL;
"const" return CONST;

"if" return IF;
"while" return WHILE;
"else" return ELSE;
"for" return FOR;
"main" return MAIN;
"return" return RETURN;

"printf" return PRINTF;
"scanf" return SCANF;

"=" return ASSIGN;
"+=" return ADDASS;
"-=" return SUBASS;

"+" return ADD;
"-" return SUB;
"*" return MUL;
"/" return DIV;
"%" return MOD;
"++" return DUOADD;
"--" return DUOSUB;

"!" return NOT;
"||" return OR;
"&&" return AND;
"&" return QUOTE;

"==" return EQUAL;
">" return GREATER;
"<" return LESS;
">=" return GREEQ;
"<=" return LESEQ;
"!=" return NOTEQ;

";" return SEMICOLON;
"," return COMMA;
"." return DOT;
":" return COLON;
"->" return POINT;
"(" return LPAREN;
")" return RPAREN;
"[" return LBRACK;
"]" return RBRACK;
"{" {
    if(for_flag){
        flag = SymbolsTable.size()-1;
        for_flag=false;
    }
    else
        flag = SymbolsTable.size();
    return LBRACE;
}
"}" {
    int t = SymbolsTable.size()-flag;
    for(int i=0;i<t;i++){
        SymbolsTable.pop_back();
    }
    return RBRACE;
}

{INTEGER} {
    TreeNode *node = new TreeNode(NODE_CONST,lineno);
    node->int_val = atoi(yytext);
    node->str_val = string(yytext);
    node->var_name = "Interger";
    yylval = node;
    return INTEGER;
}
{ID} {
    TreeNode *node = new TreeNode(NODE_VAR,lineno);
    node->var_name = string(yytext);
    yylval = node;
    return ID;
}
{CONSTRING} {
    TreeNode *node = new TreeNode(NODE_CONST,lineno);
    node->var_name = string(yytext);
    node->var_name = "ConstString";
    yylval = node;
    return CONSTRING;
}
{CONSTCHAR} {
    TreeNode *node = new TreeNode(NODE_CONST, lineno);
    string s = string(yytext);
    node->char_val = s.at(1);
    node->str_val = s.substr(1,1);
    node->var_name = "ConstChar";
    yylval = node;
    return CONSTCHAR;
}
{EOL} {++lineno;}
{WHITE}
{EXEGESIS}
{NOTE}
%%