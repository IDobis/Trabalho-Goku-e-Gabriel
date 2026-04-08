  Este código implementa um simulador de fila de atendimento utilizando a linguagem C, baseado em uma
estrutura de dados do tipo fila (queue) com lista encadeada. A lógica principal segue o modelo FIFO (First In,
First Out), em que o primeiro cliente a entrar na fila será o primeiro a ser atendido, simulando situações reais
como filas de banco ou atendimento ao público.

  A estrutura do programa é formada por dois tipos principais. O primeiro é a struct Cliente, que representa
cada pessoa na fila. Ela armazena um identificador, o tempo necessário para o atendimento e um ponteiro
para o próximo cliente, permitindo formar uma sequência encadeada. O segundo é a struct Fila, que
mantém dois ponteiros: um para o início da fila e outro para o fim. Isso facilita tanto a inserção de novos 
clientes quanto a remoção dos já atendidos.

  O funcionamento da fila começa com a função inicializarFila, que define os ponteiros de início e fim como
NULL, indicando que a fila está vazia. A função enqueue é responsável por adicionar novos clientes ao final
da fila. Ela cria um novo nó utilizando alocação dinâmica de memória com malloc, preenche os dados do
cliente e ajusta os ponteiros. Se a fila estiver vazia, esse novo cliente passa a ser o primeiro e o último ao
mesmo tempo. Caso contrário, ele é adicionado após o último elemento existente, mantendo a ordem correta.

  A função dequeue realiza a remoção do primeiro cliente da fila. Ela verifica se a fila está vazia e, se não
estiver, remove o elemento do início, atualizando o ponteiro para o próximo cliente. Se, após a remoção, não
restar nenhum elemento, o ponteiro de fim também é ajustado para NULL. Essa função retorna o cliente
removido, permitindo que seus dados sejam utilizados antes da liberação da memória.

  No programa principal, o usuário informa quantos clientes deseja inserir. Para cada cliente, são lidos o ID e o
tempo de atendimento, e esses dados são inseridos na fila por meio da função enqueue. Após a inserção de
todos os clientes, o programa inicia a simulação do atendimento.

  Durante a simulação, o programa utiliza um laço que continua enquanto houver clientes na fila. A cada
iteração, um cliente é removido com dequeue, seu ID é exibido e o tempo de espera é calculado. Esse tempo
começa em zero e vai sendo acumulado conforme os atendimentos anteriores acontecem, representando o
tempo real que cada cliente aguardou antes de ser atendido.

  Após exibir as informações de cada cliente, o programa soma o tempo de atendimento ao total acumulado
e libera a memória do cliente com a função free, evitando vazamentos de memória. Ao final, todos os
clientes terão sido atendidos e a fila estará vazia. O código demonstra de forma clara o uso de estruturas de
dados, ponteiros e alocação dinâmica, além de representar uma aplicação prática bastante comum.
