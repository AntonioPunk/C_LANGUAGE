#include<stdio.h>
#include<string.h>
#define numeroClientes 100

int main()
{

int n=0;   
struct datosFinancieros
{
    char entidad[30];
    double saldo;
};



typedef struct
    {
        char nombre[20];
        int telefono;
        char direccion[20];
        struct datosFinancieros banco;
    } ficha;
    
ficha cliente[numeroClientes];

while(n<3)
{
    n=0;
    printf("\nIntroduzca el nombre, teléfono y dirección del cliente: ");
    n=scanf("%s %d %s", cliente[0].nombre, &cliente[0].telefono, cliente[0].direccion);
    if(n!=3) printf("Formato incorrecto, repita la entrada de datos.");
    while (getchar()!='\n');
}

n=0;

while(n<2)
{
    n=0;
    printf("\nIntroduzca el la entidad y saldo del cliente: ");
    n=scanf("%s %lf", cliente[0].banco.entidad, &cliente[0].banco.saldo);
    if(n!=2) printf("Formato incorrecto, repita la entrada de datos.");
    while (getchar()!='\n');
}
printf("\nEl cliente 1 se llama %s, con número de teléfono %d y domicilio en %s", cliente[0].nombre, cliente[0].telefono, cliente[0].direccion);
printf("\n\nEl saldo de %s es de %.2lf euros y los tiene depositados en el banco %s", cliente[0].nombre, cliente[0].banco.saldo, cliente[0].banco.entidad);

getchar();
   
return 0;


}