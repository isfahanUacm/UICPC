#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
string nodes[20003];
vector<vector<int>> adj;
int dnum[20003], dlow[20003];
bool visited[20003];
int n, a, b, nums = 0, scc=0;
string sa, sb;
vector<vector<string>> okayres;
vector<string> avoid;
vector<int> s;

void tarjan(int u){
    dnum[u] = dlow[u] = nums++;
    visited[u] = true; s.push_back(u);
    for (auto v : adj[u]) {
        if(dnum[v] == -1){
            tarjan(v);
        }
        if(visited[v]){
            dlow[u] = min(dlow[u], dlow[v]);
        }
    }
    if(dnum[u] == dlow[u]){
        int w;
        vector<string> vv;
        while(true){
            w = s.back();
            s.pop_back();
            visited[w] = false;
            vv.push_back(nodes[w]);
            if(u==w)break;
        }
        if(vv.size()>=2)
            okayres.push_back(vv);
        else
            avoid.push_back(vv[0]);
        scc++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    cin>>n;
//    if(n==0)
//        cout<<endl;
//        return 0;
    int j = 0;
    adj.clear();adj.resize(20003);
    for (int i = 0; i < n; ++i) {
        cin>>sa>>sb;
        if(mp.find(sa)==mp.end()){
            nodes[j] = sa;
            mp[sa] = j++;
        }
        if(mp.find(sb)==mp.end()){
            nodes[j] = sb;
            mp[sb] = j++;
        }
        adj[mp[sa]].push_back(mp[sb]);
    }
    fill_n(dnum, j, -1);fill_n(dlow, j, -1);
    fill_n(visited, j, false);
    nums = 0;scc=0;
    for (int i = 0; i < j; ++i)
        if(dnum[i] == -1)
            tarjan(i);
    for (int i = 0; i < okayres.size(); ++i) {
        sort(okayres[i].begin(), okayres[i].end());
    }
    sort(okayres.begin(), okayres.end());
    for (int i = 0; i < okayres.size(); ++i) {
        cout<<"okay";
        for(auto it : okayres[i]){
            cout<<" "<<it;
        }
        cout<<endl;
    }
    sort(avoid.begin(), avoid.end());
    if(avoid.size()){
        cout<<"avoid";
        for(auto it : avoid){
            cout<<" "<<it;
        }
        cout<<endl;
    }
    return 0;
}

