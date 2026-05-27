#include <stdio.h>

/* Caso base: 1 disco, um movimento. Reducao: resolve n-1, move o maior, resolve n-1 de novo. */
void hanoi(int discos, char origem, char destino, char auxiliar, int *movimentos) {
    if (discos == 1) {
        (*movimentos)++;
        printf("Disco %d: %c -> %c\n", *movimentos, origem, destino);
        return;
    }

    hanoi(discos - 1, origem, auxiliar, destino, movimentos);
    (*movimentos)++;
    printf("Disco %d: %c -> %c\n", *movimentos, origem, destino);
    hanoi(discos - 1, auxiliar, destino, origem, movimentos);
}

int main(void) {
    int discos = 0;
    int movimentos = 0;

    printf("Quantidade de discos: ");
    scanf("%d", &discos);

    printf("\nMovimentos (A=origem, B=auxiliar, C=destino):\n");
    hanoi(discos, 'A', 'C', 'B', &movimentos);

    printf("\nTotal de movimentos: %d\n", movimentos);

    return 0;
}
