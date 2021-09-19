#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
int R, C;
pair<int, int> A, B, I1, I2;
pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool outside[105][105];
bool vis[105][105];
int cnt;
int resa, resb, reso;

bool inrange(int i, int j){
    return i >= 0 && i <= R+1 && j >= 0 && j <= C+1; 
}

bool check(int i, int j){
    return grid[i-1][j] == 'X' && grid[i][j+1] == 'X' && grid[i][j-1] == 'X' && grid[i+1][j] == 'X';
}

void flood_around(int uy, int ux){
    outside[uy][ux] = true;
    for (int i = 0; i < 4; ++i) {
        if(inrange(uy+dir[i].first, ux+dir[i].second) && !outside[uy+dir[i].first][ux+dir[i].second] && grid[uy+dir[i].first][ux+dir[i].second] == '.'){
            flood_around(uy+dir[i].first, ux+dir[i].second);
        }
    }
}

void dfs(int uy, int ux, int d, int ch){
    if((I1.first == uy && I1.second == ux) || (I2.first == uy && I2.second == ux)){
        dfs(uy+dir[d].first, ux+dir[d].second, d, ch);
        return;
    }
    grid[uy][ux] = ch;
    for (int i = 0; i < 4; ++i) {
        if((d+2) % 4 == i)
            continue;
        if(grid[uy+dir[i].first][ux+dir[i].second] == 'X'){
            dfs(uy+dir[i].first, ux+dir[i].second, i, ch);
        }
    }
}

void calc(int uy, int ux){
    vis[uy][ux] = true;
    cnt++;
    for (int i = 0; i < 4; ++i) {
        if(!vis[uy+dir[i].first][ux+dir[i].second] && grid[uy+dir[i].first][ux+dir[i].second] == '.'){
            calc(uy+dir[i].first, ux+dir[i].second);
        }
    }
}

int main()
{
    I2 = I1 = {-1, -1};
    cin >> R >> C;
    for (int i = 0; i < R+2; ++i) {
        for (int j = 0; j < C+2; ++j) {
            if(i == 0 || i == R+1 || j == 0 || j == C+1){
                grid[i][j] = '.';
            }
            else{
                cin >> grid[i][j];
                if(grid[i][j] == 'A'){
                    A = {i, j};
                }
                else if(grid[i][j] == 'B'){
                    B = {i, j};
                }
            }
        }
    }
    for (int i = 1; i < R+1; ++i) {
        for (int j = 1; j < C+1; ++j) {
            if(check(i, j)){
                if(I1.first == -1 && I1.second == -1){
                    I1 = {i, j};
                }
                else{
                    I2 = {i, j};
                }
            }
        }
    }
    flood_around(0, 0);
    for (int i = 0; i < 4; ++i) {
        if(grid[A.first+dir[i].first][A.second+dir[i].second] == 'X'){
            dfs(A.first+dir[i].first, A.second+dir[i].second, i, 'A');
            break;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if(grid[B.first+dir[i].first][B.second+dir[i].second] == 'X'){
            dfs(B.first+dir[i].first, B.second+dir[i].second, i, 'B');
            break;
        }
    }
    if(outside[I1.first-1][I1.second-1]){
        if(grid[I1.first-1][I1.second] == 'A'){
            cnt = 0;
            calc(I1.first-1, I1.second+1);
            resa = cnt;
            cnt = 0;
            calc(I1.first+1, I1.second-1);
            resb = cnt;
            cnt = 0;
            calc(I1.first+1, I1.second+1);
            reso = cnt;
        }
        else{
            cnt = 0;
            calc(I1.first-1, I1.second+1);
            resb = cnt;
            cnt = 0;
            calc(I1.first+1, I1.second-1);
            resa = cnt;
            cnt = 0;
            calc(I1.first+1, I1.second+1);
            reso = cnt;
        }
    }
    else if(outside[I1.first-1][I1.second+1]){
        if(grid[I1.first-1][I1.second] == 'A'){
            cnt = 0;
            calc(I1.first-1, I1.second-1);
            resa = cnt;
            cnt = 0;
            calc(I1.first+1, I1.second-1);
            reso = cnt;
            cnt = 0;
            calc(I1.first+1, I1.second+1);
            resb = cnt;
        }
        else{
            cnt = 0;
            calc(I1.first-1, I1.second-1);
            resb = cnt;
            cnt = 0;
            calc(I1.first+1, I1.second-1);
            reso = cnt;
            cnt = 0;
            calc(I1.first+1, I1.second+1);
            resa = cnt;
        }
    }
    else if(outside[I1.first+1][I1.second-1]){
        if(grid[I1.first+1][I1.second] == 'A'){
            cnt = 0;
            calc(I1.first+1, I1.second+1);
            resa = cnt;
            cnt = 0;
            calc(I1.first-1, I1.second-1);
            resb = cnt;
            cnt = 0;
            calc(I1.first-1, I1.second+1);
            reso = cnt;
        }
        else{
            cnt = 0;
            calc(I1.first+1, I1.second+1);
            resb = cnt;
            cnt = 0;
            calc(I1.first-1, I1.second-1);
            resa = cnt;
            cnt = 0;
            calc(I1.first-1, I1.second+1);
            reso = cnt;
        }
    }
    else{
        if(grid[I1.first+1][I1.second] == 'A'){
            cnt = 0;
            calc(I1.first+1, I1.second-1);
            resa = cnt;
            cnt = 0;
            calc(I1.first-1, I1.second+1);
            resb = cnt;
            cnt = 0;
            calc(I1.first-1, I1.second-1);
            reso = cnt;
        }
        else{
            cnt = 0;
            calc(I1.first+1, I1.second-1);
            resb = cnt;
            cnt = 0;
            calc(I1.first-1, I1.second+1);
            resa = cnt;
            cnt = 0;
            calc(I1.first-1, I1.second-1);
            reso = cnt;
        }
    }
    cout << resa << " " << resb << " " << reso << endl;
    return 0;
}

