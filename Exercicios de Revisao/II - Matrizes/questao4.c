/*
Crie um programa que gere uma matriz identidade de ordem N. Uma matriz identidade tem 1 em sua diagonal principal e 0 em todas as outras posições.
*/

#include <stdio.h>

void gerarMatrizIdentidade(int N, int matriz[N][N]);
void exibirMatriz(int N, int matriz[N][N]);

int main()
{
    int ordem = 3;
    int matriz[ordem][ordem];

    gerarMatrizIdentidade(ordem, matriz);
    printf("\nMatriz Identidade de Ordem %d:\n", ordem);
    exibirMatriz(ordem, matriz);
}

void gerarMatrizIdentidade(int N, int matriz[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == j)
            {
                matriz[i][j] = 1;
            }
            else
            {
                matriz[i][j] = 0;
            }
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