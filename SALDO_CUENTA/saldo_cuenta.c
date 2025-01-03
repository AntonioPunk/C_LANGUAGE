#include <stdio.h>
#include <stdlib.h>

int main()

{
    double saldo_cuenta = 15500.65;
    float ingreso;
    printf ("El saldo actual es: %.2lf \n", saldo_cuenta);
    printf ("Introduzca la cantidad a ingresar: ");
    scanf ("%f", &ingreso);
	saldo_cuenta += ingreso;
    printf ("\nEl nuevo saldo de la cuenta es %.2lf",saldo_cuenta);
    return 0;
    
}
