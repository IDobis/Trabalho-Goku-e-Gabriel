#include <stdio.h>
#include <stdlib.h>

/* Partes 1 a 4 - lista de inteiros */

typedef struct No {
    int valor;
    struct No *prox;
} No;

void inserirPosicao(No **head, int valor, int posicao) {
    if (posicao < 0) {
        printf("Erro: posicao invalida.\n");
        return;
    }

    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: sem memoria.\n");
        return;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (*head == NULL) {
        if (posicao != 0) {
            printf("Erro: posicao invalida.\n");
            free(novo);
            return;
        }
        *head = novo;
        return;
    }

    if (posicao == 0) {
        novo->prox = *head;
        *head = novo;
        return;
    }

    No *atual = *head;
    int i = 0;

    while (atual->prox != NULL && i < posicao - 1) {
        atual = atual->prox;
        i++;
    }

    if (i < posicao - 1) {
        printf("Erro: posicao invalida.\n");
        free(novo);
        return;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

int buscarValor(No *head, int valor) {
    int posicao = 0;

    while (head != NULL) {
        if (head->valor == valor) {
            return posicao;
        }
        head = head->prox;
        posicao++;
    }

    return -1;
}

void inverterLista(No **head) {
    No *anterior = NULL;
    No *atual = *head;
    No *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *head = anterior;
}

void dividirLista(No *head, No **lista1, No **lista2) {
    if (head == NULL) {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }

    if (head->prox == NULL) {
        *lista1 = head;
        *lista2 = NULL;
        return;
    }

    No *lento = head;
    No *rapido = head;

    while (rapido->prox != NULL && rapido->prox->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    *lista1 = head;
    *lista2 = lento->prox;
    lento->prox = NULL;
}

void exibirLista(No *head) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    while (head != NULL) {
        printf("%d", head->valor);
        if (head->prox != NULL) {
            printf(" -> ");
        }
        head = head->prox;
    }
    printf(" -> NULL\n");
}

void liberarLista(No **head) {
    No *atual = *head;

    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *head = NULL;
}

/* Parte 5 - playlist (mesma ideia do enunciado, nome diferente para nao conflitar com No de inteiros) */

typedef struct NoPlaylist {
    char musica[100];
    struct NoPlaylist *prox;
    struct NoPlaylist *ant;
} NoPlaylist;

void adicionarMusica(NoPlaylist **head, char *nome) {
    NoPlaylist *novo = (NoPlaylist *)malloc(sizeof(NoPlaylist));
    if (novo == NULL) {
        printf("Erro: sem memoria.\n");
        return;
    }

    int i = 0;
    while (nome[i] != '\0' && i < 99) {
        novo->musica[i] = nome[i];
        i++;
    }
    novo->musica[i] = '\0';

    if (*head == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        *head = novo;
        return;
    }

    NoPlaylist *ultimo = (*head)->ant;
    ultimo->prox = novo;
    novo->ant = ultimo;
    novo->prox = *head;
    (*head)->ant = novo;
}

void proximaMusica(NoPlaylist **atual) {
    if (*atual == NULL) {
        printf("Playlist vazia.\n");
        return;
    }
    *atual = (*atual)->prox;
}

void musicaAnterior(NoPlaylist **atual) {
    if (*atual == NULL) {
        printf("Playlist vazia.\n");
        return;
    }
    *atual = (*atual)->ant;
}

void exibirPlaylist(NoPlaylist *head) {
    if (head == NULL) {
        printf("Playlist vazia.\n");
        return;
    }

    NoPlaylist *atual = head;

    do {
        printf("[%s]", atual->musica);
        atual = atual->prox;
        if (atual != head) {
            printf(" <-> ");
        }
    } while (atual != head);

    printf("\n");
}

int totalMusicas(NoPlaylist *head) {
    if (head == NULL) {
        return 0;
    }

    int total = 0;
    NoPlaylist *atual = head;

    do {
        total++;
        atual = atual->prox;
    } while (atual != head);

    return total;
}

void tocarTodasMusicas(NoPlaylist *head, NoPlaylist **atual) {
    int qtd = totalMusicas(head);

    if (qtd == 0) {
        printf("Playlist vazia.\n");
        return;
    }

    *atual = head;
    int tocadas = 0;

    printf("Tocando todas as musicas:\n");
    while (tocadas < qtd) {
        printf("  %s\n", (*atual)->musica);
        tocadas++;
        if (tocadas < qtd) {
            proximaMusica(atual);
        }
    }
    printf("Todas as musicas foram tocadas.\n");
}

void liberarPlaylist(NoPlaylist **head) {
    if (*head == NULL) {
        return;
    }

    NoPlaylist *atual = (*head)->prox;

    while (atual != *head) {
        NoPlaylist *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    free(*head);
    *head = NULL;
}

void limparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void removerQuebraLinha(char *texto) {
    int i = 0;
    while (texto[i] != '\0') {
        if (texto[i] == '\n') {
            texto[i] = '\0';
            return;
        }
        i++;
    }
}

void menuInteiros(No **head, No **lista2) {
    int opcao;

    do {
        printf("\n--- Gerenciador de inteiros ---\n");
        printf("1 - Inserir na posicao\n");
        printf("2 - Buscar valor\n");
        printf("3 - Inverter lista\n");
        printf("4 - Dividir lista em duas\n");
        printf("5 - Exibir lista\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limparEntrada();

        if (opcao == 1) {
            int valor, posicao;
            printf("Valor: ");
            scanf("%d", &valor);
            printf("Posicao (comeca em 0): ");
            scanf("%d", &posicao);
            limparEntrada();
            inserirPosicao(head, valor, posicao);
            exibirLista(*head);
        } else if (opcao == 2) {
            int valor, posicao;
            printf("Valor para buscar: ");
            scanf("%d", &valor);
            limparEntrada();
            posicao = buscarValor(*head, valor);
            if (posicao == -1) {
                printf("Valor nao encontrado.\n");
            } else {
                printf("Valor %d encontrado na posicao %d.\n", valor, posicao);
            }
        } else if (opcao == 3) {
            inverterLista(head);
            printf("Lista invertida:\n");
            exibirLista(*head);
        } else if (opcao == 4) {
            No *lista1 = NULL;
            dividirLista(*head, &lista1, lista2);
            *head = lista1;
            printf("Lista 1: ");
            exibirLista(lista1);
            printf("Lista 2: ");
            exibirLista(*lista2);
        } else if (opcao == 5) {
            exibirLista(*head);
        }
    } while (opcao != 0);
}

void menuPlaylist(NoPlaylist **head, NoPlaylist **atual) {
    int opcao;

    do {
        printf("\n--- Playlist ---\n");
        printf("1 - Adicionar musica\n");
        printf("2 - Proxima musica\n");
        printf("3 - Musica anterior\n");
        printf("4 - Exibir playlist\n");
        printf("5 - Total de musicas\n");
        printf("6 - Tocar todas as musicas\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limparEntrada();

        if (opcao == 1) {
            char nome[100];
            printf("Nome da musica: ");
            fgets(nome, 100, stdin);
            removerQuebraLinha(nome);
            adicionarMusica(head, nome);
            if (*atual == NULL && *head != NULL) {
                *atual = *head;
            }
            exibirPlaylist(*head);
        } else if (opcao == 2) {
            if (*head == NULL) {
                printf("Playlist vazia.\n");
            } else {
                if (*atual == NULL) {
                    *atual = *head;
                }
                proximaMusica(atual);
                printf("Tocando: %s\n", (*atual)->musica);
            }
        } else if (opcao == 3) {
            if (*head == NULL) {
                printf("Playlist vazia.\n");
            } else {
                if (*atual == NULL) {
                    *atual = *head;
                }
                musicaAnterior(atual);
                printf("Tocando: %s\n", (*atual)->musica);
            }
        } else if (opcao == 4) {
            exibirPlaylist(*head);
        } else if (opcao == 5) {
            printf("Total: %d\n", totalMusicas(*head));
        } else if (opcao == 6) {
            tocarTodasMusicas(*head, atual);
        }
    } while (opcao != 0);
}

int main(void) {
    No *head = NULL;
    No *lista2 = NULL;
    NoPlaylist *headPlaylist = NULL;
    NoPlaylist *atualPlaylist = NULL;
    int opcao;

    printf("Atividade - Listas Encadeadas\n");

    do {
        printf("\n=== Menu principal ===\n");
        printf("1 - Gerenciador de inteiros (partes 1 a 4)\n");
        printf("2 - Playlist (parte 5)\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limparEntrada();

        if (opcao == 1) {
            menuInteiros(&head, &lista2);
        } else if (opcao == 2) {
            menuPlaylist(&headPlaylist, &atualPlaylist);
        }
    } while (opcao != 0);

    liberarLista(&head);
    liberarLista(&lista2);
    liberarPlaylist(&headPlaylist);

    return 0;
}
