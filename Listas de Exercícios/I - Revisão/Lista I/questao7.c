/*
QUESTÃO 07:

Implementar uma função que, dado um
número inteiro n, e o intervalo definido pelos
números a e b, determine quantos valores do
intervalo possuem divisores (sendo estes
diferentes de 1) que também sejam divisores
de n.
Exemplo:
n = 6
a = 10 e b = 20
Resposta = 7 (pois os números 10, 12, 14,
15, 16, 18 e 20 possuem divisores em
comum com o número 6).
*/

#include <stdio.h>

int divisoresEmComum(int n, int intA, int intB);

int main()
{
    int num, inf, sup, quant;

    printf("Entre com um Numero: ");
    scanf("%d", &num);

    printf("Entre com o intervalo: ");
    scanf("%d %d", &inf, &sup);

    quant = divisoresEmComum(num, inf, sup);

    printf("%d possui %d divisores em comum no intervalo de %d/%d.", num, quant, inf, sup);
}

int divisoresEmComum(int n, int intA, int intB)
{
    int i, j, cont = 0;

    for (i = intA; i <= intB; i++)
    {
        
    }
}