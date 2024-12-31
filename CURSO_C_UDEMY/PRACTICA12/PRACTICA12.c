#include <stdio.h>
#include <stdlib.h>
#define num 10

int main(){

int vector[num] , i = 1 , n ;

for (n = 0 ; n < num ; n++){
	printf("\nIntroduzca el n�mero %d: ", n + 1);
	scanf("%d", &vector[n]);
}

int mayor = vector[0] , menor = vector[0];

for (i = 1 ; i < num ; i++){
	if (vector[i] > mayor)
	{
		mayor = vector[i];
	}
	if (vector[i] < menor)
	{
		menor = vector[i];
	}
}
printf ("\nEl n�mero menor es %d y el n�mero mayor es %d", menor , mayor);	
return 0;
}
