#include<iostream>
#include<vector>
#include<utility>
#include <algorithm>
using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

/*
 * Variaveis globais
 */

// lista de adjacencia
vii* LA;

// valor da variavel x, originalmente relacionada a melhor estimativa de distancia do vertice em relacao a origem
vi d;
// atributo predecessor
vi p;

// numero de vertices
int n;

// numero de arestas
int m;

int bellman_ford(int org) {
	d.assign(n, INF);
	p.assign(n, -1);
	d[org] = 0;

	for(int i = 0; i < n - 1; i++) {
		for(int u = 0; u < n; u++) {
			for(int j = 0; j < (int)LA[u].size(); j++) {
				if (d[LA[u][j].first] > d[u] + LA[u][j].second) {
					d[LA[u][j].first] = d[u] + LA[u][j].second;
					p[LA[u][j].first] = u;
				}
			}
		}
	}
	return *max_element(d.begin(), d.end());
}

int main() {
	cin >> n >> m;
	LA = new vii[n];

	int u, v, p;

	for(int j = 0; j < m; j++) {
		cin >> u >> v >> p;
		LA[u].push_back(ii(v, p));
		LA[v].push_back(ii(u, p));
	}

	int menor = INF;

	for (int i = 0; i < n; i++) {
		int resultado = bellman_ford(i);
		menor = (resultado < menor)?resultado:menor;
	}

	cout << menor << endl;

	return 0;
}