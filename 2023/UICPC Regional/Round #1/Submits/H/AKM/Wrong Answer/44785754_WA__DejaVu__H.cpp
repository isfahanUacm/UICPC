//In the name of Allah
#include <iostream>

using namespace std;

typedef long long int ll ;

int main()
{
    ios_base::sync_with_stdio(false) ;
    int n  ;
    cin >> n  ;
    int arr[n] ;
    ll sum = 0 ;
    for(int i = 0 ; i<n;  i++){
        cin >> arr[i] ;
        if(sum==i && arr[i]==0)
            sum++ ;
        sum += arr[i] ;
    }


    ll sum2 = 0 ;
    while (sum2+n*arr[n-1]<=sum-arr[n-1]+1) {
        sum -= arr[n-1] ;
        sum2 += n*arr[n-1] ;
        n-- ;
        if(n==0)
            break;
    }
    sum ++ ;
    if(n!=0){
    ll len = (sum - sum2)/ n ;
    sum -= len ;}
    if(sum>12)
        cout << "impossible" << '\n' ;
    else
        cout << sum << '\n' ;
    return 0;
}
