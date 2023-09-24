#include "Scanner.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool GetNextToken(Token *t)
{
    int c = 0;

    int estado = 0;

    // Caracteres de numeros
    char lexeme[10] = {0};
    int contador = 0;

    while ((c = getchar()) != EOF)
    {
        printf("DENTRO DEL WHILE DE GETNEXTTOKEn");
        if (!isdigit(c) && c != '+' && c != '-' && c != '/' && c != '*' && c != '.' && c != ' ')
        {
            estado == Error;
        }
        else if (estado == Inicio)
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
            else if (isdigit(c) || c == '.')
            {
                estado = LiteralPositivo;
                lexeme[contador] = c;
                contador++;
            }
            else if (c == '+')
            {
                estado == Sumar;
            }
            else if (c == '/')
            {
                estado == Dividir;
            }
            else if (c == '*')
            {
                estado == Multiplicar;
            }
            else // Si no es operando y no es operador
            {
                estado == Error;
            }
        }
        else if (estado == CaracterMenos)
        {
            if (!isdigit(c))
            {
                estado = Inicio;
                *t = createToken(0.0, Substraction);
                // ungetc(c, stdin);
                return true;
            }
            else
            {
                estado = LiteralNegativo;
            }
        }
        else if (estado == LiteralNegativo)
        {
            // -1.
            if (!isdigit(c) && c != '.')
            {
                estado = LiteralNegativoFinal;
                // ungetc(c, stdin);
                // Ver si crear token aca
            }
            else if (c == '.')
            {
                estado = LiteralNegativoFlotante;
                lexeme[contador] = c;
                contador++;
            }
            else
            {
                lexeme[contador] = c;
                contador++;
            }
        }
        else if (estado == LiteralNegativoFlotante)
        {
            if (!isdigit(c))
            {
                estado = LiteralNegativoFinal;
                // ungetc(c, stdin);
                // Ver si crear token aca
            }
            else
            {
                lexeme[contador] = c;
                contador++;
            }
        }
        else if (estado == LiteralNegativoFinal)
        {
            estado = Inicio;
            ungetc(c, stdin);
            double numeroDouble = atof(lexeme);
            *t = createToken(numeroDouble, Number);
            return true;
        }
        else if (estado == LiteralPositivo)
        {
            if (!isdigit(c) && c != '.')
            {
                estado = LiteralPositivoFinal;
                // ungetc(c, stdin);
                // Ver si crear token aca
            }
            else if (c == '.')
            {
                estado = LiteralPositivoFlotante;
                lexeme[contador] = c;
                contador++;
            }
            else
            {
                lexeme[contador] = c;
                contador++;
            }
        }
        else if (estado == LiteralPositivoFlotante)
        {
            if (!isdigit(c))
            {
                estado = LiteralPositivoFinal;
                // ungetc(c, stdin);
                // Ver si crear token aca
            }
            else
            {
                lexeme[contador] = c;
                contador++;
            }
        }
        else if (estado == LiteralPositivoFinal)
        {
            estado = Inicio;
            ungetc(c, stdin);
            double numeroDouble = atof(lexeme);
            *t = createToken(numeroDouble, Number);
            return true;
        }
        else if (estado == Sumar)
        {
            *t = createToken(0.0, Addition);
            return true;
        }
        else if (estado == Restar)
        {
            *t = createToken(0.0, Substraction);
            return true;
        }
        else if (estado == Dividir)
        {
            *t = createToken(0.0, Division);
            return true;
        }
        else if (estado == Multiplicar)
        {
            *t = createToken(0.0, Multiplication);
            return true;
        }
        else if (estado == Error)
        {
            *t = createToken(0.0, LexError);
            return false;
        }
    }
    // Fin del stream
    *t = createToken(0.0, PopResult);
    return false;
}

Token createToken(double value, TokenType type)
{
    Token token;
    token.type = type;
    token.val = value;

    return token;
}