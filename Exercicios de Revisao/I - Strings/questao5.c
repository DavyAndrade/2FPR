/*
Crie uma função que receba uma frase como string e inverta a ordem das palavras, mantendo a posição de cada palavra inalterada. Por exemplo, a frase "Eu gosto de C" deve se tornar "C de gosto Eu".
*/

#include <stdio.h>
#include <string.h>

void inverte_palavras(char string[]);

int main()
{
    char frase[] = "Eu gosto de C";
    inverte_palavras(frase);
    printf("%s\n", frase);
}

void inverte_palavras(char string[])
{
    int i, j, tam = strlen(string);
    char stringAux[tam + 1];

    for (i = tam - 1; i >= 0; i--)
    {
        while (i >= 0 && string[i] == ' ')
        {
            i--;
        }
    }
    strcpy(string, stringAux);
}