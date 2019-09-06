%{
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include<bits/stdc++.h>
#include <sstream>
using namespace std;
map <string,int> varmap;
int lookup(char *);
char* check(char* a);
int yylex(void);
#define YYSTYPE char *
void yyerror (char const *s) {
   		//fprintf (stderr, "%s\n", s);
 }
FILE *temp;
extern char *yytext;
int labelcount=0;
int kk=0;
int aa=0;
int ll=0;
int linenum=0;
string genLabel();
%}


%start lines
%token	NUM ID EQ OSB CSB
%token BINARY_OPERATORS
%token	PLUS	MINUS	TIMES	DIVIDE	
%token SMALLER SMALLEREQ GREATER GREATEREQ EQEQ 
%token IF GOTO param  ret OPT FLOAT
%token LABEL CALL COMMA LEFTSQPAR RIGSQPAR 
%token STAR ANDP  UNARY_OPS PUSH
%%

lines:  	/* empty */
        	| lines line /* do nothing */ 

line: 		binary  
			| unary 
			| copy 
			| conditional_jump 
			| unconditional_jump 
			| parameters 
			| function_call {ll++;}
			| indexed_copy 
			| address_pointer_assignment 
			| label1 
			| retur 
			| comma 
			| typechange


retur:		ret identifiernum
				{
				fprintf(temp, "l%d: ", ++ll);
				printf("ret\n");
				int k=lookup($2);
				if(k==-1)
							{
								fprintf(temp,"li.s $f15, %s\n",check($2));
							}
							else
							{
								fprintf(temp,"lwc1 $f15, %d($sp)\n",8*k - 8);
							}
							fprintf(temp,"jr $ra\n");

				}

typechange: identifier EQ FLOAT identifiernum{
					fprintf(temp, "l%d: ", ++ll);
                    printf("converting into float\n");
	                int k=lookup($4);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",$3);
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							
						k=lookup($1);
						fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);

				}			
			
identifiernum : identifier {$$ = $1;}
				| num {$$ = $1;}
				

binary_ops: BINARY_OPERATORS { $$ = strdup(yytext); }	

identifier: ID { $$ = strdup(yytext); }
			

num: 		NUM {$$ = strdup(yytext);}

label : LABEL {$$ = strdup(yytext);}
comma : COMMA {$$ = strdup(yytext);}


