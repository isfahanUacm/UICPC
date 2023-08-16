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
    vector<int> vect ;
    for(int i=1 ; i<=n ; i++){
        if(!mark[i]){
            vect.clear() ;
            ted = -1 ;
            vect.push_back(i) ;
            mark[i] = true ;
            full++ ;

            for(int j=1 ; j<graph[i].size() ; j++){
                int u = graph[i][j] ;
                if(!mark[u]){
                    mark[u] = true ;
                    full++ ;
                    vect.push_back(u) ;
                    ted = u ;
                    break;
                }
            }
            for(int j=1 ; j<=n ; j++){
                if(!mark[j]){
                for(int k=0 ; k<=vect.size() ; k++){
                    if(k==vect.size()){
                        mark[j] = true ;
                        full++ ;
                        cout << j << ' ' ;
                        for(int k=1 ; k<=n ; k++){
                        }


                    }
                    if(test[j][vect[k]])
                        break;
                }
                }

                if(full==n)
                    break;
            }
            for(int j=0; j<vect.size() ; j++)
                cout << vect[j] << ' ' ;
            cout << '\n' ;
        }
        if(full==n)
            break;
    }
    return 0 ;
}
