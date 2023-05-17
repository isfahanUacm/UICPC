///In he nme of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;

int main()
{

    ll m , n ;
    cin >> m >> n ;
    ll arr1[m] ;
    ll arr2[n] ;
    ll ma1 = 0 ;
    ll ma2 = 0 ;
    for(int i=0 ; i<m ; i++){
        cin >> arr1[i] ;
        ma1 = max(arr1[i] , ma1) ;
    }
    for(int i=0 ; i<n ; i++){
        cin >> arr2[i] ;
        ma2 = max(arr2[i] , ma2) ;
    }
    if(ma1==ma2)
        cout << "possible" ;
    else
        cout << "impossible" ;
    return 0;
}
