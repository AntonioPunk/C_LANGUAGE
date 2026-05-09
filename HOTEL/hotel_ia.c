/*
 * hotel_ia.c  –  Precios medios de habitaciones por temporada
 *
 * Características:
 *   - Lectura con fgets + strtol/strtof  (sin riesgo de buffer corrupto)
 *   - Reintentos automáticos con límite (MAX_INTENTOS)
 *   - Detección y descarte de líneas truncadas
 *   - Validación de rangos en todos los campos
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TEMPORADAS 3
#define MAX_HAB        500   /* límite razonable de habitaciones            */
#define BUF_SIZE       64    /* suficiente para cualquier número esperado   */
#define MAX_INTENTOS   5     /* reintentos antes de abortar                 */

/* ──────────────────────────── tipos ───────────────────────────────────── */
typedef struct {
    int   numero;
    float precio[NUM_TEMPORADAS];   /* 0=baja  1=media  2=alta              */
} Habitacion;

/* ──────────────────────────── prototipos ──────────────────────────────── */
static int   leer_entero(const char *prompt, int min, int max);
static float leer_float_positivo(const char *prompt);
static void  drenar_stdin(void);

Habitacion *leer_habitaciones(int num_hab);
void        mostrar_habitaciones(const Habitacion *hab, int num_hab);
void        mostrar_medias(const Habitacion *hab, int num_hab);

/* ══════════════════════════ main ══════════════════════════════════════ */
int main(void)
{
    printf("\n\n\tAPLICACION QUE MUESTRA EL VALOR MEDIO DE\n"
           "\tLOS PRECIOS EN TEMPORADA BAJA, MEDIA Y ALTA\n"
           "\tPARA UN NUMERO DETERMINADO DE HABITACIONES\n");
    printf("---------------------------------------------------------\n");

    int num_hab = leer_entero("\nIntroduzca el numero de habitaciones: ",
                              1, MAX_HAB);

    Habitacion *habitaciones = leer_habitaciones(num_hab);
    if (!habitaciones) {
        fprintf(stderr, "Error: no se pudo reservar memoria.\n");
        return EXIT_FAILURE;
    }

    mostrar_habitaciones(habitaciones, num_hab);
    mostrar_medias(habitaciones, num_hab);

    free(habitaciones);
    return EXIT_SUCCESS;
}

/* ══════════════════════════ helpers de entrada ════════════════════════ */

/*
 * drenar_stdin – descarta todos los caracteres hasta '\n' o EOF.
 * Se usa cuando fgets detecta una línea truncada (sin '\n' en el buffer).
 */
static void drenar_stdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/*
 * leer_entero – lee y valida un entero en [min, max].
 * Reintentos: MAX_INTENTOS.  Si se agotan → exit(EXIT_FAILURE).
 */
static int leer_entero(const char *prompt, int min, int max)
{
    char buf[BUF_SIZE];

    for (int intento = 0; intento < MAX_INTENTOS; intento++) {
        printf("%s", prompt);
        fflush(stdout);

        if (!fgets(buf, sizeof(buf), stdin)) {
            fprintf(stderr, "\nError de lectura o fin de entrada inesperado.\n");
            exit(EXIT_FAILURE);
        }

        /* Línea truncada: el buffer se llenó sin capturar '\n' */
        if (!strchr(buf, '\n') && !feof(stdin)) {
            drenar_stdin();
            fprintf(stderr,
                    "  [!] Entrada demasiado larga. Intentelo de nuevo "
                    "(%d/%d).\n",
                    intento + 1, MAX_INTENTOS);
            continue;
        }

        /* Parseo seguro con strtol */
        char *endptr;
        errno = 0;
        long val = strtol(buf, &endptr, 10);

        /* Avanzar endptr sobre espacios/salto de línea finales */
        while (*endptr == ' ' || *endptr == '\t' ||
               *endptr == '\n' || *endptr == '\r')
            endptr++;

        if (endptr == buf       /* no se leyó ningún dígito */
            || *endptr != '\0'  /* sobran caracteres no blancos */
            || errno == ERANGE  /* desbordamiento de long */
            || val < min
            || val > max) {
            fprintf(stderr,
                    "  [!] Valor invalido. Introduzca un entero entre "
                    "%d y %d (%d/%d).\n",
                    min, max, intento + 1, MAX_INTENTOS);
            continue;
        }

        return (int)val;
    }

    fprintf(stderr,
            "Demasiados intentos fallidos (%d). Abortando.\n", MAX_INTENTOS);
    exit(EXIT_FAILURE);
}

