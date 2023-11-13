CC = gcc
OUTFILE = calculadora.out
CFLAGS = -c

SRC = $(shell find . -type f -iname "*.c" -exec basename {} \;)
OBJ = $(SRC:%.c=./obj/%.o)

build: pretasks $(OBJ)
	$(CC) -o $(OUTFILE) $(OBJ)

.PHONY: build pretasks clean

./obj/%.o: ./%.c
	$(CC) $(CFLAGS) $< -o $@

pretasks:
	lex -o Scanner.c Scanner.l && if [ ! -d ./obj ]; then mkdir obj; fi

clean:
	rm -rf obj
	rm -rf *.out
	rm -f Scanner.c