#include <bits/stdc++.h>
using namespace std;

// Eulerian Path

const int maxn = 1e4 + 3;

int n, m, indeg[maxn], outdeg[maxn];
vector<pair<int, bool>> adj[maxn];

vector<int> euler;

void dfs(int u){
    for(pair<int, bool>& v : adj[u])
        if(v.second)
            v.second = 0, dfs(v.first);
    euler.push_back(u);
}

int main(){
    while(1){
        cin >> n >> m;
        if(!(n + m))
            break;
        for(int i = 0; i < n; i++)
            indeg[i] = outdeg[i] = 0, adj[i].clear();
        int x, y;
        while(m--)
            cin >> x >> y, indeg[y]++, outdeg[x]++, adj[x].push_back({y, 1});
        euler.clear();
        bool tour = true;
        for(int i = 0; i < n; i++)
            if(indeg[i] != outdeg[i]){
                tour = false;
                break;
            }
        if(tour){
            for(int i = 0; i < n; i++)
                if(outdeg[i] >= 1){
                    dfs(i);
                    break;
                }
            bool valid = true;
            for(int i = 0; i < n; i++)
                for(pair<int, bool> v : adj[i])
                    if(v.second){
                        valid = false;
                        break;
                    }
            if(!valid){
                cout << "Impossible" << endl;
                continue;
            }
            for(int i = euler.size() - 1; i >= 0; i--)
                cout << euler[i] << " ";
            cout << endl;
            continue;
        }
        int s = -1;
        for(int i = 0; i < n; i++)
            if(outdeg[i] == indeg[i] + 1){
                s = i;
                break;
            }
        if(s == -1){
            cout << "Impossible" << endl;
            continue;
        }
        int e = -1;
        for(int i = 0; i < n; i++)
            if(indeg[i] == outdeg[i] + 1){
                e = i;
                break;
            }
        if(e == -1){
            cout << "Impossible" << endl;
            continue;
        }
        bool path = true;
        for(int i = 0; i < n; i++)
            if(i != s && i != e && indeg[i] != outdeg[i]){
                path = false;
                break;
            }
        if(path){
            dfs(s);
            bool valid = true;
            for(int i = 0; i < n; i++)
                for(pair<int, bool> v : adj[i])
                    if(v.second){
                        valid = false;
                        break;
                    }
            if(!valid){
                cout << "Impossible" << endl;
                continue;
            }
            for(int i = euler.size() - 1; i >= 0; i--)
                cout << euler[i] << " ";
            cout << endl;
            continue;
        }
        cout << "Impossible" << endl;
    }
}