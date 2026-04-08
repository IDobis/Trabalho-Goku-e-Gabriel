Esse código implementa um verificador de parênteses, colchetes e chaves balanceados utilizando uma estrutura de dados chamada Pilha (Stack), baseada em uma lista encadeada.
A ideia central é que, em uma expressão matemática correta, o último símbolo de abertura lido deve ser o primeiro a ser fechado (LIFO - Last In, First Out).


1. A Estrutura da Pilha (Stack)
O código define dois structs:

Node: É o "nó" da lista. Ele guarda um caractere (data) e um ponteiro para o próximo elemento (next).
Stack: Contém apenas o ponteiro para o topo da pilha.

2. Funções de Manipulação
push: Adiciona um caractere ao topo. Ela aloca memória dinamicamente, coloca o novo nó "em cima" do anterior e atualiza o topo.
pop: Remove o caractere do topo. Ela guarda o valor, aponta o topo para o próximo elemento e libera a memória (free) do nó removido.
isEmpty: Apenas checa se o topo é NULL, o que indica que a pilha está vazia.

3. A Lógica de Balanceamento (isBalanced)
Esta é a função principal do algoritmo. Ela percorre a string caractere por caractere:

Se encontrar abertura (, [ ou {: Ela faz um push na pilha. Estamos "guardando a promessa" de que esse símbolo será fechado depois.

Se encontrar fechamento ), ] ou }:
Primeiro, verifica se a pilha está vazia. Se estiver, a expressão é inválida (há um fechamento sem abertura).
Se não estiver vazia, faz um pop para pegar o último símbolo aberto e usa a função isMatchingPair para ver se eles combinam (ex: se saiu um ( para fechar um )).
Se não combinarem, a expressão é inválida.

Finalização: Após percorrer toda a string, a pilha deve estar vazia. Se sobrar algo lá dentro, significa que algum símbolo foi aberto mas nunca fechado.


Pontos Importantes no Código:
Gestão de Memória: O código é cuidadoso e usa free(temp) no pop para evitar vazamentos de memória (memory leaks).
Limpeza Final: No final de isBalanced, existe um while(!isEmpty(&stack)) pop(&stack);. Isso garante que, mesmo que a função retorne antes ou termine com erro, a memória alocada para a pilha seja liberada.
Entrada de dados: O fgets é usado com strcspn para ler a frase do usuário e remover a quebra de linha (\n) automática que o teclado insere.
