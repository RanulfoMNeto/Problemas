#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, n;
    cin >> N;
    cin.ignore();

    for (n = 0; n < N; n++) {
        string number;
        getline(cin, number);
        int size = number.size(), number_leds = 0, i;
        for (i = 0; i < size; i++) {
            switch (number[i]) {
                case '0':
                    number_leds += 6;
                    break;
                case '1':
                    number_leds += 2;
                    break;
                case '2':
                    number_leds += 5;
                    break;
                case '3':
                    number_leds += 5;
                    break;
                case '4':
                    number_leds += 4;
                    break;
                case '5':
                    number_leds += 5;
                    break;
                case '6':
                    number_leds += 6;
                    break;
                case '7':
                    number_leds += 3;
                    break;
                case '8':
                    number_leds += 7;
                    break;
                case '9':
                    number_leds += 6;
                    break;
            }
        }
        cout << number_leds << " leds\n";
    }
    return 0;
}