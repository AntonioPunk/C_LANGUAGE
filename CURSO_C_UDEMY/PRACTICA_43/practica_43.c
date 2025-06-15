#include <stdio.h>
#include <stdlib.h>

void multFunc(int *, int, int);

int main(){

    int vector[] = {2, 4, 6, 8, 10};
    int lengthVector = (sizeof(vector) / sizeof(vector[0]));
    int number = 5;

    multFunc(vector, lengthVector, number);
    
    for(int i = 0; i < lengthVector; i++){
        printf("%d ", vector[i]);
    }

    return 0;
}

void multFunc(int *vector, int length, int number){
    for (int i = 0; i < length; i ++){
        vector[i] *= number;
    }
}