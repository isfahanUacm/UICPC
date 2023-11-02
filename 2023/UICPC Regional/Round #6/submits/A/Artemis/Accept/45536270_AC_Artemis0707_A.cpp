#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n,m;
map<string, bool> vis;
map<string, vector<string>> adj;
map<string, double> blood;
string founder;
vector<string> tp_sort;

void topological_sort(string u){
    vis[u] = true;
    for(auto v: adj[u]){
        if(!vis[v]){
            topological_sort(v);
        }
    }
    tp_sort.push_back(u);
}

int main(){

    cin >> n >> m;
    cin >> founder;
    vector<string> cand(m);
    for(ll i=0;i<n;i++){
        string a,b,c;
        cin >> a >> b >> c;
        adj[c].push_back(a);
        adj[b].push_back(a);
    }
    for(ll i=0;i<m;i++){
        cin >> cand[i];
    }
    blood[founder] = 1;
    topological_sort(founder);
    reverse(tp_sort.begin(), tp_sort.end());
    for(auto u:tp_sort){
        for(auto v:adj[u]){
            blood[v] += blood[u]/2;
        }
    }

    string ans = cand[0];
    for(auto u:cand){
        if(blood[u] > blood[ans]){
            ans = u;
        }
    }
    cout << ans << endl;


    return 0;
}