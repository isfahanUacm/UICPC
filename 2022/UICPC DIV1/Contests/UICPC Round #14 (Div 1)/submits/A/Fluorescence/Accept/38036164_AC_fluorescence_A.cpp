#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

vector<vector<int>> black(1000+5);
vector<vector<int>> red(1000+5);
bool vis[1005][2];
bool stop[1005];
int n, m;

void dfs(int v, int bug){
    if (vis[v][bug])
        return;
    vis[v][bug] = true;
    //check stop
    /*if(bug == 1 && red[v].size() == 0)
        stop[v] = true;
    if(bug == 0 && black[v].size() == 0) 
        stop[v] = true;
    if(bug == 0 && red[v].size() == 0)
        stop[v] = true;*/
    if(red[v].size() == 0)
        stop[v] = true;
    //red = hamishe
    for (int u : red[v]){
        dfs(u, bug);
    }
    
    if(bug == 0){
        //just black
        for(int u : black[v]){
            dfs(u, 1);
        }
    }
}

int main(){
    int u, v;
    cin>>n>>m;
    for (int i = 0; i < m; i++){
        cin>>u>>v;
        if (u < 0){
            red[abs(u)].push_back(v);
        }
        else{
            black[u].push_back(v);
        }
    }

    dfs(1, 0);

    int cnt = 0;
    for (int i = 1; i < n+1; i++){
        if(stop[i]) {
            //cout<<i<<endl;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    
}