#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>

void solve() {
    int n , p , q;
    cin >> n >> p >> q;
    vector<pair<pair<int , ll> , int>> team(n);
    for (int i = 0; i < n; ++i) {
        team[i].second = i + 1;
    }
    vector<vector<int>> att(n , vector<int>(p , 0));
    int m , id , prob , t;
    while(q--){
        cin >> m >> id >> prob >> t;
        id--;
        prob--;
        if(!t) {
            att[id][prob] ++;
        }
        else{
            team[id].first.first++;
            team[id].first.second += (ll)(m + (ll)(20 * att[id][prob]));
        }
    }
    std::sort(team.rbegin(), team.rend());
    int rank = 1;
    for (int i = 0; i < n; ++i) {
        int same = 0;
        int index = i;
        while(index < n - 1){
            if((team[index].first.first == team[index + 1].first.first)
               && (team[index].first.second == team[index + 1].first.second)){
                same++;
                index++;
            }
            else{
                break;
            }
        }
        if(same){
            vector<pair<pair<int , ll> , int>> extra;
            for (int j = 0; j <= same ; ++j) {
                extra.push_back(team[i + j]);
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