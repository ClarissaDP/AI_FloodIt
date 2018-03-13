Clarissa Dreischerf Pereira

Ivo de Souza Bueno Júnior

**********************************
CI209 / CI752

Inteligência Artificial

Primeiro semestre de 2017

#### Trabalho prático - Jogo Floodit ####
**********************************

**Descrição:** http://www.inf.ufpr.br/fabiano/ci209/trabalho.txt


**Lógica:**
  - Algoritmo guloso que escolhe a cor que mais vai colorir, até uma certa quantidade de jogadas no futuro, nas regiões adjacentes à região do canto superior esquerdo.

**Ideia:**
1. Leitura da matriz inicial do jogo
2. Define profundidade x da árvore de busca baseada no tamanho da matriz e quantidade de cores
3. Cria árvore de possibilidades para a primeira cor do canto superior esquerdo, para x quantidades de jogadas no futuro (profundidade)
4. Cria filtro para varrer vizinhança
5. Varre vizinhança da cor do canto superior esquerdo (escolhe cor)
    - Percorre a vizinhança da cor atual pintando a matriz de filtro (matriz de 0 e 1) com a cor do nodo atual na árvore de possibilidades criada anteriormente, para saber quantas células seriam pintadas se aquela cor fosse escolhida  
    - Percorre toda a árvore de possibilidades realizando 5.1
    - Retorna qual cor pintará mais células em x jogadas
6. Pinta matriz original do jogo com a cor retornada em 5
7. Libera todos os nodos e matrizes de filtro da árvore de possibilidades
8. Repete desde o passo 3. até que matriz esteja completamente pintada de uma única cor
