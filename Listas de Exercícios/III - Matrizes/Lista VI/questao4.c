/*
QUESTÃO 04:
Fazer uma função que, dada uma matriz Mn×n,
determine se ela é simétrica.
*/

#include <stdio.h>

void transposta(int ordem, int matriz[ordem][ordem], int matrizTransposta[ordem][ordem]);
void preencherMatriz(int ordem, int matriz[ordem][ordem]);
int matrizSimetrica(int ordem, int matriz[ordem][ordem], int matrizTransposta[ordem][ordem]);

int main()
{
    int ordem;

    printf("Entre com a ordem da matriz: ");
    scanf("%d", &ordem);

    int matriz[ordem][ordem];
    int matrizTransposta[ordem][ordem];

    preencherMatriz(ordem, matriz);
    transposta(ordem, matriz, matrizTransposta);

    if (matrizSimetrica(ordem, matriz, matrizTransposta))
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

void transposta(int ordem, int m[ordem][ordem], int matrizTransposta[ordem][ordem])
{
    int i, j;

    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            matrizTransposta[j][i] = m[i][j];
        }
    }
}

int matrizSimetrica(int ordem, int matriz[ordem][ordem], int matrizTransposta[ordem][ordem])
{
    int i, j;

    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            if (matriz[i][j] != matrizTransposta[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}