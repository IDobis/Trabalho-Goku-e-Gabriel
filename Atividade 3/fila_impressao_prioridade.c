#include <stdio.h>
#include <stdlib.h>

typedef struct Documento {
    int id;
    int paginas;
    int prioridade;
    struct Documento* prox;
} Documento;

typedef struct {
    Documento* inicio;
} Fila;

void inicializarFila(Fila* f) {
    f->inicio = NULL;
}

void enqueue(Fila* f, int id, int paginas, int prioridade) {
    Documento* novo = (Documento*) malloc(sizeof(Documento));

    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        return;
    }

    novo->id = id;
    novo->paginas = paginas;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    if (f->inicio == NULL || prioridade < f->inicio->prioridade) {
        novo->prox = f->inicio;
        f->inicio = novo;
    } else {
        Documento* atual = f->inicio;

        
        while (atual->prox != NULL &&
               atual->prox->prioridade <= prioridade) {
            atual = atual->prox;
        }

        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

Documento* dequeue(Fila* f) {
    if (f->inicio == NULL) {
        return NULL;
    }

    Documento* removido = f->inicio;
    f->inicio = f->inicio->prox;

    return removido;
}

void processarFila(Fila* f) {
    Documento* doc;

    printf("\n--- Impressao ---\n");

    while ((doc = dequeue(f)) != NULL) {
        printf("Documento ID: %d\n", doc->id);
        printf("Paginas: %d\n", doc->paginas);
        printf("Prioridade: %d\n\n", doc->prioridade);

        free(doc);
    }
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    int n;
    printf("Digite o numero de documentos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int id, paginas, prioridade;

        printf("\nDocumento %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &id);

        printf("Numero de paginas: ");
        scanf("%d", &paginas);

        printf("Prioridade (menor = mais urgente): ");
        scanf("%d", &prioridade);

        enqueue(&fila, id, paginas, prioridade);
    }

    processarFila(&fila);

    return 0;
}
