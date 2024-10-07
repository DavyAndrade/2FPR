/*
Questão 01:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.
*/

#include <stdio.h>

int contarCaracteres(char *nomeArquivo);

int main()
{
    char nomeArquivo[] = "questao1.txt";
    int numeroCaracteres = contarCaracteres(nomeArquivo);

    if (numeroCaracteres != -1)
    {
        printf("O arquivo %s possui %d caracteres.\n", nomeArquivo, numeroCaracteres);
    }
    else
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    return 0;
}

int contarCaracteres(char *nomeArquivo)
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
        cont++;
    }
    fclose(arq);
    return cont;
}
