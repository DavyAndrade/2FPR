/*
Escreva uma função que leia uma string e conte quantas palavras ela contém. Considere que as palavras estão separadas por um ou mais espaços.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int contarPalavras(char string[]);

int main()
{
    char string[100] = "Hello, world!";
    int quantidadePalavras = contarPalavras(string);

    printf("A string '%s' contem %d palavras.\n", string, quantidadePalavras);
}

int contarPalavras(char string[])
{
    int i, contador = 1, tam = strlen(string);

    for (i = 0; i < tam; i++)
    {
        if (string[i] == ' ' && isalpha(string[i+1]))
        {
            contador++;
        }
    }

    return contador;
}