#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Graph {
    public:
        int N;
        int M;
        vi O;
        vvi AL;
        Graph(int N, int M) {
            this->N = N;
            this->M = M;
            AL = vvi(N, vi());
            O = vi(N);
        }
        void addEdge(int X, int Y) {
            AL[X].push_back(Y);
        }
        void addOwe(int X, int owe) {
            O[X] = owe;
        }
};

int sum = 0;

void bfs(Graph graph, int origem, vector<bool> &visitados) {

	queue<int> fila;
	visitados[origem] = true;
	fila.push(origem);
    sum += graph.O[origem];

	while(!fila.empty()) {

		int u = fila.front();
		fila.pop();

		for (int i = 0; i < graph.AL[u].size(); i++) {

			int v = graph.AL[u][i];
			if (!visitados[v]) {
				visitados[v] = true;
				fila.push(v);
                sum += graph.O[v];
			}
		}
	}
	
}

bool solve(Graph graph) {

    int n = graph.AL.size();
    vector<bool> visitados(n, false);

    for (int u = 0; u < n; u++) {
        if (!visitados[u]) {
            sum = 0;
            bfs(graph, u, visitados);
            if (sum < 0)
                return false;
        }
    }
    return true;
}

int main() {

    int N, M;
    cin >> N >> M;
    Graph graph(N, M);
    for (int n = 0; n < N; n++) {
        int owe;
        cin >> owe;
        graph.addOwe(n, owe);
    }
    for (int m = 0; m < M; m++) {
        int X, Y;
        cin >> X >> Y;
        graph.addEdge(X, Y);
        graph.addEdge(Y, X);
    }
    if (solve(graph))
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}