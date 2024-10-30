/*
Questão 08:
Desenvolver uma função recursiva que, dada
uma string, exiba-a invertida.
*/

#include <stdio.h>
#include <string.h>

void invertirString(char str[], int i, int j);

int main()
{
    char string[] = "Hello, World!";

    invertirString(string, 0, strlen(string) - 1);
    printf("Invertida: %s\n", string);

    return 0;
}

void invertirString(char str[], int i, int j)
{
    // Caso Base
    if (i >= j)
    {
        return;
    }
    else
    {
        // Caso Geral
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        invertirString(str, i + 1, j - 1);
    }
}