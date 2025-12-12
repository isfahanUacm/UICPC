#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
//#define int ll

bool flag = true;

ll f(ll d)
{
    ll p = 1;
    int sign = 1;

    while(d-p > 0)
    {
        d -= p;
        if(d-p < 0)
        {
            flag = false;
            return (p-d) * sign;
        }

        d -= p;

        sign *= -1;
        p *= 2;
    }

    if(d < 0)
    {
        flag = false;
        return (-d) * sign;
    }

    if(d <= p/4)
    {
        flag = false;
    }

    return (d) * sign;
}

void solve()
{
    ll d, y;
    cin >> d >> y;

    ll y2 = f(d);

    if(!flag)
    {
        cout << "Nao";
        return;
    }

    cout << "Sim\n";
    cout << y - y2;
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<20; i++) cout << i << ": " << f(i) << endl;

    return 0;
}
