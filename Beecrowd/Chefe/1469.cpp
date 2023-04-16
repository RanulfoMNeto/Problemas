#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void replace(vi &vector, int A, int B) {
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] == A) {
            vector[i] = B;
        } else if (vector[i] == B) {
            vector[i] = A;
        }
    }
}

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
                replace(AL[i], A, B);
            }
        }
        int question(int E) {
            vector<bool> visitados(N, false);
            queue<int> fila;
            visitados[E] = true;
            fila.push(E);
            int youngest = INT_MAX;
            while(!fila.empty()) {
                int u = fila.front();
                fila.pop();
                for (int i = 0; i < AL[u].size(); i++) {
                    int v = AL[u][i];
                    youngest = min(youngest, K[v]);
                    if (visitados[v] == false) {
                        visitados[v] = true;
                        fila.push(v);
                    }
                }
            }
            return youngest;
        }
};

int main() {

    int N, M, I;
    while(cin >> N >> M >> I) {
        Graph graph(N, M);
        for (int i = 0; i < N; i++) {
            int Ki; // Ki indica a idade do empregado de número i
            cin >> Ki;
            graph.addAge(i, Ki);
        }
        for (int i = 0; i < M; i++) {
            int X, Y;
            cin >> X >> Y;
            graph.addEdge(Y-1, X-1); // X gerencia Y diretamente
        }
        for (int i = 0; i < I; i++) {
            char identifier;
            cin >> identifier;
            if (identifier == 'T') {
                int A, B;
                cin >> A >> B;
                graph.switchPlaces(A-1, B-1);
            } else {
                int E;
                cin >> E;
                int result = graph.question(E-1);
                if (result == INT_MAX) {
                    cout << "*" << endl;
                } else {
                    cout << result << endl;
                }
            }
        }
    }
    return 0;
}