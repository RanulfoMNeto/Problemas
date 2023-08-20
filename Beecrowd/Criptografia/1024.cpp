#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, n;
    cin >> N;
    cin.ignore();
    for (n = 0; n < N; n++) {
        string line;
        getline(cin, line);
        int size = line.size(), m;
        for (m = 0; m < size; m++) {
            int c = line[m];
            if (isalpha(c)) line[m] = c + 3;
        }
        reverse(line.begin(), line.end());
        for (m = size / 2; m < size; m++) {
            line[m] = line[m] - 1;
        }
        cout << line << "\n";
    }
    return 0;
}