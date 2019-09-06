%{
#include<iostream>
#include<map>
#include<stdio.h>
#define ID 1
#define OTH 2
#define EO 3
#define ARRY 4
#define ARRY1 5
using namespace std;
map<string,int> varmap;
%}
%%
[i][f] {return(OTH);}
[p][a][r][a][m] {return(OTH);}
[g][o][t][o] {return(OTH);}
[a-zA-z]+[a-zA-z0-9]*+[\[]+[0-9]*+[\]] {return(ARRY);}
[a-zA-z]+[a-zA-z0-9]*+[\[]+[a-zA-z]+[a-zA-z0-9]*+[\]] {return(ARRY1);}
[a-zA-z]+[a-zA-z0-9]*[:] {return(OTH);}
[a-zA-z]+[a-zA-z0-9]* {return(ID);}
<<EOF>> {return(EO);}
(.|\n) {return(OTH);}
%%
int yywrap()
{
	return 1;
}
int main()
{
	int k,n=1;
	FILE *temp = fopen("mid.txt","w");
	while(1)
	{

		k=yylex();

		if(k==ID)
		{
			fprintf(temp,"%s\n",yytext);
			n++;
		}
		else if(k==ARRY || k==ARRY1){
			int i=0;
			int r=0;
			int s = strlen(yytext);
			char str[40];
			while(r<s)
			{
              if(yytext[r] != '[')
              str[r] = yytext[r];
              else break;
              r++;
			}
           
			while(r<40)
			{
              str[r] = '\0';
              r++;
			}

			while(i<25)
			{
				
				
				
				fprintf(temp,"%s[%d]\n",str,i);
				i++;
				n++;
			}
			
			fprintf(temp,"%s\n",yytext);

		}
		else if(k==EO)
		{
			break;
		}
        
        

	}
    
    fclose(temp);
	
	return 0;
}