#include <bits/stdc++.h>
using namespace std;

int t, C, N5, N10, N1, M;
int dp[153][53][200];

int cdp(int c, int n10, int n5){
    if(dp[c][n10][n5] != -1){
        return dp[c][n10][n5];
    }
    if(c == C){
        return 0;
    }
    int n1 = M - n10 * 10 - n5 * 5 - c * 8;
    int res = INT_MAX;
    if(n10 >= 1){
        res = min(res, cdp(c+1, n10-1, n5) + 1);
    }
    if(n5 >= 2){
        res = min(res, cdp(c+1, n10, n5-2) + 2);
    }
    if(n5 >= 1 && n1 >= 3){
        res = min(res, cdp(c+1, n10, n5-1) + 4);
    }
    if(n1 >= 8){
        res = min(res, cdp(c+1, n10, n5) + 8);
    }
    if(n10 >= 1 && n1 >= 3){
        res = min(res, cdp(c+1, n10-1, n5+1) + 4);
    }
    return dp[c][n10][n5] = res;
}


int main()
{
    cin >> t;
    while(t--){
        cin >> C >> N1 >> N5 >> N10;
        for (int i = 0; i < C+1; ++i)
            for (int j = 0; j < N10+1; ++j)
                for (int k = 0; k < 201; ++k)
                    dp[i][j][k] = -1;
        M = N10 * 10 + N5 * 5 + N1;
        cout << cdp(0, N10, N5) << endl;
    }
    return 0;
}

