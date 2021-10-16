#include <bits/stdc++.h>
using namespace std;

// Arranging Hat

int n, m;
char digits[43][403];

int dp[43][43][403][13];
int trt[43][43][403][13];
int trk[43][43][403][13];

int cdp(int gher, int mez, int col, int dig){
    if(dp[gher][mez][col][dig] != -1)
        return dp[gher][mez][col][dig];
    int ans = INT_MAX;
    for(int k = dig; k < 9; k++){
        int transCost = 0;
        for(int t = gher; t <= mez; t++){
            transCost += (k != digits[t][col] - '0');
            int subp = transCost;
            if(t+1 <= mez)
                subp += cdp(t+1, mez, col, k+1);
            if(col+1 <= m-1)
                subp += cdp(gher, t, col+1, 0);
            if(subp < ans){
                ans = subp;
                trt[gher][mez][col][dig] = t;
                trk[gher][mez][col][dig] = k;
            }
        }
    }
    int subp9 = 0;
    for(int t = gher; t <= mez; t++)
        subp9 += ('9' != digits[t][col]);
    if(col+1 <= m-1)
        subp9 += cdp(gher, mez, col+1, 0);
    if(subp9 < ans){
        ans = subp9;
        trt[gher][mez][col][dig] = mez;
        trk[gher][mez][col][dig] = 9;
    }    
    return dp[gher][mez][col][dig] = ans;
}

void trace(int gher, int mez, int col, int dig){
    int itt = trt[gher][mez][col][dig];
    int itk = trk[gher][mez][col][dig];
    if(itt == -1 || itk == -1)
        return;
    for(int t = gher; t <= itt; t++)
        digits[t][col] = '0' + itk;
    if(itt+1 <= mez)
        trace(itt+1, mez, col, itk+1);
    if(col+1 <= m-1)
        trace(gher, itt, col+1, 0);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> digits[i][j];
    for(int i = 0; i < 43; i++)
        for(int j = 0; j < 43; j++)
            for(int k = 0; k < 403; k++)
                for(int d = 0; d < 13; d++){
                    dp[i][j][k][d] = -1;
                    trt[i][j][k][d] = -1;
                    trk[i][j][k][d] = -1;
                }
    cdp(0, n-1, 0, 0);
    trace(0, n-1, 0, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << digits[i][j];
        cout << endl;
    }
}