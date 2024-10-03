#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[200000];
const ll INF = 1e9*4;
int main()
{
    ll n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int l = 0, h = n;
    bool f = true;
    ll ans = 0;
    ll g = INF;
    for(int i=1; i<n; i++){
        if(f && arr[i] - arr[i-1] < 0){
            f = false;
            g = arr[i-1]-arr[l];
            h = i-1;
        }
        if(!f && arr[i]-arr[i-1] >0){
            f = true;
            ans = max(ans,min(g, arr[h]-arr[i-1]));
            l = i-1;

        }
    }

    if(!f){
       ans = max(ans,min(g, arr[h]-arr[n-1]));
    }

    cout << ans << '\n';
    return 0;
}
