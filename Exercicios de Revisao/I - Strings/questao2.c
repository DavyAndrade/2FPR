/*
Faça uma função que determine se uma string fornecida pelo usuário é um palíndromo (uma palavra que pode ser lida da mesma forma de trás para frente).
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindromo(char string[]);

int main()
{
    char string[100] = "socorram-me subi no onibus em Marrocos";
    int resultado = palindromo(string);

    if (resultado)
    {
        printf("A string '%s' eh um palindromo.\n", string);
    }
    else
    {
        printf("A string '%s' NAO eh um palindromo.\n", string);
    }
}

int palindromo(char string[])
{
    int i, j, tam = strlen(string);

    for (i = 0, j = tam - 1; i < j;)
    {
        while (i < tam && !isalpha(string[i]))
        {
            i++;
        }
        while (j >= 0 && !isalpha(string[j]))
        {
            j--;
        }

        if (i < j)
        {
            if (tolower(string[i]) != tolower(string[j]))
            {
                return 0;
            }
            i++;
            j--;
        }
    }

    return 1;
}