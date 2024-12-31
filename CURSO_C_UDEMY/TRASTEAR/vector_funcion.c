#include<stdio.h>

float buscarMax(float [], int);
float buscarMin(float [], int);


int main(){

    float temperaturas[]={25.6, 23.2, 45.67, 38.5, 21, 45};
    int tamVectorTemp = sizeof(temperaturas)/4;
    float tempMax = buscarMax(temperaturas, tamVectorTemp);
    printf("La temperatura máxima de las %d registradas es:\t %.2f C\n", tamVectorTemp, tempMax);
    float tempMin = buscarMin(temperaturas, tamVectorTemp);
    printf("La temperatura mímnima de las %d registradas es:\t %.2f C\n", tamVectorTemp, tempMin);

    float humedad[]={40, 35, 67.5, 50.4};
    int tamVectorHumedad = sizeof(humedad)/4;
    float humMax = buscarMax(humedad, tamVectorHumedad);
    printf("La humedad máxima de las %d registradas es:\t %.2f %%\n", tamVectorHumedad, humMax); 
    float humMin = buscarMin(humedad, tamVectorHumedad);
    printf("La humedad mímnima de las %d registradas es:\t %.2f %%\n", tamVectorHumedad, humMin);

    return 0;
}


float buscarMax(float vector[], int i)
    {
        float maxima = vector[0];
        for (int n=1 ; n<i ; n++)
            {
                if (vector[n] > maxima) maxima=vector[n];
            }
        return maxima;
    }

float buscarMin(float vector[], int i)
    {
        float minima = vector[0];
        for (int n=1 ; n<i ; n++)
            {
                if (vector[n] < minima) minima=vector[n];
            }
        return minima;
    }