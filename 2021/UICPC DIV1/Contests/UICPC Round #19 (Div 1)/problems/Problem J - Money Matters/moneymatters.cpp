#include <bits/stdc++.h>
using namespace std;

bool visited[10003];
int money[10003];
vector<vector<int>> edge(50000);
int s;

void dfs(int i){
    visited[i] = true;
    for (int j = 0; j < edge[i].size(); ++j) {
        if(visited[edge[i][j]])
           continue;
        s += money[edge[i][j]];
        dfs(edge[i][j]);
    }
}

int main()
{
    int n, m, a, b;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
        cin>>money[i];
    for (int i = 0; i < m; ++i){
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    fill_n(visited, n, false);
    bool res = true;
    for (int i = 0; i < n; ++i) {
        if(visited[i])
            continue;
        s = money[i];
        dfs(i);
        if(s!=0){
            res = false;
            break;
        }
    }
    cout<<((res)?"POSSIBLE":"IMPOSSIBLE")<<endl;
    return 0;
}

