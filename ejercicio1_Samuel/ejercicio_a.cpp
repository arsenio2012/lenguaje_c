/*
	Ejercicio 1: 
*/

// Librerias
#include <stdio.h> 
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Definimos el numero de areas maximas 
#define max_areas 5

// Nuestras variables
char nombre_area[max_areas][20], opcion, riesgo[max_areas][20], buscar_area[max_areas][20];
int dB[max_areas], a = 0, i, k, kb, testigo;
float calor[max_areas], h;

// Funcion principal
int main(){
	printf("Bienvenido al departamento de seguridad de la carpinteria industrial dufesmit");

	// a) Cargamos los datos como nombre del area, ruido y calor  
	do{
		printf("\n Ingrese el nombre del area No. %d: ", a + 1);
		gets(nombre_area[a]);

		printf("\n Indique el valor del ruido: ");
		scanf("%d", &dB[a]);

		printf("\n Indique la temperatura de calor en grados centigrados: ");
		scanf("%f", &calor[a]);

		a++;

		printf("\n ¿Ingresar otra area? s/n");
		fflush(stdin);
		scanf("%c", &opcion);

	} while (tolower(opcion) == 's' && a < max_areas);

	// b) la calificacion de riesgo (A: Alto, T; Tolerable, B; Bajo);
	for (k = 0; k < a; ++k){
		if(dB[k] >= 120 && calor[k] > 42){
			printf("\n Alto");
		}else if(dB[k] >= 75 || dB[k] < 120 && calor[k] >= 34 || calor[k] <= 42  ){
			printf("\n Tolerable");
		}else if(dB[k] < 75 && calor[k] < 34){
			printf("\n Bajo");
		}
	}

	// c) Mostramos el ruido y el calor para un area buscado por el usuario
	testigo = 0;
	kb = 0;
	do{
		printf("\n ¿Ingrese algun area para ver los datos cargados: ");
		scanf("%c", &buscar_area[kb]);
		h = strcmp(nombre_area[kb], buscar_area[kb]);
		if(h==0){
			testigo = 1;
			printf("\n\t en el puesto de %c el calor fue de %3f °C y el ruido de %d",buscar_area[kb], calor[kb], dB[kb]);
		}
		kb++;
	} while (kb<a && testigo == 0);

	if(testigo != 1)
		printf("\n\t El area %c del departamento no fue registrado", buscar_area[k]);

	system("pause");

	return (0);
}