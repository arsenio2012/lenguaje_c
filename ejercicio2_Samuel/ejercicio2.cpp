/*
	Ejercicio 2: 
		Un Instituto encargado del suministro de agua potable, de una ciudad, ha
		registrado el consumo, en litros del preciado líquido, en los diversos municipios durante
		cada uno de los meses del año pasado. Las cantidades de litros son conocidas por el
		usuario, al igual que la población de cada uno de los municipios, pero se desconoce el
		número exacto de estos. Los datos se han organizado como se muestra a continuación
		(Ejemplo):

		Escriba un programa en lenguaje C a fin de:
			a) Solicitar al usuario: los nombres de los municipios, la correspondiente población y
			almacenar en vectores (paralelos) ( Usando el proceso de solicitar el numero
			exacto de municipios, validar y luego usar un ciclo automatico). Luego solicitar
			la cantidad de litros consumidos y al macenar en una matriz. El número del mes
			no es necesario almacenarlo ya que es un número entero, que se puede manejar
			con la variable control de un ciclo.
			
			b) Calcular el consumo percapita ( promedio general por persona) en el año. (Se
			debe calcular la cantidad total de litros consumidos en todos los municipios en
			el año y el total de la población, para luego calcular el promedio).

			c) Calcular y mostrar organizadamente la cantidad total de litros consumidos en cada
			municipio, durante el año. (Mostrar un encabezamiento y los valores respectivos
			del municipio y el consumorespectivo, en dos columnas)

			d) Permitir la consulta del consumo de un municipio, cuyo nombre sea suministrado
			por el usuario, para un mes del año, indicado por éste. (Por tratarse de una
			busqueda, ésta debe culminar si el nombre del municipio es encontrado, de lo
			contrario el usuario debe ser informmado de su ausencia en los datos
			almacenados)

	Autor: Samuel
*/

// Incluimos las librerias
#include <stdio.h>

// Definimos variables con valores que no cambiarán
#define meses_año 12
#define municipios 29
#define titulo "instituto del suministro de agua del tachira"


// Nuestra funcion principal
int main(){
	// Variables que vamos a usar
	int i = 0, j = 0, opcion, litros_consumidos, poblacion[municipios];
	bool poblacion_aceptada = false;
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

	char nombre_municipio[municipios][50]{
		"Andrés Bello",
		"Antonio Rómulo Costa",
		"Ayacucho",
		"Bolívar",
		"Cardenas",
		"Córdoba",
		"Fernández Feo",
		"Francisco de Miranda",
		"García de Hevia",
		"Guasímos",
		"Independencia",
		"Jáuregui",
		"José María Vargas",
		"Junin",
		"Libertad",
		"Libertador",
		"Lobatera",
		"Michelena",
		"Panamericano",
		"Pedro Maria Ureña",
		"Samuel Darío Maldonado",
		"San Cristóbal",
		"Seboruco",
		"Simón Rodríguez",
		"Sucre",
		"torbes",
		"Uribante"
	};


	// Le damos un mensaje de bienvenida al usuario 
	printf("Bienvenido al %s\n\n", titulo);

	// Le decimos que seleccione un municipio
	printf("Selecciona un minicipio: \n");

	for (i = 0; i < municipios; ++i)
	{
		printf("%d. %s\n", i+1, nombre_municipio[i]);
	}

	printf("Ingresa el número respectivo: ");
	scanf("%d", &opcion);

	// En caso que la eleccion no coincida con ninguna opcion le repetimos la pregunta
	while(opcion < 1 || opcion > municipios){
		printf("Opcion invalida. Seleccione un numero de la lista:");
		scanf("%d", &opcion);
	}

	// Definimos una variable en el cual nos diga la poblacion segun el municipio seleccionado
	//int poblacion_elegida = opcion-1;
	int municipio_elegido = opcion-1;

	// Condicicionamos para que en caso que ingresen una cantidad de habitantes de 0 le diga que debe ser mayor
	while(!poblacion_aceptada){
		printf("Ingrese la cantidad de habitantes del municipio %s: ", nombre_municipio[municipio_elegido]);
		scanf("%d", &poblacion[municipio_elegido]);

		if (poblacion[municipio_elegido] > 0)
		{
			poblacion_aceptada = true;
		}else{
			printf("\n La cantidad de habtitantes debe de ser mayor a 0..\n");
		}
	}

	// Definimos la variable consumo segun el municipio y meses del año
	int consumo[municipios][meses_año];

	// Le decimos que ingrese los litros segun el mes en el municipio seleccionado considerando la cantidad de habitantes que hay registrados segundo cada municipio
	for (i = 0; i < meses_año; ++i)
	{
		printf("\n Ingrese el consumo en litros del mes %s en el municipio %s considerando que tienen %d de habitantes: ", mes_cursante[i], nombre_municipio[municipio_elegido], poblacion[municipio_elegido]);
		scanf("%d", &consumo[municipio_elegido][i]);
	}


	// Y bueno mostramos la informacion 
	printf("|%15s| |%10s|\n", "Municipio", "Mes\n");
	for (i = 0; i < meses_año; ++i)
	{
		//printf("El consumo en el mes %s en el municipio %s fue de: %d litros \n", mes_cursante[i], nombre_municipio[municipio_elegido], consumo[municipio_elegido][i]);
		printf("|%15s| |%10d|\n", nombre_municipio[municipio_elegido], consumo[municipio_elegido][i]);
	}

	return 0;
}