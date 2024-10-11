#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Celula_Fila
{
    float elemento;
    struct Celula_Fila *proximo_ponteiro;
}Celula_Fila;

typedef struct Fila
{
    Celula_Fila *primeiro, *ultimo;
}Fila;

bool fila_vazia(Fila *fila)
{
    if(fila-> primeiro == NULL)
        return true;
    return false;
}

void inicializar_fila(Fila *fila)
{
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

void adicionar_elemento_na_fila(Fila *fila, float elemento)
{
    Celula_Fila *nova_celula_da_fila = (Celula_Fila*)malloc(sizeof(Celula_Fila));
    nova_celula_da_fila->elemento = elemento;
    nova_celula_da_fila->proximo_ponteiro = NULL;

    if(fila_vazia(fila))
    {
        fila->primeiro = nova_celula_da_fila;
        fila->ultimo = nova_celula_da_fila;
    }
    else
    {
        fila->ultimo->proximo_ponteiro = nova_celula_da_fila;
        fila->ultimo = nova_celula_da_fila;
    }
}

Celula_Fila* remover_elemento_na_fila(Fila *fila)
{
    if(fila_vazia(fila))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        Celula_Fila *temporario = fila->primeiro;
        fila->primeiro = fila->primeiro->proximo_ponteiro;
        return temporario;
    }
}

void percorrer_elementos_na_fila(Fila *fila)
{
    if(fila_vazia(fila))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        Celula_Fila *temporario = fila->primeiro;
        while(temporario != NULL)
        {
            printf("Elemento: %.2f\n",temporario->elemento);
            temporario = temporario->proximo_ponteiro;
        }
    }  
}

int main()
{

    Fila fila;
    inicializar_fila(&fila);
    int opcao;
    float valor;

    do
    {
        printf("------------------Bem-Vindo------------------------\n");
        printf("------------------Fila  em C-----------------------\n");
        printf("1-Adicionar Elemento na Fila\n");
        printf("2-Remover um Elemento na Fila\n");
        printf("3-Percorrer os Elementos na Fila\n");
        printf("0-Sair\n\n");

        scanf("%d",&opcao);

        switch(opcao)
        {
            case 1:
                printf("Elemento a ser adicionado na fila: ");
                scanf("%f",&valor);
                adicionar_elemento_na_fila(&fila, valor);
                break;
            case 2:
                remover_elemento_na_fila(&fila);
            case 3:
                percorrer_elementos_na_fila(&fila);
        }
    } while (opcao != 0);
    
    return EXIT_SUCCESS;
}