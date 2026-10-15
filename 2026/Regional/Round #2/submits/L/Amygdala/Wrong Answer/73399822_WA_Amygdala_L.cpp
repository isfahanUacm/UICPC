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

const int N=1e6+9;
int a[N] , w[N];
pInt p[N];

void solve()
{
    int n;
    cin >> n;
    multiset <int> s;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    for(int i=1 ; i<=n ; i++){
        cin >> w[i];
        p[i]={w[i] , i};
    }
    sort(p+1 , p+n+1);
    reverse(p+1 , p+n+1);
    int ans=0;
    for(int i=0 ; i<n ; i++){
        auto x =s.upper_bound(p[i].second);
        //cout << p[i].second << ' ' << p[i].first << endl;
        if(x==s.begin() && *x>p[i].second){
            x = (--s.end());
        }
        else{
            x--;
            //cout << p[i].first << ' ' << *x << endl;
            ans+=p[i].first;
        }
        s.erase(x);
            
    }
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}