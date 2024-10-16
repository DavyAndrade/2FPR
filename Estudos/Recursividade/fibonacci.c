#include <stdio.h>

int fibonacci(int n);

int main()
{
    int termo = 8;

    printf("%d termo de Fibonacci: %d\n", termo, fibonacci(termo));
}

int fibonacci(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}