#include <bits/stdc++.h>
using namespace std;

// Pumpkin Patch

int p, d, n, x[903], y[903], grid[33][33], ans[903];
set<int> alive, rem;

int adjR[4]{0, 0, -1, 1};
int adjC[4]{-1, 1, 0, 0};

int main(){
    cin >> p >> d >> n;
    for(int i = 0; i < p; i++)
        cin >> x[i] >> y[i], alive.insert(i);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            grid[i][j] = -1;
    for(int i = 0; i < p; i++)
        grid[x[i]][y[i]] = i;
    for(int t = 1; t <= d; t++){
        rem.clear();
        for(int p : alive){
            for(int k = 0; k < 4; k++){
                int i = x[p] + t * adjR[k], j = y[p] + t * adjC[k];
                if(i >= 0 && i < n && j >= 0 && j < n){
                    if(grid[i][j] == -1)
                        grid[i][j] = p;
                    else{
                        rem.insert(p);
                        if(alive.find(grid[i][j]) != alive.end())
                            rem.insert(grid[i][j]);
                    }
                }
                else
                    rem.insert(p);
            }
        }
        for(int p : rem)
            ans[p] = t, alive.erase(p);
    }
    for(int i = 0; i < p; i++){
        if(ans[i])
            cout << ans[i] << endl;
        else
            cout << "ALIVE" << endl;
    }
}