#include <bits/stdc++.h>
using namespace std;

double dp[1003][1003];
double tree[2003];
double target[1003];

double dis(double x, double y, double a, double b){return sqrt((x-a)*(x-a)+(y-b)*(y-b));}
int main()
{
    int n;
    cin>>n;
    double L, W;
    cin>>L>>W;
    for (int i = 0; i < n; ++i)
        cin>>tree[i];
    sort(tree, tree+n);
    n = n/2; double d = L/(n-1);
    for (int i = 0; i < n; ++i)
        target[i] = i*d;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0] + dis(tree[i-1],0,target[i-1], 0);
        dp[0][i] = dp[0][i-1] + dis(tree[i-1],0,target[i-1], W);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = min(dp[i-1][j]+dis(tree[i+j-1], 0, target[i-1], 0), dp[i][j-1]+dis(tree[i+j-1], 0, target[j-1], W));
        }    
    }
    printf("%.6f\n", dp[n][n]);
    
    return 0;
}

