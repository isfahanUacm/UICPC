#include <bits/stdc++.h>
using namespace std;

// Watersheds

int n, m, grid[103][103];
char cnt, ans[103][103];

int adjR[4]{-1, 0, 0, 1};
int adjC[4]{0, -1, 1, 0};

char hit(int i, int j){
    if(ans[i][j] != '.')
        return ans[i][j];
    int val = grid[i][j], s = -1;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] < val)
            val = grid[x][y], s = k;
    }
    if(s == -1)
        return ans[i][j] = cnt++;
    return ans[i][j] = hit(i + adjR[s], j + adjC[s]);
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> grid[i][j], ans[i][j] = '.';
        cnt = 'a';
        cout << "Case #" << t << ":" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout << hit(i, j) << " ";
            cout << endl;
        }    
    }
}