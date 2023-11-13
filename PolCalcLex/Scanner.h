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
    WhiteSpace = ' ',
    NoMoreTokens,
    LexError
};

typedef enum TokenType TokenType;

typedef double TokenValue;

typedef struct
{
    TokenType type;
    TokenValue val;
    char lexeme[10];
} Token;

bool GetNextToken(
    Token *t /*out*/); // Retorna si pudo leer, almacena en t el token leido
Token createToken(double value, TokenType type, char lexemeError[]);
bool cumpleRestriccion(char);

#endif /* SCANNER_H*/
