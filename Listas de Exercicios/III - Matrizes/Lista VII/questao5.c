/*
Questão 05:
Desenvolver uma função que receba duas matrizes de inteiros, ambas de ordem 10, com as seguintes características:
a. M1: matriz contendo números inteiros quaisquer;
b. M2: matriz contendo apenas os valores 0 ou 1.
Desenvolver uma função que a partir destas matrizes gere a matriz M3, também de ordem 10, cujos elementos são
definidos da seguinte forma:
M2ij = 0 → M3ij = M1ij
M2ij = 1 → M3ij = soma dos elementos da linha i com os da coluna j da matriz.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ordem 5

void preencherMatriz(int M1[ordem][ordem], int M2[ordem][ordem]);
void exibirMatriz(int matriz[ordem][ordem]);
void preencherM3(int M1[ordem][ordem], int M2[ordem][ordem], int M3[ordem][ordem]);

int main()
{
    int M1[ordem][ordem], M2[ordem][ordem], M3[ordem][ordem];
    preencherMatriz(M1, M2);

    printf("\nMatriz 1:\n");
    exibirMatriz(M1);

    printf("\nMatriz 2:\n");
    exibirMatriz(M2);

    preencherM3(M1, M2, M3);

    printf("\nMatriz 3:\n");
    exibirMatriz(M3);
}

void preencherM3(int M1[ordem][ordem], int M2[ordem][ordem], int M3[ordem][ordem])
{
    int i, j;

    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            if (M2[i][j] == 0)
            {
                M3[i][j] = M1[i][j];
            }
            else
            {
                M3[i][j] = M1[i][0] + M1[0][j];
            }
        }
    }
}

void preencherMatriz(int M1[ordem][ordem], int M2[ordem][ordem])
{
    int i, j;

    srand(time(NULL));

    // Preenchendo a Matriz 1
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            M1[i][j] = (rand() % 10) + 1;
        }
    }

    // Preenchendo a Matriz 2
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            M2[i][j] = rand() % 2;
        }
    }
}

void exibirMatriz(int matriz[ordem][ordem])
{
    int i, j;

    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}