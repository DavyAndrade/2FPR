#include <stdio.h>

int fatorial(int n);

int main()
{
    int num = 5;

    printf("Fatorial de %d: %d\n", num, fatorial(num));
}

int fatorial(int n)
{
    if (n == 0) 
    {
        return 1;
    } 
    else
    {
        return n * fatorial(n - 1);
    }
}