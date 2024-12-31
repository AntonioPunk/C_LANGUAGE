#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()

{
	int n;
	
	
	while (1)
	{
	
	printf ("\n\nIntroduzca el numero de la semana: ");
	scanf("%d", &n);
	
	
	switch (n)
	{
		case(1):
			printf("\nEl dia de la semana que corresponde a %d es lunes.\n", n);
			break;
		case(2):
			printf("\nEl dia de la semana que corresponde a %d es martes.\n", n);
			break;
		case(3):
			printf("\nEl dia de la semana que corresponde a %d es miercoles.\n", n);
			break;
		case(4):
			printf("\nEl dia de la semana que corresponde a %d es jueves.\n", n);
			break;
		case(5):
			printf("\nEl dia de la semana que corresponde a %d es viernes.\n", n);
			break;
		case(6):
			printf("\nEl dia de la semana que corresponde a %d es sabado.\n", n);
			break;
		case(7):
			printf("\nEl dia de la semana que corresponde a %d es domingo.\n", n);
			break;
		default:
			printf("\nEl numero introducido no se corresponde con ningun dia de la semana.\n");
	}
	}
	
	
	return 0;
}
