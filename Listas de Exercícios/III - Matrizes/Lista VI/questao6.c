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
#include <limits.h>

#define funcionarios 10
#define meses 12

void preencherMatriz(int linha, int coluna, int matriz[linha][coluna]);
void exibirMatriz(int linha, int coluna, int matriz[linha][coluna]);
int totalVendidoNoAno(int linha, int coluna, int matriz[linha][coluna]);
int totalVendidoNoMes(int linha, int coluna, int matriz[linha][coluna], int mes);
int totalVendidoPorFuncionario(int linha, int coluna, int matriz[linha][coluna], int funcionario);
int mesComMaisVendas(int linha, int coluna, int matriz[linha][coluna]);
int funcionarioComMenosVendas(int linha, int coluna, int matriz[linha][coluna]);

int main()
{
    int loja[meses][funcionarios];
    int mes, funcionario;

    printf("Escolha um Mes (1-12): ");
    scanf("%d", &mes);

    printf("Escolha o ID do Funcionario (1-10): ");
    scanf("%d", &funcionario);

    preencherMatriz(meses, funcionarios, loja);
    exibirMatriz(meses, funcionarios, loja);

    int totalAno = totalVendidoNoAno(meses, funcionarios, loja);
    int totalMes = totalVendidoNoMes(meses, funcionarios, loja, mes);
    int totalFuncionario = totalVendidoPorFuncionario(meses, funcionarios, loja, funcionario);
    int mesComMaiorVenda = mesComMaisVendas(meses, funcionarios, loja);
    int funcionarioComMenorVenda = funcionarioComMenosVendas(meses, funcionarios, loja);

    printf("================================\n");

    printf("Total de Vendas durante o Ano: %d\n", totalAno);
    printf("Total de Vendas no Mes %d: %d\n", mes, totalMes);
    printf("Total de Vendas do Funcionario %d: %d\n", funcionario, totalFuncionario);
    printf("Mes com Maior Indice de Vendas: Mes %d\n", mesComMaiorVenda);
    printf("ID do Funcionario com Menos Vendas: %d", funcionarioComMenorVenda);
    printf("\n================================\n");
}

void preencherMatriz(int linha, int coluna, int matriz[linha][coluna])
{
    int i, j;

    srand(time(NULL));

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
}

void exibirMatriz(int linha, int coluna, int matriz[linha][coluna])
{
    int i, j;

    for (i = 0; i < linha; i++)
    {
        printf("Mes %d: ", i + 1);

        for (j = 0; j < coluna; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int totalVendidoNoAno(int linha, int coluna, int matriz[linha][coluna])
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

int totalVendidoNoMes(int linha, int coluna, int matriz[linha][coluna], int mes)
{
    int i, totalMes = 0;

    for (i = 0; i < coluna; i++)
    {
        totalMes += matriz[mes - 1][i];
    }

    return totalMes;
}

int totalVendidoPorFuncionario(int linha, int coluna, int matriz[linha][coluna], int funcionario)
{
    int i, totalFuncionario = 0;

    for (i = 0; i < linha; i++)
    {
        totalFuncionario += matriz[i][funcionario - 1];
    }

    return totalFuncionario;
}

int mesComMaisVendas(int linha, int coluna, int matriz[linha][coluna])
{
    int i, j, maiorVendas = INT_MIN, mesAtual, maisVendas;

    for (i = 0; i < linha; i++)
    {
        mesAtual = 0;
        for (j = 0; j < coluna; j++)
        {
            mesAtual += matriz[i][j];
        }

        if (mesAtual > maiorVendas)
        {
            maiorVendas = mesAtual;
            maisVendas = i + 1;
        }
    }

    return maisVendas;
}

int funcionarioComMenosVendas(int linha, int coluna, int matriz[linha][coluna])
{
    int i, j, menorVendas = INT_MAX, funcionarioAtual, menosVendas;

    for (i = 0; i < linha; i++)
    {
        funcionarioAtual = 0;

        for (j = 0; j < coluna; j++)
        {
            funcionarioAtual += matriz[j][i];
        }

        if (funcionarioAtual < menorVendas)
        {
            menorVendas = funcionarioAtual;
            menosVendas = i + 1;
        }
    }
    return menosVendas;
}