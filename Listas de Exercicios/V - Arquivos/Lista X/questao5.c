/*
Questão 05:
Faça uma função que, dado um arquivo A
contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos
elementos de A, porém ordenados
decrescentemente e sem repetição.
*/

#include <stdio.h>

int ordenarArquivo(char *nomeArquivoA, char *nomeArquivoB);
int exibirArquivo(char *nomeArquivo);

int main()
{
    char nomeArquivoA[] = "questao5-A.txt";
    char nomeArquivoB[] = "questao5-B.txt";
    int retorno = ordenarArquivo(nomeArquivoA, nomeArquivoB);

    if (retorno == -1)
    {
        printf("Falha ao abrir os arquivos.\n");
    }
    else
    {
        printf("Arquivos ordenados com sucesso.\n");
        printf("Arquivo B:\n");
        exibirArquivo(nomeArquivoB);
    }

    return 0;
}

int ordenarArquivo(char *nomeArquivoA, char *nomeArquivoB)
{

    FILE *arquivoA, *arquivoB;
    float numero, array[50], temp;
    int quant = 0, i, j;

    // Abrindo os Arquivos
    arquivoA = fopen(nomeArquivoA, "r");
    arquivoB = fopen(nomeArquivoB, "w");

    if (arquivoA == NULL || arquivoB == NULL)
    {        
        fclose(arquivoA);
        fclose(arquivoB);
        return -1;
    }
    // Lendo cada número do arquivo A
    while (fscanf(arquivoA, "%f", &numero) != EOF)
    {
        array[quant] = numero;
        quant++;
    }
    fclose(arquivoA);

    // Eliminando repetições
    for (i = 0; i < quant; i++)
    {
        for (j = i + 1; j < quant; j++)
        {
            if (array[i] == array[j])
            {
                array[j] = array[quant];
                quant--;
            }
        }
    }

    // Ordenando os elementos de array em ordem decrescente
    for (i = 0; i < quant; i++)
    {
        for (j = i + 1; j < quant; j++)
        {
            if (array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for (i = 0; i < quant; i++)
    {
        fprintf(arquivoB, "%.2f\n", array[i]);
    }

    fclose(arquivoB);

    return 1;
}

int exibirArquivo(char *nomeArquivo)
{
    FILE *arquivo;
    float numero;

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL)
    {
        printf("Falha ao abrir o arquivo.\n");
        fclose(arquivo);
        return -1;
    }

    while (fscanf(arquivo, "%f", &numero) != EOF)
    {
        printf("%.2f\n", numero);
    }

    fclose(arquivo);
    return 0;
}