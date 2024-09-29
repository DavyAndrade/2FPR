/*
Questão 04:
Desenvolver uma função que, dado um arquivo
texto contendo números, determine se estes
encontram-se ordenados crescentemente.
*/

#include <stdio.h>
#include <stdlib.h>

int verificarOrdenacao(char *nomeArquivo);

int main()
{
    char nomeArquivo[] = "questao4.txt";
    int resultado = verificarOrdenacao(nomeArquivo);

    if (resultado == 1)
    {
        printf("Os numeros estao ordenados crescentemente.\n");
    }
    else if (resultado == 0)
    {
        printf("Os numeros nao estao ordenados crescentemente.\n");
    }
    else
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    return 0;
}

int verificarOrdenacao(char *nomeArquivo)
{
    FILE *arq;
    int num1, num2;

    arq = fopen(nomeArquivo, "r");

    if (arq == NULL)
    {
        return -1;
    }

    if (fscanf(arq, "%d", &num1) == 1)
    {
        while (fscanf(arq, "%d", &num2) == 1)
        {
            if (num1 > num2)
            {
                fclose(arq);
                return 0;
            }
            num1 = num2;
        }
        fclose(arq);
        return 1;
    }
}