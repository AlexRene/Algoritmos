#include<stdio.h>
#include<stdlib.h>
#define TAM 10

int main()
{
    int array[TAM],aux;
    

    for(int i = 0 ; i < TAM ; i++)
    {
        array[i] = rand() % 100 + 1;
    }

    for(int i = 0 ; i < TAM ; i++)
    {
        printf("%d\t",array[i]);
    }

    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - 1; j++) {
            if (array[j] > array[j + 1]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    printf("\n");

    for(int i = 0 ; i < TAM ; i++)
    {
        printf("%d\t",array[i]);
    }
}
