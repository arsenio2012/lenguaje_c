// Usaremos las siguientes librerias
#include <stdio.h> 
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Definimos un maximo de areas
#define MAX_AREAS 50

// Nuestras variables para empezar
char calificaciones[MAX_AREAS][10];
int dB[MAX_AREAS];
float calor[MAX_AREAS];

// Funcion para asignar la calificacion correspondiente
void asignarCalificacion(int i) {
    if (dB[i] >= 120 && calor[i] > 42) {
        strcpy(calificaciones[i], "Alto");
    } else if (dB[i] >= 75 || (dB[i] < 120 && calor[i] >= 34) || calor[i] <= 42) {
        strcpy(calificaciones[i], "Tolerable");
    } else if (dB[i] < 75 && calor[i] < 34) {
        strcpy(calificaciones[i], "Bajo");
    }
}

//La funcion principal
int main() {
    // Variables a usar 
    char nombre_area[MAX_AREAS][20], opcion, riesgo[MAX_AREAS][20], buscar_area[20];
    int a = 0, i, k, testigo;

    printf("Bienvenido al departamento de seguridad de la carpinteria industrial Dufesmit\n");

    int num_areas;
    do {
        printf("Ingrese el número exacto de áreas (máximo %d): ", MAX_AREAS);
        scanf("%d", &num_areas);
        if (num_areas <= 0 || num_areas > MAX_AREAS) {
            printf("El número de áreas debe ser un valor entre 1 y %d\n", MAX_AREAS);
        }
    } while (num_areas <= 0 || num_areas > MAX_AREAS);

    // a) Cargamos los datos como nombre del area, ruido y calor  
    for (a = 0; a < num_areas; a++) {
        getchar(); // Para leer el salto de lineas
        printf("Ingrese el nombre del area No. %d: ", a + 1);
        fgets(nombre_area[a], 20, stdin);
        nombre_area[a][strlen(nombre_area[a]) - 1] = '\0'; // eliminamos el salto de línea

        printf("Indique el valor del ruido: ");
        scanf("%d", &dB[a]);

        printf("Indique la temperatura de calor en grados centigrados: ");
        scanf("%f", &calor[a]);

         asignarCalificacion(a);
    }

    // b) Creación del arreglo con la calificación de riesgo
    for (i = 0; i < num_areas; i++) {
        printf("\nÁrea: %s - Ruido: %d dB - Calor: %.2f °C - Riesgo: %s", nombre_area[i], dB[i], calor[i], calificaciones[i]);
    }


    // c) Búsqueda del área de interés y muestra de sus valores
    printf("\n\nIngrese el nombre del área a buscar: ");
    getchar();

    fgets(buscar_area, 20, stdin);
    buscar_area[strlen(buscar_area) -1] = '\0'; //Eliminamos el salto de linea

    testigo = 0;
    for (k = 0; k < num_areas; k++)
    {
        if (strcmp(buscar_area, nombre_area[k]) == 0)
        {
            printf("\n Area: %s - Ruido: %d dB - Calor: %.2f °C - Riesgo: %s\n", nombre_area[k], dB[k], calor[k], calificaciones[k]);
            testigo = 1;
            break;
        }else{
            printf("\n No se ha encontrado el area, por favor intente de nuevo");
            break;
        }
    }
}    