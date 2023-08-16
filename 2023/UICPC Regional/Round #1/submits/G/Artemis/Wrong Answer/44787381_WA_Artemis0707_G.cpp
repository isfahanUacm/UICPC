#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 2000;
vector<int> adj[mx];
bool visited[mx];
bool rv[mx];
bool trapped[mx];

void dfs(int x) {
    visited[x] = true;
    for (auto v: adj[x]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void dfs2(int x) {
    rv[x] = true;
    for (auto v: adj[x]) {
        if (!rv[v]) {
            dfs2(v);
        }
    }
}

int main() {
    int n;
    cin >> n;
    map<int, int> id;
    vector<int> ord;

    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u;
        int k;
        cin >> k;
        if (!id.count(u)) {
            id[u] = id.size();
        }
        int uind = id[u];

        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            if (!id.count(v)) {
                id[v] = id.size();
            }
            int vind = id[v];

            adj[uind].push_back(vind);
        }

        ord.push_back(u);
    }

    for (auto x: id) {
        memset(rv, false, sizeof(rv));
        dfs2(x.second);
//        cout << "*" << x.first << ' ' << x.second <<endl;
        if (!rv[id[0]]) {
//            cout << "asd" << endl;
            trapped[x.second] = true;
        }
    }

    dfs(id[0]);

    bool problems = false;
    for (auto y: ord) {
        int x = id[y];
        if (visited[x] && trapped[x]) {
            cout << "TRAPPED " << y << endl;
            problems = true;
        }
    }

    for (auto y: ord) {
        int x = id[y];
//        cout << y << ' ' << x << endl;

        if (!visited[x]) {
            cout << "UNREACHABLE " << y << endl;
            problems = true;
        }
    }

    if (!problems) {
        cout << "NO PROBLEMS" << endl;
    }
}


