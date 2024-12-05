/*
Implementar uma função recursiva que, dado um número inteiro num, preencha um vetor, de 10 posições, com as
quantidades que cada possível algarismo aparece em num.
*/

#include <stdio.h>
#include <stdlib.h>

void contarAlgarismos(int num, int *contador);

int main()
{
    int num;
    int contador[10] = {0};

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    contarAlgarismos(num, contador);

    printf("Frequencia dos algarismos no número %d:\n", num);
    for (int i = 0; i < 10; i++)
    {
        printf("Algarismo %d: %d vez(es)\n", i, contador[i]);
    }

    return 0;
}

void contarAlgarismos(int num, int *contador)
{
    if (num == 0)
        return;

    int algarismo = num % 10;
    contador[algarismo]++;

    contarAlgarismos(num / 10, contador);
}