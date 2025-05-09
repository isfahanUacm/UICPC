#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);


vector<int> adj[100001];

void solve()
{
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> d(n+1), man(n+1), v1(n+1), v2(n+1);
    for(int i=1; i<=n; i++)
        cin >> v1[i];
    for(int i=1; i<=n; i++)
        cin >> v2[i];
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++) {
        d[i] = v1[i];
        man[i] = v2[i];
        for(int u : adj[i]) {
            d[i] += v1[u];
            man[i] += v2[u];
        }
    }
    while(q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int cnt, v;
            string kind;
            cin >> cnt >> kind >> v;
            if (kind == "desk") {
                d[v] += cnt;
                for (int u: adj[v])
                    d[u] += cnt;
            } else {
                man[v] += cnt;
                for (int u: adj[v])
                    man[u] += cnt;
            }
        } else {
            int v;
            cin >> v;
            if (d[v] > man[v])
                cout << "desks\n";
            else if (d[v] < man[v])
                cout << "monitors\n";
            else
                cout << "same\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
//    cin >> n;
    while(n--)
        solve();


    return 0;
}