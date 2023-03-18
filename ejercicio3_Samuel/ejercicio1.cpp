#include <stdio.h>
#include <math.h>

// variable con el valor pi
#define pi 3.14159265359

// Declaración de funciones
void calcular_volumen_c(float d1, float r1, int h1, float *vol, float *sup);
void calculos_triangulo_rectangulo(float a, float c, float *b, float *A, float *P);
void calcular_expresiones(float w, float z, float alpha, float *expr1, float *expr2);

// Funcion principal
int main() {
    // Declaracion de variables locales
    int h1;
    float d1, r1, vol, sup;
    float a, c, b, A, P;
    float w, z, alpha, expr1, expr2;

    // Parte 1
    printf("Ingrese la circunferencia del cilindro: ");
    scanf("%f", &c);

    d1 = c / pi;
    r1 = d1 / 2;

    printf("Ingrese el alto del cilindro: ");
    scanf("%d", &h1);

    //printf("El diametro es: %f el radio es %f y la altura es %d\n", d1, r1, h1);

    calcular_volumen_c(d1, r1, h1, &vol, &sup);

    printf("El volumen es: %f\n", vol);
    printf("La superficie es: %f\n", sup);

    // Parte 2
    printf("Ingrese el valor del cateto a: ");
    scanf("%f", &a);

    printf("Ingrese el valor de la hipotenusa c: ");
    scanf("%f", &c);

    // Llamada a la funcion de calculos
    calculos_triangulo_rectangulo(a, c, &b, &A, &P);

    // Impresion de resultados
    printf("El cateto b es: %f\n", b);
    printf("El area A es: %f\n", A);
    printf("El perimetro P es: %f\n", P);

    // Parte 3
    printf("Ingrese el valor de w: ");
    scanf("%f", &w);

    printf("Ingrese el valor de z: ");
    scanf("%f", &z);

    printf("Ingrese el valor del angulo alpha en grados: ");
    scanf("%f", &alpha);

    // Convertimos el angulo alpha de grados a radianes
    alpha = alpha * pi / 180;

    calcular_expresiones(w, z, alpha, &expr1, &expr2);

    printf("El valor de la expresion 1 es: %f\n", expr1);
    printf("El valor de la expresion 2 es: %f\n", expr2);
    return 0;
}

// Funcion de calcular el volumen de un cilindro recto
void calcular_volumen_c(float d1, float r1, int h1, float *vol, float *sup) {
    // Calculo del volumen
    *vol = pi * pow(r1, 2) * h1;

    // Calculo de la superficie
    *sup = 2 * pi * r1 * (h1 + r1);
}

// Funcion para calcular el cateto
void calculos_triangulo_rectangulo(float a, float c, float *b, float *A, float *P) {
    // Calculo del cateto b
    *b = sqrt(pow(c, 2) - pow(a, 2));

    // Calculo del area A
	*A = 0.5 * a * (*b);

	// Calculo del perimetro P
	*P = a + *b + c;
}

// Funcion para calcular expresiones
void calcular_expresiones(float w, float z, float alpha, float *expr1, float *expr2) {
    // Calculo de la expresion 1
    *expr1 = 1 / cos(alpha + pi/4) - 7 + exp(1) / (pi/2);

    // Calculo de la expresion 2
    *expr2 = sqrt(log(w)) - 2 * sqrt(z);
}