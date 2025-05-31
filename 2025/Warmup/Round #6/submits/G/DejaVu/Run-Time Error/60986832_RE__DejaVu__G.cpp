#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ":" << x << "\n"
#define deb2(x) cout << ":" << x << "\n"
#define in(x) cin >> x
#define pb push_back
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define f first
#define s second
#define ll int64_t
#define per(i, a, b) for (ll i = a; i <= b; i++)
#define rep(i, a, b) for (ll i = a; i >= b; i--)
#define outl(x) cout << x << endl;
#define outc(x) cout << x << " ";
const ll maxn = 1e5 + 15;
const ll mod = 1e9 + 7;
const ll lg = 22;

#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union, O(alpha(n))
struct DSU
{
    int c;
    vector<int> par, sz;

    DSU() {}
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        c = n;
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }

    int find(int a)
    {
        return (par[a] == a ? a : (par[a] = find(par[a])));
    }
    bool same(int a, int b)
    {
        return find(a) == find(b);
    }
    void merge(int a, int b)
    {
        if ((a = find(a)) == (b = find(b)))
        {
            return;
        }
        if (sz[a] > sz[b])
        {
            swap(a, b);
        }
        par[a] = b;
        sz[b] += sz[a];
        c--;
    }
    int size(int a)
    {
        return sz[find(a)];
    }
    int count()
    {
        return c;
    }
};

void solve()
{
    DSU dsu = DSU();
    ll n;
    cin >> n;
    dsu.init(n - 1);
    per(i, 2, n)
    {
        for (ll j = i; j <= n; j += i)
        {
            dsu.merge(i - 1, j - 1);
        }
    }
    cout << dsu.c - 1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}