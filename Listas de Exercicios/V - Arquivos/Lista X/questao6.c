/*
Questão 06:
Desenvolver uma função que, dados dois
arquivos textos arqA e arqB, crie um novo
arquivo arqC, considerando que:
 arqA e arqB contém números reais,
um por linha, ordenados
crescentemente e sem repetição no
arquivo;
 arqC deve conter todos os números
dos dois arquivos originais;
 Assim como arqA e arqB, arqC
também não possuirá repetições de

elementos e estes deverão estar
ordenados de forma crescente.
*/

#include <stdio.h>

int uniaoArquivos(char *nomeArquivoA, char *nomeArquivoB, char *nomeArquivoC);

int main()
{
    char nomeArquivoA[15] = "questao6-A.txt";
    char nomeArquivoB[15] = "questao6-B.txt";
    char nomeArquivoC[15] = "questao6-C.txt";

    int resultado = uniaoArquivos(nomeArquivoA, nomeArquivoB, nomeArquivoC);

    if (resultado)
    {
        printf("Arquivo de uniao criado com sucesso.\n");
    }
    else
    {
        printf("Erro ao criar o arquivo de uniao.\n");
    }
}

int uniaoArquivos(char *nomeArquivoA, char *nomeArquivoB, char *nomeArquivoC)
{
    FILE *arqA, *arqB, *arqC;
    float numA, numB;
    int terminouA, terminouB;

    arqA = fopen(nomeArquivoA, "r");
    arqB = fopen(nomeArquivoB, "r");
    arqC = fopen(nomeArquivoC, "w");

    if ((!arqA) || (!arqB) || (!arqC))
    {
        fclose(arqA);
        fclose(arqB);
        fclose(arqC);
        return 0;
    }

    // Ler o primeiro número de cada arquivo
    terminouA = fscanf(arqA, "%f", &numA) == EOF;
    terminouB = fscanf(arqB, "%f", &numB) == EOF;

    // Fusão dos dois arquivos
    while (!terminouA || !terminouB)
    {
        if (!terminouA && !terminouB)
        {
            if (numA < numB)
            {
                fprintf(arqC, "%.2f\n", numA);
                terminouA = fscanf(arqA, "%f", &numA) == EOF;
            }
            else if (numB < numA)
            {
                fprintf(arqC, "%.2f\n", numB);
                terminouB = fscanf(arqB, "%f", &numB) == EOF;
            }
            else
            {
                // Se os números forem iguais, escreva um deles e avance nos dois arquivos
                fprintf(arqC, "%.2f\n", numA);
                terminouA = fscanf(arqA, "%f", &numA) == EOF;
                terminouB = fscanf(arqB, "%f", &numB) == EOF;
            }
        }
        else if (!terminouA)
        {
            // Se arqB terminou, continue lendo de arqA
            fprintf(arqC, "%.2f\n", numA);
            terminouA = fscanf(arqA, "%f", &numA) == EOF;
        }
        else if (!terminouB)
        {
            // Se arqA terminou, continue lendo de arqB
            fprintf(arqC, "%.2f\n", numB);
            terminouB = fscanf(arqB, "%f", &numB) == EOF;
        }
    }

    // Fechar arquivos
    fclose(arqA);
    fclose(arqB);
    fclose(arqC);

    return 1;
}