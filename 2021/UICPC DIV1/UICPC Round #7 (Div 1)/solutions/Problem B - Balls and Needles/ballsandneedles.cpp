#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(100003);
vector<vector<int>> adj2(100003);
int visited[100003];
int parent[100003];
int k, a, b, c, x, y, z;
map<string, int> sttoi;map<string, int> sttoi2;
string itost[100003];string itost2[100003];
bool cycle = false;

void dfs(int u){
    visited[u] = 1;
    for(auto v : adj[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
            if(cycle)
                return;
        }
        else if(v!=u && visited[v]==1){
            if(parent[u]!=v){
                cycle = true;
                return;
            }
        }
    }
    visited[u] = 2;
}

void dfs2(int u){
    visited[u] = 1;
    for(auto v : adj2[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs2(v);
            if(cycle)
                return;
        }
        else if(v!=u && visited[v]==1){
            if(parent[u]!=v){
                cycle = true;
                return;
            }
        }
    }
    visited[u] = 2;
}

int main()
{
    string s1, s2, ss1,ss2;
    cin>>k;
    int j = 1, jj = 1;
    for (int i = 0; i < k; ++i) {
        cin>>a>>b>>c>>x>>y>>z;
        ss1 = to_string(a) + " " + to_string(b);
        s1 = ss1 + " " + to_string(c);
        ss2 = to_string(x) + " " + to_string(y);
        s2 = ss2 + " " + to_string(z);
        if(sttoi.find(s1)==sttoi.end()){
            itost[j] = s1;
            sttoi[s1] = j++;
        }
        if(sttoi.find(s2)==sttoi.end()){
            itost[j] = s2;
            sttoi[s2] = j++;
        }
        if(sttoi2.find(ss1)==sttoi2.end()){
            itost2[jj] = ss1;
            sttoi2[ss1] = jj++;
        }
        if(sttoi2.find(ss2)==sttoi2.end()){
            itost2[jj] = ss2;
            sttoi2[ss2] = jj++;
        }
        adj[sttoi[s1]].push_back(sttoi[s2]);
        adj[sttoi[s2]].push_back(sttoi[s1]);
        adj2[sttoi2[ss1]].push_back(sttoi2[ss2]);
        adj2[sttoi2[ss2]].push_back(sttoi2[ss1]);
    }
    
    fill_n(visited, j+1, 0);
    fill_n(parent, j+1, 0);
    cycle = false;
    dfs(1);
    cout<<((cycle)?"True closed chains":"No true closed chains")<<endl;
    fill_n(visited, jj+1, 0);
    fill_n(parent, jj+1, 0);
    cycle = false;
    dfs2(1);
    cout<<((cycle)?"Floor closed chains":"No floor closed chains")<<endl;
    
    return 0;
}

