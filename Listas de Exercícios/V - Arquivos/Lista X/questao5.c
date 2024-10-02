/*
Questão 05:
Faça uma função que, dado um arquivo A
contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos
elementos de A, porém ordenados
decrescentemente e sem repetição.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int organizaArquivo(char nomeArquivoA[], char nomeArquivoB[]);

int main()
{
    char nomeArquivoA[] = "questao5-A.txt";
    char nomeArquivoB[] = "questao5-B.txt";

    int result = organizaArquivo(nomeArquivoA, nomeArquivoB);

    if (result)
    {
        printf("Arquivos %s e %s organizados com sucesso.\n", nomeArquivoA, nomeArquivoB);
    }
    else
    {
        printf("Erro ao abrir os arquivos.\n");
    }
}

int organizaArquivo(char nomeArquivoA[], char nomeArquivoB[])
{
    FILE *arqA;
    FILE *arqB;

    // Abrindo os arquivos
    arqA = fopen(nomeArquivoA, "r");
    arqB = fopen(nomeArquivoB, "w");

    if (!arqA || !arqB)
    {
        fclose(arqA);
        fclose(arqB);
        return -1;
    }

    // Lendo os elementos de A e adicionando-os em B
    float numero;
    
    while (fscanf(arqA, "%f", &numero) != EOF)
    {
        fprintf(arqB, "%.2f\n", numero);
    }

    // Ordenando os elementos de B
    while (arqB != EOF)
    {
    }

    // Escrevendo os elementos de B sem repetição no arquivo B
    fprintf(arqB, "%.2f\n", numero);

    // Fechando os arquivos
    fclose(arqA);
    fclose(arqB);

    return 1;
}