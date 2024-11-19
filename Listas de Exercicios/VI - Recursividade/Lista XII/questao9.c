/*
Questão 09:
Desenvolver uma função recursiva que, dado
um vetor V com quant números inteiros,
determine se seus elementos estão dispostos
de maneira a representar uma progressão
aritmética.
*/

#include <stdio.h>

int verificarProgressaoAritmetica(int V[], int n, int i, int atual, int anterior);

int main()
{
    int V[] = {1, 3, 5, 7, 9};
    int tamVetor = sizeof(V) / sizeof(V[0]);

    if (verificarProgressaoAritmetica(V, tamVetor, 1, V[0], V[0]))
    {
        printf("Os elementos do vetor sao uma progressao aritmetica.\n");
    }
    else
    {
        printf("Os elementos do vetor NAO sao uma progressao aritmetica.\n");
    }

    return 0;
}

int verificarProgressaoAritmetica(int V[], int n, int i, int atual, int anterior)
{
    // Caso Base
    if (i == n)
    {
        return 1;
    }
    else // Caso Geral
    {
        if (atual - anterior!= V[i] - V[i - 1])
        {
            return 0;
        }

        return verificarProgressaoAritmetica(V, n, i + 1, V[i], anterior);
    }

    return 1;
}