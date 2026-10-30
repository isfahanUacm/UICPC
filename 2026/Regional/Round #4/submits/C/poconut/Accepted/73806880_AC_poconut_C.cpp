#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define TESTCASE
#ifdef LOCAL
#include "local.hpp"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl '\n'

template<class T, int N>
struct Point {
    array<T, N> p;
    Point(initializer_list<T> v) {
        copy(v.begin(), v.end(), p.begin());
    }
    Point() {
        p = array<T, N>{};
    }
    T& operator[](int i) {
        assert(i<N);
        return p[i];
    }
    const T& operator[](int i) const {
        assert(i<N);
        return p[i];
    }
    Point operator +(const Point& other) const {
        Point ret = *this;
        for (int i=0; i<N; i++) {
            ret[i] += other[i];
        }
        return ret;
    }
    Point operator -(const Point& other) const {
        return *this + -1*other;
    }
    Point operator *(const T& scaler) const {
        Point ret = *this;
        for (int i=0; i<N; i++) {
            ret[i] *= scaler;
        }
        return ret;
    }
    friend Point operator *(const T& scaler, const Point& q) {
        return q*scaler;
    }
    Point operator /(const T& scaler) const {
        Point ret = *this;
        for (int i=0; i<N; i++) {
            ret[i] /= scaler;
        }
        return ret;
    }
    friend Point operator /(const T& scaler, const Point& q) {
        return q/scaler;
    }

    friend T dot(const Point& a, const Point &b) {
        T ret = 0;
        for (int i=0; i<N; i++) {
            ret += a[i]*b[i];
        }
        return ret;
    }
    // returns norm^2
    friend T norm2(const Point& q) {
        return dot(q, q);
    }
    friend Point crs(const Point& a, const Point& b) {
        assert(N == 3);
        return Point({
            a[1]*b[2]-a[2]*b[1],
            a[2]*b[0]-a[0]*b[2],
            a[0]*b[1]-a[1]*b[0]
        });
    }
    // returns sign of cross product for 2D vectors
    friend T scrs(const Point& a, const Point& b) {
        assert(N == 2);
        return a[0]*b[1] - a[1]*b[0];
    }

    void operator +=(const Point& other) {
        *this = *this + other;
    }
    void operator -=(const Point& other) {
        *this = *this - other;
    }
    void operator *=(const T& scaler) {
        *this = *this * scaler;
    }
    bool operator < (const Point &other) const {
        return p < other.p;
    }
    bool operator == (const Point &other) const {
        return p == other.p;
    }


    friend ostream& operator<<(ostream& os, const Point& q) {
        os << "(";
        for (int i=0; i<N; i++) {
            os << q[i] << ",)"[i==N-1];
        }
        return os;
    }
    friend istream& operator >>(istream& is, Point& q) {
        for (int i=0; i<N; i++) {
            is >> q[i];
        }
        return is;
    }
    static bool pol_cmp(const Point &a, const Point &b) {
        assert(N == 2);
        auto low_half = [&] (const Point &x) {
            return x[1] < 0 || (x[1] == 0 && x[0] < 0);
        };
        if (low_half(a) == low_half(b)) {
            return scrs(a, b) > 0;
        }
        return low_half(a) < low_half(b);
    }
};
using P = Point<ll, 2>;

void solve([[ maybe_unused ]] uint32_t tc) {
    int n; cin >> n;
    vector<P> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    P v = P{1, 1};
    array<ll, 3> c{};
    for (int i=0; i<n; i++) {
        ll t = scrs(a[i], v);
        if (t == 0) {
            c[0]++;
        } else if (t > 0) {
            c[1]++;
        } else {
            c[2]++;
        }
    }
    ll ans = 0;
    for (int i=0; i<n; i++) {
        ll t = scrs(a[i], v);
        if (t == 0) {
            ans += n-1;
        } else if (t > 0) {
            ans += c[0]+c[2];
        } else if (t < 0) {
            ans += c[0]+c[1];
        }
    }
    ans /= 2;
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    
    #ifdef TESTCASE
    cin >> t;
    #endif
    for (int i=1; i<=t; i++) {
        Solve(i);
    }
    return 0;
}


