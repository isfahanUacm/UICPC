#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long 
ll f(ll n, ll k) {
    if(n < k) return n;
    ll r0 = n % k;
    return r0 + 1 + f((n - r0) / k, k);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll r, k;
        cin >> r >> k;
        if(r == 0){
            cout << 0 << "\n";
            continue;
        }
        if(r < k){
            cout << r << "\n";
            continue;
        }
        ll bb = (r % k == 0 ? r - 1 : r);
        ll aa = k - 1;
        ll cc = f(bb, k);
        cout << max(cc, aa) << "\n";
    }
    return 0;
}