/*
 * leer_float_positivo – lee y valida un float >= 0.
 * Reintentos: MAX_INTENTOS.  Si se agotan → exit(EXIT_FAILURE).
 */
static float leer_float_positivo(const char *prompt)
{
    char buf[BUF_SIZE];

    for (int intento = 0; intento < MAX_INTENTOS; intento++) {
        printf("%s", prompt);
        fflush(stdout);

        if (!fgets(buf, sizeof(buf), stdin)) {
            fprintf(stderr, "\nError de lectura o fin de entrada inesperado.\n");
            exit(EXIT_FAILURE);
        }

        if (!strchr(buf, '\n') && !feof(stdin)) {
            drenar_stdin();
            fprintf(stderr,
                    "  [!] Entrada demasiado larga. Intentelo de nuevo "
                    "(%d/%d).\n",
                    intento + 1, MAX_INTENTOS);
            continue;
        }

        char *endptr;
        errno = 0;
        float val = strtof(buf, &endptr);

        while (*endptr == ' ' || *endptr == '\t' ||
               *endptr == '\n' || *endptr == '\r')
            endptr++;

        if (endptr == buf
            || *endptr != '\0'
            || errno == ERANGE
            || val < 0.0f) {
            fprintf(stderr,
                    "  [!] Valor invalido. Introduzca un precio >= 0 "
                    "(%d/%d).\n",
                    intento + 1, MAX_INTENTOS);
            continue;
        }

        return val;
    }

    fprintf(stderr,
            "Demasiados intentos fallidos (%d). Abortando.\n", MAX_INTENTOS);
    exit(EXIT_FAILURE);
}

/* ══════════════════════════ lógica principal ══════════════════════════ */

Habitacion *leer_habitaciones(int num_hab)
{
    Habitacion *hab = malloc((size_t)num_hab * sizeof(Habitacion));
    if (!hab) return NULL;

    const char *nombre_temporada[NUM_TEMPORADAS] = {"BAJA ", "MEDIA", "ALTA "};
    char prompt[64];

    for (int i = 0; i < num_hab; i++) {
        hab[i].numero = i + 1;
        printf("\n--- Habitacion #%d ---\n", hab[i].numero);
        for (int t = 0; t < NUM_TEMPORADAS; t++) {
            snprintf(prompt, sizeof(prompt),
                     "  Precio temporada %s: ", nombre_temporada[t]);
            hab[i].precio[t] = leer_float_positivo(prompt);
        }
    }
    return hab;
}

void mostrar_habitaciones(const Habitacion *hab, int num_hab)
{
    printf("\n\nPrecios introducidos por habitacion:\n");
    printf("%-12s %-12s %-12s %-12s\n",
           "Habitacion", "Baja", "Media", "Alta");
    printf("%-12s %-12s %-12s %-12s\n",
           "----------", "--------", "--------", "--------");

    for (int i = 0; i < num_hab; i++) {
        printf("%-12d %-12.2f %-12.2f %-12.2f\n",
               hab[i].numero,
               hab[i].precio[0],
               hab[i].precio[1],
               hab[i].precio[2]);
    }
}

void mostrar_medias(const Habitacion *hab, int num_hab)
{
    float suma[NUM_TEMPORADAS] = {0};

    for (int i = 0; i < num_hab; i++)
        for (int t = 0; t < NUM_TEMPORADAS; t++)
            suma[t] += hab[i].precio[t];

    const char *nombre[NUM_TEMPORADAS] = {"BAJA ", "MEDIA", "ALTA "};
    printf("\nMedia de precios por temporada:\n");
    for (int t = 0; t < NUM_TEMPORADAS; t++)
        printf("  Temporada %s: %.2f\n", nombre[t], suma[t] / num_hab);
}
