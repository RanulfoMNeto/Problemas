#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Point {
    int X, Y;
};

double distance(Point p1, Point p2) {
    return hypot(p1.X - p2.X, p1.Y - p2.Y);
}

double time(double d, double v) {
    return d/v;
}

int main() {
    
    int Xi, Yi, Xf, Yf, V, Xl, Yl, Xr, Yr;

    while(cin >> Xi >> Yi >> Xf >> Yf >> V) {
        cin >> Xl >> Yl >> Xr >> Yr;
        Point house = {Xi, Yi}, school = {Xf, Yf}, lotl = {Xl, Yl}, lotr = {Xr, Yr};
        double up = distance(house, {Xl, Yr}) + distance(lotr, school);
        double down = distance(house, lotl) + distance({Xr, Yl}, school);
        double lot_length = lotr.X - lotl.X;
        cout << fixed << setprecision(1) << time((min(up, down))+lot_length, V) << "\n";
    }

    return 0;
}