#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

vi dists(vvi &g, vi s) {
    int n = g.size();
    vi dist(n, -1);
    queue<int> q;
    for(int z : s) dist[z] = 0;
    for(int z : s) q.push(z);
    while(q.size() > 0) {
        int cur = q.front();
        q.pop();
        for(int x : g[cur]) {
            if(dist[x] != -1) continue;
            dist[x] = dist[cur] + 1;
            q.push(x);
        }
    }
    return dist;
}

ii furthest(vvi &g, int s) {
    vi dist = dists(g, vi({s}));
    int mx = -1, mxi = -1;
    for(int i = 0; i < dist.size(); ++i) {
        if(dist[i] > mx) {
            mx = dist[i];
            mxi = i;
        }
    }
    return ii(mx, mxi);
}

vi path(vvi &g, int s, int t) {
    vi dist = dists(g, vi({s}));
    vi path;
    path.push_back(t);
    int cur = t;
    while(cur != s) {
        for(int z : g[cur]) {
            if(dist[z] == dist[cur] - 1) {
                path.push_back(z);
                cur = z;
                break;
            }
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, u, v; cin >> n;
    vvi g(n, vi());
    for(int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int nd = furthest(g, 0).second;
    ii res = furthest(g, nd);
    int girth = res.first + 1, opp = res.second;
    if(girth <= 3) {
        cout << "NO\n";
        return 0;
    }
    assert(g[nd].size() == 1);
    cout << "YES\n";
    vi spine = path(g, nd, opp);
    for(int i = 2; i < spine.size(); ++i) cout << spine[i] + 1 << ' ';
    cout << spine[1] + 1 << ' ' << spine[0] + 1 << ' ';
    vi spinedist = dists(g, spine);
    vii ord;
    for(int i = 0; i < n; ++i) {
        if(spinedist[i] > 0) {
            ord.push_back(ii(spinedist[i], i));
        }
    }
    sort(ord.begin(), ord.end());
    for(ii p : ord) cout << p.second + 1 << ' ';
    cout << '\n';
}
