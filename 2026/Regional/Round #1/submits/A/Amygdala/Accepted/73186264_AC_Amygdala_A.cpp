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
#define endl '\n'
#define F first
#define S second

const int N = 1e3+9;
int f[N][N];
bool ac[N][N];
int pen[N][N];
pair <pInt , int> pr[N];

bool cmp(pair <pInt , int> a , pair <pInt , int> b){
    if(a.F.F > b.F.F){
        return 1;
    }
    if(a.F.F < b.F.F){
        return 0;
    }
    if(a.F.S > b.F.S){
        return 0;
    }
    if(a.F.S < b.F.S){
        return 1;
    }
    return (a.S < b.S);

}

void solve()
{
    int n , p;
    cin >> n >> p;
    int q;
    cin >> q;
    while(q--){
        int m , id , t , v;
        cin >> m >> id >> t >> v;
        id--;
        t--;
        if(v==0){
            f[id][t]++;
        }
        else{
            if(ac[id][t]){
                continue;
            }
            pen[id][t]=m+20*f[id][t];
            ac[id][t]=1;
        }
    }
    for(int i=0 ; i<n ; i++){
        int f=0 , s=0;
        for(int j=0 ; j<p ; j++){
            f+=ac[i][j];
            s+=pen[i][j];
        }
        pr[i]={{f , s} , i};
    }
    sort(pr , pr+n , cmp);
    int cnt=1;
    cout << cnt << ' ' << pr[0].S+1 << ' ' << pr[0].F.F << ' ' << pr[0].F.S << endl;
    for(int i=1 ; i<n ; i++){
        if(pr[i].F != pr[i-1].F){
            cnt = i+1;
        }

        cout << cnt << ' ' << pr[i].S+1 << ' ' << pr[i].F.F << ' ' << pr[i].F.S << endl;
    }
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