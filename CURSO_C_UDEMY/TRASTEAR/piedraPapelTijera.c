#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    
    srand(time(NULL));

    int maquina=0, jugador=0, empates=0, victorias=0, derrotas=0, menu=1;

    printf("\n\nJUEGO PIEDRA PAPEL TIJERA");
    
    do {     
        switch (menu)
        {
        case 1:
            printf("\n\nJuguemos!!!");
            maquina= rand() % 3 + 1;
            printf("\n\nELIJE TU ARMA ;) => PIEDRA (1) - PAPEL (2) - TIJERA (3) : " );
            scanf("%d", &jugador);

            if (maquina==1) printf("\nYo elegi PIEDRA");
                else if (maquina==2) printf("\nYo elegi PAPEL");
                    else  printf("\nYo elegi TIJERA");

            if ((jugador==1 && maquina==2) || (jugador==2 && maquina==3) || (jugador==3 && maquina==1)){
                printf(". JAJAJA, has perdido!\n\n");
                derrotas++;
            }
            else if ((jugador==1 && maquina==3) || (jugador==2 && maquina==1) || (jugador==3 && maquina==2)){
                    printf(". Mierda, me has ganado.\n\n");
                    victorias++;
            }
            else if (jugador==maquina){
                printf(", hemos empatado.\n\n");
                empates++;
            }
            else printf(", pero tu eleccion no era valida.\n\n");

            system("pause");
            system("cls");
            break;

        case 2:
            printf("\nMARCADOR PARCIAL\n----------------");
            printf("\nVictorias:\t%d", victorias);
            printf("\nDerrotas:\t%d", derrotas);
            printf("\nEmpates:\t%d\n\n", empates);
            system("pause");
            system("cls");
            break;

        default:
            printf("\nLa opcion escogida no es valida.\n\n");
            system("pause");
            system("cls");
            break;
        }

    printf("\n\n(1) Seguir jugando.");
    printf("\n(2) Ver marcador parcial.");
    printf("\n(3) Salir.");
    printf("\n\nIntroduzca su seleccion: ");
    scanf("%d", &menu);
    system("cls");

    }
    while (menu!=3);

    printf("\nMARCADOR FINAL\n--------------");
    printf("\nVictorias:\t%d", victorias);
    printf("\nDerrotas:\t%d", derrotas);
    printf("\nEmpates:\t%d\n\n", empates);
    system("pause");

    printf("\n\nSaliendo del juego.............");

    return 0;
}