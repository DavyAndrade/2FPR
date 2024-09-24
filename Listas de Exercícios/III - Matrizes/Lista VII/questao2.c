/*
Questão 02:
Dada uma matriz MLxC, onde L e C são constantes, desenvolver uma função que “troque” os elementos de duas colunas
c1 e c2, respeitadas as seguintes regras:
a. A troca só será possível se as colunas c1 e c2 existirem na matriz. Caso existam, a troca será realizada e o valor 1
retornado pela função; por outro lado, 0 será retornado se uma ou as duas colunas forem inválidas;
b. Após a troca, a coluna c2 conterá exatamente os elementos originais da coluna c1, na mesma ordem. Porém, os
valores da coluna c1 serão os originais da c2, na ordem inversa.
*/

/*
Exemplo:
Trocar as colunas 1 e 3 da matriz abaixo:

1 3 5 7 9
4 6 5 8 0
3 4 5 7 8
5 9 1 2 3
7 1 5 3 5
4 0 2 1 5

1 1 5 3 9
4 3 5 6 0
3 2 5 4 8
5 7 1 9 3
7 8 5 1 5
4 7 2 0 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define row 4
#define column 4

int trocarColunas(int c1, int c2, int L, int C, int M[L][C]);
void preencherMatriz(int linha, int coluna, int matriz[linha][coluna]);
void exibirMatriz(int linha, int coluna, int matriz[linha][coluna]);

int main()
{
    int matriz[row][column], coluna1, coluna2;

    preencherMatriz(row, column, matriz);
    printf("\nMatriz Original: ");
    exibirMatriz(row, column, matriz);

    printf("Entre com a primeira coluna: ");
    scanf("%d", &coluna1);

    printf("Entre com a segunda coluna: ");
    scanf("%d", &coluna2);

    if (trocarColunas(coluna1, coluna2, row, column, matriz) == 1)
    {
        printf("Colunas Trocadas com Sucesso!\n");
        printf("\nMatriz com Colunas Trocadas: ");
        exibirMatriz(row, column, matriz);
    }
}

int trocarColunas(int c1, int c2, int L, int C, int M[L][C])
{
    int i, j, vetAux[L];

    if (c1 < 0 || c2 < 0 || c1 >= C || c2 >= C || c1 == c2)
    {
        return 0;
    }

    // Armazenando os valores da Coluna 1 em um vetor auxiliar.
    for (i = 0; i < L; i++)
    {
        vetAux[i] = M[i][c1];
    }

    // Armazenando os valores da Coluna 2 em cada posição da Coluna 1.
    for (i = L - 1, j = 0; j < L; j++, i--)
    {
        M[i][c2] = M[j][c1];
    }

    // Armazenando os valores do vetor auxiliar na Coluna 1.
    for (i = 0; i < L; i++)
    {
        M[i][c1] = vetAux[i];
    }

    return 1;
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