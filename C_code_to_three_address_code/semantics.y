%{
	#include "TAC.h"
	#define YYDEBUG 1
	extern int yylex();
	extern char *yytext;
	void yyerror(const char *s);
	type_structure *T;
	int W;
	int diff;
	int flag = 0;
	extern int numtemp;					// count of temporary variable
	extern int next_instruction;				// stores the count of next instruction
	extern int int_width;
	extern int float_width;
	extern int char_width;
	extern int bool_width;
	extern int void_width;
%}

%union{
	type_attribute tspec;		// to store attributes of type-specifiers
	param_quad_list plist;	// to store attributes of argument-expression-quad_list
	identifier_struct idt;			// to store attributes of an identifier 
	int val_int;
	char val_char;
	string *word;
	initial ini;		// to store attributes of initializer
	expression_struct expr;		// to store attributes of an expression 			
	quad_list *after;		// to store attributes of statements
	float val_float;
	int dummy;
}

%token <idt> ID  
%token <val_int> INT_CONST 
%token <val_float> FLOAT_CONST 
%token ZERO_CONST 
%token ARROW INC DEC LTE GTE EQ NEQ AND OR ADDC MODC MULC DIVC SUBC
%token BOOL BREAK CASE CHAR CONTINUE DEFAULT DO IF ELSE FLOAT FOR GOTO INT  RETURN SWITCH VOID WHILE
%type <plist> argexplist
%type <val_char> unaryop
%type <tspec> declaration_type typespec 
%type <dummy> M  
%type <after> N stmt labeled_statement compstmt selstmt iteration_statement jumpstmt blockitemlist blockitem 
%type <expr> primexp postexp unaryexp castexp multexp addexp shiftexp relexp eqexp andexp xorexp orexp logandexp logorexp condexp assignexp exp constexp initial_declarator initial_declaration_list direct_declarator declarator expstmt expopt
%type <ini> initializer initializerrow initializerrowlist  

%start transunit

%left '+' '-'
%left '*' '/' '%'

%%

typespec:    VOID		{
							$$.type = new type_structure();			
							($$.type)->type_name = "void";		
							($$.type)->isarr = 0;			// set type attribute
							($$.type)->type_size = void_width;			
							($$.type)->next = NULL;			
							
							$$.type_size = void_width;		
						}
	
	| INT				{
							$$.type = new type_structure();
							($$.type)->type_name = "int";			// set type attribute
							($$.type)->isarr = 0;
							($$.type)->type_size = int_width;
							($$.type)->next = NULL;	
							
							$$.type_size = int_width;
						}
						
	| FLOAT			{
							$$.type = new type_structure();
							($$.type)->type_name = "float";
							($$.type)->isarr = 0;					// set type attribute
							($$.type)->type_size = float_width;
							($$.type)->next = NULL;	
							
							$$.type_size = float_width;
						}
	;


/*EXTERNAL DECLARATIONS*/
transunit:	external_declaration			{}
	| transunit external_declaration		{}
	;

external_declaration:	funcdef			{}
	| declaration				{}
	;

funcdef:	declaration_type declarator declaration_list compstmt		{
															($2.type)->type_size = symtab_current->offset;
															($2.address_pointer)->type = $2.type;
															($2.address_pointer)->initial_value = "---";
															diff = ($2.type)->type_size - ($2.address_pointer)->sym_size;
															//($2.address_pointer)->sym_size = ($2.type)->type_size;
															($2.address_pointer)->func_next = symtab_current;		// save symbol table of this function
															symtab_current = symtab_global;			// restore old symbol table
															
															if($4)backpatch($4,next_instruction);
														}
														
	| declaration_type declarator compstmt						{
															($2.type)->type_size = symtab_current->offset;
															($2.address_pointer)->type = $2.type;
															($2.address_pointer)->initial_value = "---";
															diff = ($2.type)->type_size - ($2.address_pointer)->sym_size;
															//($2.address_pointer)->sym_size = ($2.type)->type_size;
															($2.address_pointer)->func_next = symtab_current;		// save symbol table of this function
															symtab_current = symtab_global;			// restore old symbol table
															
															if($3)backpatch($3,next_instruction);		// backpatch last statement of compound statement to next instruction
														}
	;

declaration_list:	declaration			{}
	| declaration_list declaration		{}
	;

/*DECLARATIONS*/
declaration:    declaration_type initial_declaration_list ';'	{}
	| declaration_type ';'						{}
	;

declaration_type:    typespec declaration_type		{}
	| typespec								{
												$$ = $1;
												T = $1.type;	// store the type
												W = $1.type_size;	// store type_size of the type
											}
	;

initial_declaration_list:    initial_declarator				{$$ = $1;}
	| initial_declaration_list ',' initial_declarator			{$$ = $1;}
	;

initial_declarator:    declarator			{
												$$ = $1;	
												if(($1.type)->type_name=="function"){
													symtab_current = symtab_global;		// restore global symbol table
												}
											}
											
	| declarator '=' initializer				// Non-terminal Q sets a flag that prevents generation of quads for initialization of a variable
											{
												if(($1.type)->isarr==0){
													if((*($3.val))!="")($1.address_pointer)->initial_value = *($3.val);		// set initial_value in symbol table
													Quadruples::emit(($3.express.address_pointer)->sym_name,($1.address_pointer)->sym_name);
												}
												else{
													($1.array)->initial_value = *($3.val);		// set initial_value in symbol table
													if($3.express.top_val==1)Quadruples::emit(($3.express.array)->sym_name,($1.array)->sym_name);
												}
																					
												$$ = $1;
												if(($1.type)->type_name=="function"){
													symtab_current = symtab_global;	// restore global symbol table if $1 is of type function
												}	
											}
	;

initializer:	assignexp			{
										if(($1.type)->isarr==0)$$.val = new string(($1.address_pointer)->initial_value);		// saving the initial value
										else $$.val = new string(($1.array)->initial_value);
										$$.express = $1;
									}

	| '{' initializerrowlist '}'	{
										$$.express = $2.express;
										$$.val = new string("{"+(*($2.val))+"}");		// saving the initial value
									}
	;

