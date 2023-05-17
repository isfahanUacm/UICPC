///In he nme of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;

int main()
{
    ios_base::sync_with_stdio(false) ;
    ll n;
    cin >> n ;
    ll arr[n] ;
    for(int i=0 ; i<n ; i++)
        cin >> arr[i] ;
    ll sum1 =0 , sum2 = arr[n-1] ;
    ll answer = 0 ;
    for(int i=0 ; i<n-1 ; i++){
        sum1 += pow(arr[i],2) ;
    }
    answer = sum1  * sum2 ;
    for(int j=n-2 ; j>0 ; j--){
        sum1 -= pow(arr[j] , 2) ;
        sum2 += arr[j] ;
        answer = max(answer , (sum1*sum2)) ;
    }
    cout << answer << '\n' ;
    return 0;
}
