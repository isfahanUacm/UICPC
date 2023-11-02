#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p;
    cin>>n>>p;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int mn = arr[0],ans=0;

    for(int i=n-1;i>=0;i--){
        if(arr[i] >= p*i) continue;
        ans = max(ans,p*(i+1) - (arr[i]- arr[0]));
    }
    if(arr[0] <=p) ans = max(ans,p);
    cout<<ans<<endl;
    return 0;
}