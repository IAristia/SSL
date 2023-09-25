#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h>

enum TokenType
{
    Number,
    Addition = '+',
    Multiplication = '*',
    Substraction = '-',
    Division = '/',
    PopResult = '\n',
    LexError
};

enum States
{
    Inicio,
    Sumar,
    Restar,
    Dividir,
    Multiplicar,
    Resultado,
    CaracterMenos,
    LiteralPositivo,
    LiteralPositivoFlotante,
    LiteralPositivoFinal,
    LiteralNegativo,
    LiteralNegativoFlotante,
    LiteralNegativoFinal,
    Error
};

typedef enum TokenType TokenType;

typedef double TokenValue;

typedef struct
{
    TokenType type;
    TokenValue val;
} Token;

bool GetNextToken(
    Token *t /*out*/); // Retorna si pudo leer, almacena en t el token leido
Token createToken(double value, TokenType type);

bool cumpleRestriccion (char);

#endif /* SCANNER_H*/