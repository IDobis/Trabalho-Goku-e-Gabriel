#include <stdio.h>

int main()
{
    int Vetor[5];
    int *Ptr = Vetor;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", Ptr + i);
    }

    printf("\nDobro dos valores lidos:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(Ptr + i) * 2);
    }

    return 0;
}