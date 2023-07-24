#include <iostream>
#include <cmath> // hypot
#include <iomanip> // setprecision
#include <climits> // INT_MAX
#include <algorithm> // min
#include <cstring> // memset

#define MAXN 17 // |N| + |{0}| + 1
#define MAXB 1 << MAXN
#define NAOVISITADO -1
#define VISITADO 1
#define INFINITO INT_MAX

int N; // N (1 ≤ N ≤ 15): representando a quantidade de focos de mosquito no mapa (casos de teste)
int X[MAXN], Y[MAXN]; // X e Y (−100 ≤ X, Y ≤ 100), representando a coordenada de um foco de dengue.
double M[MAXN][MAXN]; // Representando a distância das coordenadas (matriz de adjacência)
double memoriza[MAXN][MAXB]; // Uma matriz que memoriza os resultados dos subproblemas do TSP para reutilização em programação dinâmica
int visitado[MAXN][MAXB]; // Uma matriz para marcar se um estado (atual e bitmask) já foi visitado na recursão do TSP

/* Tommasini, S. Programação Dinâmica: Trabalho de Conclusão de Curso. Universidade de São Paulo, Supervisor: Ferreira, C. E.
TSP(c, b)
    se b == 2^(n) − 1 então
        devolva M[c][0]
    se memoriza[c][b] já tiver sido calculado então
        devolva memoriza[c][b]
    resposta = infinito
    para i = 1 até n faça
        se i não visitado então
            resposta = min(resposta, M[c][i] + TSP(i,b U {i}))
    memoriza[n] = resposta
    devolva memoriza[n]
*/

// b: O i-ésimo elemento está em b se o i-ésimo bit de b for 1
double TSP(int c, int b) { // Recebe um subconjunto de cidades já visitadas b e a cidade atual c
    if (b == (1 << (N + 1)) - 1) { // Quando já visitamos todas as cidades, nesse caso basta voltar para a cidade 0
        return M[c][0];
    }
    if (visitado[c][b] == VISITADO) {
        return memoriza[c][b];
    }
    visitado[c][b] = VISITADO;
    double resposta = INFINITO;
    for (int i = 0; i <= N; i++) {
        // O operador binário & (Bitwise AND) compara dois valores utilizando suas representações binárias, retornando um novo valor
        // Para formar esse valor de retorno, cada bit é comparado, retornando 1 (true) quando ambos os bits forem iguais a 1 (true); caso contrário, retorna 0 (false)
        if (i != c && !(b & (1 << i))) {
            resposta = std::min(resposta, M[c][i] + TSP(i, b | (1 << i)));
        }
    }
    return memoriza[c][b] = resposta;
}

int main() {
    while(std::cin >> N && N) {
        for (int i = 0; i <= N; i++) {
            std::cin >> X[i] >> Y[i];
        }
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                // Calcula a distância euclidiana entre os pontos (X[i], Y[i]) e (X[j], Y[j])
                M[i][j] = hypot(X[i] - X[j], Y[i] - Y[j]);
            }
        }
        // Inicializa o array 'visitado' com -1 para indicar que nenhum estado foi visitado ainda.
        memset(visitado, -1, sizeof(visitado));
        // Realiza a chamada à função tsp(0, 1) e imprime o resultado formatado com duas casas decimais
        std::cout << std::fixed << std::setprecision(2) << TSP(0, 1) << std::endl;
    }
    return 0;
}
