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

# Clean
clean:
	rm -rf obj
	rm -rf *.out



# Makefile opcional\
calculadora : Calculator.o Scanner.o StackOfDoublesModule.o \
	gcc Calculator.o Scanner.o StackOfDoublesModule.o -o calculadora.exe \
\
Calculator.o : Calculator.c\
	gcc -c Calculator.c\
\
Scanner.o : Scanner.c Scanner.h\
	gcc -c Scanner.c\
\
StackOfDoublesModule.o : StackOfDoublesModule.c StackOfDoublesModule.h\
	gcc -c StackOfDoublesModule.c\
\
clean:\
	rm -rf *.o\
	rm -rf *.exe\