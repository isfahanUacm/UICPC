#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
long long int res;
set<int> adj[130];
bool flag;

void bronKerbosch(set<int>& P, set<int>& R, set<int>& X){
    set<int> PUX;
    auto it = set_union(P.begin(), P.end(), X.begin(), X.end(), inserter(PUX,PUX.begin()));
    if(PUX.size() == 0){
        res++;
        if(res>1000){
            flag = true;
            return;
        }
    }
    int u = *(PUX.begin()), ux = 0;
    for(auto a : PUX){
//        cerr << "a: " << a << endl;
        set<int> tmp;
        auto itt = set_intersection(P.begin(), P.end(), adj[a].begin(), adj[a].end(), inserter(tmp,tmp.begin()));
        if(ux < tmp.size()){
            ux = tmp.size();
            u = a;
        }
    }
//    cerr << "u: " << u << endl;
    set<int> tmpp;
    for (auto vv: P) {
        if(adj[u].find(vv)==adj[u].end())
            tmpp.insert(vv);
    }
    for (auto vert : tmpp){
        set<int> newp, newr, newx, v;
        v.insert(vert);
        
        auto it1 = set_intersection(P.begin(), P.end(), adj[vert].begin(), adj[vert].end(), inserter(newp,newp.begin()));
        auto it2 = set_union(R.begin(), R.end(), v.begin(), v.end(), inserter(newr,newr.begin()));
        auto it3 = set_intersection(X.begin(), X.end(), adj[vert].begin(), adj[vert].end(), inserter(newx,newx.begin()));
        bronKerbosch(newp, newr, newx);
        if(flag)
            return;
        P.erase(find(P.begin(), P.end(), vert));
        X.insert(vert);
    }
}

int main()
{
    while(cin >> n >> m){
        flag = false;
        for (int i = 0; i < n; ++i) {
            adj[i+1].clear();
        }
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        res = 0;
        set<int> p, r, x;
        for (int i = 0; i < n; ++i) {
            p.insert(i+1);
        }
        bronKerbosch(p, r, x);
        if(flag){
            cout << "Too many maximal sets of friends." << endl;
        }
        else{
            cout << res << endl;
        }
    }
    
    return 0;
}
