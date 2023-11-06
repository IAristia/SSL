calculadora : Calculator.o Scanner.o StackOfDoublesModule.o
	gcc Calculator.o Scanner.o StackOfDoublesModule.o -o calculadora.exe

Calculator.o : Calculator.c
	gcc -c Calculator.c

Scanner.o : Scanner.c Scanner.h Scanner.l
	gcc -c Scanner.c Scanner.l

StackOfDoublesModule.o : StackOfDoublesModule.c StackOfDoublesModule.h
	gcc -c StackOfDoublesModule.c

clean:
	rm -rf *.o
	rm -rf *.exe