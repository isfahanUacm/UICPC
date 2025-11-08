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
    int n, k; cin >> n >> k;
    vector<ll> v(n); vin(v); std::sort(v.begin(), v.end());
    int s=0, f=n;
    ll sum = 0;
    loop(n, i) sum += v[i];

    while(f-s > k)
    {
        long double mean = sum / (long double)(f-s);

        long double s_dist, f_dist;
        s_dist = mean - v[s];
        f_dist = v[f-1] - mean;

        if(s_dist > f_dist)
        {
            sum -= v[s];
            s ++;
        }
        else
        {
            sum -= v[f-1];
            f --;
        }
    }

    n = f-s;
    long double mean = sum / (long double)n;
    long double ans = 0;
    for(int i=s; i<f; i++)
    {
        long double temp = mean - v[i];
        ans += temp * temp;
    }

    cout << fixed << setprecision(6) << ans;
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