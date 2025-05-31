#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, h;
        cin >> n >> m >> h;

        vector<pair<ll, ll>> scores; 
        for (ll i = 0; i < n; i++) {
            vector<ll> problems(m);
            for (ll j = 0; j < m; j++) {
                cin >> problems[j];
            }
            sort(problems.begin(), problems.end());
            ll solved = 0, penalty = 0, currentTime = 0;
            for (ll j = 0; j < m; j++) {
                if (currentTime + problems[j] <= h) {
                    currentTime += problems[j];
                    penalty += currentTime;
                    solved++;
                } else {
                    break;
                }
            }
            scores.push_back({solved, penalty});
        }
        auto rudolf = scores[0];
        sort(scores.begin(), scores.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        ll rank = 1;
        for (ll i = 0; i < n; i++) {
            if (scores[i] == rudolf) {
                cout << rank << endl;
                break;
            }
            rank++;
        }
    }
    return 0;
}
