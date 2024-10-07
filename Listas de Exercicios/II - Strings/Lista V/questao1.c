/*
Questão 01:
Implementar uma função que, dada uma string
s, determine a quantidade de caracteres
distintos em s.
*/

#include <stdio.h>

int contarDistintos(char s[]);

int main()
{
    char string[20];
    int result;

    printf("Entre com uma String: ");
    fgets(string, sizeof(string), stdin);

    result = contarDistintos(string);

    printf("A String %s possui %d caracteres distintos", string, result);
}

int contarDistintos(char s[])
{
    int i, j, cont = 0, distinto;

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '\n')
        {
            s[i] = '\0';
            break;
        }
    }

    for (i = 0; s[i]; i++)
    {
        distinto = 0;

        for (j = 0; j < i; j++)
        {
            if (s[i] == s[j])
            {
                distinto = 1;
                break;
            }
        }

        if (distinto == 0)
        {
            cont++;
        }
    }

    return cont;
}