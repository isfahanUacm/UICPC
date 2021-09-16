#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(100003);
bool visited[100003];
int n;
map<string, int> mp;
//vector<vector<string>> v(100003);
vector<int> res;

void dfs(int u){
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); ++i) {
        if(!visited[adj[u][i]])
            dfs(adj[u][i]);
    }
    res.push_back(u);
}

int main()
{
    fill_n(visited, n, false);
    cin>>n;
    string nodes[n], desc[n];
    string s, temp;
    getline(cin, s);
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        nodes[i] = s.substr(0,s.find(':'));
        mp[nodes[i]] = i;
        if (nodes[i].length() == s.length()-1)
            continue;
        s = s.substr(s.find(':')+2);      
        desc[i] = s;
    }
    for (int i = 0; i < n; ++i){
        if(desc[i].length()){
            stringstream ss(desc[i]);
            while(ss>>temp)
                adj[mp[temp]].push_back(i);
        }
    }
    cin>>temp;
    dfs(mp[temp]);
    for (int i = res.size()-1; i >= 0; i--) {
        cout<<nodes[res[i]]<<endl;
    }
    return 0;
}

