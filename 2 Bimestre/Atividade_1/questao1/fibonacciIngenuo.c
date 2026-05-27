#include <stdio.h>

/* Caso base: n==0 retorna 0, n==1 retorna 1. Reducao: F(n)=F(n-1)+F(n-2). */
long long fibonacci(int n, long long *chamadas) {
    (*chamadas)++;

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return fibonacci(n - 1, chamadas) + fibonacci(n - 2, chamadas);
}

int main(void) {
    int n = 0;
    long long chamadas = 0;
    long long resultado = 0;

    printf("Informe n: ");
    scanf("%d", &n);

    if (n > 35) {
        printf("n muito alto para a versao ingenua. Use n ate 20 ou teste valores grandes na questao 2.\n");
        return 0;
    }

    chamadas = 0;
    resultado = fibonacci(n, &chamadas);

    printf("F(%d) = %lld\n", n, resultado);
    printf("Chamadas recursivas: %lld\n", chamadas);

    return 0;
}
