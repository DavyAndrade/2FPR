/*
Questão 02:
Suponha a existência de um vetor de tamanho
TAM, cada posição armazenando o nome da
pessoa e a sua data de aniversário
(representada por um struct do tipo TData,
contendo os campos dia e mes). Pede-se o
desenvolvimento das seguintes funções:
 Determinar a quantidade de pessoas que
fazem aniversário no mês M;
 Exibir os nomes de todas pessoas que fazem
aniversário entre as datas d1 e d2, ambas
do tipo TData.
*/

#include <stdio.h>
#include <string.h>

#define TAM 4

typedef struct
{
    int dia;
    int mes;
} TData;

typedef struct
{
    char nome[50];
    TData dataNascimento;
} TPessoa;

int quantPessoas(TPessoa pessoas[TAM], int M);
void preencherPessoa(TPessoa pessoa[TAM]);
void exibirNomes(TPessoa pessoa[TAM], int d1, int d2);

int main()
{
    TPessoa pessoas[TAM];

    preencherPessoa(pessoas);

    int quant = quantPessoas(pessoas, 4);

    printf("Quantidade de pessoas que fazem aniversario no mes %d: %d\n", 4, quant);

    printf("Nomes das pessoas que fazem aniversario entre as datas 10 e 20:\n");
    exibirNomes(pessoas, 10, 20);
}

int quantPessoas(TPessoa pessoas[], int M)
{
    int cont = 0;

    for (int i = 0; i < TAM; i++)
    {
        if (pessoas[i].dataNascimento.mes == M)
        {
            cont++;
        }
    }

    return cont;
}

void exibirNomes(TPessoa pessoa[TAM], int d1, int d2)
{
    int i;

    for (i = 0; i < TAM; i++)
    {
        if ((pessoa[i].dataNascimento.dia >= d1) && (pessoa[i].dataNascimento.dia <= d2))
        {
            printf("%s\n", pessoa[i].nome);
        }
    }
}

void preencherPessoa(TPessoa pessoa[TAM])
{
    strcpy(pessoa[0].nome, "Alice");
    pessoa[0].dataNascimento.dia = 15;
    pessoa[0].dataNascimento.mes = 4; // Abril

    strcpy(pessoa[1].nome, "Bob");
    pessoa[1].dataNascimento.dia = 20;
    pessoa[1].dataNascimento.mes = 5; // Maio

    strcpy(pessoa[2].nome, "Carlos");
    pessoa[2].dataNascimento.dia = 10;
    pessoa[2].dataNascimento.mes = 6; // Junho

    strcpy(pessoa[3].nome, "Diana");
    pessoa[3].dataNascimento.dia = 8;
    pessoa[3].dataNascimento.mes = 4; // Abril
}
