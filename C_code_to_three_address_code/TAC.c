#include "TAC.h"
#include "semantics.tab.h"
extern int yylineno;
using namespace std;

int int_width = 4;
int float_width = 8;
int bool_width = 1;
int void_width = -1;
int numtemp = 0;
int next_instruction;
symbol_table *symtab_global;
symbol_table *symtab_current;
Quadruples global_quadruple;

quad_list* makelist(int i){							
	quad_list *head;									
	head = new quad_list();							
	head->quad_val = i;							
	head->next = NULL;							
	return head;								
}												

quad_list* merge(quad_list *p1,quad_list *p2){					
	if(p1!=NULL && p2!=NULL){					
		quad_list *p,*q;									
		q = p1;										 
		p = q;										
		while(q){									
			p = q;									
			q = q->next;
		}
	
		p->next = p2;	
		return p1;
	}
	else{
		if(p1!=NULL && p2==NULL)return p1;
		else{
			if(p1==NULL && p2!=NULL)return p2;
			else return NULL;
		}
	}		
}

void backpatch(quad_list *head,int i){				
	Quadruple *p;									
	quad_list *q;									
	q = head;									
	while(q){									
		p = global_quadruple.head;				
		for(int j=0;j<q->quad_val;j++){		
			p = p->next;					
		}										
		char str[10];						
		sprintf(str,"%d",i+1);				
		string str1(str);					
		p->result = str1; 					
		q = q->next;						
	}
}


int ttypecheck(type_structure *t1,type_structure *t2){
	if(t1->isarr==1 && t2->isarr==1)return ttypecheck(t1->next,t2->next);
	else{
		if(t1->isarr==0 && t2->isarr==0){
			if(t1->type_name==t2->type_name)return 1;
			else{
				if((t1->type_name=="int" && t2->type_name=="float") || (t1->type_name=="float" && t2->type_name=="int")){
					if(t1->type_name=="int" && t2->type_name=="float")return 2;
					else return 3;
				}
			}
		}
		else return 0;
	}
}

void typecheck(expression_struct *E1,expression_struct *E2){
	switch(ttypecheck(E1->type,E2->type)){			
		case 0:										
			printf("%s %s %s %s types not compatible %d \n",(E1->type->type_name).c_str(),(E1->address_pointer->sym_name).c_str(),(E2->address_pointer->sym_name).c_str(),(E2->type->type_name).c_str(),yylineno);
			exit(-1);							
			break;												
		
		case 2: convinttofloat(E1); break;
		
		case 3: convinttofloat(E2); break;
	}
}

void convinttofloat(expression_struct *E){
	symbol_struct *temp = symbol_table::gentemp();				
	temp->type = new type_structure();							 
	temp->type->type_name = "float";						
	temp->type->isarr = 0;								
	temp->type->type_size = float_width;								
	temp->type->next = NULL;
	temp->sym_size = float_width;
	symtab_current->offset += temp->sym_size;
	Quadruples::emit("(float)",E->address_pointer->sym_name,temp->sym_name);	// emit Quadruple of type conversion to float
	E->address_pointer = temp;
	E->type = temp->type;
}

void convtobool(expression_struct *E){
	if(E->type->type_name!="bool"){							
		type_structure *ty;										
		ty = new type_structure();								
		ty->type_name = "bool";								
		ty->type_size = bool_width;
		ty->isarr = 0;
		ty->next = NULL;
		
		E->type = ty;
		E->address_pointer->type = ty;
		
		E->false_list = makelist(next_instruction);
		Quadruples::emit("ifeq",(E->address_pointer)->sym_name,"0","_");		// emit Quadruple if x==0 goto _
		E->true_list = makelist(next_instruction);
		Quadruples::emit("_");								// emit Quadruple goto _
	}
}

symbol_table::symbol_table(){				// constructor
	this->offset = 0;
	this->sym_name = "";
	this->head = NULL;
}

void symbol_table::update(symbol_struct *entry,string sym_name,type_structure *type,string initial_value,int sym_size,int offset,symbol_table *func_next){
	entry->sym_name = sym_name;
	entry->type = type;
	entry->initial_value = initial_value;				// function to update a symbol table entry
	entry->sym_size = sym_size;
	entry->offset = offset;
	entry->func_next = func_next;
}

Quadruples::Quadruples(){
	this->head = NULL;
	next_instruction = 0;
}


