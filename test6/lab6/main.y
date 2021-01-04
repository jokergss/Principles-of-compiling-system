%{
    #include"common.h"
    extern TreeNode * root;
    int yylex();
    int yyerror( char const * );
    extern int lineno;
    extern symbol_table SymbolsTable;
%}
%defines

%start program

%token ID INTEGER ConstStr ConstChar
%token IF ELSE WHILE FOR SWITCH CASE MAIN CONTINUS BREAK RETURN 
%token INT VOID CHAR STRING BOOL CONST
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMICOLON COMMA DOT COLON POT
%token TRUE FALSE
%token ASSIGN AASSIGN SASSIGN MASSIGN
%token ADD SUB MUL DIV MOD
%token EQUAL NOTEQUAL GT GTE LT LTE
%token LAND LOR NOT
%token PRINTF SCANF

%right COMMA
%right ASSIGN AASSIGN SASSIGN MASSIGN
%right LAND LOR
%left EQUAL NOTEQUAL
%left GT GTE LT LTE
%left ADD SUB
%left MUL DIV MOD
%left INC DEC
%right NOT UMINUS ADDRO SADD
%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE 
%%
program
    : statements {root=new TreeNode(NODE_PROG, $1->line);root->addChild($1);}
    ;
statements
    : statement {$$=$1;}
    | statements statement{$$=$1;$$->addSibling($2);}
    ;
statement
    : declare {$$=$1;}
    | instruction {$$=$1;}
    | if_else {$$=$1;}
    | while {$$=$1;}
    | for {$$=$1;}
    | INT MAIN LPAREN RPAREN compound_stmt {$$=$5;}
    ;
compound_stmt
    : LBRACE statements RBRACE {
        TreeNode *node=new TreeNode(NODE_STMT, $2->line);
        node->stmtType=STMT_COMPOUND;
        node->addChild($2);
        $$=node;
    }
    ;
