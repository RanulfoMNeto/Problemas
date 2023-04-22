#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Monte {
    public:
        int D;
        int T;
        Monte(int D, int T) {
            this->D = D;
            this->T = T;
        }
        Monte() {}
};

bool operator<(Monte const & m1, Monte const & m2) {
    return m1.D < m2.D;
}

int main() {
    int N;
    cin >> N;
    vector<Monte> montes(N);
    for (int i = 0; i < N; i++) {
        int D, T;
        cin >> D >> T;
        Monte monte(D, T);
        montes[i] = monte;
    }
    sort(montes.rbegin(), montes.rend());
    char resp = 'S';
    for (int i = 0; i < montes.size()-1; i++) {
        if (montes[i].T > montes[i+1].T) {
            resp = 'N';
        }
    }
    cout << resp << endl;
    return 0;
}