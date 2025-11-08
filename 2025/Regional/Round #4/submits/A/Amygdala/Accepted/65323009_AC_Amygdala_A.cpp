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

const int N = 2e5+9;


void solve()
{
    int na , nb , nc , ha , hb , hc , s1 , s2;
    cin >> na >> nb >> nc >> ha >> hb >> hc >> s1 >> s2;
    na=max(0 , na-ha);
    nb=max(0 , nb-hb);
    nc=max(0 , nc-hc);
    int ans = na+nb+nc;
    if(s1 < na || s2 < nc){
        cout << -1 << endl;
    }
    else if(s1-na + s2-nc >= nb){
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }

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