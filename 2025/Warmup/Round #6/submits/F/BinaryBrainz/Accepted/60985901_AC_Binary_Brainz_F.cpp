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
    ll a,b;
    cin>>a>>b;
    cout<<a-((a-b)/2)<<' '<<((a-b)/2);
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
