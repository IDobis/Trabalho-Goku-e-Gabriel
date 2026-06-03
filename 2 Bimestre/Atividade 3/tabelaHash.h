#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define tamanhoTabela 101
#define tamanhoMaxPalavra 64
#define tamanhoMaxDefinicao 256

typedef struct Entrada {
    char palavra[tamanhoMaxPalavra];
    char definicao[tamanhoMaxDefinicao];
} Entrada;

typedef struct No {
    Entrada dados;
    struct No *proximo;
} No;

typedef struct TabelaHash {
    No **compartimentos;
    int tamanho;
    int totalElementos;
    int totalColisoes;
} TabelaHash;

TabelaHash *tabelaCriar(int tamanho);
void tabelaDestruir(TabelaHash *tabela);

int tabelaInserir(TabelaHash *tabela, const char *palavra, const char *definicao);
Entrada *tabelaBuscar(TabelaHash *tabela, const char *palavra);
int tabelaRemover(TabelaHash *tabela, const char *palavra);

void tabelaExibir(TabelaHash *tabela);
void tabelaEstatisticas(TabelaHash *tabela);

unsigned int funcaoHash(const char *palavra, int tamanhoTabelaHash);

#endif
