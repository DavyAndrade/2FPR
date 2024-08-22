/*
QUESTÃO 01:
Desenvolver uma função que exiba os múltiplos
de N compreendidos no intervalo definido por
A e B.
*/

#include <stdio.h>

void exibirMultiplos(int A, int B, int N);

int main()
{
    int inf, sup, num;

    printf("Entre com o intervalo: ");
    scanf("%d %d", &inf, &sup);

    printf("Informe o valor de N: ");
    scanf("%d", &num);

    exibirMultiplos(inf, sup, num);
}

void exibirMultiplos(int A, int B, int N)
{
    int i;

    for (i = A; i < B; i++)
    {
        if (i % N == 0)
        {
            printf("%d ", i);
        }
    }
}