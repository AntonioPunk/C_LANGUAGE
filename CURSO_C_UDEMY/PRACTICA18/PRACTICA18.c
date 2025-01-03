/* 

PRACTICA 18:

Escribir una función que reciba como parámetros:
- Un vector de enteros por REFERENCIA
- Longitud del vector por VALOR
- Número por VALOR

DEBE MULTIPLICAR CADA ELEMENTO DEL VECTOR POR EL NÚMERO.

*/

#include <stdio.h>

void mult_vector(int *vector, int size_vector, int number);

int main(){
    int vector[] = {2, 4, 6, 8, 10};
    int size_vector = 5;
    int number = 3;

    // Llamamos a la función y le pasamos los parámetros.
    // En este caso, como el nombre de un array (vector)
    // representa en sí mismo su dirección de comienzo,
    // ponemos 'vector' directamente, sin '&'.
    mult_vector(vector, size_vector, number);
    //mult_vector(&vector[0], size_vector, number); También funciona pero no es necesario.

    for(int i = 0; i < size_vector; i++){
        printf("\nEl elemento #%d del vector por %d es: %d", i, number, vector[i]);
    }



    return 0;
}

void mult_vector(int *vector, int size_vector, int number){
    for(int i = 0; i < size_vector; i++){
        *(vector + i) = *(vector + i) * number;
    }
}