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

#define N 5

int trocarColunas(int coluna1, int coluna2, int ordem, int matriz[ordem][ordem]);
void preencherMatriz(int ordem, int matriz[ordem][ordem]);
void exibirMatriz(int ordem, int matriz[ordem][ordem]);

int main()
{
    int matriz[N][N], c1, c2;

    preencherMatriz(N, matriz);

    printf("Entre com a primeira coluna: ");
    scanf("%d", &c1);

    printf("Entre com a segunda coluna: ");
    scanf("%d", &c2);

    printf("\nMatriz Original: ");
    exibirMatriz(N, matriz);

    trocarColunas(c1, c2, N, matriz);

    printf("\nMatriz com Colunas Trocadas: ");
    exibirMatriz(N, matriz);
}

int trocarColunas(int coluna1, int coluna2, int ordem, int matriz[ordem][ordem])
{
    int i, j;
}

void preencherMatriz(int ordem, int matriz[ordem][ordem])
{
    int i, j;

    srand(time(NULL));

    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
}

void exibirMatriz(int ordem, int matriz[ordem][ordem])
{
    int i, j;

    printf("\nMatriz [%d][%d]: \n", ordem, ordem);
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}