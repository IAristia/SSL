#include <stdio.h>

void printArray(int a[], int maxWordLength) {
	for (int i = 0; i < maxWordLength + 1; i++) {
		printf("Cantidad de palabras de longitud %d%s: ", i + 1, maxWordLength + 1 == i ? " o más" : "");
		for (int j = 0; j < a[i]; j++) printf("*");
		printf("\n");
	}
	return;
}