initializerrowlist:	'{' initializerrow	'}'			{
													$$.val = new string(*($2.val));		// saving the initial value
													$$.express = $2.express;
												}
	| initializerrowlist ',' '{' initializerrow	'}'		{
													$$.val = new string((*($1.val)) + ";" + (*($4.val)));	// saving the initial value
													$$.express = $1.express;	
												}
	;

initializerrow:	initializer						{
													$$.val = new string(*($1.val));			// saving the initial value
													$$.express = $1.express;
												}
	| initializerrow ',' initializer			{
													$$.val = new string((*($1.val)) + "," + (*($3.val)));		// saving the initial value
													$$.express = $1.express;
												}
	;	

declarator:    direct_declarator			{
									$$ = $1;
									
									if(($$.type)->type_name!="function"){
										if(($$.type)->isarr==0){
											// declarator i.e. $1 is a simple declarator
											($$.address_pointer)->type = $$.type;
											($$.address_pointer)->initial_value = "---"; 					// update symbol table entry
											($$.address_pointer)->sym_size = ($$.type)->type_size;
											symtab_current->offset += ($$.address_pointer)->sym_size;
										}
										else{
											// declarator i.e. $1 is of type matrix
											($$.array)->type = $$.type;
											($$.array)->initial_value = "---";					// update symbol table entry
											($$.array)->sym_size = ($$.type)->type_size;
											symtab_current->offset += ($$.array)->sym_size + (2*int_width);
										}
									}
									else{
										// declarator i.e. $1 is of type function
										if(($$.address_pointer)->func_next==NULL){
											// function is declared for the first time
											($$.address_pointer)->type = $$.type;
											($$.address_pointer)->initial_value = "---";						// update symbol table entry
											($$.address_pointer)->sym_size = 0;	
											($$.address_pointer)->func_next = symtab_current;
											symtab_global->offset += ($$.address_pointer)->sym_size;
										}
									}
								}

	;	
	
P:			// creates new symbol table							
			{
				symtab_current = new symbol_table();	/*create new symbol table*/	
			}
	;

direct_declarator:	ID							{
												$1.address_pointer = symtab_current->lookup(*($1.lexeme)); 	// create symbol table entry for identifier
												$$.address_pointer = $1.address_pointer;		//
												$$.type = T;			//	
												$$.array = NULL;		//	set the attributes
												$$.point = 0; 			//
											}
											
	| '(' declarator ')'						{
												$$ = $2;	
											}
	| direct_declarator '[' assignexp ']'		{
												if(($1.type)->isarr==1){
													// if $1 is already an array
													type_structure *p = $1.type->next;
													type_structure *q = $1.type;
													while(p->next){
														q->type_size *= atoi(($3.address_pointer)->initial_value.c_str());
														q = p;
														p = p->next;
													}
													q->type_size *= atoi(($3.address_pointer)->initial_value.c_str());		// update the type of array variable
													
													type_structure *r = new type_structure();
													r->type_name = "array";
													r->arr_num = atoi(($3.address_pointer)->initial_value.c_str());
													
													r->type_size = r->arr_num * p->type_size;
													r->isarr = 1;
													r->next = p;
													q->next = r;
													$$ = $1;	
												}
												else{
													// if $1 is not an array
													$$.type = new type_structure();
													($$.type)->type_name = "array";
													($$.type)->arr_num = atoi(($3.address_pointer)->initial_value.c_str());
													
													($$.type)->type_size = ($$.type)->arr_num * ($1.type)->type_size;
													($$.type)->isarr = 1;
													($$.type)->next = $1.type;			// make the variable of type array
													$$.array = $1.address_pointer;
													$1.array = $1.address_pointer;	
													$1.type = $$.type;
												}
												
												symtab_current->deltemp(($3.address_pointer)->sym_name);	
											}
											
	| direct_declarator '[' ']'					{}
											
	| direct_declarator '(' P paramtypelist ')'	/* Non-Terminal P is used to create a new symbol table for this function and to store the parameter quad_list in this new symbol table */
											{
												if(($1.type)->type_name!="function"){
													symtab_current->sym_name = ($1.address_pointer)->sym_name;	// sym_name of symbol table of this function
													($1.type)->return_type = new type_structure();
													($1.type)->return_type->type_name = ($1.type)->type_name;
													($1.type)->return_type->type_size = ($1.type)->type_size;
													($1.type)->return_type->isarr = ($1.type)->isarr;
													($1.type)->return_type->next = ($1.type)->next;
													
													($1.type)->type_name = "function";			//
													($1.type)->type_size = symtab_current->offset;	//
													($1.type)->isarr = 0;					// set type of this function in global symbol table
													($1.type)->next = NULL;					//
													
													$$ = $1;
													Quadruples::emit("func","",($1.address_pointer)->sym_name);
												}
												else{
													symtab_current = ($1.address_pointer)->func_next;
													$$ = $1;	
													Quadruples::emit("func","",($1.address_pointer)->sym_name);
												}
											}
											
	| direct_declarator '(' idlist ')'			{}
	
	| direct_declarator '(' P ')'				/* Non-Terminal P is used to create a new symbol table for this function */
											{
												if(($1.type)->type_name!="function"){
													symtab_current->sym_name = ($1.address_pointer)->sym_name;	// sym_name of symbol table of this function
													($1.type)->return_type = new type_structure();
													($1.type)->return_type->type_name = ($1.type)->type_name;
													($1.type)->return_type->type_size = ($1.type)->type_size;
													($1.type)->return_type->isarr = ($1.type)->isarr;
													($1.type)->return_type->next = ($1.type)->next;
													($1.type)->type_name = "function";			//
													($1.type)->type_size = symtab_current->offset;	//
													($1.type)->isarr = 0;					// set type of function in global symbol table
													($1.type)->next = NULL;					//
												
													$$ = $1;
													Quadruples::emit("func","",($1.address_pointer)->sym_name);
												}
												else{
													symtab_current = ($1.address_pointer)->func_next;
													$$ = $1;	
													Quadruples::emit("func","",($1.address_pointer)->sym_name);
												}
												
											}
	;

paramtypelist:	param_quad_list	{}
	;

param_quad_list:	parameter_declaration			{}
	| param_quad_list ',' parameter_declaration		{}
	;

parameter_declaration:	declaration_type declarator	{}
									
	| declaration_type					{}
	;

idlist:	ID				{}
	| idlist ',' ID		{}
	;	

