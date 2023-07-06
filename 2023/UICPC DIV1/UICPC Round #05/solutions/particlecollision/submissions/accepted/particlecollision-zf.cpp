#include <iostream>
#include <complex>
#include <algorithm>

#define EPS 1e-8

using namespace std;

typedef complex<double> point;

void read(point& p) {
    double x, y;
    cin >> x >> y;
    p = point(x, y);
}

// returns the value t so b - (a+dir*t) is the new direction vector,
// returns -1 if no collision
double hit(point a, point b, point dir, double r) {
    double A = norm(dir), B = -2*real(dir*conj(b-a)), C = norm(b-a) - 4*r*r;
    if (fabs(A) < EPS) return -1;

    double disc = B*B - 4*A*C;

    if (disc < -EPS) return -1;

    double t = (-B-sqrt(abs(disc)))/(2*A);

    if (t < -EPS) return -1;

    return t;
}

int main() {
    point p[3], dir;
    double r;

    for (auto& q : p) read(q);
    read(dir);
    cin >> r;

    int adj = 0;

    double t1 = hit(p[0], p[1], dir, r), t2 = hit(p[0], p[2], dir, r);
    if (t2 > -0.5 && (t1 < -0.5 || t2 < t1)) {
        ++adj;
        swap(p[1], p[2]);
        swap(t1, t2);
    }
    point dd = p[1] - (p[0] + t1*dir);
    if (t1 < -0.5) cout << 5 << endl;
    else if (hit(p[1], p[2], p[1]-(p[0]+t1*dir), r) < -0.5) cout << 3+adj << endl;
    else cout << 1+adj << endl;

    return 0;
}
