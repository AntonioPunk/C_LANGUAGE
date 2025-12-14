#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {

    char texto_tarjeta[20];
    int numero_tarjeta[16], i, decenas, unidades, sumatorio_array = 0;
    bool valido;
    size_t len;

    do {
        // Tomamos el código de la tarjeta como arreglo de caracteres (string)
        // con fgets para poder limitar la longitud del array y evitar desbordamiento de buffer
        valido = true;
        printf("Introduce el número de tu tarjeta de credito: ");
        fgets(texto_tarjeta, sizeof(texto_tarjeta), stdin);
        
        // Si la entrada supera la capacidad del array -> vaciar stdin
        // Comprobamos si \n está dentro del array, si NO lo está es que la cadena
        // supera la longitud de éste. En ese caso vaciamos el buffer de stdin para que su contenido
        // no interfiera en próximos ciclos o capturas de entrada.
        if (strchr(texto_tarjeta, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        
        // Obtenemos la longitud de la cadena introducida.
        len = strlen(texto_tarjeta);

        // Cambiamos '\n' por '\0' para ontener una cadena normalizada sin salto de línea.
        // Recordemos que 'fgets' guarda la cadena y añade al final '\n\0'
        // También restamos 1 unidad a 'len' para obtener el tamaño real de la cadena de
        // caracteres introducida, sin '\0'.
        if(len > 0 && texto_tarjeta[len - 1] == '\n'){
            texto_tarjeta[len - 1] = '\0';
            len--;
        }

        // Comprobamos que la cadena conste de 16 caracteres, si no cumple esa condición
        // mostramos mensaje de error y cambiamos 'valido' a 'false' para que no continue
        // el resto de comprobaciones y repita el ciclo "do while".
        if(len != 16){
            printf("ERROR: El número introducido debe tener 16 caracteres.\n");
            valido = false;
        }

        // Si se cumplen las anteriores condiciones (nótese el condicional '&& valido' dentro del 'for'),
        // comprobamos que los caracteres sean numéricos. Si no lo son mostramos un mensaje de ERROR y
        // cambiamos 'valido' a 'false' para repetir el bucle "do while".
        for(i = 0; i < len && valido; i++){
            if(texto_tarjeta[i] < '0' || texto_tarjeta[i] > '9'){
                printf("ERROR: Los caracteres han de ser numéricos.\n");
                valido = false;
                break;
            }
        }
    } while(valido == false);

    // Guardamos el array de caracteres en el array de enteros haciendo la conversión (-48).
    for(i = 0; i < 16; i++){
        numero_tarjeta[i] = texto_tarjeta[i] - 48;
    }

    // Mostramos el código de la tarjeta formateado a grupos de 4 dígitos.
    printf("\nEl número de tarjeta es: ");
    for(i = 0; i < 16; i++){
        printf("%d", numero_tarjeta[i]);
        if(i == 3 || i == 7 || i == 11){
            printf(" ");
        }
    }
    printf("\n");

    // Comenzamos a aplicar el algoritmo de Luhn al array:
    // Primero: multiplamos por 2 las posiciones pares del array,
    // si el resultado es superior a 9 adjudicamos a esa posición del array
    // la suma de la unidad y la decena (nótese que la decena nunca va a superar 10, por tanto
    // nos basta con sumar siempre 1).
    for (i = 0; i <= 14; i += 2){
        numero_tarjeta[i] = numero_tarjeta[i] * 2;
        if (numero_tarjeta[i] > 9){
            unidades = numero_tarjeta[i] % 10;
            numero_tarjeta[i] = unidades + 1;
        }
    }

    // Hacemos el sumatorio de todas las posiciones del array ya modidificado.
    for (i = 0; i < 16; i++){
        sumatorio_array += numero_tarjeta[i];
    }

    // Verificamos la condición para que se cumpla el algoritmo: el sumatorio
    // ha de ser múltiplo de 10.
    if (sumatorio_array % 10 == 0){
        printf("\nEl número de tarjeta es correcto.\n");
    }
    else {
        printf("\nERROR: El número introducido no se corresponde a una tarjeta válida.\n\n");
    }
    
    return 0;
}