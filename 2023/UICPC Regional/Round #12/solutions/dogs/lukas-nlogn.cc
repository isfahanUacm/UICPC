//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define double long double

template <class T>
struct Point {
    typedef T coordType;
    typedef Point P;
    typedef const P & R;
    T x, y;
    explicit Point(T x=T(), T y=T()) : x( x), y( y) { }
    bool operator==(R p) const { return x==p.x && y==p.y; }
    P operator+(R p) const { return P(x+p.x, y+p.y); }
    P operator-(R p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(R p) const { return x*p.x + y*p.y; }
    T dist2() const { return x*x + y*y; } //distance^2
    double dist() const { return sqrt((double)dist2()); } //length
    P unit() const {
        if (dist() < 1e-9) return *this;
        return *this/(T)dist();
    } //makes dist()=1
};
template <class T>
ostream & operator<<(ostream & os, const Point<T> & p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
template <class T>
istream & operator>>(istream & is, Point<T> & p) {
    is >> p.x >> p.y;
    return is;
}
template <class P>
double segDist(const P& s, const P& e, const P& p) {
    if (s==e) return (p-s).dist();
    typedef typename P::coordType T;
    T d = (e-s).dist2(), t = min(d,max(T(0),(p-s).dot(e-s)));
    return ((p-s)*d-(e-s)*t).dist()/d;
}

pair<int, double> where(vector<Point<double>>& a, vector<double>& prefixes, double length) {
    if (length >= prefixes.back()) return make_pair(a.size(), -1);
    size_t i = upper_bound(prefixes.begin(), prefixes.end(), length) - prefixes.begin() - 1;
    return make_pair(i, length - prefixes[i]);
}

double closest(vector<Point<double>>& a, vector<Point<double>>& b) {
    vector<double> prefixes(1, 0.0);
    rep(i,0,b.size() - 1)
        prefixes.push_back(prefixes.back() + (b[i + 1] - b[i]).dist());

    double res = 1e10;
    double distance = 0;
    rep(i,0,a.size() - 1) {
        pair<int, double> position = where(b, prefixes, distance);
        size_t q = position.first;
        if (q == b.size()) break;
        Point<double> p = b[q] + (b[q + 1] - b[q]).unit() * position.second;

        Point<double> mova = a[i + 1] - a[i];
        Point<double> movb = b[q + 1] - p;

        double lena = mova.dist();
        double lenb = movb.dist();
        double len = min(lena, lenb);
        Point<double> diff = a[i] - p;
        Point<double> cura = a[i] + mova.unit() * len;
        Point<double> curb = p + movb.unit() * len;
        res = min(res, segDist(diff, cura - curb, Point<double>(0, 0)));

        distance += (a[i] - a[i + 1]).dist();
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<Point<double>> a(n);
    rep(i,0,n) cin >> a[i];
    a.push_back(a.back());
    int m; cin >> m;
    vector<Point<double>> b(m);
    rep(i,0,m) cin >> b[i];
    b.push_back(b.back());

    double ma = min(closest(a, b), closest(b, a));
    printf("%.9Lf\n", ma);
}
