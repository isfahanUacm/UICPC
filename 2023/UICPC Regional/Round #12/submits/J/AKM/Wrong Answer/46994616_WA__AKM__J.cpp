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
    ll n , p ;
    cin >> n >> p ;

    double ans = 0 ;

    ll tp = min(p-1 , n-(p-1)) , tn = n;
    ll val =1 ;
    ll mine = 2 ;
    ll val2= 1 , val3 ;
    while (tp--) {
        val *= tn ;
        tn-- ;
    }
    tp = min(p-1 , n-(p-1)) ;
    while (tp--) {
        val /= tp+1 ;
    }
    val3 = val ;
    n++ ;
    val3 *= n ;
    val3 /= p ;
    ans = double(val) * double(val2) / double(val3) ;
    double temp = val*n/p  ;
    while(true) {
        n++ ;
        val2 = mine ;
        val3 *= n ;
        val3 /= n - p  ;
        temp = double(val) * double(val2) / double(val3)  ;
        mine++ ;

        if(ans < temp)
            ans = temp ;
        else
            break;
    }

    printf("%.7f", ans) ;
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
