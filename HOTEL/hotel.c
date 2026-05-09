#include <stdio.h>
#include <stdlib.h>


int main()

{
while (1)
{

int h=0 , n=1 , i=0;
float baja=0 , media=0, alta=0;

printf("\n\n\tAPLICACION QUE MUESTRA EL VALOR MEDIO DE\n\tLOS PRECIOS EN TEMPORADA BAJA, MEDIA Y ALTA\n\tPARA UN NUMERO DETERMINADO DE HABITACIONES");
printf("\n---------------------------------------------------------");

printf("\n\n\nIntroduzca el numero de habitaciones: ");
scanf("%d", &h);

float planta1[h][4];

for(n=0 ; n<h ; n++)
{
	planta1[n][0]= n+1;
}

for (n=0 ; n<h ; n++)
{
printf("\nIntroduzca el precio en temporada BAJA  para la habitacion #%d: ", n+1);
scanf("%f", &planta1[n][1]);
printf("Introduzca el precio en temporada MEDIA para la habitacion #%d: ", n+1);
scanf("%f", &planta1[n][2]);
printf("Introduzca el precio en temporada ALTA  para la habitacion #%d: ", n+1);
scanf("%f", &planta1[n][3]);
}


// mostramos por pantalla los datos del array
printf("\n\nEstos son los precios introducidos para cada habitacion:\n");

for(n=0 ; n<h ; n++)
{
	printf("HABITACION: ");
	printf("\t%.0f  ", planta1[n][0]);
	printf("\t%.2f  ", planta1[n][1]);
	printf("%.2f  ", planta1[n][2]);
	printf("%.2f  ", planta1[n][3]);
	printf("\n");

}
//hacemos el sumatorio de cada temporada
for (n=0 ; n<h ; n++)
{
	for(i=1 ; i<4 ; i++)
	{
		if (i==1)
			{
			baja+=planta1[n][i];
			}
		if (i==2)
			{
			media+=planta1[n][i];
			}
		if (i==3)
			{
			alta+=planta1[n][i];
			}	
		
	}
	
}

// mostramos por pantalla el promedio de las tres temporadas
printf("\n\n\nLa media del precio en temporada BAJA  es:\t%.2f", baja/h);
printf("\nLa media del precio en temporada MEDIA es:\t%.2f", media/h);
printf("\nLa media del precio en temporada ALTA  es:\t%.2f", alta/h);

}

return 0;
}
