#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> d(n+2),e(n+2);
    d[0] = 0;
    d[n+1] = 0;
    e[0] = 0;
    e[n+1] = 0;

    vector<set<int>> connect(n+1);
    for(int i=1;i<=n;i++){
        cin >>d[i];
    }
    for(int i=1;i<=n;i++){
        cin >>e[i];
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin >>l >> r;

        connect[l].insert(r);
        connect[r].insert(l);
    }
    for(int i=0;i<q;i++) {
        string cmd, o;
        cin >> cmd;

        if (cmd == "check") {
            int l;
            cin >> l;

            ll desk = d[l];
            for(auto & itr : connect[l]){
                desk += d[itr];
            }

            ll mons = e[l];
            for(auto & itr : connect[l]){
                mons += e[itr];
            }

            cout << ((desk > mons) ? "desks" : desk == mons ? "same" : "monitors");
            if(i!=q-1)cout<< '\n';
        }
        else {
            string s;
            int l,c;
            cin >> c >> s >> l;
            if(s == "monitor"){
                e[l] += c;
            }
            else{
                d[l] += c;
            }
        }
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        if(t!=0)
            cout<<endl;
    }
}
