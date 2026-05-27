# Atividade 1 — Recursão em C

Três programas simples em C, um arquivo por questão.

## Regras

- **camelCase** para funções e variáveis
- Tudo em **pt-BR**
- Recursão no núcleo, sem variáveis globais

## Arquivos

| Arquivo | O que faz |
|---------|-----------|
| `questao1/fibonacciIngenuo.c` | Fibonacci recursivo + contagem de chamadas |
| `questao2/fibonacciMemoizado.c` | Fibonacci com cache (`malloc`) + comparação com ingênuo |
| `questao3/torresHanoi.c` | Torres de Hanoi + lista de movimentos |

## Compilar

```powershell
cd "c:\Users\Dobis\Documents\Faculdade\Goku\2bim\Atividade_1"
gcc -Wall -std=c11 -o questao1\fibonacciIngenuo.exe questao1\fibonacciIngenuo.c
gcc -Wall -std=c11 -o questao2\fibonacciMemoizado.exe questao2\fibonacciMemoizado.c
gcc -Wall -std=c11 -o questao3\torresHanoi.exe questao3\torresHanoi.c
```

Ou use `make` se estiver disponível.

## Executar

```powershell
.\questao1\fibonacciIngenuo.exe
.\questao2\fibonacciMemoizado.exe
.\questao3\torresHanoi.exe
```

Cada programa pede um valor no terminal e mostra o resultado.

## Valores de teste recomendados

| Programa | Entrada sugerida | Motivo |
|----------|------------------|--------|
| Questão 1 | `10` a `20` | Versão ingênua; muitas chamadas recursivas |
| Questão 2 | `30` a `50` | Memoização; valores grandes terminam rápido |
| Questão 3 | `3` discos | 7 movimentos; fácil de conferir na apresentação |

### Por que a questão 1 não aceita `n` muito alto?

Na versão **ingênua**, o mesmo valor de Fibonacci é recalculado várias vezes. O número de chamadas cresce muito rápido (comportamento exponencial). Exemplos aproximados:

| n | Chamadas recursivas |
|---|---------------------|
| 10 | ~177 |
| 20 | ~21 mil |
| 30 | ~2,6 milhões |
| 40 | ~331 milhões |
| 50 | bilhões (pode travar o computador) |

Por isso, na questão 1, se `n > 35` o programa exibe uma mensagem e encerra — evita esperar sem fim. Isso faz parte da demonstração da **ineficiência** do método ingênuo.

Para testar **F(50)** ou valores parecidos, use a **questão 2** (`fibonacciMemoizado`), que guarda resultados no cache e compara as chamadas com a versão ingênua.

Apresentação para o professor: veja `Explain.MD`.
