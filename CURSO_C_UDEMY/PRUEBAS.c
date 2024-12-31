#include <stdio.h>
#include <stdlib.h>

// Uso de typedef enum para crear nuevos tipos de variables partiendo de las primitivas y enumerar datos.
// Nótese que typedef enum asigna un entero {0,1,2,3 ...} a cada valor posible enumerado.
// Su uso es para hacer más facil de leer el código al poder sustituir nombres de variables y sus valores por el nombre que queramos.


int main() 

{
int bucle = 0;
typedef enum {lunes , marte , miercoles , jueves , viernes , sabado , domingo} semana;

//while (bucle == 0) 					//Para hacer un bucle infinito
for (bucle == 0 ; bucle<5 ; bucle++)	//Hace un bucle de 5 veces,
{

semana dia;

dia = lunes;

//printf ("%d\n\n", dia);

printf("\n\nIntroduzca el dia de la semana del 1 al 7 siendo el lunes 1: ");
scanf("%d", &dia);
dia = --dia;	
//printf ("%d\n\n", dia);	
		
while (dia < 0 , dia > 6)
	{
	printf ("\n\nNumero fuera de parametro, introduzca un nuevo numero comprendido entre 1 y 7: ");
	scanf ("%d", &dia);
	dia = --dia;
	}


if (dia == 0)
	{
		printf ("\nPUTO LUNES, que pase rapidito :(");
	}	

else 
printf ("\nHoy no es lunes, FELIZ DIA!!!");


}

}
