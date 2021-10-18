#include <bits/stdc++.h>
using namespace std;

int n, d;
int a[43][403];
int dp[43][43][403][13];
pair<int, int> trace[43][43][403][13];

int cdp(int i, int j, int k, int c){
    if(i >= n || i > j || k >= d)
        return 0;
    if(dp[i][j][k][c] != -1)
        return dp[i][j][k][c];
    int ans = INT_MAX;
    for(int cc = c; cc < 9; cc++){
        int sum = 0;
        for(int z = i; z <= j; z++){
            sum += (a[z][k] != cc);
            int tmp = cdp(i, z, k + 1, 0) + cdp(z + 1, j, k, cc + 1) + sum;
            if(ans > tmp){
                ans = tmp;
                trace[i][j][k][c] = {cc, z};
            }
        }
    }
    int sum = 0;
    for(int z = i; z <= j; z++)
        sum += (a[z][k] != 9);
    int tmp = sum + cdp(i, j, k + 1, 0);
    if(tmp < ans){
        ans = tmp;
        trace[i][j][k][c] = {9, j};
    }
    return dp[i][j][k][c] = ans;
}

void build(int i, int j, int k, int c){
    if(i >= n || i > j || k >= d)
        return;
    pair<int, int> helper = trace[i][j][k][c];
    int cc = helper.first, zz = helper.second;
    for(int z = i; z <= zz; z++)
        a[z][k] = cc;
    build(i, zz, k + 1, 0);
    build(zz + 1, j, k, cc + 1);   
}


int main(){
    for(int i = 0; i < 43; i++)
        for(int z = 0; z < 43; z++)
            for(int j = 0; j < 403; j++)
                for(int k = 0; k < 13; k++)
                dp[i][z][j][k] = -1;

    cin >> n >> d;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < d; j++){
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }

    cdp(0, n - 1, 0, 0);
    build(0, n - 1, 0, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++)
            cout << a[i][j];
        cout << endl;
    }
}