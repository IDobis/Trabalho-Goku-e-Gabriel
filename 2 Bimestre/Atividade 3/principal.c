#include "tabelaHash.h"
#include "interface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void limparBuffer(void) {
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

static void lerLinha(char *destino, int tamanho) {
    if (fgets(destino, tamanho, stdin) != NULL) {
        destino[strcspn(destino, "\n")] = '\0';
    } else {
        destino[0] = '\0';
    }
}

static void pausar(void) {
    printf("\n%s  Pressione ENTER para continuar...%s", COR_FRACO, COR_RESET);
    limparBuffer();
}

static void exibirMenu(void) {
    interfaceTitulo("DICIONARIO - TABELA HASH");
    interfaceLinhaTexto(COR_VERDE,   "  [1] Inserir palavra e definicao");
    interfaceLinhaTexto(COR_VERDE,   "  [2] Buscar palavra");
    interfaceLinhaTexto(COR_VERDE,   "  [3] Remover palavra");
    interfaceLinhaTexto(COR_AZUL,    "  [4] Exibir tabela hash");
    interfaceLinhaTexto(COR_AZUL,    "  [5] Exibir estatisticas");
    interfaceLinhaTexto(COR_VERMELHO,"  [0] Sair");
    interfaceLinhaBase();
    printf("%s  Escolha uma opcao: %s", COR_NEGRITO, COR_RESET);
}

int main(void) {
    TabelaHash *tabela;
    int opcao;
    char palavra[tamanhoMaxPalavra];
    char definicao[tamanhoMaxDefinicao];
    Entrada *entradaEncontrada;

    interfaceIniciar();

    tabela = tabelaCriar(tamanhoTabela);
    if (tabela == NULL) {
        interfaceErro("Erro ao alocar a tabela hash.");
        return 1;
    }

    interfaceLimparTela();

    do {
        exibirMenu();

        {
            int lido = scanf("%d", &opcao);
            if (lido == EOF) {
                opcao = 0;
                break;
            }
            if (lido != 1) {
                limparBuffer();
                interfaceLimparTela();
                interfaceErro("Opcao invalida.");
                continue;
            }
        }
        limparBuffer();
        interfaceLimparTela();

        switch (opcao) {
            case 1:
                interfaceTitulo("INSERIR PALAVRA");
                interfaceLinhaBase();
                printf("%s  Palavra: %s", COR_NEGRITO, COR_RESET);
                lerLinha(palavra, tamanhoMaxPalavra);

                printf("%s  Definicao: %s", COR_NEGRITO, COR_RESET);
                lerLinha(definicao, tamanhoMaxDefinicao);

                if (palavra[0] == '\0') {
                    interfaceErro("Palavra nao pode ser vazia.");
                    pausar();
                    break;
                }

                if (tabelaInserir(tabela, palavra, definicao)) {
                    interfaceSucesso("Inserido com sucesso.");
                } else {
                    interfaceErro("Falha na insercao.");
                }
                pausar();
                break;

            case 2:
                interfaceTitulo("BUSCAR PALAVRA");
                interfaceLinhaBase();
                printf("%s  Palavra para buscar: %s", COR_NEGRITO, COR_RESET);
                lerLinha(palavra, tamanhoMaxPalavra);

                entradaEncontrada = tabelaBuscar(tabela, palavra);
                if (entradaEncontrada != NULL) {
                    interfaceSucesso("Palavra encontrada!");
                    printf("%s    Palavra  :%s %s\n", COR_CIANO, COR_RESET, entradaEncontrada->palavra);
                    printf("%s    Definicao:%s %s\n", COR_CIANO, COR_RESET, entradaEncontrada->definicao);
                } else {
                    interfaceErro("Palavra nao encontrada.");
                }
                pausar();
                break;

            case 3:
                interfaceTitulo("REMOVER PALAVRA");
                interfaceLinhaBase();
                printf("%s  Palavra para remover: %s", COR_NEGRITO, COR_RESET);
                lerLinha(palavra, tamanhoMaxPalavra);

                if (tabelaRemover(tabela, palavra)) {
                    interfaceSucesso("Removido com sucesso.");
                } else {
                    interfaceErro("Palavra nao encontrada.");
                }
                pausar();
                break;

            case 4:
                tabelaExibir(tabela);
                pausar();
                break;

            case 5:
                tabelaEstatisticas(tabela);
                pausar();
                break;

            case 0:
                interfaceInfo("Encerrando o dicionario. Ate logo!");
                break;

            default:
                interfaceErro("Opcao invalida.");
                pausar();
                break;
        }

        if (opcao != 0) {
            interfaceLimparTela();
        }
    } while (opcao != 0);

    tabelaDestruir(tabela);
    return 0;
}
