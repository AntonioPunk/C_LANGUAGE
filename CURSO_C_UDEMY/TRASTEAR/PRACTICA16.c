#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
int n=0 , opcion=1 , i=0 , jugador_nombre=0 , encontrado;
char nombre_buscar[30];
 
struct datos
	{
	char nombre[30];
	int edad ;
	float estatura;
	};	
	

struct datos jugador[5];


for (n=0 ; n<5 ; n++)
{
	printf ("\nIntroduzca el nombre del jugador %d: ", n+1);
	gets (jugador[n].nombre);
	printf ("Introduzca la edad del jugador %d: ", n+1);
	scanf ("%d", &jugador[n].edad);
	printf ("Introduzca la estatura del jugador %d: ", n+1);
	scanf ("%f", &jugador[n].estatura);
	
	fflush(stdin); //Limpia el buffer del teclado para que el próximo gets no lea el INTRO tras poner la estatura.
}


while (opcion != 0)	
{
	
printf ("\n\n------------ MENU BALONCESTO ---------------");
printf ("\n1.- Listar los nombres y alturas de los jugadores.");
printf ("\n2.- Buscar un jugador por su nombre y presentar su altura y edad.");
printf ("\n3.- Indicar el nombre y la edad del jugador mas alto del equipo.");
printf ("\n0.- Salir.");
printf ("\nSeleccione la opcion deseada: ");
scanf ("%d", &opcion);



if (opcion==1)
	{
		for (n=0 ; n<5 ; n++) printf ("\nNombre y estatura del jugador %d: %s - %.2f m.", n+1 , jugador[n].nombre , jugador[n].estatura);
	}

if (opcion==2)
	{
		encontrado=0;
		printf("\nIntroduzca el nombre del jugador: ");
		fflush(stdin);
		gets(nombre_buscar);
		
		for(n=0 ; n<5 ; n++)
		{
			if (strcmp (nombre_buscar , jugador[n].nombre) == 0)
				{
				printf ("\nLa estatura y edad del jugador %s es: %.2fm. y tiene %d anos.", jugador[n].nombre , jugador[n].estatura , jugador[n].edad);
				encontrado=1;
				}	
		}
		
		if (encontrado==0)
		{
		printf ("\nNo existe ningun jugador con ese nombre.");
		} 
	}
	
	
if (opcion==3)
	{
	int jugador_mas_alto=0;
	float estatura_maxima = jugador[0].estatura;	
	for (n=1 ; n<5 ; n++)
	{
		if (jugador[n].estatura > estatura_maxima)
		{
		jugador_mas_alto = n;
		estatura_maxima = jugador[n].estatura;
		}
	}
	printf ("\nEl jugador mas alto del equipo es: %s y tiene %d anos", jugador[jugador_mas_alto].nombre , jugador[jugador_mas_alto].edad);
	
	}		

if (opcion!=0 && opcion!=1 && opcion!=2 && opcion!=3) printf("\nLa opcion elegida no existe.");

}
	
	return 0;
}
