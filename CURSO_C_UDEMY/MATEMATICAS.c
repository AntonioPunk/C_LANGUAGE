#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()

{

double a, b;
int sel, n=0;

while (1)
{
    
while(n==0)
{
    printf("\nIntroduzca el primer numero: ");
    n=scanf("%lf", &a);
    if (n==0) printf ("\nEl dato introducido no es un numero.");
    while(getchar()!='\n');
}

n=0;

while(n==0)
{
    printf("\nIntroduzca el segundo numero: ");
    n=scanf("%lf", &b);
    if (n==0) printf ("\nEl dato introducido no es un numero.");
    while(getchar()!='\n');
}

n=0;




while(n==0)
    {
    printf("\n\n1.-SUMAR\n2.-RESTAR\n3.-MULTIPLICAR\n4.-DIVIDIR\n0.-SALIR\n\nELIJA LA OPERACION DESEADA: ");
    n=scanf("%d", &sel);
    if(n==0) printf("\nLa opcion escogida no es valida.");
    while(getchar()!='\n');
    }

n=0;

switch (sel)
    {
    case 1:
        printf ("\nLa SUMA de %.2lf mas %.2lf es %.2lf", a, b, a+b);
        printf("\n\nPulse ENTER para continuar.");
        getchar();
        system("cls");
        break;
 
    case 2:
        printf ("\nLa RESTA de %.2lf menos %.2lf es %.2lf", a, b, a-b);
        printf("\n\nPulse ENTER para continuar.");
        getchar();
        system("cls");       
        break;

    case 3:
        printf("\nLa MULTIPLICACION de %.2lf por %.2lf es %.2lf", a, b, a*b);
        printf("\n\nPulse ENTER para continuar.");
        getchar();
        system("cls");
        break;

    case 4:
        printf("\nLa DIVISION de %.2lf entre %.2lf es %.2lf", a, b, a/b);
        printf("\n\nPulse ENTER para continuar.");
        getchar();
        system("cls");       
        break;
 
    case 0:
        printf("\nSALIENDO DEL PROGRAMA.......");
        return 0;
 
    default: 
        printf("\nLa opcion escogida no es valida.");
        break;
    }

}



}