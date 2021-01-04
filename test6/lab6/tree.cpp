#include "tree.h"
// 这个标志位会在遍历语法树进入变量声明的节点(NODE_STMT&&STMT_DECL)时，置为true；
// 当遍历到ID节点时，可以使得不检查符号表
// 用于识别变量先使用再声明的错误
bool decl_flag = false;
// 用于存储所有的字符和字符串常量，如：'a'
// "test:\n""(存储了引号，方便汇编的生成)
string str_table[10];
// 记录临时变量的总数
int temp_var_all = 0;
// 记录字符和字符串常量的总和
int const_str_all = 0;
// 生成汇编除法代码时会生成一个label，记录这个label的总数
int m = 0;

TreeNode::TreeNode(NodeType nodeType, int lineno) {
    this->nodeType = nodeType;
    line = lineno;
    childNum = 0;
    type = Notype;
    for(int i = 0; i < MAXChildNum; i++) {
        child[i] = nullptr;
    }
    label.begin_label = label.false_label = label.next_label =
        label.true_label = "";
}

void TreeNode::addChild(TreeNode *t) {
    if(childNum < MAXChildNum) {
        child[childNum] = t;
        childNum++;
    }
}

void TreeNode::addSibling(TreeNode *t) {
    if(!sibling) {
        sibling = t;
    } else {
        TreeNode *temp = sibling;
        while(temp->sibling) {
            temp = temp->sibling;
        }
        temp->sibling = t;
    }
}

void TreeNode::printAST() {
    // 为每个表达式节点生成临时变量
    if(nodeType == NODE_EXPR) {
        if(opType == OP_ASSIGN) {
            temp_var_all++;
            temp_var = temp_var_all - 1;
        } else {
            if(child[0]->nodeType == NODE_EXPR) {
                temp_var_all++;
                child[0]->temp_var = temp_var_all - 1;
            }
            if(child[1] != NULL && child[1]->nodeType == NODE_EXPR) {
                temp_var_all++;
                child[0]->temp_var = temp_var_all - 1;
            }
        }
    }
    // 为每个字符和字符串节点生成常量
    if(nodeType == NODE_CONST && (type == VAR_CHAR || type == VAR_STRING)) {
        str_table[const_str_all] = str_val;
        const_str_all++;
        const_str = const_str_all - 1;
    }
    // 递归到声明节点时将decl_flag标志位置为true
    if(nodeType == NODE_STMT && stmtType == STMT_DECL)
        decl_flag = true;
    int i = 0;
    while(child[i]) {
        child[i]->printAST();
        i++;
    }
    type_check();
    if(sibling)
        sibling->printAST();
}

