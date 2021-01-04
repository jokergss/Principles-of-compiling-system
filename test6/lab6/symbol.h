#include <iostream>
#include <string>
using namespace std;
#define MAX_ID 1024

struct IDAttributes
{
    string name;
    int type;
	bool defined=false;
};

class symbol_table{
public:
	IDAttributes table[MAX_ID];
	
	int size;
	int lookup(string name);
	int insert(string name, int type);
	string &getname(int pos);
	int set_type(int pos, int type);
	int get_type(int pos);
};
