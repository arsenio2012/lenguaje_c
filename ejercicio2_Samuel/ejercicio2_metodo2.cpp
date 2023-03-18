#include <stdio.h>

// Función para recopilar los datos de consumo para un municipio específico
int** recopilar_consumo(int municipio, int poblacion) {
    int i, j;
    int** consumo = malloc(municipio * sizeof(int*));
    for (i = 0; i < municipio; ++i) {
        consumo[i] = malloc(meses_año * sizeof(int));
        printf("\n Ingrese el consumo en litros del mes %s en el municipio %s considerando que tienen %d de habitantes: ", mes_cursante[i], nombre_municipio[municipio-1], poblacion);
        scanf("%d", &consumo[i][j]);
    }
    return consumo;
}

int main() {
    int opcion = 0;
    int poblacion_elegida = 0;
    int** consumo = NULL;
    
    while (opcion != -1) {
        printf("\n Seleccione el municipio (1-%d) para el cual desea ingresar datos de consumo (o ingrese -1 para salir): ", municipios);
        scanf("%d", &opcion);
        
        if (opcion >= 1 && opcion <= municipios) {
            printf("\n Ingrese la población del municipio %s: ", nombre_municipio[opcion-1]);
            scanf("%d", &poblacion_elegida);
            
            // Recopilar los datos de consumo para el municipio seleccionado
            consumo = recopilar_consumo(opcion, poblacion_elegida);
            
            // Imprimir los datos de consumo para el municipio seleccionado
            printf("\n Datos de consumo para el municipio %s:\n", nombre_municipio[opcion-1]);
            for (int i = 0; i < meses_año; i++) {
                printf("El consumo en el mes %s fue de: %d litros\n", mes_cursante[i], consumo[opcion-1][i]);
            }
        }
    }
    
    return 0;
}