# Problema dos Pares Mais Próximos

Dado um conjunto de pontos em um espaço bidimensional, você deverá encontrar a distância entre os pontos mais próximos.

## Entrada

O arquivo de entrada contém vários casos de teste. Cada caso de teste começa com um número inteiro $N (0 \leq N \leq 10000)$, que denota o número de pontos neste conjunto. As $N$ linhas seguintes contêm, cada uma delas, dois valores que são as coordenadas dos N pontos bidimensionais. O primeiro destes dois valores indica a coordenada $X$ e o último indica a coordenada $Y$. A entrada é terminada por um conjunto cujo $N = 0$. Esta entrada não deve ser processada. O valor das coordenadas será um número não-negativo menor do que 40000.

## Saída

Para cada conjunto de entrada imprima uma única linha de saída contendo um valor de ponto flutuante (com 4 dígitos após o ponto decimal) o qual denotará a distância entre os dois pontos mais próximos. Se não existirem tais dois pontos na entrada cuja distância for menor do que 10000, imprima a mensagem `"INFINITY"` sem as aspas.