void TreeNode::type_check() {
    int i = 0;
    TreeNode *t = child[1];
    switch(nodeType) {
    case NODE_STMT:
        switch(stmtType) {
        case STMT_IF:
            if(child[0]->type != VAR_BOOL)
                cerr << "Bad boolean type at line: " << line << endl;
            break;
        case STMT_WHILE:
            if(child[0]->type != VAR_BOOL)
                cerr << "Bad boolean type at line: " << line << endl;
            break;
        case STMT_FORCONDITION:
            if(child[1]->type != VAR_BOOL && child[1]->nodeType != NODE_NULL)
                cerr << "Bad boolean type at line: " << line << endl;
            break;
        case STMT_DECL:
            while(t) {
                // 检查每一个兄弟节点， 并将其defined属性置为true
                int j = 0;
                if(t->nodeType == NODE_EXPR) { // 声明变量且带有赋值表达式
                    if((j = SymbolsTable.lookup(t->child[0]->var_name)) != -1) {
                        if(!SymbolsTable.table[j].defined)
                            SymbolsTable.table[j].defined = true;
                        else
                            cerr << "variable repeat define at line: " << line
                                 << endl;
                    }
                } else { // 声明变量不带有赋值表达式
                    if((j = SymbolsTable.lookup(t->var_name)) != -1) {
                        if(!SymbolsTable.table[j].defined)
                            SymbolsTable.table[j].defined = true;
                        else
                            cerr << "variable repeat define at line: " << line
                                 << endl;
                    }
                }
                t = t->sibling;
            }
            decl_flag = false;
            break;
        default:
            break;
        }
        break;
    case NODE_EXPR:
        switch(opType) {
        case OP_ADD:
            if(child[0]->type != child[1]->type)
                cerr << "add factor error at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_SUB:
            if(child[0]->type != child[1]->type ||
               child[0]->type != VAR_INTEGER)
                cerr << "sub factor error at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_MUL:
            if(child[0]->type != child[1]->type ||
               child[0]->type != VAR_INTEGER)
                cerr << "mul factor error at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_DIV:
            if(child[0]->type != child[1]->type ||
               child[0]->type != VAR_INTEGER)
                cerr << "DIV factor error at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_MOD:
            if(child[0]->type != child[1]->type ||
               child[0]->type != VAR_INTEGER)
                cerr << "mod factor error at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_SADD:
            if(child[0]->type != VAR_INTEGER)
                cerr << "single add error at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_UMINUS:
            if(child[0]->type != VAR_INTEGER)
                cerr << "uminus factor at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_ADDRO:
            type = child[0]->type;
            break;
        case OP_INC:
            if(child[0]->type != VAR_INTEGER)
                cerr << "increase error at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_DEC:
            if(child[0]->type != VAR_INTEGER)
                cerr << "decrease error at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_ASSIGN:
            if(child[0]->type != child[1]->type)
                cerr << "assign factor error at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_AASSIGN:
            if(child[0]->type != child[1]->type ||
               child[0]->type != VAR_INTEGER)
                cerr << "add assign factor error at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_MASSIGN:
            if(child[0]->type != child[1]->type ||
               child[0]->type != VAR_INTEGER)
                cerr << "mul assign factor error at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_SASSIGN:
            if(child[0]->type != child[1]->type ||
               child[0]->type != VAR_INTEGER)
                cerr << "sub assign factor error at line: " << line << endl;
            type = child[0]->type;
            break;
        case OP_EQUAL:
            if(child[0]->type != child[1]->type)
                cerr << "equal factor error at line: " << line << endl;
            type = VAR_BOOL;
            break;
        case OP_GT:
            if(child[0]->type != child[1]->type ||
               child[0]->type != VAR_INTEGER)
                cerr << "> factor error at line: " << line << endl;
            type = VAR_BOOL;
            break;
        case OP_GTE:
            if(child[0]->type != child[1]->type ||
               child[0]->type != VAR_INTEGER)
                cerr << ">= factor error at line: " << line << endl;
            type = VAR_BOOL;
            break;
        case OP_LT:
            if(child[0]->type != child[1]->type ||
               child[0]->type != VAR_INTEGER)
                cerr << "< factor error at line: " << line << endl;
            type = VAR_BOOL;
            break;
        case OP_LTE:
            if(child[0]->type != child[1]->type ||
               child[0]->type != VAR_INTEGER)
                cerr << "<= factor error at line: " << line << endl;
            type = VAR_BOOL;
            break;
        case OP_NOTEQUAL:
            if(child[0]->type != child[1]->type)
                cerr << "!= factor error at line: " << line << endl;
            type = VAR_BOOL;
            break;
        case OP_NOT:
            if(child[0]->type != VAR_BOOL)
                cerr << "! factor error at line: " << line << endl;
            type = VAR_BOOL;
            break;
        case OP_LAND:
            if(child[0]->type != VAR_BOOL)
                cerr << "&& factor error at line: " << line << endl;
            type = VAR_BOOL;
            break;
        case OP_LOR:
            if(child[0]->type != VAR_BOOL)
                cerr << "|| factor error at line: " << line << endl;
            type = VAR_BOOL;
            break;
        default:
            break;
        }
        break;
    case NODE_VAR:
        i = SymbolsTable.lookup(var_name);
        // 如果是声明语句里的ID节点，不查找，一定在符号表里
        if(decl_flag) {
            type = (VarType)SymbolsTable.table[i].type;
        } else {
            // 对于其他ID节点，如果没有在符号表中找到或者没有被声明(即defined为false)，则说明其未被声明，或其在声明之前使用
            if(i != -1 && SymbolsTable.table[i].defined)
                type = (VarType)SymbolsTable.table[i].type;
            else
                cerr << "variable not define at line: " << line << endl;
        }
        break;
    default:
        break;
    }
}

