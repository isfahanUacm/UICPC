#include <bits/stdc++.h>
using namespace std;

// Lost In The Woods

int n, m;
vector<int> adj[23];
double dp[23][1000003];

int main(){
    int x, y;
    cin >> n >> m;
    while(m--)
        cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    for(int k = 0; k <= 100000; k++)
        for(int i = 0; i < n; i++){
            if(!k)
                dp[i][k] = (i == n-1) ? 1 : 0;
            else if(i == n-1)
                dp[i][k] = 0;
            else{
                for(int j : adj[i])
                    dp[i][k] += dp[j][k-1] / (double)adj[i].size();
            }
        }
    double ans = 0;
    for(int k = 0; k <= 100000; k++)
        ans += k * dp[0][k];
    cout << fixed << setprecision(6) << ans << endl;
}