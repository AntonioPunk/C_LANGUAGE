#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LONGITUD_TARJETA 16
#define TAMANO_BUFFER    20

/**
 * es_numerico - Verifica si todos los caracteres de una cadena son dígitos
 * @cadena: Puntero a la cadena a verificar
 * @longitud: Número de caracteres a analizar
 * 
 * Retorna: true si todos son dígitos numéricos, false en caso contrario
 * 
 * Comprobación carácter a carácter buscando valores fuera del rango '0'-'9'
 */
bool es_numerico(const char *cadena, size_t longitud) {
    for (size_t i = 0; i < longitud; i++) {
        if (cadena[i] < '0' || cadena[i] > '9') {
            return false;
        }
    }
    return true;
}

/**
 * leer_tarjeta - Solicita y valida el número de tarjeta del usuario
 * @buffer: Array donde se almacenará la entrada
 * @tamano: Tamaño máximo del buffer (incluyendo terminador nulo)
 * 
 * Retorna: true si la entrada es válida, false en caso contrario
 * 
 * Proceso:
 * 1. Solicita entrada mediante fgets (previene buffer overflow)
 * 2. Limpia stdin si la entrada excede el buffer
 * 3. Normaliza eliminando salto de línea
 * 4. Valida longitud exacta de 16 caracteres
 * 5. Verifica que sean únicamente dígitos
 */
bool leer_tarjeta(char *buffer, size_t tamano) {
    size_t len;
    bool es_valido = true;

    printf("Introduce el numero de tu tarjeta de credito: ");
    fgets(buffer, tamano, stdin);

    /**
     * Si fgets no encuentra '\n', significa que la entrada
     * excedió el tamaño del buffer. Limpiamos stdin para evitar
     * que los caracteres restantes interfieran en próximas lecturas.
     */
    if (strchr(buffer, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    len = strlen(buffer);

    /**
     * Normalización: eliminamos el salto de línea leftover de fgets
     * y ajustamos la longitud real de la cadena.
     */
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }

    /**
     * Validación de longitud: el número de tarjeta debe ser
     * exactamente 16 dígitos.
     */
    if (len != LONGITUD_TARJETA) {
        printf("ERROR: El numero introducido debe tener %d caracteres.\n", LONGITUD_TARJETA);
        es_valido = false;
    }

    /**
     * Validación de contenido: verificamos que todos los caracteres
     * sean dígitos numéricos.
     */
    if (es_valido && !es_numerico(buffer, len)) {
        printf("ERROR: Los caracteres han de ser numericos.\n");
        es_valido = false;
    }

    return es_valido;
}

/**
 * convertir_a_digitos - Convierte caracteres ASCII a valores enteros
 * @origen: Cadena con caracteres numéricos ('0'-'9')
 * @destino: Array de enteros donde se almacenan los dígitos
 * @cantidad: Número de caracteres a convertir
 * 
 * Conversión mediante resta del código ASCII de '0' (48).
 * Ejemplo: '5' - '0' = 53 - 48 = 5
 */
void convertir_a_digitos(const char *origen, int *destino, size_t cantidad) {
    for (size_t i = 0; i < cantidad; i++) {
        destino[i] = origen[i] - '0';
    }
}

/**
 * mostrar_tarjeta - Imprime el número de tarjeta formateado
 * @digitos: Array de dígitos a mostrar
 * @cantidad: Total de dígitos
 * 
 * Formato de salida: XXXX XXXX XXXX XXXX (grupos de 4)
 */
void mostrar_tarjeta(const int *digitos, size_t cantidad) {
    printf("\nEl numero de tarjeta es: ");
    for (size_t i = 0; i < cantidad; i++) {
        printf("%d", digitos[i]);
        if (i == 3 || i == 7 || i == 11) {
            printf(" ");
        }
    }
    printf("\n");
}

/**
 * aplicar_luhn - Aplica el algoritmo de Luhn al array de dígitos
 * @digitos: Array de dígitos a modificar (in-place)
 * @cantidad: Total de dígitos
 * 
 * Algoritmo:
 * 1. Identificar posiciones pares (0, 2, 4, ..., n-2)
 * 2. Duplicar el valor de cada posición par
 * 3. Si el resultado excede 9, restar 9 (equivalente a sumar dígitos)
 *    Ejemplo: 7*2=14 -> 14-9=5 -> 1+4=5 (ambos métodos son equivalentes)
 */
void aplicar_luhn(int *digitos, size_t cantidad) {
    for (size_t i = 0; i <= cantidad - 2; i += 2) {
        digitos[i] *= 2;
        if (digitos[i] > 9) {
            digitos[i] -= 9;
        }
    }
}

/**
 * verificar_tarjeta - Verifica la validez mediante algoritmo de Luhn
 * @digitos: Array de dígitos a verificar
 * @cantidad: Total de dígitos
 * 
 * Retorna: true si el número es válido según Luhn, false en caso contrario
 * 
 * Criterio: la suma total debe ser múltiplo de 10 (suma % 10 == 0)
 */
bool verificar_tarjeta(const int *digitos, size_t cantidad) {
    int suma_total = 0;

    for (size_t i = 0; i < cantidad; i++) {
        suma_total += digitos[i];
    }

    return (suma_total % 10 == 0);
}

/**
 * main - Punto de entrada del programa
 * 
 * Flujo de ejecución:
 * 1. Declarar variables y buffers necesarios
 * 2. Solicitar número de tarjeta validado
 * 3. Convertir string a array de dígitos
 * 4. Mostrar número formateado
 * 5. Aplicar algoritmo de Luhn
 * 6. Verificar y mostrar resultado
 */
int main() {
    char numero_str[TAMANO_BUFFER];
    int digitos[LONGITUD_TARJETA];

    /**
     * Bucle de validación: repetimos hasta obtener una entrada válida.
     * Si leer_tarjeta() retorna false, continuamos pedindo datos.
     */
    do {
        if (!leer_tarjeta(numero_str, TAMANO_BUFFER)) {
            continue;
        }
        break;
    } while (true);

    /**
     * Conversión: transformamos el string en array de enteros.
     */
    convertir_a_digitos(numero_str, digitos, LONGITUD_TARJETA);

    /**
     * Presentación: imprimimos el número formateado en grupos de 4.
     */
    mostrar_tarjeta(digitos, LONGITUD_TARJETA);

    /**
     * Procesamiento: aplicamos el algoritmo de Luhn.
     * Modifica el array original multiplicando posiciones pares.
     */
    aplicar_luhn(digitos, LONGITUD_TARJETA);

    /**
     * Verificación final: validamos según el algoritmo.
     */
    if (verificar_tarjeta(digitos, LONGITUD_TARJETA)) {
        printf("\nEl numero de tarjeta es correcto.\n");
    } else {
        printf("\nERROR: El numero introducido no se corresponde a una tarjeta valida.\n");
    }

    return 0;
}