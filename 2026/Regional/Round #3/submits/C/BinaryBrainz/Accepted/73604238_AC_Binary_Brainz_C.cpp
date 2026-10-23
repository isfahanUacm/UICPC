#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<int , int> m;
    for (int i = 0; i < n; i++) {
        m[v[i]]++;
    }
    int cnt = 0;
    int mx = 0;
    int now = -1;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (now == -1) {
            now = it->first;
            cnt += it->second;
        }
        else {
            mx = max(mx , cnt);
            if (it->first == now + 1) {
                now ++;
                cnt += it->second;
            }
            else {
                now = it->first;
                cnt = it->second;
            }
        }
    }
    mx = max(mx , cnt);
    cout << n - mx;
}



int main() {

    int t=1;
    cin>>t;
    while(t--){
        solve();
        if (t)cout<<"\n";
    }

    return 0;
}