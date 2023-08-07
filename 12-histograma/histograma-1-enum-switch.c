#include "histograma.h"

unsigned withEnumSwitch(FILE *stream)
{
    // Initial state
    int c, ncw = 0; // ncw = numero de caracteres de la palabra
    unsigned arrayLengths[MAX_WORD_LENGTH + 1] = {0};
    State s = Out;
    printf("--------------------\n");
    printf("Longitud máxima de palabra: %d\n", MAX_WORD_LENGTH);
    printf("ingrese el texto a analizar (enter and Ctrl-Z and enter to exit):\n");
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
            case '\n':
                s = Out;
                if (ncw > MAX_WORD_LENGTH)
                    arrayLengths[MAX_WORD_LENGTH]++;
                else
                    arrayLengths[ncw]++;
                break;
            default:
                ncw++;
                break;
            }
            break;
        }
    }
    printArray(arrayLengths, MAX_WORD_LENGTH);
    return 0;
}
