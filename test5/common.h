#ifndef COMMON_H
#define COMMON_H

#include "tree.h"
#include <vector>
#define YYSTYPE TreeNode *

struct IDAttributes
{
    string var_name;
    VarType var_type;
    int int_value;
    char char_value;
};
#endif