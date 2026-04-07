#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char Nome[100];
    int Matricula;
    float MediaFinal;
} Aluno;

void RemoverQuebraLinha(char *Texto)
{
    Texto[strcspn(Texto, "\n")] = '\0';
}

void LerTexto(const char *Mensagem, char *Destino, int Tamanho)
{
    printf("%s", Mensagem);
    fgets(Destino, Tamanho, stdin);
    RemoverQuebraLinha(Destino);
}

int LerInteiro(const char *Mensagem)
{
    char Linha[100];
    int Valor;

    while (1)
    {
        printf("%s", Mensagem);
        fgets(Linha, sizeof(Linha), stdin);

        if (sscanf(Linha, "%d", &Valor) == 1)
        {
            return Valor;
        }

        printf("Entrada invalida. Digite um numero inteiro.\n");
    }
}

float LerFloat(const char *Mensagem)
{
    char Linha[100];
    float Valor;

    while (1)
    {
        printf("%s", Mensagem);
        fgets(Linha, sizeof(Linha), stdin);

        if (sscanf(Linha, "%f", &Valor) == 1)
        {
            return Valor;
        }

        printf("Entrada invalida. Digite um numero real.\n");
    }
}

int main()
{
    Aluno Alunos[10];
    Aluno Aprovados[10];
    Aluno Reprovados[10];

    int ContAprovados = 0;
    int ContReprovados = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("\nAluno %d\n", i + 1);

        LerTexto("Nome: ", Alunos[i].Nome, sizeof(Alunos[i].Nome));
        Alunos[i].Matricula = LerInteiro("Matricula: ");
        Alunos[i].MediaFinal = LerFloat("Media Final: ");

        if (Alunos[i].MediaFinal >= 6.0f)
        {
            Aprovados[ContAprovados] = Alunos[i];
            ContAprovados++;
        }
        else
        {
            Reprovados[ContReprovados] = Alunos[i];
            ContReprovados++;
        }
    }

    printf("\n=== APROVADOS ===\n");
    if (ContAprovados == 0)
    {
        printf("Nenhum aluno aprovado.\n");
    }
    else
    {
        for (int i = 0; i < ContAprovados; i++)
        {
            printf("\nAluno %d\n", i + 1);
            printf("Nome: %s\n", Aprovados[i].Nome);
            printf("Matricula: %d\n", Aprovados[i].Matricula);
            printf("Media Final: %.2f\n", Aprovados[i].MediaFinal);
        }
    }

    printf("\n=== REPROVADOS ===\n");
    if (ContReprovados == 0)
    {
        printf("Nenhum aluno reprovado.\n");
    }
    else
    {
        for (int i = 0; i < ContReprovados; i++)
        {
            printf("\nAluno %d\n", i + 1);
            printf("Nome: %s\n", Reprovados[i].Nome);
            printf("Matricula: %d\n", Reprovados[i].Matricula);
            printf("Media Final: %.2f\n", Reprovados[i].MediaFinal);
        }
    }

    return 0;
}