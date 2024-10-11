#include <stdio.h>
#define TAM 10

int main() {
    int array[TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 456};
    int encontrado = 0; // Variável para indicar se o valor 456 foi encontrado

    for (int i = 0; i < TAM && !encontrado; i++) {
        if (array[i] == 456) {
            printf("%d", array[i]);
            encontrado = 1; // Se o valor 456 foi encontrado, marca a variável como 1
        }
    }

    if (!encontrado) {
        printf("Não tem");
    }

    return 0;
}