#ifndef HISTOGRAMA_X
#define HISTOGRAMA_X
#include <stdio.h>
#include <stdlib.h>
#include "graficador.h"
#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 10
#endif

void withX(FILE *stream)
{
    unsigned c, len = 0;
    unsigned arrayLengths[MAX_WORD_LENGTH + 1] = {0};
    system("cls");
    printf("Longitud máxima de palabra: %d\n", MAX_WORD_LENGTH);
    printf("ingrese el texto a analizar (enter and Ctrl-Z and enter to exit):\n");
    while ((c = getc(stream)) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (len < 1)
                continue;
            arrayLengths[len >= MAX_WORD_LENGTH ? MAX_WORD_LENGTH : len - 1]++;
            len = 0;
        }
        else
            len++;
    }
    printArray(arrayLengths, MAX_WORD_LENGTH);
    return;
}
#endif