/*
Questão 04:
Desenvolver uma função que remova de uma
string s os caracteres compreendidos entre as
posições p1 e p2.
Caso p1 ou p2 seja uma posição inválida, a
função deverá retornar o valor 0 e a remoção de
caracteres solicitada não será realizada; caso
contrário, deverá retornar 1 e proceder com o
que foi pedido.
*/

#include <stdio.h>
#include <string.h>

int removerCaracteres(char s[], int p1, int p2);

int main()
{
    char string[20];
    int pos1, pos2;

    printf("Entre com uma string: ");
    fgets(string, sizeof(string), stdin);
    string[strlen(string)] = '\0';

    printf("Entre com duas posicoes: ");
    scanf("%d %d", &pos1, &pos2);

    if (removerCaracteres(string, pos1, pos2))
    {
        printf("\nString Final: %s", string);
    }
    else
    {
        printf("Insira posicoes validas!");
    }
}

int removerCaracteres(char s[], int p1, int p2)
{
    int i, j, tam = strlen(s);

    if (p1 < 0 || p1 > p2 || p2 > tam)
    {
        return 0;
    }

    for (i = p1, j = p2; s[j]; i++, j++)
    {
        s[i] = s[j];
    }
    s[i] = '\0';
    return 1;
}