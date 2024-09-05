/*
QUESTÃO 06:
Considere uma loja que mantém em uma
matriz o total vendido por cada funcionário
pelos diversos meses do ano. Ou seja, uma
matriz de 12 linhas (uma por mês) e 10 colunas

(10 funcionários). Pede-se o desenvolvimento
de uma função para cada item abaixo:
a. Calcular o total vendido durante o ano;
b. Dado um mês fornecido pelo usuário,
determinar o total vendido nesse mês;
c. Dado um funcionário fornecido pelo
usuário, determinar o total vendido por ele
durante o ano;
d. Determinar o mês com maior índice de
vendas;
e. Determinar o funcionário que menos
vendeu durante o ano.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

#define funcionarios 10
#define meses 12

void preencherMatriz(int linha, int coluna, float matriz[linha][coluna]);
void exibirMatriz(int linha, int coluna, float matriz[linha][coluna]);
float totalVendidoNoAno(int linha, int coluna, float matriz[linha][coluna]);
float totalVendidoNoMes(int linha, int coluna, float matriz[linha][coluna], int mes);
float totalVendidoPorFuncionario(int linha, int coluna, float matriz[linha][coluna], int funcionario);
int mesComMaisVendas(int linha, int coluna, float matriz[linha][coluna]);
int funcionarioComMenosVendas(int linha, int coluna, float matriz[linha][coluna]);

int main()
{
    float loja[meses][funcionarios];
    int mes, funcionario;

    preencherMatriz(meses, funcionarios, loja);
    printf("\nPlanilha de Vendas: \n");
    exibirMatriz(meses, funcionarios, loja);

    printf("\nEscolha um Mes (1-12): ");
    scanf("%d", &mes);

    printf("Escolha o ID do Funcionario (1-10): ");
    scanf("%d", &funcionario);

    printf("================================\n");
    printf("Total de Vendas durante o Ano: R$ %.2f\n", totalVendidoNoAno(meses, funcionarios, loja));
    printf("Total de Vendas no Mes %d: R$ %.2f\n", mes, totalVendidoNoMes(meses, funcionarios, loja, mes));
    printf("Total de Vendas do Funcionario com ID %d: R$ %.2f\n", funcionario, totalVendidoPorFuncionario(meses, funcionarios, loja, funcionario));
    printf("Mes com Maior Indice de Vendas: Mes %d\n", mesComMaisVendas(meses, funcionarios, loja));
    printf("ID do Funcionario com Menos Vendas: %d", funcionarioComMenosVendas(meses, funcionarios, loja));
    printf("\n================================\n");
}

void preencherMatriz(int linha, int coluna, float matriz[linha][coluna])
{
    int i, j;

    srand(time(NULL));

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            matriz[i][j] = (rand() % 10) + 1;
        }
    }
}

void exibirMatriz(int linha, int coluna, float matriz[linha][coluna])
{
    int i, j;

    for (i = 0; i < linha; i++)
    {
        printf("Mes %d: ", i + 1);

        for (j = 0; j < coluna; j++)
        {
            printf("R$ %.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

float totalVendidoNoAno(int linha, int coluna, float matriz[linha][coluna])
{
    int i, j, totalDeVendas = 0;

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            totalDeVendas += matriz[i][j];
        }
    }

    return totalDeVendas;
}

float totalVendidoNoMes(int linha, int coluna, float matriz[linha][coluna], int mes)
{
    int j, totalMes = 0;

    mes--;

    for (j = 0; j < coluna; j++)
    {
        totalMes += matriz[mes][j];
    }

    return totalMes;
}

float totalVendidoPorFuncionario(int linha, int coluna, float matriz[linha][coluna], int funcionario)
{
    int i, totalFuncionario = 0;

    funcionario--;

    for (i = 0; i < linha; i++)
    {
        totalFuncionario += matriz[i][funcionario];
    }

    return totalFuncionario;
}

int mesComMaisVendas(int linha, int coluna, float matriz[linha][coluna])
{
    int mes;
    float maiorVendas = FLT_MIN, totalMes, maisVendas;

    for (mes = 1; mes <= linha; mes++)
    {
        totalMes = totalVendidoNoMes(linha, coluna, matriz, mes);

        if (totalMes > maiorVendas)
        {
            maiorVendas = totalMes;
            maisVendas = mes;
        }
    }

    return maisVendas;
}

int funcionarioComMenosVendas(int linha, int coluna, float matriz[linha][coluna])
{
    int funcionario;
    float menorVendas = FLT_MAX, totalFuncionario, menosVendas;

    for (funcionario = 1; funcionario <= coluna; funcionario++)
    {
        totalFuncionario = totalVendidoPorFuncionario(linha, coluna, matriz, funcionario);

        if (totalFuncionario < menorVendas)
        {
            menorVendas = totalFuncionario;
            menosVendas = funcionario;
        }
    }
    return menosVendas;
}