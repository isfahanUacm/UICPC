#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
const ll  mod  = 1e9+7;

void solve()
{
    int n; cin >> n;
    if(n==2){
        cout << 1 << '\n';
        return;
    }
    int i = n-3;
    ll ans = 1;
    while(i--){
        ans = (ans * 2LL) % (mod);
    }
    ans = (ans * n) %(mod);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
//    cin >> n;
    while(n--)
        solve();

    return 0;
}