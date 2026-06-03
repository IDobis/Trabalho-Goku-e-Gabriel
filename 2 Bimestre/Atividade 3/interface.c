#include "interface.h"

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#endif

static const char *BORDA_TL = "\xe2\x95\x94"; /* ╔ */
static const char *BORDA_TR = "\xe2\x95\x97"; /* ╗ */
static const char *BORDA_BL = "\xe2\x95\x9a"; /* ╚ */
static const char *BORDA_BR = "\xe2\x95\x9d"; /* ╝ */
static const char *BORDA_ML = "\xe2\x95\xa0"; /* ╠ */
static const char *BORDA_MR = "\xe2\x95\xa3"; /* ╣ */
static const char *BORDA_H  = "\xe2\x95\x90"; /* ═ */
static const char *BORDA_V  = "\xe2\x95\x91"; /* ║ */

void interfaceIniciar(void) {
#ifdef _WIN32
    HANDLE saida = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD modo = 0;

    SetConsoleOutputCP(CP_UTF8);

    if (GetConsoleMode(saida, &modo)) {
        SetConsoleMode(saida, modo | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }
#endif
}

void interfaceLimparTela(void) {
    printf("\x1b[2J\x1b[H");
}

static int larguraVisivel(const char *texto) {
    int largura = 0;

    while (*texto != '\0') {
        if ((*texto & 0xC0) != 0x80) {
            largura++;
        }
        texto++;
    }

    return largura;
}

static void repetir(const char *unidade, int vezes) {
    int i;
    for (i = 0; i < vezes; i++) {
        printf("%s", unidade);
    }
}

void interfaceLinhaTopo(void) {
    printf("%s%s", COR_CIANO, BORDA_TL);
    repetir(BORDA_H, LARGURA_PAINEL);
    printf("%s%s\n", BORDA_TR, COR_RESET);
}

void interfaceLinhaMeio(void) {
    printf("%s%s", COR_CIANO, BORDA_ML);
    repetir(BORDA_H, LARGURA_PAINEL);
    printf("%s%s\n", BORDA_MR, COR_RESET);
}

void interfaceLinhaBase(void) {
    printf("%s%s", COR_CIANO, BORDA_BL);
    repetir(BORDA_H, LARGURA_PAINEL);
    printf("%s%s\n", BORDA_BR, COR_RESET);
}

void interfaceLinhaTexto(const char *cor, const char *texto) {
    int usado = larguraVisivel(texto);
    int espacos = LARGURA_PAINEL - 1 - usado;

    if (espacos < 0) {
        espacos = 0;
    }

    printf("%s%s%s %s%s", COR_CIANO, BORDA_V, COR_RESET, cor, texto);
    printf("%s", COR_RESET);
    repetir(" ", espacos);
    printf("%s%s%s\n", COR_CIANO, BORDA_V, COR_RESET);
}

void interfaceTitulo(const char *texto) {
    int usado = larguraVisivel(texto);
    int total = LARGURA_PAINEL - usado;
    int esquerda = total / 2;
    int direita = total - esquerda;

    if (esquerda < 0) {
        esquerda = 0;
    }
    if (direita < 0) {
        direita = 0;
    }

    interfaceLinhaTopo();
    printf("%s%s%s", COR_CIANO, BORDA_V, COR_RESET);
    repetir(" ", esquerda);
    printf("%s%s%s%s", COR_NEGRITO, COR_AMARELO, texto, COR_RESET);
    repetir(" ", direita);
    printf("%s%s%s\n", COR_CIANO, BORDA_V, COR_RESET);
    interfaceLinhaMeio();
}

void interfaceSucesso(const char *texto) {
    printf("%s%s  [OK] %s%s\n", COR_NEGRITO, COR_VERDE, texto, COR_RESET);
}

void interfaceErro(const char *texto) {
    printf("%s%s  [X] %s%s\n", COR_NEGRITO, COR_VERMELHO, texto, COR_RESET);
}

void interfaceInfo(const char *texto) {
    printf("%s%s  > %s%s\n", COR_NEGRITO, COR_AZUL, texto, COR_RESET);
}
