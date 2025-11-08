#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back

const int N = 2e5+9;


void solve()
{
    cint(n);
    vector<ll> v(n), vi(n);
    vin(vi) vin(v);
    std::sort(v.rbegin(), v.rend());

    ll sum = 0;
    long double res = 0;
    for(int i=0; i<n; i++)
    {
        sum += v[i];
//        cout << sum << endl;

        ll temp = sum + vi[i];
        long double ans = temp / (long double)(i+1);
        res = max(res, ans);
    }

    cout << fixed << setprecision(6) << res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}