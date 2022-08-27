#include <iostream>
#include <vector>

#define C 100000

#define x first
#define y second
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pt;
typedef pair<Pt, Pt> Seg;
typedef vector<Seg> vseg;

Pt operator + (Pt a, Pt b) { return Pt(a.x+b.x, a.y+b.y); }
Pt operator - (Pt a, Pt b) { return Pt(a.x-b.x, a.y-b.y); }
Pt operator * (ll s, Pt a) { return Pt(s*a.x, s*a.y); }
Pt operator * (Pt a, ll s) { return s*a; }

ll dot(Pt a, Pt b) { return a.x*b.x + a.y*b.y; }
ll cross(Pt a, Pt b) { return a.x*b.y - a.y*b.x; }

ll isLeft(Pt a, Pt b, Pt c) {
    ll z = cross(b-a, c-a);
    if (z == 0) return 0;
    else if (z > 0) return 1;
    else return -1;
}

bool LinesParallel(Pt a, Pt b, Pt c, Pt d) {
    return cross(b-a,c-d) == 0;
}

bool LinesCollinear(Pt a, Pt b, Pt c, Pt d) {
    return LinesParallel(a,b,c,d)
        && isLeft(a,b, c) == 0
        && isLeft(c,d, a) == 0;
}

bool SegmentsIntersect(Pt a, Pt b, Pt c, Pt d) {
    if (LinesCollinear(a,b, c,d)) {
        throw new runtime_error("points on street");

        if (a==c || a == d || b == c || b == d) return true;
        if (dot(a-c,b-c) > 0 && dot(a-d,b-d) > 0 && dot(c-b,d-b) > 0)
            return false;
        return true;
    }
    if (isLeft(a,b, d) * isLeft(a,b, c) > 0) return false;
    if (isLeft(c,d, a) * isLeft(c,d, b) > 0) return false;
    return true;
}

int main() {
    ll S;
    cin >> S;
    vseg street(S);
    for (ll i = 0; i < S; ++i) {
        Pt one, two;
        cin >> one.x >> one.y >> two.x >> two.y;
        Pt diff = two-one;

        street[i].f = one + (-C*diff);
        street[i].s = two + (C*diff);
    }

    for (ll i = 0; i < S; ++i) {
        for (ll j = i+1; j < S; ++j) {
            if (LinesCollinear(street[i].f, street[i].s, street[j].f, street[j].s)) throw new runtime_error("lines are the same");
        }
    }

    ll T;
    cin >> T;
    for (ll i = 0; i < T; ++i) {
        Pt three, four;
        cin >> three.x >> three.y >> four.x >> four.y;

        ll intersections = 0;
        for (ll j = 0; j < S; ++j) {
            if (SegmentsIntersect(three, four, street[j].f, street[j].s))
                ++intersections;
        }
        if (intersections == 0) throw runtime_error("points in same region!");

        if (intersections % 2 == 0)
            cout << "same" << endl;
        else
            cout << "different" << endl;
    }
}
