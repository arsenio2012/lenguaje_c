/* Programa: Primeros diez n�meros naturales (Soluci�n 3) */

#include <conio.h>
#include <stdio.h>

int main()
{
	int contador;

	printf( "\n   " );

	contador = 1; /* Inicializaci�n del contador */
	while ( contador <= 10 ) /* Condici�n */
	{
		printf( "%d ", contador ); /* Salida */
		contador++; /* Incremento del contador */
	}

	getch(); /* Pausa */

	return 0;
}
