#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n, t, k, d;
    cin >> n >> t >> k >> d ;
    int a = 2 * k;
    int cnt = n / a;
    if(a*cnt != n)
        cnt++;
    ll sum = d +  cnt *1LL* t;
    cnt = n / k;
    if(k * cnt != n)
        cnt++;
    ll sum2 = cnt *1LL* t;
    if(d < sum2 && sum >= sum2){
        ll num = d + (sum2-d)/2 + ((sum2-d) % 2) * t;
        sum = min(sum, num);
        ll f = d / t;
        if(t*f != d)
            f++;
        if((n - (f*k)) <= k){
            cout << "NO\n";
            return;
        }
    }

    if(sum < sum2)
        cout << "YES\n";
    else
        cout << "NO\n";
//    ull r, k;
//    cin >> r >> k;
//)
//    int lg = 0;
//    ull r_cpy;
//
//    vector<ull> kn;
//
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