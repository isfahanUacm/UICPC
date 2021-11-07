#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1503
int dist[MAX_N][MAX_N];
int n;
char grid[MAX_N][MAX_N];
vector<pair<int ,int>> tr;
int dirr[4] = {0, -1, 0 ,1};
int dirc[4] = {-1, 0, 1 ,0};

bool inrange(int i, int j){
    return i>=0 && j>=0 && i<n && j<n;
}

int main()
{
    cin>>n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j]=INT_MAX;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            cin>>grid[i][j];
            if(grid[i][j]=='3'){
                dist[i][j]=0;
                q.push({i, j});
            }
            else if(grid[i][j]=='1'){
                tr.push_back({i, j});
            }
        }
    pair<int, int> p;
    while(!q.empty()){
        p = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            if(inrange(p.first+dirr[i], p.second+dirc[i]) && dist[p.first][p.second]+1<dist[p.first+dirr[i]][p.second+dirc[i]]){
                dist[p.first+dirr[i]][p.second+dirc[i]] = dist[p.first][p.second]+1;
                q.push({p.first+dirr[i], p.second+dirc[i]});
            }
        }
    }
    int mx = 0;
    for (auto v: tr)
        mx = max(dist[v.first][v.second], mx);
    cout<<mx<<endl;
    
    return 0;
}

