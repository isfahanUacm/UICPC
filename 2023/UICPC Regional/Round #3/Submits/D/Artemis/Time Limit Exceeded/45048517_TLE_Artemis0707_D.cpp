#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll cal_sum(ll dp[], ll num ){
    if(num<10)
        return (num*(num+1)/2);
    ll n = ll(log10(num));
    ll pw = ceil(pow(10,n));
    ll last_dg = num/pw;
    ll sum =last_dg*(last_dg-1)/2 * pw + last_dg *(1+ num % pw) +(last_dg)*dp[n] ;
    sum+= cal_sum(dp, num%pw);
    return sum;

}

int main(){
    string x,y;
    ll t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a >> b;
        ll n = ll(log10(b))+1;
        ll dp[n+1];
        fill(dp,dp+n+1, 0);
        dp[1] = 45;
        for(ll i=2;i<=n;i++){
            dp[i] = dp[i-1]*10 + 45*pow(10,i-1);
        }
        ll suma =0;
        if(a != 0) suma = cal_sum(dp, a-1);
        ll sumb = cal_sum(dp, b);
        cout<< sumb-suma<<endl;
    }
    

    return 0;
}