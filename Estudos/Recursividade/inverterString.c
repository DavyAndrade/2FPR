/*
Questão 08:
Desenvolver uma função recursiva que, dada
uma string, inverta e exiba-a.
*/

#include <stdio.h>
#include <string.h>

void inverterString(char str[], int i, int j);

int main()
{
    char string[] = "Hello, World!";

    inverterString(string, 0, strlen(string) - 1);
    printf("%s\n", string);

    return 0;
}

void inverterString(char str[], int i, int j)
{
    // Caso Base
    if (i >= j)
    {
        return;
    }
    else
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        return inverterString(str, i + 1, j - 1);
    }
}