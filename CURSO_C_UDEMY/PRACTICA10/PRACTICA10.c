#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()

{
int divisor=0;	
float n=1 , suma=0 , promedio ;

while (n != 0 )
	{
		printf("\nIntroduzca número: ");
		scanf("%f", &n);
		suma += n;
		divisor++;
	}
promedio= suma/divisor;	
printf("\n\nLa suma de los números es %.2f y el promedio %.2f", suma , promedio );
	
	return 0;
}
