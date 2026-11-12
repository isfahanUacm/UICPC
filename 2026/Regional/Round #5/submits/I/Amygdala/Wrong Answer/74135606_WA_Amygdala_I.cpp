#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n)
#define sint(s) string (s); cin >> (s)
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n'
#define int ll
// #define endl '\n'

pair<int, int> E(int i, int n, int ai, pair<int, int> p)
{
    // pair<int, int> rev_p = p;
    // swap(rev_p.first, rev_p.second);
    int a = p.first;
    pair<int, int> otp = {1000*n - a*n, a};
    otp.first += i * otp.second;
    otp.first += ai * otp.second;
    return otp;
}

bool is_bigger(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first * p2.second > p1.second * p2.first;
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n); vin(a);
    vector<pair<int, int>> p(n);
    for(int i=0; i<n; i++)
    {
        double pi; cin >> pi;
        pi *= 1000;
        p[i] = {pi, 1000};
    }


    pInt mn = E(0, n, a[0], p[0]);
    for(int i=1; i<n; i++)
    {
        pInt res = E(i, n, a[i], p[i]);
        if(is_bigger(mn, res)) mn = res;
    }

    double up = mn.first, down = mn.second;
    cout << fixed << setprecision(9) << up / down << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}