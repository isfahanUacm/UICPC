#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, dp[10][(1 << 10) + 3];
vector<int> adj[13];

int tsp(int cur, int visited){
    if (dp[cur][visited])
        return dp[cur][visited];
    if (cur == 0 && visited != 0){
        int c = 0;
        for (int i = 0; i < n; i++)
            if (visited & (1 << i))
                c++;
        return dp[cur][visited] = c;
    }
    int ans = 0;
    for (auto v: adj[cur])
        if (!(visited & (1 << v)))
            ans = max(ans, tsp(v, visited | (1 << v)));
    return dp[cur][visited] = ans;
}

int main(){
    while (cin >> n && n){
        for (int i = 0; i < n; i++){
            adj[i].clear();
            for (int j = 0; j < (1 << n); j++)
                dp[i][j] = 0;
        }
        cin >> m;
        for (int i = 0; i < m; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        tsp(0, 0);
        int res = 1;
        for (int i = 0; i < (1 << n); i++)
            res = max(res, dp[0][i]);
        cout << res << endl;
    }
    return 0;
}