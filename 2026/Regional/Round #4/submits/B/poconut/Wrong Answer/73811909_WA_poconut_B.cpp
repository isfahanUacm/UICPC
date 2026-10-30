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
    friend ostream& operator<<(ostream& o, Mint& a) { o << a.x; return o;}
};
const int mod1 = 1e9+7, mod2 = 998244353;
using mi = Mint<mod2>;

void solve([[ maybe_unused ]] uint32_t tc) {
    ll n, m; cin >> n >> m;
    auto f = [&] (int x) -> mi {
        ll l = m >> (x + 1);
        mi c = 1ll<<x;
        mi res = l * c;
        if (!(m >> x & 1)) {
            return res;
        }
        dbg(res);
        ll r = 0;
        for (int i=0; i<x; i++) {
            if (m>>i&1) {
                r |= 1<<i;
            }
        }
        res += r+1;
        dbg(m, x, r, res);
        return res;
    };
    // .....i....
    // 1101010110
    // 110101....

    mi ans = 0;
    for (int i=0; i<=60; i++) {
        ans += (mi)(n+1)*f(i);
    }
    ans -= 1;
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


