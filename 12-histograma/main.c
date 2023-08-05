

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "histograma-1-enum-switch.c"
#include "histograma-2-goto.c"
#include "histograma-3-rec.c"
#include "histograma-x.c"

int main(void)
{
	// loop
	bool exit = false;
	while (!exit)
	{
		printf("Histograma de palabras\n");
		printf("Opción 1: con enum switch\n");
		printf("Opción 2: con goto\n");
		printf("Opción 3: con recursividad\n");
		printf("Opción 4: con Ifs o guardas\n");
		printf("Opción 5: salir\n");
		printf("\n\n\nIngrese una opción: ");
		// get option
		unsigned option = 0;
		scanf("%d", &option);
		// clear screan
		system("cls");
		// switch option
		switch (option)
		{
		case 1:
			withEnumSwitch(stdin);
			system("pause");
			break;
		case 2:
			withGoTo(stdin);
			system("pause");
			break;
		case 3:
			withRec(stdin);
			system("pause");
			break;
		case 4:
			withX(stdin);
			system("pause");
			break;
		case 5:
			exit = true;
			break;
		default:
			printf("Opción inválida\n");
			system("pause");
			break;
		}
		system("cls");
	}
}