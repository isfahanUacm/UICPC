#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

struct LCA {
    int n, LOG;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> comp;

    LCA(int n) : n(n) {
        adj.assign(n + 1, {});
        depth.assign(n + 1, -1);
        comp.assign(n + 1, -1);

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        up.assign(LOG, vector<int>(n + 1, 0));
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void build() {
        int cid = 0;
        queue<int> q;
        for (int start = 1; start <= n; ++start) {
            if (depth[start] != -1) continue;
            ++cid;
            depth[start] = 0;
            comp[start] = cid;
            up[0][start] = start;
            q.push(start);

            while (!q.empty()) {
                int v = q.front(); q.pop();
                for (int to : adj[v]) {
                    if (depth[to] == -1) {
                        depth[to] = depth[v] + 1;
                        up[0][to] = v;
                        comp[to] = cid;
                        q.push(to);
                    }
                }
            }
        }

        for (int j = 1; j < LOG; ++j) {
            for (int i = 1; i <= n; ++i) {
                up[j][i] = up[j - 1][ up[j - 1][i] ];
            }
        }
    }

    int lift(int v, int k) {
        for (int j = 0; j < LOG && v != 0; ++j) {
            if (k & (1 << j)) {
                v = up[j][v];
            }
        }
        return v;
    }

    int lca(int a, int b) {
        if (a < 1 || a > n || b < 1 || b > n) return -1;
        if (comp[a] == -1 || comp[b] == -1) return -1;
        if (comp[a] != comp[b]) return -1;

        if (depth[a] < depth[b]) swap(a, b);
        a = lift(a, depth[a] - depth[b]);
        if (a == b) return a;

        for (int j = LOG - 1; j >= 0; --j) {
            if (up[j][a] != up[j][b]) {
                a = up[j][a];
                b = up[j][b];
            }
        }
        return up[0][a];
    }

    int dist(int u, int v) {
        int c = lca(u, v);
        if (c == -1) return -1;
        return depth[u] + depth[v] - 2 * depth[c];
    }
};

void solve() {
    int n;
    cin >> n;
    while(n){
        vector<array<int , 3>> edges;
        LCA lca(n);
        for (int i = 2; i <= n; ++i) {
            int u , w;
            cin >> u >> w;
            edges.push_back({u , i, w});
            lca.addEdge(u , i);
        }
        lca.build();
        sort(edges.begin(), edges.end() , [&](auto i , auto j){
            return i[2] < j[2];
        });
        vi vis(n + 1 , 0) , ans;
        int now = 1;
        vis[1] = 1;
        int time = 0;
        bool flag = true;
        for (int i = 0; i < n - 1; ++i) {
            auto [u , v , w] = edges[i];
            if(!vis[u] && !vis[v]) {
                if (lca.depth[u] < lca.depth[v]) {
                    int common = lca.lca(u, now);
                    int p1 = lca.dist(common, u);
                    int cnt = 1;
                    for (int j = 0 ; j < p1; ++j) {
                        if (!vis[lca.up[j][u]]) {
                            cnt++;
                        }
                        else {
                            break;
                        }
                    }
                    if(time + cnt <= w){
                        for (int j = cnt - 1; j >= 0; --j) {
                            if (!vis[lca.up[j][u]] && lca.up[j][u] != 1) {
                                ans.push_back(lca.up[j][u]);
                                vis[lca.up[j][u]] = 1;
                            }
                        }
                        ans.push_back(u);
                        vis[u] = 1;
                        ans.push_back(v);
                        vis[v] = 1;
                        time += cnt;
                        now = u;
                    }
                    else{
                        cout << "no\n";
                        flag = false;
                        break;
                    }
                }
                else{
                    int common = lca.lca(v, now);
                    int p1 = lca.dist(common, v);
                    int cnt = 1;
                    for (int j = 0 ; j < p1; ++j) {
                        if (!vis[lca.up[j][v]]) {
                            cnt++;
                        }
                        else {
                            break;
                        }
                    }
                    if(time + cnt <= w){
                        for (int j = cnt - 1; j >= 0; --j) {
                            if (!vis[lca.up[j][v]] && lca.up[j][v] != 1) {
                                ans.push_back(lca.up[j][v]);
                                vis[lca.up[j][v]] = 1;
                            }
                        }
                        ans.push_back(v);
                        vis[v] = 1;
                        ans.push_back(u);
                        vis[u] = 1;
                        time += cnt;
                        now = v;
                    }
                    else{
                        cout << "no\n";
                        flag = false;
                        break;
                    }

                }
            }
            else if(!vis[u]){
                if(time <= w){
                    ans.push_back(u);
                    now = v;
                    time++;
                }
                else{
                    cout << "no\n";
                    flag = false;
                    break;
                }
            }
            else if(!vis[v]){
                if(time <= w){
                    ans.push_back(v);
                    now = u;
                    time++;
                }
                else{
                    cout << "no\n";
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            cout << "yes\n";
            for (int x : ans) {
                cout << x << " ";
            }
            cout << "\n";
        }
        cin >> n;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}