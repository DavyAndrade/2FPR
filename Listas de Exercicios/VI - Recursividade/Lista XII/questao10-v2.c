/*
Questão 10:
Implementar uma função recursiva que,
dados uma string str e um caracter ch,
remova de str todas as ocorrências de ch,
retornando o total de remoções realizadas.
*/

#include <stdio.h>
#include <string.h>

int removerCaracteres(char str[], char ch, int i);

int main()
{
    char str[] = "Hello, World!";
    char ch = 'l';
    int totalRemocao = removerCaracteres(str, ch, 0);

    /*
    i=0 compara x
    1 x
    2 achou -> 1+str[i] = str[i+1]
    2 achou -> 1+str[i] = str[i+1]
    2 x -> i+1
    3
    4
    5
    */

    printf("Total de remocoes: %d\n", totalRemocao);
    printf("String após remover caracteres: %s\n", str);

    return 0;
}

int removerCaracteres(char str[], char ch, int i)
{
    // Caso Base
    if (str[i] == '\0')
    {
        return 0;
    }
    else // Caso Geral
    {
        if (str[i] == ch)
        {
            // str[i] = str[i + 1]; // eliminando o caracter atual
            int j;
            for (j = i; str[j]; j++)
            {
                str[j] = str[j + 1]; // eliminando o caracter
            }
            return 1 + removerCaracteres(str, ch, i);
        }
        else
        {
            return removerCaracteres(str, ch, i + 1);
        }
    }
}