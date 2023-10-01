
#include <stdio.h>
#include <errno.h>

#include "Scanner.h"
#include "StackOfDoublesModule.h"

int compare_count(int countNumber, int countOperador)
{
    if (countNumber > countOperador + 1)
    {
        printf("[LexError] - Faltan operadores\n");
        return EIO;
    }
    if (countNumber < countOperador + 1)
    {
        printf("[LexError] - Faltan operandos\n");
        return EIO;
    }
}

int main()
{
    Token token;
    double aux;

    int countNumber = 0;
    int countOperador = 0;

    while (GetNextToken(&token))
    {
        switch (token.type)
        {
        case Number:
            Push(token.val);
            countNumber++;
            break;
        case Addition:
            Push(Pop() + Pop());
            countOperador++;
            break;
        case Multiplication:
            Push(Pop() * Pop());
            countOperador++;
            break;
        case Substraction:
            aux = Pop();
            Push(Pop() - aux);
            countOperador++;
            break;
        case Division:
            aux = Pop();
            if (aux != 0.0)
            {
                Push(Pop() / aux);
                countOperador++;
            }
            else
            {
                // Rompe el programa
                printf("[Error]: Denominador cero\n");
                return ERANGE;
            }
            break;
        case PopResult:
            if (countNumber > 0 && countOperador > 0)
            {
                if (countNumber > countOperador + 1)
                {
                    printf("[LexError] - Faltan operadores\n");
                    return EIO;
                }
                if (countNumber < countOperador + 1)
                {
                    printf("[LexError] - Faltan operandos\n");
                    return EIO;
                }
                countNumber = 0;
                countOperador = 0;
            }
            break;
        }
    }

    if (token.type == LexError)
    {
        printf("[LexError] - Syntax Error: %s\n", token.lexeme);
        return EIO;
    }

    if (countNumber != 0 && countOperador != 0)
    {
        if (countNumber > countOperador + 1)
        {
            printf("[LexError] - Faltan operadores\n");
            return EIO;
        }
        if (countNumber < countOperador + 1)
        {
            printf("[LexError] - Faltan operandos\n");
            return EIO;
        }
    }

    while (!IsEmpty())
    {
        StackItem item = Pop();
        printf("Resultado: %f\n", item);
    }

    return 0;
}