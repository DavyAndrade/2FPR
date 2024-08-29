/*
QUESTÃO 01:
Faça uma função que, dada uma matriz Mm×n de
reais, gere a matriz Mt, sua transposta.
*/

#include <stdio.h>

void preencherMatriz(int linha, int coluna, float matriz[linha][coluna]);
void transposta(int m, int n, float M[m][n], float Mt[n][m]);

int main()
{
    int colunas, linhas, i, j;

    printf("Entre com o numero de linhas e colunas da matriz: ");
    scanf("%d %d", &linhas, &colunas);

    float matriz[linhas][colunas], matrizTransposta[colunas][linhas];

    preencherMatriz(linhas, colunas, matriz);

    transposta(linhas, colunas, matriz, matrizTransposta);

    printf("\nMatriz Transposta Mt[%d][%d]:\n", colunas, linhas);
    for (i = 0; i < colunas; i++)
    {
        for (j = 0; j < linhas; j++)
        {
            printf("%.1f ", matrizTransposta[i][j]);
        }
        printf("\n");
    }
}

void preencherMatriz(int linha, int coluna, float matriz[linha][coluna])
{
    int i, j;

    printf("Preencha a Matriz de %dx%d\n", linha, coluna);
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("Valor [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
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