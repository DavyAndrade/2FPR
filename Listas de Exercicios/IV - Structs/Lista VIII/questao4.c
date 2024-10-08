/*
Questão 04:
Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre um grupo
de pessoas: nome (string), gênero (char) e
idade (int). Pede-se uma função que determine
se os elementos deste vetor estão ordenados e
retorne 1, caso estejam ordenados, e 0, caso
contrário.
Observação: o vetor será considerado ordenado se
estiver organizado crescentemente em função da
idade. Porém, no caso de pessoas com a mesma
idade, estas devem estar ordenadas crescentemente
pelo nome.
*/

#include <stdio.h>
#include <string.h>

#define QUANT 5

typedef struct
{
    char nome[50];
    char genero;
    int idade;
} TPessoa;

int verificarOrdenacao(TPessoa pessoas[], int quant);
void inicializarPessoas(TPessoa pessoas[]);

int main()
{
    TPessoa pessoas[QUANT];

    inicializarPessoas(pessoas);

    if (verificarOrdenacao(pessoas, QUANT) == 1)
    {
        printf("As pessoas estao organizadas.\n");
    }
    else
    {
        printf("As pessoas NAO estao organizadas.\n");
    }
}

int verificarOrdenacao(TPessoa pessoas[], int quant)
{
    int i;

    for (i = 0; i < quant - 1; i++)
    {
        if ((pessoas[i].idade > pessoas[i + 1].idade) ||
            (pessoas[i].idade == pessoas[i + 1].idade &&
             strcmp(pessoas[i].nome, pessoas[i + 1].nome) > 0))
        {
            return 0;
        }
    }
    return 1;
}

void inicializarPessoas(TPessoa pessoas[])
{
    // Preenchimento do vetor com dados de pessoas em ordem crescente
    strcpy(pessoas[0].nome, "Beatrice");
    pessoas[0].genero = 'F';
    pessoas[0].idade = 22;

    strcpy(pessoas[1].nome, "Carlos");
    pessoas[1].genero = 'M';
    pessoas[1].idade = 23;

    strcpy(pessoas[2].nome, "Alice");
    pessoas[2].genero = 'F';
    pessoas[2].idade = 24;

    strcpy(pessoas[3].nome, "Bob");
    pessoas[3].genero = 'M';
    pessoas[3].idade = 25;

    strcpy(pessoas[4].nome, "David");
    pessoas[4].genero = 'M';
    pessoas[4].idade = 25;
}