if_else
    : IF bool_statment compound_stmt %prec LOWER_THEN_ELSE {
        TreeNode *node=new TreeNode(NODE_STMT, $2->line);
        node->stmtType=STMT_IF;
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
    | IF bool_statment compound_stmt ELSE compound_stmt {
        TreeNode *node=new TreeNode(NODE_STMT, $2->line);
        node->stmtType=STMT_IF;
        node->addChild($2);
        node->addChild($3);
        node->addChild($5);
        $$=node;
    }
    | IF bool_statment compound_stmt ELSE if_else {
        TreeNode *node=new TreeNode(NODE_STMT, $2->line);
        node->stmtType=STMT_IF;
        node->addChild($2);
        node->addChild($3);
        node->addChild($5);
        $$=node;
    }
    ;
while
    : WHILE bool_statment compound_stmt {
        TreeNode *node=new TreeNode(NODE_STMT, $2->line);
        node->stmtType=STMT_WHILE;
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
    ;
for
    : FOR LPAREN for_statment RPAREN compound_stmt {
        TreeNode *node=new TreeNode(NODE_STMT, $3->line);
        node->stmtType=STMT_FOR;
        node->addChild($3);
        node->addChild($5);
        $$=node;
    }
    ;
for_statment
    : declare bool_expr SEMICOLON expr {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_FORCONDITION;
        node->addChild($1);
        node->addChild($2);
        node->addChild($4);
        $$=node;
    }
    | expr SEMICOLON bool_expr SEMICOLON expr{
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_FORCONDITION;
            node->addChild($1);
            node->addChild($3);
            node->addChild($5);
            $$=node;
    }
    ;
bool_statment
    : LPAREN bool_expr RPAREN {$$=$2;}
    ;
declare
    : type id_list SEMICOLON {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_DECL;
        TreeNode *t=$2;
        while(t){
            if(t->nodeType==NODE_EXPR){// 声明变量且带有赋值表达式
                t->child[0]->varType=$1->varType;
                t->child[0]->type=$1->type;
                if(SymbolsTable.lookup(t->child[0]->var_name)==-1)
                    SymbolsTable.insert(t->child[0]->var_name, t->child[0]->varType);
            }else{// 声明变量不带有赋值表达式
                t->varType=$1->varType;
                t->type=$1->type;
                if(SymbolsTable.lookup(t->var_name)==-1)
                    SymbolsTable.insert(t->var_name, t->varType);
            }
            t=t->sibling;
        }
        node->addChild($1);
        node->addChild($2);
        $$=node;
    }
    ;
instruction
    : expr SEMICOLON {
        $$=$1;  
    }
    | RETURN expr SEMICOLON {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_RETURN;
        node->addChild($2);
        $$=node;
    }
    | BREAK SEMICOLON {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_BREAK;
        $$=node;
    }
    | printf SEMICOLON {$$=$1;}
    | scanf SEMICOLON {$$=$1;}
    ;
id_list
    : id_list COMMA expr {
        $$=$1;
        $$->addSibling($3);
    }
    | expr {$$=$1;}
    ;
printf
    : PRINTF LPAREN expr RPAREN {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_PRINTF;
        node->addChild($3);
        $$=node;
    }
    ;
scanf
    : SCANF LPAREN expr RPAREN {
        TreeNode *node=new TreeNode(NODE_STMT, lineno);
        node->stmtType=STMT_SCANF;
        node->addChild($3);
        $$=node;
    }
    ;
bool_expr
    : TRUE {$$=$1;}
    | FALSE {$$=$1;}
    | expr {$$=$1;}
    | expr EQUAL expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_EQUAL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | expr GT expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_GT;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | expr GTE expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_GTE;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | expr LT expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_LT;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | expr LTE expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_LTE;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | expr NOTEQUAL expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_NOTEQUAL;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | NOT bool_expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_NOT;
        node->addChild($2);
        $$=node;        
    }
    | bool_expr LAND bool_expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_LAND;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | bool_expr LOR bool_expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_LOR;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | LPAREN bool_expr RPAREN{
        $$=$2;
    }
    |  {
        TreeNode *node=new TreeNode(NODE_NULL, lineno);
        $$=node;
    }
    ;
expr
    : ID {$$=$1;}
    | INTEGER {$$=$1;}
    | ConstStr {$$=$1;}
    | ConstChar {$$=$1;}
    | ConstStr COMMA id_list {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_COMMA;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | expr ADD expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_ADD;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
    }
    | expr SUB expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_SUB;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
    }
    | expr MUL expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_MUL;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
    }
    | expr DIV expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_DIV;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
    }
    | expr MOD expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_MOD;
        node->addChild($1);
        node->addChild($3);
        $$=node;   
    }
    | ADD expr %prec SADD {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_SADD;
        node->addChild($2);
        $$=node;
    }
    | SUB expr %prec UMINUS {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_UMINUS;
        node->addChild($2);
        $$=node;
    }
    | ADDRO ID {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_ADDRO;
        node->addChild($2);
        $$=node;
    }
    | ID INC {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_INC;
        node->addChild($1);
        $$=node;
    }
    | ID DEC {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_DEC;
        node->addChild($1);
        $$=node;
    }
    | ID ASSIGN expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_ASSIGN;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
    | ID AASSIGN expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_AASSIGN;
        node->addChild($1);
        node->addChild($3);
        $$=node;  
    }
    | ID MASSIGN expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_MASSIGN;
        node->addChild($1);
        node->addChild($3);
        $$=node;  
    }
    | ID SASSIGN expr {
        TreeNode *node=new TreeNode(NODE_EXPR, lineno);
        node->opType=OP_SASSIGN;
        node->addChild($1);
        node->addChild($3);
        $$=node;  
    }
    | LPAREN expr RPAREN{
        $$=$2;
    }
    |  {
        TreeNode *node=new TreeNode(NODE_NULL, lineno);
        $$=node;
    }
    ;
type
    : INT {
        TreeNode *node=new TreeNode(NODE_TYPE, lineno);
        node->varType=VAR_INTEGER;
        node->type=VAR_INTEGER;
        $$=node;
    }
    | VOID {
        TreeNode *node=new TreeNode(NODE_TYPE, lineno);
        node->varType=VAR_VOID;
        node->type=VAR_VOID;
        $$=node;         
    }
    | CHAR {
        TreeNode *node=new TreeNode(NODE_TYPE, lineno);
        node->varType=VAR_CHAR;
        node->type=VAR_CHAR;
        $$=node;   
    }
    | BOOL {
        TreeNode *node=new TreeNode(NODE_TYPE, lineno);
        node->varType=VAR_BOOL;
        node->type=VAR_BOOL;
        $$=node;   
    }
    ;

%%