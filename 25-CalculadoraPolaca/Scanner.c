#include "Scanner.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            if (estado == Inicio)
            {
                if (c == ' ' || c == '\n' || c == '\t')
                {
                    estado = Inicio;
                }
                else if (c == '-')
                {
                    estado = CaracterMenos;
                    lexeme[contador] = c;
                    contador++;
                }
                else if (isdigit(c))
                {
                    estado = LiteralPositivo;
                    lexeme[contador] = c;
                    contador++;
                }
                else if (c == '.')
                {
                    estado = Error;
                }
                else if (c == '+')
                {
                    ungetc(c, stdin);
                    estado = Sumar;
                }
                else if (c == '/')
                {
                    ungetc(c, stdin);
                    estado = Dividir;
                }
                else if (c == '*')
                {
                    ungetc(c, stdin);
                    estado = Multiplicar;
                }
            }
            else if (estado == CaracterMenos) // ya leí - , ahora puedo leer un dígito, otro operadoru .
            {
                if (isdigit(c)) // leo un dígito
                {
                    estado = LiteralNegativo;
                    lexeme[contador] = c;
                    contador++;
                }
                else if (c == '.') // leo un .
                {
                    estado = Error;
                }
                else // leo un espaciador u operando
                {
                    ungetc(c, stdin);
                    estado = Restar;
                }
            }
            else if (estado == LiteralNegativo) // ya leí -1
            {
                if (isdigit(c))
                {
                    estado = LiteralNegativo;
                    lexeme[contador] = c;
                    contador++;
                }

                else if (c == '.')
                {
                    estado = LiteralNegativoFlotante;
                    lexeme[contador] = c;
                    contador++;
                }
                else // c = espaciador u operando
                {
                    estado = LiteralNegativoFinal;
                    ungetc(c, stdin);
                }
            }
            else if (estado == LiteralNegativoFlotante)
            {
                if (isdigit(c))
                {
                    estado = LiteralNegativoFlotante;
                    lexeme[contador] = c;
                    contador++;
                }
                else if (c == '.')
                {
                    estado = Error;
                    lexeme[contador] = c;
                    contador++;
                }
                else // c = espaciador u operando
                {
                    estado = LiteralNegativoFinal;
                    ungetc(c, stdin);
                }
            }
            else if (estado == LiteralNegativoFinal)
            {
                ungetc(c, stdin);
                estado = Inicio;
                double numeroDouble = atof(lexeme);
                *t = createToken(numeroDouble, Number, "");
                return true;
            }
            else if (estado == LiteralPositivo) // ya leí 1
            {
                if (isdigit(c))
                {
                    estado = LiteralPositivo;
                    lexeme[contador] = c;
                    contador++;
                }
                else if (c == '.')
                {
                    estado = LiteralPositivoFlotante;
                    lexeme[contador] = c;
                    contador++;
                }
                else // c = espaciador u operando
                {
                    estado = LiteralPositivoFinal;
                    ungetc(c, stdin);
                }
            }
            else if (estado == LiteralPositivoFlotante)
            {
                if (isdigit(c))
                {
                    estado = LiteralPositivoFlotante;
                    lexeme[contador] = c;
                    contador++;
                }
                else if (c == '.')
                {
                    estado = Error;
                    lexeme[contador] = c;
                    contador++;
                }
                else
                {
                    estado = LiteralPositivoFinal;
                    ungetc(c, stdin);
                }
            }
            else if (estado == LiteralPositivoFinal)
            {
                ungetc(c, stdin);
                estado = Inicio;
                double numeroDouble = atof(lexeme);
                *t = createToken(numeroDouble, Number, "");
                return true;
            }
            else if (estado == Sumar)
            {
                estado = Inicio;
                *t = createToken(0.0, Addition, "");
                return true;
            }
            else if (estado == Restar)
            {
                estado = Inicio;
                *t = createToken(0.0, Substraction, "");
                return true;
            }
            else if (estado == Dividir)
            {
                estado = Inicio;
                *t = createToken(0.0, Division, "");
                return true;
            }
            else if (estado == Multiplicar)
            {
                estado = Inicio;
                *t = createToken(0.0, Multiplication, "");
                return true;
            }
            else if (estado == Error)
            {
                ungetc(c, stdin);
                estado = Inicio;
                *t = createToken(0.0, LexError, lexeme);
                return false;
            }
        }
        else
        {
            estado = Error;
            lexeme[contador] = c;
            contador++;
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

    // Fin del stream
    *t = createToken(0.0, PopResult, "");
    return false;
}

Token createToken(double value, TokenType type, char lexemeError[])
{
    Token token;
    token.type = type;
    token.val = value;
    strncpy(token.lexeme, lexemeError, sizeof(token.lexeme));
    // token.lexeme[sizeof(token.lexeme) - 1] = '\0';

    return token;
}

bool cumpleRestriccion(char c)
{
    return isdigit(c) || c == '+' || c == '-' || c == '/' || c == '*' || c == ' ' || c == '.' || c == '\n';
}
