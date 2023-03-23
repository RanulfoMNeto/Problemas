# Abastecendo o Tanque
O aumento considerável no preço dos combustíveis faz com que o planejamento de qualquer viagem seja feito com muita cautela. Considere um grafo ponderado G=(V,E) que representa as estradas de uma região de interesse, em que 1 ≤ |V| ≤ 1.000 e 0 ≤ |E| ≤ 10.000. O preço para abastecer uma unidade de combustível na cidade v é dado por c[v], e a capacidade do tanque de combustível de um veículo é dada por Q, com 1 ≤ Q ≤ 100.

**Tarefas**: determine a viagem mais barata que se pode realizar entre uma cidade de origem s e uma cidade destino t, utilizando um carro com capacidade de combustível Q.

**Observação**: (i) o carro em questão usa uma unidade de combustível por unidade de distância percorrida; (ii) o carro inicia com tanque vazio.

**Dica**: dicionários (em Python) ou estruturas map (C++) podem ser úteis nesse exercício.

## Entradas
A primeira linha corresponde a quantidade de vértices (|V|) e arestas (|E|) do grafo. A próxima linha contém |V| inteiros, representando o custo de se abastecer uma unidade do combustível na cidade v (o v-ésimo inteiro corresponde a c[v]). As próximas |E| linhas são compostas por inteiros i, j, d, indicando que existe uma estrada saindo de i e alcançando j com distância d. A linha subsequente corresponde a 1 ≤ x ≤ 10 testes que serão realizados no grafo de entrada, em que cada uma das x linhas dispostas a seguir são compostas pela capacidade do tanque de combustível do veículo, denotada por Q, o ponto de partida s e o ponto de destino t.

## Saídas
Para cada um dos x testes realizados, a resposta deve imprimir o menor custo de se sair de s e chegar a t, dada a capacidade Q do tanque de combustível do veículo. Caso não seja possível alcançar o vértice destino t a partir de s, o programa deve imprimir a resposta "sem solucao" (frase com letras minúsculas, e sem acento gráfico).