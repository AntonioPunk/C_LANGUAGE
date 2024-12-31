// MUESTRA POR PANTALLA LOS MÚLTIPLOS HASTA 100 DE UN NÚMERO FIJADO CON #define 

#include <stdio.h>
#include <stdlib.h>
#define N 2


int main()
{
	
int n=0;

for (n=N ; n<=100 ; n++)
{
	if (n%N==0)
	{
	printf("%d - ", n);
	}	
}
	
	return 0;
}
