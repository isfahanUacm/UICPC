#include <bits/stdc++.h>
using namespace std;

int A, F, L, W, si, sj, ti, tj;
char grid[1003][1003];
int Edist[1003][1003], Fdist[1003][1003];

bool inrange(int i, int j){
    return i < L && i >= 0 && j < W && j >= 0;
}

bool accessible(int curi, int curj, int targi, int targj, int step){
    double dst = (curi - targi) * (curi - targi) + (curj - targj) * (curj - targj);
    return 1.0 * step * step >= dst;
}

int main()
{
    cin >> A >> F >> L >> W;
    for (int i = 0; i < L; ++i)
        for (int j = 0; j < W; ++j){
            cin >> grid[i][j], Edist[i][j] = Fdist[i][j] = INT_MAX;
            if(grid[i][j] == 'S'){
                Edist[i][j] = Fdist[i][j] = 0;
                si = i, sj = j;
            }
            else if(grid[i][j] == 'G'){
                ti = i, tj = j;
            }
        }
    queue<pair<int, int>> q;
    q.push({si, sj});
    pair<int, int> p;
    bool flag = false;
    while(!q.empty() && !flag){
        p = q.front(); q.pop();
        for (int i = max(0, p.first-A); i <= min(L-1, p.first + A); ++i) {
            for (int j = max(0, p.second-A); j <= min(W-1, p.second + A); ++j) {
                if(grid[i][j] != 'B' && accessible(p.first, p.second, i, j, A) && Edist[i][j] == INT_MAX){
                    Edist[i][j] = Edist[p.first][p.second] + 1;
                    q.push({i, j});
                    if(grid[i][j] == 'G'){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
    }
    queue<pair<int, int>> qq;
    qq.push({si, sj});
    flag = false;
    while(!qq.empty() && !flag){
        p = qq.front(); qq.pop();
        for (int i = -F; i <= F; ++i) {
            if(inrange(p.first + i, p.second) && grid[p.first + i][p.second] != 'B' && Fdist[p.first + i][p.second] == INT_MAX){
                Fdist[p.first + i][p.second] = Fdist[p.first][p.second] + 1;
                qq.push({p.first + i, p.second});
                if(grid[p.first + i][p.second] == 'G'){
                    flag = true;
                    break;
                }
            }
            if(inrange(p.first, p.second + i) && grid[p.first][p.second + i] != 'B' && Fdist[p.first][p.second + i] == INT_MAX){
                Fdist[p.first][p.second + i] = Fdist[p.first][p.second] + 1;
                qq.push({p.first, p.second + i});
                if(grid[p.first][p.second + i] == 'G'){
                    flag = true;
                    break;
                }
            }
        }
    }
    if(Edist[ti][tj] == INT_MAX && Edist[ti][tj] == Fdist[ti][tj])
        cout << "NO WAY" << endl;
    else if(Edist[ti][tj] < Fdist[ti][tj])
        cout << "GO FOR IT" << endl;
    else if(Edist[ti][tj] > Fdist[ti][tj])
        cout << "NO CHANCE" << endl;
    else
        cout << "SUCCESS" << endl;
    return 0;
}

