/*
	Autor: Samuel
*/

// Incluimos las librerias
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Definimos variables con valores que no cambiarán
#define meses_año 12
#define max_municipios 29
#define titulo "instituto del suministro de agua del tachira"

// funcion para limpiar el buffer y así evitar saltos de lineas 
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcion para consultar municipios
void consultar_consumo(char nombre_municipio[][50], int consumo[][max_municipios], char mes_cursante[][25]){
	char municipio[50], mes[25];
	int mes_index, municipio_index, litros_consumidos;
	bool encontrado = false;

	// Pedimos el nombre del municipio 
	printf("\nIngrese el nombre del municipio: ");
	clear_input_buffer();
	scanf("%[^\n]", municipio);

	// y el mes
	printf("\nIngrese el mes (nombre completo): ");
	clear_input_buffer();
	scanf("%[^\n]", mes);	

	// Buscamos el inidice del mes
	for (int i = 0; i < meses_año; ++i){
		if(strcmp(mes, mes_cursante[i]) == 0){
			mes_index = i;
			break; // Salimos del ciclo
		}
	}

	// Buscamos el indice del municipio
	for (int i = 0; i < max_municipios; ++i){
		if(strcmp(nombre_municipio[i], municipio) == 0){
			municipio_index = i;
			encontrado = true;
			break; // Salimos del ciclo
		}
	}

	// Validamos en caso de que encontrado sea verdadero
	if(encontrado){
		// Mostramos el consumo del municipio para el mes seleccionado
		litros_consumidos = consumo[mes_index][municipio_index];
		printf("\n\nEl municipio %s consumió %d litros durante el mes de %s.\n", municipio, litros_consumidos, mes);
	}else{
		printf("\n\nEl municipio no se encuentra en los datos almacenados");	
	}
}

// Nuestra funcion principal
int main(){
	// Variables que vamos a usar
	int i, j, opcion, litros_consumidos, poblacion[max_municipios], municipios, consumo[meses_año][max_municipios];
	float consumo_promedio_m[max_municipios];
	char mes_cursante[meses_año][25] = {
		"Enero",
		"Febrero",
		"Marzo",
		"Abril", 
		"Mayo",
		"Junio",
		"Julio",
		"Agosto",
		"Septiembre",
		"Octubre",
		"Noviembre",
		"Diciembre"
	};

	char nombre_municipio[max_municipios][50];


	// Le damos un mensaje de bienvenida al usuario 
	printf("Bienvenido al %s\n\n", titulo);

	printf("¿Cuandos municipios vas a ingresar?: ");
	scanf("%d", &municipios);

	// En caso que la eleccion no coincida con ninguna opcion le repetimos la pregunta
	while(municipios < 1 || municipios > max_municipios){
		printf("Debe ser una cantidad arriba de 0 que no supere de 29 municipios: \n");
		scanf("%d", &municipios);
	}

	// Empezamos a ingresar el nombre de los municipios
	for (i = 0; i < municipios; ++i)
	{
		printf("\n Ingrese el  nombre del municipio #%d: ", i+1);
		clear_input_buffer(); // Llamamos la funcion para evitar saltos de linea
		scanf("%[^\n]", nombre_municipio[i]);
	}

	// Ingresammos la cantidad de habitantes por municipio
	for (i = 0; i < municipios; ++i)
	{
		printf("\n Ingresa la cantidad de habtitantes del municipio %s: ", nombre_municipio[i]);
		scanf("%d", &poblacion[i]);
	}

	// Ingresamos el consumo de litros de agua por municipio
	for (i= 0; i < meses_año; ++i)
	{
		for (j = 0; j < municipios; ++j)
		{
			printf("\nIngrese la cantidad de litros consumidos en el municipio %s durante el mes de %s: ", nombre_municipio[j], mes_cursante[i]);
			scanf("%d", &consumo[i][j]);
		}
	}

	// Calculamos el consumo promedio por municipio al año
	for (i=0; i < municipios; i++){
		int litros_totales = 0;
		for (j =0; j < meses_año; j++){
			litros_totales += consumo[j][i];
		}	
		consumo_promedio_m[i] = (float) litros_totales / meses_año;
	} 

	// Calculamos la cantidad total de litros consumidos en el año
	int litros_totales = 0;
	for (i = 0; i < meses_año; ++i){
		for (j = 0; j < municipios; ++j){
			litros_totales += consumo[i][j];
		}
	}

	// Calculamos la cantidad total de habitantes 
	int habitantes_totales = 0;
	for(i = 0; i < municipios; i++){
		habitantes_totales += poblacion[i];
	}

	// Calculamos el consumo promedio por persona al año
	float consumo_promedio_p = (float) litros_totales / habitantes_totales;

	// Le preguntamos al usuario lo que quiere consultar:

	// Ejecutamos la funcion de consultar el consumo
	do {
		printf("\n\n MENU: \n");
		printf("1. consultar el consumo promedio de los municipios al año\n");
		printf("2. Consultar el consumo promedio al año por persona\n");
		printf("3. Consultar el consumo promedio por municipio al año\n");
		printf("4. Salir del ejercicio\n");

		printf("Ingrese su opcion: ");
		scanf("%d", &opcion);

		switch(opcion){
			case 1:
				
				printf("\n\n MENU de municipios cargados: \n");
				for (int i = 0; i < municipios; ++i)
				{
					printf("%d: %s\n", i+1, nombre_municipio[i]);
				}
				printf("Elije el municipio para ver su promedio de consumo al año (0 para salir): ");
				int opcion_municipio;
				scanf("%d", &opcion_municipio);

				printf("El promedio de consumo del municipio %s es de: %f al año", nombre_municipio[opcion_municipio-1], consumo_promedio_m[opcion_municipio-1]);
			break;
			case 2:
				printf("El promedio de consumo por personas es de: %f al año", consumo_promedio_p);
			break;	
			case 3:
				consultar_consumo(nombre_municipio, consumo, mes_cursante);
			break;	
			case 4: 
				printf("Saliendo del programa..");
				opcion = 0;
			break;

			default:
				printf("Opcion invalida,. Intente de nuevo");
			break;
		}
	}while(opcion != 0);
	
	return 0;
}