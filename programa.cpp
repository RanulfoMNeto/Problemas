#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef pair<int, int> ii; // pares de inteiros
typedef vector<int> vi; // vetor de inteiros
typedef int tipo; // tipo do valor

class UFDS
{
    public:
      // construtor com parametro: n eh o numero de conjuntos disjuntos
      UFDS(int n)
      {
          rank.assign(n, 0);
          p.assign(n, 0);
          for(int i = 0; i < n; i++)
            p[i] = i;
      }
      int busca(tipo i)
      {
          if(p[i] == i)
              return i;
      
          p[i] = busca(p[i]);
          return p[i];
      }
      bool mesmoConjunto(tipo i, tipo j)
      {
          return busca(i) == busca(j);
      }
 
      void uniao(tipo i, tipo j)
      {
          if(!mesmoConjunto(i, j))
          {
              int c1 = busca(i);
              int c2 = busca(j);
          
              if(rank[c1] > rank[c2])
                  p[c2] = c1;
          
              else
              {
                  p[c1] = c2;
                  if(rank[c1] == rank[c2])
                      rank[c2]++;
              }
          }
      }
 
      friend ostream &operator<<(ostream& saida, const UFDS& conjunto)
      {
          for(int i = 0; i < (int)conjunto.p.size(); i++)
            saida << i << ": p(" << conjunto.p[i] << "), rank(" << conjunto.rank[i] << ")";
          return saida;
      }
 
    private:
      // vetor que armazena os pais de cada vertice no conjunto disjunto
      vi p;
 
      // vetor que armazena o rank de cada elemento do conjunto
      vi rank;
};

class Interseccao {
    public:
        tipo valor;
		Interseccao();
        Interseccao(tipo valor) {
            this->valor = valor;
        }
		Interseccao(const Interseccao &interseccao) {
            this->valor = interseccao.valor;
        }
		bool operator==(Interseccao interseccao) {  
			return this->valor == interseccao.valor;
		}
};

class Estrada {
    public:
        Interseccao *origem;
	Interseccao *destino;
        int custo;
	Estrada();
        Estrada(Interseccao &origem, Interseccao &destino, int custo) {
            this->origem = &origem;
            this->destino = &destino;
            this->custo = custo;
        }
};

bool operator<(const Estrada &e1, const Estrada &e2) {
    return e1.custo < e2.custo;
}


// (Grafo Conexo) Uma análise preliminar da empresa de consultoria indicou que sempre existe um caminho entre uma dada intersecção x e outra intersecção y, ao longo de uma sequência de estradas.

class Cidade {
	public:
		// a cidade é modelada por n intersecções e m estradas bidirecionais que conectam os pares de intersecções.
		int n;
		int m;
        	vector<Interseccao> interseccoes;
		vector<Estrada> estradas; // cada estrada possui uma certa estimativa de capacidade de tráfego, mensurada em veículos por minuto.

		Cidade(int n, int m) {
			this->n = n;
			this->m = m;
			// Inserção de valores padrões (int);
			for (int i = 0; i <= n; i++) {
				adicionarIntersecao(i);
			}
		}

		void adicionarIntersecao(tipo valor) {
			Interseccao interseccao(valor);
			interseccoes.push_back(interseccao);
		}

		bool adicionarEstrada(tipo uValor, tipo vValor, int custo) {
			Interseccao *u;
			Interseccao *v;
			bool uE = false;
			bool vE = false;
			for (int i = 0; i < (int)interseccoes.size(); i++) {
				if (interseccoes[i].valor == uValor) {
					u = &interseccoes[i];
					uE = true;
				}
				if (interseccoes[i].valor == vValor) {
					v = &interseccoes[i];
					vE = true;
				}
				if (uE && vE) {
					Estrada estrada(*u, *v, custo);
					estradas.push_back(estrada);
					return true;
				}
			}
			return false;
            
		}

		void imprimir() {
			for (int i = 0; i < (int)estradas.size(); i++) {
				cout << "[" << estradas[i].origem->valor << "," << estradas[i].destino->valor << "]->c(" << estradas[i].custo << ")" << endl;
			}
		}

};

/* retorna o custo da AGM
* Parametros:
*  arestas: lista da arestas
*  n: quantidade de vertices
*  m: quantidade de arestas
*/

int kruskal(Cidade &cidade) { // Algoritmo de kruskall adaptado ao problema

	UFDS ufds(cidade.n); // codigo equivalente ao MAKE-SET(v) do pseudocodigo

	// ordenacao em O(mlogm), de acordo com https://www.cplusplus.com/reference/algorithm/sort/?kw=sort
	sort(cidade.estradas.rbegin(), cidade.estradas.rend()); // ordene as arestas de G.E em ordem não decrescente de peso w(custo)
	// sobrecarga do operador '<' para realizar a ordenação em ordem decrescente de custo

	// custo da AGM
	int custo = 0;
	int numero_arestas = 0;

	int menor = cidade.estradas[0].custo;

	Interseccao *u;
	Interseccao *v;
	
	// for cada aresta (u, v) em G.E, tomada em ordem decrescente de peso
	for (int i = 0; i < (int)cidade.estradas.size(); i++) {
		u = cidade.estradas[i].origem;
		v = cidade.estradas[i].destino;
		custo = cidade.estradas[i].custo;
		// if (FIND-SET(u) != FIND-SET(v))
		if (!ufds.mesmoConjunto(u->valor, v->valor)) {
			if (custo < menor)
				menor = custo;
			numero_arestas++;
			if(numero_arestas == cidade.n-1)
				break;
			// UNION(u, v)
			ufds.uniao(u->valor, v->valor);
		}
	}

	return menor;
}

int main() {

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int n, m;

		cin >> n >> m;

		Cidade cidade(n, m);

		// Inserção de valores manualmente
		/*
		for (int j = 0; j < n; j++) {
			tipo x;
			cin >> x;
			cidade.adicionarIntersecao(x);
		}
		*/

		for (int i = 0; i < m; i++) {
			tipo u, v;
			int c;
			cin >> u >> v >> c;
			i = (cidade.adicionarEstrada(u, v, c))?i:i-1; // caso não exista nenhuma intersecção com um dos valores
		}

		cout << kruskal(cidade) << endl;
	}
	return 0;
}
