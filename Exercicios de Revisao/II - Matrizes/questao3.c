/*
Escreva uma função que receba uma matriz quadrada de ordem N e retorne sua matriz transposta.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarMatrizTransposta(int N, int matriz[N][N], int transposta[N][N]);
void preencheMatriz(int N, int Matriz[N][N]);
void exibirMatriz(int N, int Matriz[N][N]);

int main()
{
    int ordem = 3;
    int matriz[ordem][ordem];
    int transposta[ordem][ordem];

    // Preenchendo a Matriz
    preencheMatriz(ordem, matriz);
    printf("Matriz Original:\n");
    exibirMatriz(ordem, matriz);

    // Calculando a Matriz Transposta
    gerarMatrizTransposta(ordem, matriz, transposta);
    printf("\nMatriz Transposta:\n");
    exibirMatriz(ordem, transposta);
}

void gerarMatrizTransposta(int N, int matriz[N][N], int transposta[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            transposta[j][i] = matriz[i][j];
        }
    }
}

void preencheMatriz(int N, int matriz[N][N])
{
    int i, j;

    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
}

void exibirMatriz(int N, int matriz[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}