#include<stdio.h>

#define FILAS 10
#define COLUMNAS 10

void presentarMatriz(char [FILAS][COLUMNAS]);

int main(){

    char matriz[FILAS][COLUMNAS];
	
	int filas, columnas;
    for(filas=0; filas<FILAS; filas++){
        for(columnas=0; columnas<COLUMNAS; columnas++){
            matriz[filas][columnas]='O';
        }
    }

    presentarMatriz(matriz);

    getchar();

    return 0;
}

void presentarMatriz(char m[FILAS][COLUMNAS]){
    int a;
    int b;
	
    for(a=0; a<FILAS; a++){
        printf("\n");
        for(b=0; b<COLUMNAS; b++){
            printf("%c", m[a][b]);
        }
    }
}
