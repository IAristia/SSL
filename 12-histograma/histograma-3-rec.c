#ifndef HISTOGRAMA_3
#define HISTOGRAMA_3
#include <stdio.h>
#include <stdlib.h>
#include "graficador.h"
#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 10
#endif

void read(unsigned len, unsigned arrayLengths[MAX_WORD_LENGTH + 1], FILE *stream)
{
    unsigned c = getc(stream);
    if (c == EOF)
    {
        printArray(arrayLengths, MAX_WORD_LENGTH);
        return;
    }
    if (c == ' ' || c == '\n' || c == '\t')
    {
        arrayLengths[len >= MAX_WORD_LENGTH ? MAX_WORD_LENGTH : len - 1]++;
        len = 0;
    }
    else
        len++;
    read(len, arrayLengths, stream);
    return;
}

unsigned withRec(FILE *stream)
{
    system("cls");
    printf("Longitud máxima de palabra: %d\n", MAX_WORD_LENGTH);
    printf("ingrese el texto a analizar(enter and Ctrl-Z and enter to exit):\n");
    getc(stream);
    unsigned arrayLengths[MAX_WORD_LENGTH + 1] = {0};
    read(0, arrayLengths, stream);
    return 0;
}
#endif