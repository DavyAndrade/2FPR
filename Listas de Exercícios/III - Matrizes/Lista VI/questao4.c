/*
QUESTÃO 04:
Fazer uma função que, dada uma matriz Mn×n,
determine se ela é simétrica.
*/

#include <stdio.h>

void transposta(int ordem, int m[ordem][ordem], int Mt[ordem][ordem]);
void preencherMatriz(int ordem, int m[ordem][ordem]);
int matrizSimetrica(int ordem, int m[ordem][ordem], int Mt[ordem][ordem]);

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

void preencherMatriz(int ordem, int m[ordem][ordem])
{
    int i, j;

    printf("Preencha a Matriz de %dx%d\n", ordem, ordem);
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            printf("Valor [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void transposta(int ordem, int m[ordem][ordem], int Mt[ordem][ordem])
{
    int i, j;

    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            Mt[j][i] = m[i][j];
        }
    }
}

int matrizSimetrica(int ordem, int m[ordem][ordem], int Mt[ordem][ordem])
{
    int i, j;

    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            if (m[i][j] != Mt[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}