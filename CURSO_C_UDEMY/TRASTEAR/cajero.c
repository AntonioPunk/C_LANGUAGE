#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{

double saldo=0, ingreso=0, reembolso=0;
int sel , n=0, ning=0, nreem=0;

while(1)
{
system("cls");

printf("\n\n\n\n\n\n\t\t\t****************************************");
printf("\n\t\t\t*                                      *");
printf("\n\t\t\t*      OPERACIONES CUENTA BANCO        *");
printf("\n\t\t\t*                                      *");
printf("\n\t\t\t****************************************");

sel=0;
n=0;

printf("\n\n\t\t\t1.- INGRESAR DINERO.");
printf("\n\t\t\t2.- RETIRAR DINERO.");
printf("\n\t\t\t3.- CONSULTAR SALDO.");
printf("\n\t\t\t4.- CONSULTAR NUMERO DE INGRESOS.");
printf("\n\t\t\t5.- CONSULTAR NUMERO DE REEMBOLSOS.");
printf("\n\t\t\t6.- SALIR.");


while(n==0)
{
    printf("\n\n\t\t\tSELECCIONE LA OPERACION A REALIZAR: ");
    n=scanf("%d", &sel);
    while(getchar()!='\n');
    if(n==0) printf("\n\t\t\tLa opcion seleccionada no es valida.");
}

n=0;

switch (sel)
{
case 1:
    while(n==0)
    {
    printf("\n\t\t\tINTRODUZCA LA CANTIDAD A INGRESAR EN EUROS: ");
    n=scanf("%lf", &ingreso);
    while(getchar()!='\n');
    if(n==0) printf("\n\t\t\tLa cantidad introducida no es valida.");
    }
    saldo+=ingreso;
    ning++;
    printf("\n\t\t\tHa ingresado %.2lf euros.", ingreso);
    printf("\n\t\t\tPresione ENTER para continuar.");
    getchar();

    break;
case 2:
    while(n==0)
    {
    printf("\n\t\t\tINTRODUZCA LA CANTIDAD A RETIRAR EN EUROS: ");
    n=scanf("%lf", &reembolso);
    while(getchar()!='\n');
    if(n==0) printf("\n\t\t\tLa cantidad introducida no es valida.");
    }
    saldo-=reembolso;
    nreem++;
    printf("\t\t\tHa retirado %.2lf euros.", reembolso);
    printf("\n\t\t\tPresione ENTER para continuar.");
    getchar();

    break;
case 3:
    printf("\n\t\t\tEL SALDO ACTUAL ES DE: %.2lf euros.", saldo);
    printf("\n\t\t\tPresione ENTER para continuar.");
    getchar();   
    break;
case 4:
    printf("\n\t\t\tEL NUMERO DE INGRESOS REALIZADOS ES: %d", ning);
    printf("\n\t\t\tPresione ENTER para continuar.");
    getchar();
    break;
case 5:
    printf("\n\t\t\tEL NUMERO DE REEMBOLSOS REALIZADO ES: %d", nreem);
    printf("\n\t\t\tPresione ENTER para continuar.");
    getchar();
    break;
case 6:
    printf("\n\n\t\t\t\tSALIENDO DEL PROGRAMA..............");
    return 0;
default:
    printf("\n\t\t\tLa opcion seleccionada no es valida.");
    break;
}

}

}