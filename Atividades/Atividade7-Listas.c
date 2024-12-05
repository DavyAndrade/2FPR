/*
Dadas 3 (três) listas encadeadas L1, L2, L3, todas do tipo TLista, fazer uma função que crie uma nova lista com todos os
elementos de L1 que estejam em L2, porém não se encontram em L3.
Nota: o tipo TLista consiste exatamente naquele trabalhado em nossas aulas.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int inserir(TLista *L, int num);
int gerarLista(TLista L1, TLista L2, TLista L3, TLista *novaLista);
int exibir(TLista L);

int main()
{
    TLista L1 = NULL, L2 = NULL, L3 = NULL, L4 = NULL;

    // Inserindo elementos em L1
    inserir(&L1, 1);
    inserir(&L1, 2);
    inserir(&L1, 3);

    // Inserindo elementos em L2
    inserir(&L2, 2);
    inserir(&L2, 3);
    inserir(&L2, 4);

    // Inserindo elementos em L3
    inserir(&L3, 1);
    inserir(&L3, 2);

    gerarLista(L1, L2, L3, &L4);
    exibir(L4);
}

int inserir(TLista *L, int numero)
{
    TLista aux;

    aux = malloc(sizeof(TNo));

    if (aux == NULL)
    {
        printf("Falha ao alocar memoria.\n");
        return 0;
    }
    else
    {
        aux->valor = numero;
        aux->prox = *L;
        *L = aux;
        return 1;
    }
}

int gerarLista(TLista L1, TLista L2, TLista L3, TLista *novaLista)
{
    TLista aux1 = L1;

    while (aux1 != NULL)
    {
        TLista aux2 = L2, aux3 = L3;

        int encontrouL2 = 0, encontrouL3 = 0;

        while (aux2 != NULL)
        {
            if (aux2->valor == aux1->valor)
            {
                encontrouL2 = 1;
                break;
            }
            aux2 = aux2->prox;
        }

        while (aux3 != NULL)
        {
            if (aux3->valor == aux1->valor)
            {
                encontrouL3 = 1;
                break;
            }
            aux3 = aux3->prox;
        }

        if (encontrouL2 && !encontrouL3)
        {
            inserir(novaLista, aux1->valor);
        }

        aux1 = aux1->prox;
    }

    return 1;
}

int exibir(TLista L)
{
    TLista aux;
    aux = L;

    if (!aux)
    {
        printf("Lista vazia.\n");
        return 0;
    }
    else
    {
        printf("Elementos da lista:\n");
        while (aux != NULL)
        {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
    }

    return 1;
}