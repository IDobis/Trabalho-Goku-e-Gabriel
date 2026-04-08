#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente {
    int id;
    int tempoAtendimento;
    struct Cliente* prox;
} Cliente;

typedef struct {
    Cliente* inicio;
    Cliente* fim;
} Fila;

void inicializarFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enqueue(Fila* f, int id, int tempo) {
    Cliente* novo = (Cliente*) malloc(sizeof(Cliente));

    if (novo == NULL) {
        printf("Erro de alocação!\n");
        return;
    }

    novo->id = id;
    novo->tempoAtendimento = tempo;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

Cliente* dequeue(Fila* f) {
    if (f->inicio == NULL) {
        return NULL;
    }

    Cliente* removido = f->inicio;
    f->inicio = f->inicio->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    return removido;
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    int n;
    printf("Digite o numero de clientes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int id, tempo;
        printf("Cliente %d - ID: ", i + 1);
        scanf("%d", &id);
        printf("Tempo de atendimento (min): ");
        scanf("%d", &tempo);

        enqueue(&fila, id, tempo);
    }

    printf("\n--- Atendimento ---\n");

    int tempoEspera = 0;

    Cliente* atual;
    while ((atual = dequeue(&fila)) != NULL) {
        printf("Cliente ID: %d\n", atual->id);
        printf("Tempo de espera: %d minutos\n\n", tempoEspera);

        tempoEspera += atual->tempoAtendimento;

        free(atual);
    }

    return 0;
}
