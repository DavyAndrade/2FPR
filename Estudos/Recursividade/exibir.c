#include <stdio.h>

void exibir(int n);

int main()
{
    int num = 10;

    exibir(num);
}

void exibir(int n)
{
    if (n > 0)
    {
        exibir(n - 1);
        printf("%d\n", n);
    }
}