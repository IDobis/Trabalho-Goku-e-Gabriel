#include <stdio.h>

int main()
{
    int vetor[3], matriz[3][3], resultado[3];

    printf("Digite o vetor (3 elementos):\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite a matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite o valor [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int j = 0; j < 3; j++)
    {
        resultado[j] = 0;
        for (int i = 0; i < 3; i++)
        {
            resultado[j] += vetor[i] * matriz[i][j];
        }
    }

    printf("\nVetor:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%4d ", vetor[i]);
    }

    printf("\n\nMatriz:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nResultado (vetor x colunas da matriz):\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%4d ", resultado[i]);
    }

    return 0;
}