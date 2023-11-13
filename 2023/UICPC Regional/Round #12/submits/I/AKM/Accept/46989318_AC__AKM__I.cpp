//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

#define fastio() ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
#define MOD 1000000007
#define MOD1 998244353
#define LL_INF 1e18 + 100
#define INT_INF 1e9 + 100
#define MAXN int(1e5 + 100)
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pil pair<ll,ll>
#define pid pair<double,double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define pf push_front
#define nl '\n'
#define FOR(i ,a ,b) for(int i = (a) ; i<(b) ; i++)
#define sz(x) ((int)(x).size())
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin(), x.rend()


void solve(){
    int n , m ;
    cin >> n >> m ;

    int tm = m + 360 ;
    int tm2 = m - 360 ;



    int ans = min(abs(n-m) , min(abs(n-tm) , abs(n-tm2))) ;

    if(ans == 180){
        cout << ans << nl ;
        return;
    }

    if(ans == abs(n-m)){
        cout << m - n ;

    }
    else if(ans == abs(n-tm)){
        cout << tm -n ;
    }
    else{
        cout << tm2 - n ;
    }
    cout << nl ;
}




int32_t main(){

    fastio() ;
    int t = 1 ;
  //  cin >> t ;
    while (t--) {
        solve() ;
    }
    return 0 ;
}
