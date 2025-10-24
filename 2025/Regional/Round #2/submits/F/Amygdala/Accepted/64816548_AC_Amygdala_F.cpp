#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';

string bin_str(ll a)
{
    string otp;
    while(a)
    {
        otp.push_back('0' + (a % 2));
        a /= 2;
    }
    return otp;
}

int f(int a)
{
    if(a <= 31) return 32;
    else if(a <= 63) return 64;
    else return 128;
}

void solve()
{
    ll n,t; cin >> n >> t;
    ll sum = 0;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum <= t){
        cout << 1<< '\n';
        return;
    }
    ll l = 1, r = 1e12;
    while(r-l > 1){
        sum = 0;
        ll mid = ((r+l)/2);
        for(int i=0; i<n; i++){
            ll c = (a[i]+mid-1)/mid;
            sum += c;
        }
        if(sum > t)
            l = mid;
        else
            r = mid;
    }
    cout << r << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<20; i++) cout << i << ':' << is_prime(i) << endl;
    return 0;
}