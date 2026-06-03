#include "tabelaHash.h"
#include "interface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int funcaoHash(const char *palavra, int tamanhoTabelaHash) {
    unsigned long valorHash = 5381;
    int caractere;

    while ((caractere = (unsigned char)*palavra++) != '\0') {
        valorHash = ((valorHash << 5) + valorHash) + (unsigned long)caractere;
    }

    return (unsigned int)(valorHash % (unsigned long)tamanhoTabelaHash);
}

static No *noCriar(const char *palavra, const char *definicao) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        return NULL;
    }

    strncpy(novoNo->dados.palavra, palavra, tamanhoMaxPalavra - 1);
    novoNo->dados.palavra[tamanhoMaxPalavra - 1] = '\0';

    strncpy(novoNo->dados.definicao, definicao, tamanhoMaxDefinicao - 1);
    novoNo->dados.definicao[tamanhoMaxDefinicao - 1] = '\0';

    novoNo->proximo = NULL;
    return novoNo;
}

TabelaHash *tabelaCriar(int tamanho) {
    if (tamanho <= 0) {
        return NULL;
    }

    TabelaHash *tabela = (TabelaHash *)malloc(sizeof(TabelaHash));
    if (tabela == NULL) {
        return NULL;
    }

    tabela->compartimentos = (No **)calloc((size_t)tamanho, sizeof(No *));
    if (tabela->compartimentos == NULL) {
        free(tabela);
        return NULL;
    }

    tabela->tamanho = tamanho;
    tabela->totalElementos = 0;
    tabela->totalColisoes = 0;

    return tabela;
}

void tabelaDestruir(TabelaHash *tabela) {
    int indice;
    No *noAtual;
    No *proximoNo;

    if (tabela == NULL) {
        return;
    }

    for (indice = 0; indice < tabela->tamanho; indice++) {
        noAtual = tabela->compartimentos[indice];
        while (noAtual != NULL) {
            proximoNo = noAtual->proximo;
            free(noAtual);
            noAtual = proximoNo;
        }
    }

    free(tabela->compartimentos);
    free(tabela);
}

int tabelaInserir(TabelaHash *tabela, const char *palavra, const char *definicao) {
    unsigned int indice;
    No *noAtual;
    No *novoNo;

    if (tabela == NULL || palavra == NULL || definicao == NULL || palavra[0] == '\0') {
        return 0;
    }

    indice = funcaoHash(palavra, tabela->tamanho);
    noAtual = tabela->compartimentos[indice];

    while (noAtual != NULL) {
        if (strcmp(noAtual->dados.palavra, palavra) == 0) {
            strncpy(noAtual->dados.definicao, definicao, tamanhoMaxDefinicao - 1);
            noAtual->dados.definicao[tamanhoMaxDefinicao - 1] = '\0';
            return 1;
        }
        noAtual = noAtual->proximo;
    }

    novoNo = noCriar(palavra, definicao);
    if (novoNo == NULL) {
        return 0;
    }

    if (tabela->compartimentos[indice] != NULL) {
        tabela->totalColisoes++;
    }

    novoNo->proximo = tabela->compartimentos[indice];
    tabela->compartimentos[indice] = novoNo;
    tabela->totalElementos++;

    return 1;
}

Entrada *tabelaBuscar(TabelaHash *tabela, const char *palavra) {
    unsigned int indice;
    No *noAtual;

    if (tabela == NULL || palavra == NULL || palavra[0] == '\0') {
        return NULL;
    }

    indice = funcaoHash(palavra, tabela->tamanho);
    noAtual = tabela->compartimentos[indice];

    while (noAtual != NULL) {
        if (strcmp(noAtual->dados.palavra, palavra) == 0) {
            return &noAtual->dados;
        }
        noAtual = noAtual->proximo;
    }

    return NULL;
}

int tabelaRemover(TabelaHash *tabela, const char *palavra) {
    unsigned int indice;
    No *noAtual;
    No *noAnterior;

    if (tabela == NULL || palavra == NULL || palavra[0] == '\0') {
        return 0;
    }

    indice = funcaoHash(palavra, tabela->tamanho);
    noAtual = tabela->compartimentos[indice];
    noAnterior = NULL;

    while (noAtual != NULL) {
        if (strcmp(noAtual->dados.palavra, palavra) == 0) {
            if (noAnterior == NULL) {
                tabela->compartimentos[indice] = noAtual->proximo;
            } else {
                noAnterior->proximo = noAtual->proximo;
            }

            free(noAtual);
            tabela->totalElementos--;
            return 1;
        }

        noAnterior = noAtual;
        noAtual = noAtual->proximo;
    }

    return 0;
}

void tabelaExibir(TabelaHash *tabela) {
    int indice;
    int posicaoLista;
    No *noAtual;

    if (tabela == NULL) {
        interfaceErro("Tabela invalida.");
        return;
    }

    interfaceTitulo("TABELA HASH");
    interfaceLinhaBase();

    for (indice = 0; indice < tabela->tamanho; indice++) {
        if (tabela->compartimentos[indice] == NULL) {
            continue;
        }

        printf("%s%s  Compartimento [%d]%s\n",
               COR_NEGRITO, COR_MAGENTA, indice, COR_RESET);
        noAtual = tabela->compartimentos[indice];
        posicaoLista = 1;

        while (noAtual != NULL) {
            const char *conector = (noAtual->proximo != NULL) ? "├─" : "└─";
            printf("    %s%s%s %s%s%s : %s\n",
                   COR_CIANO, conector, COR_RESET,
                   COR_NEGRITO, noAtual->dados.palavra, COR_RESET,
                   noAtual->dados.definicao);
            noAtual = noAtual->proximo;
            posicaoLista++;
        }
    }

    if (tabela->totalElementos == 0) {
        interfaceInfo("Tabela vazia - nenhum elemento inserido.");
    }
}

void tabelaEstatisticas(TabelaHash *tabela) {
    int indice;
    int tamanhoLista;
    int maiorLista;
    double fatorCarga;
    No *noAtual;

    if (tabela == NULL) {
        interfaceErro("Tabela invalida.");
        return;
    }

    maiorLista = 0;

    for (indice = 0; indice < tabela->tamanho; indice++) {
        tamanhoLista = 0;
        noAtual = tabela->compartimentos[indice];

        while (noAtual != NULL) {
            tamanhoLista++;
            noAtual = noAtual->proximo;
        }

        if (tamanhoLista > maiorLista) {
            maiorLista = tamanhoLista;
        }
    }

    fatorCarga = (tabela->tamanho > 0)
        ? (double)tabela->totalElementos / (double)tabela->tamanho
        : 0.0;

    {
        char linha[80];

        interfaceTitulo("ESTATISTICAS");

        sprintf(linha, "  Numero de elementos .... : %d", tabela->totalElementos);
        interfaceLinhaTexto(COR_BRANCO, linha);

        sprintf(linha, "  Numero de colisoes ..... : %d", tabela->totalColisoes);
        interfaceLinhaTexto(COR_BRANCO, linha);

        sprintf(linha, "  Fator de carga ......... : %.4f", fatorCarga);
        interfaceLinhaTexto(COR_BRANCO, linha);

        sprintf(linha, "  Maior lista encadeada .. : %d", maiorLista);
        interfaceLinhaTexto(COR_BRANCO, linha);

        sprintf(linha, "  Tamanho da tabela ...... : %d", tabela->tamanho);
        interfaceLinhaTexto(COR_FRACO, linha);

        interfaceLinhaBase();
    }
}
