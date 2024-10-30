/*
Questão 07:
Desenvolver uma função recursiva que
determine o número de caracteres comuns
entre duas strings s1 e s2.
*/

#include <stdio.h>
#include <string.h>

int contarCaracteresComuns(char s1[], char s2[], int i, int j);

int main()
{
    char s1[] = "tabu";
    char s2[] = "tabuada";

    int numCaracteresComuns = contarCaracteresComuns(s1, s2, 0, 0);

    printf("Numero de caracteres comuns: %d\n", numCaracteresComuns);

    return 0;
}

int contarCaracteresComuns(char s1[], char s2[], int i, int j)
{
    // Caso Base
    if (s1[i] == '\0')
    {
        return 0;
    }

    // Caso Geral 1
    if (s2[j] == '\0')
    {
        return contarCaracteresComuns(s1, s2, i + 1, 0);
    }

    // Caso Geral 2
    if (s1[i] == s2[j])
    {
        return 1 + contarCaracteresComuns(s1, s2, i + 1, 0);
    }
    // Caso Geral 3
    else
    {
        return contarCaracteresComuns(s1, s2, i, j + 1);
    }
}