string tree::new_label(void) {
    char tmp[20];
    sprintf(tmp, "label%d", label_seq);
    label_seq++;
    return tmp;
}

void tree::stmt_get_label(TreeNode *t) {
    TreeNode *e = t->child[0];
    TreeNode *s1 = t->child[1];
    TreeNode *s2 = t->child[2];
    TreeNode *s3 = t->child[3];
    switch(t->stmtType) {
    case STMT_COMPOUND:
        TreeNode *last;
        TreeNode *p;
        // 跳过变量声明节点
        for(p = t->child[0];
            p->nodeType == NODE_STMT && p->stmtType == STMT_DECL;
            p = p->sibling);
        // 对compound_stmt的每个子语句递归生成label
        for(; p; p = p->sibling) {
            last = p;
            recursive_get_label(p);
        }
        // compound_stmt语句的结束label和其最后一个子语句的相同
        t->label.next_label = last->label.next_label;
        // compound_stmt语句的兄弟语句的开始label等于它的结束label
        if(t->sibling)
            t->sibling->label.begin_label = t->label.next_label;
        break;
    case STMT_WHILE:
        // 生成开始label，循环体执行完后跳转至此label
        if(t->label.begin_label == "")
            t->label.begin_label = new_label();
        // 循环体的结束label为while循环的开始
        s1->label.next_label = t->label.begin_label;
        // 循环体的开始label是循环条件为真的label
        s1->label.begin_label = e->label.true_label = new_label();

        if(t->label.next_label == "")
            t->label.next_label = new_label();
        e->label.false_label = t->label.next_label;
        if(t->sibling)
            t->sibling->label.begin_label = t->label.next_label;

        recursive_get_label(e);
        recursive_get_label(s1);
        break;
    case STMT_FOR:
        s3 = s1;
        s1 = e->child[1];
        s2 = e->child[2];
        e = e->child[0];
        if(t->label.begin_label == "")
            t->label.begin_label = new_label();
        s1->label.true_label = new_label();
        if(t->label.next_label == "")
            t->label.next_label = new_label();
        s3->label.next_label = t->label.begin_label;
        s3->label.begin_label = s1->label.true_label;
        s1->label.false_label = t->label.next_label;
        if(t->sibling)
            t->sibling->label.begin_label = t->label.next_label;

        recursive_get_label(s1);
        recursive_get_label(s3);
        break;
    case STMT_IF:
        if(s2 == NULL) { // if(e) s1
            if(e->label.true_label == "")
                e->label.true_label = new_label();
            if(t->label.next_label == "")
                t->label.next_label = new_label();
            e->label.false_label = t->label.next_label;
            s1->label.begin_label = e->label.true_label;
            s1->label.next_label = t->label.next_label;
        } else { // if(e) s1  else s2
            if(e->label.true_label == "")
                e->label.true_label = new_label();
            if(t->label.next_label == "")
                t->label.next_label = new_label();
            e->label.false_label = new_label();
            s1->label.begin_label = e->label.true_label;
            s1->label.next_label = t->label.next_label;
            s2->label.begin_label = e->label.false_label;
            s2->label.next_label = t->label.next_label;
        }
        recursive_get_label(e);
        recursive_get_label(s1);
        if(s2)
            recursive_get_label(s2);
        break;
    }
}

//为逻辑表达式节点生成label
void tree::expr_get_label(TreeNode *t) {
    if(t->type != VAR_BOOL)
        return;

    TreeNode *e1 = t->child[0];
    TreeNode *e2 = t->child[1];
    switch(t->opType) {
    case OP_LAND:
        if(e1->label.true_label == "")
            e1->label.true_label = new_label();
        if(t->label.true_label == "")
            t->label.true_label = new_label();
        if(t->label.false_label == "")
            t->label.false_label = new_label();
        e2->label.true_label = t->label.true_label;
        // 三者假值出口相同
        e1->label.false_label = e2->label.false_label = t->label.false_label;
        break;
    case OP_LOR:
        if(t->label.true_label == "")
            t->label.true_label = new_label();
        if(t->label.false_label == "")
            t->label.false_label = new_label();
        e1->label.false_label = new_label();
        e2->label.false_label = t->label.false_label;
        // 三者真值出口相同
        e1->label.true_label = e2->label.true_label = t->label.true_label;
        break;
    case OP_NOT:
        if(t->label.true_label == "")
            t->label.true_label = new_label();
        if(t->label.false_label == "")
            t->label.false_label = new_label();
        e1->label.false_label = t->label.true_label;
        e1->label.true_label = t->label.false_label;
        break;
    }
    if(e1)
        recursive_get_label(e1);
    if(e2)
        recursive_get_label(e2);
}

