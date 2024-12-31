#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()

{

float planta1[3][4]={{1,120,150,220},{2,130,160,230},{3,100,120,200}} , baja=0 , media=0, alta=0;
int n=1 , i=0;

for (n=0 ; n<3 ; n++)
{
	for(i=1 ; i<4 ; i++)
	{
		if (i==1)
			{
			baja+=planta1[n][i];
			}
		if (i==2)
			{
			media+=planta1[n][i];
			}
		if (i==3)
			{
			alta+=planta1[n][i];
			}	
		
	}
	
}

/*   OPCION 1
--------------
baja=(planta1[0][1]+planta1[1][1]+planta1[2][1]);
media=(planta1[0][2]+planta1[1][2]+planta1[2][2]);
alta=(planta1[0][3]+planta1[1][3]+planta1[2][3]);
*/

/*   OPCION 2
--------------
for (n=0 ; n<3 ; n++)
{
baja+=planta1[n][1];
media+=planta1[n][2];
alta+=planta1[n][3];
*/


printf("\nEl promedio de la temporada baja es: %.2f", baja/3);
printf("\nEl promedio de la temporada media es: %.2f", media/3);
printf("\nEl promedio de la temporada alta es: %.2f", alta/3);






return 0;
}
