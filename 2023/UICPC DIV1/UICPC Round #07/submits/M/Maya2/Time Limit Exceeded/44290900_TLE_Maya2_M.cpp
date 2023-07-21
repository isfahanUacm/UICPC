// l a s h v

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endll '\n'
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fori(x, u) for (int i = x; i < u; ++i)
#define forj(x, u) for (int j = x; j < u; ++j)
#define sortv(a) sort(a.begin(), a.end())
#define ES cout << "YES\n"
#define NO cout << "NO\n"
// lower_bound -> greater than or equal
// upper_bound -> greater than
const int maxn = 3e5+9;
int b[maxn];
int v[maxn];

vector<pii> dfs(int node ,vector<vector<int>>& g) {
    vector<pii> mxtrades;
    vector<pii> alltrades;   

    if (g[node].size() == 0) {
        if (b[node] > 0) {
            mxtrades.push_back({v[node], node});
            return mxtrades;
        }
    }
    else {
        for (int x : g[node]) {
            vector<pii> tmp;
            tmp = dfs(x, g);
            for (pii u : tmp) {
                alltrades.push_back(u);
            }
        }
        alltrades.push_back({v[node], node});
        sort(alltrades.begin(), alltrades.end(), greater<pii>());
        fori (0, b[node]) {
            mxtrades.push_back(alltrades[i]);
        }
    }

    return mxtrades;
}

bool cmp(const pii& a, const pii& b) {
    return a.second < b.second;
}

void solve() { 
    int n, tmp;
    cin >> n;
    vector<vector<int>> g(n);
    
    fori (0, n-1) {
        cin >> tmp;
        g[tmp-1].push_back(i+1);
    }
    
    fori (0, n) {
        cin >> b[i];
    }
    fori (0, n) {
        cin >> v[i];
    }

    vector<pii> x;
    x = dfs(0 ,g);

    int mx=0;
    for (pii u : x) {
        mx += u.first;
    }
    cout << mx << endll;
    cout << x.size() << ' ';
    sort(x.begin(), x.end(), cmp);
    for (pii u : x) {
        cout << u.second+1 << ' ';
    }

}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    //int T; cin >> T; while (T--)
    solve();

    return 0;
}