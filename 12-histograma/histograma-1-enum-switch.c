#include <stdio.h>

void printArray(int a[])
{
    for (int i = 0; i < 11; i++)
    {
        printf("Cantidad de palabras de longitud %d:", i + 1);
        for (int j = 0; j < a[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main(void)
{
    typedef enum
    {
        In,
        Out,
    } State;

    // Initial state
    int c, ncw; // ncw = numero de caracteres de la palabra
    int arrayLengths[11] = {0};
    State s = Out;
    ncw = 0;
    while ((c = getchar()) != EOF)
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
                if (ncw > 10)
                    arrayLengths[10]++;
                else
                    arrayLengths[ncw]++;
                break;
            case '\n':
                s = Out;
                if (ncw > 10)
                    arrayLengths[10]++;
                else
                    arrayLengths[ncw]++;
                printArray(arrayLengths);
                break;
            default:
                ncw++;
                break;
            }
            break;
        }
    }
}