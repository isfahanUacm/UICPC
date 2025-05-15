#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;cin>>n;
    string s;cin>>s;
    ll ans=0;
    for (int i = 0; i <n ; ++i) {
        ans+=((n-1)*(s[i]-'0'))+(1-(s[i]-'0'));
    }
    cout<<ans;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin>>t;
    while (t--)
    {
        solve();
        if (t != 0)
            cout << '\n';
    }
}
