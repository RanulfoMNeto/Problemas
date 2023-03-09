#include <iostream>
#include <vector>
#include <queue>
#include <climits>

/*
	Gilson dos Santos Junior 202020783
	Heitor Rodrigues Sabino 202120101
	Ranulfo Mascari Neto 202120792
*/

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;


int INFINITY = INT_MAX;

vector<int> currentPath;

vvi copyGraph;

/*
	Algoritmo baseado na implementação desenvolvida por Manvi Saxena em FavTutor:
	https://favtutor.com/blogs/ford-fulkerson-algorithm
*/

// Using BFS as a searching algorithm
int bfs(int source,int target,int n,vector<int>& parent,vvi& graph){
	currentPath.clear();
	//Update the parent vector as each node value to be -1
	fill(parent.begin(),parent.end(),-1);
	//parent of source node to be -2
	parent[source] = -2;
	//Initializing queue for storing and min capacity so far
	queue<pair<int,int> > q;
	//Source node min capacity to be 1e9
	q.push(ii(source,INFINITY));
	
	//Looping while queue is not empty 
	while(!q.empty()){
		//storing top node and min capacity so far
		int u = q.front().first;
		currentPath.push_back(u);
		int cap = q.front().second;
		
		//Removing top node from queue
		q.pop();
		//Looping all edges from u
		for(int v=0;v<n;v++){
			//finding v node has edge from u
			if(u!=v && graph[u][v]!=0 && parent[v]==-1){
				//storing parent v to be u
				parent[v] = u;
				//Updating the minimum capacity
				int min_cap = min(cap,graph[u][v]);
				//If v is the target node then return minimum capacity
				if(v==target){
					currentPath.push_back(v);
					return min_cap;
				}
				//if we didn't find target node
				//Insert the v node and minimum capacity so far in queue
				q.push(ii(v,min_cap));
			}
		}
	}
	//if we didn't find path between source to target return 0
	return 0;
}

int Ford_Fulkerson(int source,int target,int n,vvi& graph){
	//Initializing parent vector for finding the path from source to target
	//In which we add parent of the node
	vector<int> parent(n,-1);
	//Initializing maximum flow for storing ans
	int max_flow = 0;
	int min_cap = 0;   //storing minimum capacity in each path
	
	//looping while minimum capacity become zero 
	//For finding path and minimum capacity we call function bfs()
	while((min_cap = bfs(source,target,n,parent,graph))){

		

		//Adding the min_cap from this path 
		max_flow += min_cap;
		//storing target node in v
		int v = target;
		
		//while we didn't find the source node
		//Looping through path stored in parent 
		while(v!=source){
			//finding parent of v node
			int u = parent[v];
			//Subtracting minimum capacity from u to v
			//And adding minimum capacity from v to u
			graph[u][v] -= min_cap;
			graph[v][u] += min_cap;
			//Update the v node to it's parent
			v=u;
		}
	}
	//Returning maximum flow in the graph
	return max_flow;
}

// Também seria necessário selecionar as arestas saturadas da Rede Residual de cada iteração do Método Ford-Fulkerson, ao invés de apenas a iteração final

// Inserir a aresta (u,v) em G.E, caso sua inserção não torne possível existir um caminho de s até t
void inserirArestas(vvi grafoSemArestasSaturadas, vii arestasSaturadas, int s, int t) {
	// Realizar uma ordenação das arestas (por custo) parar determinar o melhor conjunto de arestas (das inseridas) de um corte mínimo
	// imprimir arestas inseridas (resposta)
}

int main() {
	
	int n; // number of vertices
	int m; // number of edges
	
	int s = 0; // s(1): source
	int t = 5; // t(2): target

	do {

		cin >> n >> m;

		vvi graph = vvi(n, vi(n, 0)); // graph adjacency matrix

		for(int i = 0; i < m; i++) {		
			int u, v, c; // edge leaving vertex 'u' and reaching 'v' with cost c
			cin >> u >> v >> c;
			u = u - 1;
			v = v - 1;

			graph[u][v] = c;
			

			int z = graph.size();
			for (int j = 0; j < n; j++)
				graph[j].push_back(0);
			n++;
			graph.push_back(vi(n,0));
			// propagação energética bidirecional
			// c[u][v] = c[v][u]
			graph[v][z] = c;
			graph[z][u] = c;
		}
		
		copyGraph = graph;

		if (n) {
			Ford_Fulkerson(s,t,n,graph);
			vii arestasSaturadas;
			// Seleciona as arestas saturadas da rede residual (candidatas ao corte mínimo) na iteração final
			for (int i = 0; i < graph.size(); i++) {
				for (int j = 0; j < graph[i].size(); j++) {
					if (copyGraph[i][j] != 0) {
						if (graph[i][j] == 0) {
							arestasSaturadas.push_back(ii(i,j));
						}
					}
				}
			}

			/*
				Infelizmente não foi possível finalizar a implementação do código em razão do tempo.
				No entanto, deixo aqui uma possível resolução para o problema utilizando a função "inserirArestas" que retornaria (imprimir) as arestas da solução.
			*/
			// inserirArestas(vvi grafoSemArestasSaturadas, vii arestasSaturadas, int s, int t);
			
			for (int j = 0; j < arestasSaturadas.size(); j++) {
				cout << arestasSaturadas[j].first+1 << " " << arestasSaturadas[j].second+1 << endl;
			}
			cout << endl;
		}
		copyGraph.clear();
	
	} while (n and m);

	return 0;
}
