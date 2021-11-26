#include <bits/stdc++.h>
using namespace std;

// Passing Secrets

const int maxn = 5e3 + 3;
const int inf = INT_MAX;

string a, b, s, x;
int n, src, dst, dis[maxn], par[maxn];
vector<pair<int, int>> adj[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij;

map<string, int> id;
string names[maxn];
int cnt;
int gid(string name){
    if(id.find(name) != id.end())
        return id[name];
    names[cnt] = name;
    return id[name] = cnt++;
}

vector<int> group;

int main(){
    while(cin >> a >> b){
        cin >> n;
        cin.ignore();
        for(int i = 0; i < maxn; i++)
            adj[i].clear();
        id.clear();
        cnt = 0;
        while(n--){
            getline(cin, s);
            stringstream ss(s);
            group.clear();
            while(ss >> x)
                group.push_back(gid(x));
            for(int i = 0; i < group.size(); i++)
                for(int j = 0; j < group.size(); j++)
                    if(i != j)
                        adj[group[i]].push_back({group[j], group.size() - 1});
        }
        n = cnt;
        if(id.find(a) == id.end() || id.find(b) == id.end()){
            cout << "impossible" << endl;
            continue;
        }
        src = id[a], dst = id[b];
        fill_n(dis, n, inf), fill_n(par, n, -1);
        dis[src] = 0;
        dij.push({0, src});
        while(!dij.empty()){
            int u = dij.top().second, w = dij.top().first;
            dij.pop();
            if(dis[u] < w)
                continue;
            for(pair<int, int> v : adj[u])
                if(w + v.second < dis[v.first])
                    dis[v.first] = w + v.second, par[v.first] = u, dij.push({dis[v.first], v.first});
        }
        if(dis[dst] == inf){
            cout << "impossible" << endl;
            continue;
        }
        group.clear();
        int it = dst;
        while(it != -1)
            group.push_back(it), it = par[it];
        cout << dis[dst] - 1 << " ";
        for(int i = group.size() - 1; i >= 0; i--)
            cout << names[group[i]] << " ";
        cout << endl;
    }
}