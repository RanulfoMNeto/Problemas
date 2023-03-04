#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;


int INFINITY = INT_MAX;

// Using BFS as a searching algorithm
int bfs(int source,int target,int n,vector<int>& parent,vvi& graph){
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

int main() {
	
	int n; // number of vertices
	int m; // number of edges
	
	int s = 1; // s: source
	int t = 2; // t: target

	do {

		cin >> n >> m;

		vvi graph = vvi(n, vi(n, 0)); // graph adjacency matrix

		for(int i = 0; i < m; i++) {		
			int u, v, c; // edge leaving vertex 'u' and reaching 'v' with cost c
			cin >> u >> v >> c;

			graph[u][v] = c;
			// propagação energética bidirecional
			int z = graph.size();
			// c[u][v] = c[v][u]
			graph[v][z] = c;
			graph[z][u] = c;
		}
		cout << "Maximum Flow Using Ford Fulkerson Algo: " << Ford_Fulkerson(s,t,n,graph) << endl;

	} while (n && m);	

	return 0;
}

