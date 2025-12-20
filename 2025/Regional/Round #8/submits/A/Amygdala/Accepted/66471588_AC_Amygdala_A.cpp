#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define int ll



void solve()
{
    ll n , m;;
    while(1)
    {
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        int ans = (m/7)*2+(m%7==6);
        set<int> s;
        for(int i=0 ; i<n ; i++){
            int a;
            cin >> a;
            a--;
            if(a%7!=6 && a%7!=5 && a<m){
                s.insert(a);
            }
        }
        cout << m-(s.size() + ans) << endl;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<10; i++) cout << f(i, i) << endl;

    return 0;
}