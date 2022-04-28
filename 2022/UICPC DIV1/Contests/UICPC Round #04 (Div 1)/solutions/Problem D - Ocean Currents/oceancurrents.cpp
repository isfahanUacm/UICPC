#include <bits/stdc++.h>
using namespace std;

char gridc[1003][1003];
int grid[1003][1003];
int dist[1003][1003];
int r, c, n;
int dirr[8] = {-1,-1,0,1,1,1,0,-1};
int dirc[8] = {0,1,1,1,0,-1,-1,-1};
vector<pair<int, int>> sr, tr;

bool inrange(int i, int j){
    return i>=0 && j>=0 && i<r && j<c;
}

int main()
{
    cin>>r>>c;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin>>gridc[i][j],grid[i][j]=gridc[i][j]-'0';
    cin>>n;
    sr.resize(n);tr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>sr[i].first>>sr[i].second>>tr[i].first>>tr[i].second;
        sr[i].first--;sr[i].second--;tr[i].first--;tr[i].second--;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                dist[i][j]=INT_MAX;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        pair<int, int> p;
        pair<int, pair<int, int>> pp;
        q.push({0, sr[i]});
        dist[sr[i].first][sr[i].second]=0;
        while(!q.empty()){
            pp = q.top(); q.pop();
            p = pp.second;
            if(tr[i].first == p.first && tr[i].second == p.second){
                break;
            }
            if(pp.first>dist[p.first][p.second]){
                continue;
            }
            for (int i = 0; i < 8; ++i) {
                if(inrange(p.first+dirr[i], p.second+dirc[i]) && dist[p.first][p.second] + ((grid[p.first][p.second]==i)?0:1)<dist[p.first+dirr[i]][p.second+dirc[i]]){
                    dist[p.first+dirr[i]][p.second+dirc[i]]=dist[p.first][p.second] + ((grid[p.first][p.second]==i)?0:1);
                    q.push({dist[p.first+dirr[i]][p.second+dirc[i]], {p.first+dirr[i], p.second+dirc[i]}});
                }
            }
        }
        cout<<dist[tr[i].first][tr[i].second]<<endl;
    }
    
    return 0;
}
