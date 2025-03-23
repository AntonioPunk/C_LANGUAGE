#include <stdio.h>

int main(){

    float number;
    printf("Introduzca un número: ");
    scanf("%f, %*c", &number);
    printf("\nHa introducido el número: %.2f", number);

    return 0;
}