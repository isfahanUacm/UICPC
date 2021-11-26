#include <bits/stdc++.h>
using namespace std;

// Erratic Ants

map<char, int> adjR{{'S', 1}, {'N', -1}, {'E', 0}, {'W', 0}};
map<char, int> adjC{{'S', 0}, {'N', 0}, {'E', 1}, {'W', -1}};
map<pair<int, int>, vector<pair<int, int>>> adj;
map<pair<int, int>, int> dis;
queue<pair<int, int>> bfs;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        adj.clear();
        dis.clear();
        int x = 0, y = 0;
        char d;
        while(n--){
            cin >> d;
            int u = x + adjR[d], v = y + adjC[d];
            adj[{x, y}].push_back({u, v});
            adj[{u, v}].push_back({x, y});
            x = u, y = v; 
        }
        dis[{0, 0}] = 0;
        bfs.push({0, 0});
        while(!bfs.empty()){
            pair<int, int> uv = bfs.front();
            bfs.pop();
            for(pair<int, int> pq : adj[uv])
                if(dis.find(pq) == dis.end()){
                    dis[pq] = dis[uv] + 1;
                    bfs.push(pq);
                }
        }
        cout << dis[{x, y}] << endl;
    }
}