#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<char>> v;
    v.resize(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> dist;
    dist.resize(n, vector<int>(m, INT_MAX));

    int sx, sy;
    cin >> sx >> sy;
    sx--; sy--;

    dist[sx][sy] = 1;
    set<pair<int,pair<int,int>>> s;
    s.insert({0,{sx, sy}});

    int mvx[4] = {1, -1, 0, 0};
    int mvy[4] = {0, 0 , 1, -1};
    while(!s.empty()) {
        int currx = (*s.begin()).second.first;
        int curry = (*s.begin()).second.second;
        s.erase(s.begin());
        for(int i=0 ; i<4; i++) {
            int nxtx = currx + mvx[i];
            int nxty = curry + mvy[i];
            if(nxtx<n && nxtx>=0 && nxty>=0 && nxty<m){
                if(v[nxtx][nxty] == 'D')
                    if(dist[nxtx][nxty] > dist[currx][curry]) {
                        s.erase({dist[nxtx][nxty], {nxtx,nxty}});
                        dist[nxtx][nxty] = dist[currx][curry];
                        s.insert({dist[nxtx][nxty], {nxtx,nxty}});
                    }
                if(v[nxtx][nxty] == 'c')
                    if(dist[nxtx][nxty] > dist[currx][curry] + 1) {
                        s.erase({dist[nxtx][nxty], {nxtx,nxty}});
                        dist[nxtx][nxty] = dist[currx][curry] + 1;
                        s.insert({dist[nxtx][nxty], {nxtx,nxty}});
                    }
            }
        }
    }
    int best = INT_MAX;
    for(int i = 0; i < n; i++) {
        best = min(best, dist[i][0]);
        best = min(best, dist[i][m-1]);
    }
    for(int j = 0; j < m; j++) {
        best = min(best, dist[0][j]);
        best = min(best, dist[n-1][j]);
    }
    cout<<best<<endl;
    return 0;
}
