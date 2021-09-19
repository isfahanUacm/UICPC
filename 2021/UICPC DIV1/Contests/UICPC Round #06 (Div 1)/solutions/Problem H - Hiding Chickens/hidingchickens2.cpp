#include <bits/stdc++.h>
using namespace std;

// Hiding Chickens

int n;
pair<double, double> points[23];
double dis[23][23];

double dp[(1<<21)+3];

double cdp(int mask){
    if(dp[mask] != -1)
        return dp[mask];
    int cnt = 0;
    int i, j;
    for(int node = 1; node < n; node++)
        if(mask & (1<<(node-1))){
            cnt++;
            if(cnt == 1)
                i = node;
            if(cnt == 2)
                j = node;
        }
    if(cnt == 1){
        return dp[mask] = dis[0][i];
    }
    if(cnt == 2){
        double ans = min(dis[0][i], dis[0][j]) + dis[i][j];
        ans = min(ans, 2 * dis[0][i] + dis[0][j]);
        ans = min(ans, 2 * dis[0][j] + dis[0][i]);
        return dp[mask] = ans;
    }
    double ans = INT_MAX;
    for(int i = 1; i < n; i++)
        if(mask & (1<<(i-1))){
            ans = min(ans, 2 * dis[0][i] + cdp(mask - (1<<(i-1))));
            for(int j = 1; j < n; j++)
                if(j != i && (mask & (1<<(j-1))))
                    ans = min(ans, dis[0][i] + dis[i][j] + dis[j][0] + cdp(mask - (1<<(i-1)) - (1<<(j-1))));
        }
    return dp[mask] = ans;
}

int main(){
    cin >> points[0].first >> points[0].second;
    cin >> n;
    n++;
    for(int i = 1; i < n; i++)
        cin >> points[i].first >> points[i].second;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++){
            double deltax = points[i].first - points[j].first;
            double deltay = points[i].second - points[j].second;
            dis[i][j] = sqrt(deltax * deltax + deltay * deltay);
            dis[j][i] = dis[i][j];
        }
    for(int i = 0; i < ((1<<21)+3); i++)
            dp[i] = -1;
    cout << fixed << setprecision(10) << cdp((1<<(n-1)) - 1) << endl;
}