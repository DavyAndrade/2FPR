/*
Questão 02:
Dada uma string s, desenvolver uma função
que determine se s é ou não um palíndromo.
Observação: uma string s será um palíndromo
quando seus caracteres formarem a mesma
sequência, independente se s é percorrida da
esquerda para direita ou vice-versa.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindromo(char string[]);

int main()
{
    char text[50];

    printf("Digite o Texto: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    if (palindromo(text))
    {
        printf("A string eh um palindromo.\n");
    }
    else
    {
        printf("A string nao eh um palindromo.\n");
    }
}

int palindromo(char string[])
{
    int i;
    int j = strlen(string) - 1;
    int tam = strlen(string);

    for (int i = 0; i < tam; i++)
    {
        if (string[i] == '\n')
        {
            string[i] = '\0';
            break;
        }
    }

    for (i = 0; string[i]; i++)
    {
        string[i] = tolower(string[i]);
    }

    i = 0;

    while (i < j)
    {
        if (string[i] != string[j])
        {
            return 0;
        }

        i++, j--;
    }

    return 1;
}