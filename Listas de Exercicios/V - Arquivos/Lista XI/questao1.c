/*
Questão 01:
Considere a existência de um arquivo texto,

contendo números inteiros, um por linha. Pede-
se a implementação de uma função que, dado

um arquivo como especificado, crie um segundo
arquivo texto contendo, para cada elemento do
original, o seu valor e a quantidade de
ocorrências naquele arquivo (ambos os dados
na mesma linha do novo arquivo).
Exemplo:

Arquivo 1
10
12
7
10
15
2
7
15
7
8
10
14
12
8
15

Arquivo2
10 3
12 2
7 3
15 3
2 1
8 2
14 1
*/

#include <stdio.h>

int quantidadeOcorrencias(char *nomeArquivo1, char *nomeArquivo2);

int main()
{
    char arquivo1[] = "questao1-A.txt";
    char arquivo2[] = "questao1-B.txt";
    int result = quantidadeOcorrencias(arquivo1, arquivo2);

    if (result)
    {
        printf("Arquivo criado com sucesso!");
    }
    else
    {
        printf("Ocorreu um erro ao criar o arquivo");
    }
}

int quantidadeOcorrencias(char *nomeArquivo1, char *nomeArquivo2)
{
    FILE *arq1 = fopen(nomeArquivo1, "r");
    FILE *arq2 = fopen(nomeArquivo2, "w");

    int vetNum[30], numExistentes[30] = {0};
    int i, j, num, cont, quant = 0;

    if ((!arq1) || (!arq2))
    {
        fclose(arq1);
        fclose(arq2);
        return 0;
    }

    while (fscanf(arq1, "%d", &num) != EOF)
    {
        vetNum[quant] = num;
        quant++;
    }

    for (i = 0; i < quant; i++)
    {
        if (numExistentes[i] == 0)
        {
            cont = 1;

            for (j = i + 1; j < quant; j++)
            {
                if (vetNum[i] == vetNum[j])
                {
                    cont++;
                    numExistentes[j] = 1;
                }
            }
            fprintf(arq2, "%d %d\n", vetNum[i], cont);
        }
    }

    fclose(arq1);
    fclose(arq2);

    return 1;
}