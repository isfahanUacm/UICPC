#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    int n , m;
    cin >> n >> m;
    int x1 , y1 , x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    x1--;
    y1--;
    x2--;
    y2--;
    pair<pair<int , int> , int> q;
    q = {{x1 , y1} , 1};
    vector<vector<vi>> vis(n , vector<vi>(m , vi(5 , 0)));
    vis[x1][y1][1] = 1;
    while(true){
        int na , nb;
        switch (q.second) {
            case 1:
                na = q.first.first - 1;
                nb = q.first.second;
                if(na >= 0 && na < n && nb >= 0 && nb < m && a[na][nb] == '0'){
                    q.first.first = na;
                    q.first.second = nb;
                    q.second = 4;
                    vis[na][nb][4]++;
                    if(vis[na][nb][4] > 1){
                        cout << "0";
                        return;
                    }
                    continue;
                }
                na = q.first.first;
                nb = q.first.second + 1;
                if(na >= 0 && na < n && nb >= 0 && nb < m && a[na][nb] == '0'){
                    q.first.first = na;
                    q.first.second = nb;
                    q.second = 1;
                    vis[na][nb][1]++;
                    if(vis[na][nb][1] > 1){
                        cout << "0";
                        return;
                    }
                    continue;
                }
                na = q.first.first;
                nb = q.first.second;
                q.second = 2;
                vis[na][nb][2]++;
                if(vis[na][nb][2] > 1){
                    cout << "0";
                    return;
                }
                break;

            case 2:
                na = q.first.first;
                nb = q.first.second + 1;
                if(na >= 0 && na < n && nb >= 0 && nb < m && a[na][nb] == '0'){
                    q.first.first = na;
                    q.first.second = nb;
                    q.second = 1;
                    vis[na][nb][1]++;
                    if(vis[na][nb][1] > 1){
                        cout << "0";
                        return;
                    }
                    continue;
                }
                na = q.first.first + 1;
                nb = q.first.second;
                if(na >= 0 && na < n && nb >= 0 && nb < m && a[na][nb] == '0'){
                    q.first.first = na;
                    q.first.second = nb;
                    q.second = 2;
                    vis[na][nb][2]++;
                    if(vis[na][nb][2] > 1){
                        cout << "0";
                        return;
                    }
                    continue;
                }
                na = q.first.first;
                nb = q.first.second;
                q.second = 3;
                vis[na][nb][3]++;
                if(vis[na][nb][3] > 1){
                    cout << "0";
                    return;
                }
                break;
            case 3:
                na = q.first.first + 1;
                nb = q.first.second;
                if(na >= 0 && na < n && nb >= 0 && nb < m && a[na][nb] == '0'){
                    q.first.first = na;
                    q.first.second = nb;
                    q.second = 2;
                    vis[na][nb][2]++;
                    if(vis[na][nb][2] > 1){
                        cout << "0";
                        return;
                    }
                    continue;
                }
                na = q.first.first;
                nb = q.first.second - 1;
                if(na >= 0 && na < n && nb >= 0 && nb < m && a[na][nb] == '0'){
                    q.first.first = na;
                    q.first.second = nb;
                    q.second = 3;
                    vis[na][nb][3]++;
                    if(vis[na][nb][3] > 1){
                        cout << "0";
                        return;
                    }
                    continue;
                }
                na = q.first.first;
                nb = q.first.second;
                q.second = 4;
                vis[na][nb][4]++;
                if(vis[na][nb][4] > 1){
                    cout << "0";
                    return;
                }
                break;
            case 4:
                na = q.first.first + 1;
                nb = q.first.second;
                if(na >= 0 && na < n && nb >= 0 && nb < m && a[na][nb] == '0'){
                    q.first.first = na;
                    q.first.second = nb;
                    q.second = 3;
                    vis[na][nb][3]++;
                    if(vis[na][nb][3] > 1){
                        cout << "0";
                        return;
                    }
                    continue;
                }
                na = q.first.first - 1;
                nb = q.first.second;
                if(na >= 0 && na < n && nb >= 0 && nb < m && a[na][nb] == '0'){
                    q.first.first = na;
                    q.first.second = nb;
                    q.second = 4;
                    vis[na][nb][4]++;
                    if(vis[na][nb][4] > 1){
                        cout << "0";
                        return;
                    }
                    continue;
                }
                na = q.first.first;
                nb = q.first.second;
                q.second = 1;
                vis[na][nb][1]++;
                if(vis[na][nb][1] > 1){
                    cout << "0";
                    return;
                }

        }
        if(q.first.first == x2 && q.first.second == y2){
            cout << 1;
            return;
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