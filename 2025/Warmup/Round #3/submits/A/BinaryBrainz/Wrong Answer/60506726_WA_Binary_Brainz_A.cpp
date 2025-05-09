#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

ll poww(ll a ,ll b){
    if(b==0)return 1;
    ll ans = poww(a , b/2);
    ans = (ans*ans)%MOD;
    if(b%2==1)
        ans = (ans*a)%MOD;
    return ans;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = (i * f[i - 1]) % MOD;
    }

    ll tmp = f[n - k - 1] *poww((f[m - k] * f[n - m - 1])%MOD,MOD-2);

    if (m - k >= k) {
        tmp = (tmp - (f[n-2*k] *poww((f[m-2*k+1] * f[n-m-1])%MOD,MOD-2)) + MOD )% MOD;
    }

    tmp = tmp * 3;
    tmp = tmp % MOD;

    cout << tmp;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        if(t!=0)
            cout<<endl;
    }
}
