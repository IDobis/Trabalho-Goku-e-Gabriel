#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char Nome[100];
    float Nota;
} Aluno;

Aluno *MaiorNota(Aluno *PonteiroAluno, int Quantidade)
{
    Aluno *Maior = PonteiroAluno;

    for (int i = 1; i < Quantidade; i++)
    {
        if ((PonteiroAluno + i)->Nota > Maior->Nota)
        {
            Maior = PonteiroAluno + i;
        }
    }

    return Maior;
}

int main()
{
    int n;
    Aluno *Alunos;
    Aluno *Maior;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Quantidade invalida.\n");
        return 1;
    }

    Alunos = (Aluno *)malloc(n * sizeof(Aluno));

    if (Alunos == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nAluno %d\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", (Alunos + i)->Nome);

        printf("Nota: ");
        scanf("%f", &((Alunos + i)->Nota));
    }

    Maior = MaiorNota(Alunos, n);

    printf("\nAluno com maior nota:\n");
    printf("Nome: %s\n", Maior->Nome);
    printf("Nota: %.2f\n", Maior->Nota);

    free(Alunos);

    return 0;
}