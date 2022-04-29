#include <bits/stdc++.h>
using namespace std;

// Helpful Currents

const int mod = 1000003;

bool reached = false;

int n, m, x;
char g[303][50003];
long long int dp[303][50003];

long long int cdp(int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(g[i][j] == '@'){
        reached = true;
        return dp[i][j] = 1;
    }
    long long int ans = 0;
    if(i && g[i-1][j] != '#')
        ans += cdp(i-1, j), ans %= mod;
    if(g[i][j] == '>')
        ans += cdp(i, j+1), ans %= mod;
    if(g[i][j] == '<')
        ans += cdp(i, j-1), ans %= mod;
    return dp[i][j] = ans;
}

int main(){
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j], dp[i][j] = -1;
    cdp(n-1, x);
    if(reached)
        cout << dp[n-1][x] << endl;
    else
        cout << "begin repairs" << endl;
}