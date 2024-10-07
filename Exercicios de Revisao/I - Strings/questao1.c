/*
Escreva um programa que leia uma string e conte quantas vogais e quantas consoantes ela contém. A função deve desconsiderar espaços e diferenciar letras maiúsculas de minúsculas.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void contagemLetras(char string[], int *vogais, int *consoantes);

int main()
{
    char string[25] = "Hello, world";
    int vogais, consoantes;

    contagemLetras(string, &vogais, &consoantes);

    printf("A string possui %d vogais e %d consoantes.", vogais, consoantes);
}

void contagemLetras(char string[], int *vogais, int *consoantes)
{
    int i, tam = strlen(string);

    *vogais = 0;
    *consoantes = 0;

    for (i = 0; i < tam; i++)
    {
        if (isalpha(string[i]))
        {
            if (tolower(string[i]) == 'a' || tolower(string[i]) == 'e' || tolower(string[i]) == 'i' || tolower(string[i]) == 'o' || tolower(string[i]) == 'u')
            {
                (*vogais)++;
            }
            else
            {
                (*consoantes)++;
            }
        }
    }
}