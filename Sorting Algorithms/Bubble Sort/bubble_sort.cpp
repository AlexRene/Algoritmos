#include<iostream>
#include<cstdlib>
using namespace std;
#define TAM 10

int main()
{
    int array[10],aux;

    for(int i = 0 ; i < TAM ; i++)
    {
        array[i] = rand() % 100;
    }

    for(int i = 0 ; i < TAM - 1 ; i++)
    {
        for(int j = 0 ; j < TAM - 1 ; j++)
        {
            if(array[j] > array[j+1])
            {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }
    }

    for(int i = 0 ; i < TAM ; i++)
    {
        cout << array[i] << " ";
    }
}