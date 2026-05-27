# Explain.MD — Como explicar ao professor

---

## Lucas — Questões 1 e 2

### Questão 1 — Fibonacci ingênuo

- O programa pede `n` e calcula F(n) com a função `fibonacci`.
- **Caso base:** `n == 0` retorna 0; `n == 1` retorna 1.
- **Redução:** para `n > 1`, chama `fibonacci(n-1)` e `fibonacci(n-2)` e soma.
- A variável `chamadas` conta quantas vezes a função entrou — mostra que o método é lento porque recalcula os mesmos valores várias vezes.

**Demonstração:** rodar com `n = 10` e mostrar o número alto de chamadas.

### Questão 2 — Fibonacci com memoização

- Usa a mesma ideia recursiva, mas antes de calcular verifica o array `cache`.
- O `cache` é criado com `malloc` no `main` e liberado com `free`.
- Se `cache[n]` já tem valor, retorna direto (não recalcula).
- No final o programa imprime **memoizado** e **ingênuo** com o mesmo `n` para comparar as chamadas.

**Demonstração:** `n = 30` — poucas chamadas no memoizado e muitas no ingênuo.

---

## Maria — Questão 3

### Torres de Hanoi

- O programa pede quantos discos existem.
- A função `hanoi` é recursiva.
- **Caso base:** 1 disco — imprime um movimento de origem para destino.
- **Redução:** com `n` discos, move `n-1` para o auxiliar, move o maior para o destino, depois move os `n-1` do auxiliar para o destino.
- No final mostra o total de movimentos (para 3 discos são 7).

**Demonstração:** usar 3 discos e conferir os 7 passos na tela.

---

## Fechamento (os dois)

- Os três programas usam recursão com caso base claro no código.
- Não há variáveis globais.
- A diferença principal entre as questões 1 e 2 é o **cache**: mesma lógica, menos retrabalho.
