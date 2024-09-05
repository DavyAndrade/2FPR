#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDado(int num, int mod);

int main()
{
    int dado, modificador, resultado;
    char opcao = 'Y';

    while (opcao == 'Y')
    {
        printf("\nEntre com o Roll de Dado desejado: ");
        scanf("%d %d", &dado, &modificador);
        fflush(stdin);

        resultado = rollDado(dado, modificador);

        printf("Resultado do d%d+(%d): %d\n", dado, modificador, resultado);

        printf("\nDeseja continuar? [Y/N]: ");
        scanf("%c", &opcao);
        fflush(stdin);
    }
}

int rollDado(int num, int mod)
{
    srand(time(NULL));

    int result = (rand() % num) + 1 + mod;

    return result;
}