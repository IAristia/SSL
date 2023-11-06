# 26 - Calculadora Polaca con Lex/Flex

## Este trabajo está es una segunda iteración de Capítulo 25, Calculadora Polaca — Léxico, en la cual el scanner se implementa con lex y no con una máquina de estados.

26.1. Objetivo

Aplicar lex para el análisis lexicográfico.

26.2. Restricciones

• No cambiar Scanner.h, implica recompilar solo Scanner.c y volver a vincular.

• Utilizar make para construir el hacer uso de lex.

• La única diferencia está en Scanner.c, en el cual la función GetNextToken debe invocar a la función yylex.

26.3. Productos

• Sufijo del nombre de la carpeta: PolCalLex.

• Los mismos que Capítulo 25, Calculadora Polaca — Léxico con la adición de /Scanner.l


# 28 - Calculadora Infija con Yacc/Bison

Esta vez, el parser lo construye Yacc por nosotros.
