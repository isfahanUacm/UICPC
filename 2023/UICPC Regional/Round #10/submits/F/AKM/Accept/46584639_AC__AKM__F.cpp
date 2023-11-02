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
    int n;
    cin >> n ;
    ll sa = 0 , sb = 0 ;
    pair<int, int> ps[n] ;

    map<pii, int> mpp ;
    FOR(i , 0 , n){
        cin >> ps[i].F >> ps[i].S ;
        sa += ps[i].F ;
        sb += ps[i].S ;

    }

    if(n % 2 == 1 || sa % (n/2) != 0 || sb % (n/2) != 0 ){
        cout << "impossible" << nl ;
        return;
    }

    sa /= n/2 ;
    sb /= n/2 ;

    multiset<pii> s ;

    FOR(i , 0 , n){
        s.insert(ps[i]) ;

    }

    pii t1 , t2 ;
    while (s.size()) {
        t1 = {- 1e9 , -1e9} ;
        t2 = *--s.end() ;

            s.erase(--s.end()) ;


        for(auto u : s){
            if(u.F + t2.F == sa && u.S + t2.S == sb){
                t1 = u ;
                break;
            }
            else{
                if(u.F + t2.F != sa){
                    cout << "impossible" << nl ;
                    return;
                }

            }
        }

        if(t1.F == -1e9){
            cout << "impossible" << nl ;
            return;
        }
            s.erase(s.find(t1)) ;


    }


    cout << "possible" << nl ;
    return;



}



int32_t main(){
    fastio() ;
    int t = 1 ;

    while (t--) {
        solve() ;
    }
    return 0 ;
}

