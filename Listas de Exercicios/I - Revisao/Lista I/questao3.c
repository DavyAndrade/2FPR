/*
QUESTÃO 03:
Desenvolver uma função que calcule o n-ésimo
termo da sequência de Fibonacci.
*/

#include <stdio.h>

int fibonacci(int n);

int main()
{
    int num, termo;

    printf("Entre com N: ");
    scanf("%d", &num);

    termo = fibonacci(num);

    printf("Termo %d de Fibonacci: %d", num, termo);
}

int fibonacci(int n)
{
    int i, termo1 = 0, termo2 = 1, proximoTermo;

    for (i = 1; i <= n; i++)
    {
        proximoTermo = termo1 + termo2;
        termo1 = termo2;
        termo2 = proximoTermo;
    }

    return termo1;
}