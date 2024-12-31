# include <stdio.h>

int main (){

    int multiplicando, multiplicador, producto = 0;

    printf("Introduzca el número que desea multiplicar: ");
    scanf("%d", &multiplicando);
    printf("\nIntroduzca el número por el cual lo desea multiplicar: ");
    scanf("%d", &multiplicador);

//  producto = multiplicando * multiplicador;

    if(multiplicando != 0){
        for(int i = 0; i < multiplicador; i++ ){
            producto += multiplicando;
        } 
    }

    printf("\nEl resultado de %d por %d es: %d", multiplicando, multiplicador, producto);

    return 0;

}