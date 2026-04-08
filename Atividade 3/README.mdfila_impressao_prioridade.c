Este código implementa um simulador de fila de impressão utilizando a linguagem C, baseado em uma
estrutura de dados do tipo fila com prioridade, construída a partir de uma lista encadeada. A lógica principal
difere de uma fila comum, pois os elementos não são atendidos apenas pela ordem de chegada, mas sim
pela prioridade atribuída a cada documento. Nesse caso, quanto menor o valor da prioridade, mais urgente
é o documento e mais cedo ele será processado.

  A estrutura do programa é composta por dois tipos principais. O primeiro é a struct Documento, que
representa cada item da fila de impressão. Ela armazena um identificador, a quantidade de páginas, o nível
de prioridade e um ponteiro para o próximo documento, permitindo a formação de uma lista encadeada. O
segundo é a struct Fila, que possui apenas um ponteiro para o início da fila, já que a ordenação é feita no 
momento da inserção.

  O funcionamento começa com a função inicializarFila, que define o início da fila como NULL, indicando que
ela está vazia. A função enqueue é responsável por inserir novos documentos na fila, mas de forma
ordenada. Ela aloca memória dinamicamente para um novo documento, preenche seus dados e decide em
que posição ele deve ser inserido com base na prioridade. Se a fila estiver vazia ou se o novo documento
tiver prioridade maior (ou seja, valor menor) que o primeiro elemento, ele é inserido no início. 
Caso contrário, o código percorre a lista até encontrar a posição correta, garantindo que a fila permaneça 
sempre ordenada por prioridade.

  A função dequeue remove o primeiro documento da fila, que será sempre o de maior prioridade naquele
momento. Ela atualiza o ponteiro de início para o próximo elemento e retorna o documento removido. Essa
função garante que o processamento respeite a ordem de prioridade estabelecida.

  A função processarFila é responsável por simular a impressão dos documentos. Ela utiliza um laço que
continua enquanto houver elementos na fila. A cada iteração, um documento é removido com dequeue,
suas informações são exibidas na tela e sua memória é liberada com free. Isso simula o envio dos
documentos para impressão, respeitando a ordem de prioridade.

  No programa principal, o usuário informa quantos documentos deseja inserir na fila. Para cada documento,
são coletados o ID, o número de páginas e a prioridade. Esses dados são inseridos na fila por meio da
função enqueue, que garante que a ordem correta seja mantida desde o início.

  Ao final, a função processarFila é chamada para iniciar a simulação da impressão. O código demonstra o uso
de estruturas de dados com ordenação dinâmica, manipulação de ponteiros e gerenciamento de memória,
além de representar de forma prática o funcionamento de sistemas de impressão que utilizam prioridades para 
organizar tarefas.
