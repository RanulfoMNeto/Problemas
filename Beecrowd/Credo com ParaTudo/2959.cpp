#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

void dfsVisit(vi* graph, vb& visited, vb& reached, int u) {
    visited[u] = true; // vértice branco u acabou de ser descoberto
    reached[u] = true;
    for (int i = 0; i < graph[u].size(); i++) { // explorar aresta (u,v)
        int v = graph[u][i];
        if (!visited[v]) {
            dfsVisit(graph, visited, reached, v);
        }
    }
    // está terminado
}

void dfs(vi* graph, vvb& sets, int N) {
    vb visited(N, false);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            vb reached(N, false);
            dfsVisit(graph, visited, reached, i);
            sets.push_back(reached);
        }
    }
}

bool contains(vvb& sets, int K, int L) {
    for (int i = 0; i < sets.size(); i++) {
        if (sets[i][K] and sets[i][L]) {
            return true;
        }
    }
    return false;
}

int main() {
    int N, M, P;
    cin >> N >> M >> P;

    vi* graph = new vi[N];

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A-1].push_back(B-1);
        graph[B-1].push_back(A-1);
    }
    vvb sets;
    dfs(graph, sets, N);
    for (int i = 0; i < P; i++) {
        int K, L;
        cin >> K >> L;
        if (contains(sets, K-1, L-1)) {
            cout << "Lets que lets" << endl;
        } else {
            cout << "Deu ruim" << endl;
        }
    }
    return 0;
}