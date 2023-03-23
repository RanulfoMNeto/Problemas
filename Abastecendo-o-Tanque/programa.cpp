#include<iostream>
#include<vector>
#include<utility>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int, int> mii;
typedef vector<vii> vvii; // vetor de vetor de pares

int INF = numeric_limits<int>::max(); // infinito

void bellman_ford(vvii &LAG, map<int, int> c, int Q, int s, int t) {
	vi d; // vetor de distâncias
	vi p; // vetor de pais
	int n = LAG.size();
	d.assign(n, INF);
	p.assign(n, -1);
	d[s] = 0;

	for(int i = 0; i < n - 1; i++) {
		for(int u = 0; u < n; u++) {
			for(int j = 0; j < (int)LAG[u].size(); j++) {
				if (d[LAG[u][j].first] > d[u] + LAG[u][j].second) { // RELAX
					d[LAG[u][j].first] = d[u] + LAG[u][j].second;
					p[LAG[u][j].first] = u;
				}
			}
		}
	}
	
	for(int u = 0; u < n; u++) {
		cout << u << ":";
		for(int j = 0; j < (int)LAG[u].size(); j++) {
			cout << LAG[u][j].first << "[" << LAG[u][j].first << "];";
		}
		cout << endl;
	}

}

int main() {

	
	int n; // quantidade de vértices
	int m; // quantidade de arestas

	cin >> n >> m;

	mii c; // custo de se abastecer uma unidade do combustível na cidade v (o v-ésimo inteiro corresponde a c[v])

	for (int v = 0; v < n; v++) {
		int custo;
		cin >> custo;
		c.insert(pair<int, int>(v, custo));
	}

	vvii LAG = vvii(n, vii()); // Lista de adjacência da rede de fluxo G

	for(int k = 0; k < m; k++) {		
		int i,j,d; // estrada saindo de i e alcançando j com distância d
		cin >> i >> j >> d;
		LAG[i].push_back(ii(j, d));
	}

	int x; // quantidade de testes que serão realizados no grafo de entrada
	cin >> x;
	for (int i = 0; i < x; i++) {
		int Q; // capacidade do tanque de combustível do veículo
		int s; // ponto de partida (fonte)
		int t; // ponto de destino (sorvedouro)
		cin >> Q >> s >> t;
		bellman_ford(LAG, c, Q, s, t);
	}
	
	return 0;
}