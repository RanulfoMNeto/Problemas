# Rodovia

As estradas da Nlogônia estão severamente danificadas, devido ao intenso fluxo de veículos pesados criado pelo desenvolvimento econômico do reino. Para resolver o problema, o rei da Nlogônia decretou que seriam construídas novas rodovias. O decreto determinou que:

- todas as rodovias construídas terão mão única, e ligarão exatamente duas cidades;
nenhum par de rodovias se intersectará — serão construídos viadutos, túneis e pontes conforme necessário;
- por razões orçamentárias, o número de rodovias a construir será igual ao número de cidades que existem na Nlogônia;
- deve ser possível, partindo de qualquer cidade, chegar a qualquer outra cidade usando só as novas rodovias, sempre respeitando a mão das rodovias.

O engenheiro-chefe do reino desenhou uma proposta de mapa viário; o rei verificou que o plano satisfaz as três primeiras restrições, mas não conseguiu verificar a última. Por isso, ele pediu que você escrevesse um programa que determina se o plano de rodovias permite viajar de qualquer cidade até qualquer outra cidade da Nlogônia.

## Entrada

A primeira linha de cada caso de teste contém um inteiro $N (2 \leq N \leq 104)$, indicando o número de cidades. Cada uma das $N$ linhas seguintes descrevem uma estrada: a linha contém dois inteiros $A$ e $B$ $(A \neq B)$ que indicam que existe uma estrada de mão única ligando a cidade $A$ a outra cidade, $B$ (as cidades são numeradas de $1$ a $N$).

## Saída

Imprima uma única linha contendo um único caractere: ‘S’ se for possível ir de qualquer cidade a qualquer outra cidade por rodovias e ‘N’ caso contrário.