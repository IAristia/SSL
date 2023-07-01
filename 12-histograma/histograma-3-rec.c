#include <stdio.h>
#include "graficador.h"
#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 10
#endif

void read(int len, int arrayLengths[MAX_WORD_LENGTH + 1], FILE* stream) {
    int c = getc(stream);
    if (c == EOF) {
        printArray(arrayLengths, MAX_WORD_LENGTH);
        return;
    }
    if (c == ' ' || c == '\n' || c == '\t') {
        arrayLengths[len >= MAX_WORD_LENGTH ? MAX_WORD_LENGTH : len - 1]++;
        len = 0;
        if (c == '\n') printArray(arrayLengths, MAX_WORD_LENGTH);
    } else len++;
    read(len, arrayLengths, stream);
}

int withRec(FILE* stream) {
    int arrayLengths[MAX_WORD_LENGTH + 1] = {0};
    read(0, arrayLengths, stream);
    return 0;
}