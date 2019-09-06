#ifndef myl_h
#define myl_h

#include <stdio.h>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;

struct type_structure;						// data structure to store type of an expression
struct type_attribute;					// data structure to store attributes of a type specifier

struct quad_list;						// data structure to store attributes of a statement
class Quadruples;					// data structure to store array of quads
struct Quadruple;						// data structure to store a Quadruple
struct param_list;
struct param_quad_list;					// data structure to store attributes of a parameter quad_list
struct initial;
struct identifier_struct;						// data structure to store attributes of an identifier
struct expression_struct;						// data structure to store attributes of an expression
class symbol_table;						// data structure to store details of a symbol table
struct symbol_struct;					// data structure to store an entry of a symbol table


extern symbol_table *symtab_global;		// pointer to global symbol table
extern symbol_table *symtab_current;		// pointer to current symbol table
extern Quadruples global_quadruple;		// represents Quadruple array



struct type_structure{			// data structure to store type of a variable
	string type_name;			// sym_name of the type
	int arr_num;			// number of elements in case the type is array
	type_structure *next;			// pointer to base type in an array or a pointer variable
	int type_size;				// type_size of the type
	int isarr;				// flag to tell whether the type is an array or not
	type_structure *return_type;			// return type if type_name=function
};

struct type_attribute{			// data structure to store attributes of a type specifier 
	type_structure *type;				// type
	int type_size;					// type_size of the type
};

struct quad_list{			
	int quad_val;
	quad_list *next;
};

struct Quadruple{				// data structure to store a Quadruple
	string opcode;				// operator field 
	string arg1;				// 1st argument
	string arg2;				// 2nd argument
	string result;				// result field
	Quadruple *next;					// pointer to next Quadruple
};

class Quadruples{		// class definition of Quadruple array
	public:
		Quadruples();		// constructor
		Quadruple *head;			// pointer to a quad_list of quads
		static void emit(string opcode,string arg1,string arg2,string result);  // function to emit a Quadruple with given parameters
		static void emit(string opcode,string arg1,string result);		// function to emit a Quadruple with given parameters
		static void emit(string arg1,string result);			// function to emit a Quadruple with given parameters
		static void emit(string result);				// function to emit a Quadruple with given parameters
		void print();							// function to print the Quadruple array
};

quad_list* makelist(int i);						// function to create a quad_list with i (an quad_val to the quad_list of instructions) as the only element and return the pointer to that quad_list
quad_list* merge(quad_list *p1,quad_list *p2);				// function to merge two lists and return a pointer to the resulting quad_list
void backpatch(quad_list *head,int i);			// function to set quad_val i as the target in all instructions whose indices are stored in the quad_list
void typecheck(expression_struct *E1,expression_struct *E2);		// function to check the type of E1 and E2 for compatibility
void convinttofloat(expression_struct *E);			// function to change the type of expression E from int to float
void convtobool(expression_struct *E);				// function to change the type of expression E to boolean

struct expression_struct{				// data structure to store attributes of an expression 
	symbol_struct *address_pointer;				// address of the temporary representing this expression in the symbol table
	type_structure *type;				// type of the expression
	symbol_struct *array;			// address of base of array if the expression is of type Matrix
	quad_list *true_list;				// quad_list of indices of goto instructions that are generated when this boolean expression is true
	quad_list *false_list;            // quad_list of indices of goto instructions that are generated when this boolean expression is false
	int point;
	int top_val;
};

struct param_list{
	expression_struct express;
	param_list *next;
};

struct param_quad_list{			// data structures to store attributes of an argument quad_list
	param_list *head;			// pointer to a quad_list of addresses where each address is a pointer to an expression
	int pnum;					// number of arguments
};

struct initial{				// data structure to store attributes of initializer 
	expression_struct express;			// an expression
	string *val;				// pointer to a string that holds the initial value of a variable
};

struct identifier_struct{				// data structure to store attributes of an identifier
	symbol_struct *address_pointer;				// a pointer to entry of this Identifier in the Symbol Table
	string *lexeme;				// lexeme of this identifier
}; 


struct symbol_struct{			// data structure to store an entry in a symbol table
	string sym_name;			// sym_name of the symbol
	type_structure *type;			// type of the symbol
	string initial_value;			// initial value of the symbol
	int sym_size;				// sym_size of the symbol
	int offset;				// offset of the symbol
	symbol_table *func_next;		// pointer to a symbol table if the symbol represents a function
	symbol_struct *next;			// pointer to next entry
};

class symbol_table{				// class definition of a symbol table
	public:
		symbol_table();							// constructor
		string sym_name;						// sym_name of the symbol table
		int offset;							// total offset  of the symbol table
		symbol_struct *head;						// pointer to a quad_list of symbol table entries
		symbol_struct* lookup(string lexeme);	// function to lookup an entry with sym_name = lexeme
		symbol_struct* find(string lexeme);		// function to search an entry with sym_name = lexeme
		static symbol_struct* gentemp();			// function to generate a temporary in the symbol table
		symbol_struct* deltemp(string tname);	// function to delete a temporary from the symbol table
		void update(symbol_struct *entry,string sym_name,type_structure *type,string initial_value,int sym_size,int offset,symbol_table *func_next);
											// function to update an entry in the symbol table
		void print();						// function to print the symbol table in a particular format
};

#endif
