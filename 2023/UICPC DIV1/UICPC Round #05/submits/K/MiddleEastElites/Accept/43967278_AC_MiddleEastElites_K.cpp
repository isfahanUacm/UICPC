//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;



int main(void){

    int  m ,n ;
    cin >> n >> m ;
    int arr[n] ;
    int arr2[m] ;

    for(int i = 0 ; i<n ; i++)
        cin >> arr[i] ;

    for(int i = 0 ; i<m ; i++)
        cin >> arr2[i] ;

    sort(arr,arr+n) ;
    sort(arr2,arr2+m) ;


    int ans = 0 ;
    int in = 0 ;
    for(int i= 0 ; i<n ; i++){
        if(in>=m)
            break;
        if(arr[i]<=arr2[in]){
            in++ ;
            ans++ ;
        }
        else{
            i-- ;
            in++ ;
        }

    }

    cout << ans << '\n' ;
    return 0 ;
}