/*EXPRESSIONS*/
primexp: INT_CONST		{	
						$$.address_pointer = symbol_table::gentemp();							// generate temporary
						($$.address_pointer)->type = new type_structure();							//
						($$.address_pointer)->type->type_name = "int";							//
						($$.address_pointer)->type->isarr = 0;								// set the type
						($$.address_pointer)->type->type_size = int_width;						//
						($$.address_pointer)->type->next = NULL;							//
						char str[10];
						sprintf(str,"%d",$1);									// set initial value
						string str1(str);
						($$.address_pointer)->initial_value = str1;
						($$.address_pointer)->sym_size = ($$.address_pointer)->type->type_size;				// set sym_size
						symtab_current->offset += ($$.address_pointer)->sym_size;					// update total offset of the symbol table
						Quadruples::emit(($$.address_pointer)->initial_value,($$.address_pointer)->sym_name);	// emit Quadruple that represents initialization instruction
						$$.type = ($$.address_pointer)->type;								// 
						$$.array = NULL;										// set the attributes of $$
						$$.point = 0;											//
						$$.top_val = 0;											//
					}

	|   ID			{	
						// Check if it is a global variable/function
						symbol_struct *p = symtab_current->find(*($1.lexeme));
						if(p){
							if(p->type->isarr==1){
								//It is an array
								$$.array = p;
								$$.type = p->type;
								$$.address_pointer = symbol_table::gentemp();  		// Temporary for offset of array
								type_structure *t;
								t = new type_structure();
								t->type_name = "int";
								t->isarr = 0;
								t->type_size = int_width;
								t->next = NULL;
								($$.address_pointer)->type = t;					// $$.address_pointer stores offset of array
								($$.address_pointer)->initial_value = "0";
								($$.address_pointer)->sym_size = int_width; 
								symtab_current->offset += ($$.address_pointer)->sym_size;	
								Quadruples::emit(($$.address_pointer)->initial_value,($$.address_pointer)->sym_name);   // Copy instruction for array offset 
							}
							else{
								// Not an array. 
								$$.type = p->type;        // Set the attributes of primexp i.e. $$
								$$.address_pointer = p;			
								$$.array = NULL;
							}
						}
						else{
							// it is a global variable/function
							p = symtab_global->find(*($1.lexeme));
							if(p->type->type_name!="function"){
								if(p->type->isarr==1){
									//It is an array
									$$.array = p;
									$$.type = p->type;
									$$.address_pointer = symbol_table::gentemp();  		// Temporary for offset of array
									type_structure *t;
									t = new type_structure();
									t->type_name = "int";
									t->isarr = 0;
									t->type_size = int_width;
									t->next = NULL;
									($$.address_pointer)->type = t;					// $$.address_pointer stores offset of array
									($$.address_pointer)->initial_value = "0";
									($$.address_pointer)->sym_size = int_width; 
									symtab_current->offset += ($$.address_pointer)->sym_size;	
									Quadruples::emit(($$.address_pointer)->initial_value,($$.address_pointer)->sym_name);   // Copy instruction for array offset 
								}
								else{
									// Not an array. 
									$$.address_pointer = p;			
									$$.type = p->type;        // Set the attributes of primexp i.e. $$
									$$.array = NULL;
								}
							}
							else{
								//Set the attributes of primexp i.e. $$
								$$.address_pointer = p;  
								$$.type = p->type;
								$$.array = NULL;
							}
						}
						
						$$.point = 0;
						$$.top_val = 0;
					}				
					
	| FLOAT_CONST	{	
						$$.address_pointer = symbol_table::gentemp();							// generate temporary
						($$.address_pointer)->type = new type_structure();							//
						($$.address_pointer)->type->type_name = "float";						//
						($$.address_pointer)->type->isarr = 0;								// set the type
						($$.address_pointer)->type->type_size = float_width;					//
						($$.address_pointer)->type->next = NULL;							//
						char str[50];
						sprintf(str,"%.3f",$1);									// set initial value
						string str1(str);
						($$.address_pointer)->initial_value = str1;
						($$.address_pointer)->sym_size = ($$.address_pointer)->type->type_size;				// set sym_size
						symtab_current->offset += ($$.address_pointer)->sym_size;					// update total offset of the symbol table
						Quadruples::emit(($$.address_pointer)->initial_value,($$.address_pointer)->sym_name);	// emit Quadruple that represents initialization instruction
						$$.type = ($$.address_pointer)->type;								//
						$$.array = NULL;										// set the attributes of $$
						$$.point = 0;											//
						$$.top_val = 0;											//
					}	
	| '(' exp ')'	{$$ = $2;}
	;

