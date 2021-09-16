#include <bits/stdc++.h>
using namespace std;

// Aspen Avenue

int n;
double L, W;
double points[2003];

double dp[2003][1003];

double cdp(int i, int lptr){
    if(dp[i][lptr] != -1)
        return dp[i][lptr];
    if(i == 0 && lptr == 0)
        return dp[i][lptr] = 0;
    int rptr = i - lptr;
    double ans = INT_MAX;
    if(lptr > 0)
        ans = min(ans, abs(points[i] - ((lptr-1) * L)/(n-1)) + cdp(i-1, lptr-1));
    if(rptr > 0){
        double deltax = points[i] - ((rptr-1) * L)/(n-1);
        ans = min(ans, sqrt(W*W + deltax*deltax) + cdp(i-1, lptr));
    }
    return dp[i][lptr] = ans;
}

int main(){
    cin >> n;
    n /= 2;
    cin >> L >> W;
    for(int i = 1; i <= 2 * n; i++)
        cin >> points[i];
    sort(points+1, points+2*n+1);
    for(int i = 0; i < 2003; i++)
        for(int j = 0; j < 1003; j++)
            dp[i][j] = -1;
    cout << fixed << setprecision(10) << cdp(2*n, n) << endl;
}