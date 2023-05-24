#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

void bfs(vvi &LA, int s, vb& visitados) {

	int N = LA.size();
	queue<int> fila;

	visitados[s] = true;
	fila.push(s);

	while(!fila.empty()) {

		int u = fila.front();
		fila.pop();

		for (int i = 0; i < LA[u].size(); i++) {

			int v = LA[u][i];
			if (visitados[v] == false) {
				visitados[v] = true;
				fila.push(v);
			}
		}
	}
}

bool alcancavel(vvi &LA, vvi &LAT, int s) {
    int N = LA.size();
    vb visitados(N, false);
    bfs(LA, s, visitados);
	vb visitadosT(N, false);
	bfs(LAT, s, visitadosT);
    for (int i = 0; i < N; i++) {
        if (!visitados[i] || !visitadosT[i]) {
            return false;
        }
    }
    return true;
}

int main() {
	int N; // quantidade de vértices

	cin >> N;

	int M = N; // quantidade de arestas 

	vvi LA = vvi(N, vi()); // lista de adjacência do grafo
    vvi LAT = vvi(N, vi()); // lista de adjacência do grafo transposto

	for(int i = 0; i < M; i++) {		
		int A, B;
		cin >> A >> B;
		LA[A-1].push_back(B-1);
        LAT[B-1].push_back(A-1);
	}
    if (alcancavel(LA, LAT, 0)) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
	
	return 0;
}