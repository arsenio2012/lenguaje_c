/* Programa: �rea de una circunferencia (Soluci�n 3) */

#include <conio.h>
#include <math.h>
#include <stdio.h>

#define PI 3.141592

int main()
{
	float radio;

	printf( "\n   Introduzca radio: " );

	scanf( "%f", &radio );

	printf( "\n   El %crea de la circunferencia es: %.2f", 160, PI * pow( radio, 2 ) );

	printf( "\n\n   Pulse una tecla para salir..." );

	getch(); /* Pausa */

	return 0;
}
