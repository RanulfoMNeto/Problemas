# Dinheiro Importa

Nossa triste história começa com um grupo restrito de amigos. Juntos, eles fizeram uma viagem para o país pitoresco da Molvânia. Durante sua estadia, vários eventos que são horríveis demais de mencionar ocorreram. O resultado líquido foi que a última noite da viagem terminou com uma troca importante de "Eu nunca mais quero ver você de novo!"s. Um cálculo rápido diz a você que pode ter sido dito esta frase quase 50 milhões de vezes!

De volta em casa na Escandinávia, nosso grupo de ex-amigos perceberam que não dividiram os custos durante a viagem uniformemente. Algumas  pessoas podem ter vários milhares de coroas. Liquidar as dívidas acaba sendo um pouco mais problemático do que deveria ser, já que muitos do grupo não desejam mais se falar, e menos ainda, dar dinheiro uns aos outros.

Naturalmente, você quer ajudar, então pede a cada pessoa que diga quanto dinheiro ela deve ou é devida e de quem ainda é amiga. Com essas informações, você tem certeza que pode descobrir se é possível que todos fiquem quites, e com o dinheiro sendo dado apenas entre pessoas que ainda são amigas.

Entrada

A primeira linha contém dois inteiros $N$ ($2 \leq N \leq 10000$), e $M$ ($0 \leq M \leq 50000$), o número de amigos e o número de amizades restantes. Então seguem $N$ linhas, cada uma contendo um número inteiro $O$ ($−10000 \leq O \leq 10000$) indicando quanto cada pessoa deve (ou é devida caso $O < 0$). A soma desses valores é zero. Depois disso vem $M$ linhas dando as amizades restantes, cada linha contendo dois inteiros $X, Y$ ($0 \leq X < Y \leq N − 1$) indicando que as pessoas $X$ e $Y$ ainda são amigas.

Saída

A saída deve consistir em uma única linha dizendo "`POSSIBLE`" (se for possível) ou "`IMPOSSIBLE`" (se for impossível).

### Exemplos de Entrada
```
5 3
100
-75
-25
-42
42
0 1
1 2
3 4
```
### Exemplos de Saída
```
POSSIBLE
```

### Exemplos de Entrada
```
4 2
15
20
-10
-25
0 2
1 3
```
### Exemplos de Saída
```
IMPOSSIBLE
```