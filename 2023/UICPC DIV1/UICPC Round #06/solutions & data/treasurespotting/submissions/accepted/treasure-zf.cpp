#include <iostream>
#include <complex>

#define MAXW 1000
#define MAXP 1000

using namespace std;

typedef long long ll;
typedef complex<ll> point;

ll   dot(point a, point b) { return real(a*conj(b)); }
ll cross(point a, point b) { return imag(a*conj(b)); }

int  ccw(point a, point b, point c) {
    ll x = cross(a-b, c-b);
    return x?(x>0?1:-1):0;
}

// check if a lies on the segment [b,c], works if b==c
bool on(point a, point b, point c) {
    return ccw(b,a,c) == 0 && dot(b-a,c-a) <= 0;
}

bool touch(point a, point b, point c, point d) {
    // check if an endpoint lies on the other segment
    if (on(a,c,d) || on(b,c,d) || on(c,a,b) || on(d,a,b)) return true;

    // here, they cannot touch if they are parallel or at least one is a point
    if (cross(a-b,c-d) == 0) return false;

    return ccw(c,a,d)*ccw(c,b,d) != 1 && ccw(a,c,b)*ccw(a,d,b) != 1;
}

point read() {
    ll x, y;
    cin >> x >> y;
    return point(x, y);
}

int main() {
    int w, p;
    point walls[2*MAXW], people[2*MAXP];

    cin >> w >> p;
    point tr = read();
    for (int i = 0; i < 2*w; ++i) walls[i] = read();
    for (int i = 0; i < 2*p; ++i) people[i] = read();

    for (int i = 0; i < p; ++i) {
        point pos = people[2*i];
        point dir = people[2*i+1]-pos;

        bool ok = dot(tr-pos, dir) >= 0 && norm(tr-pos) <= norm(dir);

        for (int j = 0; j < w; ++j)
            ok &= !touch(pos, tr, walls[2*j], walls[2*j+1]);

        for (int j = 0; j < p; ++j)
            ok &= (i == j || !touch(pos, tr, people[2*j], people[2*j]));

        cout << (ok?"visible":"not visible") << endl;
    }

    return 0;
}
