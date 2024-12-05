#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int enfilar(TLista *F, TLista *U, int numero);
int desenfilar(TLista *F, TLista *U);
int removerDivisores(TLista *F, TLista *U, int N);

int main()
{
    int N = 100; // Número de referência para verificar divisores
    TLista F = NULL, U = NULL;

    // Inserindo elementos na fila F
    enfilar(&F, &U, 1);
    enfilar(&F, &U, 2);
    enfilar(&F, &U, 3);
    enfilar(&F, &U, 4);
    enfilar(&F, &U, 5);

    // Removendo divisores e retornando a quantidade de remoções
    int remocoes = removerDivisores(&F, &U, N);

    // Exibindo a quantidade de remoções
    printf("Quantidade de remocoes: %d\n", remocoes);

    return 0;
}

// Função para adicionar um número na fila
int enfilar(TLista *F, TLista *U, int numero)
{
    TLista aux = malloc(sizeof(TNo));
    if (!aux)
    {
        return 0;
    }
    aux->valor = numero;
    aux->prox = NULL;

    if (*F)
    {
        (*U)->prox = aux;
    }
    else
    {
        *F = aux;
    }

    *U = aux;
    return 1;
}

// Função para remover o primeiro elemento da fila
int desenfilar(TLista *F, TLista *U)
{
    if (!(*F))
    {
        return 0;
    }
    TLista aux = *F;
    *F = (*F)->prox;

    if (!(*F)) // Se a fila ficar vazia, o ponteiro U também deve ser nulo
    {
        *U = NULL;
    }

    free(aux);
    return 1;
}

// Função para remover os divisores de N da fila
int removerDivisores(TLista *F, TLista *U, int N)
{
    int remocoes = 0;
    TLista auxF = *F;   // Fila original
    TLista auxA = NULL; // Fila auxiliar

    // Enquanto houver elementos na fila original
    while (auxF != NULL)
    {
        if (N % auxF->valor == 0) // Verifica se o elemento é divisor de N
        {
            desenfilar(F, U); // Remove o número da fila
            remocoes++;       // Incrementa a quantidade de remoções
        }
        else
        {
            // Se não for divisor, coloca na fila auxiliar
            enfilar(&auxA, &auxA, auxF->valor);
            desenfilar(F, U);
        }

        auxF = *F; // Atualiza o ponteiro para a fila original
    }

    // Agora, adiciona todos os elementos da fila auxiliar de volta à fila original
    while (auxA != NULL)
    {
        enfilar(F, U, auxA->valor);
        desenfilar(&auxA, &auxA);
    }

    return remocoes; // Retorna o número de remoções realizadas
}
