#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()

{
int n=0 , ch=0 , ln;
char nombre[30];

printf("Hola, introduzca un numero: ");
scanf("%d", &n);
printf("Introduzca un nombre: ");
while ((ch = getchar()) != '\n' && ch != EOF);
fgets(nombre , sizeof nombre , stdin);
ln = strlen (nombre);
if (nombre[ln-1]=='\n') nombre[ln-1]='\0';

printf("El nombre introducido es %s y el numero es %d.", nombre , n);

return 0;
}