#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm> 

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Graph {
    public:
        int N;
        int M;
        vi K;
        vvi AL;
        Graph(int N, int M) {
            this->N = N;
            this->M = M;
            AL = vvi(N, vi());
            K = vi(N);
        }
        void addEdge(int X, int Y) {
            AL[X].push_back(Y);
        }
        void addAge(int i, int Ki) {
            K[i] = Ki;
        }
        void switchPlaces(int A, int B) {
            swap(AL[A], AL[B]);
            for (int i = 0; i < N; i++) {
                replace(AL[i].begin(), AL[i].end(), A, B);
                replace(AL[i].begin(), AL[i].end(), B, A);
            }
        }
        int question(int E);
};

bool bfs(Graph graph, int origem, int E) {

	queue<int> fila;
    vector<bool> visitados(graph.N, false);
	visitados[origem] = true;
	fila.push(origem);

	while(!fila.empty()) {

		int u = fila.front();
		fila.pop();

		for (int i = 0; i < graph.AL[u].size(); i++) {

			int v = graph.AL[u][i];
            if (v == E) {
                return true;
            }
			if (visitados[v] == false) {
				visitados[v] = true;
				fila.push(v);
			}
		}
	}
    return false;
}

int Graph::question(int E) {
    int youngest = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (bfs(*this, i, E)) {
            youngest = min(youngest, K[i]);
        }
    }
    return youngest;
}

int main() {

    int N, M, I;
    cin >> N >> M >> I;
    Graph graph(N, M);
    for (int i = 0; i < N; i++) {
        int Ki; // Ki indica a idade do empregado de número i
        cin >> Ki;
        graph.addAge(i, Ki);
    }
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        graph.addEdge(X-1, Y-1); // X gerencia Y diretamente
    }
    for (int i = 0; i < I; i++) {
        char identifier;
        cin >> identifier;
        if (identifier == 'T') {
            int A, B;
            cin >> A >> B;
            graph.switchPlaces(A-1, B-1);
        } else if (identifier == 'P') {
            int E;
            cin >> E;
            int result = graph.question(E-1);
            if (result != INT_MAX) {
                cout << result << endl;
            } else {
                cout << "*" << endl;
            }
        }
    }
    return 0;
}