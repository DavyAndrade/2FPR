/*
Questão 05:
Pede-se a implementação de uma função
recursiva que exiba os n primeiros termos de
uma PG (Progressão Geométrica), onde a1 é o
seu primeiro termo e q a razão.

Observação: uma PG consiste em uma
sequência de valores, iniciadas pelo valor a1. Os
demais elementos são definidos como o
anterior multiplicado pela razão.
*/

#include <stdio.h>

void exibePG(int n, int a1, float q);

int main()
{
    int n = 5, a1 = 2, q = 3;

    exibePG(n, a1, q);
}

void exibePG(int n, int a1, float q)
{
    // Caso Base
    if (n == 0)
    {
        return;
    }

    // Caso Geral
    printf("%d ", a1);
    exibePG(n - 1, a1 * q, q);
}