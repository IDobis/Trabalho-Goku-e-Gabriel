#ifndef INTERFACE_H
#define INTERFACE_H

#define COR_RESET   "\x1b[0m"
#define COR_NEGRITO "\x1b[1m"
#define COR_FRACO   "\x1b[2m"

#define COR_VERMELHO "\x1b[31m"
#define COR_VERDE    "\x1b[32m"
#define COR_AMARELO  "\x1b[33m"
#define COR_AZUL     "\x1b[34m"
#define COR_MAGENTA  "\x1b[35m"
#define COR_CIANO    "\x1b[36m"
#define COR_BRANCO   "\x1b[37m"

#define LARGURA_PAINEL 50

void interfaceIniciar(void);
void interfaceLimparTela(void);

void interfaceTitulo(const char *texto);
void interfaceLinhaTopo(void);
void interfaceLinhaMeio(void);
void interfaceLinhaBase(void);
void interfaceLinhaTexto(const char *cor, const char *texto);

void interfaceSucesso(const char *texto);
void interfaceErro(const char *texto);
void interfaceInfo(const char *texto);

#endif
