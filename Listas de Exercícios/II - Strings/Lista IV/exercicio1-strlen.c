/*
Questão 01:
Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.
*/

#include <stdio.h>

int stringLength(char str[]);

void main()
{
    char nome[50];
    int strTam;

    printf("Insira seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    strTam = stringLength(nome);

    printf("Seu nome possui %d caracteres.", strTam);
}

int stringLength(char str[])
{
    int i = 0;

    while (str[i])
    {
        i++;
    }
    return i;
}