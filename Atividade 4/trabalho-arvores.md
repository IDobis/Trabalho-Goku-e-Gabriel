Tipos de Árvores

1. AVL

É uma Árvore Binária de Busca (BST) que possui balanceamento automático, ela foi criada por Adelson-Velsky e Landis com o objetivo de manter a árvore organizada e eficiente, sua principal característica é que a diferença de altura entre as subárvores esquerda e direita de cada nó não pode ser maior que 1, evitando que a árvore fique balanceada.

Características 

Ela possui uma estrutura binária, ou seja, cada nó pode ter no máximo dois filhos, sempre que uma inserção ou remoção causa desequilíbrio, a árvore realiza ajustes automaticamente para voltar ao estado balanceado, esses ajustes são feitos por meio de rotações simples ou duplas, graças a esse mecanismo, as operações de busca, inserção e remoção continuam apresentando um bom desempenho mesmo quando a quantidade de dados armazenados é grande.

Vantagens e Desvantagens 

Uma das principais vantagens é o seu desempenho nas operações de busca, já que ela permanece balanceada durante o uso, isso faz com que a busca por elementos seja rápida e previsível, com complexidade O(log n).
Porém, sua implementação é mais complexa quando comparada a uma árvore binária de busca comum, além disso para manter o balanceamento, podem ser necessárias rotações frequentes após inserções e remoções, o que aumenta o trabalho realizado pela estrutura.

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

Cada nó deve ser classificado como vermelho ou preto, a raiz da árvore deve ser sempre preta, e um nó vermelho não pode ter filhos também vermelhos, além disso todos os caminhos da raiz até as folhas devem conter a mesma quantidade de nó pretos, ajudando a manter a árvore balanceada e eficiente.

Vantagens e Desvantagens


Ela realiza menos rotações que a AVL durante inserções e remoções, tornando essas operações mais rápidas em muitas situações, por isso é bastante utilizada em bibliotecas e sistemas computacionais
sua implementação é mais complexa devido ás regras de colaração e balanceamento, além disso a bsuca pode ser ligeiramente menos eficiente que uma árvere AVL.

Exemplo Ilustrado:

         20(P)
       /      \
    10(V)      30(V)

   
P = Preto
V = Vermelho 

3. N-ária

É uma estrutura de dados hierárquica em cada nó pode possuir vários filhos. Diferente das árvores binárias, que permitem ao máximo dois filhos por nó, á árvore N-ária pode um número maior de ramificações, sendo muito utilizada para representar estruturas mais complexas e organizadas em níveis.

Diferenças 

A principal diferença entre uma árvore binária e uma árvore N-ária está na quantidade de filhos que cada nó pode possuir, enquanto a árvore binária permite dois filhos por nó, a árvore N-ária pode ter vários filhos, de aocrdo com a necessidade da aplicação, isso torna essa estrutura mais adequada para representar a hierarquias com muitos elementos relacionados.

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

A rotação ela é utilizada para corrigir o desequilibrio de um árvore quando há excesso de nós na subárvore esquerda. Seu objetivo é restaurar o balancemaneto e manter a eficiência das operações.

Situação:  Essa rotação ocorre em uma situação conhecida como Esquerda-Esquerda (LL), quando um novo nó é inserido na subárvore esquerda do filho esquerdo 

Exemplo 

            30
          /
       20
      /
    10

Exemplo de depois da rotsção:

        20
     /     \
    10      30


Rotação Simples á Esquerda 

A rotação á esquerda é utilizada para corrigir o desequilibrio causado pelo crescimento excessivo da subárvore direita.

Situação: Ocorre na siruação Direita-Direita (RR) quando um novo nó é inserido na subárvore direita do filho direito.

Exemplo Antes:

     10
       \
        20
         \
          30 

Exemplo Depois:

       20
      /   \
    10     30

Rotação Dupla 

Esquerda-Direita : é utilizada quando o desequilíbrio acontece na subárvore esquerda, mas o novo elemento foi inserido á direita do filho esquerdo. Nesse caso, é necessário realizar duas ratações para que a árvore volte a ficar balanceada. 

Exemplo antes:

        30
      /
    10
      \ 
       20

Exemplo depois:

      20 
     /   \
    10    30

Direita-Esquerda: Acontece quando o desequilíbrio ocorre na subárvore direita, mas o novo elemento foi inserido á esquerda do filho direito. Assim como no caso anterior, são necessárias duas rotações para corrigir a estrutura.

Exemplo antes: 

    10
      \
       30
      /
     20

Exemplo depois:

        20
      /   \
     10    30

Inversão (espelhamento)
É uma operação que troca a posição dos filhos esquerdo e direito de todos os nós da árvore, o resultado é uma estrutura que representa o espelho da árvore original.

Ela pode ser aplicada em estudos de estruturas de dados, testes de algoritmos e aplicações que necessitam compararbárvores ou gerar versões espelhadas de uma estrutura.

Exemplo antes da operação:
           
        10
      /    \
    5       15

Exemplo Depois:

         10
       /    \
     15      5

Aplicações na Prática 
Sistemas de Arquivos 
Estre as estruturas que foi pesquisada, a árvore N-ária é a mais adequada para representar um sistema de arquivos, isso acontece porque uam pasta pode conter diversos arquivos e subpastas, não ficando limitada a apenas dois filhos como ocorre uma árvore binária. A utilização da árvore N-ária permite organizar os dados de forma hierárquica e intuitiva, facilitando a navegação entre diretórios e a localização de informações, além disso, essa estrutura oferece flexibilidade para armezenar uma grande quantidade de arquivos e pastas sem comprometer a organização do sistema. Um exemplo que poderia usar é a pasta "Documentos", que pode conter várias outras pastas, como "faculdade" ou "Projetos", além de arquivos individuais, dessa forma a árvore N-ária representa muito bem a estrutura utilizada pelos sistemas operacionais atuais.


  | Estrutura | Nº Máximo de Filhos | Balanceamento | Complexidade de Busca | Complexidade de Inserção | Vantagem Principal | Desvantagem Principal | Exemplo de Aplicação |
|------------|------------|------------|------------|------------|------------|------------|------------|
| BST | 2 | Não possui balanceamento automático | O(log n) melhor caso e O(n) pior caso | O(log n) melhor caso e O(n) pior caso | Simplicidade de implementação | Pode ficar desbalanceada | Árvores de busca básicas |
| AVL | 2 | Sim, através de rotações | O(log n) | O(log n) | Busca muito eficiente | Mais rotações durante atualizações | Índices e sistemas de consulta |
| Rubro-Negra | 2 | Sim, através de coloração e rotações | O(log n) | O(log n) | Menos rotações que a AVL | Implementação mais complexa | Bibliotecas e sistemas operacionais |
| N-ária | N | Depende da implementação | O(log n) em estruturas balanceadas | O(log n) ou proporcional à estrutura | Representa hierarquias complexas | Estrutura mais complexa | Sistemas de arquivos |

Explicação 
Ao analisar a tabela, podemos perceber que cada tipo de árvore possui características próprias e é mais adequada para determinadas situações, a BST é a mais simples, porém pode perder desempenho caso fique desbalanceada, as árvores AVL e Rubro-Negra possuem mecanismos de balanceamento que ajudam a manter as operações mais eficientes, já a árvore N-ária se diferencia por permitir vários filhos em um mesmo nó, sendo muito utilizada para representar estruturas hierárquicas, como sistemas de arquivos. Dessa forma, a escolha da estrutura depende das necessidades de cada aplicação.

   
