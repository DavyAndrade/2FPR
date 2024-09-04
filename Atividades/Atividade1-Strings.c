/*
Atividade 1 – Strings
[2024/2]

O Cadastro Nacional de Pessoas Jurídicas (CNPJ) associa a cada empresa um código no formato XX.XXX.XXX/YYYY-ZZ,
onde:
 XX.XXX.XXX: representa a inscrição;
 YYYY: indica se é matriz ou filial. No caso de ser matriz, YYYY será igual a 0001;
 ZZ: dígitos verificadores.
Desenvolver uma função que receba uma string representando um CNPJ e retorne: a inscrição (string), a sequência que
representa a matriz ou o número da filial (string), além da informação (no inteiro) se o código representa uma matriz (1)
ou uma filial (0) e, por último, os dígitos verificadores (string).

Observação: caso alguma função de manipulação de strings for necessária, utilizar apenas aquelas trabalhadas em nossas aulas.
*/

#include <stdio.h>

// Função que processa o CNPJ e separa suas partes
int processaCNPJ(char cnpj[], char inscricao[], char matriz[], char verificadores[]);

int main()
{
    char CNPJ[19] = "12.345.678/0001-00";
    char inscricao[11], matrizFilial[5], verificadores[3];
    int isMatriz;

    // Chama a função para processar o CNPJ
    isMatriz = processaCNPJ(CNPJ, inscricao, matrizFilial, verificadores);

    // Exibe as partes do CNPJ
    printf("\nInscricao: %s", inscricao);
    printf("\nTipo CNPJ: %s, %s", matrizFilial, isMatriz ? "Matriz" : "Filial");
    printf("\nDigitos Verificadores: %s", verificadores);

    return 0;
}

int processaCNPJ(char cnpj[], char inscricao[], char matriz[], char verificadores[])
{
    int i, j;

    for (i = 0; i < 10; i++)
    {
        inscricao[i] = cnpj[i];
    }
    inscricao[i] = '\0';

    for (i = 11, j = 0; j < 4; i++, j++)
    {
        matriz[j] = cnpj[i];
    }
    matriz[j] = '\0';

    for (i = 16, j = 0; j < 2; i++, j++)
    {
        verificadores[j] = cnpj[i];
    }
    verificadores[j] = '\0'; // Adiciona o terminador nulo ao final da string

    if (matriz[0] == '0' && matriz[1] == '0' && matriz[2] == '0' && matriz[3] == '1')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
