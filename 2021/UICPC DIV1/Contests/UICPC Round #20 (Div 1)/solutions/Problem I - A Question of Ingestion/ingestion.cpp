#include <bits/stdc++.h>
using namespace std;

// A Question of Ingestion

#define num long long int
num n, m, a[103], b[103];

num dp[103][103][3];

num cdp(int i, int j, int k){
    if(i >= n || j >= n)
        return 0;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    num ans;
    if(k == 0){
        ans = cdp(i+1, j+1, 0);
        ans = max(ans, cdp(i+1, j, 1));
        ans = max(ans, cdp(i+1, j, 2));
        ans += min(a[i], b[j]);
    }
    else if(k == 1)
        ans = cdp(i+1, j, 0);
    else 
        ans = cdp(i+2, 0, 0);
    return dp[i][j][k] = ans;
}

int main(){
    cin >> n >> m;
    b[0] = m;
    for(int i = 1; i < n; i++)
        b[i] = b[i-1] * 2 / 3;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < 3; k++)
                dp[i][j][k] = -1;
    cout << max(cdp(0, 0, 2), max(cdp(0, 0, 0), cdp(0, 0, 1))) << endl;
}