#include <stdio.h>
#include <errno.h>
#include "Scanner.h"
#include "StackOfDoublesModule.h"

int main()
{
    Token token;
    double aux;

    while (GetNextToken(&token))
    {
        printf("Tipo de token: %i\n", token.type);
        switch (token.type)
        {
        case Number:
            Push(token.val);
            break;
        case Addition:
            Push(Pop() + Pop());
            break;
        case Multiplication:
            Push(Pop() * Pop());
            break;
        case Substraction:
            aux = Pop();
            Push(Pop() - aux);
            break;
        case Division:
            aux = Pop();
            if (aux != 0.0)
            {
                Push(Pop() / aux);
            }
            else
            {
                // Rompe el programa
                printf("[Error]: divisor cero\n");
                return ERANGE;
            }
            break;
        }
    }

    if (token.type == LexError)
    {
        printf("[LexError] - Valor %f\n", token.val);
        return EIO;
    }

    while (!IsEmpty())
    {
        StackItem item = Pop();
        printf("Resultado: %f\n", item);
    }

    return 0;
}