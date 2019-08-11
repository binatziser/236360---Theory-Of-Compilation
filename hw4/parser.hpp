#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <stack>	
#define YYSTYPE Node*

using namespace std;

class Node{
	public:
		string type;
		
		Node(string type) : type(type) {}
		
		virtual ~Node(){}

};

class Value_node : public Node{
	public:
		string value;
		
		Value_node(string type, string value) : Node(type), value(value) {}
};

class Exp_list : public Node{
	public:
	vector<string>* types;
	
	Exp_list(string type) : Node("EXP_LIST"){
		types = new vector<string>();
		types->push_back(type);
	}
};

class Mem_list : public Node{
	public:
	vector<string>* types;
	vector<string>* names;
	
	Mem_list(string type, string name) : Node("EXP_LIST"){
		types = new vector<string>();
		names = new vector<string>();
		types->push_back(type);
		names->push_back(name);
	}
	
	Mem_list(vector<string>* _types, vector<string>* _names): Node("EXP_LIST"){
		types = new vector<string>(*_types);
		names = new vector<string>(*_names);		
	}
	
};


class Info {
	public:
		string name;
		string type;
		int offset;
		vector<string>* arg_types; 
		vector< pair <string, string> >* struct_fields; // first - type, second - name;
		
		Info() {};
		Info(string name, string type, int offset,vector<string>* arg_types,vector< pair <string, string> >* struct_fields) :
		name(name), type(type), offset(offset), arg_types(arg_types), struct_fields(struct_fields){}
		
		~Info () {
			delete arg_types;
			delete struct_fields;
		}
}
;

typedef vector<Info*> SymbolTable;