//function to emit a Quadruple with only one address addresses
void Quadruples::emit(string result){
	Quadruple *q;
	Quadruple *p;
	q = global_quadruple.head;
	p = q;
	while(q){
		p=q;
		q = q->next;
	}
	
	if(p){
		q = new Quadruple();
		q->opcode = "";
		q->arg1 = "";
		q->arg2 = "";
		q->result = result;
		q->next = NULL;
		p->next = q;
	}
	else{
		q = new Quadruple();
		q->opcode = "";
		q->arg1 = "";
		q->arg2 = "";
		q->result = result;
		q->next = NULL;
		global_quadruple.head = q;
	}
	
	next_instruction = next_instruction + 1;
}

//function to emit a Quadruple with three addresses
void Quadruples::emit(string opcode,string arg1,string arg2,string result){
	Quadruple *q;
	Quadruple *p;
	q = global_quadruple.head;
	p = q;
	while(q){
		p=q;
		q = q->next;
	}
	
	if(p){
		q = new Quadruple();
		q->opcode = opcode;
		q->arg1 = arg1;
		q->arg2 = arg2;
		q->result = result;
		q->next = NULL;
		p->next = q;
	}
	else{
		q = new Quadruple();
		q->opcode = opcode;
		q->arg1 = arg1;
		q->arg2 = arg2;
		q->result = result;
		q->next = NULL;
		global_quadruple.head = q;
	}
	
	next_instruction = next_instruction + 1;
}

//function to emit a Quadruple with two addresses and an opcode
void Quadruples::emit(string opcode,string arg1,string result){
	Quadruple *q;
	Quadruple *p;
	q = global_quadruple.head;
	p = q;
	while(q){
		p=q;
		q = q->next;
	}
	
	if(p){
		q = new Quadruple();
		q->opcode = opcode;
		q->arg1 = arg1;
		q->arg2 = "";
		q->result = result;
		q->next = NULL;
		p->next = q;
	}
	else{
		q = new Quadruple();
		q->opcode = opcode;
		q->arg1 = arg1;
		q->arg2 = "";
		q->result = result;
		q->next = NULL;
		global_quadruple.head = q;
	}
	
	next_instruction = next_instruction + 1;
}

// function to emit Quadruple of copy instruction
void Quadruples::emit(string arg1,string result){
	Quadruple *q;
	Quadruple *p;
	q = global_quadruple.head;
	p = q;
	while(q){
		p=q;
		q = q->next;
	}
	
	if(p){
		q = new Quadruple();
		q->opcode = "";
		q->arg1 = arg1;
		q->arg2 = "";
		q->result = result;
		q->next = NULL;
		p->next = q;
	}
	else{
		q = new Quadruple();
		q->opcode = "";
		q->arg1 = arg1;
		q->arg2 = "";
		q->result = result;
		q->next = NULL;
		global_quadruple.head = q;
	}
	
	next_instruction = next_instruction + 1;
}

symbol_struct* symbol_table::lookup(string lexeme){
	symbol_struct *q = this->head;	
	symbol_struct *p = q;	
	while(q){
		if(q->sym_name==lexeme)return q;
		p = q;
		q = q->next;
	}
	
	if(p){
		q = new symbol_struct();					//
		q->sym_name = lexeme;					//
		q->type = NULL;						//
		q->initial_value = "---";					//
		q->sym_size = 0;						// creating a new symbol table entry
		q->offset = symtab_current->offset;	//
		q->func_next = NULL;					//
		q->next = NULL;						//
		p->next = q;						//
		return q;							//
	}
	else{
		q = new symbol_struct();					//
		q->sym_name = lexeme;					//
		q->type = NULL;						//
		q->initial_value = "---";					//
		q->sym_size = 0;						// 
		q->offset = symtab_current->offset;	// creating a new symbol table entry
		q->func_next = NULL;					//
		q->next = NULL;						//
		this->head = q;						//
		return q;							//
	}
}

symbol_struct* symbol_table::find(string lexeme){
	symbol_struct *q = this->head;
	while(q){
		if(q->sym_name==lexeme)return q;			// searching for an entry in the symbol table
		q = q->next;
	}
	
	return NULL;
}

symbol_struct* symbol_table::gentemp(){
	char lexeme[10];
	sprintf(lexeme,"t%d",numtemp);				// generating a temporary
	numtemp++;
	return symtab_current->lookup(lexeme);
}

symbol_struct* symbol_table::deltemp(string tname){
	symbol_struct *q = this->head;
	symbol_struct *p = q;
	int diff;
	
	if(p->sym_name==tname){
		diff = p->sym_size;
		this->head = p->next;
		q = p->next;
		while(q){
			q->offset -= diff;
			q = q->next;
		}	
		this->offset -= diff;
	}												
	else{
		while(q){
			if(q->sym_name==tname){
				diff = q->sym_size;
				p->next = q->next;
				q = p->next;
				while(q){
					q->offset -= diff;
					q = q->next;
				}
				this->offset -= diff;
				break;
			}
			p = q;
			q = q->next;
		}
	}
}

