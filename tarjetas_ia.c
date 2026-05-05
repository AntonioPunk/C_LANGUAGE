// Header files for character classification, I/O operations, string manipulation, and boolean types
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Constants for card number validation
enum {
    MAX_LONGITUD_TARJETA = 19,                           // Maximum card number length
    TAMANO_BUFFER = MAX_LONGITUD_TARJETA + 2,           // Buffer size: 19 digits + newline + null terminator
};

// Validates if the card number length is acceptable (13, 15, 16, or 19 digits)
static bool es_longitud_valida(size_t longitud) {
    return longitud == 13 || longitud == 15 || longitud == 16 || longitud == 19;
}

// Clears any remaining characters in the input buffer (stdin)
static void limpiar_stdin(void) {
    int c;
    // Consume characters until newline or end of file
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}

// Reads a line from input into buffer, handling newline removal
static bool leer_linea(char *buffer, size_t tamano) {
    // Attempt to read from input
    if (fgets(buffer, tamano, stdin) == NULL) {
        return false;
    }

    // If newline wasn't found, clear the remaining input
    if (strchr(buffer, '\n') == NULL) {
        limpiar_stdin();
    }

    // Remove the newline character
    size_t longitud = strlen(buffer);
    if (longitud > 0 && buffer[longitud - 1] == '\n') {
        buffer[longitud - 1] = '\0';
    }

    return true;
}

// Checks if all characters in the string are digits
static bool es_numerico(const char *cadena, size_t longitud) {
    for (size_t i = 0; i < longitud; ++i) {
        // Return false if any character is not a digit
        if (!isdigit((unsigned char)cadena[i])) {
            return false;
        }
    }
    return true;
}

// Validates card number: checks length and ensures all characters are digits
static bool validar_numero_tarjeta(const char *numero) {
    size_t longitud = strlen(numero);

    // Check if length is valid
    if (!es_longitud_valida(longitud)) {
        puts("ERROR: El numero de tarjeta debe tener 13, 15, 16 o 19 digitos.");
        return false;
    }

    // Check if all characters are numeric
    if (!es_numerico(numero, longitud)) {
        puts("ERROR: El numero de tarjeta solo puede contener digitos.");
        return false;
    }

    return true;
}

// Converts a string of digit characters to an array of integers
static void convertir_a_digitos(const char *origen, int *destino, size_t cantidad) {
    for (size_t i = 0; i < cantidad; ++i) {
        // Convert ASCII digit character to integer
        destino[i] = origen[i] - '0';
    }
}

// Displays the card number formatted in groups of 4 digits separated by spaces
static void mostrar_tarjeta(const char *numero, size_t cantidad) {
    puts("\nEl numero de tarjeta es:");
    for (size_t i = 0; i < cantidad; ++i) {
        putchar(numero[i]);
        // Add space after every 4 digits (except at the end)
        if ((i + 1) % 4 == 0 && i + 1 < cantidad) {
            putchar(' ');
        }
    }
    putchar('\n');
}

// Identifies the card type based on prefixes and length according to IIN standards
static const char *tipo_tarjeta(const char *numero) {
    size_t longitud = strlen(numero);
    // Extract prefixes of different lengths for IIN identification
    int pref2 = (numero[0] - '0') * 10 + (numero[1] - '0');        // First 2 digits
    int pref3 = pref2 * 10 + (numero[2] - '0');                   // First 3 digits
    int pref4 = pref3 * 10 + (numero[3] - '0');                   // First 4 digits
    int pref6 = pref4 * 100 + (numero[4] - '0') * 10 + (numero[5] - '0'); // First 6 digits

    // Visa: starts with 4, length 13, 16, or 19
    if (numero[0] == '4' && (longitud == 13 || longitud == 16 || longitud == 19)) {
        return "Visa";
    }

    // American Express: starts with 34 or 37, length 15
    if (longitud == 15 && (pref2 == 34 || pref2 == 37)) {
        return "American Express";
    }

    // MasterCard: length 16, starts with 51-55 or 2221-2720
    if (longitud == 16 && ((pref2 >= 51 && pref2 <= 55) || (pref4 >= 2221 && pref4 <= 2720))) {
        return "MasterCard";
    }

    // Discover: length 16 or 19, starts with 6011, 65, 644-649, or 622126-622925
    if ((longitud == 16 || longitud == 19) &&
        (pref4 == 6011 || pref2 == 65 ||
        (pref3 >= 644 && pref3 <= 649) ||
        (pref6 >= 622126 && pref6 <= 622925))) {
        return "Discover";
    }

    // JCB: length 16 or 19, starts with 3528-3589
    if ((longitud == 16 || longitud == 19) && (pref4 >= 3528 && pref4 <= 3589)) {
        return "JCB";
    }

    // Diners Club: length 14, starts with 36, 38, 39, or 300-305
    if (longitud == 14 && (pref2 == 36 || pref2 == 38 || pref2 == 39 ||
        (pref3 >= 300 && pref3 <= 305))) {
        return "Diners Club";
    }

    return "Desconocido";
}

// Validates card number using the Luhn algorithm
static bool validar_luhn(const int *digitos, size_t cantidad) {
    int suma = 0;
    bool doble = false;

    // Process digits from right to left
    for (size_t i = cantidad; i-- > 0;) {
        int valor = digitos[i];
        // Double every other digit (from the right)
        if (doble) {
            valor *= 2;
            // If result is greater than 9, subtract 9
            if (valor > 9) {
                valor -= 9;
            }
        }
        suma += valor;
        doble = !doble;
    }

    // Card is valid if sum is divisible by 10
    return (suma % 10) == 0;
}

// Main function: orchestrates card validation process
int main(void) {
    char numero[TAMANO_BUFFER];
    int digitos[MAX_LONGITUD_TARJETA];

    // Repeatedly request card number until valid input is received
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

    // Get card number length and convert to digit array
    size_t longitud = strlen(numero);
    convertir_a_digitos(numero, digitos, longitud);
    
    // Display the card number and identify its type
    mostrar_tarjeta(numero, longitud);
    printf("Tipo de tarjeta: %s\n", tipo_tarjeta(numero));

    // Validate using the Luhn algorithm and display result
    if (validar_luhn(digitos, longitud)) {
        puts("\nEl numero de tarjeta es correcto.");
    } else {
        puts("\nERROR: El numero introducido no se corresponde a una tarjeta valida.");
    }

    return 0;
}
