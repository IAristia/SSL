#include <stdio.h>
#include <stdlib.h>
#include "graficador.h"
#include "histograma.h"
#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 10
#endif

void withX(FILE *stream)
{
    typedef enum
    {
        In,
        Out,
    } State;
    unsigned c, ncw = 0;
    State s = Out;
    unsigned arrayLengths[MAX_WORD_LENGTH + 1] = {0};
    system("cls");
    printf("Longitud máxima de palabra: %d\n", MAX_WORD_LENGTH);
    printf("ingrese el texto a analizar (enter and Ctrl-Z and enter to exit):\n");
    while ((c = getc(stream)) != EOF)
    {
        if (s == Out)
        {
            if (c == ' ' || c == '\n' || c == '\t')
            {
                s = Out;
                continue;
            }
            else
            {
                s = In;
                ncw = 0;
                continue;
            }
        }
        else if (s == In)
        {
            if (c == ' ' || c == '\n' || c == '\t')
            {
                if (ncw > MAX_WORD_LENGTH)
                    arrayLengths[MAX_WORD_LENGTH]++;
                else
                    arrayLengths[ncw]++;
                ncw = 0;
                s = Out;
                continue;
            }
            else
            {
                s = In;
                ncw++;
                continue;
            }
        }
    }
    printArray(arrayLengths, MAX_WORD_LENGTH);
    return;
}