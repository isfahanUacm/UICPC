#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n;
    vector<double> p;
    cin >> n;
    for(ll i=0;i<n;i++){
        string g;
        double pi;
        cin >> g >> pi;
        p.push_back(pi);
    }
    sort(p.begin(),p.end());
    double ans = 0;
    for(ll i=0;i<n;i++){
        ans += p[i]*(n-i);
    }
    printf("%.4f\n",ans);
}