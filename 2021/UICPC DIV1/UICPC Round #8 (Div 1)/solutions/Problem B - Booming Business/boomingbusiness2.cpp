#include <bits/stdc++.h>
using namespace std;

// Booming Business

#define num long long int
const num mod = 1000000007;

num c[603][603];
num dp[303][303][303];

num cdp(int h, int w, int b){
    if(dp[h][w][b] != -1)
        return dp[h][w][b];
    if(h == 0)
        return dp[h][w][b] = w == 0;
    if(w < h)
        return dp[h][w][b] = 0;
    num ans = 0;
    for(int k = 1; k <= w; k++){
        num tmp = (c[k+b-1][b-1] * cdp(h-1, w-k, k)) % mod;
        ans = (ans + tmp) % mod;
    }
    return dp[h][w][b] = ans;   
}

int main(){
    for(int i = 0; i <= 600; i++)
        for(int j = 0; j <= i; j++){
            if(i == j || j == 0)
                c[i][j] = 1;
            else c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    for(int i = 0; i <= 300; i++)
        for(int j = 0; j <= 300; j++)
            for(int k = 0; k <= 300; k++)
                dp[i][j][k] = -1;
    int h, w;
    cin >> h >> w;
    cout << cdp(h-1, w-1, 1) << endl;
}