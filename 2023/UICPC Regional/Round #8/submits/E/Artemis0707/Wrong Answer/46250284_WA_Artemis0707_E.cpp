#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<string> f1;
set<string> f2;

vector<pair<ll,ll>> adj1[100000 + 1];
vector<pair<ll,ll>> adj2[100000 + 1];
ll visited1[100000 + 1];
ll visited2[100000 + 1];
ll m1,n1,k1,m2,n2,k2;
void dfs1(ll u, string s){
    if(u == n1-1){
        f1.insert(s);
        return;
    }
    visited1[u] = 1;
    for(ll i=0;i<adj1[u].size();i++){
        if(adj1[u][i].first == u && visited1[adj1[u][i].first] == 1){
                visited1[adj1[u][i].first] = 2;
    
                s += (to_string(adj1[u][i].second) + '*');
            }
        else if(visited1[adj1[u][i].first] == 0){
            dfs1(adj1[u][i].first, s + to_string(adj1[u][i].second));
        }
    }
    
}
void dfs2(ll u, string s){
    if(u == n2-1){
        f2.insert(s);
        return;
    }
    visited2[u] = 1;
    for(ll i=0;i<adj2[u].size();i++){
        if(adj2[u][i].first == u && visited2[adj2[u][i].first] == 1){
                visited2[adj2[u][i].first] = 2;
                s += (to_string(adj2[u][i].second) + '*');
            }
        else if(visited2[adj2[u][i].first] == 0){
            dfs2(adj2[u][i].first, s + to_string(adj2[u][i].second));
        }
    }
    
}
int main(){
    ll t;
    cin >> t;
    while (t--){
        f1.clear();
        f2.clear();
        cin >> m1 >> n1 >> k1 >> m2 >> n2 >> k2;
        for(ll i=0;i<n1;i++){
            adj1[i].clear();
            visited1[i] = 0;
        }
        for(ll i=0;i<n2;i++){
            adj2[i].clear();
            visited2[i] = 0;
        }
        for(ll i=0;i<m1;i++){
            ll t1, t2, s;
            cin >> t1 >> t2 >> s;
            adj1[t1].push_back({t2,s});
        }
        for(ll i=0;i<m2;i++){
            ll t1, t2, s;
            cin >> t1 >> t2 >> s;
            adj2[t1].push_back({t2,s});
        }
        dfs1(0,"");
        dfs2(0,"");
        bool eq = true;
        if(f1.size() != f2.size()){
            eq = false;
        }
        else{
            for(auto it1 = f1.begin(), it2 = f2.begin(); it1 != f1.end(); it1++, it2++){
                cerr << *it1 << " " << *it2 << endl;
                if(*it1 != *it2){
                    eq = false;
                    break;
                }
            }
        }

        if(eq){
            cout << "eligible" << endl;
        }
        else{
            cout << "not eligible" << endl;
        }

        
    }

    return 0;
}