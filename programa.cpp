#include<iostream>
#include<vector>
#include<utility>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int, int> mii;

void solve(vector< vector<int> > &MAG, int Q, int s, int t) {
	
}

int main() {

	int n, m;
	// n: quantidade de vértices
	// m: quantidade de arestas
	cin >> n >> m;

	mii c;
	// c: o custo de se abastecer uma unidade do combustível na cidade v (o v-ésimo inteiro corresponde a c[v])

	for (int v = 0; v < n; v++) {
		int custo;
		cin >> custo;
		c.insert(pair<int, int>(v, custo));
	}

	vector< vector<int> > MAG(n, vector<int>(m, 0));
	// MAG: matriz de adjacência da rede de fluxo G

	for (int k = 0; k < m; k++) {
		int i,j,d;
		// estrada saindo de i e alcançando j com distância d
		cin >> i >> j >> d;
		MAG[i][j] = d;
	}

	int x;
	// x: quantidade de testes que serão realizados no grafo de entrada
	cin >> x;
	for (int i = 0; i < x; i++) {
		int Q, s, t;
		// Q: capacidade do tanque de combustível do veículo
		// s: ponto de partida (fonte)
		// t: ponto de destino (sorvedouro)
		cin >> Q >> s >> t;
		solve(MAG, Q, s, t);
	}
	
	return 0;
}