#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


// cores dos vertices
#define BRANCO -1 // vertice nao descoberto
#define CINZA 0 // vertice descoberto
#define PRETO 1 // vertice fechado

class Graph {
    public:
        int V;
        int A;
        vvi AL;
        Graph(int V, int A) {
            this->V = V;
            this->A = A;
            AL = vvi(V, vi());
        }
        void addEdge(int u, int v) {
            AL[u].push_back(v);
        }
};

int result;

void dfsVisit(Graph graph, int u, vi &cor) {
    cor[u] = CINZA; // vértice branco u acabou de ser descoberto
    for (int i = 0; i < graph.AL[u].size(); i++) { // explorar aresta (u,v)
        int v = graph.AL[u][i];
        if (cor[v] == BRANCO) {
            result++;
            dfsVisit(graph, v, cor);
            result++;
        }
    }
    cor[u] = PRETO; // pintar u de preto; está terminado
}

int solve(Graph graph, int N) {
    result = 0;
    vi cor = vi(graph.V, BRANCO);
    dfsVisit(graph, N, cor);
    return result;
}
 
int main() {

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, V, A;
        cin >> N >> V >> A;
        Graph graph(V, A);
        for (int a = 0; a < A; a++) {
            int u, v;
            cin >> u >> v;
            graph.addEdge(u, v);
            graph.addEdge(v, u);
        }
        cout << solve(graph, N) << endl;
    }
    return 0;
}