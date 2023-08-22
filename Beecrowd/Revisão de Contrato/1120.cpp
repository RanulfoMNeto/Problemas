#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    char D;
    string N;

    while(1) {
        cin >> D >> N;
        if (D == '0' && N == "0") break;
        for (int i = 0; i < N.size(); i++) {
            if (N[i] == D) N.erase(N.begin() + i--);
        }
        for (int i = 0; i < N.size(); i++) {
            if (N[i] == '0') N.erase(N.begin() + i--); else break;
        }
        cout << (N.empty()?"0":N) << "\n";
    }

    return 0;
}