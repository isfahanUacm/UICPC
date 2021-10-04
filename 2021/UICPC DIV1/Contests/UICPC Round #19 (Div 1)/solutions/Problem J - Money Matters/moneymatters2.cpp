#include <bits/stdc++.h>
using namespace std;

// Money Matters

int v, e;
vector<int> adj[10003];
bool visited[100003];
int w[100003];
int sum;

void dfs(int i){
    visited[i] = true;
    sum += w[i];
    for(auto j : adj[i])
        if(!visited[j])
            dfs(j);
}

int main(){
    for(int i = 0; i < 100003; i++)
        visited[i] = false;
    cin >> v >> e;
    for(int i = 0; i < v; i++)
        cin >> w[i];
    for(int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool ans = true;
    for(int i = 0; i < v; i++)
        if(!visited[i]){
            sum = 0;
            dfs(i);
            if(sum != 0){
                ans = false;
                break;
            }
        }
    cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}