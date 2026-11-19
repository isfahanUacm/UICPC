#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    ll r, c;
    cin >> r >> c;

    string a[r];
    string b[r];

    using ss  = std::array<ll, 4>;
    using T = pair<ll,ss>;

    ss s = {-1,-1,-1,-1};

    ll di = -1;
    ll dj = -1;

    for (int i = 0 ;i<r;i++) {
        cin >> a[i];
        if (s[0] == -1) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] == 'S') {
                    s[0] = i;
                    s[1] = j;
                }
            }
        }
    }

    for (int i = 0 ;i<r;i++) {
        cin >> b[i];
        if (s[2] == -1 || di == -1) {
            for (int j = 0; j < c; j++) {
                if (b[i][j] == 'S') {
                    s[2] = i;
                    s[3] = j;
                }
                else if (b[i][j] == 'D') {
                    di = i;
                    dj = j;
                }
            }
        }
    }


    queue<T> pq;
    pq.push({0,s});
    // set<ss> visit;
    vector<vector<set<pair<ll,ll>>>> vis(r, vector<set<pair<ll,ll>>>(c));

    auto valida = [&](ll ii, ll jj) {
        bool c1 = (ii < r) && (ii >= 0);
        bool c2 = (jj < c) && (jj >= 0);
        if (c1 && c2) {
            return a[ii][jj] != 'X';
        }
        return false;
    };

    auto validb = [&](ll ii, ll jj) {
        bool c1 = (ii < r) && (ii >= 0);
        bool c2 = (jj < c) && (jj >= 0);
        if ( c1 && c2 ) {
            return b[ii][jj] != 'X';
        }
        return false;
    };

    ll ans = -1;
    vector<pair<ll,ll>> moves = {{-1,0},{0,-1},{1,0},{0,1}};
    while (!pq.empty()) {
        // cout <<"A " <<  pq.front().second[0] << ' ' << pq.front().second[1] << " B " <<pq.front().second[2] << ' ' <<pq.front().second[3] << endl;
        if ((pq.front().second[2] == di) && (pq.front().second[3] == dj)) {
            ans = pq.front().first;
            break;
        }
        s = pq.front().second;
        // visit.insert(pq.front().second);
        vis[s[0]][s[1]].insert({s[2], s[3]});

        for (auto &itr : moves) {
                ll i = itr.first;
                ll j = itr.second;

                if (valida(s[0] + i,s[1] + j)) {
                    ss ns;
                    ns[0] = i + s[0];
                    ns[1] = s[1] + j;

                    if (validb(s[2] + i, s[3] + j)) {
                        ns[2] = i + s[2];
                        ns[3] = s[3] + j;
                    }
                    else {
                        ns[2] = s[2];
                        ns[3] = s[3];
                    }
                    if (vis[ns[0]][ns[1]].find({ns[2],ns[3]}) == vis[ns[0]][ns[1]].end()) {
                        pq.push({pq.front().first + 1, ns});
                        // cout <<"NS : A " <<  ns[0] << ' ' << ns[1] << " B " << ns[2] << ' ' << ns[3] << " step " << i << ' ' << j << endl;
                        // for (int k = 0; k < r; k++) {
                        //     for (int l = 0; l < c; l++) {
                        //         if (ns[0] == k && ns[1] == l) {
                        //             cout << "A";
                        //         }
                        //         else if (ns[2] == k && ns[3] == l) {
                        //             cout << "B";
                        //         }
                        //         else {
                        //             cout << "x";
                        //         }
                        //     }
                        //     cout << endl;
                        // }
                    }
                }
        }
        pq.pop();
    }
    cout << ans;
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;

    while (T--) {
        solve();
        if (T)
            cout << '\n';
    }

    return 0;
}