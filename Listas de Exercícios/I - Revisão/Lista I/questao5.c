/*
QUESTÃO 05:
Fazer uma função que calcule o MMC (mínimo
múltiplo comum) entre dois números.
*/

/*
QUESTÃO 04:
Fazer uma função que calcule o MDC (máximo
divisor comum) entre dois números.
*/

#include <stdio.h>

int MMC(int n1, int n2);

int main()
{
    int num1, num2;
    int mmc;

    printf("Insira dois numeros: ");
    scanf("%d %d", &num1, &num2);

    mmc = MMC(num1, num2);

    if (mmc)
    {
        printf("MMC (%d, %d): %d", num1, num2, mmc);
    }
    else
    {
        printf("MMC (%d, %d): Inexistente", num1, num2);
    }
}

int MMC(int n1, int n2)
{
    int i, maior;

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
        if (i % n1 == 0 && i % n2 == 0)
        {
            return i;
        }
    }

    return 0;
}