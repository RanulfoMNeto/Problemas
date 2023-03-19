#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<bool> vb;

class Graph {
	public:
		int n;
		int m;
		vvi adj;

		Graph(int n, int m) {
			this->n = n;
			this->m = m;
			adj = vvi(n, vi(n, 0));
		}

		void addEdge(int u, int v, int w) {
			adj[u][v] = w;
		}
};

bool bfs(Graph &graph, int s, int t, vi &parent, vb &visited) {
	visited = vb(graph.n, false);
	
	visited[s] = true;
	parent[s] = -1;
	queue<int> Q;
	Q.push(s);

	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();

		for (int v = 0; v < graph.n; v++) {
			if ((visited[v] == false) and (graph.adj[u][v] > 0)) {
				visited[v] = true;
				parent[v] = u;
				Q.push(v);
			}
		}
	}

	return visited[t];
}

int fordFulkerson(Graph &residualGraph, int s, int t) {
	int maxFlow = 0;
	vb visited(residualGraph.n);
	vi parent(residualGraph.n);
	while(bfs(residualGraph, s, t, parent, visited)) {
		// A quantidade máxima possível de aumento para o fluxo em cada aresta de um caminho aumentador p é denominada capacidade residual de p e é dada por:
		int residualCapacity = INT_MAX;
		for (int v = t; v != s; v = parent[v]) {
			int u = parent[v];
			residualCapacity = min(residualCapacity, residualGraph.adj[u][v]); // min {Cf(u, v) : (u, v) está em p}
		}

		for (int v = t; v != s; v = parent[v]) {
			int u = parent[v];
			residualGraph.adj[u][v] -= residualCapacity;
      		residualGraph.adj[v][u] += residualCapacity;
		}
		maxFlow += residualCapacity;
	}
	return maxFlow;
}

vii solution(Graph graph, vb visited) {
	int n = graph.n;
	vii edges;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { 
			if (graph.adj[i][j] > 0 and visited[i] and !visited[j]) {
				edges.push_back(ii(i, j));
			}
		}
    }
	return edges;
}

int main() {
	
	int n; // Número de vértices
	int m; // Número de arestas
	
	int s = 0; // s(1): source
	int t = 1; // t(2): target

	cin >> n >> m;

	while (n and m) {

		Graph graph(n, m);
		for(int i = 0; i < m; i++) {

			int u, v, c;
			cin >> u >> v >> c;

			u = u - 1;
			v = v - 1;

			graph.addEdge(u, v, c);
			graph.addEdge(v, u, c);
		}
	
		Graph flowGraph = graph;
		// Executar o algoritmo de Ford-Fulkerson.
		fordFulkerson(flowGraph, s, t);

		// Executamos uma DFS ou BFS da fonte "s" novamente.
		vi parent(flowGraph.n); // Não utilizado (apenas para uso da bfs)
		vb visited(flowGraph.n);
		bfs(flowGraph, s, t, parent, visited);

		// Todos os vértices alcançáveis de "s" usando arcos ponderados do grafo original pertencem à componente S.
		// Todos os outros inacessíveis vértices pertencem à componente T.
		// Se uma aresta liga vértices de componentes diferentes, então ela pertence a solução.
		vii edges = solution(graph, visited);
		for (int i = 0; i < edges.size(); i++)
			cout << edges[i].first+1 << " " << edges[i].second+1 << endl;

		cin >> n >> m;
	}

	return 0;
}
