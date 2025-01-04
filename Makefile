CC = g++
CFLAGS = -Wno-register 

all: compilator

compilator: compilator.tab.c lex.yy.c
	$(CC) $(CFLAGS) compilator.tab.c lex.yy.c -o compilator

lex.yy.c: compilator.l compilator.tab.c
	flex compilator.l

compilator.tab.c: compilator.y
	bison -d -Wcounterexamples compilator.y

clean:
	rm -f compilator compilator.tab.* lex.yy.c

.PHONY: all clean