postexp:    primexp					{
										$$ = $1;
										if($$.array)$$.top_val = 1;			// a matrix operation may be performed
									}

	| postexp '[' exp ']'			{	
										$$.array = $1.array;				// set base address of array
										$$.type = $1.type->next;			// set type
										$$.point = $1.point;
										$$.top_val = 0;						// matrix operation is not being performed
										$1.top_val = 0;
										
										$$.address_pointer = symbol_table::gentemp();						// generate temporary for offset of array	
										($$.address_pointer)->type = new type_structure();						//
										($$.address_pointer)->type->type_name = "int";						//
										($$.address_pointer)->type->isarr = 0;							// set type
										($$.address_pointer)->type->type_size = int_width;					//
										($$.address_pointer)->type->next = NULL;						//
										($$.address_pointer)->sym_size = int_width;						// set sym_size
										symtab_current->offset += ($$.address_pointer)->sym_size;				// update total offset of symbol table

										symbol_struct *t = symbol_table::gentemp();					// generate temporary
										t->type = new type_structure();								//
										t->type->type_name = "int";								//
										t->type->isarr = 0;									// set type
										t->type->type_size = int_width;							//
										t->type->next = NULL;								//
										t->sym_size = int_width;								// set sym_size
										symtab_current->offset += t->sym_size;						// update total offset of symbol table
										
										char str[10];
										sprintf(str,"%d",($$.type)->type_size);
										
										Quadruples::emit("*",str,($3.address_pointer)->sym_name,t->sym_name);				// Quadruple to set the value
										Quadruples::emit("+",($1.address_pointer)->sym_name,t->sym_name,($$.address_pointer)->sym_name); // of array offset					
									}
									
	| postexp '(' argexplist ')'	{	
										$$.address_pointer = symbol_table::gentemp();					// generate temporary
										($$.address_pointer)->type = ($1.type)->return_type;				// set type
										($$.address_pointer)->sym_size = ($1.type)->return_type->type_size;		// set sym_size
										$$.type = ($1.type)->return_type;						// 			
										$$.array = NULL;								// set attributes of $$ 
										$$.point = $1.point;							//
										$$.top_val = 0;									// matrix operation is not being performed
										$1.top_val = 0;									//
										
										// update total offset of symbol table
										if(($$.address_pointer)->sym_size>=0)symtab_current->offset += ($$.address_pointer)->sym_size;			
										
										param_list *p = $3.head;
										
										while(p){
											Quadruples::emit("param","",p->express.address_pointer->sym_name);	// emit quads of function parameters
											p = p->next;
										}
										
										char str[10];
										sprintf(str,"%d",$3.pnum);
										Quadruples::emit("call",($1.address_pointer)->sym_name,str,($$.address_pointer)->sym_name);	// emit Quadruple of function call
									}
									
	| postexp '(' ')'				{	
										$$.address_pointer = symbol_table::gentemp();					// generate temporary
										($$.address_pointer)->type = ($1.type)->return_type;				// set type
										($$.address_pointer)->sym_size = ($1.type)->return_type->type_size;		// set sym_size
										$$.type = ($1.type)->return_type;						//
										$$.array = NULL;								// set attributes
										$$.point = $1.point;							//
										$$.top_val = 0;									// matrix operation is not being performed
										$1.top_val = 0;									//
										
										// update total offset of symbol table
										if(($$.address_pointer)->sym_size>=0)symtab_current->offset += ($$.address_pointer)->sym_size;			
										
										Quadruples::emit("call",($1.address_pointer)->sym_name,"0",($$.address_pointer)->sym_name);	// emit Quadruple of function call
									}
									
	| postexp '.' ID				{}
	
	| postexp INC					{	
										$$.address_pointer = symbol_table::gentemp();					// generate temporary
										($$.address_pointer)->type = $1.type;						// set type
										($$.address_pointer)->sym_size = ($1.type)->type_size;				// set sym_size
										$$.type = $1.type;								//
										$$.array = NULL;								// set attributes
										$$.point = $1.point;							//
										$$.top_val = 0;									// matrix operation is not being performed
										$1.top_val = 0;									//
										symtab_current->offset += ($$.address_pointer)->sym_size;
										
										symbol_struct *t = symbol_table::gentemp();
										t->type = $1.type;	
										t->sym_size = ($1.type)->type_size;	
										symtab_current->offset += t->sym_size;
										
										if($1.array){
											// emit quads of indexed copy and arithmetic instructions
											Quadruples::emit("rindexed",($1.array)->sym_name,($1.address_pointer)->sym_name,($$.address_pointer)->sym_name);
											Quadruples::emit("rindexed",($1.array)->sym_name,($1.address_pointer)->sym_name,t->sym_name);
											Quadruples::emit("+",t->sym_name,"1",t->sym_name);
											Quadruples::emit("lindexed",($1.address_pointer)->sym_name,t->sym_name,($1.array)->sym_name);
										}
										else{
											// emit quads of arithmetic and copy instructions
											Quadruples::emit(($1.address_pointer)->sym_name,($$.address_pointer)->sym_name);
											Quadruples::emit("+",($1.address_pointer)->sym_name,"1",t->sym_name);
											Quadruples::emit(t->sym_name,($1.address_pointer)->sym_name);
										}																	
									}
									
	| postexp DEC					{	
										$$.address_pointer = symbol_table::gentemp();
										($$.address_pointer)->type = $1.type;	
										($$.address_pointer)->sym_size = ($1.type)->type_size;
										$$.type = $1.type;
										$$.array = NULL;
										$$.point = $1.point;	
										$$.top_val = 0;									// matrix operation is not being performed
										$1.top_val = 0;									//
										symtab_current->offset += ($$.address_pointer)->sym_size;
										
										symbol_struct *t = symbol_table::gentemp();
										t->type = $1.type;	
										t->sym_size = ($1.type)->type_size;	
										symtab_current->offset += t->sym_size;
										
										if($1.array){
											// emit quads of indexed copy and arithmetic instructions
											Quadruples::emit("rindexed",($1.array)->sym_name,($1.address_pointer)->sym_name,($$.address_pointer)->sym_name);
											Quadruples::emit("rindexed",($1.array)->sym_name,($1.address_pointer)->sym_name,t->sym_name);
											Quadruples::emit("-",t->sym_name,"1",t->sym_name);
											Quadruples::emit("lindexed",($1.address_pointer)->sym_name,t->sym_name,($1.array)->sym_name);
										}
										else{
											// emit quads of arithmetic and copy instructions
											Quadruples::emit(($1.address_pointer)->sym_name,($$.address_pointer)->sym_name);
											Quadruples::emit("-",($1.address_pointer)->sym_name,"1",t->sym_name);
											Quadruples::emit(t->sym_name,($1.address_pointer)->sym_name);
										}
									}
	;

