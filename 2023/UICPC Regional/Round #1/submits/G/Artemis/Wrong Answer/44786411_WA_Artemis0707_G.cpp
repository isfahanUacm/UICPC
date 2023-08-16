#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 2000;
vector<int> adj[mx];
bool visited[mx];
bool trapped[mx];

void dfs(int x) {
    visited[x] = true;
    for (auto v: adj[x]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> ord;

    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u;
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            adj[u].push_back(v);
        }
        ord.push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        trapped[i] = adj[i].empty();
    }

    dfs(0);

    bool problems = false;
    for (auto x: ord) {
        if (visited[x] && trapped[x]) {
            cout << "TRAPPED " << x << endl;
            problems = true;
        }
    }

    for (auto x: ord) {
        if (!visited[x]) {
            cout << "UNREACHABLE " << x << endl;
            problems = true;
        }
    }

    if (!problems) {
        cout << "NO PROBLEMS" << endl;
    }
}


