#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n, m, a, b, c;
int pri[28][28];
string s;
bool visited[28];

void dfs(int u){
    visited[u] = true;
    for (auto v : adj[u]) {
        if(!visited[v])
            dfs(v);
    }
}

int main()
{
    cin>>n>>m;
    adj.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pri[i][j] = 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        cin>>b>>s;
        for (int j = 0; j < s.length()-1; ++j) {
            a = s[j]-'A';
            for (int k = j+1; k < s.length(); ++k) {
                c = s[k]-'A';
                pri[a][c] += b;
                pri[c][a] -= b;
            }
        }
    }
    for (int i = 0; i < n-1; ++i) {
        for (int j = i; j < n; ++j) {
            if(pri[i][j]>0)
                adj[i].push_back(j);
            else
                adj[j].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        fill_n(visited, n, false);
        dfs(i);
        bool res = true;
        for (int j = 0; j < n; ++j) {
            if(!visited[j]){
                res = false;
                break;
            }
        }
        if(res)
            cout<<((char)('A'+i))<<": "<<"can win"<<endl;
        else
            cout<<((char)('A'+i))<<": "<<"can't win"<<endl;
    }
    
    return 0;
}

