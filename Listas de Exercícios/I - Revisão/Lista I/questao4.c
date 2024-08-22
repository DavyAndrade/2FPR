/*
QUESTÃO 04:
Fazer uma função que calcule o MDC (máximo
divisor comum) entre dois números.
*/

#include <stdio.h>

int MDC(int n1, int n2);

int main()
{
    int num1, num2;
    int mdc;

    printf("Insira dois numeros: ");
    scanf("%d %d", &num1, &num2);

    mdc = MDC(num1, num2);

    if (mdc)
    {
        printf("MDC (%d, %d): %d", num1, num2, mdc);
    }
}

int MDC(int n1, int n2)
{
    int i, maior, result;

    if (n1 > n2)
    {
        maior = n1;
    }
    else
    {
        maior = n2;
    }

    for (i = 1; i < maior; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            result = i;
        }
    }

    return result;
}