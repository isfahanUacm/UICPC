#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define TESTCASE
//#define TIME
#ifdef DEBUG
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#define dbg(...)
#define TC solve
#endif
#define nl '\n'

template<ll mod>
struct Mint {
    ll x;
    Mint() :x(0) {}
    Mint(ll a) :x((a%mod+mod)%mod) {}
    explicit operator ll() const { return x; }
    explicit operator int() const { return x; }
    
    Mint& operator+=(const Mint& a) { if ((x += a.x) >= mod) x-=mod; return *this;}
    Mint& operator-=(const Mint& a) { if ((x -= a.x) < 0) x+=mod; return *this;}
    Mint& operator*=(const Mint& a) { if ((x *= a.x) >= mod) x%=mod; return *this;}
    friend Mint mpow(Mint a, ll p) { assert(p >= 0); return p==0?1:mpow(a*a, p/2)*(p&1?a:1); }
    Mint& operator/=(const Mint& a) { if ((x *= (ll)mpow(a, mod-2)) >= mod) x%=mod; return *this;}
    
    friend Mint operator+(Mint a, Mint b) { return a += b; }
    friend Mint operator-(Mint a, Mint b) { return a -= b; }
    friend Mint operator*(Mint a, Mint b) { return a *= b; }
    friend Mint operator/(Mint a, Mint b) { return a /= b;}
    
    bool operator<(const Mint& a)const { return x < a.x;}
    bool operator==(const Mint& a)const { return x == a.x;}
    
    friend istream& operator>>(istream& i, Mint& a) { i >> a.x; return i;}
    friend ostream& operator<<(ostream& o, const Mint& a) {o << a.x; return o;}
};
const int mod1 = 1e9+7, mod2 = 998244353;
using  mi = Mint<mod1>;

void solve(int tc) {
    int n; cin >> n;
    mi res = n*mpow((mi)2, n-3);
    cout << res << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i=1; i<=t; i++) {
        TC(i);
    }
    return 0;
}

