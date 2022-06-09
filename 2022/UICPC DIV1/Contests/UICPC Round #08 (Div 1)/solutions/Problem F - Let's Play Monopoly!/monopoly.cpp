#include <bits/stdc++.h>
using namespace std;

#define num long long int

num dp[100003], val[100003];
vector<int> adj[100003];
int n, m, k, sa, sb, b, r, valu;

num cdp(int u) {
    if (dp[u] > LLONG_MIN) 
        return dp[u];
    if (adj[u].empty()) 
        return dp[u] = 0; 
    for (int v : adj[u]) { 
        dp[u] = max(dp[u], val[v] + cdp(v));
    }
    return dp[u];
}

int main(){
    cin >> n >> m >> k >> sa >> sb;
    sa--; sb--;
    int u, v;
    for (int i = 0; i < m; i++){
        cin >> u >> v; u--; v--;
        adj[u].push_back(v);
    }
    string typ;
    for (int i = 0; i < n; i++){
        cin >> typ;
        if (typ == "PROPERTY")
            cin >> b >> r;
        else{
            cin >> valu;
            if (typ == "SALARY")
                val[i] = valu;
            else
                val[i] = -valu;
        }
    }
    
    fill_n(dp, n, LLONG_MIN);
    num res1 = cdp(sa);
    fill_n(dp, n, LLONG_MIN);
    num res2 = cdp(sb);

    cout << res1 << " " << res2 << endl;

    return 0;
}