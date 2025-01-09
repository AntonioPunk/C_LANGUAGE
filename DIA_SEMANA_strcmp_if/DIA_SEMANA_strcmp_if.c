#include <stdio.h>
#include <stdlib.h>

/* COMPARAR CADENAS CON strcmp Y USO DE if */

int main()

{
	
	char dia[10];
	
	printf ("Introduzca el dia de la semana en que estas: ");
	scanf ("%s" , dia);
	printf("\n%s!!!" , dia);
	
	if (strcmp (dia, "lunes") == 0) {
			printf("\n\nQue pase rapidito :(");
		}
		
		else 
		printf("\n\nQue tengas un bello dia :)");
		
				
		
	
	return 0;
}
