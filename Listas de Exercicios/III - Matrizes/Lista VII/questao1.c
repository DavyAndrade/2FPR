/*
Questão 01:
Considerando a existência de uma matriz de inteiros M, de N N (ou seja, o no de linhas e o no de colunas são iguais a
N), onde N é uma constante, desenvolver uma função que retorne 1 se a seguinte regra for atendida por M (caso contrário,
o valor 0 deverá ser retornado):
 A soma dos elementos da diagonal principal deve ser igual à soma dos elementos que estão acima desta
diagonal, assim como à soma dos elementos abaixo da diagonal.
*/

/*
Exemplo 1:
Para a seguinte matriz, a função retornará 1:
6 3 1 2 6
1 3 5 4 2
3 4 4 2 2
5 9 1 9 3
4 0 2 1 8

Exemplo 2:
Para a seguinte matriz, a função retornará 0:
1 8 5 9 4
2 5 4 6 5
4 1 2 3 6
4 5 5 8 7
4 2 5 6 9
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ordem 5

int diagonal(int N, int matriz[N][N]);
void preencherMatriz(int N, int matriz[N][N]);
void exibirMatriz(int N, int matriz[N][N]);

int main()
{
    int matriz[ordem][ordem];

    preencherMatriz(ordem, matriz);
    exibirMatriz(ordem, matriz);

    if (diagonal(ordem, matriz))
    {
        printf("A matriz respeita a regra.\n");
    }
    else
    {
        printf("As matriz NAO respeita a regra.\n");
    }
}

int diagonal(int N, int matriz[N][N])
{
    int i, j, somaDiagonal = 0, somaSuperior = 0, somaInferior = 0;

    // Somando os elementos da diagonal principal;
    for (i = 0; i < N; i++)
    {
        somaDiagonal += matriz[i][i];
    }

    // Somando os elementos acima da diagonal principal;
    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            somaSuperior += matriz[i][j];
        }
    }

    // Somando os elementos abaixo da diagonal principal;
    for (i = 1; i < N; i++)
    {
        for (j = 0; j < i; j++)
        {
            somaInferior += matriz[i][j];
        }
    }

    // Verificando se as somas são iguais e retornando o resultado;
    if (somaDiagonal == somaSuperior && somaDiagonal == somaInferior)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void preencherMatriz(int N, int matriz[N][N])
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

    printf("\nMatriz [%d][%d]: \n", N, N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}