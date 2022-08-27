#include<bits/stdc++.h>
#define LL  long long  ;
using namespace std ;

int a[5005] ;
int siz[5005][5005] ;
vector<int> v [5005] ;
int f[5005][5005] ;
int g [5005][5005] ;
int main ()
{
    int n , k , s ;
    cin >> n >> k >> s ;
    for ( int i = 0 ; i < n ; i ++)
    {
        cin >> a[i] ;
        if (siz[i%k+1][a[i]] == 0)
        {
            v[i%k+1].push_back(a[i]);

        }
        siz[i%k+1][a[i]] ++ ;
    }
    for ( int i = 1 ; i <=s ; i ++)
    {
        f[0][i] -=1<<30 ;
    }
    f[0][0] = 0 ;
    for ( int i = 1 ; i <= k ; i ++)
    {
        for ( int j = 0 ; j <=s ; j ++)
        {
            g[i][j] = g[i-1][j] ;
        }
        for ( int j = 0 ; j <s ; j ++)
        {
            g[i][j] = max(j?g[i][j-1] : 0 , f[i-1][j]) ;

        }
        for ( int j = 0 ; j <s ; j ++)
        {
            for ( int k = 0 ; k <v[i].size() ; k++)
            {
                if ( j>= v[i][k])
                {
                    f[i][j] = max (f[i][j]  , f[i-1][j-v[i][k]]+siz[i][v[i][k]]);

                }
                else {
                    f[i][j] = max (f[i][j] , f[i-1][j]) ;
                }
            }
        }

    for ( int j = 0 ; j <=s ; j++)
    {
        f[i][j] = max (f[i][j] , g[i][j]) ;

    }
    }
    cout << n-f[k][s] << endl;
    
    return 0 ;
}