unaryexp:    postexp				{$$ = $1;}

	| INC unaryexp					{	
										$$.address_pointer = symbol_table::gentemp();				// generate temporary
										($$.address_pointer)->type = $2.type;					// set type in the symbol table
										($$.address_pointer)->sym_size = ($2.type)->type_size;			// set sym_size in the symbol table
										$$.type = $2.type;							//
										$$.array = NULL;							// set attributes of $$
										$$.point = $2.point;						//
										$$.top_val = $2.top_val;						//
										symtab_current->offset += ($$.address_pointer)->sym_size;		// update total offset in symbol table
										
										symbol_struct *t = symbol_table::gentemp();
										t->type = $2.type;	
										t->sym_size = ($2.type)->type_size;	
										symtab_current->offset += t->sym_size;
										
										if($2.array){
											// emit quads of indexed copy and arithmetic instructions
											Quadruples::emit("rindexed",($2.array)->sym_name,($2.address_pointer)->sym_name,t->sym_name);
											Quadruples::emit("+",t->sym_name,"1",t->sym_name);
											Quadruples::emit("lindexed",($2.address_pointer)->sym_name,t->sym_name,($2.array)->sym_name);
											Quadruples::emit(t->sym_name,($$.address_pointer)->sym_name);
										}
										else{
											// emit quads of arithmetic and copy instructions
											Quadruples::emit("+",($2.address_pointer)->sym_name,"1",t->sym_name);
											Quadruples::emit(t->sym_name,($2.address_pointer)->sym_name);
											Quadruples::emit(t->sym_name,($$.address_pointer)->sym_name);
										}
									}
									
	| DEC unaryexp					{	
										$$.address_pointer = symbol_table::gentemp();				// generate temporary
										($$.address_pointer)->type = $2.type;					// set type in the symbol table
										($$.address_pointer)->sym_size = ($2.type)->type_size;			// set sym_size in the symbol table
										$$.type = $2.type;							//
										$$.array = NULL;							// set attributes of $$
										$$.point = $2.point;						//
										$$.top_val = $2.top_val;						//
										symtab_current->offset += ($$.address_pointer)->sym_size;		// update total offset in symbol table
										
										symbol_struct *t = symbol_table::gentemp();
										t->type = $2.type;	
										t->sym_size = ($2.type)->type_size;	
										symtab_current->offset += t->sym_size;
										
										if($2.array){
											// emit quads of indexed copy and arithmetic instructions
											Quadruples::emit("rindexed",($2.array)->sym_name,($2.address_pointer)->sym_name,t->sym_name);
											Quadruples::emit("-",t->sym_name,"1",t->sym_name);
											Quadruples::emit("lindexed",($2.address_pointer)->sym_name,t->sym_name,($2.array)->sym_name);
											Quadruples::emit(t->sym_name,($$.address_pointer)->sym_name);
										}
										else{
											// emit quads of arithmetic and copy instructions
											Quadruples::emit("-",($2.address_pointer)->sym_name,"1",t->sym_name);
											Quadruples::emit(t->sym_name,($2.address_pointer)->sym_name);
											Quadruples::emit(t->sym_name,($$.address_pointer)->sym_name);
										}
									}
									
	| unaryop castexp				{	
										switch($1){
											case '+':
												$$.address_pointer = symbol_table::gentemp();	// generate temporary 
												($$.address_pointer)->type = $2.type;		// set the address attribute
												($$.address_pointer)->sym_size = ($2.type)->type_size;		//
												if(($2.address_pointer)->initial_value!="")($$.address_pointer)->initial_value = "+" + ($2.address_pointer)->initial_value;
												symtab_current->offset += ($$.address_pointer)->sym_size;		// update total offset of symbol table
												
												$$.array = NULL;		//
												$$.type = $2.type;      // set other attributes
												$$.point = $2.point;	//
												$$.top_val = $2.top_val;	//
												
												Quadruples::emit("+",($2.address_pointer)->sym_name,($$.address_pointer)->sym_name);	// emit Quadruple for unary plus
												break;
											
																								
											case '-':
												$$.address_pointer = symbol_table::gentemp();	// generate temporary 
												($$.address_pointer)->type = $2.type;		// set the address attribute
												($$.address_pointer)->sym_size = ($2.type)->type_size;	//
												if(($2.address_pointer)->initial_value!="")($$.address_pointer)->initial_value = "-" + ($2.address_pointer)->initial_value;
												symtab_current->offset += ($$.address_pointer)->sym_size;	// update total offset of symbol table
												
												$$.array = NULL;		//
												$$.type = $2.type;		// set other attributes
												$$.point = $2.point;	//
												$$.top_val = $2.top_val;	//
												
												Quadruples::emit("-",($2.address_pointer)->sym_name,($$.address_pointer)->sym_name);	// emit Quadruple for unary minus
												break;
												
											case '*':
												$$.address_pointer = $2.address_pointer;				// set address_pointer attribute						
												$$.array = NULL;				// set array attribute	
												$$.type = ($2.type)->next;		// set type attribute
												$$.point = 1;					// set point attribute
												$$.top_val = $2.top_val;			//
												break;
										}
									}
	;

unaryop:    '*'							{$$ = '*';}
	| '+'							{$$ = '+';}
	| '-'							{$$ = '-';}
	;

castexp:    unaryexp				{	
										if($1.array){
											if($1.top_val==0){
												// if unaryexp is an array
												$$.address_pointer = symbol_table::gentemp();
												($$.address_pointer)->type = $1.type;
												($$.address_pointer)->sym_size = ($1.type)->type_size;
												symtab_current->offset += ($$.address_pointer)->sym_size;
											
												$$.array = NULL;
												$$.type = $1.type;
												$$.point = $1.point;
												$$.top_val = $1.top_val;
											
												// emit Quadruple of right indexed copy instruction
												Quadruples::emit("rindexed",($1.array)->sym_name,($1.address_pointer)->sym_name,($$.address_pointer)->sym_name);
											}
											else $$ = $1;
										}
										else{
												$$ = $1;
											}
										}									
									
	;

