#include <bits/stdc++.h>
using namespace std;

// Cracker Barrel Game

char target;
map<string, bool> memo;

int adjR[6]{-1, -1, 0, 0, 1, 1};
int adjC[6]{0, -1, -1, 1, 0, 1};

bool dp(string state){
    if(memo.find(state) != memo.end())
        return memo[state];
    int ptr = 0, cnt = 0;
    char g[5][5], last;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < i + 1; j++){
            g[i][j] = state[ptr++];
            if(g[i][j] != '_')
                cnt++, last = g[i][j];
        }
    if(cnt == 1)
        return memo[state] = last == target;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < i + 1; j++)
            if(g[i][j] != '_')
                for(int k = 0; k < 6; k++){
                    int x = i + adjR[k], y = j + adjC[k];
                    int xx = i + 2 * adjR[k], yy = j + 2 * adjC[k];
                    if(x >= 0 && x < 5 && y >= 0 && y < x + 1 && xx >= 0 && xx < 5 && yy >= 0 && yy < xx + 1 && g[x][y] != '_' && g[xx][yy] == '_'){
                        string subp = "";
                        for(int ii = 0; ii < 5; ii++)
                            for(int jj = 0; jj < ii + 1; jj++){
                                if(ii == i && jj == j)
                                    subp += '_';
                                else if(ii == x && jj == y)
                                    subp += '_';
                                else if(ii == xx && jj == yy)
                                    subp += g[i][j];
                                else 
                                    subp += g[ii][jj];
                            }
                        if(dp(subp))
                            return memo[state] = true;
                    }
                }
    return memo[state] = false;    
}

int main(){
    char tmp;
    string s;
    while(1){
        cin >> target >> target;
        if(target == '*')
            break;
        memo.clear();
        s = "";
        for(int i = 0; i < 15; i++)
            cin >> tmp >> tmp, s += tmp;
        cout << (dp(s) ? "Possible" : "Impossible") << endl;
    }
}