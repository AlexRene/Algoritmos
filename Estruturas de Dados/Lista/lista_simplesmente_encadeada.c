#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Celula_Lista
{
    float elemento;
    struct Celula_Lista *proximo_ponteiro;
}Celula_Lista;

typedef struct Lista
{
    Celula_Lista *primeiro, *ultimo;
}Lista;

bool lista_vazia(Lista* lista)
{
    if(lista->primeiro == NULL)
        return true;
    return false;
}

void inicializar_lista(Lista* lista)
{
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

void adicionar_elemento_na_lista(Lista* lista, float elemento)
{
    Celula_Lista* nova_celula_da_lista = (Celula_Lista*)malloc(sizeof(Celula_Lista));
    nova_celula_da_lista->elemento = elemento;
    nova_celula_da_lista->proximo_ponteiro = NULL;

    if(lista_vazia(lista))
    {
        lista->primeiro = nova_celula_da_lista;
        lista->ultimo = nova_celula_da_lista;
    }
    else
    {
        Celula_Lista *temporario = lista->primeiro;
        lista->primeiro = nova_celula_da_lista;
        lista->primeiro->proximo_ponteiro = temporario;
    }
}

void remover_elemento_da_lista(Lista* lista)
{
    if(lista_vazia(lista))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        if(lista->ultimo == lista->primeiro)
        {
            free(lista->primeiro);
            inicializar_lista(&lista);
        }

        Celula_Lista *temporario = lista->primeiro;

        while (temporario->proximo_ponteiro->proximo_ponteiro != NULL)
        {
            temporario = temporario->proximo_ponteiro;
        }
        free(lista->ultimo);
        lista->ultimo = temporario;
        temporario->proximo_ponteiro = NULL;
    }
}

void percorrer_lista(Lista* lista)
{
    Celula_Lista *temporario = lista->primeiro;

    while(temporario != NULL)
    {
        printf("Elemento: %.2f\n",temporario->elemento);
        temporario = temporario->proximo_ponteiro;
    }
}

int main()
{
    Lista lista;

    int opcao;
    float valor;

    do
    {
        printf("-----------------Fila Encadeada-----------------\n");
        printf("0-Sair\n1-Adicionar\n2-Remover\n3-Percorrer Elementos\n");
        scanf("%d",&opcao);

        switch(opcao)
        {
            case 1:
                printf("Informe o elemento a ser adicionado: ");
                scanf("%f",&valor);
                adicionar_elemento_na_lista(&lista, valor);
                break;
            case 2:
                remover_elemento_da_lista(&lista);
                break;
            case 3:
                percorrer_lista(&lista);
        }
    }
    while(opcao != 0);

    return 0;
}