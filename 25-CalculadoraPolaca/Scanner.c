#include "Scanner.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool GetNextToken(Token *t) {
    // Ver para que sirve ungetc y donde lo deberiamos usar

    int c = 0;

    int estado = 0;

    // Caracteres de numeros
    char lexeme[10] = {0};
    int contador = 0;

    while ((c = getchar()) != EOF) {
        if (estado == 0) {
            if (c == ' ' || c == '\n' || c == '\t') {
                estado = 0;
            } else if (c == '-' && (c = getchar()) == EOF) {
                *t = createToken(0.0, Substraction);
                return true;
            } else if (isdigit(c) || c == '-' || c == '.') {
                estado = 1;
                lexeme[contador] = c;
                contador++;
            } else if (c == '+') {
                *t = createToken(0.0, Addition);
                return true;
            } else if (c == '/') {
                *t = createToken(0.0, Division);
                return true;
            } else if (c == '*') {
                *t = createToken(0.0, Multiplication);
                return true;
            } else  // Si no es operando y no es operador
            {
                *t = createToken(0.0, LexError);
                return false;
            }
        } else {
            if ((c == ' ' || c == '\n' || c == '\t')) {
                estado = 0;

                if (strlen(lexeme) == 1 && lexeme[0] == '-') {
                    *t = createToken(0.0, Substraction);
                    return true;
                } else {
                    double numeroDouble = atof(lexeme);
                    *t = createToken(numeroDouble, Number);
                    return true;
                }

                // Limpiar array de numero
                for (int i = 0; i < contador; i++) lexeme[i] = 0;

                contador = 0;
            } else if (isdigit(c) || c == '.') {
                estado = 1;
                lexeme[contador] = c;
                contador++;
            } else {
                *t = createToken(0.0, LexError);
                return false;
            }
        }
    }

    // Fin del stream
    *t = createToken(0.0, PopResult);
    return false;
}

Token createToken(double value, TokenType type) {
    Token token;
    token.type = type;
    token.val = value;

    return token;
}