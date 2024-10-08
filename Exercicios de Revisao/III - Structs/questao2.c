/*
Implemente uma struct para representar um livro, contendo título, autor, ano de publicação e número de páginas. Faça um programa que cadastre 3 livros e permita que o usuário busque livros por autor.
*/

#include <stdio.h>
#include <string.h>

#define QTD_LIVROS 3

typedef struct
{
    char titulo[100];
    char autor[100];
    int anoPublicacao;
    int numeroPaginas;
} TLivro;

void cadastrarLivro(TLivro catalogo[]);
int buscarLivro(TLivro catalogo[]);
void exibirLivro(TLivro catalogo[], int target);

int main()
{
    TLivro catalogo[QTD_LIVROS];

    cadastrarLivro(catalogo);
    int resultBusca = buscarLivro(catalogo);

    if (resultBusca == -1)
    {
        printf("Livro nao encontrado.\n");
    }
    else
    {
        exibirLivro(catalogo, resultBusca);
    }
}

void cadastrarLivro(TLivro catalogo[])
{
    int i;
    for (i = 0; i < QTD_LIVROS; i++)
    {
        printf("Livro %d:\n", i + 1);
        printf("Titulo: ");
        fgets(catalogo[i].titulo, sizeof(catalogo[i].titulo), stdin);
        catalogo[i].titulo[strlen(catalogo[i].titulo)] = '\0';

        printf("Autor: ");
        fgets(catalogo[i].autor, sizeof(catalogo[i].autor), stdin);
        catalogo[i].autor[strlen(catalogo[i].autor)] = '\0';

        printf("Ano de publicacao: ");
        scanf("%d", &catalogo[i].anoPublicacao);

        printf("Numero de paginas: ");
        scanf("%d", &catalogo[i].numeroPaginas);
        fflush(stdin);
        printf("\n");
    }
}

int buscarLivro(TLivro catalogo[])
{
    char autorBuscado[100];
    int i;

    printf("Digite o autor do livro: ");
    fgets(autorBuscado, sizeof(autorBuscado), stdin);

    for (i = 0; i < QTD_LIVROS; i++)
    {
        if (strcmp(catalogo[i].autor, autorBuscado) == 0)
        {
            return i;
        }
    }

    return -1; // Livro não encontrado
}

void exibirLivro(TLivro catalogo[], int target)
{
    printf("\nLivro encontrado:\n");
    printf("Titulo: %s", catalogo[target].titulo);
    printf("Autor: %s", catalogo[target].autor);
    printf("Ano de publicacao: %d\n", catalogo[target].anoPublicacao);
    printf("Numero de paginas: %d\n", catalogo[target].numeroPaginas);
}