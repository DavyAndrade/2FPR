/*
Questão 04:
Fazer uma função recursiva que, dado um
número inteiro N, exiba o mesmo na base 2
(binária).
*/

#include <stdio.h>

void converterBase2(int N);

int main()
{
    converterBase2(10);
}

void converterBase2(int N)
{
    // Caso Base
    if (N == 0)
    {
        return;
    }

    // Caso Geral
    converterBase2(N / 2);
    printf("%d ", N % 2);
}