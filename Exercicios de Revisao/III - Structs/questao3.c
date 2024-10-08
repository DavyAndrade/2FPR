/*
Crie uma struct para armazenar dados de funcionários: nome, cargo e salário. Faça um programa que leia os dados de 10 funcionários e, em seguida, exiba o nome do funcionário com o maior salário.
*/

#include <stdio.h>
#include <float.h>
#include <string.h>

#define QTD_FUNCIONARIOS 10

typedef struct
{
    char nome[50];
    char cargo[50];
    float salario;
} TFuncionario;

void lerFuncionarios(TFuncionario funcionarios[], int quantidade);

int main()
{
    TFuncionario funcionarios[QTD_FUNCIONARIOS];

    lerFuncionarios(funcionarios, QTD_FUNCIONARIOS);
}

void lerFuncionarios(TFuncionario funcionarios[], int quantidade)
{
    int i, idMaiorSalario;
    float maiorSalario = FLT_MIN;

    for (i = 0; i < quantidade; i++)
    {
        printf("Nome %d: ", i + 1);
        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);
        funcionarios[i].nome[strlen(funcionarios[i].nome) - 1] = '\0';

        printf("Cargo %d: ", i + 1);
        fgets(funcionarios[i].cargo, sizeof(funcionarios[i].cargo), stdin);
        funcionarios[i].cargo[strlen(funcionarios[i].cargo) - 1] = '\0'; 

        printf("Salario %d: ", i + 1);
        scanf("%f", &funcionarios[i].salario);
        fflush(stdin);
        printf("\n");
    }

    for (i = 0; i < quantidade; i++)
    {
        if (funcionarios[i].salario > maiorSalario)
        {
            maiorSalario = funcionarios[i].salario;
            idMaiorSalario = i;
        }
    }

    printf("Funcionario com maior salario: %s", funcionarios[idMaiorSalario].nome);
}