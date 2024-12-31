#include <stdio.h>
#include <stdlib.h>
#define personas 5

int main() 

{
	
float pesos[personas] , promedio=0 , sumatorio=0 ;
int puntero , inferior=0 , superior=0 ;


for (puntero=0 ; puntero<personas ; puntero++)
	{
		printf("\nIntroduzca el peso de la persona %d : ", puntero+1);
		scanf("%f", &pesos[puntero]);
		sumatorio +=pesos[puntero];		
	}
	
promedio=sumatorio/personas;
//puntero=0;

for (puntero=0 ; puntero<personas ; puntero++)
	{
		if (pesos[puntero]<promedio) inferior++;	
		else superior++;
	}

printf("\n\nEl promedio de los pesos es: %.2f", promedio);
printf("\n\nEl número de personas con peso inferior al promedio es: %d", inferior);
printf("\n\nEl número de personas con peso superior o igual al promedio es: %d", superior);




	return 0;
}
