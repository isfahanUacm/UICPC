#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int R, C, res;
bool visited[10003];
char arr[103][103];

int dirr[4] = {1,0,-1, 0};
int dirc[4] = {0,1,0, -1};

bool inrange(int r, int c){
    return r >= 0 && r < R && c >= 0 && c < C;
}


void dfs(int u){
    visited[u] = true;
    int r = u/C, c = u % C, rr, cc, uu;
    for (int i = 0; i < 4; ++i) {
        rr = r+dirr[i]; cc = c+dirc[i]; uu = rr*C+cc;
        if(inrange(rr, cc) && arr[rr][cc]=='-' && !visited[uu])
            dfs(uu);
    }
}

int main()
{
    int cas = 1;
    while(cin>>R>>C){
        res = 0;
        fill_n(visited, R*C, false);
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                cin>>arr[i][j];
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if(arr[i][j]=='-' && !visited[i*C+j]){
                    dfs(i*C+j);
                    res++;
                }
        cout<<"Case "<<cas<<": "<<res<<endl;
        cas++;
    }
    return 0;
}
