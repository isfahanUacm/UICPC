#include<bits/stdc++.h>
using namespace std;

// Muzicari

int T, n;
int arr[503];
int psum[503];

int dp[503][5003];

int cdp(int i, int a){
    if(i == n)
        return 0;
    if(dp[i][a] != -1)
        return dp[i][a];
    int ans = -2;
    int T1 = T - a;
    int T2 = T + a - (i > 0 ? psum[i-1] : 0);
    if(arr[i] <= T1 && cdp(i+1, a+arr[i]) != -2)
        ans = 1;
    else if(arr[i] <= T2 && cdp(i+1, a) != -2)
        ans = 2;
    return dp[i][a] = ans;
}

int main(){
    cin >> T >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    partial_sum(arr, arr+n, psum);
    for(int i = 0; i < 503; i++)
        for(int j = 0; j < 5003; j++)
            dp[i][j] = -1;
    cdp(0, 0);
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(dp[i][a] == 1){
            cout << a << " ";
            a += arr[i];
        }
        else if(dp[i][a] == 2){
            cout << b << " ";
            b += arr[i];
        }
    }
}