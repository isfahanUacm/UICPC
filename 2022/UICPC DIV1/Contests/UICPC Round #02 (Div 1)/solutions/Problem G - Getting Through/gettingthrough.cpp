#include <bits/stdc++.h>
using namespace std;

#define prec 0.0000001

struct circle{
    double x, y, r;
};

int n;
double w;
circle a[1003];

vector<int> adj[1003];
bool vis[1003];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

bool judge(double k){
    for(int i = 0; i < n + 2; i++)
        adj[i].clear();
    fill_n(vis, n+2, false);
    for(int i = 2; i < n + 2; i++)
        if(a[i].x - (a[i].r+2*k) <= 0)
            adj[0].push_back(i), adj[i].push_back(0);
    for(int i = 2; i < n + 2; i++)
        if(a[i].x + (a[i].r+2*k) >= w)
            adj[1].push_back(i), adj[i].push_back(1);
    for(int i = 2; i < n + 2; i++)
        for(int j = i + 1; j < n + 2; j++){
            double deltax = a[i].x - a[j].x, deltay = a[i].y - a[j].y;
            if(deltax * deltax + deltay * deltay <= (a[i].r + a[j].r + 2*k) * (a[i].r + a[j].r+2*k))
                adj[i].push_back(j), adj[j].push_back(i);
        }
    dfs(0);
    return !vis[1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin >> w >> n;
        if(n==0){   
            cout<<w/2<<endl;
            continue;
        }
        for(int i = 0; i < n; i++)
            cin >> a[i+2].x >> a[i+2].y >> a[i+2].r;
        double lo = 0, hi = w;
        while(hi-lo>prec){
            double mid = (lo + hi) / 2;//cout<<mid<<endl;
            if(judge(mid))
                lo = mid;
            else hi = mid;
        }
        cout << fixed << setprecision(7) << lo << endl;
    }
}
