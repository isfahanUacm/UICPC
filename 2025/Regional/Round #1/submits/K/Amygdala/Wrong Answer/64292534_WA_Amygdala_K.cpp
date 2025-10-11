#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
const int mod = 1e9+7;

bool mark[105][105];
int g[105][105];

void solve(int t)
{
    cint(n);
    vecInt v(n);
    vin(v);
    std::sort(v.rbegin(), v.rend());

    int p1=0, p2=n-1;
    bool right = true;
    vecInt ans(n, 0);
    for(auto x : v)
    {
        if(right)
        {
            right = false;
            ans[p2--] = x;
        }
        else
        {
            right = true;
            ans[p1++] = x;
        }
    }

    cout <<"Case " << t << " :\n";
    vout(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cubes.in", "r", stdin);

    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        solve( i+1);
    }

//    cout << generate('d', 5, 31, 12);

    return 0;
}