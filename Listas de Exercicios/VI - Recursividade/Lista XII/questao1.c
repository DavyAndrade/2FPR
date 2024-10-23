/*
Questão 01:
Analise a seguinte função recursiva:

int funcao (int A, int B)
{
    if (A >= B)
    {
        return funcao (A-B, B);
    }
    else
    {
    return A;
    }
}

O que é armazenado na variável x quando o
comando x = funcao (32, 6); for executado?
Observação: apresentar a sequência de
chamadas recursivas disparadas pela execução
do comando acima.

*/

/*

32-6 = 26

26 >= 6? Sim

26-6 = 20

20 >= 6? Sim

20-6 = 16

16 >= 6? Sim

14-6 = 8

8 >= 6? Sim

8-6 = 2

2 >= 6? Não

X = 2

*/

#include <stdio.h>

int funcao(int A, int B);

int main()
{
    int x = funcao(32, 6);
    printf("x = %d\n", x);
}

int funcao(int A, int B)
{
    if (A >= B)
    {
        return funcao(A - B, B);
    }
    else
    {
        return A;
    }
}