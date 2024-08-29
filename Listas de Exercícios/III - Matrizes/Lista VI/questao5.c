/*
QUESTÃO 05:
Implementar uma função que, dada uma matriz
Mm×n, gere um vetor V de tamanho n, onde
cada elemento do vetor consiste na soma dos
elementos de uma coluna de M. Ou seja, o
elemento V[0] consiste na soma dos elementos
da primeira coluna de M, o elemento V[1]
consiste na soma dos elementos da segunda
coluna de M, e assim por diante.
*/

#include <stdio.h>

void preencherMatriz(int linha, int coluna, int matriz[linha][coluna]);
void exibirMatriz(int linha, int coluna, int matriz[linha][coluna]);
void somaColunas(int m, int n, int M[m][n], int V[]);

int main()
{
    int linhas, colunas, i;

    printf("Entre com o numero de linhas e colunas da matriz: ");
    scanf("%d %d", &linhas, &colunas);

    int matriz[linhas][colunas];
    int vet[colunas];

    preencherMatriz(linhas, colunas, matriz);
    exibirMatriz(linhas, colunas, matriz);

    somaColunas(linhas, colunas, matriz, vet);
    for (i = 0; i < colunas; i++)
    {
        printf("Soma da Coluna %d: %d\n", i + 1, vet[i]);
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
            printf("Insira o Valor [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void exibirMatriz(int linha, int coluna, int matriz[linha][coluna])
{
    int i, j;

    printf("\nMatriz [%d][%d]: \n", linha, coluna);
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void somaColunas(int m, int n, int M[m][n], int V[])
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        V[i] = 0;

        for (j = 0; j < n; j++)
        {
            V[i] += M[j][i]; // linha, coluna
        }
    }
}