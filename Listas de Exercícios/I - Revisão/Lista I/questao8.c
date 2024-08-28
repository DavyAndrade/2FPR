/*
QUESTÃO 08:
Desenvolver uma função que exiba todos os
números primos inferiores a determinado valor
inteiro N.
*/

#include <stdio.h>

void exibirPrimos(int n);

int main()
{
    int num;

    printf("Entre com um numero: ");
    scanf("%d", &num);

    exibirPrimos(num);
}

void exibirPrimos(int n)
{
    int i, boolean = 1;

    if (n <= 1)
    {
        boolean = 0;
    }
    else
    {
        for (i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                boolean = 0;
                break;
            }

        }
    }
}