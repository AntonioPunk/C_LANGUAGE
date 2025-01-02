#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONG 30

int main()

{
int l;
char nombre[LONG];
printf("Hola, introduzca un nombre: ");
scanf("%s", &nombre);
//fgets(nombre , LONG , stdin);

//l=strlen(nombre);
//if(nombre[l-1]=='\n') nombre[l-1]='\0';

printf("El nombre introducido es: %s" , nombre);

return 0;

}