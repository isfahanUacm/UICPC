#include<bits/stdc++.h>
using namespace std;

int t, n, k, a, b;
vector<int> adj[13];
long long int dp[13][(1 << 10) + 3];
vector<pair<int, int>> forbid;

void construct(){
    for (int i = 0; i < n; i++)
        adj[i].clear();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (1 << n) + 1; j++){
            dp[i][j] = -1;
        }
        for (int j = i + 1; j < n; j++){
            bool flag = true;
            for (int kk = 0; kk < k; kk++){
                if (forbid[kk] == make_pair(i, j) || forbid[kk] == make_pair(j, i)){
                    flag = false;
                    break;
                }
            }
            if (flag){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

long long int cdp (int i, int mask){
    // cerr << i << " " << mask << " : " << endl;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    if (i == 0 && mask != 0)
        return dp[i][mask] = 0;
    long long int ans = 0;
    for (auto v : adj[i]){
        // cerr << i << " " << v << " " << mask << endl;
        if (!(mask & (1 << v)))
            ans += cdp(v, mask | (1 << v));
        // cerr << "res: " << i << " " << ans << endl;
    }
    return dp[i][mask] = ans;
}

int main(){
    cin >> t;
    for (int i = 0; i < t; i++){
        forbid.clear();
        cin >> n >> k;
        for (int j = 0; j < k; j++){
            cin >> a >> b; a--; b--;
            forbid.push_back({a, b});
        }
        construct();
        // for (int i = 0; i < n; i++){
        //     for (auto v: adj[i])
        //         cout << v << " ";
        //     cout << endl;
        // }
        dp[0][(1 << n) - 1] = 1;
        cout << "Case #" << i + 1 << ": " << (cdp(0, 0) / 2) % 9901 << endl;
    }
    return 0;
}