/*
Questão 02:
Dados um arquivo texto arq e uma string s,
desenvolver uma função que exclua de arq
todos as ocorrências dos caracteres que estão
em s.
*/

#include <stdio.h>
#include <string.h>

int excluirCaracteres(char *nomeArquivo, char *s);

int main()
{
    char arq[] = "questao2.txt";
    char s[] = "aeiou";

    int result = excluirCaracteres(arq, s);

    if (result == 1)
    {
        printf("Operacao realizada com sucesso!\n");
    }
    else
    {
        printf("Falha ao abrir o arquivo!\n");
    }

    return 0;
}

int excluirCaracteres(char *nomeArquivo, char *s)
{
    FILE *arq = fopen(nomeArquivo, "r");
    FILE *temp = fopen("temp.txt", "w");
    char c;
    int i, remover;

    if ((!arq) || (!temp))
    {
        fclose(arq);
        fclose(temp);
        return 0;
    }

    while ((c = fgetc(arq)) != EOF)
    {
        remover = 0;

        for (i = 0; i < s[i]; i++)
        {
            if (c == s[i])
            {
                remover = 1;
                break;
            }
        }

        if (!remover)
        {
            fputc(c, temp);
        }
    }

    fclose(arq);
    fclose(temp);

    remove(nomeArquivo);
    rename("temp.txt", nomeArquivo);

    return 1;
}