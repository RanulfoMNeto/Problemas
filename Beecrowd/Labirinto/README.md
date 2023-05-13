# Labirinto

Labirinto de papel é o passatempo favorito de Rafael, mas ele anda reclamando que os labirintos que ele encontra para resolver são muito fáceis. Para ser mais específico, a distância entre o início do labirinto e a saída é sempre muito pequena.

A entrada de um labirinto é por onde o jogador deve começar a resolvê-lo, e a saída é por onde o jogador deve terminar o labirinto. O jogador pode dar passos nas quatro direções – cima, direita, baixo ou esquerda – e a distância entre a entrada e a saída do labirinto é dado pela soma de passos do menor caminho que pode ser feito.

Dado um labirinto de $N$ linhas e $M$ colunas, diga qual a distância máxima que pode ser definida se a entrada e a saída for escolhida de forma ótima.

## Entrada

A entrada contém diversos casos de teste. Cada caso de teste inicia com dois inteiros $N$ e $M$ $(5 \leq N, M \leq 500)$, representando o número de linhas e colunas do labirinto, respectivamente.

A seguir haverá $N$ linhas contendo $M$ caracteres cada, representando o labirinto a ser analizado. O caractere da $i$-ésima linha e da $j$-ésima coluna indica o que há na posição $i$, $j$ do labirinto. Se o caractere for um “.” (ponto), significa que aquele é um espaço vazio, por onde o jogador pode passar. Caso seja um “#”, significa que aquele é um obstáculo, por onde o jogador não pode passar.

Haverá sempre ao menos dois espaços vazios no labirinto, e só há um caminho entre quaisquer dois espaços vazios. A entrada e a saída do labirinto não necessariamente precisam estar nas bordas.

O último caso de teste é indicado quando $N$ = $M$ = 0, o qual não deverá ser processado.

## Saída

Para cada caso de teste imprima uma linha, contendo um inteiro, indicando a distância entre a entrada e a saída do labirinto se a localização da entrada e da saída do labirinto for escolhida de forma ótima.