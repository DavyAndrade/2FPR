/*
Questão 01:
Uma loja de automóveis mantém os carros à
venda sob a forma de um vetor de structs
contendo as seguintes informações, para cada
veículo: placa, modelo, marca, cor,
quilometragem, ano modelo/fabricação (deve
ser um struct), valor e tipo (usado ou 0Km,
conforme o valor do campo quilometragem).
Pede-se a declaração de uma variável que
represente o estoque de veículos da loja,
incluindo todas as declarações de tipos que
possam ser necessárias.
Além disso, implementar as seguintes funções:
i. Exibir todos os carros do modelo m, ano de
fabricação entre a1 e a2 (inclusive), com
valor não superior a x reais;
ii. Reajustar os valores de todos os carros 0Km, considerando um aumento de p %;
iii. Retirar do estoque um determinado veículo,
dada a sua placa.
*/

// Importação de Biblliotecas
#include <stdio.h>
#include <string.h>

// Definição de Constantes e Variáveis Globais
#define ESTOQUE_VEICULOS 5

typedef struct
{
    int anoModelo;
    int anoFabricacao;
} TAno;

typedef struct
{
    char placa[8];
    char modelo[50];
    char marca[30];
    char cor[20];
    int quilometragem;
    TAno ano;
    float valor;
    char tipo[6];
} TCarro;

// Protótipo das Funções
void exibirCarrosPorFiltros(TCarro agencia[], int quant, char modelo[], int a1, int a2, float valorLimite);
void reajustarCarros0Km(TCarro agencia[], int quant, float taxa);
void retirarVeiculo(TCarro agencia[], int *quant, char placa[8]);

void preencherEstoque(TCarro veiculo[]);
void exibirCarro(TCarro carro);
void exibirTodosOsCarros(TCarro agencia[], int quant);

// Função Main
int main()
{
    TCarro agencia[ESTOQUE_VEICULOS];
    int estoque = ESTOQUE_VEICULOS;

    // Preenchendo o Estoque
    preencherEstoque(agencia);

    // Exibindo todos os Carros em Estoque
    printf("Visão Geral de Carros na Agencia:\n");
    exibirTodosOsCarros(agencia, estoque);

    // Exibindo todos os Carros por Filtro
    printf("Resultado da Busca de Carros por Filtro:\n");
    exibirCarrosPorFiltros(agencia, estoque, "HB20", 2000, 2020, 38000);

    // Removendo um Carro
    retirarVeiculo(agencia, &estoque, "ABC1234");

    // Exibindo o Estoque após Remoção
    printf("\nEstoque de Carros apos Remocao:\n");
    exibirTodosOsCarros(agencia, estoque);
}

void exibirCarrosPorFiltros(TCarro agencia[], int quant, char modelo[], int a1, int a2, float valorLimite)
{
    int i, cont = 0;

    for (i = 0; i < quant; i++)
    {
        if ((strcmp(modelo, agencia[i].modelo) == 0) &&
            ((agencia[i].ano.anoFabricacao >= a1) && (agencia[i].ano.anoFabricacao <= a2)) &&
            (agencia[i].valor <= valorLimite))
        {
            exibirCarro(agencia[i]);
            cont++;
        }
    }

    if (cont == 0)
    {
        printf("Nenhum carro encontrado com os filtros especificados.\n");
    }
    else
    {
        printf("\nTotal de carros encontrados: %d\n", cont);
    }
}

void reajustarCarros0Km(TCarro agencia[], int quant, float taxa)
{
    int i;

    for (i = 0; i < quant; i++)
    {
        if (agencia[i].quilometragem == 0)
        {
            agencia[i].valor += agencia[i].valor * (taxa / 100);
        }
    }
}

void retirarVeiculo(TCarro agencia[], int *quant, char placa[])
{
    int i, j;

    for (i = 0; i < *quant; i++)
    {
        if (strcmp(placa, agencia[i].placa) == 0)
        {
            for (j = i; j < (*quant) - 1; j++)
            {
                agencia[j] = agencia[j + 1];
            }
            printf("\nVeiculo com a placa %s retirado do estoque.", placa);
            (*quant)--;
            return;
        }
    }

    printf("Nenhum veiculo foi encontrado em estoque com a placa %s.", placa);
}

void exibirCarro(TCarro carro)
{
    printf("Placa: %s\n", carro.placa);
    printf("Modelo: %s\n", carro.modelo);
    printf("Marca: %s\n", carro.marca);
    printf("Cor: %s\n", carro.cor);
    printf("Quilometragem: %d\n", carro.quilometragem);
    printf("Ano Modelo: %d\n", carro.ano.anoModelo);
    printf("Ano Fabricacao: %d\n", carro.ano.anoFabricacao);
    printf("Valor: %.2f\n", carro.valor);
    printf("Tipo: %s\n", carro.tipo);
    printf("---------------------------\n");
}

void exibirTodosOsCarros(TCarro agencia[], int quant)
{
    int i;

    for (i = 0; i < quant; i++)
    {
        exibirCarro(agencia[i]);
    }
}

// Função para Preencher o Estoque
void preencherEstoque(TCarro agencia[])
{
    // 1º carro
    strcpy(agencia[0].placa, "ABC1234");
    strcpy(agencia[0].modelo, "HB20");
    strcpy(agencia[0].marca, "HYUNDAI");
    strcpy(agencia[0].cor, "PRATA");
    agencia[0].quilometragem = 20000;
    agencia[0].ano.anoModelo = 2016;
    agencia[0].ano.anoFabricacao = 2015;
    agencia[0].valor = 25000;
    strcpy(agencia[0].tipo, "USADO");

    // 2º carro
    strcpy(agencia[1].placa, "BCD2345");
    strcpy(agencia[1].modelo, "CIVIC");
    strcpy(agencia[1].marca, "HONDA");
    strcpy(agencia[1].cor, "BRANCA");
    agencia[1].quilometragem = 0;
    agencia[1].ano.anoModelo = 2022;
    agencia[1].ano.anoFabricacao = 2022;
    agencia[1].valor = 90000;
    strcpy(agencia[1].tipo, "0KM");

    // 3º carro
    strcpy(agencia[2].placa, "CDE3456");
    strcpy(agencia[2].modelo, "HB20");
    strcpy(agencia[2].marca, "HYUNDAI");
    strcpy(agencia[2].cor, "PRETA");
    agencia[2].quilometragem = 45000;
    agencia[2].ano.anoModelo = 2017;
    agencia[2].ano.anoFabricacao = 2017;
    agencia[2].valor = 35000;
    strcpy(agencia[2].tipo, "USADO");

    // 4º carro
    strcpy(agencia[3].placa, "EFG4567");
    strcpy(agencia[3].modelo, "HB20");
    strcpy(agencia[3].marca, "HYUNDAI");
    strcpy(agencia[3].cor, "AZUL");
    agencia[3].quilometragem = 58000;
    agencia[3].ano.anoModelo = 2019;
    agencia[3].ano.anoFabricacao = 2018;
    agencia[3].valor = 40000;
    strcpy(agencia[3].tipo, "USADO");

    // 5º carro
    strcpy(agencia[4].placa, "FGH5678");
    strcpy(agencia[4].modelo, "ECOSPORT");
    strcpy(agencia[4].marca, "FORD");
    strcpy(agencia[4].cor, "VERDE");
    agencia[4].quilometragem = 0;
    agencia[4].ano.anoModelo = 2022;
    agencia[4].ano.anoFabricacao = 2022;
    agencia[4].valor = 85000;
    strcpy(agencia[4].tipo, "0KM");
}