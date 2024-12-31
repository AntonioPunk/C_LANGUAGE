 #include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()

{
	float euros ;
	
	
	printf("CONVERSOR DE EUROS A PESETAS\n\n");
	printf("Introduzca la cantidad de euros que desea convertir: ");
	scanf("%f" , &euros);
	printf("\n\nEl valor en pesetas de %.2f euros es: %f pesetas." , euros , euros*166.386);
	
	
	
	return 0;
}
