/*
Questão 04:
Fazer uma função que, dados dois arquivos
textos A e B, remova de A todos os elementos
que também estejam em B.
*/

#include <stdio.h>

#define MAX 100

int removeElementos(char *nomeArquivoA, char *nomeArquivoB);

int main()
{
    char nomeArquivoA[] = "questao4-A.txt";
    char nomeArquivoB[] = "questao4-B.txt";

    int result = removeElementos(nomeArquivoA, nomeArquivoB);

    if (result)
    {
        printf("Elementos removidos com sucesso!");
    }
    else
    {
        printf("Falha ao abrir os arquivos.\n");
    }

    return 0;
}

int removeElementos(char *nomeArquivoA, char *nomeArquivoB)
{
    FILE *arquivoA = fopen(nomeArquivoA, "r");
    FILE *arquivoB = fopen(nomeArquivoB, "r");
    FILE *temp = fopen("temp.txt", "w");

    int numA[MAX], numB[MAX];
    int tamA = 0, tamB = 0;
    int i, j, encontrado;

    if ((!arquivoA) || (!arquivoB) || (!temp))
    {
        return 0;
    }

    while (fscanf(arquivoA, "%d", &numA[tamA]) != EOF)
    {
        tamA++;
    }

    while (fscanf(arquivoB, "%d", &numB[tamB]) != EOF)
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
            fprintf(temp, "%d\n", numA[i]);
        }
    }

    fclose(arquivoA);
    fclose(arquivoB);
    fclose(temp);

    temp = fopen("temp.txt", "r");
    arquivoA = fopen(nomeArquivoA, "w");

    if ((!arquivoA) || (!temp))
    {
        return 0;
    }

    while (fscanf(temp, "%d", &numA[0]) != EOF)
    {
        fprintf(arquivoA, "%d\n", numA[0]);
    }

    fclose(arquivoA);
    fclose(temp);

    remove("temp.txt");

    return 1;
}