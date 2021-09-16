#include <bits/stdc++.h>
using namespace std;

// Walrus Weights

int n, w;
bool dp[2001];

int main(){
    dp[0] = true;
    cin >> n;
    while(n--){
        cin >> w;
        for(int i = 2000 - w; i >= 0; i--)
            if(dp[i])
                dp[i + w] = true;
    }
    for(int d = 0; 1; d++){
        if(dp[1000+d]){
            cout << 1000 + d << endl;
            return 0;
        }
        if(dp[1000-d]){
            cout << 1000 - d << endl;
            return 0;
        }
    }
}