/*
Questão 03:
Desenvolver uma função recursiva que exiba
todos os múltiplos do número N, inferiores ou
iguais ao valor V.
*/

#include <stdio.h>

void exibirMultiplos(int N, int atual, int V);

int main()
{
    exibirMultiplos(5, 5, 20);
}

void exibirMultiplos(int N, int atual, int V)
{

    // Caso Base
    if (atual > V)
    {
        return;
    }

    // Caso Geral
    printf("%d ", atual);
    exibirMultiplos(N, N + atual, V);
}