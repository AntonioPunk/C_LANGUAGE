#include <stdio.h>
#include <stdlib.h>


int main()


{
	char cadena1[100] , cadena2[100] , cadena3[100] , cadena4[100];
	int i=0;
	
	for (i=0 ; i<4 ; i++)
	{
	printf("\n\nIntroduzca la CADENA %d:\n", i+1);
	
	if(i==0)
		{
		gets(cadena1);
		}
	if(i==1)
		{
		gets(cadena2);
		}
	if(i==2)
		{
		gets(cadena3);
		}
	if(i==3)
		{
		gets(cadena4);
		}	
	}
	
	printf("\n%s - %s - %s - %s", cadena1, cadena2, cadena3, cadena4);
	
	return 0;
}
