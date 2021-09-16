#include <bits/stdc++.h>
using namespace std;
int res = 0;
bool vis[1003][1003];
char gridc[1003][1003];
bool grid[1003][1003];
int dirr[4] = {0, 1, -1, 0};
int dirc[4] = {1, 0, 0, -1};
int n, m;
bool inrange(int i, int j){
    return i>=0 && j>=0 && i<n+2 && j<m+2;
}

void dfs(int i, int j){
    vis[i][j]=true;
    if(!grid[i][j]){
        for (int k = 0; k < 4; ++k) {
            if(inrange(i+dirr[k], j+dirc[k]) && !vis[i+dirr[k]][j+dirc[k]]){
                if(grid[i+dirr[k]][j+dirc[k]])
                    res++;
                else
                    dfs(i+dirr[k], j+dirc[k]);
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>gridc[i][j];
            if(gridc[i][j]=='1')
                grid[i][j] = true;
        }
    }
    dfs(0, 0);
    cout<<res<<endl;
    return 0;
}

