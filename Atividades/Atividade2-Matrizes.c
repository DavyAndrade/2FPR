/*
Atividade 2 – Matrizes
[2024/2]

Implementar uma função que, dadas uma matriz M de inteiros (com lin linhas e col colunas) e uma linha L,
desloque todos os elementos da linha L para a última linha da matriz. Para que isso ocorra, 
os elementos das linhas L+1 à última devem ser copiados para a linha anterior.
Exemplo:

1 2 4 8 6 2 0 3 4 6
9 7 4 0 3 1 0 9 5 4
8 8 4 1 2 0 1 3 6 9
4 7 2 1 5 4 8 9 6 3
2 1 2 4 0 1 0 2 5 7

1 2 4 8 6 2 0 3 4 6
8 8 4 1 2 0 1 3 6 9
4 7 2 1 5 4 8 9 6 3
2 1 2 4 0 1 0 2 5 7
9 7 4 0 3 1 0 9 5 4

Nota: se a linha L não existir na matriz, nada será realizado e o valor 0 retornado
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int moverLinha(int linha, int coluna, int matriz[linha][coluna], int row);
void preencherMatriz(int linha, int coluna, int matriz[linha][coluna]);
void exibirMatriz(int linha, int coluna, int matriz[linha][coluna]);

int main()
{
    int linha, coluna, target;

    printf("Entre com o numero de linhas e colunas: ");
    scanf("%d %d", &linha, &coluna);

    int matriz[linha][coluna];

    preencherMatriz(linha, coluna, matriz);
    printf("\nMatriz Original: \n");
    exibirMatriz(linha, coluna, matriz);

    printf("Escolha uma linha para mover: ");
    scanf("%d", &target);

    moverLinha(linha, coluna, matriz, target);
    printf("\nMatriz Movida: \n");
    exibirMatriz(linha, coluna, matriz);
}

int moverLinha(int linha, int coluna, int matriz[linha][coluna], int row)
{
    int i, j;
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