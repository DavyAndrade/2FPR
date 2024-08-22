/*
QUESTÃO 01:
Desenvolver uma função que determine o
número de ocorrências de um número inteiro x
em um vetor A.
*/

#include <stdio.h>

int numOcorrencias(int vetA[], int tam, int x);

int main()
{
    int vetorInt[5] = {1, 2, 3, 1, 2};
    int valor = 1;
    int quant;

    quant = numOcorrencias(vetorInt, 5, valor);

    printf("Foram encontradas %d ocorrencias de %d no vetor.", quant, valor);
}

int numOcorrencias(int vetA[], int tam, int x)
{
    int i, cont = 0;

    for (i = 0; i < tam; i++)
    {
        if (vetA[i] == x)
        {
            cont++;
        }
    }

    return cont;
}