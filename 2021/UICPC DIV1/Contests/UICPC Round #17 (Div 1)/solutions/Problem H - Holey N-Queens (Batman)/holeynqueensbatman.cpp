/**
  https://open.kattis.com/problems/holeynqueensbatman
  Author: https://github.com/smh997/
**/

#include <bits/stdc++.h>
using namespace std;

bool holes[15][15];
int n, m, hr, hc, ans, queens[15];

void trace(int r){
    if(r == n){
        ans++;
        return;
    }
    for (int j = 0; j < n; ++j) {
        if(holes[r][j])
            continue;
        bool possible = true;
        for (int k = 0; k < r; ++k)
            if(queens[k] == j || r - k == abs(queens[k] - j)){
                possible = false;
                break;
            }
        if(possible){
            queens[r] = j;
            trace(r+1);
        }
    }
}

int main()
{
    while(true){
        cin >> n >> m;
        if(n+m == 0){
            break;
        }
        ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                holes[i][j] = false;
        for (int i = 0; i < m; ++i) {
            cin >> hr >> hc;
            holes[hr][hc] = true;
        }
        trace(0);
        cout << ans << endl;
    }
    return 0;
}

