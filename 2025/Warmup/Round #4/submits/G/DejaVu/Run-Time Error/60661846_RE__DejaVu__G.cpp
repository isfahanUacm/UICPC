#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;

// Linear Sieve with Smallest Prime Factor(SPF), O(n)
vector<int> spf, primes;
void sieve(int n) {
    spf.assign(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int)primes.size() && i * primes[j] <= n && primes[j] <= spf[i]; j++) {
            spf[i * primes[j]] = primes[j];
        }
    }
}

vector<bool> visited(1e6, false);
vector<ll> dp(1e6, 0);
vector<ll> par(1e6, -1);

void dfs(ll u, vector<set<ll>>& g) {
    visited[u] = true;

    for (ll v : g[u]) {
        if (!visited[v])
            dfs(v, g);

        if (dp[u] < dp[v] + 1) {
            par[u] = v;
            dp[u] = dp[v] + 1;
        }
    }
}

void solve() {
    const int N = 1e6;
    sieve(N);

    int n;
    cin >> n;

    vl s(n), q;
    map<ll, set<ll>> idxs;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        idxs[s[i]].insert(i);
    }
    q = s;

    set<ll> uniques;
    for (auto x : s) {
        if (x != 1) {
            uniques.insert(x);
        }
    }

    vl result(uniques.begin(), uniques.end());
    s = result;
    n = s.size();
    sort(s.begin(), s.end());

    map<ll, ll> id, idp;
    for (int i = 0; i < n; i++) {
        id[s[i]] = i;
    }
    
    ll m = primes.size();
    for (int i = 0; i < m; i++) {
        idp[primes[i]] = i;
    }

    vector<set<ll>> g(n, set<ll>());
    vector<ll> mxP(m);

    for (int i = 0; i < n; i++) {
        ll x = s[i];
        set<ll> pf;
        while (x > 1) {
            pf.insert(spf[x]);
            x /= spf[x];
        }

        for (ll u : pf) {
            if (mxP[u] != 0) {
                g[id[mxP[u]]].insert(i);
            }
            mxP[u] = s[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, g);
        }
    }

    ll idxAns = 0;
    for (int i = 0; i < n; i++) {
        if (dp[idxAns] < dp[i])
            idxAns = i;
    }

    vl res = {};
    while (idxAns != -1) {
        res.push_back(s[idxAns]);
        idxAns = par[idxAns];
    }

    cout << res.size() << endl;
    ll hi = *idxs[res[0]].begin();
    cout << hi + 1 << ' ';
    for (int i = 1; i < res.size(); i++) {
        ll a = *idxs[res[i]].begin();
        cout << a + 1 << ' ';
        hi = a; 
    }

    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}