void tree::recursive_get_label(TreeNode *t) {
    if(t != NULL) {
        if(t->nodeType == NODE_STMT)
            stmt_get_label(t);
        else if(t->nodeType == NODE_EXPR)
            expr_get_label(t);
    }
}

void tree::get_label(void) {
    TreeNode *p = root->child[0];
    // 跳过变量声明语句
    for(; p->nodeType == NODE_STMT && p->stmtType == STMT_DECL; p = p->sibling);
    p->label.begin_label = "main";
    while(p) {
        recursive_get_label(p);
        p = p->sibling;
    }
}

void tree::stmt_gen_code(TreeNode *t) {
    int i = 0;
    int j = 0;
    int q = 0;
    TreeNode *e = t->child[0];
    TreeNode *s1 = t->child[1];
    TreeNode *s2 = t->child[2];
    TreeNode *s3 = t->child[3];
    switch(t->stmtType) {
    case STMT_IF:
        if(s2 == NULL) { // 无else
            recursive_gen_code(e);
            cout << e->label.true_label << ":" << endl;
            recursive_gen_code(s1);
        } else { // 有else 或else if
            recursive_gen_code(e);
            cout << e->label.true_label << ":" << endl;
            recursive_gen_code(s1);
            cout << "\tJMP " << t->label.next_label << endl;
            cout << e->label.false_label << ":" << endl;
            recursive_gen_code(s2);
        }
        if(t->label.next_label != "")
            cout << t->label.next_label << ":" << endl;
        break;
    case STMT_WHILE:
        if(t->label.begin_label != "")
            cout << t->label.begin_label << ":" << endl;
        recursive_gen_code(e);
        cout << e->label.true_label << ":" << endl;
        recursive_gen_code(s1);
        cout << "\tjmp " << t->label.begin_label << endl;
        if(t->label.next_label != "")
            cout << t->label.next_label << ":" << endl;
        break;
    case STMT_FOR:
        s3 = s1;
        s1 = e->child[1];
        s2 = e->child[2];
        e = e->child[0];
        recursive_gen_code(e);
        cout << t->label.begin_label << ":" << endl;
        recursive_gen_code(s1);
        cout << s1->label.true_label << ":" << endl;
        recursive_gen_code(s3);
        recursive_gen_code(s2);
        cout << "\tJMP " << t->label.begin_label << endl;
        if(t->label.next_label != "")
            cout << t->label.next_label << ":" << endl;
        break;
    case STMT_COMPOUND:
        for(TreeNode *p = t->child[0]; p; p = p->sibling)
            recursive_gen_code(p);
        cout << endl;
        break;
    case STMT_DECL:
        // 递归生成每个带赋值的变量声明语句
        while(s1) {
            if(s1->nodeType == NODE_EXPR)
                recursive_gen_code(s1);
            s1 = s1->sibling;
        }
        break;
    case STMT_SCANF:
        s1 = e->child[1];
        // i存储参数个数
        while(s1) {
            i++;
            s1 = s1->sibling;
        }
        // 从右至左将每个参数压入栈中
        for(j = i; j > 0; j--) {
            q = j - 1;
            s2 = e->child[1];
            for(q; q > 0; q--) {
                s2 = s2->sibling;
            }
            cout << "\tpushl $_" << s2->child[0]->var_name << endl;
        }
        // 将格式化字符串压入栈中
        cout << "\tpushl $STR" << e->child[0]->const_str << endl;
        cout << "\tcall scanf" << endl;
        cout << "\taddl $" << 4 * i + 4 << ", %esp" << endl;
        break;
    case STMT_PRINTF:
        if(e->opType == OP_COMMA) { // printf("format", n1, ...)
            s1 = e->child[1];
            while(s1) {
                i++;
                s1 = s1->sibling;
            }
            for(j = i; j > 0; j--) {
                q = j - 1;
                s2 = e->child[1];
                for(q; q > 0; q--) {
                    s2 = s2->sibling;
                }
                if(s2->nodeType == NODE_EXPR)
                    cout << "\tpushl t" << s2->temp_var << endl;
                else
                    cout << "\tpushl _" << s2->var_name << endl;
            }
            cout << "\tpushl $STR" << e->child[0]->const_str << endl;
            cout << "\tcall printf" << endl;
            cout << "\taddl $" << 4 * i + 4 << ", %esp" << endl;
        } else { // printf("format")
            cout << "\tpushl $STR" << e->const_str << endl;
            cout << "\tcall printf" << endl;
            cout << "\taddl $" << 4 << ", %esp" << endl;
        }
        break;
    default:
        break;
    }
}

