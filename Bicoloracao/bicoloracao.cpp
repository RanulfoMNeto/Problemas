#include <iostream>
#include <vector>

using namespace std;

// cores dos vertices
#define BRANCO 0 // vertice nao descoberto
#define CINZA 1 // vertice descoberto
#define PRETO 2 // vertice fechado

class Mapa {
	public:
		int n; // Número de regiões
		int m; // Número de Fronteiras
		vector<int>* fronteiras;
		vector<int> cor;

		Mapa(int n, int m) {
			this->n = n;
			this->m = m;
			cor = vector<int>(n, BRANCO);
			fronteiras = new vector<int>[n];
		}

		void adicionarFronteira(int v1, int v2) {
			fronteiras[v1].push_back(v2); // v1 -> v2

			// Grafo não direcionado
			fronteiras[v2].push_back(v1); // v2 -> v1
		}

		// RESOLVER
		int verificarBiocoloracao() {

			int eh_bicolorido = 1;

			for(int i = 0; i < n && eh_bicolorido; i++) {

				// Vértice ainda não visitado
				if (cor[i] == BRANCO)
					eh_bicolorido = DFSVisit(i, CINZA); // estabeleço que a raíz da componente é colorida com a cor CINZA(1)
			}
			return eh_bicolorido;
		}

		int DFSVisit(int i, int c) { // (Vértice, Cor)
			
			cor[i] = c;
			
			for(int j = 0; j < (int)fronteiras[i].size(); j++) {
				int v = fronteiras[i][j];
				if (cor[v] == BRANCO) {
					c = (cor[i] == CINZA)?PRETO:CINZA; // Intercalação de cores
					DFSVisit(v, c);
				} else if (cor[v] == cor[i]) {
					return 0;
				}
			}
			return 1;

		}
		/*
		void imprimir() {
			for (int i = 0; i < n; i++) {
				cout << i << "(" << cor[i] << "):";
				for (int j = 0; j < fronteiras[i].size(); j++) {
					cout << "->" << fronteiras[i][j] << "(" << cor[fronteiras[i][j]] << ")";
				}
				cout << endl;
			}
		}
		*/
};

int main() {

	// Quantidade de vértices e arestas
	int n, m;

	cin >> n;

	while(n) {
		cin >> m;
		Mapa mapa(n, m);

		// Inicializando o grafo não-orientado
		for (int i = 0; i < m; i++) {
			int v, a;
			cin >> v >> a;
			mapa.adicionarFronteira(v, a);
		}
		cout << mapa.verificarBiocoloracao() << endl;
		//mapa.imprimir();

		cin >> n;
	};

	return 0;
}

