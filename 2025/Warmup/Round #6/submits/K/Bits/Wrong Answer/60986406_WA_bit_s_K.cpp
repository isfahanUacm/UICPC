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
    ll sum = 0;

    bool flag = false;
    int i;
    for(i=1; i<=sum2; i++)
    {
        if(i%t == 0)
        {
            n -= k;
        }
        if(n<0) break;
        if(i%t == d%t && flag)
        {
            n -= k;
        }
        if(n<0) break;
        if(i == d)
        {
            n -= k;
            flag = true;
        }
        if(n<0) break;
    }
    cout << (i < sum2 ? "YES\n" : "NO\n");
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