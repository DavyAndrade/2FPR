/*
Questão 05:
O histórico de um aluno é representado por um
vetor de structs onde cada posição armazena o
código da disciplina cursada, semestre e ano
que a cumpriu e a média final na disciplina.
Implementar uma função que exiba o histórico
do aluno com o seguinte formato:
NomeDisciplina1 (código1) MédiaDisciplina1
NomeDisciplina2 (código2) MédiaDisciplina2

.
.
.

NomeDisciplinaN (códigoN) MédiaDisciplinaN
Coeficiente de rendimento: CR
Observações:
1. Para obter os dados da disciplina, um outro
vetor de structs deve ser consultado. Este,
por sua vez, armazena para cada disciplina
do curso as seguintes informações: código,
nome e número de créditos;
2. O coeficiente de rendimento consiste em
uma média ponderada de todos os graus
atribuídos às disciplinas cursadas, onde os
pesos são representados pelo número de
créditos da disciplina;
3. Todos os dados em negrito apresentados no
formato do histórico devem ser obtidos a
partir dos vetores.
*/

#include <stdio.h>
#include <string.h>

#define DISCIPLINAS 5
#define CURSADAS 4

typedef struct
{
    int codigo;
    char nome[50];
    int creditos;
} TDisciplina;

typedef struct
{
    int codigoDisciplina;
    int semestre;
    int ano;
    float mediaFinal;
} THistorico;

void exibirHistorico(THistorico historico[], int numCursadas, TDisciplina disciplinas[], int numDisciplinas);

int main()
{
    // Dados das disciplinas do curso
    TDisciplina disciplinas[DISCIPLINAS] = {
        {101, "Matematica", 4},
        {102, "Fisica", 3},
        {103, "Quimica", 4},
        {104, "Historia", 2},
        {105, "Geografia", 3}};

    // Histórico de disciplinas cursadas pelo aluno
    THistorico historico[CURSADAS] = {
        {101, 1, 2022, 8.0},
        {102, 2, 2022, 7.5},
        {103, 1, 2023, 9.0},
        {104, 2, 2023, 6.5}};


    // Exibir o histórico do aluno
    exibirHistorico(historico, CURSADAS, disciplinas, DISCIPLINAS);
}

// Função para exibir o histórico do aluno e calcular o coeficiente de rendimento
void exibirHistorico(THistorico historico[], int numCursadas, TDisciplina disciplinas[], int numDisciplinas)
{
    float somaNotasPonderadas = 0;
    int somaCreditos = 0;

    // Exibe o histórico e calcula a média ponderada
    for (int i = 0; i < numCursadas; i++)
    {
        // Procura o nome da disciplina pelo código
        for (int j = 0; j < numDisciplinas; j++)
        {
            if (historico[i].codigoDisciplina == disciplinas[j].codigo)
            {
                printf("%s (%d) Media: %.2f\n", disciplinas[j].nome, disciplinas[j].codigo, historico[i].mediaFinal);
                somaNotasPonderadas += historico[i].mediaFinal * disciplinas[j].creditos;
                somaCreditos += disciplinas[j].creditos;
                break;
            }
        }
    }

    // Calcula o Coeficiente de Rendimento (CR)
    float CR = somaNotasPonderadas / somaCreditos;
    printf("Coeficiente de rendimento: %.2f\n", CR);
}