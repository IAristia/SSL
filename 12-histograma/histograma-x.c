#include <stdio.h>
#include "graficador.h"
#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 10
#endif

void withX(FILE* stream) {
    int c, len = 0;
    int arrayLengths[MAX_WORD_LENGTH + 1] = {0};
    while ((c = getc(stream)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
			if (len < 1) continue;
			arrayLengths[len >= MAX_WORD_LENGTH ? MAX_WORD_LENGTH : len - 1]++;
            len = 0;
            if (c == '\n') printArray(arrayLengths, MAX_WORD_LENGTH);
        } else len++;
    }
    printArray(arrayLengths, MAX_WORD_LENGTH);
}