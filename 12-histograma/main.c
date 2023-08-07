#include "histograma.h"
// #include "graficador.h"

int main()
{
	bool exit = false;
	while (!exit)
	{
		printf("Histograma de Palabras\n");
		printf("Opción 1: Con enum switch\n");
		printf("Opción 2: Con goto\n");
		printf("Opción 3: Con recursividad\n");
		printf("Opción 4: Con continue\n");
		printf("Opción 5: Salir\n");
		printf("\n\n\nIngrese una opción: ");
		// get option
		unsigned option = 0;
		scanf("%d", &option);
		printf("--------------------\n");
		// switch option
		switch (option)
		{
		case 1:
			withEnumSwitch(stdin);
			break;
		case 2:
			withGoTo(stdin);
			break;
		case 3:
			withRec(stdin);
			break;
		case 4:
			withX(stdin);
			break;
		case 5:
			exit = true;
			break;
		default:
			printf("Opción inválida\n");
			break;
		}
		printf("\n--------------------\n");
	}
	return 0;
}
