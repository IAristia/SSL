#include <stdio.h>
#include "graficador.h"
#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 10
#endif

void withGoTo(FILE *stream)
{
	unsigned c, len = 0;
	unsigned arrayLengths[MAX_WORD_LENGTH + 1] = {0};
	system("cls");
	printf("Longitud máxima de palabra: %d\n", MAX_WORD_LENGTH);
	printf("ingrese el texto a analizar (enter and Ctrl-Z and enter to exit):\n");
read:
	c = getc(stream);
	if (c == EOF)
		goto end;
	if (c == ' ' || c == '\n' || c == '\t')
	{
		arrayLengths[len >= MAX_WORD_LENGTH ? MAX_WORD_LENGTH : len - 1]++;
		len = 0;
	}
	else
		len++;
	goto read;
end:
	printArray(arrayLengths, MAX_WORD_LENGTH);
	return;
}