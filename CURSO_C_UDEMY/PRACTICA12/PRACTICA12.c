#include <stdio.h>
#include <stdlib.h>
#define num 10

int main()

{
	
int vector[num] , i=1 , n ;


for (n=0 ; n<10 ; n++)
{
	printf("\nIntroduzca el número %d: ", n+1);
	scanf("%d", &vector[n]);
}

int mayor=vector[0] , menor=vector[0];

for (i=1 ; i<10 ; i++)
{

if (vector[i] > mayor)
{
	mayor=vector[i];
}

if (vector[i] < menor)
{
	menor=vector[i];
}

}
	
	printf ("\nEl número menor es %d y el número mayor es %d", menor , mayor);	



return 0;
}
