#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    
int n=0 , opcion=1 , encontrado , c=0 , l ;
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
    fgets (jugador[n].nombre, 30, stdin);
	l = strlen(jugador[n].nombre);
	if (jugador[n].nombre[l-1]=='\n') jugador[n].nombre[l-1]='\0';
	printf ("Introduzca la edad del jugador %d: ", n+1);
	scanf ("%d", &jugador[n].edad);
	printf ("Introduzca la estatura del jugador %d: ", n+1);
	scanf ("%f", &jugador[n].estatura);
    while((c = getchar()) != '\n' && c != EOF);
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
		while((c = getchar()) != '\n' && c != EOF);
        fgets (nombre_buscar , 30 , stdin);
		l = strlen(nombre_buscar);
		if (nombre_buscar[l-1]=='\n') nombre_buscar[l-1]='\0';

		
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