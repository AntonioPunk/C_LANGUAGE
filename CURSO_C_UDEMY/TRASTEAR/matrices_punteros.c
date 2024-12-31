#include <stdio.h>


int main (){

    int matriz[3][4]= { {23,45,67,56} , {87,65,90,67} , {21,23,67,55} };
    int i, j;

    for (i=0; i<3; i++){
        for(j=0; j<4; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    int *puntero[3];

    for (i=0;i<2;i++) puntero[i]=matriz[i];


    printf("Introduzca un numero: ");
    scanf("%d", (*(puntero+1)+2));


    printf ("\n%d\n", *(*(puntero+1)+2));
    
        for (i=0; i<3; i++){
        for(j=0; j<4; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}