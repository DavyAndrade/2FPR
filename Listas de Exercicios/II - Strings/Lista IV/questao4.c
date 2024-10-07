/*
Questão 04:
Implementar uma função que remova todas as
ocorrências de determinado caracter em uma
string.
*/

#include <stdio.h>
#include <string.h>

int removerCaracteres(char string[], char letra);

int main()
{
    char text[20];
    char caracter;
    int quantidade;

    printf("Entre com um texto: ");
    fgets(text, sizeof(text), stdin);

    printf("Entre com o caracter a ser removido: ");
    scanf("%c", &caracter);
    fflush(stdin);

    printf("\nTexto Original: %s", text);

    quantidade = removerCaracteres(text, caracter);

    printf("\nTexto Alterado: %s", text);
    printf("\nForam removidas %d ocorrencias de '%c' no texto!", quantidade, caracter);
}

int removerCaracteres(char string[], char letra)
{
    int i = 0, j, cont = 0;

    while (string[i])
    {
        if (string[i] == letra)
        {
            for (j = i; string[j]; j++)
            {
                string[j] = string[j + 1];
            }
            cont++;
        }
        else
        {
            i++;
        }
    }

    return cont;
}