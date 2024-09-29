/*
Questão 03:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e símbolos).
*/

#include <stdio.h>
#include <ctype.h>

int contarLetras(char *nomeArquivo);

int main()
{
    char nomeArquivo[] = "questao3.txt";
    int quantidadeLetras = contarLetras(nomeArquivo);

    if (quantidadeLetras != -1)
    {
        printf("O arquivo possui %d letras.\n", quantidadeLetras);
    }
    else
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    return 0;
}

int contarLetras(char *nomeArquivo)
{
    FILE *arquivo;
    int quantidadeLetras = 0;
    char caractere;

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL)
    {
        return -1;
    }

    while ((caractere = fgetc(arquivo)) != EOF)
    {
        if (isalpha(caractere))
        {
            quantidadeLetras++;
        }
    }
    fclose(arquivo);
    return quantidadeLetras;
}