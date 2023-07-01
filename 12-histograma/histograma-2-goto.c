#include <stdio.h>
#include "graficador.h"
#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 10
#endif

void withGoTo(FILE* stream) {
    int c, len = 0;
    int arrayLengths[MAX_WORD_LENGTH + 1] = {0};
	read:
    c = getc(stream);
	if (c == EOF) goto end;
	if (c == ' ' || c == '\n' || c == '\t') {
		arrayLengths[len >= MAX_WORD_LENGTH ? MAX_WORD_LENGTH : len - 1]++;
		len = 0;
		if (c == '\n') goto show;
	} else len++;
	goto read;
	show:
	printArray(arrayLengths, MAX_WORD_LENGTH);
	goto read;
	end:
	printArray(arrayLengths, MAX_WORD_LENGTH);
}