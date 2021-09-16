#include <bits/stdc++.h>
using namespace std;

// Holey N-Queens (Batman)

const int maxn = 12;

int n, m, ans, queen[maxn];
bool hole[maxn][maxn];

void track(int row){
    if(row == n){
        ans++;
        return;
    }
    for(int column = 0; column < n; column++){
        if(hole[row][column])
            continue;
        bool feasible = true;
        for(int prevy = 0; prevy < row; prevy++)
            if(queen[prevy] == column || row - prevy == abs(column - queen[prevy])){
                feasible = false;
                break;
            }
        if(feasible){
            queen[row] = column;
            track(row + 1);
        }
    }
}

int main(){
    while(true){
        cin >> n >> m;
        if(!(n + m))
            break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                hole[i][j] = false;
        int x, y;
        while(m--)
            cin >> x >> y, hole[x][y] = true;
        ans = 0;
        track(0);
        cout << ans << endl;
    }
}