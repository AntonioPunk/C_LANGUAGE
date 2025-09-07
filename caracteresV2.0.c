#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGH 100

int main()
{
    char vocales[] = {'a', 'e', 'i', 'o', 'u'};
    int recuentoVocales[5] = {0};
    char frase[MAX_LENGH + 1];
    int longitudFrase;

    printf("Introduzca una frase de %d caracteres como maximo: ", MAX_LENGH);
    fgets(frase, sizeof(frase), stdin);
    // Elimina el salto de línea '\n' que fgets podría dejar al final de la cadena
    frase[strcspn(frase, "\n")] = '\0';
    longitudFrase = strlen(frase);

    for(int i = 0; i < longitudFrase; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(tolower(frase[i]) == vocales[j])
            {
                recuentoVocales[j]++;
                // Metemos este break para salir del bucle for y no seguir comparando
                // con el resto de vocales.
                break;
            }
        }
    }

    printf("\nLa frase tiene %d caracteres.", longitudFrase);

    for(int i = 0; i < 5; i++)
    {
        printf("\nNumero de %c = %d", vocales[i], recuentoVocales[i]);
    }

    printf("\n\nHISTOGRAMA DE VOCALES:");
    for(int i = 0; i < 5; i++)
    {
        printf("\nLetra '%c' |", vocales[i]);
        for(int j = 0; j < recuentoVocales[i]; j++)
        {
            printf("#");
        }
    }

    return 0;
}
