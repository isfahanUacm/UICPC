#include <bits/stdc++.h>
using namespace std;

// Arriving on Time

const int maxn = 1e5 + 3;

struct edge {
    int v, t0, p, d;
    edge(int v, int t0, int p, int d){
        this->v = v;
        this->t0 = t0;
        this->p = p;
        this->d = d;
    }
};

int n, m, s;
vector<edge> adj[maxn];
long long int sp[maxn];
priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> dij; 


bool judge(long long int t){
    fill_n(sp, n, LLONG_MAX);
    sp[0] = t;
    dij.push({t, 0});
    while(!dij.empty()){
        long long int w = dij.top().first;
        int u = dij.top().second;
        dij.pop();
        if(sp[u] < w)
            continue;
        for(auto v: adj[u]){
            long long int cost = (w - v.t0) / v.p + (((w - v.t0) % v.p) ? 1 : 0);
            cost = max(cost, 0ll);
            cost = cost * v.p + v.t0;
            cost += v.d;
            if(cost < sp[v.v]){
                sp[v.v] = cost;
                dij.push({cost, v.v});
            }
        }
    }
    return sp[n-1] <= (long long int)s;
}

int main(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int u, v, t0, p, d;
        cin >> u >> v >> t0 >> p >> d;
        adj[u].push_back(edge(v, t0, p, d));
    }
    if(!judge(0)){
        cout << "impossible" << endl;
        return 0;
    }
    int lo = 0, hi = s;
    while(lo < hi){
        int mid = (lo + hi) / 2 + (lo + hi) % 2;
        if (judge(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    cout << lo << endl;
}