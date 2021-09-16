#include <bits/stdc++.h>
using namespace std;

bool parent[101];
set<int> nodes;
vector<vector<int>> adj(101, vector<int>());
vector<int> res;
int target;

bool dfs(int a){
    if(a==target)
        return true;
    for(auto b : adj[a])
        if(dfs(b)){
            res.push_back(b);
            return true;
        }
    return false;
}


int main()
{
    fill_n(parent, 101, false);
    int source = 0;
    string inp, aa;
    cin>>target;
    vector<int> v;
    cin.ignore();
    while(getline(cin, inp)){
        if(inp=="-1")break;
        istringstream ss(inp);
        v.clear();
        while(getline(ss, aa, ' '))
            v.push_back(stoi(aa));
        nodes.insert(v[0]);
        for (int i = 1; i < v.size(); ++i)
            nodes.insert(v[i]), parent[v[i]] = true, adj[v[0]].push_back(v[i]);
    }
    for(auto a: nodes)
        if(!parent[a])
            source = a;
    dfs(source);
    res.push_back(source);
    for (int i = 0; i < res.size(); ++i)
        cout<<res[i]<<((i==res.size()-1)?"\n":" ");
    
    return 0;
}

