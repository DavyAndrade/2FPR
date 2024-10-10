/*
Desenvolva um programa que leia duas matrizes A (N x M) e B (M x P), e calcule a multiplicação das duas matrizes, gerando uma matriz C (N x P).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 2
#define P 4

void multiplicarMatrizes(int n, int m, int p, int matrizA[n][m], int matrizB[m][p], int matriz[n][p]);
void preencherMatriz(int linha, int coluna, int matriz[linha][coluna]);
void exibirMatriz(int linha, int coluna, int matriz[linha][coluna]);

int main()
{
    int matrizA[N][M];
    int matrizB[M][P];
    int matrizC[N][P] = {0};

    // Preenche as matrizes A e B
    preencherMatriz(N, M, matrizA);
    printf("\nMatriz A:\n");
    exibirMatriz(N, M, matrizA);

    preencherMatriz(M, P, matrizB);
    printf("\nMatriz B:\n");
    exibirMatriz(M, P, matrizB);

    // Calcula a multiplicação das matrizes
    multiplicarMatrizes(N, M, P, matrizA, matrizB, matrizC);

    printf("\nMatriz C:\n");
    exibirMatriz(N, P, matrizC);

    return 0;
}

void multiplicarMatrizes(int n, int m, int p, int matrizA[n][m], int matrizB[m][p], int matrizC[n][p])
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
        {
            for (k = 0; k < m; k++)
            {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void preencherMatriz(int linha, int coluna, int matriz[linha][coluna])
{
    int i, j;

    srand(time(NULL));

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            matriz[i][j] = rand() % 3;
        }
    }
}

void exibirMatriz(int linha, int coluna, int matriz[linha][coluna])
{
    int i, j;

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}