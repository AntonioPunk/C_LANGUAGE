#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()

{

int numero1, numero2, operador, n=10, aciertos=0, juego=1, resultado, respuesta;

srand(time(NULL));

while(juego==1)
{
numero1= rand() %n;
numero2= rand() %n;
operador= rand() %4;

switch (operador)
{
case 0:
    resultado=numero1+numero2;
    printf("\n\nCuál es el resultado de: ( %d + %d ) ? ", numero1, numero2);
    scanf("%d", &respuesta);
    if(respuesta==resultado)
        {
        printf("\nEnhorabuena, el resultado es correcto.");
        aciertos +=1;
        }
    else 
        {
        printf("\nEl resultado es incorrecto, idiota!!!");
        juego=0;
        }
break;

case 1:
    resultado=numero1-numero2;
    printf("\n\nCuál es el resultado de: ( %d - %d) ? ", numero1, numero2);
    scanf("%d", &respuesta);
    if(respuesta==resultado)
        {
        printf("\nEnhorabuena, el resultado es correcto.");
        aciertos +=1;
        }
    else 
        {
        printf("\nEl resultado es incorrecto, idiota!!!");
        juego=0;
        }
break;

case 2:
    resultado=numero1*numero2;
    printf("\n\nCuál es el resultado de: ( %d * %d) ? ", numero1, numero2);
    scanf("%d", &respuesta);
    if(respuesta==resultado)
        {
        printf("\nEnhorabuena, el resultado es correcto.");
        aciertos +=1;
        }
    else 
        {
        printf("\nEl resultado es incorrecto, idiota!!!");
        juego=0;
        }
break;

case 3:
    if (numero2==0) numero2++;
    resultado=numero1/numero2;
    printf("\n\nCuál es el resultado de: ( %d / %d ) ? ", numero1, numero2);
    scanf("%d", &respuesta);
    if(respuesta==resultado)
        {
        printf("\nEnhorabuena, el resultado es correcto.");
        aciertos +=1;
        }
    else 
        {
        printf("\nEl resultado es incorrecto, idiota!!!");
        juego=0;
        }
break;
}
}

printf("\n\nEl número de aciertos han sido: %d", aciertos);
getchar();

return 0;

}