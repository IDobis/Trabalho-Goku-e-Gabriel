#include <stdio.h>

int main()
{
    int matriz[3][3], identidade[3][3], resultado[3][3];

    printf("Digite a matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite o valor [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            identidade[i][j] = (i == j) ? 1 : 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resultado[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                resultado[i][j] += matriz[i][k] * identidade[k][j];
            }
        }
    }

    printf("\nMatriz original:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz identidade:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%4d ", identidade[i][j]);
        }
        printf("\n");
    }

    printf("\nResultado da multiplicacao:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%4d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}