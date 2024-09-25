#include <stdio.h>

int escreverArquivo(char nomeArquivo[], int n);
int lerArquivo(char nomeArquivo[]);

int main()
{
    if (escreverArquivo("teste.txt", 5) == 1)
    {
        printf("Arquivo alterado com sucesso.\n");
    }
    else
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    if (lerArquivo("teste.txt") == 1)
    {
        printf("Arquivo aberto com sucesso.\n");
    }
    else
    {
        printf("Erro ao abrir o arquivo.\n");
    }
}

int escreverArquivo(char nomeArquivo[], int n)
{
    int i;
    FILE *arq;

    arq = fopen(nomeArquivo, "w");

    if (arq)
    {
        for (i = 1; i <= n; i++)
        {
            fprintf(arq, "%d\n", i);
        }

        fclose(arq);
        return 1;
    }
    else
    {
        fclose(arq);
        return 0;
    }
}

int lerArquivo(char nomeArquivo[])
{
    FILE *arq;
    int numero;

    arq = fopen(nomeArquivo, "r");

    if (arq == NULL)
    {
        return 0;
    }
    else
    {
        while (fscanf(arq, "%d", &numero) != EOF)
        {
            printf("%d\n", numero);
        }

        fclose(arq);
        return 1;
    }
}
