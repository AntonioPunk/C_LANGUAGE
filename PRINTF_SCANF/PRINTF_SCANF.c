#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 


{
	char perro[10] , madre[10] , abuela[10] ;
	
	printf("Introduzca el nombre de su perro , de su madre y de su abuela: ");
	scanf("%s %s %s", perro , madre , abuela);

	printf("%-10s %-10s %-10s", perro , madre , abuela);
	
	
	
	return 0;
}
