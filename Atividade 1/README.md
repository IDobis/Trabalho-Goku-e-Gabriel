# Trabalho em Linguagem C

Exercício 1
O programa tem como objetivo realizar a leitura de três palavras informadas pelo usuário e exibi-las em ordem inversa. Para isso, são utilizados três vetores de caracteres capazes de armazenar cadeias de texto. A leitura é realizada por meio da função scanf utilizando três especificadores de formato (%s), permitindo a captura sequencial das entradas. Cada palavra pode ser representada como uma sequência de caracteres ( P_1, P_2, P_3 ). A inversão ocorre apenas no momento da saída, sendo exibida na ordem ( P_3, P_2, P_1 ), sem alteração da organização interna na memória. Esse procedimento demonstra a manipulação lógica da saída mantendo a integridade dos dados armazenados.

Exercício 2
Este programa realiza a leitura de cinco valores inteiros e os armazena em um vetor de tamanho fixo. Considerando o vetor como ( V = [v_0, v_1, v_2, v_3, v_4] ), a leitura é feita sequencialmente utilizando um laço for, garantindo que cada posição seja preenchida corretamente. A exibição em ordem inversa corresponde à impressão dos elementos na sequência ( v_4, v_3, v_2, v_1, v_0 ). Essa operação não altera os valores armazenados, apenas modifica a ordem de acesso aos índices, caracterizando um percurso reverso do vetor.

Exercício 3
O programa tem como finalidade ler uma matriz de ordem 3x3 e aplicar uma multiplicação escalar em todos os seus elementos. A matriz pode ser representada por ( M \in \mathbb{Z}^{3 \times 3} ), onde cada elemento é denotado por ( M[i][j] ). A leitura é realizada por meio de laços aninhados que percorrem as dimensões da matriz. A operação realizada consiste na multiplicação de cada elemento por um escalar ( k = 5 ), resultando em uma nova matriz ( M' ), definida por ( M'[i][j] = 5 \cdot M[i][j] ). A exibição mantém a estrutura matricial original, evidenciando a transformação aplicada a cada posição.

Exercício 4
Neste programa, é realizada a leitura de uma matriz ( A \in \mathbb{Z}^{3 \times 3} ) e a construção de uma matriz identidade ( I ) de mesma ordem. A matriz identidade é definida por ( I[i][j] = 1 ) quando ( i = j ) e ( I[i][j] = 0 ) quando ( i \neq j ). Em seguida, é implementada a multiplicação matricial entre ( A ) e ( I ), conforme a definição formal do produto de matrizes, onde cada elemento da matriz resultante ( C ) é dado por
( C[i][j] = \sum\_{k=0}^{2} A[i][k] \cdot I[k][j] ).
Como a matriz identidade possui 1 apenas na diagonal principal, o somatório se reduz ao elemento correspondente da matriz original, resultando em ( C[i][j] = A[i][j] ). Dessa forma, o programa demonstra computacionalmente a propriedade fundamental da matriz identidade, onde ( A \cdot I = A ).

Exercício 5
O programa realiza a leitura de um vetor ( V \in \mathbb{Z}^3 ) e de uma matriz ( M \in \mathbb{Z}^{3 \times 3} ). A operação executada consiste na multiplicação do vetor pelas colunas da matriz, que pode ser interpretada como o cálculo do produto escalar entre o vetor e cada coluna da matriz. Para cada coluna ( j ), o resultado é calculado por
( R[j] = \sum\_{i=0}^{2} V[i] \cdot M[i][j] ).
O vetor resultante ( R ) contém os valores obtidos dessa operação, onde cada posição corresponde ao produto escalar do vetor com uma coluna específica da matriz. O programa exibe o vetor original, a matriz e o resultado final, permitindo a visualização clara da transformação realizada e da relação matemática entre os dados.
