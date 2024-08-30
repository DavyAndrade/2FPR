/*
QUESTÃO 01:
Faça uma função que, dada uma matriz Mm×n de
reais, gere a matriz Mt, sua transposta.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void transposta(int m, int n, float M[m][n], float Mt[n][m]);
void preencherMatriz(int linha, int coluna, float matriz[linha][coluna]);
void exibirMatriz(int linha, int coluna, float matriz[linha][coluna]);

int main()
{
    int colunas, linhas, i, j;

    printf("Entre com o numero de linhas e colunas da matriz: ");
    scanf("%d %d", &linhas, &colunas);

    float matriz[linhas][colunas], matrizTransposta[colunas][linhas];

    preencherMatriz(linhas, colunas, matriz);

    transposta(linhas, colunas, matriz, matrizTransposta);

    printf("\nMatriz Original:\n");
    exibirMatriz(linhas, colunas, matriz);

    printf("\n\nMatriz Transposta:\n");
    exibirMatriz(colunas, linhas, matrizTransposta);
}

void preencherMatriz(int linha, int coluna, float matriz[linha][coluna])
{
    int i, j;

    srand(time(NULL));

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
}

void exibirMatriz(int linha, int coluna, float matriz[linha][coluna])
{
    int i, j;

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void transposta(int m, int n, float M[m][n], float Mt[n][m])
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            Mt[j][i] = M[i][j];
        }
    }
}