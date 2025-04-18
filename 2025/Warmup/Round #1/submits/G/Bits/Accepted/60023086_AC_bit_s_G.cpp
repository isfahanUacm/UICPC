#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int w, n; cin >> w >> n;
    vector<pair<pair<int,int>,int>> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].first.second >> v[i].first.first;
        v[i].second = i+1;
    }
    sort(v.begin(),v.end());
    priority_queue<pair<int,int>> pq;
    int ind = 0;
    int amount = 0;
    vector<int> rs;
    while(amount < w){
        while(v[ind].first.first <= amount && ind < n) {
            pq.push({v[ind].first.second, v[ind].second});
            ind++;
        }
        if(pq.empty()){
            cout << "-1\n";
            return;
        }
        rs.push_back(pq.top().second);
        amount += pq.top().first;
        pq.pop();
    }
    cout << rs.size() << '\n';
    for(int a : rs)
        cout << a << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
//    cin >> n;
    while(n--)
        solve();

    return 0;
}