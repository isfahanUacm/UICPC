//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;

const int maxn = 1e5 + 10 ;

vector<int> graph[maxn] ;
bool mark[maxn] ;


int main(void){
    ios_base::sync_with_stdio(false) ;
    int n , m ;
    int u , v ;
    cin >> n >> m ;
    bool test[n+1][n+1] ;
    for(int i =1 ; i<=n ; i++)
        graph[i].push_back(i) ;
    for(int i = 0 ; i<m ; i++){
        cin >> u >> v ;
        test[u][v] = true ;
        test[v][u] = true ;
        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }

    ll ans = 0 ;
    for(int i = 1 ; i<=n; i++)
        if(ans<graph[i].size())
            ans = graph[i].size() ;

    cout << int(ans+1)/2 << '\n' ;

    int full = 0 ;
    int ted = 0 ;
    for(int i=1 ; i<=n ; i++){
        if(!mark[i]){
            ted = -1 ;
            cout << i << ' ' ;
            mark[i] = true ;
            full++ ;

            for(int j=1 ; j<graph[i].size() ; j++){
                int u = graph[i][j] ;
                if(!mark[u]){
                    mark[u] = true ;
                    full++ ;
                    cout << u << ' ' ;
                    ted = u ;
                    break;
                }
            }
            for(int j=1 ; j<=n ; j++){
                if(!mark[j] && !test[i][j] && (ted==-1 || !test[ted][j])){
                    mark[j] = true ;
                    full++ ;
                    cout << j << ' ' ;
                }

                if(full==n)
                    break;
            }
            cout << '\n' ;
        }
        if(full==n)
            break;
    }
    return 0 ;
}
