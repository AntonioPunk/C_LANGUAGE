#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416

int main()
{
	float radio;
	float area;
	int exp = 2;
	printf("Introduzca el radio en centimetros del circulo: ");
	scanf("%f", &radio);
	float potencia = pow(radio,exp);
	area = PI*potencia ;
	printf("\nEl area del circulo de radio %.2f es de  %.3fcm. cuadrados.", radio, area);
	
	
	return 0;
}
