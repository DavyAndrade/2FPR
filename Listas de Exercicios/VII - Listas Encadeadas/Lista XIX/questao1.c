/*
QUESTÃO 01:
Desenvolver uma função que remova todos os elementos de uma pilha P do tipo TLista e retorne a
quantidade de elementos que existiam em P.
Nota: as regras de manipulação de uma pilha clássica devem ser respeitadas.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int empilhar(TLista *P, int num);
int removerTodosElementos(TLista *P);
int desempilhar(TLista *P, int *numero);

int main()
{
    TLista pilha = NULL;

    int qtdRemocoes;

    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);

    qtdRemocoes = removerTodosElementos(&pilha);

    printf("Quantidade de elementos removidos: %d\n", qtdRemocoes);
}

int removerTodosElementos(TLista *P)
{
    TLista aux;

    int contador = 0;

    if (!(*P))
    {
        return 0;
    }
    else
    {
        while (*P)
        {
            aux = *P;
            *P = (*P)->prox;
            free(aux);
            contador++;
        }

        return contador;
    }
}

int empilhar(TLista *P, int numero)
{
    TLista aux;

    aux = malloc(sizeof(TNo));

    if (!aux)
    {
        return 0;
    }
    else
    {
        aux->valor = numero;

        aux->prox = *P;

        *P = aux;

        return 1;
    }
}