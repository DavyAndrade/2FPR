/*
QUESTÃO 04:
Fazer uma função que, dada uma matriz Mn×n,
determine se ela é simétrica.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherMatriz(int ordem, int matriz[ordem][ordem]);
int matrizSimetrica(int ordem, int matriz[ordem][ordem]);

int main()
{
    int ordem;

    printf("Entre com a ordem da matriz: ");
    scanf("%d", &ordem);

    int matriz[ordem][ordem];

    preencherMatriz(ordem, matriz);

    if (matrizSimetrica(ordem, matriz))
    {
        printf("A Matriz informada eh simetrica.");
    }
    else
    {
        printf("A matriz informada nao eh simetrica.");
    }
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



int matrizSimetrica(int ordem, int matriz[ordem][ordem])
{
    int i, j;

    for (i = 0; i < ordem-1; i++)
    {
        for (j = i+1; j < ordem; j++)
        {
            if (matriz[i][j] != matriz[j][i])
            {
                return 0;
            }
        }
    }

    return 1;
}
