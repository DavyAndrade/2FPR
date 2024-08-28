/*
Questão 02:
Implementar uma função que, dadas duas
strings s1 e s2, crie uma nova string – s3 –
contendo todos os caracteres de s1 que não
estejam em s2.
Nota: em s3, não devem existir caracteres
repetidos.
*/

#include <stdio.h>

int buscar(char s[], char caracter);
void criaString(char s1[], char s2[], char s3[]);

int main()
{
    char str1[20];
    char str2[20];
    char str3[20];

    printf("Entre com a primeira string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strlen(str1)] = '\0';

    printf("Entre com a segunda string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strlen(str2)] = '\0';

    criaString(str1, str2, str3);

    printf("Nova String: %s", str3);
}

int buscar(char s[], char caracter)
{
    int i;

    for (i = 0; s[i]; i++)
    {
        if (s[i] == caracter)
        {
            return 1;
        }
    }

    return 0;
}

void criaString(char s1[], char s2[], char s3[])
{
    int i, j = 0;

    s3[0] = '\0';

    for (i = 0; s1[i]; i++)
    {
        if ((buscar(s2, s1[i])) == 0 && (buscar(s3, s1[i])) == 0)
        {
            s3[j] = s1[i];
            j++;
            s3[j] = '\0';
        }
    }
}