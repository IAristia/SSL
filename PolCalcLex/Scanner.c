#include "Scanner.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum States
{
    Inicio,
    Sumar,
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
    // invocar la función yylex.
}