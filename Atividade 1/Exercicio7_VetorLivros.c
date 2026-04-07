#include <stdio.h>
#include <string.h>

typedef struct
{
    char Titulo[31];
    char Autor[16];
    int Ano;
} Livro;

int main()
{
    Livro Livros[5];
    char Busca[31];
    int Encontrou = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("\nLivro %d\n", i + 1);

        printf("Titulo: ");
        scanf(" %[^\n]", Livros[i].Titulo);

        printf("Autor: ");
        scanf(" %[^\n]", Livros[i].Autor);

        printf("Ano: ");
        scanf("%d", &Livros[i].Ano);
    }

    printf("\nDigite o titulo que deseja buscar: ");
    scanf(" %[^\n]", Busca);

    printf("\n=== RESULTADOS ===\n");
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(Livros[i].Titulo, Busca) == 0)
        {
            printf("Titulo: %s\n", Livros[i].Titulo);
            printf("Autor: %s\n", Livros[i].Autor);
            printf("Ano: %d\n\n", Livros[i].Ano);
            Encontrou = 1;
        }
    }

    if (Encontrou == 0)
    {
        printf("Nenhum livro encontrado.\n");
    }

    return 0;
}