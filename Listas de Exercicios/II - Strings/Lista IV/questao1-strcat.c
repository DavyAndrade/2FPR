/*
Questão 01:
Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.
*/

#include <stdio.h>

void stringConcatenate(char string1[], char string2[]);

int main()
{
    char text1[50] = "This is a ";
    char text2[25] = "simple text";

    stringConcatenate(text1, text2);

    printf("text1 = %s\n", text1);
    printf("text2 = %s\n", text2);
}

void stringConcatenate(char string1[], char string2[])
{
    int i, j = 0;

    for (i = 0; string1[i]; i++);

    while (string2[j])
    {
        string1[i] = string2[j];
        i++, j++;
    }

    string1[i] = '\0';
}