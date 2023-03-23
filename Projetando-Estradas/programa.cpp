#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef pair<int, int> ii; // pares de inteiros
typedef vector<int> vi; // vetor de inteiros


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
 
      /* Dado um elemento do conjunto, busca-se seu pai no conjunto disjunto e o 
       * atualiza (se necessário) para o ancestral de maior nivel na arvore.
       *
       * Parametros
       * i: identificacao do elemento cujo o conjunto sera buscado.
       */
      int busca(int i)
      {
          if(p[i] == i)
              return i;
      
          p[i] = busca(p[i]);
          return p[i];
      }
 
      /* Dado dois elementos do conjunto, verifica-se se esses elementos possuem o
      * o mesmo pai na floresta disjunta.
      *
      * Parametros
      * i: um elemento qualquer.
      * j: um elemento qualquer.
      */
      bool mesmoConjunto(int i, int j)
      {
          return busca(i) == busca(j);
      }
 
      /* Dados dois elementos, une os seus respectivos conjuntos considerando o rank 
      * de maior valor (em caso de empate, o elemento de maio indice)
      *
      * Parametros
      * i: um elemento qualquer.
      * j: um elemento qualquer.
      */
      void uniao(int i, int j)
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
 
      /* Imprime as informacoes de quais os elementos estao em cada conjunto.
      * Apresenta-se tambem o rank de cada elemento
      *
      * Parametros
      * p: vetor que armazena os pais de cada vertice no conjunto disjunto.
      * rank: vetor que armazena o rank de cada elemento do conjunto.
      * n: numero de elementos no conjunto
      */
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

/* retorna o custo da AGM
 * Parametros:
 *  arestas: lista da arestas
 *  n: quantidade de vertices
 *  m: quantidade de arestas
 */
int kruskall(vector<pair<int, ii> >& arestas, int n, int m) {
    // ordenacao em O(mlogm), de acordo com https://www.cplusplus.com/reference/algorithm/sort/?kw=sort
    sort(arestas.rbegin(), arestas.rend());
 
    // custo da AGM
    int custo = 0;
	int menor = arestas[0].first;
 
    UFDS ufds(n); // codigo equivalente ao MAKE-SET(v) do pseudocodigo
 
    int u, v;
    pair<int, ii> e;
 
    int numero_arestas = 0;
    for (int i = 0; i < (int)arestas.size(); i++) {
        e = arestas[i];
        u = e.second.first;
        v = e.second.second;
		custo = e.first;
        if (!ufds.mesmoConjunto(u, v)) {
			if (custo < menor)
				menor = custo;
            numero_arestas++;
            if(numero_arestas == n-1)
              break;
         
            ufds.uniao(u, v);
        }
    }
 
    return menor;
}


// (Grafo Conexo) Uma análise preliminar da empresa de consultoria indicou que sempre existe um caminho entre uma dada intersecção x e outra intersecção y, ao longo de uma sequência de estradas.

class Cidade {
	public:
		// a cidade é modelada por n intersecções e m estradas bidirecionais que conectam os pares de intersecções.
		int n;
		int m;
		vector<pair<int, ii> > estradas; // cada estrada possui uma certa estimativa de capacidade de tráfego, mensurada em veículos por minuto.

		Cidade(int n, int m) {
			this->n = n;
			this->m = m;
		}

		void adicionarEstrada(int u, int v, int c) {
			estradas.push_back(make_pair(c, ii(u, v)));
		}

		int capacidadeMinima() { // a menor capacidade de tráfego das estradas remanescentes seja a maior possível
			return kruskall(estradas, n, m);
		}

		void imprimir() {
			for (int i = 0; i < (int)estradas.size(); i++) {
				cout << "[" << estradas[i].second.first << "," << estradas[i].second.second << "]->c(" << estradas[i].first << ")" << endl;
			}
		}

};



int main() {


	int c; // Número de casos de testes a serem resolvidos
	cin >> c;

	for (int i = 0; i < c; i++) {

		int n, m;

		cin >> n >> m;

		Cidade cidade(n, m);

		for (int j = 0; j < m; j++) {
			int u, v, c;
			cin >> u >> v >> c;
			cidade.adicionarEstrada(u, v, c);
			cidade.adicionarEstrada(v, u, c);
		}

		//cidade.imprimir();

		cout << cidade.capacidadeMinima() << endl;
		
	}

	return 0;
}


