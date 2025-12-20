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

    LCA(int n) : n(n) {
        adj.assign(n + 1, {});
        depth.assign(n + 1, -1);

        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;
        up.assign(LOG, vector<int>(n + 1, 0));
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int root = 1) {
        vector<int> parent(n + 1, 0);
        stack<int> st;
        st.push(root);
        parent[root] = root;
        depth[root] = 0;
        up[0][root] = root;

        while (!st.empty()) {
            int v = st.top(); st.pop();
            for (int to : adj[v]) {
                if (to == parent[v]) continue;
                parent[to] = v;
                depth[to] = depth[v] + 1;
                up[0][to] = v;
                st.push(to);
            }
        }

        for (int j = 1; j < LOG; ++j) {
            for (int v = 1; v <= n; ++v) {
                up[j][v] = up[j - 1][ up[j - 1][v] ];
            }
        }
    }

    int lift(int v, int k) {
        for (int j = 0; j < LOG; ++j) {
            if (k & (1 << j)) v = up[j][v];
        }
        return v;
    }

    int lca(int a, int b) {
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
            edges.push_back({u, i, w});
            lca.addEdge(u , i);
        }
        lca.init();
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
            else if(!vis[u] && u != 1){
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
            else if(!vis[v] && v != 1){
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
            for (int x: ans) {
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