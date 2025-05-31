#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    ll n, t, k, d;
    cin >> n >> t >> k >> d ;
    int cnt = n / k;
    if(k * cnt != n)
        cnt++;
    ll sum2 = cnt *1LL* t;
    ll a = 2 * k;
    cnt = n / a;
    if(a * cnt != n)
        cnt++;
    ll sum = d + cnt * t;
    a = d / t;
    if (t*a != d)
        a++;
    n -= a*k;
    ll sum1 = a * t;
    a = k * 2;
    cnt = n / a;
    if(cnt*a != n)
        cnt++;
    sum1 += cnt * 1LL * t;
    sum = min(sum, sum1);
    if(sum < sum2)
        cout << "YES\n";
    else
        cout << "NO\n";

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