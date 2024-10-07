/*
Questão 03:
Desenvolver uma função, em C, que, dada uma
string s e dada uma posição p desta string, crie duas
novas strings: s1 com os caracteres de s das
posições 0 a p-1; e s2 com os caracteres de s da
posição p à última.
Nota: Caso p seja uma posição inválida, a função
deverá retornar o valor 0; caso contrário,
procederá com a criação das duas strings e
retornará o valor 1.
*/

#include <stdio.h>
#include <string.h>

int cria_strings(char s[], int p, char s1[], char s2[]);

int main()
{
    char string[20], string1[10], string2[10];
    int pos;

    printf("Entre com uma string: ");
    fgets(string, sizeof(string), stdin);

    printf("Entre com uma posicao: ");
    scanf("%d", &pos);

    cria_strings(string, pos, string1, string2);

    printf("String 1: %s\n", string1);
    printf("String 2: %s\n", string2);
}

int cria_strings(char s[], int p, char s1[], char s2[])
{
    int i, j, tam = strlen(s);

    if (p < 0 || p >= tam)
    {
        return 0;
    }

    // colocando s em s1
    for (i = 0; i < p; i++)
    {
        s1[i] = s[i];
    }
    s1[i] = '\0';

    // Colocando em S2
    for (i = 0, j = p; j < tam; i++, j++)
    {
        s2[i] = s[j];
    }
    s2[i] = '\0';

    return 1;
}