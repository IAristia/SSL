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
	FILE* stream = fopen("test.txt", "r");
	printf("Enum switch:\n");
	withEnumSwitch(stream);
	rewind(stream);
	printf("Goto:\n");
	withGoTo(stream);
	rewind(stream);
	printf("Rec:\n");
	withRec(stream);
	rewind(stream);
	printf("X:\n");
	withX(stream);
	fclose(stream);
	return 0;
}