#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc; // vetor de vetor de caracteres

typedef vector<bool> vb;
typedef vector<vb> vvb; // vetor de vetor de booleanos

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int , ii> iii; // (distância, (i, j))

int INF = INT_MAX;


iii bfs(vvc &LA, int N, int M, int i, int j) {

	vvb visitados = vvb(N, vb(M, false));
    vvi d = vvi(N, vi(M, INF));

	queue<ii> fila;

	visitados[i][j] = true;
    d[i][j] = 0;
	fila.push(ii(i, j));

    ii entrada;
    int maior = 0;

	while(!fila.empty()) {

		i = fila.front().first;
        j = fila.front().second;
		fila.pop();

        char v = LA[i][j];
        if ((i > 0) && (visitados[i-1][j] == false) && (LA[i-1][j] == '.')) {
            visitados[i-1][j] = true;
            d[i-1][j] = d[i][j] + 1;
            maior = d[i-1][j];
            entrada = ii(i-1,j);
            fila.push(ii(i-1, j));
        }
        if ((j < M-1) && (visitados[i][j+1] == false) && (LA[i][j+1] == '.')) {
            visitados[i][j+1] = true;
            d[i][j+1] = d[i][j] + 1;
            maior = d[i][j+1];
            entrada = ii(i,j+1);
            fila.push(ii(i, j+1));
        }
        if ((i < N-1) && (visitados[i+1][j] == false) && (LA[i+1][j] == '.')) {
            visitados[i+1][j] = true;
            d[i+1][j] = d[i][j] + 1;
            maior = d[i+1][j];
            entrada = ii(i+1,j);
            fila.push(ii(i+1, j));
        }
        if ((j > 0) && (visitados[i][j-1] == false) && (LA[i][j-1] == '.')) {
            visitados[i][j-1] = true;
            d[i][j-1] = d[i][j] + 1;
            maior = d[i][j-1];
            entrada = ii(i,j-1);
            fila.push(ii(i, j-1));
        }
	}
    return iii(maior, entrada);

}

int main() {
	int N; // número de linhas do labirinto
	int M; // número de colunas do labirinto

	cin >> N >> M;

    while(N != 0 && M != 0) {
        vvc LA = vvc(N, vc(M, '#')); // labirinto

        for (int i = 0; i < M; i++) {	
            for (int j = 0; j < M; j++) {	
                // O caractere da i-ésima linha e da j-ésima coluna indica o que há na posição i, j do labirinto.
                cin >> LA[i][j];
            }
        }

        bool encontrou = false;
        ii entrada;
        for (int i = 0; i < N && !encontrou; i++) {	
            for (int j = 0; j < M && !encontrou; j++) {
                if (LA[i][j] == '.') {
                    encontrou = true;
                    // encontra a entrada do labirinto (maior distância)
                    entrada = bfs(LA, N, M, i, j).second; // retorna a entrada
                }
            }
        }

        int maior = bfs(LA, N, M, entrada.first, entrada.second).first; // encontra a saída do labirinto a partir da maior distância da entrada
        
        cout << maior << endl;

        cin >> N >> M;
    }

	return 0;
}