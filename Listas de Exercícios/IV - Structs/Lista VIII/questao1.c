/*
Questão 01:
Uma loja de automóveis mantém os carros à
venda sob a forma de um vetor de structs
contendo as seguintes informações, para cada
veículo: placa, modelo, marca, cor,
quilometragem, ano modelo/fabricação (deve
ser um struct), valor e tipo (usado ou 0 km,
conforme o valor do campo quilometragem).
Pede-se a declaração de uma variável que
represente o estoque de veículos da loja,
incluindo todas as declarações de tipos que
possam ser necessárias.
Além disso, implementar as seguintes funções:
i. Exibir todos os carros do modelo m, ano de
fabricação entre a1 e a2 (inclusive), com
valor não superior a x reais;
ii. Reajustar os valores de todos os carros 0
km, considerando um aumento de p %;
iii. Retirar do estoque um determinado veículo,
dada a sua placa.
*/

// Importação de Biblliotecas
#include <stdio.h>
#include <string.h>

// Definição de Constantes e Variáveis Globais
#define ESTOQUE_VEICULOS 100

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
void preencherEstoque(TCarro veiculo[], int quant);
void exibirCarrosPorFiltros(TCarro agencia[], int *quant, char modelo[], int a1, int a2, float valorLimite);
void reajustarCarros0km(TCarro agencia[], int quant, float taxa);
void exibirCarro(TCarro carro);

// Função Main
int main()
{
    int quantidade = 0;
    TCarro agencia[ESTOQUE_VEICULOS];

    preencherEstoque(agencia, ESTOQUE_VEICULOS);
}

// Função para Preencher o Estoque
void preencherEstoque(TCarro veiculo[], int quant)
{
    int i;
    char opcao;

    // Preencher o estoque com dados fictícios
    for (i = 0; i < quant; i++)
    {

        // Preencher os dados do veículo
        printf("Preenchimento do Veiculo [%d]\n", i + 1);

        printf("Placa do Veiculo: ");
        scanf("%s", veiculo[i].placa);

        getchar();

        printf("Modelo do Veiculo: ");
        fgets(veiculo[i].modelo, sizeof(veiculo[i].modelo), stdin);
        veiculo[i].modelo[strlen(veiculo[i].modelo) - 1] = '\0';

        printf("Marca do Veiculo: ");
        fgets(veiculo[i].marca, sizeof(veiculo[i].marca), stdin);
        veiculo[i].marca[strlen(veiculo[i].marca) - 1] = '\0';

        printf("Cor do Veiculo: ");
        fgets(veiculo[i].cor, sizeof(veiculo[i].cor), stdin);
        veiculo[i].cor[strlen(veiculo[i].cor) - 1] = '\0';

        printf("Quilometragem do Veiculo: ");
        scanf("%d", &veiculo[i].quilometragem);

        getchar();

        printf("Ano de Modelo do Veiculo: ");
        scanf("%d", &veiculo[i].ano.anoModelo);

        printf("Ano de Fabricacao do Veiculo: ");
        scanf("%d", &veiculo[i].ano.anoFabricacao);

        printf("Valor do Veiculo: ");
        scanf("%f", &veiculo[i].valor);
        getchar();

        printf("Tipo do Veiculo (0km/Usado): ");
        scanf("%s", veiculo[i].tipo);
        getchar();

        printf("Deseja continuar? [S/N]: ");
        scanf("%c", &opcao);
        getchar();

        if (opcao == 'N' || opcao == 'n')
        {
            break;
        }
    }
}

void exibirCarrosPorFiltros(TCarro agencia[], int *quant, char modelo[], int a1, int a2, float valorLimite)
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

void reajustarCarros0km(TCarro agencia[], int quant, float taxa)
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

void exibirCarro(TCarro carro)
{
}