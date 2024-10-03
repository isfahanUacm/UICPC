#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int min_cyc_at(vvi &g, int s) {
    vi dist(g.size(), -1);
    vi par(g.size(), -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    int mn = INT_MAX;
    while(q.size() > 0) {
        int cur = q.front();
        q.pop();
        for(int x : g[cur]) {
            if(par[cur] == x) continue;
            if(dist[x] != -1) {
                mn = min(mn, dist[cur] + dist[x] + 1);
                continue;
            }
            dist[x] = dist[cur] + 1;
            par[x] = cur;
            q.push(x);
        }
    }
    return mn;
}

ll cyc_num_at(vvi &g, int s, int l) {
    vi dist(g.size(), -1);
    vi par(g.size(), -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(q.size() > 0) {
        int cur = q.front();
        q.pop();
        for(int x : g[cur]) {
            if(par[cur] == x) continue;
            if(dist[x] == -1 && dist[cur] < l / 2) {
                dist[x] = dist[cur] + 1;
                par[x] = cur;
                q.push(x);
            }
        }
    }
    ll ans = 0;
    if(l % 2 == 0) {
        for(int i = 0; i < g.size(); ++i) {
            if(dist[i] != l / 2) continue;
            ll cnt = 0;
            for(int j : g[i]) {
                if(dist[j] != (l / 2) - 1) continue;
                cnt++;
            }
            ans += cnt * (cnt - 1) / 2;
        }
    } else {
        for(int i = 0; i < g.size(); ++i) {
            if(dist[i] != l / 2) continue;
            for(int j : g[i]) {
                if(j < i) continue;
                if(dist[j] != l / 2) continue;
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, u, v;
    cin >> n >> m;
    vvi g(n, vi());
    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    vi cycs(n);
    for(int i = 0; i < n; ++i) cycs[i] = min_cyc_at(g, i);
    int mn = INT_MAX;
    for(int i = 0; i < n; ++i) mn = min(mn, cycs[i]);
    ll res = 0;
    for(int i = n - 1; i >= 0; --i) {
        if(mn == cycs[i]) res += cyc_num_at(g, i, mn); 
        g.pop_back();
        for(int j = 0; j < i; ++j) {
            if(g[j].size() > 0 && g[j].back() == i) g[j].pop_back();
        }
    }
    cout << res << '\n';
}
