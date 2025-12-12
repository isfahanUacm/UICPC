#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=2e5+9,MOD=1e9+7;
int fact[N], a[N], b[N], num1[N], num2[N];

int32_t main(){
    int n;
    cin>>n;

    int ans = n;
    ans = ans%MOD;
    ans += (((2*n)%MOD)*((n+1)%MOD))%MOD;

    int a = n;
    int b = n+1;
    int c = 2*n + 1;
    if (a % 3 == 0) a /=3;
    else if (b % 3 == 0) b /=3;
    else if (c % 3 == 0) c /=3;

    ans %= MOD;
    ans += (((((2*a)%MOD)*(b%MOD))%MOD)*(c%MOD))%MOD;
    ans %= MOD;
    cout << ans;
    return 0;
}