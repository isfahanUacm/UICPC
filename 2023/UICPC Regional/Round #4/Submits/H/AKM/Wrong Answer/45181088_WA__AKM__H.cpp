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
#define sz(x) ((int)(x).size())
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin(), x.rend()




void solve(){
    int c , n , a ;
    cin >> c >> n >> a ;
    set<int> s[n] ;
    int arr[a]  ;

    for(int i = 0 ; i<a ; i++){
        cin >> arr[i]  ;
        s[arr[i]].insert(i) ;
    }
    set<pii> ram ;
    set<pii> ram2 ;
    int ans= 0 ;
    int sz = 0 ;
    pii p ;
    for(int i=0 ; i<a ; i++){
        if(ram.find(mp(*s[arr[i]].begin() , arr[i]))!=ram.end()) {
            ram2.erase(ram2.find(mp(-*s[arr[i]].begin() , arr[i]))) ;
            ram.erase(ram.find(mp(*s[arr[i]].begin() , arr[i]))) ;
            s[arr[i]].erase(*s[arr[i]].begin()) ;
            if(s[arr[i]].size()){
                ram2.insert(mp(-*s[arr[i]].begin() , arr[i])) ;
                ram.insert(mp(*s[arr[i]].begin() , arr[i])) ;
            }
            else
                sz-- ; 
        }
        else{
            s[arr[i]].erase(*s[arr[i]].begin()) ;
            ans++ ;
            if(s[arr[i]].size()){
                ram.insert(mp(*s[arr[i]].begin() , arr[i])) ;
                ram2.insert(mp(-*s[arr[i]].begin() , arr[i])) ;
                sz++ ;
            }

            if(sz>c){
                p = *ram2.begin() ;
                ram2.erase(*ram2.begin()) ;
                p.first *= -1 ;
                ram.erase(*ram.find(p)) ;

                sz-- ;
            }
        }


    }

    cout << ans << nl ;
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
