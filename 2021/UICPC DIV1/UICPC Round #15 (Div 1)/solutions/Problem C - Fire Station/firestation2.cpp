#include <bits/stdc++.h>
using namespace std;

// Fire Station

#define inf INT_MAX

int f, n, fst[503], x, y, w, dis[503];
vector<pair<int, int>> adj[503];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij;
string line;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> f >> n;
        for(int i = 0; i < n; i++)
            adj[i].clear();
        fill_n(fst, n, 0);
        for(int i = 0; i < f; i++)
            cin >> x, x--, fst[x] = 1;
        cin.ignore();
        while(getline(cin, line) && line.size()){
            stringstream ss(line);
            ss >> x >> y >> w, x--, y--;
            adj[x].push_back({y, w}), adj[y].push_back({x, w});
        }
        int ans = INT_MAX, fans = 0;
        for(int nf = 0; nf < n; nf++)
            if(!fst[nf]){
                fill_n(dis, n, inf);
                for(int fs = 0; fs < n; fs++)
                    if(fst[fs])
                        dis[fs] = 0, dij.push({0, fs});
                dis[nf] = 0;
                dij.push({0, nf});
                int curr = 0;
                while(!dij.empty()){
                    int u = dij.top().second, w = dij.top().first;
                    dij.pop();
                    if(dis[u] < w)
                        continue;
                    curr = max(curr, w);
                    for(pair<int, int> v : adj[u])
                        if(w + v.second < dis[v.first])
                            dis[v.first] = w + v.second, dij.push({dis[v.first], v.first});
                }
                if(curr < ans)
                    ans = curr, fans = nf;
            }
        cout << fans + 1 << endl;
    }
}