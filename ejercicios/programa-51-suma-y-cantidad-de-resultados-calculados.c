/* Programa: Suma y cantidad de resultados calculados */

#include <conio.h>
#include <stdio.h>

int main()
{
	char seguir;
	int acumulador, contador, numero, resultado;

	acumulador = 0;
	contador = 0;
	do
	{
		printf( "\n   Introduzca un n%cmero entero: ", 163 );
		scanf( "%d", &numero);

		resultado = numero * numero - numero;
		printf( "\n   %d * %d - %d = %d", numero, numero, numero, resultado );

		acumulador += resultado;
		contador++;

		printf( "\n\n   %cDesea introducir otro n%cmero (s/n)?: ", 168, 163 );
		fflush( stdin );
		scanf( "%c", &seguir);
	} while ( seguir != 'n' );

	printf( "\n   Ha introducido %d n%cmero(s).", contador, 163 );
	printf( "\n\n   La suma de los resultados es: %d", acumulador );

	getch(); /* Pausa */

	return 0;
}