void tree::expr_gen_code(TreeNode *t) {
    if(t->opType != OP_LAND && t->opType != OP_LOR && t->opType != OP_NOT)
        for(int i = 0; i < MAXChildNum, t->child[i] != NULL; i++)
            recursive_gen_code(t->child[i]);
    TreeNode *e1 = t->child[0];
    TreeNode *e2 = t->child[1];
    switch(t->opType) {
    case OP_ASSIGN:
        cout << "\tmovl ";
        if(e2->nodeType == NODE_VAR) {
            cout << "_" << e2->var_name;
        } else if(e2->nodeType == NODE_CONST) {
            if(e2->type == VAR_INTEGER)
                cout << "$" << e2->int_val;
            else if(e2->type == VAR_CHAR)
                cout << "STR" << e2->const_str;
        } else {
            cout << "t" << e2->temp_var;
        }
        cout << ", %eax" << endl;
        cout << "\tmovl %eax, t" << t->temp_var << endl;
        cout << "\tmovl %eax, _" << e1->var_name << endl;
        break;
    case OP_AASSIGN:
        cout << "\tmovl _" << e1->var_name << ", %eax" << endl;
        cout << "\taddl ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST)
            cout << "$" << e2->int_val;
        else
            cout << "t" << e2->temp_var;
        cout << ", %eax" << endl;
        cout << "\tmovl %eax, t" << t->temp_var << endl;
        cout << "\tmovl %eax, _" << e1->var_name << endl;
        break;
    case OP_SASSIGN:
        cout << "\tmovl _" << e1->var_name << ", %eax" << endl;
        cout << "\tsubl ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST)
            cout << "$" << e2->int_val;
        else
            cout << "t" << e2->temp_var;
        cout << ", %eax" << endl;
        cout << "\tmovl %eax, t" << t->temp_var << endl;
        cout << "\tmovl %eax, _" << e1->var_name << endl;
        break;
    case OP_ADD:
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST)
            cout << "$" << e1->int_val;
        else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\taddl ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST)
            cout << "$" << e2->int_val;
        else
            cout << "t" << e2->temp_var;
        cout << ", %eax" << endl;
        cout << "\tmovl %eax, t" << t->temp_var << endl;
        break;
    case OP_SUB:
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST)
            cout << "$" << e1->int_val;
        else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\tsubl ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST)
            cout << "$" << e2->int_val;
        else
            cout << "t" << e2->temp_var;
        cout << ", %eax" << endl;
        cout << "\tmovl %eax, t" << t->temp_var << endl;
        break;
    case OP_MUL:
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST)
            cout << "$" << e1->int_val;
        else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\timull ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST)
            cout << "$" << e2->int_val;
        else
            cout << "t" << e2->temp_var;
        cout << ", %eax" << endl;
        cout << "\tmovl %eax, t" << t->temp_var << endl;
        break;
    case OP_DIV:
        cout << "\tXOR %edx, %edx" << endl;
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST)
            cout << "$" << e1->int_val;
        else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\tcmp %edx, %eax" << endl; // 判断被除数是否大于0
        cout << "\tjge O" << m << endl; // 如果被除数大于零，直接进行除法
        cout << "\tmovl $0, %edx" << endl; // 如果被除数小于零，将edx全置为1
        cout << "\tnot %edx" << endl;
        cout << "O" << m << ":" << endl;
        m++;
        cout << "\tmovl ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST)
            cout << "$" << e2->int_val;
        else
            cout << "t" << e2->temp_var;
        cout << ", %ebx" << endl;

        cout << "\tidiv %ebx" << endl;
        cout << "\tXOR %edx, %edx" << endl;
        cout << "\tmovl %eax, t" << t->temp_var << endl;
        break;
    case OP_MOD:
        cout << "\tXOR %edx, %edx" << endl;
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST)
            cout << "$" << e1->int_val;
        else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\tcmp %edx, %eax" << endl; // 判断被除数是否大于0
        cout << "\tjge O" << m << endl; // 如果被除数大于零，直接进行除法
        cout << "\tmovl $0, %edx" << endl; // 如果被除数小于零，将edx全置为1
        cout << "\tnot %edx" << endl;
        cout << "O" << m << ":" << endl;
        m++;
        cout << "\tmovl ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST)
            cout << "$" << e2->int_val;
        else
            cout << "t" << e2->temp_var;
        cout << ", %ebx" << endl;

        cout << "\tidiv %ebx" << endl;
        cout << "\tXOR %eax, %eax" << endl;
        cout << "\tmovl %edx, t" << t->temp_var << endl;
        break;
    case OP_SADD:
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST)
            cout << "$" << e1->int_val;
        else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\tmovl %eax, t" << t->temp_var << endl;
        break;
    case OP_UMINUS:
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST)
            cout << "$" << e1->int_val;
        else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\timul $-1, %eax" << endl;
        cout << "\tmovl %eax, t" << t->temp_var << endl;
        break;
    case OP_INC:
        cout << "\tmovl _" << e1->var_name << ", %eax" << endl;
        cout << "\tmovl %eax, t" << t->temp_var << endl;
        cout << "\taddl $1, %eax" << endl;
        cout << "\tmovl %eax, _" << e1->var_name << endl;
        break;
    case OP_DEC:
        cout << "\tmovl _" << e1->var_name << ", %eax" << endl;
        cout << "\tmovl %eax, t" << t->temp_var << endl;
        cout << "\tsubl $1, %eax" << endl;
        cout << "\tmovl %eax, _" << e1->var_name << endl;
        break;
    case OP_EQUAL:
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST) {
            if(e1->type == VAR_INTEGER)
                cout << "$" << e1->int_val;
            else if(e1->type == VAR_CHAR)
                cout << "STR" << e1->const_str;
        } else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\tcmp ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST) {
            if(e2->type == VAR_INTEGER)
                cout << "$" << e2->int_val;
            else if(e2->type == VAR_CHAR)
                cout << "STR" << e2->const_str;
        } else
            cout << "t" << e2->temp_var;
        cout << ", %eax" << endl;
        cout << "\tje " << t->label.true_label << endl;
        cout << "\tjmp " << t->label.false_label << endl;
        break;
    case OP_NOTEQUAL:
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST) {
            if(e1->type == VAR_INTEGER)
                cout << "$" << e1->int_val;
            else if(e1->type == VAR_CHAR)
                cout << "STR" << e1->const_str;
        } else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\tcmp ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST) {
            if(e2->type == VAR_INTEGER)
                cout << "$" << e2->int_val;
            else if(e2->type == VAR_CHAR)
                cout << "STR" << e2->const_str;
        } else
            cout << "t" << e2->temp_var;
        cout << ", %eax" << endl;
        cout << "\tjne " << t->label.true_label << endl;
        cout << "\tjmp " << t->label.false_label << endl;
        break;
    case OP_GT:
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST && e1->type == VAR_INTEGER)
            cout << "$" << e1->int_val;
        else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\tcmp ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST && e2->type == VAR_INTEGER)
            cout << "$" << e2->int_val;
        else
            cout << "t" << e2->temp_var;
        cout << ", %eax" << endl;
        cout << "\tjg " << t->label.true_label << endl;
        cout << "\tjmp " << t->label.false_label << endl;
        break;
    case OP_GTE:
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST && e1->type == VAR_INTEGER)
            cout << "$" << e1->int_val;
        else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\tcmp ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST && e2->type == VAR_INTEGER)
            cout << "$" << e2->int_val;
        else
            cout << "t" << e2->temp_var;
        cout << ", %eax" << endl;
        cout << "\tjge " << t->label.true_label << endl;
        cout << "\tjmp " << t->label.false_label << endl;
        break;
    case OP_LT:
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST && e1->type == VAR_INTEGER)
            cout << "$" << e1->int_val;
        else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\tcmp ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST && e2->type == VAR_INTEGER)
            cout << "$" << e2->int_val;
        else
            cout << "t" << e2->temp_var;
        cout << ", %eax" << endl;
        cout << "\tjl " << t->label.true_label << endl;
        cout << "\tjmp " << t->label.false_label << endl;
        break;
    case OP_LTE:
        cout << "\tmovl ";
        if(e1->nodeType == NODE_VAR)
            cout << "_" << e1->var_name;
        else if(e1->nodeType == NODE_CONST && e1->type == VAR_INTEGER)
            cout << "$" << e1->int_val;
        else
            cout << "t" << e1->temp_var;
        cout << ", %eax" << endl;
        cout << "\tcmp ";
        if(e2->nodeType == NODE_VAR)
            cout << "_" << e2->var_name;
        else if(e2->nodeType == NODE_CONST && e2->type == VAR_INTEGER)
            cout << "$" << e2->int_val;
        else
            cout << "t" << e2->temp_var;
        cout << ", %eax" << endl;
        cout << "\tjle " << t->label.true_label << endl;
        cout << "\tjmp " << t->label.false_label << endl;
        break;
    case OP_LAND:
        recursive_gen_code(e1);
        cout << e1->label.true_label << ":" << endl;
        recursive_gen_code(e2);
        break;
    case OP_LOR:
        recursive_gen_code(e1);
        cout << e1->label.false_label << ":" << endl;
        recursive_gen_code(e2);
        break;
    case OP_NOT:
        recursive_gen_code(e1);
        break;
    }
}

