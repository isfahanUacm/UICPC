#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {

    string s;cin>>s;
    ll ind = s.length()-1;
    ll ans = 0;
    while(s[ind] == '0'){
        ans = ans + 1;
        ind--;
    }
    ind--;
    while(ind >= 0){
        if(s[ind] != '0')
            ans ++;
        ind--;
    }
    cout << ans;
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
