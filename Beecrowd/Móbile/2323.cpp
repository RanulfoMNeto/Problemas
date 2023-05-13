#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi; // vetor de vetor de inteiros

int bfs(vvi &LA, int s) {

	int N = LA.size();
	//vector<bool> visitados(N, false);
	queue<int> fila;
    int subMobiles = 0;

	//visitados[s] = true;
	fila.push(s);

	while(!fila.empty()) {

		int u = fila.front();
		fila.pop();

		for (int i = 0; i < LA[u].size(); i++) {

			int v = LA[u][i];
			//if (visitados[v] == false) {
				//visitados[v] = true;
				fila.push(v);
                subMobiles++;
			//}
		}
	}
	return subMobiles;
}

bool balanceamento(vvi &LA) {
    int N = LA.size();
    vi r(N, 0); // armazena o total de sub-móbiles de cada peça

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < LA[i].size(); j++) {
            int u = LA[i][j];
            r[u] = bfs(LA, u); // retorna o número total de sub-móbiles de uma peça da lista de adjacência
        }
        // verifica se o número total de sub-móbiles das peças da lista de adjacência são iguais
        for (int j = 0; j < LA[i].size(); j++) {
            if (j < LA[i].size()-1) {
                int u = LA[i][j];
                int v = LA[i][j+1];
                if (r[u] != r[v]) {
                    return false;
                }
            }
        }
        
    }
    return true;
}

int main() {

    int N; // indica o número de peças utilizadas no móbile
    cin >> N;

    // as peças são identificadas por inteiros de 1 a N => N+1
    vvi LA = vvi(N+1, vi()); // lista de adjacência do grafo

    int M = N; // Cada uma das N linhas seguintes contém dois números inteiros I e J
    for (int m = 0; m < M; m++) {
        int I, J;
        cin >> I >> J;
        LA[J].push_back(I); // indicando que a peça de número I está pendurada na peça de número J 
    }
    if (balanceamento(LA)) {
        cout << "bem" << endl;
    } else {
        cout << "mal" << endl;
    }
    
    return 0;
}
