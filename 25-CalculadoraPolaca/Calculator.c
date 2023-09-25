
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
                printf("[Error]: Denominador cero\n");
                return ERANGE;
            }
            break;
        }
    }

    if (token.type == LexError)
    {
        printf("[LexError] - Syntax Error: %s\n", token.lexeme);
        return EIO;
    }

    while (!IsEmpty())
    {
        StackItem item = Pop();
        printf("Resultado: %f\n", item);
    }

    return 0;
}