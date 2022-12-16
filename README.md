# Bicoloração

#Descrição
O Teorema das 4 Cores estabelece que qualquer mapa pode ser colorido utilizando apenas quatro cores, de tal forma que uma região não possa ter a mesma cor que a sua região vizinha. Sua tarefa consiste em: dado um mapa em que as regiões podem ser modeladas por vértices, e as arestas indicam as fronteiras entre as regiões, você deve determinar se é possível colorir o mapa com apenas duas cores. Os grafos de entrada serão simples, conexos e não-direcionados.

#Entrada
A entrada consiste em vários casos de teste. Cada caso de teste inicia com o valor n, indicando a quantidade de vértices do grafo em questão (1 < n < 200). A segunda linha contém a quantidade de arestas m. As próximas m linhas do caso de teste indicam as ligações entre os vértices que constituem cada aresta. Um vértice é identificado por um inteiro v, com 0 ≤ v < n. Uma linha com um único inteiro igual a zero indica o fim da entrada a ser testada.

#Saída
O seu algoritmo deve imprimir 1 se o grafo pode ser colorido com duas cores, e 0, caso contrário.

#Exemplo
##Entrada
3 
3 
0 1 
1 2 
2 0 
3 
2 
0 1 
1 2 
9 
8 
0 1 
0 2 
0 3 
0 4 
0 5 
0 6 
0 7 
0 8 
0

##Saída
0 
1 
1
