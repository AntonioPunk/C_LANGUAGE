#include <stdio.h>
#include <stdlib.h>

#define PRECIO_ENTRADA 10.50

int main(){

    typedef struct
    {
        int hora;
        int minutos;
    } time_in;
    
    
    typedef struct 
    {
        time_in hora_entrada;
        int num_personas;
        float precio_total;
    } grupo_personas;
    
    grupo_personas grupo;

    printf("----- DATOS GRUPO VISITANTES MUSEO -----\n\n");
    printf("Introduzca el numero de personas que compone el grupo: ");
    scanf("%d", &grupo.num_personas);
    printf("Introduzca la hora de entrada (HH MM): ");
    scanf("%d %d", &grupo.hora_entrada.hora, &grupo.hora_entrada.minutos);

    float precio_grupo= PRECIO_ENTRADA*grupo.num_personas;

    printf("\nEl precio total para el grupo de %d personas con hora de entrada %d:%d es de %.2f Euros\n\n", grupo.num_personas, grupo.hora_entrada.hora, grupo.hora_entrada.minutos, precio_grupo);

    system ("pause");

    return 0;
}