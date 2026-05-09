#include <stdio.h>
#include <stdlib.h>

#define NUM_TEMPORADAS 3

typedef struct {
    int   numero;
    float precio[NUM_TEMPORADAS]; // 0=baja, 1=media, 2=alta
} Habitacion;

/* Prototipos */
Habitacion *leer_habitaciones(int num_hab);
void        mostrar_habitaciones(const Habitacion *hab, int num_hab);
void        mostrar_medias(const Habitacion *hab, int num_hab);

int main(void)
{
    int num_hab = 0;

    printf("\n\n\tAPLICACION QUE MUESTRA EL VALOR MEDIO DE\n"
           "\tLOS PRECIOS EN TEMPORADA BAJA, MEDIA Y ALTA\n"
           "\tPARA UN NUMERO DETERMINADO DE HABITACIONES\n");
    printf("---------------------------------------------------------\n");

    printf("\nIntroduzca el numero de habitaciones: ");
    if (scanf("%d", &num_hab) != 1 || num_hab <= 0) {
        fprintf(stderr, "Numero de habitaciones invalido.\n");
        return EXIT_FAILURE;
    }

    Habitacion *habitaciones = leer_habitaciones(num_hab);
    if (!habitaciones) {
        fprintf(stderr, "Error de memoria.\n");
        return EXIT_FAILURE;
    }

    mostrar_habitaciones(habitaciones, num_hab);
    mostrar_medias(habitaciones, num_hab);

    free(habitaciones);
    return EXIT_SUCCESS;
}

Habitacion *leer_habitaciones(int num_hab)
{
    Habitacion *hab = malloc(num_hab * sizeof(Habitacion));
    if (!hab) return NULL;

    const char *nombres_temporada[NUM_TEMPORADAS] = {"BAJA ", "MEDIA", "ALTA "};

    for (int i = 0; i < num_hab; i++) {
        hab[i].numero = i + 1;
        for (int t = 0; t < NUM_TEMPORADAS; t++) {
            printf("Habitacion #%d - Precio temporada %s: ",
                   hab[i].numero, nombres_temporada[t]);
            scanf("%f", &hab[i].precio[t]);
        }
    }
    return hab;
}

void mostrar_habitaciones(const Habitacion *hab, int num_hab)
{
    printf("\n\nPrecios introducidos por habitacion:\n");
    printf("%-12s %-10s %-10s %-10s\n", "Habitacion", "Baja", "Media", "Alta");

    for (int i = 0; i < num_hab; i++) {
        printf("%-12d %-10.2f %-10.2f %-10.2f\n",
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

    const char *nombres[NUM_TEMPORADAS] = {"BAJA ", "MEDIA", "ALTA "};
    printf("\nMedia de precios:\n");
    for (int t = 0; t < NUM_TEMPORADAS; t++)
        printf("  Temporada %s: %.2f\n", nombres[t], suma[t] / num_hab);
}
