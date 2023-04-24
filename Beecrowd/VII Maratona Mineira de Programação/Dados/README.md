# Dados

Após longas partidas de Dungeons & Dragons, Alice e seus amigos resolveram fazer outra coisa. Como Alice é muito organizada, na hora de guardar os dados ela gostaria de deixar todos os dados com o mesmo valor de face voltado para cima. Mas como ela também é preguiçosa, gostaria de fazer isto com a menor quantidade de movimentos possíveis.

A cada movimento, ela pode rotacionar o dado para mostrar uma das faces adjacentes da face atual. Veja que nesta versão do jogo, Alice e seus amigos estão usando dados regulares, de seis faces, numerados de 1 a 6, onde a soma de duas faces opostas resulta sempre em 7.

Ajude Alice a determinar a menor quantidade de movimentos necessários para que todos os dados fiquem com a mesma face voltada para cima.

## Entrada

A entrada é composta por duas linhas. Na primeira delas temos um inteiro $N$, indicando a quantidade de dados presentes. A segunda linha contêm $N$ inteiros separados por espaço. O $i$-ésimo deles, $d_i$, representa o valor da face que está virado para cima.

$1 \leq N \leq 10^5$

$1 \leq d_i \leq 6, para todo 1 \leq i \leq N$

## Saída

Exiba em uma linha um inteiro, a menor quantidade de movimentos necessários para deixar todos os dados com a mesma face para cima.
