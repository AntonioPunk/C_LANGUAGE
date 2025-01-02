#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()

{

char cadena[50] , caracter;
int i=0 , posicion=0 , n=0;

printf("Introduzca una cadena (maáx 50 char): ");
gets(cadena);

printf("\nIntroduzca un caracter: ");
scanf("%c", &caracter);
 



while (cadena[i] != '\0')
{
	
	if (cadena[i]==caracter && n!=1) 
		{
		posicion=i;
		printf("\nEl caracter '%c' se encuentra en la cadena '%s' y su primera aparición es en la posición %d", caracter, cadena , posicion+1);
		n=1;
		}
	i++;
	
}	

if (n==0) printf("\n\nEl caracter '%c' no se encuentra en la cadena '%s'.", caracter, cadena);

	
	return 0;
}
