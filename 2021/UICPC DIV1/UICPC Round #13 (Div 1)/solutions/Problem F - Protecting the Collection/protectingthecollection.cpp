#include <bits/stdc++.h>
using namespace std;

short dp[2005][2005][5][2];

int grid[2005][2005]; string ch;

int n, C, R;

pair<int, int> direct[4] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

int next_dir[3][4];

void init(){
    next_dir[0][0] = 0, next_dir[0][1] = 1, next_dir[0][2] = 2, next_dir[0][3] = 3;
    next_dir[1][0] = 1, next_dir[1][1] = 0, next_dir[1][2] = 3, next_dir[1][3] = 2;
    next_dir[2][0] = 3, next_dir[2][1] = 2, next_dir[2][2] = 1, next_dir[2][3] = 0;
}

int cdp(int r, int c, int dir, int used){
    if (r < 0 || c < 0 || r >= n || c >= n){
        if(c == n && r == R-1 && dir == 1){
            return 1;
        }
        return 0;
    }
    if (dp[r][c][dir][used] != -1)
        return dp[r][c][dir][used];
    int ans = 0;
    ans |= cdp(r + direct[next_dir[grid[r][c]][dir]].first, c + direct[next_dir[grid[r][c]][dir]].second, next_dir[grid[r][c]][dir], used);
    if (!used && !grid[r][c]){
        ans |= cdp(r + direct[next_dir[0][dir]].first, c + direct[next_dir[0][dir]].second, next_dir[0][dir], 1);
        ans |= cdp(r + direct[next_dir[1][dir]].first, c + direct[next_dir[1][dir]].second, next_dir[1][dir], 1);
    }    
    return dp[r][c][dir][used] = ans;
}

int main()
{
    init();
    cin >> n >> C >> R;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> ch, grid[i][j] = ((ch == ".") ? 0 : ((ch == "/") ? 1 : 2));
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k < 4; ++k)
                dp[i][j][k][0] = dp[i][j][k][1] = -1;
    cout << ((cdp(0, C-1, 2, 0))?"YES":"NO") << endl;
    return 0;
}

