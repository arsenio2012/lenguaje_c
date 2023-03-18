#include <stdio.h>



int main(){
	char opcion;

	printf("Seleccione una opcion: \n");
	printf("Gc. Saludo: \n");
	printf("HL. Despedida: \n");

	scanf("%s", &opcion);

	switch(opcion){
		case 'c': //Gc
			printf("Hola como estás");
		break;

		case 'f': // Gf
			printf("chau");
		break;
	}
	//getch();
}