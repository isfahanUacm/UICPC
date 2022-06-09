#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 250;

double dist[MAX];
ll parent[MAX];
set<pair<ll, ll>> ss;
vector<pair<ll, double>> adj[MAX];

void dijkstra(int start) {
    dist[start] = 0;
    parent[start] = start;
    ss.insert({0, start});
    while (!ss.empty()) {
        ll u = ss.begin()->second;
        ss.erase(ss.begin());
        for (auto v : adj[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                ss.erase({dist[v.first], v.first});
                dist[v.first] = dist[u] + v.second;
                ss.insert({dist[v.first], v.first});
                parent[v.first] = u;
            }
        }
    }
}

void print(int end) {
    stack<ll> stc;
    ll ind = end;
    do {
        stc.push(ind);
        ind = parent[ind];
    } while (parent[ind] != ind);
    stc.push(ind);
    while (!stc.empty()) {
        cout << stc.top() << ' ';
        stc.pop();
    }
    cout << endl;
}

struct s {
    int f, x, y;
};

double cDist(s a, s b) {
    return sqrt((a.f - b.f) * (a.f - b.f) + (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<s> vc;
    for (int i = 0; i < n; ++i) {
        s temp;
        cin >> temp.f >> temp.x >> temp.y;
        temp.f *= 5;
        vc.push_back(temp);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        string p;
        cin >> u >> v >> p;

        if (p == "walking" || p == "stairs") {
            double d = cDist(vc[u], vc[v]);

            adj[u].emplace_back(v, d);
            adj[v].emplace_back(u, d);
        }

        if (p == "lift") {
            adj[u].emplace_back(v, 1);
            adj[v].emplace_back(u, 1);
        }

        if (p == "escalator") {
            adj[u].emplace_back(v, 1);

            double d = cDist(vc[u], vc[v]);
            adj[v].emplace_back(u, d * 3);
        }
    }


    int tc;
    cin >> tc;
    while (tc--) {
        for (ll i = 0; i < n; ++i) {
            dist[i] = LONG_LONG_MAX / 2;
        }
        for (ll i = 0; i < n; ++i) {
            parent[i] = 0;
        }

        int u, v;
        cin >> u >> v;
        dijkstra(u);
        print(v);
    }
}