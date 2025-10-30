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

const int N = 200;
double a[N] , mx[N] , mn[N];
string s[N];


void solve()
{
    cint(n);
    cout << 1 << ' ' << n << endl;

    vecInt v(n);
    vin(v);
    vecInt pref_sum(n);
    v.push_back(-1);
    int p; cin >> p;
    int number_of_query = 0;

    while(p < 70 && number_of_query++ < 125)
    {
        int ps = 0;
        for(int i=0; i<n; i++)
        {
            if(v[i] == 0) ps += 25;
            else ps -= 75;

            pref_sum[i] = ps;
        }

        int mx1, mx2, mn1, mn2;
        int mx, mn;

        mx=n-1, mn=0;
        for(int i=0; i<n; i++)
            if(pref_sum[i] > pref_sum[mx]) mx = i;
        for(int i=mx; i>=0; i--)
            if(pref_sum[i] < pref_sum[mn]) mn = i;
        mx1 = mx, mn1 = mn;

        mx=n-1, mn=0;
        for(int i=0; i<n; i++)
            if(pref_sum[i] < pref_sum[mn]) mn = i;
        for(int i=mn; i<n; i++)
            if(pref_sum[i] > pref_sum[mx]) mx = i;
        mx2 = mx, mn2 = mn;

        if(pref_sum[mx1]-pref_sum[mn1] > pref_sum[mx2]-pref_sum[mn2])
            cout << mn1+1 << ' ' << mx1+1 << endl;
        else
            cout << mn2+1 << ' ' << mx2+1 << endl;

        for(int i=0; i<n; i++) cin >> v[i];
        cin >> p;
    }
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

//    for(int i=1; i<20; i++) cout << i << ':' << is_prime(i) << endl;
    return 0;
}
