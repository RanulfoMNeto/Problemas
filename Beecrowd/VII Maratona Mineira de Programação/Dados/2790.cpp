#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int INF = INT_MAX;

class Dado {
    public:
        // representa o valor da face que está virado para cima.
        int face; 
        // A cada movimento, ela pode rotacionar o dado para mostrar uma das faces adjacentes da face atual.
        vvi movimentos; 
        vi d;
        Dado() {}
        Dado(int face) {
            this->face = face;
            movimentos = vvi(6, vi(6, INF)); // lista de adjacência do grafo
            for(int i = 0; i < 6; i++) {
                for(int j = 0; j < 6; j++) {
                    if ((j != i) and (j+1 != 7 - (i+1))) {
                        movimentos[i][j] = 1;
                    } else if (j == i) {
                        movimentos[i][j] = 0;
                    } else if (j+1 == 7 - (i+1)) {
                        movimentos[i][j] = 2;
                    }
                }
            }
        }
};

// estimativa de limite superior para o peso de um caminho mínimo da fonte s a cada vértice
vi d;
// predecessores dos vértices
vi p;

void INITIALIZE_SINGLE_SOURCE(vvi &AM, int s) {
	int n = AM.size();
	d.assign(n, INF);
	p.assign(n, -1); // NIL = -1
	d[s] = 0;
}

void RELAX(int u, int v, vvi &AM) {
	if (d[v] > d[u] + AM[u][v]) {
		d[v] = d[u] + AM[u][v];
		p[v] = u;
	}
}

int EXTRACT_MIN(vi &Q) {
	int menor = INF, u, j;
	for (int i = 0 ; i < Q.size(); i++) {
		int v = Q[i];
		if (d[v] < menor) {
			menor = d[v];
			u = v;
			j = i;
		}
	}
	Q.erase(Q.begin()+j);
	return u;
}

vi dijkstra(vvi &AM, int s) {

	INITIALIZE_SINGLE_SOURCE(AM, s);
	vi S; // conjunto S de vértices cujos pesos finais de caminhos mínimos que partem da fonte s já foram determinados
	vi Q; // fila de prioridades mínimas
	for (int i = 0; i < AM.size(); i++) {
		Q.push_back(i);
	}
	while(!Q.empty()) {
		int u = EXTRACT_MIN(Q);
		S.push_back(u);
		for (int v = 0; v < AM[u].size(); v++) {
			if (AM[u][v] != INF) {
				RELAX(u, v, AM);
			}
		}
	}
	return d;
}

int main() {
    int N;
    cin >> N;
    vector<Dado> dados(N);
    for(int i = 0; i < N; i++) {
        int face;
        cin >> face;
        dados[i] = Dado(face-1);
        dados[i].d = dijkstra(dados[i].movimentos, face-1);
    }
    int menor = INF;
    for(int i = 0; i < 6; i++) {
        int soma = 0;
        for(int j = 0; j < N; j++) {
            soma += dados[j].d[i];
        }
        menor = min(menor, soma);
    }
    cout << menor << endl;
}