/*
Questão 03:
Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre os
funcionários de uma empresa: matricula (int),
nome (string), gênero (char) e salário (float).
Pede-se uma função que, dado um gênero,
desloque todos os funcionários deste gênero
para o início do vetor (e, consequentemente, os
funcionários do outro gênero ficarão ao final do
conjunto).
*/

#include <stdio.h>
#include <string.h>

#define QUANT 5 // Quantidade de funcionários

typedef struct
{
    int matricula;
    char nome[100];
    char genero;
    float salario;
} TFuncionario;

void deslocarFuncionarios(TFuncionario funcionarios[], int quant, char genero);
void inicializarFuncionarios(TFuncionario funcionarios[]);
void exibirFuncionarios(TFuncionario funcionarios[QUANT]);

int main()
{
    TFuncionario funcionarios[QUANT];
    inicializarFuncionarios(funcionarios);

    deslocarFuncionarios(funcionarios, QUANT, 'F'); // Deslocando funcionários do gênero feminino

    // Mostrando os dados dos funcionários após a deslocação
    exibirFuncionarios(funcionarios);
}

void deslocarFuncionarios(TFuncionario funcionarios[], int quant, char genero)
{
    int i, j;

    for (i = 0; i < quant; i++)
    {
        if (funcionarios[i].genero == genero)
        {
            // Deslocando funcionário para o início do vetor
            TFuncionario temp = funcionarios[i];
            for (j = i; j > 0; j--)
            {
                funcionarios[j] = funcionarios[j - 1];
            }
            funcionarios[0] = temp;
        }
    }
}

void inicializarFuncionarios(TFuncionario funcionarios[])
{
    // Preenchimento do vetor com dados dos funcionários
    funcionarios[0].matricula = 1001;
    strcpy(funcionarios[0].nome, "Alice");
    funcionarios[0].genero = 'F'; // Feminino
    funcionarios[0].salario = 3500.00;

    funcionarios[1].matricula = 1002;
    strcpy(funcionarios[1].nome, "Bob");
    funcionarios[1].genero = 'M'; // Masculino
    funcionarios[1].salario = 4500.00;

    funcionarios[2].matricula = 1003;
    strcpy(funcionarios[2].nome, "Carla");
    funcionarios[2].genero = 'F'; // Feminino
    funcionarios[2].salario = 3800.00;

    funcionarios[3].matricula = 1004;
    strcpy(funcionarios[3].nome, "David");
    funcionarios[3].genero = 'M'; // Masculino
    funcionarios[3].salario = 5000.00;

    funcionarios[4].matricula = 1005;
    strcpy(funcionarios[4].nome, "Diana");
    funcionarios[4].genero = 'F'; // Feminino
    funcionarios[4].salario = 4200.00;
}

void exibirFuncionarios(TFuncionario funcionarios[QUANT])
{
    int i;

    for (i = 0; i < QUANT; i++)
    {
        printf("Funcionario %d:\n", i + 1);
        printf("Matricula: %d\n", funcionarios[i].matricula);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Genero: %c\n", funcionarios[i].genero);
        printf("Salario: %.2f\n", funcionarios[i].salario);
        printf("\n");
    }
}