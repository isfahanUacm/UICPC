#include <bits/stdc++.h>
using namespace std;

string inp[100003];
map<string, int> mp;
int n, m;
string s, t;
int color[100003];
vector<int> adj[100003];

bool bicolorable(int u, int col){
    color[u] = col;
//    cerr << u << col;
    for(auto v: adj[u]){
        if(color[v]==-1){
            if(!bicolorable(v, 1-color[u]))
                return false;
        }
        else if(color[v] == color[u]){
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
        mp[inp[i]] = i;
        color[i] = -1;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s >> t;
        adj[mp[s]].push_back(mp[t]);
        adj[mp[t]].push_back(mp[s]);
    }
    for (int i = 0; i < n; ++i) {
        if(color[i] == -1 && !bicolorable(i, 0)){
            cout << "impossible" << endl;
            return 0;
        }
    }
    vector<string> W, J;
    for (int i = 0; i < n; ++i) {
        if(color[i]){
            W.push_back(inp[i]);
        }
        else{
            J.push_back(inp[i]);
        }
    }
    for (auto v: W) {
        cout << v << " ";
    }cout << endl;
    for (auto v: J) {
        cout << v << " ";
    }cout << endl;
    
    return 0;
}

