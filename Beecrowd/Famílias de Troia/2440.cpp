#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

void bfs(vvi &LA, int N, int s, vb &visitados) {
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

int main() {
	int N; // indica o número de elementos da comunidade, numerados de 1 a N
	int M; // linhas do arquivo de entrada

	cin >> N >> M;

	vvi LA = vvi(N, vi()); // lista de adjacência do grafo

	for(int i = 0; i < M; i++) {		
		int u, v, w;
		cin >> u >> v; // indica que os dois indivíduos pertencem a uma mesma família
		LA[u-1].push_back(v-1);
        LA[v-1].push_back(u-1);
	}

    int familias = 0;
    vb visitados(N, false);
    for(int u = 0; u < N; u++) {
        if (!visitados[u]) {
            bfs(LA, N, u, visitados);
            familias++;
        }
    }
    // A saída deve conter apenas uma linha contendo um único inteiro, que é o número de famílias
    cout << familias << endl;
	
	return 0;
}
