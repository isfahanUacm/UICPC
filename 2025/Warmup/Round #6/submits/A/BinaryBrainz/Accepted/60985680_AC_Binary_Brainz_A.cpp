#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
struct pairs{
    ll s;
    ll time;
    bool r;
};

bool operator < (const pairs& a,const pairs& b){
    if(a.s > b.s){
        return true;
    }
    else {
        if(a.s < b.s)
            return false;
        else {
            {
                if( a.time < b.time)
                    return true;
                else if (a.time > b.time)
                    return false;
                else return a.r;
            }
        }
    }
}



void solve() {
    ll n,m,h;
    cin>>n >> m>> h;

    vector<vector<ll>> t(n,vector<ll>(m));
    vector<pairs> p(n);
    int ind = 0;

    for(int i =0 ; i< n ; i++){
        for(int j =0 ; j< m ;j++){
            cin >> t[i][j];
        }
        sort(t[i].begin(),t[i].end());
        ll pnalty = 0;
        ll cnt = 0;
        ll lst =0;
        for(int j =0;j<m;j++){
            if(lst + t[i][j]> h){
                p[ind++] = {cnt,pnalty,false};
                break;
            }
            else {
                pnalty += lst + t[i][j];
                lst = lst + t[i][j];
                cnt++;
                if(j  == m-1){
                    p[ind++] = {cnt,pnalty,false};
                }
            }
        }

    }
    p[0].r = true;
    sort(p.begin(),p.end());

    for(int i =0;i<n;i++){
        if(p[i].r){
            cout << i+1;
            return;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin >> t;
    while (t--) {
        solve();
        if (t) cout << '\n';
    }
    return 0;
}
