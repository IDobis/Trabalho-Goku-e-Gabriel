#include <stdio.h>
#include <stdlib.h>

long long fibonacciIngenuo(int n, long long *chamadas) {
    (*chamadas)++;

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return fibonacciIngenuo(n - 1, chamadas) + fibonacciIngenuo(n - 2, chamadas);
}

/* Caso base igual ao ingenuo. Reducao igual, mas guarda no cache antes de retornar. */
long long fibonacciMemo(int n, long long *cache, long long *chamadas) {
    long long valor = 0;

    (*chamadas)++;

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    if (cache[n] != -1) {
        return cache[n];
    }

    valor = fibonacciMemo(n - 1, cache, chamadas) + fibonacciMemo(n - 2, cache, chamadas);
    cache[n] = valor;
    return valor;
}

int main(void) {
    int n = 0;
    int i = 0;
    long long chamadasIngenuo = 0;
    long long chamadasMemo = 0;
    long long *cache = NULL;

    printf("Informe n: ");
    scanf("%d", &n);

    cache = (long long *)malloc((n + 1) * sizeof(long long));
    for (i = 0; i <= n; i++) {
        cache[i] = -1;
    }

    chamadasMemo = 0;
    printf("\nMemoizado: F(%d) = %lld | chamadas: %lld\n",
           n, fibonacciMemo(n, cache, &chamadasMemo), chamadasMemo);

    chamadasIngenuo = 0;
    printf("Ingenuo:   F(%d) = %lld | chamadas: %lld\n",
           n, fibonacciIngenuo(n, &chamadasIngenuo), chamadasIngenuo);

    free(cache);
    return 0;
}
