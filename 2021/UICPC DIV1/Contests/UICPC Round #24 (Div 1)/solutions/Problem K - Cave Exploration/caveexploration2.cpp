#include <bits/stdc++.h>
using namespace std;

bool vis[103][103];
int n;
int grid[103][103];
pair<int, int> dirr[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool inrange(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < n;
}

bool judge(int h){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vis[i][j] = false;
        }
    }
    pair<int, int> cur = {0, 0}, nxt;
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[cur.first][cur.second] = true;
    while(!q.empty()){
        cur = q.front(); q.pop();
        if(cur.first == n-1 && cur.second == n-1){
            return true;
        }
        for (int k = 0; k < 4; ++k) {
            nxt = {cur.first + dirr[k].first, cur.second + dirr[k].second};
            if(inrange(nxt.first, nxt.second) && !vis[nxt.first][nxt.second] && grid[nxt.first][nxt.second] < h){
                vis[nxt.first][nxt.second] = true;
                q.push(nxt);
            }
        }
    }
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    int lo = 0, hi = 100000000, mid;
    int hh = 1;
    while(lo < hi){
        mid = (lo + hi)/2;
        if(judge(hh + mid)){
            hi = mid;
//            cout << mid << " " << lo << " " << hi << " " << true << endl;
        }
        else{
            lo = mid + 1;
//            cout << mid << " " << lo << " " << hi << " " << false << endl;
        }
    }
    cout << lo << endl;
    return 0;
}

