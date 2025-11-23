#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main(){

    int num1, num2, r_suma, r_resta, r_multiplicacion;
    float r_division;

    printf("Introduzca el primer operador: ");
    scanf("%d", &num1);
    printf("Introduzca el segundo operador: ");
    scanf("%d", &num2);

    r_suma = suma(num1, num2);
    r_resta = resta(num1, num2);
    r_multiplicacion = multiplicacion(num1, num2);
    r_division = division(num1, num2);

    printf("\n %d + %d = %d", num1, num2, r_suma);
    printf("\n %d - %d = %d", num1, num2, r_resta);
    printf("\n %d * %d = %d", num1, num2, r_multiplicacion);
    printf("\n %d / %d = %.2f\n", num1, num2, r_division);


    system("pause");

    return 0;
}