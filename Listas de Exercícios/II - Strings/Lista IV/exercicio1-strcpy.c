/*
Questão 01:
Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.
*/

#include <stdio.h>

void stringCopy(char s1[], char s2[]);

int main()
{
    char text[20];
    char textCopy[20];

    printf("Entre com um Texto: ");
    fgets(text, sizeof(text), stdin);

    stringCopy(textCopy, text);

    printf("\nTexto Copiado!\n");
    printf("%s\n", textCopy);
}

void stringCopy(char s1[], char s2[])
{
    int i = 0;

    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}