/*
Questão 01:
Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.
*/

#include <stdio.h>

int stringCompare(char s1[], char s2[]);

int main()
{
    char str1[10] = "Casa";
    char str2[10] = "Casa";
    int result;

    result = stringCompare(str1, str2);

    printf("%d", result);
}

int stringCompare(char s1[], char s2[])
{
    int i;

    for (i = 0; (s1[i]) && (s2[i]) && (s1[i] == s2[i]); i++);

    return s1[i] - s2[i];
}