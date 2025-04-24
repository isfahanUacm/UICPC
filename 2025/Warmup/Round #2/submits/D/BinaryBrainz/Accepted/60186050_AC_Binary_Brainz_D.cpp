#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;

void solve()
{
    int n;
    cin >> n;
    ll *arr = new ll[n];


    int o = 1,e = 2;
    for(int i=0 ; i < n/2 ; i++){
        arr[i] = e;
        arr[n - i - 1] = o;
        e += 2;
        o += 2;
    }
    if(n % 2) arr[n/2] = n;

    for(int i =0 ; i < n ; i++)
        cout << arr[i]<<' ';
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