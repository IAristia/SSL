#include "Scanner.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum States
{
    Inicio,
    Sumar,
    Restar,
    Dividir,
    Multiplicar,
    Resultado,
    CaracterMenos,
    ParteEntera,
    ParteFlotante,
    Error
};

bool GetNextToken(Token *t)
{
    int c = 0;

    int estado = Inicio;

    // Caracteres de numeros
    char lexeme[10] = {0};
    int contador = 0;

    while ((c = getchar()) != EOF)
    {
        if (cumpleRestriccion(c))
        {
            switch (estado)
            {
            case Inicio:
                if (c == ' ' || c == '\n' || c == '\t')
                {
                    estado = Inicio;
                }
                else if (c == '+' || c == '/' || c == '*')
                {
                    ungetc(c, stdin);
                    estado = c == '+' ? Sumar : (c == '/' ? Dividir : Multiplicar);
                }
                else if (c == '-')
                {
                    estado = CaracterMenos;
                    lexeme[contador++] = c;
                }
                else if (isdigit(c))
                {
                    estado = ParteEntera;
                    lexeme[contador++] = c;
                }
                else if (c == '.')
                {
                    estado = Error;
                }
                break;

            case CaracterMenos:
                if (isdigit(c))
                {
                    estado = ParteEntera;
                    lexeme[contador++] = c;
                }
                else if (c == '.')
                {
                    estado = Error;
                }
                else
                {
                    ungetc(c, stdin);
                    estado = Restar;
                }
                break;

            case ParteEntera:
                if (isdigit(c))
                {
                    lexeme[contador++] = c;
                }
                else if (c == '.')
                {
                    estado = ParteFlotante;
                    lexeme[contador++] = c;
                }
                else
                {
                    ungetc(c, stdin);
                    estado = Inicio;
                    double numeroDouble = atof(lexeme);
                    *t = createToken(numeroDouble, Number, "");
                    return true;
                }
                break;

            case ParteFlotante:
                if (isdigit(c))
                {
                    lexeme[contador++] = c;
                }
                else if (c == '.')
                {
                    estado = Error;
                }
                else
                {
                    ungetc(c, stdin);
                    estado = Inicio;
                    double numeroDouble = atof(lexeme);
                    *t = createToken(numeroDouble, Number, "");
                    return true;
                }
                break;

            case Sumar:
            case Dividir:
            case Multiplicar:
                // ungetc(c, stdin);
                *t = createToken(0.0, estado == Sumar ? Addition : (estado == Dividir ? Division : Multiplication), "");
                return true;

            case Restar:
                ungetc(c, stdin);
                *t = createToken(0.0, Substraction, "");
                return true;

            case Error:
                ungetc(c, stdin);
                estado = Inicio;
                *t = createToken(0.0, LexError, lexeme);
                return false;
            }
        }
        else
        {
            estado = Error;
            lexeme[contador++] = c;
        }
    }

    if (estado == CaracterMenos)
    {
        *t = createToken(0.0, Substraction, "");
        return true;
    }
    else if (estado == Error)
    {
        *t = createToken(0.0, LexError, lexeme);
        return false;
    }

    *t = createToken(0.0, PopResult, "");
    return false;
}

Token createToken(double value, TokenType type, char lexemeError[])
{
    Token token;
    token.type = type;
    token.val = value;
    strncpy(token.lexeme, lexemeError, sizeof(token.lexeme));

    return token;
}

bool cumpleRestriccion(char c)
{
    return isdigit(c) || c == '+' || c == '-' || c == '/' || c == '*' || c == ' ' || c == '.' || c == '\n';
}
