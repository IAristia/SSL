#include "histograma.h"

int main()
{
	printf("Longitud máxima de palabra: %d\n", MAX_WORD_LENGTH);
	FILE *stream = fopen("test.txt", "r");
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