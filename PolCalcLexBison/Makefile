# Globales
CC = gcc
OUTFILE = calculadora.out

### Reglas ###
SRC = $(shell find . -type f -iname "*.c" -exec basename {} \;)
OBJ = $(SRC:%.c=./obj/%.o)


build: makefolder $(OBJ)
	$(CC) -o $(OUTFILE) $(OBJ)

CFLAGS = -c

./obj/%.o: ./%.c
	$(CC) $(CFLAGS) $< -o $@

makefolder:
	if [ ! -d ./obj ]; then mkdir obj; fi
	lex Scanner.l
	bison -d parser.y

# Clean
clean:
	rm -rf obj
	rm -rf *.out
	rm parser.tab.*
	rm lex.yy.c