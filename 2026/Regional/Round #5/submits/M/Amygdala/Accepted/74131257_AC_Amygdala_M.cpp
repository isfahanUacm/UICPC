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

double M(char ta, char td)
{
    if(ta=='F' && td=='G') return 2;
    if(ta=='G' && td=='W') return 2;
    if(ta=='W' && td=='F') return 2;
    return 0.5;
}

void solve()
{
    char ta, td;
    double p, h;
    cin >> ta >> td >> p >> h;

    h = h - p * M(ta, td);
    if(h <= 0) cout << "Nocaute!";
    else cout << "Sobraram " << h << " pontos de vida!";
    cout << endl;
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