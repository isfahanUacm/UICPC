#include <bits/stdc++.h>
using namespace std;

// City Destruction

#define num long long int

const int maxn = 1e4 + 3;

int n;
num d, h[maxn], e[maxn], dp[maxn][3];

inline num cost(num h){
    h = max(h, 0ll);
    return h / d + ((h % d) ? 1 : 0);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 0; i < n; i++)
            cin >> h[i];
        for(int i = 0; i < n; i++)
            cin >> e[i];
        if(n == 1){
            cout << cost(h[0]) << endl;
            continue;
        }
        dp[n-1][0] = cost(h[n-1]);
        dp[n-1][1] = cost(h[n-1] - e[n-2]);
        for(int i = n-2; i >= 0; i--)
            for(int p = 0; p <= 1; p++)
                dp[i][p] = min(cost(h[i] - p * (i ? e[i-1] : 0ll)) + dp[i+1][1], cost(h[i] - p * (i ? e[i-1] : 0ll) - e[i+1]) + dp[i+1][0]);
        cout << dp[0][0] << endl;
    }
}