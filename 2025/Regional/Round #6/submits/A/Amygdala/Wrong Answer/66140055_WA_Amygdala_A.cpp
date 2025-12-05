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

struct dot{
    int x,y;
};

bool comp(pair<dot,dot> a, pair<dot,dot> b){
    return a.second.y > b.second.y;
}
void solve()
{
    int n, a, b, c, d;  cin >> n >> a >> b >> c >> d;
    vector<pair<dot,dot>> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i].first.x >> v[i].first.y >> v[i].second.x >> v[i].second.y;
    sort(v.begin(),v.end(),comp);

    if(b <= d){
        cout << fixed << setprecision(1) << 0.0 << '\n';
        return;
    }
    double ans = 0.0;
    for(int i=0; i<n; i++){
//        cout << v[i].second.y << " " << v[i].first.y << '\n';
        if(v[i].first.y > b)
            continue;
        ans += max(b-v[i].second.y, 0);
        b = v[i].first.y;
        if(b <= d)
            break;


    }
    if(b > d){
        ans += b - d;
    }
    cout << fixed << setprecision(1) << ans << '\n';
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
