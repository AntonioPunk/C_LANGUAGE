#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){

    char repetir;

    typedef struct 
    {
        int hora;
        int minuto;
    } hora;

    typedef struct 
    {
        hora hora_acceso;
        int num_personas;
        float precio_total;
        int menores_6;
        int de_7_a_15;
        int de_16_a_26_65;
        int resto_edades;
        bool descuento10;    
    } fichaGrupo;

    do {
        fichaGrupo grupo;
        grupo.menores_6 = 0;
        grupo.de_7_a_15 = 0;
        grupo.de_16_a_26_65 = 0;
        grupo.resto_edades = 0;
        grupo.descuento10=false;

        system ("cls");

        printf ("\t----- MUSEO DEL PRADO -----\n");
        printf ("\n\nBienvenido al sistema de reservas para grupos.");

        printf ("\n\nIntroduzca el numero de personas: ");
        scanf ("%d", &grupo.num_personas);
        if (grupo.num_personas>=5) grupo.descuento10=true;
        printf("Introduzca la hora de acceso (hh mm): ");
        scanf ("%d %d", &grupo.hora_acceso.hora , &grupo.hora_acceso.minuto);
        printf ("\n");


        for (int i=0; i<grupo.num_personas; i++){
            int edad;
            printf("\tIntroduzca la edad de la persona %d: ", i+1);
            scanf ("%d", &edad);

            if (edad>=0 && edad<6) grupo.menores_6++;
            else if (edad>=6 && edad<=15) grupo.de_7_a_15++;
            else if ((edad>=16 && edad<=26) || edad>=65) grupo.de_16_a_26_65++ ;
            else grupo.resto_edades++;
        }

        grupo.precio_total= (grupo.de_7_a_15 * 5)+(grupo.de_16_a_26_65 * 8)+(grupo.resto_edades * 10);

        if (grupo.descuento10==true){
            grupo.precio_total = grupo.precio_total-(grupo.precio_total*0.1);
            printf ("\n\nTienen un descuento del 10%% al ser un grupo de 5 personas o mas.");
        }

        if (grupo.menores_6>0) printf("\nPara los %d menores de 6 anos la entrada es gratuita.", grupo.menores_6);

        printf ("\n\nEL TOTAL DEL IMPORTE PARA EL GRUPO DE %d PERSONAS ES DE %.2f EUROS", grupo.num_personas, grupo.precio_total);
        printf ("\n\nEl grupo podra acceder a partir de las %d:%d horas.\n\n", grupo.hora_acceso.hora, grupo.hora_acceso.minuto);
        
        do{
            printf ("Desea introducir los datos de otro grupo (s)/(n) ");
            while (getchar() != '\n');
            scanf ("%c", &repetir);
    
            if (repetir=='s');
            else if (repetir=='n') printf ("\nGracias por usar el sistema de reservas del Museo del Prado, vuelva pronto.\n\n\n");
            else printf ("\nLa opcion no es correcta, pulse (s) o (n).\n");

        } while (repetir!='s' && repetir!='n'); 

        
        



    } while (repetir=='s');
    
    system ("pause");


    return 0;
}