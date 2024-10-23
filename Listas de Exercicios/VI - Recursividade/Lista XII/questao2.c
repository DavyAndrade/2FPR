/*
Questão 02:
Dado o programa abaixo, pede-se avaliar a
sua execução e, ao final, informar o valor que
é exibido. Para isto, é obrigatório apresentar
o passo a passo de sua execução, com a
sequência de chamadas à função, assim
como o valor retornado por cada uma delas.
*/

/*

#include <stdio.h>

int funcao (int a, int b) 
{
    if (a > 0) 
    {
        if (a > b) 
        {
            return funcao (a-1, b+2) + funcao (b-a, b);
        } 
        else 
        {
            return funcao (a-2, b);
        }
    }
    else 
    {
        return b;
    }
}

void main () 
{
    printf ("Resposta = %d", funcao (10, 5));
}
*/

/*
A = 10, B = 5

A > 0? Sim

    A > B? Sim

        funcao (10-1, 5+2) + funcao (5-10, 5) // segunda função retorna b (vulgo 5)

    9 > 7? Sim

        funcao (9-1, 7+2) + funcao (7-9, 7) // retorna função retorna b (vulgo 7)

        8 > 9? Não

            funcao (8-2, 9);

            6 > 9? Não

                funcao(6-2, 9)

                4 > 9? Não
            
                    funcao(4-2, 9)

                    2 > 9? Não

                        funcao(2-2, 9) // Return 9

    5 + 7 + 9 = 21

*/

#include <stdio.h>

int funcao(int a, int b)
{
    if (a > 0)
    {
        if (a > b)
        {
            return funcao(a - 1, b + 2) + funcao(b - a, b);
        }
        else
        {
            return funcao(a - 2, b);
        }
    }
    else
    {
        return b;
    }
}

int main()
{
    printf("Resposta = %d\n", funcao(10, 5));
}