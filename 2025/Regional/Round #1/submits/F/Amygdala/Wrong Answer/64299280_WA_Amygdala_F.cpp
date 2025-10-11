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
    if(n%3==0)
    {
        ll n1 = n/3;
        ll n2;
        if(n%2==0)
        {
            n1=n1/2ull;
            return n1 * (n+1) * (2*n+1ull);
        }
        else
        {
            n2 = (n+1) / 2ull;
            return n1 * n2 * (2*n+1ull);
        }
    }
    else if(n%3==1)
    {
        ll n3 = (2*n+1) / 3;
        ll n2;
        if(n%2==0)
        {
            return (n/2) * (n+1) * n3;
        }
        else
        {
            n2 = (n+1) / 2ull;
            return n * n2 * n3;
        }
    }
    else
    {
        ll n2 = (n+1) / 3;
        if(n%2==0)
        {
            return (n/2) * n2 * (2*n+1ull);
        }
        else
        {
            n2 /= 2;
            return n * n2 * (2*n+1ull);
        }
    }
}

ll triangle(ll n)
{
    if(n%2)
    {
        return n * ((n+1)/2ull);
    }
    else
    {
        return (n/2ull) * (n+1);
    }
}

ll f2(ll row, ll n)
{
    if(n <= row)
    {
        return triangle(n);
    }

    ll res1 = triangle(row);
    ll a = row * 2 - n + 1;
    ll res2 = res1 - triangle(a);
    return res1 + res2;
}


void solve(int t)
{
    ll k; cin >> k;

    ll mn=1ull, mx=2e6 + 8e5;
    ll last_ans;
    while(mx >= mn)
    {
        ll md = (mn + mx) / 2ull;

        ll res = f(md);

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
    ll sum = f(full);

//    ll l=0, r = last_ans*2-1;
//    while(r-l > 1){
//        ll mid = (l+r)/2;
//        ll res1, res2 = 0;
//        if(mid>last_ans){
//            res1 = (last_ans * (last_ans + 1))/2;
//            ll a = 2*last_ans - mid - 1;
//            res2 = ((last_ans)*(last_ans-1)) / 2 - (a * (a+1)) / 2;
//        }
//        else{
//            res1 = (mid * (mid + 1))/2;
//        }
//
//        if(sum+res1+res2 >= k)
//            r = mid;
//        else
//            l = mid;
//    }

    mn = 1, mx=last_ans*2 - 1;
    ll r;
    while(mx >= mn)
    {
        ll md = (mx + mn) / 2ull;
        ll rrr = f2(last_ans, md);

        if(sum + rrr > k)
        {
            mx = md - 1;
            r = md;
        }
        else if(sum + rrr < k)
        {
            mn = md + 1;
        }
        else
        {
            r = md;
            break;
        }
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

//    cout << f(2e6 + 8e5);
//    for(int  i=1; i<20; i++) cout << f(i) << endl;

    return 0;
}