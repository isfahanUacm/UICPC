#include <bits/stdc++.h>
using namespace std;

// Getting Through

struct sensor{
    double x, y, r;
};

double w;
int n;
sensor a[1003];

vector<int> adj[1003];
bool vis[1003];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

// build a graph, assume two nodes for walls and n nodes for circles, check connectivity of walls
// check for every two node that can we pass a circle with radius=r through them or not

bool judge(double r){
    if(r == 0)
        return true;
    for(int i = 0; i < n + 2; i++)
        adj[i].clear();
    fill_n(vis, n + 2, false);
    if(w < 2 * r)
        adj[0].push_back(1), adj[1].push_back(0);
    for(int i = 2; i < n + 2; i++)
        if(a[i].x - a[i].r < 2 * r) 
            adj[0].push_back(i), adj[i].push_back(0);
    for(int i = 2; i < n + 2; i++)
        if(w - (a[i].x + a[i].r) < 2 * r) 
            adj[1].push_back(i), adj[i].push_back(1);
    for(int i = 2; i < n + 2; i++)
        for(int j = i + 1; j < n + 2; j++){
            double deltax = a[i].x - a[j].x, deltay = a[i].y - a[j].y;
            double d = sqrt(deltax * deltax + deltay * deltay);
            if(d - (a[i].r + a[j].r) < 2 * r)
                adj[i].push_back(j), adj[j].push_back(i);
        }
    dfs(0);
    return !vis[1];
}


int main(){
    cout << fixed << setprecision(6);
    int t;
    cin >> t;
    while(t--){
        cin >> w >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i+2].x >> a[i+2].y >> a[i+2].r;
        double lo = 0, hi = 1e5;
        while(fabs(hi - lo) > 1e-9){
            double mid = (lo + hi) / 2;
            if(judge(mid))
                lo = mid;
            else hi = mid;
        }
        cout << lo << endl;
    }
}