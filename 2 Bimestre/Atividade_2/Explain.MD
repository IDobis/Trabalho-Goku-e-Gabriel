# Explain — Apresentação ao professor

Programa **interativo**: o usuário digita valores, posições e nomes das músicas nos menus.

Arquivo único: `atividade.c` (sem `.h`).

---

## Lucas — Partes 1, 2 e 3

No menu **Gerenciador de inteiros**, o usuário monta a lista na hora.

### Parte 1 — `inserirPosicao`

O usuário informa **valor** e **posição** (inicia em 0).

Funciona em lista vazia, início, meio e fim. Posição inválida mostra erro.

Demonstração: inserir 10, 20, 30 e depois 99 na posição 1 → `10 -> 99 -> 20 -> 30`.

### Parte 2 — `buscarValor`

O usuário digita o valor; o programa retorna a posição ou avisa que não achou (`-1`).

### Parte 3 — `inverterLista`

Inverte só com ponteiros, sem vetor e sem criar outra lista.

---

## Maria — Partes 4 e 5

### Parte 4 — `dividirLista`

Opção 4 do menu de inteiros: divide a lista atual em duas com ponteiro lento/rápido, sem contar antes. Se for ímpar, a primeira fica maior.

Exemplo: `10 -> 20 -> 30 -> 40 -> 50` → lista1: `10,20,30` e lista2: `40,50`.

### Parte 5 — Playlist

Menu **Playlist** com lista circular dupla.

- `adicionarMusica` — usuário digita o nome
- `proximaMusica` / `musicaAnterior` — navegação circular
- `exibirPlaylist` / `totalMusicas`
- Opção **Tocar todas** — usa contador para não entrar em loop infinito

A estrutura da playlist usa `NoPlaylist` no código (mesmos campos do enunciado: `musica`, `prox`, `ant`), pois `No` já é usado para inteiros no mesmo arquivo.

---

## Demonstração em sala

1. Compilar e executar
2. Menu 1: montar `10 -> 20 -> 30`, inserir 99 na posição 1, buscar 20, inverter
3. Montar lista com 5 elementos e dividir
4. Menu 2: adicionar Rock, Jazz, Pop; navegar e tocar todas
