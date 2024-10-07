/*
Crie uma struct que represente um aluno, contendo nome, idade e nota. Em seguida, faça um programa que leia os dados de 5 alunos e exiba o nome do aluno com a maior nota.
*/

#include <stdio.h>
#include <string.h>
#include <float.h>

#define QTD_ALUNOS 5

typedef struct
{
    char nome[100];
    int idade;
    float nota;
} TAluno;

void leituraAlunos(TAluno alunos[], int totalAlunos);
void maiorNota(TAluno alunos[], int totalAlunos);

int main()
{
    TAluno alunos[QTD_ALUNOS];

    leituraAlunos(alunos, QTD_ALUNOS);
    maiorNota(alunos, QTD_ALUNOS);
}

void leituraAlunos(TAluno alunos[], int totalAlunos)
{
    int i;

    for (i = 0; i < totalAlunos; i++)
    {
        printf("Nome do Aluno %d: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        printf("Idade do Aluno %d: ", i + 1);
        scanf("%d", &alunos[i].idade);

        printf("Nota do Aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota);
        fflush(stdin);
        printf("\n");
    }
}

void maiorNota(TAluno alunos[], int totalAlunos)
{
    int i, idAluno;
    float maiorNota = FLT_MIN;

    for (i = 0; i < totalAlunos; i++)
    {
        if (alunos[i].nota > maiorNota)
        {
            maiorNota = alunos[i].nota;
            idAluno = i;
        }
    }

    printf("Nome do Aluno com a maior Nota: %s", alunos[idAluno].nome);
}