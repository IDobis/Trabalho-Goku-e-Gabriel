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

Exercício 6
O programa realiza a leitura de dados de 10 alunos utilizando uma struct denominada Aluno, contendo os campos Nome, Matricula e MediaFinal, conforme implementado em . A entrada dos dados é feita de forma sequencial, garantindo que cada valor seja atribuído corretamente às variáveis correspondentes. Os dados são armazenados em um vetor principal e posteriormente classificados em dois novos vetores, aprovados e reprovados, com base na condição (MediaFinal \geq 6.0). Formalmente, seja um conjunto de alunos (A = {a*1, a_2, ..., a*{10}}), onde cada aluno possui uma média associada, o programa realiza uma partição do conjunto em dois subconjuntos (A*{aprovados}) e (A*{reprovados}), definidos por
(A*{aprovados} = { a_i \in A \mid MediaFinal_i \geq 6.0 })
(A*{reprovados} = { a_i \in A \mid MediaFinal_i < 6.0 }).
A saída exibe os dados completos de cada subconjunto, demonstrando a aplicação de estruturas de dados e lógica condicional.

Exercício 7
O programa utiliza uma struct denominada Livro para armazenar informações de cinco livros, contendo título, autor e ano, conforme definido em . Os dados são lidos de forma sequencial e armazenados em um vetor (L = {l*1, l_2, l_3, l_4, l_5}). Após a leitura, o usuário informa um título para busca. O programa percorre o vetor e realiza uma comparação entre strings utilizando a função strcmp, que pode ser interpretada como uma função de equivalência (f(t_i, t*{busca})), onde o resultado é verdadeiro quando (t*i = t*{busca}). Assim, o conjunto de resultados pode ser descrito como
(R = { l*i \in L \mid Titulo_i = Titulo*{buscado} }).
Todos os elementos pertencentes a esse conjunto são exibidos. Caso (R = \emptyset), o programa informa que nenhum livro foi encontrado, caracterizando uma busca sequencial em estrutura linear.

Exercício 8
O programa trabalha com um vetor de cinco elementos inteiros, utilizando exclusivamente aritmética de ponteiros para acesso e manipulação dos dados, conforme implementado em . Considerando o vetor (V = [v_0, v_1, v_2, v_3, v_4]), o ponteiro inicial referencia o primeiro elemento, e os demais são acessados por deslocamento de memória (\*(ptr + i)). A operação realizada consiste no cálculo do dobro de cada elemento, resultando em um novo conjunto de valores definido por
(v'\_i = 2 \cdot v_i), para (i = 0, 1, 2, 3, 4).
A saída apresenta os valores transformados, demonstrando o uso de ponteiros e acesso indireto à memória.

Exercício 9
O programa realiza a leitura de três valores inteiros e utiliza uma função para ordená-los diretamente nas variáveis originais, conforme apresentado em . A função recebe os valores por referência, permitindo a modificação direta das variáveis externas. Seja o conjunto inicial (S = {a, b, c}), o objetivo é reorganizar os valores de forma que (a \leq b \leq c). A ordenação é realizada por meio de comparações e trocas entre os elementos. Após o processo, a função verifica a condição de igualdade total, definida por
(a = b \land b = c), retornando 1 quando verdadeira e 0 caso contrário.
O programa exibe os valores ordenados e o resultado da função, evidenciando o uso de passagem por referência e lógica de ordenação.

Exercício 10
O programa define uma struct chamada Aluno contendo os campos Nome e Nota, realizando a alocação dinâmica de memória para armazenar (n) alunos, conforme implementado em . Seja o conjunto (A = {a*1, a_2, ..., a_n}), onde cada elemento possui uma nota associada. O programa percorre esse conjunto utilizando aritmética de ponteiros para identificar o elemento com maior valor. Formalmente, o objetivo é encontrar
(a*{max} \in A \mid Nota\_{max} = \max(Nota_1, Nota_2, ..., Nota_n)).
A função retorna um ponteiro para esse elemento, que é então exibido na saída. Ao final, a memória alocada dinamicamente é liberada, demonstrando o uso correto de ponteiros, alocação dinâmica e busca de máximo em estrutura linear.