unary: 		identifier EQ UNARY_OPS identifier {
			fprintf(temp, "l%d: ", ++ll);
}

	
binary: 	identifier EQ identifiernum binary_ops identifiernum {
						fprintf(temp, "l%d: ", ++ll);
						
						
						cout<<check($3)<<endl;
						printf("%s\n",check($3));
						if(strcmp($4,"+")==0)
						{
							printf("binaryyyy\n");

							int k=lookup($3);
							int k2 = lookup($3);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($3));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							//pushing into stack first arg
							
							
							


							k=lookup($5);
							if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check($5));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}

							
							
							fprintf(temp,"add.s $f0, $f0, $f1\n");
							k=lookup($1);
							
							fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);
									
						}else if(strcmp($4,"-")==0){
							cout<<"MINUS"<<endl;
							int k=lookup($3);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($3));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							


							k=lookup($5);
							if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check($5));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}
							
							fprintf(temp,"sub.s $f0, $f0, $f1\n");
							k=lookup($1);
							
							fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);
									
						}else if(strcmp($4,"*")==0){
							int k=lookup($3);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($3));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							
							k=lookup($5);
							if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check($5));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}
							
							fprintf(temp,"mul.s $f0, $f0, $f1\n");
							k=lookup($1);
							
							fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);
									
						}else if(strcmp($4,"/")==0){
							int k=lookup($3);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($3));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							


							k=lookup($5);
							if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check($5));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}
							
							fprintf(temp,"div.s $f0, $f0, $f1\n");
							k=lookup($1);
							
							fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);
									
						}else if(strcmp($4,"<")==0){
							
							int k=lookup($3);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($3));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							//pushing into stack first arg
							fprintf(temp,"swc1 $f0, 0($sp)\n");
							fprintf(temp,"addiu $sp, $sp, -8\n");


							k=lookup($5);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($5));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
							fprintf(temp,"lwc1 $f1, 8($sp)\n");
							fprintf(temp,"addiu $sp, $sp, 8\n");
							fprintf(temp,"sub.s $f0, $f0, $f1\n");

							string l1 = genLabel();
							string l2 = genLabel();

							cout<<"l1 "<<l1<<endl;
							cout<<"l2 "<<l2<<endl;

							fprintf(temp, "bgtz $f0 %s\n", l1.c_str() );
							fprintf(temp, "li.s $f0, 0\n" );
							fprintf(temp, "b %s\n",l2.c_str() );
							fprintf(temp, "%s:",l1.c_str() );
							fprintf(temp, "li.s $f0, 1\n" );
							fprintf(temp, "%s:",l2.c_str() );
							k=lookup($1);
							
							fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);
									
						}else if(strcmp($4,">")==0){
							
							int k=lookup($3);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($3));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							//pushing into stack first arg
							fprintf(temp,"swc1 $f0, 0($sp)\n");
							fprintf(temp,"addiu $sp, $sp, -8\n");


							k=lookup($5);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($5));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
							fprintf(temp,"lwc1 $f1, 8($sp)\n");
							fprintf(temp,"addiu $sp, $sp, 8\n");
							fprintf(temp,"sub.s $f0, $f1, $f0\n");

							string l1 = genLabel();
							string l2 = genLabel();

							cout<<"l1 "<<l1<<endl;
							cout<<"l2 "<<l2<<endl;

							fprintf(temp, "bgtz $f0 %s\n", l1.c_str() );
							fprintf(temp, "li.s $f0, 0.0\n" );
							fprintf(temp, "b %s\n",l2.c_str() );
							fprintf(temp, "%s:",l1.c_str() );
							fprintf(temp, "li.s $f0, 1\n" );
							fprintf(temp, "%s:",l2.c_str() );
							k=lookup($1);
							
							fprintf(temp,"swc1 $f0, %d($t0)\n",8*k - 8);
									
						}else if(strcmp($4,"==")==0){
							
							int k=lookup($3);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($3));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}

							//pushing into stack first arg
							fprintf(temp,"sw $f0, 0($sp)\n");
							fprintf(temp,"addiu $sp, $sp, -8\n");


							k=lookup($5);
							if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($5));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
							fprintf(temp,"lwc1 $f1, 8($sp)\n");
							fprintf(temp,"addiu $sp, $sp, 8\n");
							

							string l1 = genLabel();
							string l2 = genLabel();

							cout<<"l1 "<<l1<<endl;
							cout<<"l2 "<<l2<<endl;

							fprintf(temp, "beq $f0 $f1 %s\n", l1.c_str() );
							fprintf(temp, "li.s $f0, 0\n" );
							fprintf(temp, "b %s\n",l2.c_str() );
							fprintf(temp, "%s:",l1.c_str() );
							fprintf(temp, "li.s $f0, 1\n" );
							fprintf(temp, "%s:",l2.c_str() );
							k=lookup($1);
							
							fprintf(temp,"swc1 $f0, %d($sp)\n",8*k - 8);
									
						}
					}
			


copy: 		identifier EQ identifier {
										fprintf(temp, "l%d: ", ++ll);
										printf("inden1 %s\n",check($3));
										int k = lookup($3);
										fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k-8);
										k = lookup($1);
										fprintf(temp,"swc1 $f0, %d($sp)\n",8*k-8);
									}
			| identifier EQ num 	{
										fprintf(temp, "l%d: ", ++ll);
										printf("inden %s %s\n",$3, check($3));
										int k = lookup($1);
										fprintf(temp,"li.s $f0, %s\n",check($3));
									
										fprintf(temp,"swc1 $f0, %d($sp)\n",8*k-8);
									
									}
