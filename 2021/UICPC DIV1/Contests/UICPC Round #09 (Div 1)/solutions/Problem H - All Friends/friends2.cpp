#include <bits/stdc++.h>
using namespace std;

// All Friends

const int maxn = 133;

int n, m, deg[maxn];
set<int> adj[maxn];
set<int> R, P, X;
long long int ans;

void bron(){
    if(ans > 1000)
        return;
    if(P.empty() && X.empty()){
        ans++;
        return;
    }
    int u, degm = -1;
    for(int cand : P)
        if(deg[cand] > degm)
            u = cand, degm = deg[cand];
    for(int cand : X)
        if(deg[cand] > degm)
            u = cand, degm = deg[cand];
    set<int> PP = P;
    for(int nu : adj[u])
        PP.erase(nu);
    for(int v : PP){
        set<int> cR = R, cP = P, cX = X;
        R.insert(v);
        P.clear();
        X.clear();
        for(int nv : adj[v]){
            if(cP.find(nv) != cP.end())
                P.insert(nv);
            if(cX.find(nv) != cX.end())
                X.insert(nv);
        }
        bron();
        if(ans > 1000)
            return;
        R = cR, P = cP, X = cX;
        P.erase(v);
        X.insert(v);
    }
}

int main(){
    while(scanf("%d %d", &n, &m) == 2){
        for(int i = 0; i < n; i++)
            adj[i].clear();
        int u, v;
        while(m--)
            scanf("%d %d", &u, &v), adj[u-1].insert(v-1), adj[v-1].insert(u-1);
        R.clear();
        P.clear();
        X.clear();
        for(int i = 0; i < n; i++)
            deg[i] = adj[i].size(), P.insert(i);
        ans = 0;
        bron();
        if(ans > 1000)
            printf("Too many maximal sets of friends.\n");
        else
            printf("%lld\n", ans);
    }
}
