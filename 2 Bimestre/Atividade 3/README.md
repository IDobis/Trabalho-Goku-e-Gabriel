# Dicionário com Tabela Hash (C)

Sistema de dicionário em linguagem C com resolução de colisões por **listas encadeadas** (encadeamento separado).

## Convenções de nomenclatura

- **PascalCase**: tipos (`Entrada`, `No`, `TabelaHash`)
- **camelCase**: funções, variáveis e campos (`tabelaInserir`, `totalElementos`, `compartimentos`)
- **pt-BR**: identificadores e mensagens em português

## Requisitos atendidos

| Funcionalidade | Descrição |
|----------------|-----------|
| Inserir | Palavra + definição (atualiza se a palavra já existir) |
| Buscar | Retorna a definição da palavra |
| Remover | Remove entrada da lista encadeada do compartimento |
| Exibir tabela | Mostra compartimentos ocupados e cadeias |
| Estatísticas | Elementos, colisões, fator de carga, maior lista |

## Estruturas

- `Entrada`: palavra e definição
- `No`: nó da lista encadeada (ponteiro `proximo`)
- `TabelaHash`: vetor de ponteiros para listas + contadores

## Compilação

### Linux / MinGW (make)

```bash
make
./dicionario
```

### Windows (gcc direto)

```bash
gcc -Wall -Wextra -std=c99 -o dicionario.exe principal.c tabelaHash.c
dicionario.exe
```

## Estatísticas

- **Número de elementos**: total de pares palavra/definição na tabela
- **Número de colisões**: incrementado quando um novo elemento é inserido em compartimento já ocupado
- **Fator de carga**: `totalElementos / tamanho`
- **Maior lista encadeada**: maior quantidade de nós em um único compartimento

## Arquivos

- `tabelaHash.h` / `tabelaHash.c` — implementação da tabela hash
- `principal.c` — menu interativo
- `Makefile` — build
