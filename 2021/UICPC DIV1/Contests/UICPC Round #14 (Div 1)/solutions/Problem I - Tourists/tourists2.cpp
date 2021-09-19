#include <bits/stdc++.h>
using namespace std;

// Tourists

const int maxn = 2e5 + 3;
const int inf = INT_MAX;

int n;
vector<int> adj[maxn];

vector<int> euler;
int ind[maxn], h[maxn];

void dfs(int u, int p, int h1){
    ind[u] = euler.size();
    euler.push_back(u);
    h[u] = h1;
    for(int v : adj[u])
        if(v != p)
            dfs(v, u, h1 + 1), euler.push_back(u);
}

int seg[8 * maxn];

void build(int v, int tl, int tr){
    if(tl == tr)
        seg[v] = h[euler[tl]];
    else{
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid + 1, tr);
        seg[v] = min(seg[2 * v], seg[2 * v + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return inf;
    if(tl == l && tr == r)
        return seg[v];
    int mid = (tl + tr) / 2;
    return min(query(2 * v, tl, mid, l, min(r, mid)), query(2 * v + 1, mid + 1, tr, max(l, mid + 1), r));
}

int lca(int u, int v){
    int i = ind[u], j = ind[v];
    if(j < i)
        swap(i, j);
    int h2 = query(1, 0, euler.size() - 1, i, j);
    return h[u] - h2 + h[v] - h2;
}

long long int ans = 0;

int main(){
    cin >> n;
    int x, y;
    for(int i = 0; i < n-1; i++)
        cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    dfs(1, -1, 0);
    build(1, 0, euler.size() - 1);
    for(int v = 2; v <= n; v++)
        ans += h[v] + 1;
    for(int u = 2; u <= n; u++)
        for(int v = 2 * u; v <= n; v += u)
            ans += lca(u, v) + 1;
    cout << ans << endl;
}