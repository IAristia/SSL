#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 10
#endif

#include <stdio.h>
#include "histograma-1-enum-switch.c"
#include "histograma-2-goto.c"
#include "histograma-3-rec.c"
#include "histograma-x.c"

int main() {
	printf("Longitud máxima de palabra: %d\n", MAX_WORD_LENGTH);
	// Descomentar la implementación a utilizar
	withEnumSwitch(stdin);
	//withGoTo(stdin);
	//withRec(stdin);
	//withX(stdin);
	return 0;
}