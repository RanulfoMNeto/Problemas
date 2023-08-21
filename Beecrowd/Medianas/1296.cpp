#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double semi_perimeter(double a, double b, double c) {
    return (a+b+c)/2.0;
}

double area(double a, double b, double c) {
    double s = semi_perimeter(a, b, c);
    return (4.0/3.0)*sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    double a, b, c;
    while(cin >> a >> b >> c) {
        double r = area(a, b, c);
        cout << fixed << setprecision(3) << ((isnan(r) || (r == 0))?-1:r) << "\n";
    }

    return 0;
}