void tree::recursive_gen_code(TreeNode *t) {
    if(t != NULL) {
        if(t->nodeType == NODE_STMT)
            stmt_gen_code(t);
        else if(t->nodeType == NODE_EXPR)
            expr_gen_code(t);
    }
}

void tree::gen_decl(TreeNode *t) {
    for(TreeNode *p = t->child[1]; p; p = p->sibling) {
        if(p->nodeType == NODE_VAR && p->type == VAR_INTEGER) {
            cout << "_" << p->var_name << ":" << endl;
        } else if(p->nodeType == NODE_VAR && p->type == VAR_CHAR) {
            cout << "_" << p->var_name << ":" << endl;
        } else if(p->nodeType == NODE_EXPR && p->opType == OP_ASSIGN) {
            cout << "_" << p->child[0]->var_name << ":" << endl;
        }
        cout << "\t.zero\t4" << endl;
        cout << "\t.align\t4" << endl;
    }
}

void tree::gen_code() {
    cout << "\t.section .bss" << endl;
    TreeNode *p = root->child[0];
    // 生成声明的变量，变量的位置可以在int main()里面或外面
    while(p) {
        if(p->nodeType == NODE_STMT && p->stmtType == STMT_COMPOUND)
            p = p->child[0];
        if(p->nodeType == NODE_STMT && p->stmtType == STMT_DECL)
            gen_decl(p);
        p = p->sibling;
    }
    // 生成临时变量
    for(int i = 0; i < temp_var_all; i++) {
        cout << "t" << i << ":" << endl;
        cout << "\t.zero\t4" << endl;
        cout << "\t.align\t4" << endl;
    }
    cout << endl;
    // 生成字符和字符串常量
    cout << "\t.section .rodata" << endl;
    for(int i = 0; i < const_str_all; i++) {
        cout << "STR" << i << ":" << endl;
        cout << "\t.string\t" << str_table[i] << "" << endl;
        cout << "\t.align\t4" << endl;
    }
    // 生成代码段
    cout << endl;
    cout << "\t.section .text" << endl;
    cout << "\t.globl main" << endl << endl;
    cout << "main:" << endl;

    p = root->child[0];
    while(p) {
        recursive_gen_code(p);
        p = p->sibling;
    }

    if(root->label.next_label != "")
        cout << root->label.next_label << ":" << endl;
    cout << "\tret" << endl;
}
