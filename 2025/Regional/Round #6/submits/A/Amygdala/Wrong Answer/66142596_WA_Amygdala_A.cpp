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
#define pii pair<int, int>
#define F first
#define S second


void solve()
{
    int n; cin >> n;
    int xs, ys, xf, yf;
    cin >> xs >> ys >> xf >> yf;

    vector<pInt> shad(n);
    for(auto& it : shad)
    {
        int temp;
        cin >> temp >> it.second >> temp >> it.first;
    }
    std::sort(shad.rbegin(), shad.rend());

//    if(yf >= ys)
//    {
//        cout << "0.0";
//        return;
//    }

    int ans = 0;
    int y = ys;
    for(auto it : shad)
    {
        if(it.second >= y)continue;

        ans += max(y - it.first , 0);
        y = it.second;

        if(y <= yf) break;
    }
    ans += max(y-yf, 0);

    cout << ans << ".0";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
