#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;

void solve()
{
    int n,c;
    ll tmp;
    cin>>n >> c;

    ll b = c;
    ll count = 1;

    for(int i =0 ; i < n ; i ++){
        cin >> tmp;
        b -= tmp;
        if(b <= 0){
            b = c;
            count++;
        }
    }

    cout << count ;
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
            cout << endl;
    }
}