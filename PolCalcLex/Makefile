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
	lex -o Scanner.c Scanner.l && if [ ! -d ./obj ]; then mkdir obj; fi

# Clean
clean:
	rm -rf obj
	rm -rf *.out