#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int mod = INT_MAX;
int n, arr[2003];
num dp[2003][2003][5];

num cdp(int i, int s, int d){
    if (i == n + 1)
        return 1;
    if (dp[i][s][d] != LLONG_MAX)
        return dp[i][s][d];
        
    num ans = 0;
    int e;
    e = arr[i - 1];

    if (d){
        if (arr[i] < s)
            ans = (ans % mod + cdp(i + 1, s, 1) % mod) % mod;
        if (arr[i] > e)
            ans = (ans % mod + cdp(i + 1, e, 0) % mod) % mod;
    }
    else{
        if (arr[i] > s)
            ans = (ans % mod + cdp(i + 1, s, 0) % mod) % mod;
        if (arr[i] < e)
            ans = (ans % mod + cdp(i + 1, e, 1) % mod) % mod;
    }

    return dp[i][s][d] = ans;
}

int main(){

    cin >> n;
    for (int i = 0; i < n + 1; i++){
        cin >> arr[i];
        for (int j = 0; j <= n + 1; j++){
            dp[i][j][0] = dp[i][j][1] = LLONG_MAX;
        }
    }

    cout << (cdp(2, arr[0], 0) % mod) << endl;
    
    return 0;
}