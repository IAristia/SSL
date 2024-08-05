CC = gcc
OUTFILE = calculadora.out
CFLAGS = -c

build: pretasks objs
	$(CC) -o $(OUTFILE) ./obj/parser.tab.o ./obj/lex.yy.o

.PHONY: build pretasks clean objs

pretasks:
	lex Scanner.l
	bison -d parser.y
	(if [ ! -d ./obj ]; then mkdir obj; fi)

objs:
	$(CC) $(CFLAGS) parser.tab.c -o obj/parser.tab.o
	$(CC) $(CFLAGS) lex.yy.c -o obj/lex.yy.o

clean:
	rm -rf obj
	rm -rf *.out
	rm -f parser.tab.c
	rm -f parser.tab.h
	rm -f lex.yy.c