#include <iostream>
#include <cmath>

int main() {
    int R1, X1, Y1, R2, X2, Y2;
    while(std::cin >> R1 >> X1 >> Y1 >> R2 >> X2 >> Y2) {
        std::cout << (((hypot(X2-X1, Y2-Y1) + R2) <= R1) ? "RICO" : "MORTO") << std::endl;
    }
    return 0;
}