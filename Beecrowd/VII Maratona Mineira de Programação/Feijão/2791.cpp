#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    int n = 4;
    vi C(n, 0);
    int feijao;
    for (int i = 0; i < n; i++) {
        cin >> C[i];
        if (C[i]) {
            feijao = i;
        }
    }
    cout << feijao+1 << endl;
    return 0;
}