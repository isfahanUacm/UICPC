#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    int n , p , q;
    cin >> n >> p >> q;
    vector<vi> acc(n , vi(p , -1));
    vector<pair<int , int>> acc2(n);
    for (int i = 0; i < n; ++i) {
        acc2[i].second = i;
    }
    vector<vi> fail(n , vi(p));
    for (int i = 0; i < q; ++i) {
        int time , id , que , v;
        cin >> time >> id >> que >> v;
        id --;
        que --;
        if(acc[id][que] == -1){
            if(v == 1){
                acc[id][que] = time;
                acc2[id].first ++;
            }
            else{
                fail[id][que] ++;
            }
        }
    }
    sort(acc2.rbegin(), acc2.rend());
    int rate = 1;
    for (int i = 0; i < n; ++i) {
        if(i < n - 1){
            if(acc2[i].first != acc2[i + 1].first){
                ll T = 0;
                int id = acc2[i].second;
                for (int j = 0; j < p; ++j) {
                    if(acc[id][j] != -1)
                        T += fail[id][j] * 20 + acc[id][j];
                }
                cout << rate++ << " " << id + 1 << " " << acc2[i].first << " " << T << "\n";
            }
            else{
                vector<pair<int , int>> l;
                while(acc2[i].first == acc2[i + 1].first){
                    l.push_back({acc2[i]});
                    i++;
                }
                l.push_back(acc2[i]);
                int accept = l[0].first;
                int size = (int)l.size();
                int r = rate;
                rate += size;
                for (int j = 0; j < size; ++j) {
                    int id = l[j].second;
                    ll T = 0;
                    for (int k = 0; k < p; ++k) {
                        if (acc[id][k] != -1)
                            T += fail[id][k] * 20 + acc[id][k];
                    }
                    l[j].first = T;
                }
                std::sort(l.begin(), l.end());
                for (int j = 0; j < size; ++j) {
                    cout << r << " " << l[j].second + 1 << " " << accept << " " << l[j].first << "\n";
                }
            }
        }
        else{
            ll T = 0;
            int id = acc2[i].second;
            for (int j = 0; j < p; ++j) {
                if(acc[id][j] != -1)
                    T += fail[id][j] * 20 + acc[id][j];
            }
            cout << rate++ << " " << id + 1 << " " << acc2[i].first << " " << T << "\n";
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