#include <stdio.h>

void printArray(unsigned a[], unsigned maxWordLength)
{
	for (unsigned i = 0; i < maxWordLength + 1; i++)
	{
		printf("Cantidad de palabras de longitud %d%s: ", i + 1, maxWordLength + 1 == i ? " o más" : "");
		for (unsigned j = 0; j < a[i]; j++)
			printf("*");
		printf("\n");
	}
	return;
}