label1: label

		{	if(aa==1) {
				aa=0;
				fprintf(temp,"li $v0,10\nsyscall\n\n");
				
			}
			else if(strcmp($1,"main:")==0) aa=1;
			printf("level %s\n",$1);
			fprintf(temp,"%s\n",$1);
			ll++;
		}
conditional_jump : IF identifier GOTO label
					 {
					 fprintf(temp, "l%d: ", ++ll);
					 	//remove : from label:
					 	int l=strlen($4);
					 	$4[l-1]=0;
                        
                        int r = strlen($4);
                        char nst[25];
                        int i=0;
                        while($4[i] !=':')
                        {
                          nst[i] = $4[i];
                          i++;
                        }

					 	cout<<"yes1"<<endl;
					 	int k=lookup($2);
					 	fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k-8);
				   	 	fprintf(temp,"li.s $f1, 0\n");
				   	 	fprintf(temp,"c.eq.s $f0, $f1\n");
						fprintf(temp,"bc1f %s\n",nst);		

											
					 }

				   | IF num GOTO label 
				   	 {
				   	 	//remove : from label:
				   	 	fprintf(temp, "l%d: ", ++ll);
				   	 	int l=strlen($4);
					 	$4[l-1]=0;
					 	int r = strlen($4);
                        char nst[25];
                        int i=0;
                        while($4[i] !=':')
                        {
                          nst[i] = $4[i];
                          i++;
                        }

				   	 	cout<<"yes2"<<endl;
				   	 	fprintf(temp,"li.s $f0, %s\n",check($1));
				   	 	fprintf(temp,"li.s $f1, 0.0\n");
				   	 	fprintf(temp,"c.eq.s $f0, $f1\n");
						fprintf(temp,"bc1t %s\n",nst);		

				   	 }
				   | IF identifiernum binary_ops identifiernum GOTO label
				   {
				   fprintf(temp, "l%d: ", ++ll);
				     printf("a something b %s\n",$3);
				     int r = strlen($6);
                        char nst[25];
                        int i=0;
                        while($6[i] !=':')
                        {
                          nst[i] = $6[i];
                          i++;
                        }

                        while(i<25)
                        {
                           nst[i] = '\0';
                           i++;
                        }

				     if(strcmp($3,"==")==0)
				     {
				        int k=lookup($2);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($2));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
						 k=lookup($4);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check($4));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}

						fprintf(temp,"c.eq.s $f0, $f1\n");
						fprintf(temp,"bc1t %s\n",nst);		

				     }

				     if(strcmp($3,">=")==0)
				     {
				        int k=lookup($2);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($2));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
						 k=lookup($4);
				        if(k==-1)
							{	
								fprintf(temp,"li.s $f1, %s\n",check($4));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}
						fprintf(temp,"c.lt.s $f0, $f1\n");
						fprintf(temp,"bc1f %s\n",nst);		

				     }

				     if(strcmp($3,">")==0)
				     {
				        int k=lookup($2);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($2));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
						 k=lookup($4);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check($4));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}

	
						fprintf(temp,"c.le.s $f0, $f1\n");
						fprintf(temp,"bc1f %s\n",nst);		
	

				     }

				     if(strcmp($3,"<=")==0)
				     {
				        int k=lookup($2);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($2));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
						 k=lookup($4);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check($4));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}
						fprintf(temp,"c.le.s $f0, $f1\n");
						fprintf(temp,"bc1t %s\n",nst);		
		

				     }
				     if(strcmp($3,"<")==0)
				     {
				        int k=lookup($2);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f0, %s\n",check($2));
							}
							else
							{
								fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
							}
						 k=lookup($4);
				        if(k==-1)
							{
								fprintf(temp,"li.s $f1, %s\n",check($4));
							}
							else
							{
								fprintf(temp,"lwc1 $f1, %d($sp)\n",8*k - 8);
							}
						fprintf(temp,"c.lt.s $f0, $f1\n");
						fprintf(temp,"bc1t %s\n",nst);		


				     }


				   }
				   


