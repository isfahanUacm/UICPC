#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  endl '\n'
void solve() {
int n;
cin>>n;
if(n>=2&&n<=12)
{
    cout<<"Yes";
}
else cout<<"No";
return;

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
