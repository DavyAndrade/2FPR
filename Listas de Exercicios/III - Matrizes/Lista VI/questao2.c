/*
QUESTÃO 02:
Desenvolver uma função que, dada uma matriz
Mm×n, determine se um número X se encontra
na linha L da matriz.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int identificarNum(int m, int n, int M[m][n], int L, int X);
void preencherMatriz(int linha, int coluna, int matriz[linha][coluna]);
void exibirMatriz(int linha, int coluna, int matriz[linha][coluna]);

int main()
{
    int num, coluna, linha, target;

    printf("Entre com o tamanho da matriz: ");
    scanf("%d %d", &linha, &coluna);

    int matriz[linha][coluna];

    preencherMatriz(linha, coluna, matriz);

    printf("Matriz:\n");
    exibirMatriz(linha, coluna, matriz);

    printf("\nEntre com o numero que deseja encontrar: ");
    scanf("%d", &num);

    printf("Entre com a linha em que deseja encontrar o numero: ");
    scanf("%d", &target);

    if (identificarNum(linha, coluna, matriz, target, num))
    {
        printf("\nO numero %d foi encontrado na linha %d.", num, target);
    }
    else
    {
        printf("\nO numero %d nao foi encontrado na linha %d.", num, target);
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
            matriz[i][j] = rand() % 10;
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

int identificarNum(int m, int n, int M[m][n], int L, int X)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (M[L][i] == X)
        {
            return 1;
        }
    }
    return 0;
}
