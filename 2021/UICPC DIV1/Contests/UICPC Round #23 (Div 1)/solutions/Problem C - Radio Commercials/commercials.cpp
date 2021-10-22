#include <bits/stdc++.h>
using namespace std;

// Radio Commercials

int n, p;
int arr[100003];
long long int dp[100003];

int main(){
    cin >> n >> p;
    for(int i = 0; i < n; i++)
        cin >> arr[i], arr[i] -= p;
    dp[0] = arr[0];
    for(int i = 1; i < n; i++)
        dp[i] = max(arr[i] + 0ll, arr[i] + dp[i-1]);
    cout << *max_element(dp, dp+n) << endl;
}