#include <stdio.h>
#include "graficador.h"
#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 10
#endif

int withEnumSwitch(FILE* stream)
{
    typedef enum
    {
        In,
        Out,
    } State;

    // Initial state
    int c, ncw; // ncw = numero de caracteres de la palabra
    int arrayLengths[MAX_WORD_LENGTH + 1] = {0};
    State s = Out;
    ncw = 0;
    while ((c = getc(stream)) != EOF)
    {

        switch (s)
        {
        case Out:
            switch (c)
            {
            case ' ':
            case '\n':
            case '\t':
                s = Out;
                break;
            default:
                s = In;
                ncw = 0;
                break;
            }
            break;
        case In:
            switch (c)
            {
            case ' ':
            case '\t':
                s = Out;
                if (ncw > MAX_WORD_LENGTH)
                    arrayLengths[MAX_WORD_LENGTH]++;
                else
                    arrayLengths[ncw]++;
                break;
            case '\n':
                s = Out;
                if (ncw > MAX_WORD_LENGTH)
                    arrayLengths[MAX_WORD_LENGTH]++;
                else
                    arrayLengths[ncw]++;
                printArray(arrayLengths, MAX_WORD_LENGTH);
                break;
            default:
                ncw++;
                break;
            }
            break;
        }
    }
    printArray(arrayLengths, MAX_WORD_LENGTH);
}