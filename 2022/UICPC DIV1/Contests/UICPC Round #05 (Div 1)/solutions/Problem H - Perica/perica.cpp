#include <bits/stdc++.h>
using namespace std;

long long int C[100003][53];
const long long int mod = 1000000007;


void calc(){
    C[0][0] = 1;
    for (int i = 1; i < 100001; ++i) {
        for (int j = 0; j <= 50; ++j) {
            if(j == 0){
                C[i][j] = 1;
                continue;
            }
            C[i][j] = (C[i-1][j-1] % mod + C[i-1][j] % mod) % mod;
        }
    }
}

int n, k;
long long int arr[100003];

int main()
{
    calc();
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n, greater<int>());
    long long int res = 0;
    for (int i = 0; i <= n-k; ++i) {
        res = (res + ((arr[i] % mod) * (C[n-i-1][k-1] % mod)) % mod) % mod; 
    }
    cout << res << endl;
    return 0;
}