multexp:    castexp					{$$ = $1;}

	| multexp '*' castexp			{
										typecheck(&($1),&($3));					// check the types
										$$.address_pointer = symbol_table::gentemp();
										($$.address_pointer)->type = $1.type;
										($$.address_pointer)->sym_size = ($1.type)->type_size;
										symtab_current->offset += ($$.address_pointer)->sym_size;
										
										$$.type = $1.type;			//
										$$.array = $1.array;		// set other attributes
										$$.point = $1.point;		//
										$$.top_val = $1.top_val;		//
										
										if($1.top_val==1 && $3.top_val==1){
											$$.array = $$.address_pointer;
											$$.type = new type_structure();			// set type of transpose of postexp i.e. $1
											($$.type)->type_name = "array";
											($$.type)->type_size = ($1.type)->arr_num * ($3.type)->next->arr_num * ($3.type)->next->next->type_size;
											($$.type)->isarr = 1;
											($$.type)->arr_num = ($1.type)->arr_num; 		// row number of $$ matrix is same as $1 matrix
											($$.type)->next = new type_structure();						
											($$.type)->next->type_name = "array"; 
											($$.type)->next->arr_num = ($3.type)->next->arr_num;		// col number of $$ matrix is same as $3 matrix
											($$.type)->next->type_size = ($$.type)->next->arr_num * ($1.type)->next->next->type_size;
											($$.type)->next->isarr = 1;
											($$.type)->next->next = new type_structure();
											($$.type)->next->next->type_name = ($1.type)->next->next->type_name;
											($$.type)->next->next->type_size = ($1.type)->next->next->type_size;
											($$.type)->next->next->next = NULL;
											($$.type)->next->next->isarr = 0;
										
											($$.array)->type = $$.type;						//
											symtab_current->offset -= ($$.array)->sym_size;		// subtract old sym_size
											($$.array)->sym_size = ($$.type)->type_size;			// set new sym_size
											symtab_current->offset += ($$.array)->sym_size;		// add new sym_size
											
											// emit Quadruple of matrix multiplication instruction 
											Quadruples::emit("*",($1.array)->sym_name,($3.array)->sym_name,($$.array)->sym_name);
										}
										else{
											// emit Quadruple of multiplication instruction 
											Quadruples::emit("*",($1.address_pointer)->sym_name,($3.address_pointer)->sym_name,($$.address_pointer)->sym_name);
										}
									}
									
	| multexp '/' castexp			{
										typecheck(&$1,&$3);					// check the types
										$$.address_pointer = symbol_table::gentemp();
										($$.address_pointer)->type = $1.type;
										($$.address_pointer)->sym_size = ($1.type)->type_size;
										symtab_current->offset += ($$.address_pointer)->sym_size;
										
										$$.type = $1.type;			//
										$$.array = $1.array;		// set other attributes
										$$.point = $1.point;		//
										$$.top_val = $1.top_val;		//
										
										if($1.top_val==1 && $3.top_val==1){
											$$.array = $$.address_pointer; 
											Quadruples::emit("/",($1.array)->sym_name,($3.array)->sym_name,($$.array)->sym_name);
										}
										else{
											// emit Quadruple of division instruction
											Quadruples::emit("/",($1.address_pointer)->sym_name,($3.address_pointer)->sym_name,($$.address_pointer)->sym_name);
										}	
									}
									
	| multexp '%' castexp			{
										typecheck(&$1,&$3);					// check the types
										$$.address_pointer = symbol_table::gentemp();
										($$.address_pointer)->type = $1.type;
										($$.address_pointer)->sym_size = ($1.type)->type_size;
										symtab_current->offset += ($$.address_pointer)->sym_size;
										
										$$.type = $1.type;			//
										$$.array = $1.array;		// set other attributes
										$$.point = $1.point;		//
										$$.top_val = $1.top_val;		//
										
										if($1.top_val==1 && $3.top_val==1){
											$$.array = $$.address_pointer;
											Quadruples::emit("%",($1.array)->sym_name,($3.array)->sym_name,($$.array)->sym_name);
										}
										else{
											// emit Quadruple of modulo instruction
											Quadruples::emit("%",($1.address_pointer)->sym_name,($3.address_pointer)->sym_name,($$.address_pointer)->sym_name);
										}	
									}
	;

addexp:    multexp					{$$ = $1;}

	| addexp '+' multexp			{
										typecheck(&$1,&$3);					// check the types
										$$.address_pointer = symbol_table::gentemp();
										($$.address_pointer)->type = $1.type;
										($$.address_pointer)->sym_size = ($1.type)->type_size;
										symtab_current->offset += ($$.address_pointer)->sym_size;
										
										$$.type = $1.type;			//
										$$.array = $1.array;		// set other attributes
										$$.point = $1.point;		//
										$$.top_val = $1.top_val;		//
										
										if($1.top_val==1 && $3.top_val==1){
											$$.array = $$.address_pointer;
											
											// emit Quadruple of matrix addition instruction
											Quadruples::emit("+",($1.array)->sym_name,($3.array)->sym_name,($$.array)->sym_name);
										}
										else{
											// emit Quadruple of addition instruction
											Quadruples::emit("+",($1.address_pointer)->sym_name,($3.address_pointer)->sym_name,($$.address_pointer)->sym_name);
										}	
									}
									
	| addexp '-' multexp			{
										typecheck(&$1,&$3);					// check the types
										$$.address_pointer = symbol_table::gentemp();
										($$.address_pointer)->type = $1.type;
										($$.address_pointer)->sym_size = ($1.type)->type_size;
										symtab_current->offset += ($$.address_pointer)->sym_size;
										
										$$.type = $1.type;			//
										$$.array = $1.array;		// set other attributes
										$$.point = $1.point;		//
										$$.top_val = $1.top_val;		//
										
										if($1.top_val==1 && $3.top_val==1){
											$$.array = $$.address_pointer;
											
											// emit Quadruple of matrix subtraction instruction
											Quadruples::emit("-",($1.array)->sym_name,($3.array)->sym_name,($$.array)->sym_name);
										}
										else{
											// emit Quadruple of subtraction instruction
											Quadruples::emit("-",($1.address_pointer)->sym_name,($3.address_pointer)->sym_name,($$.address_pointer)->sym_name);
										}
									}
	;

shiftexp:    addexp					{$$ = $1;}
	;

relexp:    shiftexp					{$$ = $1;}

	| relexp '<' shiftexp			{
										typecheck(&$1,&$3);					// check the types
										$$.type = new type_structure();
										($$.type)->type_name = "bool";
										($$.type)->type_size = bool_width;
										($$.type)->next = NULL;
										($$.type)->isarr = 0;
										
										$$.true_list = makelist(next_instruction);			// generate true_list of $$
										
										// emit Quadruple of if x<y goto _ instruction
										Quadruples::emit("iflt",($1.address_pointer)->sym_name,($3.address_pointer)->sym_name,"_");
										
										$$.false_list = makelist(next_instruction);		// generate false_list of $$
										Quadruples::emit("_");	
									}
									
	| relexp '>' shiftexp			{
										typecheck(&$1,&$3);					// check the types
										$$.type = new type_structure();
										($$.type)->type_name = "bool";
										($$.type)->type_size = bool_width;
										($$.type)->next = NULL;
										($$.type)->isarr = 0;
										
										$$.true_list = makelist(next_instruction);			// generate true_list of $$
										
										// emit Quadruple of if x>y goto _ instruction
										Quadruples::emit("ifgt",($1.address_pointer)->sym_name,($3.address_pointer)->sym_name,"_");
										
										$$.false_list = makelist(next_instruction);		// generate false_list of $$
										Quadruples::emit("_");	
									}
									
	| relexp LTE shiftexp			{
										typecheck(&$1,&$3);					// check the types
										$$.type = new type_structure();
										($$.type)->type_name = "bool";
										($$.type)->type_size = bool_width;
										($$.type)->next = NULL;
										($$.type)->isarr = 0;
										
										$$.true_list = makelist(next_instruction);			// generate true_list of $$
										
										// emit Quadruple of if x<=y goto _ instruction
										Quadruples::emit("iflte",($1.address_pointer)->sym_name,($3.address_pointer)->sym_name,"_");
										
										$$.false_list = makelist(next_instruction);		// generate false_list of $$
										Quadruples::emit("_");	
									}
									
	| relexp GTE shiftexp			{
										typecheck(&$1,&$3);						// check the types
										$$.type = new type_structure();
										($$.type)->type_name = "bool";
										($$.type)->type_size = bool_width;
										($$.type)->next = NULL;
										($$.type)->isarr = 0;
										
										$$.true_list = makelist(next_instruction);			// generate true_list of $$
										
										// emit Quadruple of if x>=y goto _ instruction
										Quadruples::emit("ifgte",($1.address_pointer)->sym_name,($3.address_pointer)->sym_name,"_");
										
										$$.false_list = makelist(next_instruction);		// generate false_list of $$
										Quadruples::emit("_");	
									}
	;

