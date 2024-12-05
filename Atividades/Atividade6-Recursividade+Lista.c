/*
Desenvolver uma função recursiva que, dada uma lista encadeada L do tipo TLista, altere todas as ocorrências do valor
num1 por num2. Além disso, a função deve retornar a quantidade de alterações realizadas.
Nota: o tipo TLista consiste exatamente naquele trabalhado em nossas aulas.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int inserir(TLista *L, int numero);
int alterarValores(TLista L, int num1, int num2);
int exibir(TLista L);
int menu();

int main()
{
    int opcao, num1 = 0, num2 = 3;

    TLista L = NULL;

    do
    {
        system("CLS");
        opcao = menu();

        switch (opcao)
        {
        case 1:
            printf("Entre com um numero: ");
            scanf("%d", &num1);
            if (inserir(&L, num1))
                printf("Numero inserido com sucesso.\n");
            else
                printf("Falha ao inserir numero.\n");
            break;

        case 2:
            printf("Entre com o numero a ser alterado: ");
            scanf("%d", &num1);

            printf("Entre com o novo valor: ");
            scanf("%d", &num2);

            if (alterarValores(L, num1, num2))
            {
                printf("Alteracoes realizadas com sucesso.\n");
            }
            break;

        case 3:
            printf("Valores da Lista: \n");
            exibir(L);
            break;

        default:
            printf("Opcao invalida. Tente novamente!\n");
            break;
        }

        system("PAUSE");
    } while (opcao != 4);
}

int inserir(TLista *L, int numero)
{
    TLista aux;

    aux = malloc(sizeof(TNo));

    if (aux == NULL)
    {
        printf("Falha ao alocar memoria.\n");
        return 0;
    }
    else
    {
        aux->valor = numero;
        aux->prox = *L;
        *L = aux;
        return 1;
    }
}

int alterarValores(TLista L, int num1, int num2)
{
    TLista aux = L;

    if (!aux)
    {
        return 0;
    }

    if (aux->valor == num1)
    {
        aux->valor = num2;
        return 1 + alterarValores(aux->prox, num1, num2);
    }
    else
    {
        return alterarValores(aux->prox, num1, num2);
    }
}

int exibir(TLista L)
{
    TLista aux = L;

    if (!aux)
    {
        printf("Lista vazia.\n");
        return 0;
    }
    
    printf("Elementos da lista:\n");
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}

int menu()
{
    int opcao;

    printf("Menu de Operacoes:\n\n");
    printf("(1) Inserir\n");
    printf("(2) Alterar\n");
    printf("(3) Exibir\n");
    printf("(4) Sair\n\n");

    printf("Entre com a sua opcao: ");
    scanf("%d", &opcao);

    // retornando a opção escolhida
    return opcao;
}