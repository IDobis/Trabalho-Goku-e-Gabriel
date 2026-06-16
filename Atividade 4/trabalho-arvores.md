Tipos de Árvores

1. AVL

A árvore AVL é uma Árvore Binária de Busca auto balanceada, criada por Adelson Velsky e Landis, ela mantém a diferença de altura entre as subárvores esquerda e direita de cada nó em no máximo 1.

Características 

Ela possui uma estrutura binária, cada nó pode ter no máximo dois filhos ela realiza balanceamento automático sempre que ocorre alguma operação que provoque desequilíbrio na árvore. Para corrigir esses problemas são utilizadas rotações simples ou dupla, graças a esse mecanismo, as operações de busca, inserção e remoção mantêm um desempenho eficiente mesmo quando a quantidade de dados armazenados é grande.

Vantagens e Desvantagens 

A principal vantagem da Árvore AVL é o excelente desempenho nas operações de bsuca, já que a estrutura permanece sempre balanceada, isso garante uma complexidade de O(log n), tornando a localização de elementos rápida e prvisível.
Apesar de bom desempenho, a implementação da árvore AVL é mais complexa do que a de uma ávore binária de busca comum, além disso, inserções e remoções podem exigir rotações fequentes para manter o balanceamento da estrutura.

Exemplo Ilustrado 

Antes do balanceamento:

          30
        /
      20
     /
    10

Após rotação:

         20
       /    \
    10       30

2. Rubro-Negra

A árvore é uma BST balanceada que utiliza cores vermelho e preta para organizar seus nós, essas cores seguem regras especifícas que ajudam a manter a  árvore balanceada e garantem eficiência nas operações de busca, inserção e remoção

Regras de Coloração 

Todo nó deve ser vermelho ou preto, a raiz da árvore  deve ser preta e um nó vermelho não pode possuir filhos vermelhos, além disso, todos os caminhos da raiz até as folhas devem possuir a mesma quantidade de nós pretos

Vantagens e Desvantagens


A árvore Rubro-Negra realiza menos rotações que a AVL durante inserções e remoções, tornando essas operações mais rápidas em muitas situações, por isso é bastante utilizada em bibliotecas e sistemas computacionais
sua implementação é mais complexa devido ás regras de colaração e balanceamento, além disso a bsuca pode ser ligeiramente menos eficiente que uma árvere AVL

Exemplo Ilustrado:

         20(P)
       /      \
    10(V)      30(V)

   
P = Preto
V = Vermelho 

3. N-ária

A árvore é uma estrutura de dados hierárquica em que cada nó pode possuir vários filhos, diferentemente das árvores binárias, que permitem no máximo dois filhos por nó, a árvore N-ária possibilita uma quantidade maior de ramificações, tonando-se adequada para representar estruturas mais complexas

Diferenças 

A principal diferença é a quantidade de filhos que cada nó pode possuir, enquanto uma árvore binária permite apenas dois filhos, ela árvore N-ária pode ter vários filhos, uma árvore N-ária pode ter vários filhos, dependendo da necessidade da aplicação

Vantagens e Desvantagens 

Representa melhor estruturas hierárquicas complexas, tornando a organização dos dados mais natural em determinadas aplicações. A implementação pode ser mais complexa e algumas operações podem depender da quantidade de filhos existentes em cada nó.

Exemplo Ilustrado:

               A
            /  |  \
          B    C   D
        /   \      |
      E      F     G

Aplicações Práticas 

As árvores N-árias são utilizadas em sistemas de arquivos, menus de aplicativo, estruturas organizacionais.

Rotação Simples a Direita 

A rotação ela é utilizada para corrigir o desequilibrio de um árvore quando há excesso de nós na sub
