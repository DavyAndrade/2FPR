#include <stdio.h>
#include <string.h>

#define QUANT 2

typedef struct
{
    char nome[50];
    float AV1, AV2, media;
    char situacao[10];
} TAluno;

void leituraDados(TAluno turma[], int tamanho);
void calcularMedia(TAluno turma[], int tamanho);
void exibirDados(TAluno turma[], int tamanho);

int main()
{
    TAluno turma[QUANT];

    leituraDados(turma, QUANT);
    calcularMedia(turma, QUANT);
    exibirDados(turma, QUANT);
}

void leituraDados(TAluno turma[], int tamanho)
{
    int i;

    // Preenchimento dos dados dos alunos
    for (i = 0; i < tamanho; i++)
    {
        printf("\nEntre com o nome do aluno: ");
        fgets(turma[i].nome, sizeof(turma[i].nome), stdin);
        fflush(stdin);

        printf("Entre com as notas do aluno: ");
        scanf("%f %f", &turma[i].AV1, &turma[i].AV2);
        fflush(stdin);
    }
}

void calcularMedia(TAluno turma[], int tamanho)
{
    int i;

    // Calculando a media de cada aluno;
    for (i = 0; i < tamanho; i++)
    {
        turma[i].media = (turma[i].AV1 + turma[i].AV2) / 2;

        if (turma[i].media < 4)
        {
            strcpy(turma[i].situacao, "REPROVADO");
        }
        else if (turma[i].media < 6)
        {

            strcpy(turma[i].situacao, "AVF");
        }
        else
        {
            strcpy(turma[i].situacao, "APROVADO");
        }
    }
}

void exibirDados(TAluno turma[], int tamanho)
{
    int i;

    // Exibir cada aluno
    for (i = 0; i < tamanho; i++)
    {
        printf("===================");
        printf("\nNome do Aluno [%d]: %s", i + 1, turma[i].nome);
        printf("\nSituacao: %s", turma[i].situacao);
        printf("\n===================");
    }
}