eqexp:    relexp					{$$ = $1;}

	| eqexp EQ relexp				{
										typecheck(&$1,&$3);						// check the types
										$$.type = new type_structure();
										($$.type)->type_name = "bool";
										($$.type)->type_size = bool_width;
										($$.type)->next = NULL;
										($$.type)->isarr = 0;
										
										$$.true_list = makelist(next_instruction);			// generate true_list of $$
										
										// emit Quadruple of if x==y goto _ instruction
										Quadruples::emit("ifeq",($1.address_pointer)->sym_name,($3.address_pointer)->sym_name,"_");
										
										$$.false_list = makelist(next_instruction);		// generate false_list of $$
										Quadruples::emit("_");	
									}
									
	| eqexp NEQ relexp				{
										typecheck(&$1,&$3);						// check the types
										$$.type = new type_structure();
										($$.type)->type_name = "bool";
										($$.type)->type_size = bool_width;
										($$.type)->next = NULL;
										($$.type)->isarr = 0;
										
										$$.true_list = makelist(next_instruction);			// generate true_list of $$
										
										// emit Quadruple of if x!=y goto _ instruction
										Quadruples::emit("ifneq",($1.address_pointer)->sym_name,($3.address_pointer)->sym_name,"_");
										
										$$.false_list = makelist(next_instruction);		// generate false_list of $$
										Quadruples::emit("_");	
									}
	;

andexp:    eqexp					{$$ = $1;}
	;

xorexp:    andexp					{$$ = $1;}
	;

orexp:    xorexp					{$$ = $1;}
	;
	
M:									{
										$$ = next_instruction; // store the quad_val of next instruction
									}	
;

logandexp:    orexp					{ $$ = $1;}
	| logandexp AND M orexp			/* Non-Terminal M is used to jump to 2nd Boolean Expression if 1st Boolean Expression is true */
									{
										convtobool(&$4);			// convert expression to boolean
										convtobool(&$1);			// convert expression to boolean
										
										$$.type = new type_structure();
										($$.type)->type_name = "bool";
										($$.type)->type_size = bool_width;
										($$.type)->next = NULL;
										($$.type)->isarr = 0;	
										
										backpatch($1.true_list,$3);	
										$$.true_list = $4.true_list;							// generate true_list of $$
										$$.false_list = merge($1.false_list,$4.false_list);	// generate false_list of $$
									}
	;

logorexp:    logandexp 				{$$ = $1;}
	| logorexp OR M logandexp		/* Non-Terminal M is used to jump to 2nd Boolean Expression if 1st Boolean Expression is false */
									{
										convtobool(&$4);				// convert expression to boolean
										convtobool(&$1);				// convert expression to boolean
										
										$$.type = new type_structure();
										($$.type)->type_name = "bool";
										($$.type)->type_size = bool_width;
										($$.type)->next = NULL;
										($$.type)->isarr = 0;	
										
										backpatch($1.false_list,$3);
										$$.false_list = $4.false_list;						// generate false_list of $$
										$$.true_list = merge($1.true_list,$4.true_list);		// generate true_list of $$
									}
	;
	
N:									{
										// generates goto instruction to jump to some specific Quadruple. Mostly used in if-else statements
										$$ = makelist(next_instruction); 
										Quadruples::emit("_");
									}
;

condexp:    logorexp				{$$ = $1;}

	| logorexp '?' exp ':' condexp	/* if logorexp (i.e. $1) is true jump to the code [t = exp (i.e. $3)] and go to the end of condexp(i.e. $$) else jump to the code [t = condexp (i.e. $5)].*/
										{
											convtobool(&$1);				// convert expression to boolean
											$$.address_pointer = symbol_table::gentemp();
											($$.address_pointer)->type = $3.type;
											($$.address_pointer)->sym_size = ($3.type)->type_size;
											symtab_current->offset += ($$.address_pointer)->sym_size;
											
											$$.type = $3.type;			//
											$$.array = $3.array;		// set other attributes
											$$.point = $3.point;		//
											$$.top_val = $3.top_val;		//
											
											backpatch($1.true_list,next_instruction);		// if $1 is true jump to [t = exp (i.e. $4)]
											backpatch($1.false_list,next_instruction+2);	// if $1 is false jump to [t = condexp (i.e. $7)]		
											
											if($3.top_val==1 && $5.top_val==1){
												$$.array = $$.address_pointer;
											
												// emit Quadruple of matrix copy instruction
												Quadruples::emit(($3.array)->sym_name,($$.array)->sym_name);
											}
											else{
												// emit Quadruple of copy instruction
												Quadruples::emit(($3.address_pointer)->sym_name,($$.address_pointer)->sym_name);
											}
											
											char str[10];
											sprintf(str,"%d",next_instruction+2);
											string str1(str);
											Quadruples::emit(str);		// jump to instruction at next_instruction+1 if $$ is assigned to $3
											
											if($3.top_val==1 && $5.top_val==1){
												$$.array = $$.address_pointer;
											
												// emit Quadruple of matrix copy instruction
												Quadruples::emit(($5.array)->sym_name,($$.array)->sym_name);
											}
											else{
												// emit Quadruple of copy instruction
												Quadruples::emit(($5.address_pointer)->sym_name,($$.address_pointer)->sym_name);
											}
										}
	;

