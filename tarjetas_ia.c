#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum {
    MAX_LONGITUD_TARJETA = 19,
    TAMANO_BUFFER = MAX_LONGITUD_TARJETA + 2, /* 19 digitos + '\n' + '\0' */
};

static bool es_longitud_valida(size_t longitud) {
    return longitud == 13 || longitud == 15 || longitud == 16 || longitud == 19;
}

static void limpiar_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}

static bool leer_linea(char *buffer, size_t tamano) {
    if (fgets(buffer, tamano, stdin) == NULL) {
        return false;
    }

    if (strchr(buffer, '\n') == NULL) {
        limpiar_stdin();
    }

    size_t longitud = strlen(buffer);
    if (longitud > 0 && buffer[longitud - 1] == '\n') {
        buffer[longitud - 1] = '\0';
    }

    return true;
}

static bool es_numerico(const char *cadena, size_t longitud) {
    for (size_t i = 0; i < longitud; ++i) {
        if (!isdigit((unsigned char)cadena[i])) {
            return false;
        }
    }
    return true;
}

static bool validar_numero_tarjeta(const char *numero) {
    size_t longitud = strlen(numero);

    if (!es_longitud_valida(longitud)) {
        puts("ERROR: El numero de tarjeta debe tener 13, 15, 16 o 19 digitos.");
        return false;
    }

    if (!es_numerico(numero, longitud)) {
        puts("ERROR: El numero de tarjeta solo puede contener digitos.");
        return false;
    }

    return true;
}

static void convertir_a_digitos(const char *origen, int *destino, size_t cantidad) {
    for (size_t i = 0; i < cantidad; ++i) {
        destino[i] = origen[i] - '0';
    }
}

static void mostrar_tarjeta(const char *numero, size_t cantidad) {
    puts("\nEl numero de tarjeta es:");
    for (size_t i = 0; i < cantidad; ++i) {
        putchar(numero[i]);
        if ((i + 1) % 4 == 0 && i + 1 < cantidad) {
            putchar(' ');
        }
    }
    putchar('\n');
}

static const char *tipo_tarjeta(const char *numero) {
    size_t longitud = strlen(numero);
    int pref2 = (numero[0] - '0') * 10 + (numero[1] - '0');
    int pref3 = pref2 * 10 + (numero[2] - '0');
    int pref4 = pref3 * 10 + (numero[3] - '0');
    int pref6 = pref4 * 100 + (numero[4] - '0') * 10 + (numero[5] - '0');

    if (numero[0] == '4' && (longitud == 13 || longitud == 16 || longitud == 19)) {
        return "Visa";
    }

    if (longitud == 15 && (pref2 == 34 || pref2 == 37)) {
        return "American Express";
    }

    if (longitud == 16 && ((pref2 >= 51 && pref2 <= 55) || (pref4 >= 2221 && pref4 <= 2720))) {
        return "MasterCard";
    }

    if ((longitud == 16 || longitud == 19) &&
        (pref4 == 6011 || pref2 == 65 ||
        (pref3 >= 644 && pref3 <= 649) ||
        (pref6 >= 622126 && pref6 <= 622925))) {
        return "Discover";
    }

    if ((longitud == 16 || longitud == 19) && (pref4 >= 3528 && pref4 <= 3589)) {
        return "JCB";
    }

    if (longitud == 14 && (pref2 == 36 || pref2 == 38 || pref2 == 39 ||
        (pref3 >= 300 && pref3 <= 305))) {
        return "Diners Club";
    }

    return "Desconocido";
}

static bool validar_luhn(const int *digitos, size_t cantidad) {
    int suma = 0;
    bool doble = false;

    for (size_t i = cantidad; i-- > 0;) {
        int valor = digitos[i];
        if (doble) {
            valor *= 2;
            if (valor > 9) {
                valor -= 9;
            }
        }
        suma += valor;
        doble = !doble;
    }

    return (suma % 10) == 0;
}

int main(void) {
    char numero[TAMANO_BUFFER];
    int digitos[MAX_LONGITUD_TARJETA];

    while (true) {
        printf("Introduce el numero de tu tarjeta de credito: ");
        if (!leer_linea(numero, sizeof numero)) {
            puts("ERROR: Entrada invalida.");
            continue;
        }

        if (validar_numero_tarjeta(numero)) {
            break;
        }
    }

    size_t longitud = strlen(numero);
    convertir_a_digitos(numero, digitos, longitud);
    mostrar_tarjeta(numero, longitud);
    printf("Tipo de tarjeta: %s\n", tipo_tarjeta(numero));

    if (validar_luhn(digitos, longitud)) {
        puts("\nEl numero de tarjeta es correcto.");
    } else {
        puts("\nERROR: El numero introducido no se corresponde a una tarjeta valida.");
    }

    return 0;
}
