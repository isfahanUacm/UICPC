#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pi pair<int, int>
#define pl pair<ll, ll>
#define F first
#define S second
#define vi vector<int>
#define pb push_back
#define pf push_front
#define nl '\n'
#define MOD 1000000007
#define MOD1 998244353
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0);
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
/**************************************************************/
#ifdef LOCAL
#include "/home/mamad/debug.h"
#else
#define debug(...) 42
#define arrdebug(...) 42
#endif
/**************************************************************/

const int N = 1e5 + 9;
pi arr[N];

struct DSU {
    int parent[N], rank[N], sz[N];
    int c; //connected components

    DSU(int n = 0) : c(0) {
        for (int i = 1; i <= n; ++i) make(i);
    }
    void make(int i) {
        parent[i] = i;
        sz[i] = 1;
        c++;
    }
    int find(int i) {
        return (parent[i] == i ? i : (parent[i] = find(parent[i])));
    }
    bool same(int i, int j) {
        return find(i) == find(j);
    }
    int get_size(int i) {
        return sz[find(i)];
    }
    int count() {
        return c;    
    }
    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --c;
        if (rank[i] > rank[j]) swap(i, j);
        parent[i] = j;
        sz[j] += sz[i];
        if (rank[i] == rank[j]) rank[j]++;
        return j;
    }
};

void solve()
{
    ll n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.merge(a, b);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu.parent[i] == i) {
            int z = dsu.get_size(i);
            ans += 1ll * z * (z - 1) / 2;
        }
    }
    ld ans1 = 1.0 * ans / (n * (n - 1) / 2);
    cout << fixed << setprecision(8) << ans1 << nl;
}

int32_t main()
{
    fastio();
    solve();
    
    #ifdef LOCAL
    cout << "____________________" << endl << endl;
    cout << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    
    return 0;
}