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
    priority_queue<pii> s ;
    pii p ;
    pair<int,int> arr[n] ;


    FOR(i , 0 , n) cin >> arr[i].S ;
    FOR(i , 0 , n) cin >> arr[i].F;
    FOR(i , 0 , n){
        p = arr[i] ;
        if(p.F!=-1){
            s.push(p) ;

        }


    }
    vector<pii> vect ;
    while (s.size()) {
        vect.push_back(s.top()) ;
        s.pop() ;
    }
    ll ans = 0 ;
    reverse(vect.begin(), vect.end()) ;

    ll az = 0 ;
    ll sum = 0 ;
    ll maxi = 0 ;
    for(int i = 0 ; i<int(vect.size()) ; i++) {
        p  = vect[i] ;
        sum += p.S ;
        maxi = max(int(maxi) , p.F) ;
        az = sum / maxi ;
        if(sum % p.F != 0 )
            az++ ;
        ans = max(ans , az) ;
    }

    cout << ans << nl ;

}



int32_t main(){
    fastio() ;
    int t = 1 ;

    while (t--) {
        solve() ;
    }
    return 0 ;
}
