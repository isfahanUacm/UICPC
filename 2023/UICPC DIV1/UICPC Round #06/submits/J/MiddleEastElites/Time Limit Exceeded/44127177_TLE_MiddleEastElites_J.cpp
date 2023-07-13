//In the name of Alllah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll  ;

vector<int> graph[7*7*7 + 100] ;

int mar[7*7*7 + 100][7*7*7 + 100] ;

ll ans = 1e18 + 100 ;

pair<int,char> pp[7*7*7 + 100][7*7*7 + 100] ;

void Dij(int v , bool mark[7] , char c , ll vazn){


    if(c=='R')
        mark[0] = true ;
    else if(c=='O')
        mark[1] = true ;
    else if(c=='Y')
        mark[2] = true ;
    else if(c=='G')
        mark[3] = true ;
    else if(c=='B')
        mark[4] = true ;
    else if(c=='I')
        mark[5] = true ;
    else if(c=='V')
        mark[6] = true ;

    bool test = true ;

    for(int i = 0 ; i<7 ; i++){
        if(!mark[i]){
            test = false ;
            break;
        }
    }
    if(test){
        if(vazn<ans && v==1)
            ans = vazn ;
    }
    for(int u: graph[v]){
        if(mar[u][v]<2){
            mar[u][v] ++ ;
            mar[v][u]++ ;
            Dij(u,mark,pp[u][v].second,pp[u][v].first+ vazn) ;
            mar[u][v]-- ;
            mar[v][u]-- ;
        }
    }

    if(c=='R')
        mark[0] = false ;
    else if(c=='O')
        mark[1] = false ;
    else if(c=='Y')
        mark[2] = false ;
    else if(c=='G')
        mark[3] = false ;
    else if(c=='B')
        mark[4] = false ;
    else if(c=='I')
        mark[5] = false ;
    else if(c=='V')
        mark[6] = false ;

}

int main(void){
    ios_base::sync_with_stdio(false) ;
    bool mark[7] ;
    for(int i = 0 ; i<7 ; i++)
        mark[i] = false ;
    ll n, m  ;
    pair<int,char> tt;
    ll a , b , c ;
    char d ;
    cin >> n >> m ;
    for(int i = 0 ; i<m;  i++){
        cin >> a >> b >> c >> d  ;
        graph[a].push_back(b) ;
        graph[b].push_back(a) ;
        tt = make_pair(c,d) ;
        pp[a][b] = tt ;
        pp[b][a] = tt ;
    }

    Dij(1 , mark , 'Q' , 0) ;


    cout << ans << '\n' ;
    return  0 ;
}
