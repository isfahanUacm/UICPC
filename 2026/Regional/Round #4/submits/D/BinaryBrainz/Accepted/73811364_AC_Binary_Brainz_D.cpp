#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vll vector<long long>
#define ll long long

vector<vector<ll>> g;
ll mxd = 0;

void dfs(ll node, ll dpt, vector<ll>& d) {

    d[node] = dpt;

    if (dpt > mxd)
        mxd = dpt;

    for (auto &neig : g[node]) {
        if (d[neig] == 0)
            dfs(neig,dpt+1, d);
    }
}


void solve() {

    ll n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    a--;
    b--;
    c--;

    g = vector<vector<ll>>(n);
    vector<ll> l_a(n), l_b(n), l_c(n);

    for (int i =0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    mxd = -1;
    dfs(a, 1, l_a);
    ll mxa = mxd;

    mxd = -1;
    dfs(b, 1, l_b);
    ll mxb = mxd;

    mxd = -1;
    dfs(c, 1, l_c);
    ll mxc = mxd;

    if (l_a[b] > 0) {
        if (l_a[c] > 0) { // A-B-C
            if (l_a[c] < l_b[c]) {
                cout << "Alice";
            }
            else if (l_a[c] > l_b[c]) {
                cout << "Bob";
            }
            else {
                cout << "Tie";
            }
        }
        else { // A-B C
            cout << "Alice";
        }
    }
    else if (l_a[b] == 0) {
        if (l_b[c] == 0) {
            if (l_a[c] == 0) { // A B C
                cout << "Tie";
            }
            else { // A-C B
                ll mx_new_distb = mxb + mxc;
                if (mx_new_distb > l_a[c]) {
                    cout << "Alice";
                }
                else if (mx_new_distb == l_a[c]){
                    cout << "Tie";
                }
                else {
                    cout << "Bob";
                }
            }
        }
        else { // A B-C
            if (l_b[c] - 1 > 1) {
                cout << "Alice";
            }
            else {
                cout << "Tie";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
        if (t)
            cout << endl;
    }

    return 0;
}