#include <bits/stdc++.h>
using namespace std;

// Rock Climbing

const int inf = INT_MIN;

int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, -1, 1};

int r, c, g[23][23], dis[23][23];
char idiot;
priority_queue<pair<int, int>> dij;

// Bellman Ford:

bool judge(int energy){
    for(int i = 0; i <= r + 1; i++)
        for(int j = 0; j < c; j++)
            dis[i][j] = inf;
    for(int j = 0; j < c; j++)
        dis[r+1][j] = energy;
    for(int _ = 0; _ < ((r + 2) * c - 1); _++)
        for(int i = 0; i <= r + 1; i++)
            for(int j = 0; j < c; j++)
                if(dis[i][j] != inf)
                    for(int k = 0; k < 4; k++){
                        int x = i + adjR[k], y = j + adjC[k];
                        if(x >= 0 && x < r + 2 && y >= 0 && y < c && dis[i][j] >= g[x][y])
                            dis[x][y] = max(dis[x][y], dis[i][j] - g[x][y]);
                    }
    for(int j = 0; j < c; j++)
        if(dis[0][j] != inf)
            return true;
    return false;
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < c; i++)
        cin >> idiot;
    for(int i = 1; i <= r; i++)
        for(int j = 0; j < c; j++)
            cin >> g[i][j];
    for(int i = 0; i < c; i++)
        cin >> idiot;
    int lo = 0, hi = 15 * 15 * 9;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << endl;
}