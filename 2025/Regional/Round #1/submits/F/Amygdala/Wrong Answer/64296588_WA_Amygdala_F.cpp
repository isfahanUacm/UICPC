#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
const int mod = 1e9+7;

ll f(ll n)
{
    if(n <= 0) return 0;

    ll r1, r2, r3;
    ll otp1, otp2, otp3;

    ll n2 = n * n;
    ll rest = n % 10ull;
    ll full = (n - n%10ull) / 10ull;
    ll n2rest = n2 * rest;
    otp1 = n2*full + (n2rest - (n2rest%10ull))/10ull;
    r1 = n2rest % 10ull;
    otp1 *= 2; r1 *= 2;
//    cout << r1 << ' ' << otp1 << endl;

    otp2 = n * n * 3;
    r2 = otp2 % 10ull;
    otp2 -= r2;
    otp2 /= 10ull;
//    cout << r2 << ' ' << otp2 << endl;

    otp3 = 7 * n;
    r3 = otp3 % 10;
    otp3 -= r3;
    otp3 /= 10ull;
//    cout << r3 << ' ' << otp3 << endl;

    ll R = r1 + r2  + r3 - 2;
    R /= 10;

    return otp1 + otp2 + otp3 + R;
}

void solve(int t)
{
    ll k; cin >> k;

    ll mn=1ull, mx=1e6;
    ll last_ans;
    while(mx >= mn)
    {
        ll md = (mn + mx) / 2ull;

        ll res = f(md) + f(md-1);

        if(res > k)
        {
            mx = md - 1;
            last_ans = md;
        }
        else if(res < k)
        {
            mn = md + 1;
        }
        else
        {
            last_ans = md;
            break;
        }
    }

    ll full = (last_ans-1);
    ll result = full * full;
    ll sum = f(full) + f(full - 1);
//    for(ll i=1; i<=full+1; i++)
//    {
//        if(sum >= k) break;
//        sum += i;
//        result++;
//    }
//    for(ll i=full; i>=0; i--)
//    {
//        if(sum >= k) break;
//        sum += i;
//        result++;
//    }

    ll l=0, r = last_ans*2-1;
    while(r-l > 1){
        ll mid = (l+r)/2;
        ll res1, res2 = 0;
        if(mid>last_ans){
            res1 = (last_ans * (last_ans + 1))/2;
            ll a = 2*last_ans - mid - 1;
            res2 = ((last_ans)*(last_ans-1)) / 2 - (a * (a+1)) / 2;
        }
        else{
            res1 = (mid * (mid + 1))/2;
        }

        if(sum+res1+res2 >= k)
            r = mid;
        else
            l = mid;
    }
    cout << "Case " << t << ": " << result+r << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("army.in", "r", stdin);

    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        solve( i+1);
    }

//    cout << f(2);
//    for(int  i=1; i<10; i++) cout << f(i) << endl;

    return 0;
}