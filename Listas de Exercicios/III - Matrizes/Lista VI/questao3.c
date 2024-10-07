/*
QUESTÃO 03:
Desenvolver uma função que gere uma matriz
Mnxn, nos moldes do exemplo apresentado a
seguir (que consiste em uma matriz de ordem
5)

1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9
*/

#include <stdio.h>

void novaMatriz(int ordem, int m[ordem][ordem]);
void exibirMatriz(int ordem, int matriz[ordem][ordem]);

    int main()
{
    int ordem;

    printf("Entre com a ordem da matriz: ");
    scanf("%d", &ordem);

    int matriz[ordem][ordem];

    novaMatriz(ordem, matriz);

    printf("Matriz de Ordem %d: \n", ordem);
    exibirMatriz(ordem, matriz);
}

void novaMatriz(int ordem, int m[ordem][ordem])
{
    int i, j, cont;

    for (i = 0; i < ordem; i++)
    {
        cont = 1;
        for (j = 0; j < ordem; j++)
        {
            m[i][j] = i + cont;
            cont++;
        }
    }
}

void exibirMatriz(int ordem, int matriz[ordem][ordem])
{
    int i, j;

    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}