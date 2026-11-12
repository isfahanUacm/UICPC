#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    ll n , m;
    cin>>n>>m;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    int i = n - 1;
    ll sum = 0;
    vector<ll> ans(m);
    for(ll j=m ; j>=1 ; j--) {
        while(i >= 0 && v[i] >= j) {
            sum += v[i--];
        }
        ans[j - 1] = sum;
    }
    for(int j = 0 ; j < m; j++) {
        cout<<ans[j]<<" ";
    }
    return 0;
}