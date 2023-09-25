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

        printf("VALOR DEL CHAR: %c\n", c);
        printf("ESTADO AL RRANCAR EL WHILE %d \n", estado);

        // if (!isdigit(c) || c != '+' || c != '-' || c != '/' || c != '*' || c != ' ')
        // {
        //     estado == Error;
        // }
        // else
        if (estado == Inicio)
        {
            if (c == ' ' || c == '\n' || c == '\t')
            {
                estado = Inicio;
            }
            else if (c == '-')
            {
                if ((c = getchar()) == EOF)
                {
                    estado = Inicio;
                    *t = createToken(0.0, Substraction);
                    return true;
                }
                else
                {
                    estado = CaracterMenos;
                    lexeme[contador] = c;
                    contador++;
                }
            }
            else if (isdigit(c) || c == '.')
            {
                estado = LiteralPositivo;
                lexeme[contador] = c;
                contador++;
            }
            else if (c == '+')
            {
                estado = Sumar;
                ungetc(c, stdin);
            }
            else if (c == '/')
            {
                estado = Dividir;
                ungetc(c, stdin);
            }
            else if (c == '*')
            {
                estado = Multiplicar;
                ungetc(c, stdin);
            }
            else // Si no es operando y no es operador
            {
                estado = Error;
            }
        }
        else if (estado == CaracterMenos)
        {
            if (!isdigit(c))
            {
                estado = Inicio;
                *t = createToken(0.0, Substraction);
                ungetc(c, stdin);
                return true;
            }
            else
            {
                estado = LiteralNegativo;
            }
        }
        else if (estado == LiteralNegativo)
        {
            if (!isdigit(c) && c != '.')
            {
                estado = LiteralNegativoFinal;
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
            double numeroDouble = atof(lexeme);
            *t = createToken(numeroDouble, Number);
            return true;
        }
        else if (estado == LiteralPositivo)
        {
            if (!isdigit(c) && c != '.')
            {
                printf("INGRESE UN NO DIGITO\n");
                estado = LiteralPositivoFinal;
                ungetc(c, stdin);
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
            estado = Inicio;
            ungetc(c, stdin);
            *t = createToken(0.0, Addition);

            return true;
        }
        else if (estado == Restar)
        {
            estado = Inicio;
            *t = createToken(0.0, Substraction);
            return true;
        }
        else if (estado == Dividir)
        {
            estado = Inicio;
            *t = createToken(0.0, Division);
            return true;
        }
        else if (estado == Multiplicar)
        {
            estado = Inicio;
            *t = createToken(0.0, Multiplication);
            return true;
        }
        else if (estado == Error)
        {
            estado = Inicio;
            *t = createToken(0.0, LexError);
            return false;
        }

        printf("ESTADO: %i\n", estado);
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