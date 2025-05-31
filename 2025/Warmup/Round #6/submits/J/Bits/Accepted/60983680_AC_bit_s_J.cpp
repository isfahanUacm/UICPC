#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n ;
    cin >> n ;
    ll v = 0;
    for(int i = 0 ;i < n ;i ++)
    {

        int num ; cin >> num ;
        v += num ;
    }
    if(v % 2 == 0)
        cout << n << '\n';
    else
        cout << 0 << '\n';

//    ull r, k;
//    cin >> r >> k;
//
//    if(r < k-1)
//    {
//        cout << r << '\n';
//        return;
//    }
//
//    ull ans = k-1;
//    while(r >= ans*k)
//    {
//        ans *= k;
//        if(r<=ans+k-1)
//            break;
//        ans += k-1;
//    }
//    if(ans % k == 0)
//        ans += min(r, k-1);
//
//    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
    cin >> n;
    while(n--)
        solve();

    return 0;
}