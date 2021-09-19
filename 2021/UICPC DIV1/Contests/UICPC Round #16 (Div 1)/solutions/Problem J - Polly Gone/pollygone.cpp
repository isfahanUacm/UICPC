#include <bits/stdc++.h>
using namespace std;

long long int dp[1003][10003];
int e[1003], p[1003], psum[1003];
double pp;
int n, P;

long long int cdp(int i, int j){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(j >= P){
        return 0;
    }
//    cerr << i << " " << j << " " << P << " " << p[i] << endl;
    long long int ans = e[i] + cdp(i+1, j+p[i]);
    if(P-j <= psum[n-1]-psum[i]){
        ans = min(ans, cdp(i+1, j));
    }
    return dp[i][j] = ans;
}

int main()
{
    cin >> n >> pp;
    P = (int)(pp * 10000);
    for (int i = 0; i < n; ++i) {
        cin >> e[i] >> pp;
        p[i] = (int)(pp * 10000 + 0.5);
        if(i>=1){
            psum[0] = p[0];
            psum[i] = psum[i-1] + p[i];
//            cerr << psum[i] << endl;
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 10000; ++j) {
            dp[i][j] = -1;
        }
    }
    cout << cdp(0, 0) << endl;
    return 0;
}

