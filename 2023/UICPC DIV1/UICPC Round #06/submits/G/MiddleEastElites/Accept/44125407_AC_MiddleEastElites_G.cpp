//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;

int main(void){
    ios_base::sync_with_stdio(false) ;

    ll a , b , tem ;
    cin >> a >> b ;
    ll ans = a*(a+1)/2 ;
    priority_queue<ll> vect ;
    for(int i = 0 ; i<b;  i++){
        cin >> tem ;
        vect.push(tem) ;
    }

    ll arr[b] ;
    for(int i = b-1 ; i>=0 ; i--){
        arr[i] = vect.top() ;
        vect.pop() ;
    }
    if(b!=0){
        ans -= (arr[0]-1)*(arr[0])/2 ;
    ans -= (a-arr[b-1])*(a-arr[b-1]+1)/2 ;
    }

    for(int i=1 ; i<b ; i++)
        ans -= (arr[i]-arr[i-1]-1)*(arr[i]-arr[i-1])/2 ;
    if(b==0)
        ans = 0 ;
    cout << ans ;
}

