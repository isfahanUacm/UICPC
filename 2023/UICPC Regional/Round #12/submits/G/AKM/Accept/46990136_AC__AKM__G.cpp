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
    string str ;
    cin >> str ;

    int rank = 25 ;
    int star = 2 ;
    int cur = 0 ;
    int mot = 0 ;

    FOR(i , 0 , int(str.length())){
        if(str[i] == 'W'){
            mot++ ;
            cur ++ ;
            if(mot >=3 && rank>5)
                cur++ ;

            if(rank>20 && cur >2){
                rank -- ;
                cur -= 2 ;
            }
            else if(rank>15 && cur > 3){
                rank -- ;
                cur -= 3 ;
            }
            if(rank>10 && cur >4){
                rank -- ;
                cur -= 4 ;
            }
            if(cur > 5){
                rank -- ;
                cur -= 5 ;
            }
        }
        else{
            mot = 0 ;
            if(rank >20)
                continue;
            cur-- ;
            if(cur == -1 && rank>=20){
                cur = 0 ;
            }
            else if(cur == -1){
                rank++ ;
                if(rank>15)
                    cur = 2 ;
                else if(rank>10)
                    cur = 3 ;
                else
                    cur = 4 ;

            }

        }
        if(rank == 0){
            cout << "Legend" << nl ;
            return;
        }
    }

    cout << rank << nl ;
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
