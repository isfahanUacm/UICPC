#include <bits/stdc++.h>
using namespace std;

// Anthony and Cora

int n, m;
double p[2003], dp[1003][1003];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n + m - 1; i++)
        cin >> p[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++){
            if(i == 0 && j == 0)
                dp[i][j] = 0;
            else if(i == 0)
                dp[i][j] = 0;
            else if(j == 0)
                dp[i][j] = 1;
            else{
                int r = (n - i) + (m - j);
                dp[i][j] = p[r] * dp[i][j-1] + (1 - p[r]) * dp[i-1][j];
            }
        }
    cout << fixed << setprecision(10) << dp[n][m] << endl;
}