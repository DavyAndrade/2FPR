/*
Escreva um programa que receba duas matrizes de ordem N x M e calcule a soma dessas matrizes, armazenando o resultado em uma terceira matriz.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void somarMatrizes(int lin, int col, int mat1[lin][col], int mat2[lin][col], int mat3[lin][col]);
void preencherMatriz(int lin, int col, int mat1[lin][col], int mat2[lin][col]);
void exibirMatriz(int lin, int col, int matriz[lin][col]);

int main()
{
    int linhas = 3, colunas = 3;
    int mat1[linhas][colunas], mat2[linhas][colunas], mat3[linhas][colunas];

    preencherMatriz(linhas, colunas, mat1, mat2);
    printf("\nMatriz 1:\n");
    exibirMatriz(linhas, colunas, mat1);

    printf("\nMatriz 2:\n");
    exibirMatriz(linhas, colunas, mat2);

    somarMatrizes(linhas, colunas, mat1, mat2, mat3);
    printf("\nMatriz Resultante:\n");
    exibirMatriz(linhas, colunas, mat3);
}

void somarMatrizes(int lin, int col, int mat1[lin][col], int mat2[lin][col], int mat3[lin][col])
{
    int i, j;

    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void preencherMatriz(int lin, int col, int mat1[lin][col], int mat2[lin][col])
{
    int i, j;

    srand(time(NULL));

    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            mat1[i][j] = rand() % 5;
        }
    }

    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            mat2[i][j] = rand() % 5;
        }
    }
}

void exibirMatriz(int lin, int col, int matriz[lin][col])
{
    int i, j;

    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}