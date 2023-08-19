#include <iostream>

int main() {
    int H1, M1, H2, M2;
    while(std::cin >> H1 >> M1 >> H2 >> M2) {
        if (H1 == 0 && M1 == 0 && H2 == 0 && H2 == 0) break;
        int current_time = H1 * 60 + M1;
        int alarm_time = H2 * 60 + M2;
        if (alarm_time >= current_time) {
            std::cout << alarm_time - current_time << std::endl;
        } else {
            std::cout << 24 * 60 - current_time + alarm_time << std::endl;
        }
    }
    return 0;
}