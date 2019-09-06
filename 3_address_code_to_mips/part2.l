%{
#include<stdio.h>
#include<iostream>
#include "y.tab.h"
using namespace std;
%}
%%
[i][f] {return(IF);}
[c][a][l][l] {return(CALL);}
[r][e][t] {return(ret);}
[(][f][l][o][a][t][)] {return(FLOAT);}
"," {return(COMMA);}
[p][a][r][a][m] {return(param);}
[g][o][t][o] {return(GOTO);}
[a-zA-z]+[a-zA-z0-9]* {return(ID);}
"==" {return(BINARY_OPERATORS);}
[-+*/!<>]+"="* { return(BINARY_OPERATORS);}
[0-9.]+ {return(NUM);}
[=] {return(EQ);}
[&] {return(ANDP);}
[a-zA-z]+[a-zA-z0-9]*+[:] {return(LABEL);}

(.|\n)
%%
int yywrap()
{
	return 1;
}
