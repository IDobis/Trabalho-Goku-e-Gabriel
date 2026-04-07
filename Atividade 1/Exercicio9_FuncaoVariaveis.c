#include <stdio.h>

int OrdenarValores(int *A, int *B, int *C)
{
    int Auxiliar;

    if (*A > *B)
    {
        Auxiliar = *A;
        *A = *B;
        *B = Auxiliar;
    }

    if (*A > *C)
    {
        Auxiliar = *A;
        *A = *C;
        *C = Auxiliar;
    }

    if (*B > *C)
    {
        Auxiliar = *B;
        *B = *C;
        *C = Auxiliar;
    }

    if (*A == *B && *B == *C)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int PrimeiroValor;
    int SegundoValor;
    int TerceiroValor;
    int Resultado;

    printf("Digite o primeiro valor: ");
    scanf("%d", &PrimeiroValor);

    printf("Digite o segundo valor: ");
    scanf("%d", &SegundoValor);

    printf("Digite o terceiro valor: ");
    scanf("%d", &TerceiroValor);

    Resultado = OrdenarValores(&PrimeiroValor, &SegundoValor, &TerceiroValor);

    printf("\nValores ordenados:\n");
    printf("%d %d %d\n", PrimeiroValor, SegundoValor, TerceiroValor);

    printf("Retorno da funcao: %d\n", Resultado);

    return 0;
}