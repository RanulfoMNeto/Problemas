#include <iostream>
#include <cmath> // hypot
#include <iomanip> // setprecision

#define MAXN 17

int N; // N (1 ≤ N ≤ 15): representando a quantidade de focos de mosquito no mapa (casos de teste)

int X[MAXN], Y[MAXN]; // X e Y (−100 ≤ X, Y ≤ 100), representando a coordenada de um foco de dengue.

double adj[MAXN][MAXN]; // representando a distância das coordenadas (matriz de adjacência)

/* Tommasini, S. Programação Dinâmica: Trabalho de Conclusão de Curso. Universidade de São Paulo, Supervisor: Ferreira, C. E.

tsp(c, b)
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

double tsp(int c, int b) {

}

int main() {
    
    while(std::cin >> N && N) {
        for (int i = 0; i <= N; i++) {
            std::cin >> X[i] >> Y[i];
        }
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                // Calcula a distância euclidiana entre os pontos (X[i], Y[i]) e (X[j], Y[j])
                adj[i][j] = hypot(X[i] - X[j], Y[i] - Y[j]);
            }
        }
        // Realiza a chamada à função tsp(0, 1) e imprime o resultado formatado com duas casas decimais
        std::cout << std::fixed << std::setprecision(2) << tsp(0, 1) << std::endl;
    }

    return 0;
}
