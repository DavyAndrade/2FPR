/*
Questão 03:
Desenvolver uma função que, dados os nomes
de dois arquivos textos, contendo números
inteiros, um por linha, determine se o primeiro
arquivo está contido no segundo (ou seja, se
todos os elementos do primeiro também estão
no segundo).

Nota: considerar que não existem repetições
de elementos dentro do mesmo arquivo.
*/

#include <stdio.h>

#define MAX 100

int compararArquivos(char *nomeArquivoA, char *nomeArquivoB);

int main()
{
    char arquivo1[] = "questao3-A.txt";
    char arquivo2[] = "questao3-B.txt";

    int resultado = compararArquivos(arquivo1, arquivo2);

    if (resultado)
    {
        printf("O Arquivo 1 esta contido no Arquivo 2.\n");
    }
    else if (resultado == 0)
    {
        printf("O Arquivo 1 NAO esta contido no Arquivo 2.\n");
    }
    else
    {
        printf("Erro ao abrir os Arquivos.\n");
    }
}

int compararArquivos(char *nomeArquivoA, char *nomeArquivoB)
{
    FILE *arqA, *arqB;
    int numA[MAX], numB[MAX];
    int tamA = 0, tamB = 0;
    int i, j, encontrado;

    arqA = fopen(nomeArquivoA, "r");
    arqB = fopen(nomeArquivoB, "r");

    if ((!arqA) || (!arqB))
    {
        return -1;
    }

    while (fscanf(arqA, "%d", &numA[tamA]) != EOF)
    {
        tamA++;
    }

    while (fscanf(arqB, "%d", &numB[tamB]) != EOF)
    {
        tamB++;
    }

    for (i = 0; i < tamA; i++)
    {
        encontrado = 0;

        for (j = 0; j < tamB; j++)
        {
            if (numA[i] == numB[j])
            {
                encontrado = 1;
                break;
            }
        }

        if (!encontrado)
        {
            fclose(arqA);
            fclose(arqB);
            return 0;
        }
    }

    fclose(arqA);
    fclose(arqB);
    return 1;
}