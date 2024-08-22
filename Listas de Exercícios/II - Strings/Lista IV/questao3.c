/*
Questão 03:
Desenvolver uma função que, dada uma string
s, crie uma substring que inicie na posição p de
s e contenha n caracteres.
Observações: se p e/ou n forem inválidos, a
substring será vazia; ii) se s não possuir n
caracteres além de p, a substring a ser criada
começará em p e terminará no final de s.
*/

#include <stdio.h>
#include <string.h>

void subString(char s[], char subStr[], int p, int n);

int main()
{
    char text[20];
    char subStr[20];
    int pos, quantidade;

    printf("Entre com um texto: ");
    fgets(text, sizeof(text), stdin);

    printf("Entre com uma posicao: ");
    scanf("%d", &pos);

    printf("Entre com uma quantidade de caracteres: ");
    scanf("%d", &quantidade);

    subString(text, subStr, pos, quantidade);

    printf("\nString: %s", text);
    printf("\nSub String: %s\n", subStr);
}

void subString(char s[], char subStr[], int p, int n)
{
    int i, j, tam = strlen(s);

    if (p < 0 || p >= tam || n < 0)
    {
        subStr[0] = '\0';
    }
    else
    {
        for (i = 0, j = p; (i < n) && (i < tam); i++, j++)
        {
            subStr[i] = s[j];
        }
        subStr[i] = '\0';
    }
}