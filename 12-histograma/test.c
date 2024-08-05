#include "histograma.h"

int main()
{
	printf("Longitud máxima de palabra: %d\n", MAX_WORD_LENGTH);
	FILE *stream = fopen("test.txt", "r");
	printf("\n--------------------\nEnum switch:\n");
	withEnumSwitch(stream);
	rewind(stream);
	printf("\n--------------------\nGoto:\n");
	withGoTo(stream);
	rewind(stream);
	printf("\n--------------------\nRec:\n");
	withRec(stream);
	rewind(stream);
	printf("\n--------------------\nX:\n");
	withX(stream);
	fclose(stream);
	return 0;
}