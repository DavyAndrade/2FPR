/*
Questão 04:
Dada uma matriz MLxC, onde L e C são constantes, desenvolver uma função que verifique se os elementos da matriz estão
ordenados de forma crescente. Para isto, as seguintes regras devem ser atendidas:
a. Os elementos de cada linha devem estar ordenados crescentemente (ou seja, cada elemento será maior ou igual àquele da mesma linha, porém da coluna anterior – caso exista);
b. O primeiro elemento de cada linha deve ser maior ou igual ao último da linha anterior (caso exista).
Caso a matriz M atenda aos critérios definidos, o valor 1 deverá ser retornado pela função; caso contrário, 0.
*/

#include <stdio.h>

#define row 5
#define column 5

int verificarOrdenados(int matriz[row][column]);

int main()
{
    int matriz[row][column] = {{1, 2, 3, 4, 5},
                               {6, 7, 8, 9, 10},
                               {11, 12, 13, 14, 15},
                               {16, 17, 18, 19, 20},
                               {21, 22, 23, 24, 25}};

    if (verificarOrdenados(matriz) == 1)
    {
        printf("Os elementos da matriz estao ordenados corretamente.\n");
    }
    else
    {
        printf("Os elementos da matriz NAO estao ordenados corretamente.\n");
    }
}

int verificarOrdenados(int matriz[row][column])
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column - 1; j++)
        {
            if (matriz[i][j] > matriz[i][j + 1])
            {
                return 0; // Elemento da linha não é maior ou igual ao do próximo
            }
        }
    }
    
    return 1;
}