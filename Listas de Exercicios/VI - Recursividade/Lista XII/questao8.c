/*
Questão 08:
Desenvolver uma função recursiva que, dada
uma string, exiba-a invertida.
*/

#include <stdio.h>
#include <string.h>

void exibirStringInvertida(char str[], int i);

int main()
{
    char string[] = "Hello, World!";

    exibirStringInvertida(string, strlen(string) - 1);

    return 0;
}

void exibirStringInvertida(char str[], int i)
{
    // Caso Base
    if (i < 0)
    {
        printf("\n");
    }
    else
    {
        // Caso Geral
        printf("%c", str[i]);
        exibirStringInvertida(str, i - 1);
    }
}