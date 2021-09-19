#include <bits/stdc++.h>
using namespace std;

// Build Dependencies

int n;
map<string, vector<string>> adj;
set<string> vis;
vector<string> order;

void dfs(string u){
    vis.insert(u);
    for(string v : adj[u])
        if(vis.find(v) == vis.end())
            dfs(v);
    order.push_back(u);
}

int main(){
    cin >> n;
    cin.ignore();
    string line;
    while(n--){
        getline(cin, line);
        stringstream ss(line);
        string a, b;
        ss >> a;
        a = a.substr(0, a.size()-1);
        while(ss >> b)
            adj[b].push_back(a);
    }
    cin >> line;
    dfs(line);
    for(int i = order.size() - 1; i >= 0; i--)
        cout << order[i] << endl;   
}