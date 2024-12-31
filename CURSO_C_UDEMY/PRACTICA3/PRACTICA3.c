#include <stdio.h>
#include <stdlib.h>


int main()

{
	float base , altura;
	
	printf ("Vamos a calcular el area de un rectangulo!!!\n\n");
	
	printf ("Introduzca la medida de la base en cm: ");
	scanf ("%f", &base);
	
	printf ("\nIntroduzca la medida de la altura en cm: ");
	scanf ("%f", &altura);
	
	printf ("\n\nEl area del rectangulo es de: %.2fcm. cuadrados." , base*altura );
	
	return 0;
}
