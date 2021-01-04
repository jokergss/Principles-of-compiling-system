#ifndef TREE_H
#define TREE_H
#define MAXChildNum 4
#include <iostream>
#include <string>
#include "symbol.h"
using namespace std;

extern symbol_table SymbolsTable; 
//节点类型
enum NodeType{
    NODE_PROG,
    NODE_STMT,
    NODE_TYPE,
    NODE_CONST,
    NODE_VAR,
    NODE_BOOL,
    NODE_EXPR, 
    NODE_OP,
    NODE_NULL
};

enum StmtType{
    STMT_IF,
    STMT_WHILE,
    STMT_DECL,
    STMT_ASSIGN,
    STMT_PRINTF,
    STMT_SCANF,

    STMT_FOR,
    STMT_FORCONDITION,
    STMT_RETURN,
    STMT_BREAK,
    STMT_COMPOUND

};

enum OpType{
    OP_EQUAL,
    OP_GT,
    OP_GTE,
    OP_LT,
    OP_LTE,
    OP_NOTEQUAL,
    
    OP_LAND,
    OP_LOR,
    OP_NOT,


    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_INC,
    OP_DEC,
    OP_UMINUS,
    OP_SADD,

    OP_ASSIGN,
    OP_AASSIGN,
    OP_SASSIGN,
    OP_MASSIGN,
    
    OP_LPAREN,
    OP_RPAREN,
    OP_LBRACK,
    OP_RBRACK,
    OP_LBRACE,
    OP_RBRACE,
    OP_COMMA,
    OP_DOT,
    OP_COLON,
    OP_SEMICOLON,
    OP_DQUOTATION,
    OP_SQUOTATION,
    OP_POT,

    OP_ADDRO
};

enum VarType{
    VAR_INTEGER,
    VAR_VOID,
    VAR_BOOL,
    VAR_CHAR,
    VAR_STRING,

    Notype
};

struct Label {
	string true_label;
	string false_label;
	string begin_label;
	string next_label;
};

struct TreeNode {
    int nodeID; //节点序号
    int line; // 行号
    int childNum;
    NodeType nodeType; // 节点类型

    TreeNode *child[MAXChildNum];
    TreeNode *sibling = nullptr;

    void addChild(TreeNode *);
    void addSibling(TreeNode *);

    void printAST();//打印语法树结点

    int int_val; // 节点为常量时，相对应的类型存储其值
    bool bool_val; // 布尔常量
    string str_val;
    string char_val;

    StmtType stmtType; // 节点为其他类型时，存储其内容
    OpType opType; // 节点为表达式节点
    VarType varType;

    VarType type; // 用于存储id，expression，const的类型，与varType有一定功能上的重复
    string var_name; // 变量名

    TreeNode(NodeType type, int lineno);

    int temp_var=0; // 记录节点临时变量的序号，也就是生成汇编时的临时变量tn
    Label label;
    int const_str=0; // 记录所有出现的字符以及字符串常量的序号，也就是生成汇编时的常量STRn

    void type_check(); // 类型检查
};

class tree{
public:
	TreeNode *root;
	int label_seq = 0; // label的总数

	string new_label(void); // 生成一个新序号的label
	void recursive_get_label(TreeNode *t); // 递归生成label
	void stmt_get_label(TreeNode *t); // 为NODE_STMT生成label
	void expr_get_label(TreeNode *t); // 为NODE_EXPR生成label

	void gen_decl(TreeNode *t); // 声明变量，均生成为bss段，不为其声明类型，赋值时自动获得类型
	void recursive_gen_code(TreeNode *t); // 递归生成汇编代码
	void stmt_gen_code(TreeNode *t); // 为NODE_STMT生成汇编代码
	void expr_gen_code(TreeNode *t); // 为NODE_EXPR生成汇编代码

	void get_label(void); // 生成label
	void gen_code();
    tree(TreeNode *node){
        root = node;
    }
};
#endif