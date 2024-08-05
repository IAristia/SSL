#include "graficador.h"

void printArray(unsigned a[], unsigned maxWordLength)
{
	for (unsigned i = 0; i < maxWordLength + 1; i++)
	{
		printf(i + 1 <= 10 ? "%d:" : "%d+:", i + 1 <= 10 ? i + 1 : maxWordLength); // aca decido si imprimir número del 1 al 10 o 10+
		for (unsigned j = 0; j < a[i]; j++)
			printf("*");
		printf("\n");
	}
	return;
}
