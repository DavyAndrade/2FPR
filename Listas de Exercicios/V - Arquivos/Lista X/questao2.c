/*
Questão 02:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.
*/

#include <stdio.h>
#include <stdlib.h>

int contarCaracter(char *nomeArquivo, char caracter);

int main()
{
    char nomeArquivo[] = "questao2.txt";
    char caracter = 'd';
    int quantidade = contarCaracter(nomeArquivo, caracter);

    if (quantidade != -1)
    {
        printf("O caracter '%c' aparece %d vezes no arquivo.\n", caracter, quantidade);
    }
    else
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    return 0;
}

int contarCaracter(char *nomeArquivo, char caracter)
{
    FILE *arq;
    int cont = 0;
    char c;

    arq = fopen(nomeArquivo, "r");

    if (arq == NULL)
    {
        return -1;
    }

    while ((c = fgetc(arq)) != EOF)
    {
        if (c == caracter)
        {
            cont++;
        }
    }
    fclose(arq);
    return cont;
}