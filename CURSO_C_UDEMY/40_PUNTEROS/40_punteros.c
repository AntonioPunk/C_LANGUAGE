#include <stdio.h>
#include <stdlib.h>

int main(){

// Puntero a entero:   
    int number_of_items = 30;
    int *puntero_entero = &number_of_items;
    printf("El contenido de la variable 'number_of_items' es: %d", *puntero_entero);
    printf("\nLa dirección de memoria de la variable 'number_of_items' es : %p\n", puntero_entero);


// IMPORTANTE: PARA ASIGNAR LA DIRECCIÓN DE MEMORIA DONDE
// COMIENZA UNA CADENA Ó ARRAY, BASTA CON ASIGNAR EL NOMBRE, YA QUE
// EL NOMBRE REPRESENTA LA DIRECCIÓN DE COMIENZO.

// Puntero a cadena:
    char cadena[30] = "esta es una cadena de prueba";
    char *puntero_cadena = cadena;
    // Recorremos el array usando el puntero:
    for(int i = 0; i < 30; i++){
        printf("%c ", *(puntero_cadena + i));
    }

// Puntero a vector de enteros:
    int vector_enteros[5] = {2, 4, 6, 8, 10};
    int *puntero_vector = vector_enteros;

    printf("\n%d", *(puntero_vector + 1));

// Puntero a estructuras:
    struct ficha
    {
        char genero;
        int age;
    };

    struct ficha student_1;

    struct ficha *puntero_estructura = &student_1;

    (*puntero_estructura).age = 47;
    puntero_estructura->genero = 'M';
    printf("\n%d", (*puntero_estructura).age);
    printf("\n%c", student_1.genero);
    return 0;

}