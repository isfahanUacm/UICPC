#include <bits/stdc++.h>
using namespace std;

// Atomic Energy

#define num long long int

const int maxd = 100 * 101 + 1;

int n, q;
num dp[maxd];

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> dp[i];
    int m = 1;
    for(int i = 2; i <= n; i++)
        if(dp[i] * m < dp[m] * i)
            m = i;
    int bound = n * (m + 1);    
    for(int i = n + 1; i <= bound; i++){
        dp[i] = dp[i-1] + dp[1];
        for(int j = 2; j <= n; j++)
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
    }
    while(q--){
        int k;
        cin >> k;
        if(k <= bound)
            cout << dp[k] << endl;
        else{
            int take = (k - bound) / m;
            if ((k - bound) % m)
                take++;
            cout << dp[k - take * m] + dp[m] * take << endl;
        }
    }   
}