#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  endl '\n'
void solve() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if((a+b>c&&a+c>b&&b+c>a)||(a+d>c&&a+c>d&&d+c>a)||(d+b>c&&d+c>b&&b+c>d)||(a+b>d&&a+d>b&&b+d>a))
    {
        cout<<"TRIANGLE";
        return;
    }
    if((a+b==c)||(c+b==a)||(a+c==b)||(a+b==d)||(a+d==b)||(d+b==a)||(a+d==c)||(c+d==a)||(a+c==d)||(d+b==c)||(b+c==d)||(d+c==b))
    {
        cout<<"SEGMENT";
        return;
    }
    else cout<<"IMPOSSIBLE";

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
