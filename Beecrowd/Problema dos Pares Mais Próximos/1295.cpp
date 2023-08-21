// Diego Garbelini Venancio dos Santos - Par de pontos mais próximo: https://youtu.be/frr_Pg6Yb4c?si=-XOsy1TtXbv_4JGa

#include <iostream>
#include <vector>
#include <iomanip>
#include <cfloat>
#include <cmath>
#include <algorithm>

using namespace std;

#define X first
#define Y second

typedef pair<double, double> Point;

int compareX(Point p1, Point p2) {
    return p1.X < p2.X;
}

int compareY(Point p1, Point p2) {
    return p1.Y < p2.Y;
}

double brute_force(vector<Point>& P, int left, int right) {
    double shorter_distance = DBL_MAX;
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j < right; ++j) {
            shorter_distance = min(shorter_distance, hypot(P[i].X - P[j].X, P[i].Y - P[j].Y));
        }
    }
    return shorter_distance;
}

double closest_pair(vector<Point>& P, int left, int right) {
    if (right - left <= 3) {
        return brute_force(P, left, right);
    }
    int m = (left + right)/2;
    double dl = closest_pair(P, left, m);
    double dr = closest_pair(P, m, right);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i < right; i++) {
        if (abs(P[i].X - P[m].X) < d) {
            strip.push_back(P[i]);
        }
    }
    sort(strip.begin(), strip.end(), compareY);
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; (j < strip.size()) && ((strip[j].Y - strip[i].Y) < d); j++) {
            d = min(d, hypot(strip[i].X - strip[j].X, strip[i].Y - strip[j].Y));
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        int N;
        cin >> N;
        if (N == 0) break;
        vector<Point> Q;
        for (int n = 0; n < N; n++) {
            double x, y;
            cin >> x >> y;
            Q.push_back(Point(x, y));
        }

        sort(Q.begin(), Q.end(), compareX);
        double shorter_distance = closest_pair(Q, 0, Q.size());
        
        if (shorter_distance >= 10000.0)
            cout << "INFINITY\n";
        else
            cout << fixed << setprecision(4) << shorter_distance << "\n";
    }

    return 0;
}