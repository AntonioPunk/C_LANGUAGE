#include <stdio.h>
#include <stdlib.h>

// PASO DE ARGUMENTOS POR VALOR EN FUNCIONES:
// NO podemos alterar el valor de los parámetros dentro de la función.
float suma_valor(float num1, float num2);

// PASO DE ARGUMENTOS POR REFERENCIA EN FUNCIONES:
// Podemos alterar el valor de los parámetros dentro de la función.

void suma_referencia(float num1, float num2, float *resultado);


int main(){

    float num1, num2, resultado;

    printf("Introduzca el primer número: ");
    scanf("%f", &num1);
    printf("Introduzca el segundo número: ");
    scanf("%f", &num2);

    resultado = suma_valor(num1, num2);
    printf("La suma de %.2f + %.2f es: %.2f", num1, num2, resultado);

    suma_referencia(num1, num2, &resultado);
    printf("\nLa suma de %.2f + %.2f es: %.2f", num1, num2, resultado);

    return 0;
}

float suma_valor(float num1, float num2){
    float resultado = num1 + num2;
    return resultado;
}

void suma_referencia(float num1, float num2, float *resultado){
    *resultado = num1 + num2;
}