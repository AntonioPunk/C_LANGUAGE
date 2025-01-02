#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

int main(){

    typedef struct
    {
            float diametro;
            float carrera;
    } cil;


    typedef struct
    {
        char identificador_motor[10];
        cil cilindro;
        int numero_cilindros;
        float cilindrada;
    } mot;

    mot motor;

    printf("----CALCULO CILINDRADA MOTOR----");
    printf("\n\nIntroduzca los siguientes datos:\n");
    printf("\nCodigo de motor: ");
    scanf("%s", motor.identificador_motor);
    printf("Diametro del cilindro (mm.): ");
    scanf("%f", &motor.cilindro.diametro);
    printf("Carrera del cilindro (mm.): ");
    scanf("%f", &motor.cilindro.carrera);
    printf("Numero de cilindros: ");
    scanf("%d", &motor.numero_cilindros);

    motor.cilindrada = (motor.numero_cilindros * (motor.cilindro.carrera/10) * M_PI * pow((motor.cilindro.diametro/10),2))/4;

    printf("\nEl motor %s tiene una cilindrada de %.2fcm3.\n\n", motor.identificador_motor, motor.cilindrada);

    system("pause");

    return 0;
}