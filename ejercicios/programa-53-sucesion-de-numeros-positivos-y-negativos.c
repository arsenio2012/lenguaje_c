/* Programa: Sucesi�n de n�meros positivos y negativos */

#include <conio.h>
#include <stdio.h>

int main()
{
	int numero;

	printf( "\n   " );

	for ( numero = 1 ; numero <= 5 ; numero++ )
	{
		printf( "%d %d ", numero, -numero );
	}

	getch(); /* Pausa */

	return 0;
}
