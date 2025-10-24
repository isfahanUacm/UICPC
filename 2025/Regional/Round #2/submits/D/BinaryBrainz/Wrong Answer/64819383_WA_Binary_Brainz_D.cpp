#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>

void solve() {
   ll n , p , q;
    cin >> n >> p >> q;
    vector<pair<pair<ll , ll> , ll>> team(n);
    for (int i = 0; i < n; ++i) {
        team[i].second = i + 1;
    }
    vector<vector<ll>> att(n , vector<ll>(p , 0));
    vector<vector<ll>> solve(n , vector<ll>(p , 0));
    ll m , id , prob , t;
    while(q--){
        cin >> m >> id >> prob >> t;
        id--;
        prob--;
        if(solve[id][prob]){
            continue;
        }
        if(!t) {
            att[id][prob] ++;
        }
        else{
            team[id].first.first++;
            team[id].first.second += (ll)(m + (ll)(20 * att[id][prob]));
            solve[id][prob] = 1;
        }
    }
    std::sort(team.rbegin(), team.rend());
    ll rank = 1;
    for (int i = 0; i < n; ++i) {
        ll same = 0;
        ll index = i;
        while(index < n - 1){
            if(team[index].first.first == team[index + 1].first.first){
                same++;
                index++;
            }
            else{
                break;
            }
        }
        if(same){
            vector<pair<pair<ll , ll> , ll>> extra;
            for (int j = 0; j <= same ; ++j) {
                extra.emplace_back(team[i + j]);
            }
            sort(extra.begin(), extra.end());
            for (int j = 0; j <= same ; ++j) {
                cout << rank << " " << extra[j].second << " " << extra[j].first.first  << " " << extra[j].first.second << '\n';
            }
            rank += same + 1;
            i += same;
        }
        else{
            cout << rank << " " << team[i].second << " " << team[i].first.first  << " " << team[i].first.second << '\n';
            rank++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}