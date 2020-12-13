#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<string>

using namespace std;

#define MAXnum 5

enum NodeType{
    NODE_CONST,  
    NODE_BOOL,
    NODE_VAR,
    NODE_EXPR,
    NODE_TYPE,
    NODE_STMT,
    NODE_PROG,
    NODE_OP
};

enum StmtType{
    STMT_IF,
    STMT_WHILE,
    STMT_DECL,
    STMT_ASSIGN,
    STMT_PRINTF,
    STMT_SCANF,
    STMT_FOR,
    STMT_CONDITION
};

enum OpType{
    OP_EQUAL,
    OP_NOTEQ,
    OP_ASSIGN,
    OP_NOT,
    OP_OR,
    OP_AND,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_GT,
    OP_LT,
    OP_GE,
    OP_LE,
    OP_NE,
    OP_COMMA,
    OP_UMINUS,
    OP_UPLUS,
    OP_QUOTE,
    OP_DUOADD,
    OP_DUOSUB,
    OP_ADDASS,
    OP_SUBASS
};

enum VarType{
    VAR_INTEGER,
    VAR_CHAR,
    VAR_STRING,
    VAR_VOID
};

struct TreeNode {
    int nodeID;
    int childnum;
    int line;
    NodeType nodeType;

    TreeNode *child[MAXnum];
    TreeNode *sibling = nullptr;

    void addChild(TreeNode *);
    void addSibling(TreeNode *);

    void genNodeId();//从根节点开始逐个赋Id 实现方式同学们可以自行修改

    void printAST();//打印语法树结点
    /***
     * 以下的几个函数皆为在printAST过程中辅助输出使用
     * 同学们可以根据需要自己使用其他方法
    ***/
    void printNodeInfo();
    void printNodeConnection();
    string nodeTypeInfo();

    int int_val;
    bool bool_val;
    string str_val;
    char char_val;
    StmtType stmtType;
    OpType opType;
    VarType varType;
    string var_name;

    TreeNode(NodeType type,int lineno);
    
    string NodeTypeTostring(NodeType type);
    string StmtTypeTostring(StmtType type);
    string opTypeTostring(OpType type);
    string VarTypeTostring(VarType type);
};
#endif