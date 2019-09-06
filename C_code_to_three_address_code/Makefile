a.out:	semantics.tab.o lex.yy.o TAC.o
	g++  semantics.tab.o lex.yy.o TAC.o -lfl
	
lex.yy.o:	lex.yy.c	
	g++ -g -c lex.yy.c
	
semantics.tab.o:	semantics.tab.c semantics.tab.h
	g++ -g -c semantics.tab.c
	
TAC.o:	TAC.c TAC.h semantics.tab.h
	g++ -g -c TAC.c
	
lex.yy.c:	lex.l TAC.h semantics.tab.h
	flex lex.l	
	
semantics.tab.c:	semantics.y TAC.h
	bison semantics.y
	
semantics.tab.h:	semantics.y TAC.h
	bison -d semantics.y
	
clean:
	rm a.out lex.yy.o semantics.tab.o TAC.o lex.yy.c semantics.tab.c semantics.tab.h
