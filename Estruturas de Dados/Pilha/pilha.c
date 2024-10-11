#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Celula_Pilha
{
    float elemento;
    struct Celula_Pilha *proximo_ponteiro;
}Celula_Pilha;

typedef struct Pilha
{
    Celula_Pilha *topo;
}Pilha;

bool pilha_vazia(Pilha *pilha)
{
    if(pilha->topo == NULL)
        return true;
    return false;
}

void inicializar_pilha(Pilha *pilha)
{
    pilha->topo = NULL; 
}

void adicionar_elemento_na_pilha(Pilha *pilha, float elemento)
{
    Celula_Pilha *nova_celula_da_pilha = (Celula_Pilha*)malloc(sizeof(Celula_Pilha));
    nova_celula_da_pilha->elemento = elemento;
    nova_celula_da_pilha->proximo_ponteiro = NULL;

    if(pilha_vazia(pilha))
    {
        pilha->topo = nova_celula_da_pilha;
    }
    else
    {
        nova_celula_da_pilha->proximo_ponteiro = pilha->topo;
        pilha->topo = nova_celula_da_pilha;
    }
}

Celula_Pilha* remover_elemento_da_pilha(Pilha *pilha)
{
    if(pilha->topo == NULL)
    {
        printf("Pilha Vazia\n");
    }
    else
    {
        Celula_Pilha *temporario;
        temporario = pilha->topo;
        pilha->topo = pilha->topo->proximo_ponteiro;
        free(temporario);
    }
}

void percorrer_pilha(Pilha *pilha)
{
    Celula_Pilha *temporario = pilha->topo;

    if(pilha_vazia(pilha))
    {
        printf("Pilha Vazia\n");
    }
    else
    {
        while(temporario != NULL)
        {
            printf("Elemento: %.2f", temporario->elemento);
            temporario = temporario->proximo_ponteiro;
        }
    }
}

int main()
{
    int valor, opcao;
    Pilha pilha;

    do
    {
        printf("Menu da Pilha\n1-Empilhar\n2-Desempilhar\n3-Imprimir\n0-Sair\n");
        scanf("%d",&opcao);
        switch(opcao)
        {
            case 1:
                printf("Informe o valor a ser empilhado: ");
                scanf("%d",&valor);
                adicionar_elemento_na_pilha(&pilha, valor);
                break;

            case 2:
                remover_elemento_da_pilha(&pilha);
                break;
            case 3:
                percorrer_pilha(&pilha);
                break;
        } 
    }
    while(opcao != 0);
}