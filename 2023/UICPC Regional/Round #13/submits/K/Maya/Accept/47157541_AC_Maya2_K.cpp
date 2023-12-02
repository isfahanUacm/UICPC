#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define F first
#define S second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef DEBUG
#include "/home/mohammad/Code/debug.h"
#else
#define dbg(x...)
#define dbgarr(x, s)
#define LINE
#define TIME
#endif


const int MOD = 1000000007;
//const int MOD = 998244353;
const char nl = '\n';
const int N =  2e5 + 9;


struct mi {
    ll v; explicit operator ll() const { return v; }
    mi() { v = 0; }
    mi(ll _v) {
        v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0) v += MOD;
    }

    friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
    friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
    friend bool operator<=(const mi& a, const mi& b) { return a.v < b.v; }
    
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
    mi& operator+=(const mi& m) { if ((v += m.v) >= MOD) v -= MOD; return *this; }
    mi& operator-=(const mi& m) { if ((v -= m.v) < 0) v += MOD; return *this; }
    mi& operator*=(const mi& m) { v = v*m.v%MOD; return *this; }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    
    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    mi operator++(int) { mi temp; temp.v = v++; return temp; }
    mi operator--(int) { mi temp; temp.v = v--; return temp; }

    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mi inv(const mi& a) {
        assert(a.v != 0);
        return pow(a, MOD-2);
    }
    
    friend ostream& operator<<(ostream& os, const mi& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, mi& m) {
        ll x; is >> x;
        m.v = x;
        return is;
    }
};

mi fact[N];
mi fact_inv[N];

void init_fact(int n) {
    fact[0] = 1;
    for (int i = 1; i < n; i++) {
        fact[i] = (fact[i-1] * i);
    }
    fact_inv[n - 1] = inv(fact[n - 1]);
    for (int i = n - 1; i >= 0; i--) {
        fact_inv[i] = fact_inv[i + 1] * (i + 1);
    }
}

mi choose(mi _a, mi _b) {
    ll a = (ll) _a, b = (ll) _b;
    if (b > a || a < 0 || b < 0) return 0;
    mi cur = fact[a];
    cur = cur * inv(fact[b]);
    cur = cur * inv(fact[a - b]);
    return cur;
}


void solve() {
	mi k;
	ll n; cin >> n >> k;	
	for (int i = 0; i < n-1; i++) {
		int a; cin >> a;
	}
	mi ans = 0;
	for (mi i = 0; i < k-1; i++) {
		if (ll(i)%2==0) ans += choose(k, i) * (k-i) * pow((k-i-1), (n-1));
		else ans -= choose(k, i) * (k-i) * pow((k-i-1), (n-1));
	}
	cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	init_fact(2600);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
        LINE
    }
    TIME

    return 0;
}
