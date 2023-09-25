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
                }
                else if (isdigit(c))
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
                else if (c == '+')
                {
                    estado = Sumar;
                }
                else if (c == '/')
                {
                    estado = Dividir;
                }
                else if (c == '*')
                {
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
                    estado = LiteralNegativoFlotante;
                    lexeme[contador] = c;
                    contador++;
                }
                 else // leo un espaciador u operando
                {
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
                    estado = LexError;
                }
                else // c = espaciador u operando
                {
                    estado = LiteralNegativoFinal;
                }
            
            }
            else if (estado == LiteralNegativoFinal)
            {
                ungetc(c,stdin);
                estado = Inicio;
                double numeroDouble = atof(lexeme);
                *t = createToken(numeroDouble, Number);
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
                    estado = LexError;
                }
                else 
                {
                    estado = LiteralPositivoFinal;    
                }
            }
            else if (estado == LiteralPositivoFinal)
            {
                ungetc(c, stdin);
                estado = Inicio;
                double numeroDouble = atof(lexeme);
                *t = createToken(numeroDouble, Number);
                return true;
            }
            else if (estado == Sumar)
            {
                ungetc(c, stdin);
                estado = Inicio;
                *t = createToken(0.0, Addition);
                return true;
            }
            else if (estado == Restar)
            {
                ungetc(c, stdin);
                estado = Inicio;
                *t = createToken(0.0, Substraction);
                return true;
            }
            else if (estado == Dividir)
            {
                ungetc(c, stdin);
                estado = Inicio;
                *t = createToken(0.0, Division);
                return true;
            }
            else if (estado == Multiplicar)
            {
                ungetc(c, stdin);
                estado = Inicio;
                *t = createToken(0.0, Multiplication);
                return true;
            }
            else if (estado == Error)
            {
                ungetc(c, stdin);
                estado = Inicio;
                *t = createToken(0.0, LexError);
                return false;
            }
        }
        else
        {
            estado = Error;
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

bool cumpleRestriccion (char c) {
    return isdigit(c) || c == '+' || c == '-' || c == '/' || c == '*' || c == ' ';
}
