#include <stdio.h>

int escreverArquivo(char nomeArquivo[], int n);
int lerArquivo(char nomeArquivo[]);

int main()
{
    if (escreverArquivo("teste2.txt", 20) == 1)
    {
        printf("Arquivo alterado com sucesso.\n");
    }
    else
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    if (lerArquivo("teste2.txt") == 1)
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
    char ch;

    arq = fopen(nomeArquivo, "r");

    if (arq)
    {
        while (fscanf(arq, "%c", &ch) != EOF)
        {
            printf("%c", ch);
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
