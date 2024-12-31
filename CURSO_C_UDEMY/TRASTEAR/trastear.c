#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()


{
int vector[10] , n , mayor , menor;

for (n=0 ; n<10 ; n++)
	{
		printf("\nIntroduzca el número de la posición %d: ", n+1);
		scanf("%d",  &vector[n]);
	}

mayor=vector[0];
menor=vector[0];
	
for (n=1 ; n<10 ; n++)
	{
		if(vector[n]>mayor) mayor=vector[n];
		if(vector[n]<menor) menor=vector[n];
	}
	
printf("\n\nEl número mayor de la cadena es %d y el menor %d", mayor, menor);
	
return 0;
	
}
