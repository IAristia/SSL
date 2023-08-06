#include <stdio.h>
#include <stdlib.h>
#include "graficador.h"
#include "histograma.h"
#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 10
#endif

typedef enum
{
    In,
    Out,
} State;

void read(unsigned ncw, unsigned arrayLengths[MAX_WORD_LENGTH + 1], State s, FILE *stream)
{
    unsigned c = getc(stream);
    if (c == EOF)
    {
        printArray(arrayLengths, MAX_WORD_LENGTH);
        return;
    }

    if (s == Out)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            s = Out;
            read(ncw, arrayLengths, s, stream);
        }
        else
        {
            s = In;
            ncw = 0;
            read(ncw, arrayLengths, s, stream);
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
            read(ncw, arrayLengths, s, stream);
        }
        else
        {
            s = In;
            ncw++;
            read(ncw, arrayLengths, s, stream);
        }
    }

    return;
}

unsigned withRec(FILE *stream)
{
    system("cls");
    printf("Longitud máxima de palabra: %d\n", MAX_WORD_LENGTH);
    printf("ingrese el texto a analizar(enter and Ctrl-Z and enter to exit):\n");
    // getc(stream);
    State s = Out;
    unsigned ncw = 0;
    unsigned arrayLengths[MAX_WORD_LENGTH + 1] = {0};
    read(ncw, arrayLengths, s, stream);
    return 0;
}