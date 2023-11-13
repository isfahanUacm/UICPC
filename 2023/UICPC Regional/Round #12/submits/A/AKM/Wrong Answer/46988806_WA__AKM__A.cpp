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
    int n ;
    cin >> n ;
    ll arr[n] ;

    FOR(i , 0 , n) cin >> arr[i] ;

    ll mon = 100 ;
    ll ted = 0 ;
    FOR(i , 0 , n){
        if(arr[i] <= mon && i<n-1 && arr[i] <= arr[i+1]){
            ted += mon / arr[i] ;
            mon = mon % arr[i] ;
        }
        else{
            mon += arr[i] * ted ;
            ted = 0 ;
        }
    }

    cout << mon << nl ;
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
