#include <iostream>
#include <vector>

using namespace std;

// cores dos vertices
#define BRANCO -1 // vertice nao descoberto
#define CINZA 0 // vertice descoberto
#define PRETO 1 // vertice fechado

typedef vector<int> vi;
typedef vector<vi> vvi; // vetor de vetor de inteiros

void dfsVisit(vvi &LA, int u, vi &cor) {
    cor[u] = CINZA; // vértice branco u acabou de ser descoberto
    for (int i = 0; i < LA[u].size(); i++) { // explorar aresta (u,v)
        int v = LA[u][i];
        if (cor[v] == BRANCO) {
            dfsVisit(LA, v, cor);
        }
    }
    cor[u] = PRETO; // pintar u de preto; está terminado
}

int dfs(vvi &LA) {
    int E = -1; // inicia com -1 devido a primeira iteração
    int N = LA.size();
    vi cor = vi(N, BRANCO);

    for (int u = 0; u < N; u++) {
        if (cor[u] == BRANCO) {
            dfsVisit(LA, u, cor);
            E++;
        }
    }
    return E;
}

int main() {

    int T;
    cin >> T; // O número T (T ≤ 100) de casos de teste

    for(int t = 0; t < T; t++) {
        int N; // N é o número de pontos principais da cidade
        int M; // M é o número de estradas já construídas

        cin >> N >> M;

        vvi LA = vvi(N, vi()); // lista de adjacência do grafo

        for(int k = 0; k < M; k++) {		
            int X, Y; // indicam que existe uma estrada que liga o ponto X ao ponto Y
            cin >> X >> Y;
            LA[X-1].push_back(Y-1);
            LA[Y-1].push_back(X-1);
        }

        int E = dfs(LA); // E é o número mínimo de estradas que devem ser construídas para que a promessa seja cumprida
        if (E == 0) {
            cout << "Caso #" << t+1 << ": a promessa foi cumprida" << endl;
        } else {
            cout << "Caso #" << t+1 << ": ainda falta(m) " << E << " estrada(s)" << endl;
        }
    }
    
    return 0;
}
