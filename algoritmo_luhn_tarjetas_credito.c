#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {

    char texto_tarjeta[20];
    int numero_tarjeta[16], i;
    bool valido;
    size_t len;

    do {
        valido = true;
        printf("Introduce el número de tu tarjeta de credito: ");
        fgets(texto_tarjeta, sizeof(texto_tarjeta), stdin);
        
        // Si la entrada supera la capacidad del array -> vaciar stdin
        if (strchr(texto_tarjeta, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        len = strlen(texto_tarjeta);

        if(len > 0 && texto_tarjeta[len - 1] == '\n'){
            texto_tarjeta[len - 1] = '\0';
            len--;
        }

        if(len != 16){
            printf("ERROR: El número introducido debe tener 16 caracteres.\n");
            valido = false;
        }

        for(size_t i = 0; i < len && valido; i++){
            if(texto_tarjeta[i] < '0' || texto_tarjeta[i] > '9'){
                printf("ERROR: Los caracteres han de ser numéricos.");
                valido = false;
                break;
            }
        }
    } while(valido == false);

    for(i = 0; i < 16; i++){
        numero_tarjeta[i] = texto_tarjeta[i] - 48;
    }
    printf("\nEl número de tarjeta es: ");
    for(i = 0; i < 16; i++){
        printf("%d", numero_tarjeta[i]);
        if(i == 3 || i == 7 || i == 11){
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}