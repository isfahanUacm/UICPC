#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define vi vector <int>
#define all(x) x.begin(),x.end()

const int N = 1e6+9 , INF = 1e18 , mod=1006903069;


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    //cin >> T;
    while(T--) {
        int n; cin >> n;
        int sa; cin >> sa;
        vector<pair<int,int>> pa(sa);
        vector<int> a(sa);
        map<int,int> ma, mb;
        for(int i=0; i<sa; i++) {
            cin >> pa[i].first >> pa[i].second >> a[i];
            pa[i].first--; pa[i].second--;
            ma[pa[i].first*n+pa[i].second] = a[i]%mod;

        }
        int sb; cin >> sb;
        vector<pair<int,int>> pb(sb);
        vector<int> b(sb);
        for(int i=0; i<sb; i++) {
            cin >> pb[i].first >> pb[i].second >> b[i];
            pb[i].first--; pb[i].second--;
            mb[pb[i].second*n+pb[i].first] = b[i]%mod;
        }
        int sum = 0;
        for(pair<int,int> p : mb){
            if(ma[p.first] != 0){
                sum += (p.second * ma[p.first])%mod;
                sum %= mod;
            }
        }
        cout << sum << '\n';
    }

}