#include <stdio.h>
#include <stdlib.h>
#include "graficador.h"
#include "histograma.h"
#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 10
#endif

void withGoTo(FILE *stream)
{
	typedef enum
	{
		In,
		Out,
	} State;
	State s = Out;
	unsigned c, ncw = 0; // numero de caracteres de la palabra
	unsigned arrayLengths[MAX_WORD_LENGTH + 1] = {0};
	system("cls");
	printf("Longitud máxima de palabra: %d\n", MAX_WORD_LENGTH);
	printf("ingrese el texto a analizar (enter and Ctrl-Z and enter to exit):\n");
read:
	c = getc(stream);
	if (c == EOF)
		goto end;

	if (s == Out)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			s = Out;
			goto read;
		}
		else
		{
			s = In;
			ncw = 0;
			goto read;
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
			goto read;
		}
		else
		{
			s = In;
			ncw++;
			goto read;
		}
	}
end:
	printArray(arrayLengths, MAX_WORD_LENGTH);
	return;
}