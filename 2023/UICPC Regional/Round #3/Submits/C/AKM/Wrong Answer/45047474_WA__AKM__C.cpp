//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;



int main(void){
    ios_base::sync_with_stdio(false) ;

    int t , n ;
    vector<int> vect[30] ;
    double point[30] ;
    double poi[30] ;
    char arr[30][30] ;
    vector<int> ans ;
    set<pair<double,int>> s ;
    double mp , p ;
    set<pair<int,int>> temp ;
   bool mark[30] ;
    int in ;
    cin >> t ;
    vector<int> az ;
    while (t--) {
        cin >> n ;
        for(int i  = 0 ; i<n;  i++){
            vect[i].clear() ;
            mark[i] = false ;
            point[i] = 0 ;
            for(int j = 0 ; j<n;  j++)
                cin >> arr[i][j] ;
        }

        for(int i = 0 ; i<n;  i++)
            for(int j = 0 ; j<n ; j++){
                if(arr[i][j]=='1')
                    point[i]++ ;
                else if(arr[i][j]=='d')
                    point[i] += 0.5 ;
                else if(arr[i][j]=='.')
                    vect[i].push_back(j) ;

            }



        for(int i=0 ; i<n;  i++){
            s.insert(make_pair(-point[i] , i)) ;
            if(point[i]>mp)
                mp = point[i] ;
        }

        for(int i = 0 ; i<n;  i++)
            poi[i] = point[i] ;


        while (s.size()) {
            p = -s.begin()->first ;
            in = s.begin()->second ;
            if(mark[in]){
                s.erase(*s.begin()) ;
                continue;
            }
            for(auto u : vect[in]){
                if(arr[u][in]=='0' || arr[u][in]=='1' || arr[u][in]=='d')
                    continue;
                
                if(p>point[u]){
                    point[u] += 1 ;
                    if(!mark[u])
                        az.push_back(u) ;
                    arr[u][in] = '1' ;
                }
                else if(p==point[u]){
                    p+= 0.5 ;
                    point[u] += 0.5 ;
                    arr[u][in] = 'd' ;
                    if(!mark[u])
                        az.push_back(u) ;

                }
                else{
                    arr[u][in] = '0' ;
                    p += 1 ;
                }
            }

            if(mp<p)
                mp = p ;
            mark[in] = true ;

            s.erase(*s.begin()) ;
            for(int u : az)
                s.insert(make_pair(-point[u] , u )) ;
            az.clear() ;

        }
        ans.clear() ;
        for(int i = 0 ; i<n;  i++)
            if(poi[i] + vect[i].size() >=mp)
                ans.push_back(i+1) ;


        for(int u : ans)
            cout << u << ' ' ;
        cout << '\n' ;
    }

    return 0 ;
}
