#include <stdio.h>
#define N 5

int main(){

    float lista_numeros[N];
    float sumatorio = 0;
    float media = 0;
    float *pointer;

    for(int i = 0; i < N; i++){
        printf("\nIntroduzca un número real para la posición %d del vector: ", (i + 1));
        scanf("%f", &lista_numeros[i]);
    }
    
    pointer = &lista_numeros[0];

    for(int i = 0; i < N; i++){
        sumatorio = sumatorio + *(pointer + i);
    }

    media = sumatorio / N;

    printf("\nLa media de los %d números introducidos es: %.2f", N, media);

    return 0;
}