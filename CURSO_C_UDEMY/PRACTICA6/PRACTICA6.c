/* 	El programa pide el preciobase de un vehículo, los kilómetros y el consumo.
	Si los kilómetros son menores a 20000 y el consumo menor o igual a 5, se incrementa el precio base en un 20%
	Si los kilómetros son 20000 o más y el consumo es menor o igual a 5, se incrementa el valor en un 10%
	Si el consumo es mayor a 5 se decrementa el valor en un 5&
	*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()

{

float preciobase, preciofinal, consumo;
int km;
int bucle=1;

while (bucle==1)
{
	
printf("Introduzca el precio base del vehiculo: ");
scanf("%f", &preciobase);
printf("\nIntroduzca el numero de kilometros que tiene el vehiculo: ");
scanf("%d", &km);
printf("\nIntroduzca el consumo del vehiculo en l/100Km.: ");
scanf("%f", &consumo);

if (consumo<=5 && km<20000)

	{
		preciofinal=preciobase + (preciobase*20/100);
	}
	
else if (consumo<=5 && km>=20000)
	{
		preciofinal=preciobase + (preciobase*10/100);
	}
	
else if (consumo>5)
	{
		preciofinal=preciobase-(preciobase*5/100);
	}
	
printf("\nEl precio final del vehiculo es: %.2f euros\n\n\n", preciofinal);
}

	return 0;
}
