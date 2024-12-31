#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()

{
int alumnos, aprobados=0 ,  suspensos=0;
float nota;
int n=1;
printf("Introduzca el numero de alumnos: ");
scanf("%d", &alumnos);

for (n==1 ; n<=alumnos ; n++)
	{
		printf ("\nIntroduzca la nota del alumno %d: ", n);
		scanf ("%f", &nota);
		
		if (nota>=0 && nota<5)
		{
			suspensos++;
		}
		if (nota>=5 && nota <=10)
		{
			aprobados++;
		}
	}
	
printf("\n\nEl numero de alumnos aprobados es %d y el de suspensos es %d .", aprobados, suspensos);
	
	
	
	
	
	return 0;
}
