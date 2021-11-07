#include <bits/stdc++.h>
using namespace std;

// Cave Exploration

int n, h[103][103], vis[103][103];

int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};

void dfs(int i, int j, int l){
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && h[x][y] < l)
            dfs(x, y, l);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> h[i][j];
    int lo = 1, hi = 1e8 + 1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                vis[i][j] = 0;
        dfs(0, 0, mid);
        if(vis[n-1][n-1])
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo - 1 << endl;
}