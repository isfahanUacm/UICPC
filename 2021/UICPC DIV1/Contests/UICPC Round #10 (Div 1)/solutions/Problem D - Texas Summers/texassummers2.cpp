#include <bits/stdc++.h>
using namespace std;

// Texas Summers

#define inf INT_MAX

int n, x[2503], y[2503], dis[2503], par[2503];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij;
vector<int> path;

int main(){
    cin >> n, n += 2;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    fill_n(dis, n, inf);
    fill_n(par, n, -1);
    dis[n-2] = 0;
    dij.push({0, n-2});
    while(!dij.empty()){
        int w = dij.top().first, u = dij.top().second;
        dij.pop();
        if(dis[u] < w)
            continue;
        for(int v = 0; v < n; v++){
            int dx = x[u] - x[v], dy = y[u] - y[v];
            int c = dx * dx + dy * dy;
            if(w + c < dis[v])
                dis[v] = w + c, par[v] = u, dij.push({dis[v], v});
        }
    }
    int it = par[n-1];
    while(it != n-2)
        path.push_back(it), it = par[it];
    if(path.empty())
        cout << "-" << endl;
    else for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << endl;
}