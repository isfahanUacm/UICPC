#include <bits/stdc++.h>
using namespace std;

int N, L, B, s, d, a, b, X, Y;
vector<vector<pair<int,pair<int,int>>>> adj(1003);
bool vis[1003];
set<int> v;
set<int>ss;
int l, r, res=0;
bool dfs(int u){
    vis[u] = true;
    if(u==d)
        return true;
    for (auto a: adj[u]) {
        if(!vis[a.first] && l>=a.second.first && r<=a.second.second){
            if(dfs(a.first))
                return true;
        }
    }
    return false;
}

int main()
{
    cin>>N>>L>>B>>s>>d;
    for (int i = 0; i < L; ++i) {
        cin>>a>>b>>X>>Y;
        adj[a].push_back({b,{X, Y}});
        v.insert(X);v.insert(Y);
    }
    auto endd = v.end();endd--;
    auto it=v.begin();
    bool flag = false;
    while(true){
        l = *it; r = l;
        fill_n(vis, N+1, false);
        if(dfs(s)){
            res += r-l;
            if(!flag)
                res++;
//            cout<<l<<" "<<r<<res<<endl;
            flag = true;
        }else flag = false;
        it++;
        if(it==v.end())
            break;
        r = *it;
        fill_n(vis, N+1, false);
        if(dfs(s)){
            res += r-l;
            if(!flag)
                res++;
            flag = true;
        }else flag = false;
    }
    cout<<res<<endl;
    return 0;
}
