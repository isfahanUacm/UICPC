#include <bits/stdc++.h>
using namespace std;

// Through the Grapevine

int n, m, d, t[100003], dis[100003];
map<string, int> id;
vector<int> adj[100003];
queue<int> kahn;
set<int> heard;

int main(){
    cin >> n >> m >> d;
    string name;
    for(int i = 0; i < n; i++)
        cin >> name >> t[i], id[name] = i;
    string x, y;
    while(m--)
        cin >> x >> y, adj[id[x]].push_back(id[y]), adj[id[y]].push_back(id[x]);
    fill_n(dis, n, INT_MAX);
    cin >> x;
    if(d >= 1)
        dis[id[x]] = 1, kahn.push(id[x]);
    while(!kahn.empty()){
        int u = kahn.front();
        kahn.pop();
        for(int v : adj[u])
            if(dis[v] == INT_MAX){
                t[v]--;
                heard.insert(v);
                if(!t[v]){
                    dis[v] = dis[u] + 1;
                    if(dis[v] <= d)
                        kahn.push(v);
                }
            }
    }
    cout << heard.size() << endl;
}