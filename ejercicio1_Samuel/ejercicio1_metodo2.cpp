#include <stdio.h> 
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AREAS 5

char nombres_areas[MAX_AREAS][20];
int dB[MAX_AREAS];
float temperaturas[MAX_AREAS];
char calificaciones[MAX_AREAS][10];

void asignarCalificacion(int i) {
    if (dB[i] >= 120 && temperaturas[i] > 42) {
        strcpy(calificaciones[i], "Alto");
    } else if (dB[i] >= 75 || (dB[i] < 120 && temperaturas[i] >= 34) || temperaturas[i] <= 42) {
        strcpy(calificaciones[i], "Tolerable");
    } else if (dB[i] < 75 && temperaturas[i] < 34) {
        strcpy(calificaciones[i], "Bajo");
    }
}

int main() {
    int num_areas, i, encontrado = 0;
    char opcion;
    char area_buscada[20];

    printf("Bienvenido al departamento de seguridad de la carpinteria industrial dufesmit\n");
    printf("\nIngrese el número de áreas a registrar: ");
    scanf("%d", &num_areas);

    while (num_areas > MAX_AREAS) {
        printf("El número máximo de áreas es %d. Por favor, ingrese un número válido: ", MAX_AREAS);
        scanf("%d", &num_areas);
    }

    for (i = 0; i < num_areas; i++) {
        printf("\nIngrese el nombre del área %d: ", i + 1);
        scanf("%s", nombres_areas[i]);
        printf("\nIndique el valor del ruido: ");
        scanf("%d", &dB[i]);
        printf("\nIndique la temperatura de calor en grados centígrados: ");
        scanf("%f", &temperaturas[i]);
        asignarCalificacion(i);
    }

    // b) Creación del arreglo con la calificación de riesgo
    for (i = 0; i < num_areas; i++) {
        printf("\nÁrea: %s - Ruido: %d dB - Calor: %.2f °C - Riesgo: %s", nombres_areas[i], dB[i], temperaturas[i], calificaciones[i]);
    }

    // c) Búsqueda del área de interés y muestra de sus valores
        printf("\n\nIngrese el nombre del área a buscar: ");
