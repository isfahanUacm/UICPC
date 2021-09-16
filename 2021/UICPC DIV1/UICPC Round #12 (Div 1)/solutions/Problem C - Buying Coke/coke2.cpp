#include <bits/stdc++.h>
using namespace std;

// Buying Coke

const int inf = INT_MAX;

int t, C, n1, n5, n10, m;
int dp[153][303][53];

int cdp(int c, int n5, int n10){
    if(dp[c][n5][n10] != -1)
        return dp[c][n5][n10];
    if(c == C)
        return dp[c][n5][n10] = 0;
    int n1 = m - 5 * n5 - 10 * n10 - 8 * c;
    int ans = inf;
    if(n1 >= 8){
        int subp = cdp(c+1, n5, n10);
        if(subp != inf)
            ans = min(ans, 8 + subp);
    }
    if(n5 >= 1 && n1 >= 3){
        int subp = cdp(c+1, n5-1, n10);
        if(subp != inf)
            ans = min(ans, 4 + subp);
    }
    if(n5 >= 2){
        int subp = cdp(c+1, n5-2, n10);
        if(subp != inf)
            ans = min(ans, 2 + subp);
    }
    if(n10 >= 1){
        int subp = cdp(c+1, n5, n10-1);
        if(subp != inf)
            ans = min(ans, 1 + subp);
    }
    if(n10 >= 1 && n1 >= 3){
        int subp = cdp(c+1, n5+1, n10-1);
        if(subp != inf)
            ans = min(ans, 4 + subp);
    }
    if(n5 >= 2 && n1 >= 3){
        int subp = cdp(c+1, n5-1, n10);
        if(subp != inf)
            ans = min(ans, 5 + subp);
    }
    return dp[c][n5][n10] = ans;
}

int main(){
    cin >> t;
    while(t--){
        cin >> C >> n1 >> n5 >> n10, m = n1 + 5 * n5 + 10 * n10;
        for(int i = 0; i < 153; i++)
            for(int j = 0; j < 303; j++)
                for(int k = 0; k < 53; k++)
                    dp[i][j][k] = -1;
        cout << cdp(0, n5, n10) << endl;
    }
}