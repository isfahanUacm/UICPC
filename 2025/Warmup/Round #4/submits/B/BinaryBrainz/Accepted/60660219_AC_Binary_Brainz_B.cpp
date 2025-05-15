#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {

    ll n,x;
    cin>>n>>x;

    int num = 0;
    while(num < x){
        cout << num << ' ';
        num++;
    }
    num++;
    while(num < n){
        cout << num << ' ';
        num++;
    }
    if(n!=x)
    cout << x;
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
