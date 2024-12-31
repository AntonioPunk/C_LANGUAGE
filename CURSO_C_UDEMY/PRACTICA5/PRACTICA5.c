#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()

{
	float nota;
	int bucle=1;
	
	
	while (bucle==1)
{
	
	printf("\n\nIntroduzca la nota del alumno: ");
	scanf("%f", &nota );
	
	if (nota>=5 && nota<6)
	{
		printf("\nEl alumno ha sacado un SUFICIENTE\n");
	}
	else if (nota>=6 && nota<7)
	{
		printf("\nEl alumno ha obtenido un BIEN\n");
	}
	else if (nota>=7 && nota<9)
	{
		printf("\nEl alumno ha obtenido un NOTABLE\n");
	}
	else if (nota>=9 && nota<=10)
	{
		printf("\nENHONABUENA, el alumno ha obtenido un SOBRESALIENTE !!!\n");
	}
	else if (nota>= 0 && nota<5)
	{
		printf("\nEl alumno ha suspendido :(\n");
	}
	else
	{
		printf("\n\nLa nota introducida no es correcta :/ \n");
	}
}
	return 0;
}
