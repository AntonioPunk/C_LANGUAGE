#include <stdio.h>
#define LONGITUD_MAXIMA 101

int main()
{

    char frase[101];
    int i, contadorCaracteres = 0, contA = 0, contE = 0, contI = 0, contO = 0, contU = 0;

    printf("Introduzca una frase de %d caracteres como máximo: ", LONGITUD_MAXIMA);
    scanf("%100[^\n]", frase);

    while(frase[contadorCaracteres] != '\0')
    {
        contadorCaracteres++;
    }

    for(i = 0; i < contadorCaracteres; i++)
    {
        switch (frase[i])
        {
        case 'a':
        case 'A':
            contA++;
            break;
        case 'e':
        case 'E':
            contE++;
            break;
        case 'i':
        case 'I':
            contI++;
            break;
        case 'o':
        case 'O':
            contO++;
            break;
        case 'u':
        case 'U':
            contU++;
            break;        
        default:
            break;
        }
    }

    printf("\nLa frase es: %s", &frase);    
    printf("\nLa frase consta de %d caracteres.", contadorCaracteres);
    printf("\nLa frase contiene %d letras A.", contA);
    printf("\nLa frase contiene %d letras E.", contE);
    printf("\nLa frase contiene %d letras I.", contI);
    printf("\nLa frase contiene %d letras O.", contO);
    printf("\nLa frase contiene %d letras U.", contU);
    
    printf("\n\nHISTOGRAMA DE VOCALES:");
    printf("\nLetra A: ");
    for(i = 0; i < contA; i++)
    {
        printf("#");
    }
    printf("\nLetra B: ");
    for(i = 0; i < contE; i++)
    {
        printf("#");
    }
    printf("\nLetra I: ");
    for(i = 0; i < contI; i++)
    {
        printf("#");
    }
    printf("\nLetra O: ");
    for(i = 0; i < contO; i++)
    {
        printf("#");
    }
    printf("\nLetra U: ");
    for(i = 0; i < contU; i++)
    {
        printf("#");
    }

    return 0;
}