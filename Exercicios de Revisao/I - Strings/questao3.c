/*
Implemente um programa que substitua todas as ocorrências de um determinado caractere em uma string por outro caractere informado pelo usuário.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int substituirCaracteres(char string[], char caractereOriginal, char caractereNovo);

int main()
{
    char string[100] = "dado";
    char caractereOriginal = 'a';
    char caractereNovo = 'e';
    int result = substituirCaracteres(string, caractereOriginal, caractereNovo);

    printf("O caractere '%c' foi substituido por '%c' %d vezes.\n", caractereOriginal, caractereNovo, result);
    printf("Novo texto: %s", string);
}

int substituirCaracteres(char string[], char caractereOriginal, char caractereNovo)
{
    int i, tam = strlen(string), cont = 0;

    for (i = 0; i < tam; i++)
    {
        if (string[i] == caractereOriginal)
        {
            string[i] = caractereNovo;
            cont++;
        }
    }

    return cont;
}