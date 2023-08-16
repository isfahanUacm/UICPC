#include <bits/stdc++.h>
using namespace std;


void dfs(int x, int y, int n, vector<vector<bool>>& vis) {
    if (vis[x][y])
        return;
    vis[x][y]= true;
    if (x == n-1 && y == n-1){
        cout << "THE GAME IS A LIE";
        exit(0);
    }

    if (x < n-1){
        dfs(x+1, y, n, vis);
    }
    if (x > 0){
        dfs(x-1, y, n, vis);
    }

    if (y < n-1){
        dfs(x, y+1, n, vis);
    }

    if (y > 0){
        dfs(x, y-1, n, vis);
    }
}

int main() {
    int n;
    cin >>n;
    vector<string> arr(n);
    vector<vector<long>> dp(n, vector<long>(n));

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i){
        if (arr[n-1][n-i-1] == '#')
            break;
        dp[n-1][n-i-1] = 1;
    }

    for (int i = 0; i < n; ++i) {
        if (arr[n-i-1][n-1] == '#')
            break;
        dp[n-i-1][n-1] = 1;
    }
    for (int i = n-2; i >= 0; --i) {
        for (int j = n-2; j >= 0; --j) {
            if(arr[i][j]=='#') {
                dp[i][j]= 0;
            } else{
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
    }
//    for (auto a : dp) {
//        for(auto  b : a){
//            cout<< b <<" ";
//        }
//        cout << endl;
//    }

    if(dp[0][0] > 0) {
        long m = pow(2, 31)-1;
        cout << dp[0][0] % m;
    } else {
        vector<vector<bool>> vis(n, vector<bool>(n));
        dfs(0, 0, n, vis);
        cout << "INCONCEIVABLE";

    }
    return 0;
}
