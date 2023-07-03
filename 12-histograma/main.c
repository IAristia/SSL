

#include <stdio.h>
#include <stdbool.h>

#include "histograma-1-enum-switch.c"
#include "histograma-2-goto.c"
#include "histograma-3-rec.c"
#include "histograma-x.c"


int main() {
	//loop
	bool exit = false;
	while (!exit){
		printf("Histograma de palabras\n");
		printf("opcion 1: con enum switch\n");
		printf("opcion 2: con goto\n");
		printf("opcion 3: con recursividad\n");
		printf("opcion 4: con Ifs o guardas\n");
		printf("opcion 5: salir\n");
		printf("\n\n\ningrese una opcion: ");
		//get option
		int option = 0;
		scanf("%d", &option);
		//clear screan
		system("cls");
		//switch option
		switch (option) {
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
			return 0;
		default:
			printf("opcion invalida\n");
			break;
		}
		system("cls");
	}
}