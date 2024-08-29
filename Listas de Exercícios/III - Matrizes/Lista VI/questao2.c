/*
QUESTÃO 02:
Desenvolver uma função que, dada uma matriz
Mm×n, determine se um número X se encontra
na linha L da matriz.
*/

#include <stdio.h>

void preencherMatriz(int linha, int coluna, int matriz[linha][coluna]);
int identificarNum(int m, int n, int M[m][n], int L, int X);

int main()
{
    int num, coluna, linha, target;

    printf("Entre com o tamanho da matriz: ");
    scanf("%d %d", &linha, &coluna);

    int matriz[linha][coluna];

    preencherMatriz(linha, coluna, matriz);

    printf("Entre com o numero que deseja encontrar: ");
    scanf("%d", &num);

    printf("Entre com a linha em que deseja encontrar o numero: ");
    scanf("%d", &target);

    if (identificarNum(linha, coluna, matriz, target, num))
    {
        printf("O numero %d foi encontrado na linha %d.", num, target);
    }
    else
    {
        printf("o numero %d nao foi encontrado na linha %d.", num, target);
    }
}

void preencherMatriz(int linha, int coluna, int matriz[linha][coluna])
{
    int i, j;

    printf("Preencha a Matriz de %dx%d\n", linha, coluna);
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("Valor [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

int identificarNum(int m, int n, int M[m][n], int L, int X)
{
    int i, j;

    for (i = 0; i < L; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (M[i][j] == X)
            {
                return 1;
            }
        }
    }
    return 0;
}