unconditional_jump : GOTO label
					 {
					 	fprintf(temp, "l%d: ", ++ll);
					 	//remove : from label:
					 	
					 	char nst[25];
                        int i=0;
                        while($2[i] !=':')
                        {
                          nst[i] = $2[i];
                          i++;
                        }

                        while(i<25)
                        {
                           nst[i] = '\0';
                           i++;
                        }
					 	
                         


					 	cout<<"yes3"<<endl;
					 	fprintf(temp,"j %s\n",nst);
					 }


			
function_call : CALL label COMMA NUM {
				kk=0;
				int size = strlen($2);
				char str[25];
				int i=0;
				while($2[i] != ':')
				{
					str[i] = $2[i];
					i++;
				}

				while(i<25)
				{
				  str[i] = '\0';
				  i++;
				}

				printf("function call\n");
				fprintf(temp,"jal %s\n", str);
				cout<<"yes7"<<endl;
				}
				| identifier EQ CALL label COMMA NUM{


				kk=0;
				int size = strlen($4);
				char str[25];
				int i=0;
				while($4[i] != ':')
				{
					str[i] = $4[i];
					i++;
				}

				while(i<25)
				{
				  str[i] = '\0';
				  i++;
				}

				printf("function call\n");
				fprintf(temp,"jal %s\n", str);
				int k=lookup($1);
				fprintf(temp,"lwc1 $f0, %d($sp)\n",8*k - 8);
				fprintf(temp,"mov.s , $f0, $f15\n");
				fprintf(temp,"swc1 $f0, %d($sp)\n",8*k-8);

				}

parameters : param identifiernum {
					fprintf(temp, "l%d: ", ++ll);
					printf("param\n");
									int k = lookup($2);
									if(k==-1){
									   fprintf(temp,"li.s $f%d, %s\n",kk,check($2));
									}
									else
									{
									fprintf(temp,"lwc1 $f%d, %d($sp)\n",kk,8*k - 8);
									}
									kk++;

							   }


indexed_copy : 	identifier EQ identifier LEFTSQPAR num RIGSQPAR 
				| identifier EQ identifier LEFTSQPAR identifier RIGSQPAR {cout<<"yes8"<<endl;}

address_pointer_assignment : 	STAR identifier EQ identifier 
								| identifier EQ STAR identifier | identifier EQ ANDP identifier |ANDP identifier EQ identifier | STAR identifier EQ num
								{cout<<"yes9"<<endl;}
%%


string genLabel(){
	string l = "_lb";
	stringstream ss;
	ss<<labelcount;
	labelcount++;
	cout<<labelcount<<endl;
	
	return l+ss.str();
}


char* check(char* a)
{
	int n=0;
	for(int r=0;a[r] !='\0';r++)
	n++;
	for(int i=0;i<n;i++)
	{
	  if(a[i]=='.')
	  return a;
	}
	char *k;
	k = (char *)malloc(25);
	
	int i=0;
	for(i=0; i<n; i++) k[i]=a[i];
	k[i++]='.';
	k[i++]='0';
	while(i<25){
	k[i]='\0';
	i++;
	}

	
	return (char *)k;
}


int lookup(char * a)
{
	string x(a);
	if(varmap.find(x)!=varmap.end())return varmap[x];
	else return -1;
}




int main (void) {
	//printf("yes\n");
	char a[1000];
	temp=fopen("mid.txt","r");
	int k=1;
	
	while(fscanf(temp,"%s",a)!=EOF)
	{
		string b(a);
		//cout<<a<<endl;
		//fscanf(temp,"%d",&k);
		if(varmap.find(b)==varmap.end()){varmap[b]=k++;}
	}
	fclose(temp);
	//printf("yes\n");
	temp=fopen("out.s","w+");
	
	
	fprintf(temp,".data\n .text\n j main\n");
	yyparse ();
	if(aa==1)
	{
	  fprintf(temp,"li $v0, 10\n syscall\n");
	}

	fclose(temp);
	
	return 0;
}


int yyerror (char *s) {fprintf (stderr, "%s\n", s); return 1;}
