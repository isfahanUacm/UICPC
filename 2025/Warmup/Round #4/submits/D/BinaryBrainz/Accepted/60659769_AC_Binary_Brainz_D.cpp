#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    ll ans=0;
    int v=a;
    if(a==c)
    {
        cout<<abs(d-b);
        return;
    }
    else {
        ans = (n-b) + d+1;
        ans += (c-a-1)*(n+1);
        cout << ans;
        return;
    }

}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
        if (t != 0)
            cout << '\n';
    }
}
