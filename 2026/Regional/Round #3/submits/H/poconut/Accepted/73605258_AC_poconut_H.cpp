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
    int n; cin >> n;
    vector<vector<int>> g(n);
    for (int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //1 2 3
    array<vector<mi>, 2> dp{vector<mi>(n), vector<mi>(n)};
    vector<mi> chfree(n, 1);
    auto dfs = [&] (auto&& self, int u, int par=-1) -> void {
        dp[1][u] = 1;
        for (int v: g[u]) if (v != par) {
            self(self, v, u);
            chfree[u] *= dp[0][v]+dp[1][v];
            dp[1][u] *= dp[0][v];
        }
        for (int v: g[u]) if (v != par) {
            dp[0][u] += chfree[v] * chfree[u] / (dp[0][v] + dp[1][v]);
        }
    };
    dfs(dfs, 0);
    dbg(dp);
    mi ans = (dp[0][0]+dp[1][0]);
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