// function to print the quads in a Quadruple array
void Quadruples::print(){
	Quadruple *q = this->head;
	int instrcount = 0;
	while(q){
		// printf("%2d :- ",instrcount);
		// ARITHMETIC OPERATIONS
		if(q->arg1!="" && q->arg2!="" && (q->opcode=="+" || q->opcode=="-"|| q->opcode=="*"|| q->opcode=="/"|| q->opcode=="%"|| q->opcode=="<<"|| q->opcode==">>"|| q->opcode=="^"|| q->opcode=="&"|| q->opcode=="|"|| q->opcode=="&&"|| q->opcode=="||"|| q->opcode=="<"|| q->opcode=="<="|| q->opcode==">"|| q->opcode==">="|| q->opcode=="="|| q->opcode=="!=")){
			printf("%s = %s %s %s \n",(q->result).c_str(),(q->arg1).c_str(),(q->opcode).c_str(),(q->arg2).c_str());
		}
		else{ // TYPE CONVERSION 
			if(q->arg1!="" && q->arg2=="" && (q->opcode=="-" || q->opcode=="+" || q->opcode=="!" || q->opcode==".'" || q->opcode=="(float)" || q->opcode=="(int)")){
				if(q->opcode!=".'")printf("%s = %s %s \n",(q->result).c_str(),(q->opcode).c_str(),(q->arg1).c_str());
				else printf("%s = %s %s \n",(q->result).c_str(),(q->arg1).c_str(),(q->opcode).c_str());
			}
			else{ // COPY INSTRUCTIONS
				if(q->arg1!="" && q->arg2=="" && q->opcode==""){
					printf("%s = %s \n",(q->result).c_str(),(q->arg1).c_str());
				}
				else{ //GOTO INSTRUCTION
					if(q->arg1=="" && q->arg2=="" && q->opcode==""){
						printf("goto l%s: \n",(q->result).c_str());
					}
					else{ 
						// PARAMETER INSTRUCTIONS
						if(q->opcode=="param"){printf("param %s \n",(q->result).c_str()); q = q->next; instrcount++; continue;}
						if(q->opcode=="call"){printf("%s = call %s , %s \n",(q->result).c_str(),(q->arg1).c_str(),(q->arg2).c_str()); q = q->next; instrcount++; continue;}
						if(q->opcode=="func"){printf("%s:\n",(q->result).c_str()); q = q->next; instrcount++; continue;}	
						
						// RETURN INSTRUCTIONS
						if(q->opcode=="return"){printf("return %s \n",(q->result).c_str()); q = q->next; instrcount++; continue;}
						
						// INDEXED COPY INSTRUCTIONS
						if(q->opcode=="lindexed"){printf("%s[%s] = %s \n",(q->result).c_str(),(q->arg1).c_str(),(q->arg2).c_str()); q = q->next; instrcount++; continue;}
						if(q->opcode=="rindexed"){printf("%s = %s[%s] \n",(q->result).c_str(),(q->arg1).c_str(),(q->arg2).c_str()); q = q->next; instrcount++; continue;}
						//UNCONDITIONAL AND CONDITIONAL JUMP INSTRUCTIONS
						if(q->opcode=="ifgte"){printf("if %s >= %s goto l%s: \n",(q->arg1).c_str(),(q->arg2).c_str(),(q->result).c_str()); q = q->next; instrcount++; continue;}
						if(q->opcode=="ifeq"){printf("if %s == %s goto l%s: \n",(q->arg1).c_str(),(q->arg2).c_str(),(q->result).c_str()); q = q->next; instrcount++; continue;}
						if(q->opcode=="ifneq"){printf("if %s != %s goto l%s: \n",(q->arg1).c_str(),(q->arg2).c_str(),(q->result).c_str()); q = q->next; instrcount++; continue;} 
						if(q->opcode=="iflt"){printf("if %s < %s goto l%s: \n",(q->arg1).c_str(),(q->arg2).c_str(),(q->result).c_str()); q = q->next; instrcount++; continue;}
						if(q->opcode=="iflte"){printf("if %s <= %s goto l%s: \n",(q->arg1).c_str(),(q->arg2).c_str(),(q->result).c_str()); q = q->next; instrcount++; continue;}
						if(q->opcode=="ifgt"){printf("if %s > %s goto l%s: \n",(q->arg1).c_str(),(q->arg2).c_str(),(q->result).c_str()); q = q->next; instrcount++; continue;}

					}
				}
			}
		}
		
		q = q->next;
		instrcount++;
	}
}

int main(){
	symtab_global = new symbol_table();
	symtab_current = symtab_global;
	
	yyparse();

	global_quadruple.print();
	
	return 0;
}