assignexp:    condexp				{$$ = $1;}

	| unaryexp assignop assignexp	{
										if($1.point==0){
											
											if($1.array){
												typecheck(&$1,&$3);
												// emit Quadruple of matrix copy instruction
												if($1.top_val==1 && $3.top_val==1)Quadruples::emit(($3.array)->sym_name,($1.array)->sym_name);
												// emit Quadruple of left indexed copy instruction
												else Quadruples::emit("lindexed",($1.address_pointer)->sym_name,($3.address_pointer)->sym_name,($1.array)->sym_name);
											}
											else{
												typecheck(&$1,&$3);
												// emit Quadruple of copy instruction
												Quadruples::emit(($3.address_pointer)->sym_name,($1.address_pointer)->sym_name);
											}
										}
										else{
											// emit Quadruple of left dereference instruction
											Quadruples::emit("ldref",($3.address_pointer)->sym_name,($1.address_pointer)->sym_name);
										}
										
										$$ = $1;
									}
	;

assignop:    '='	{}
	| MULC			{}
	| DIVC			{}
	| MODC			{}
	| ADDC			{}
	| SUBC			{}
	;

exp:    assignexp			{$$ = $1;}
	| exp ',' assignexp		{}
	;

constexp:    condexp		{$$ = $1;}
	;

argexplist:    assignexp			{	
										// Insertion of $1 in quad_list of expressions in $$
										$$.head = new param_list();
										($$.head)->express = $1;
										($$.head)->next = NULL;
										$$.pnum = 1;
									}
									
	| argexplist ',' assignexp		{	
										// Insertion of $3 at the end of quad_list of expressions in $$
										param_list *p,*q;	
										p = $1.head;	
										q = p;		
										while(p){
											q = p;
											p = p->next;
										}	
										
										p = new param_list();
										p->express = $3;
										p->next = NULL;
										q->next = p;
										$1.pnum = $1.pnum + 1;
										$$ = $1;
									}
	;

/*STATEMENTS*/
stmt:	labeled_statement			{}
	| compstmt			{$$ = $1;}
	| expstmt			{$$ = NULL;}
	| selstmt			{$$ = $1;}
	| iteration_statement			{$$ = $1;}
	| jumpstmt			{$$ = $1;} 
	;

labeled_statement:	CASE constexp ':' stmt	{}
	| DEFAULT ':' stmt			{}
	;

compstmt:	'{' '}'				{$$ = NULL;}
	| '{' blockitemlist '}'		{$$ = $2;}
	;

blockitemlist:	blockitem			{$$ = $1;}

	| blockitemlist M blockitem		/* Non-Terminal M is used to jump to 2nd statement block i.e. $3 from 1st statement block i.e. $1 */
									{
										backpatch($1,$2);
										$$ = $3;
									}
	;

blockitem:	declaration			{$$ = NULL;}
	| stmt					{$$ = $1;}
	;

expstmt:	exp ';'			{$$ = $1;}
	| ';'					{$$.address_pointer = NULL;}
	;

selstmt:	IF '(' exp ')' M stmt			/* Non-Terminal M is used to jump to stmt i.e. $6 if the Boolean Expression is true */
											{
												backpatch($3.true_list,$5);
												$$ = merge($3.false_list,$6);	
											}
											
	| IF '(' exp ')' M stmt N ELSE M stmt	/* 1st M is used to jump to 1st stmt i.e. $6 if the Boolean Expression is true and 2nd M is used to jump to 2nd stmt i.e. $10 if the Boolean Expression is false. Non-Terminal N is used to jump from 1st stmt i.e. $6 to end of selstmt i.e. $$ */
											{
												backpatch($3.true_list,$5);	
												backpatch($3.false_list,$9);
												quad_list *tep = merge($6,$7); 	
												$$ = merge(tep,$10);
											}
											
	| SWITCH '(' exp ')' stmt				{}
	;

iteration_statement:	WHILE M '(' exp ')' M stmt		/* 1st M is used to jump to beginning of while loop after dealing with stmt i.e. $7. 2nd M is used to jump to stmt i.e. $7 if the boolean expression exp i.e. $4 is true */		
										{
											backpatch($4.true_list,$6);
											backpatch($7,$2);
											$$ = $4.false_list;
											char str[10];
											sprintf(str,"%d",$2);
											Quadruples::emit(str);	// emit Quadruple of goto instruction
										}
											
	| DO M stmt WHILE '(' exp ')' ';'	/* Non-Terminal M is used to jump to stmt i.e. $3 if the boolean expression exp i.e. $6 is true */
										{
											backpatch($6.true_list,$2);
											$$ = $6.false_list;	
										}
											
	| FOR '(' expopt ';' M expopt ';' M expopt N ')' M stmt		/*3rd M is used to jump to stmt i.e. $13 if the Bool Expression i.e. $6 is true. 2nd M is used to jump to expression represented by $9 after dealing with stmt. Non-Terminal N is used to generate a goto Quadruple after executing the expression represented by $9. 1st M is used to jump to the Bool Expression from the goto Quadruple generated by N. */
															{
																backpatch($13,$8);
																backpatch($10,$5);
																backpatch($6.true_list,$12);
																$$ = $6.false_list;
																char str[10];
																sprintf(str,"%d",$8);
																Quadruples::emit(str);	// emit Quadruple of goto instruction
															}
															
	| FOR '(' declaration expopt ';' expopt ')' stmt		{}
	;

expopt: 				{$$.address_pointer = NULL;}
	| exp				{$$ = $1;}
	;

jumpstmt:	GOTO ID ';'		{}
	| CONTINUE ';'			{}
	| BREAK ';'				{}
	| RETURN expopt ';'		{
								if($2.address_pointer){
									Quadruples::emit("return","",($2.address_pointer)->sym_name);	// emit Quadruple of return statement instruction
								}	
								$$ = NULL;
							}
	;

%%

void yyerror(const char *s){
	printf("%s at %s \n",s,yytext);
}
