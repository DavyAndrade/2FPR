/*
Questão 06:
Dada uma string s, desenvolver uma função
recursiva que determine se s é ou não um
palíndromo.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[], int i, int j);

int main()
{
    char string[] = "radar";
    int tamString = strlen(string);

    if (isPalindrome(string, 0, tamString - 1))
    {
        printf("%s eh um palindromo.\n", string);
    }
    else
    {
        printf("%s NAO eh um palindromo.\n", string);
    }

    return 0;
}

int isPalindrome(char str[], int i, int j)
{
    // Caso Base
    if (i == j)
    {
        return 1;
    }
    else
    {
        if (tolower(str[i]) != tolower(str[j]))
        {
            return 0;
        }

        return isPalindrome(str, i + 1, j - 1);
    }

    return 1;
}