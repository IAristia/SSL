# 28 - Calculadora Infija con Yacc/Bison
Esta vez, el parser lo construye Yacc por nosotros.
##  Building
Build with make or:
```
lex Scanner.l
bison -d parser.y
if [ ! -d ./obj ]; then mkdir obj; fi
gcc -c parser.tab.c -o obj/parser.tab.o
gcc -c lex.yy.c -o obj/lex.yy.o
gcc -o calculadora.out ./obj/parser.tab.o ./obj/lex.yy.o
```