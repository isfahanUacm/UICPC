#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';


void solve()
{
    ll a, b, c; cin >> a >> b >> c;
    string s; cin >> s;

    ll t = 2*a*b + 5*a*c;
    ll m = a*c;

    bool time=true, mem=true;

    int v1=5*1e8, v2=1e8, v3=2*1e7;

    if(s == "cpp")
        if(t > v1)
            time = false;
    if(s == "java")
        if(t > v2)
            time = false;
    if(s == "py")
        if(t > v3)
            time = false;

    if(m > v3) mem = false;

    if(!mem && !time) cout << "TL and ML";
    else if(!mem) cout << "ML";
    else if(!time) cout << "TL";
    else cout << "OK";
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