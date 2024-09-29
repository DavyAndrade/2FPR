/*
Uma instituição de ensino armazenou sob a forma de vetores de structs, um por turno (manhã e noite), os dados das diversas disciplinas (código, nome e a quantidade de alunos inscritos).
Considerando a existência dos vetores vetManha e vetNoite, conforme definido anteriormente, pede-se a
implementação de uma função que gere um novo vetor, do mesmo tipo, que armazene, para cada disciplina ministrada na instituição, o total de alunos nela inscritos (somando as quantidades matriculadas em cada turno).
*/

#include <stdio.h>
#include <string.h>

#define TAM 5

typedef struct
{
    int codigo;
    char nome[50];
    int qntdAlunos;
} TDisciplina;

void inicializarDisciplinas(TDisciplina vetManha[], TDisciplina vetNoite[]);
void totalAlunos(TDisciplina vetTotal[], TDisciplina vetManha[], TDisciplina vetNoite[]);
void exibirDisciplina(TDisciplina disciplina[]);

int main()
{
    TDisciplina vetManha[TAM], vetNoite[TAM], vetTotal[TAM];

    inicializarDisciplinas(vetManha, vetNoite);
    totalAlunos(vetTotal, vetManha, vetNoite);
    exibirDisciplina(vetTotal);

    return 0;
}

void totalAlunos(TDisciplina vetTotal[], TDisciplina vetManha[], TDisciplina vetNoite[])
{
    int i, j;

    for (i = 0; i < TAM; i++)
    {
        vetTotal[i] = vetManha[i];

        for (j = 0; j < TAM; j++)
        {
            if (vetTotal[i].codigo == vetNoite[j].codigo)
            {
                vetTotal[i].qntdAlunos += vetNoite[j].qntdAlunos;
                break;
            }
        }
    }
}

void inicializarDisciplinas(TDisciplina vetManha[], TDisciplina vetNoite[])
{
    // Inicializando vetManha
    vetManha[0] = (TDisciplina){101, "Matematica", 30};
    vetManha[1] = (TDisciplina){102, "Fisica", 25};
    vetManha[2] = (TDisciplina){103, "Quimica", 20};
    vetManha[3] = (TDisciplina){104, "Biologia", 15};
    vetManha[4] = (TDisciplina){105, "Geografia", 10};

    // Inicializando vetNoite
    vetNoite[0] = (TDisciplina){101, "Matematica", 20};
    vetNoite[1] = (TDisciplina){102, "Fisica", 25};
    vetNoite[2] = (TDisciplina){103, "Quimica", 20};
    vetNoite[3] = (TDisciplina){104, "Biologia", 15};
    vetNoite[4] = (TDisciplina){105, "Geografia", 10};
}

void exibirDisciplina(TDisciplina disciplina[])
{
    int i;

    for (i = 0; i < TAM; i++)
    {
        printf("Disciplina: %s (Codigo: %d) - Total de Alunos: %d\n", disciplina[i].nome, disciplina[i].codigo, disciplina[i].qntdAlunos);
    }
}