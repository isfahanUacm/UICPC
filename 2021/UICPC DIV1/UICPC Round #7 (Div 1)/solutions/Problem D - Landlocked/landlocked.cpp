#include <bits/stdc++.h>
using namespace std;

int dist[30];
int dist2[1003][1003];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int n, m, a, b, w;
char grid[1003][1003];
vector<pair<int, int>> countries[30];
int dirr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dirc[8] = {-1, 0, 1, 1, 0, 1, -1, -1};

bool inrange(int i, int j){
    return i>=0 && j>=0 && i<n && j<m;
}

int main()
{
    cin>>n>>m;
    for (int i = 0; i < 30; ++i) {
        dist[i]=INT_MAX;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>grid[i][j];dist2[i][j]=INT_MAX;
            countries[int(grid[i][j]-'A')].push_back({i, j});
            if(grid[i][j]=='W')
                dist2[i][j]=0, pq.push({0, {i, j}});
        }
    }
    pair<int, pair<int, int>> pp;
    pair<int, int> p;
    while(!pq.empty()){
        pp = pq.top();pq.pop();
        p = pp.second;
        if(pp.first>dist2[p.first][p.second])
            continue;
        for (int i = 0; i < 8; ++i) {
            a = p.first+dirr[i]; b = p.second+dirc[i];
            w = ((grid[p.first][p.second]=='W' || (grid[p.first][p.second]==grid[a][b]))?0:1);
            if(inrange(a, b) && dist2[a][b]>dist2[p.first][p.second]+w){
                dist2[a][b] = dist2[p.first][p.second]+w;
                pq.push({dist2[a][b], {a, b}});
            }
        }
    }
    for (int i = 0; i < 26; ++i) {
        if(i==('W'-'A')|| !countries[i].size())continue;
        for (auto v: countries[i]) {
            dist[i] = min(dist[i], dist2[v.first][v.second]); 
        }
        cout<<char('A'+i)<<" "<<dist[i]<<endl;
    }
    
    return 0;
}

