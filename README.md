## Projetando-Estradas-OO
Disciplina: GCC218 - Algoritmos em Grafos 

Projeto semelhante ao do repositório "Projetando-Estradas", no entanto, esse foi desenvolvido através da orientação à objetos(OO).

# Descrição
O prefeito de Delta City contratou uma consultoria para um projeto de construção de uma nova rede de estradas. A cidade é modelada por n intersecções e m estradas bidirecionais que conectam os pares de intersecções. Cada estrada possui uma certa estimativa de capacidade de tráfego, mensurada em veículos por minuto. Uma análise preliminar da empresa de consultoria indicou que sempre existe um caminho entre uma dada intersecção x e outra intersecção y, ao longo de uma sequência de estradas. O Departamento de Infraestrutura de Delta City está com sérios problemas orçamentários, e necessita de reduzir os custos de manutenção de malha viária fechando algumas estradas, mantendo as intersecções conectadas. A prefeitura de Delta City pretende realizar tal estudo, de forma que a menor capacidade de tráfego das estradas remanescentes seja a maior possível.

# Entrada
A primeira linha contém o número de casos de teste, denotada por C. Cada um dos C casos de teste é denotado a seguir. A primeira linha indica o número de intersecções (0 < n <= 100) e o número de estradas (0 < m <= 10.000) . As próximas m linhas representam as estradas, cada uma composta por uma série de três valores: intersecções u e v, em que 0 <= u,v < n, e sua capacidade de tráfego c (0 < c <= 1.000).

# Saída
Para cada caso de teste, indique a capacidade mínima referente às estradas remanescentes.

# Exemplo de Entrada
2 
2 3 
0 1 10 
0 1 20 
0 0 30 
4 5 
0 1 1 
3 1 2 
1 2 3 
2 3 4 
0 2 5

# Exemplo de Saída
20
3
