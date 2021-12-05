#include <bits/stdc++.h>
using namespace std;

map<string, int> s_to_a;
string a_to_s[5003];
vector<vector<int>> adj(5003);
int visited[5003];
int n; bool cycle = false;

void dfs(int u){
    visited[u] = 1;
    for (auto v : adj[u]) {
        if(!visited[v]){
            dfs(v);
            if(cycle)
                return;
        }
        else if(visited[v]==1){
            cycle = true;
            return;
        }
    }
    visited[u]=2;
}

int main()
{
    string a, b;
    cin>>n;
    fill_n(visited, 5003, 0);
    int j = 1;
    for (int i = 0; i < n; ++i) {
        cin>>a>>b;
        if(s_to_a.find(a)==s_to_a.end()){
            a_to_s[j] = a;
            s_to_a[a] = j++;
        }
        if(s_to_a.find(b)==s_to_a.end()){
            a_to_s[j] = b;
            s_to_a[b] = j++;
        }
        adj[s_to_a[a]].push_back(s_to_a[b]);
    }
    
    while(cin>>a){
        cycle = false;
        fill_n(visited, 5003, 0);
        dfs(s_to_a[a]);
        cout<<a<<" "<<((cycle)?"safe":"trapped")<<endl;
    }
    return 0;
}

