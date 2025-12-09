#include <stdio.h>

int main(){

    char texto_tarjeta[17];
    int numero_tarjeta[16], i, j = 0;

    printf("Introduce el número de tu tarjeta de credito: ");
    fgets(texto_tarjeta, 17, stdin);

    for(i = 0; i < 16; i++){
        numero_tarjeta[i] = texto_tarjeta[i] - 48;
    }
    printf("\nEl número de tarjeta es: ");
    for(i = 0; i < 16; i++){
        printf("%d", numero_tarjeta[i]);
        if(j == 3 || j == 7 || j == 11){
            printf(" ");
        }
        j++;
    }
    printf("\n");

    return 0;
}