#include <bits/stdc++.h>
using namespace std;

int dist[503];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int F, I, a, b, c;
bool stations[503];
vector<int>stvec;
vector<pair<int, int>>adj[503];
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>F>>I;
        stvec.clear();
        fill_n(dist, I, INT_MAX);
        fill_n(stations, I, false);
        for (int i = 0; i < I; ++i) {
            adj[i].clear();
        }
        for (int i = 0; i < F; ++i) {
            cin>>a;a--;
            if(!stations[a]){
                stations[a]=true;
                stvec.push_back(a);
            }
        }
        string str; getline(cin, str);
        while (getline(cin, str) && !str.empty()) {
            stringstream ss(str);
            ss>>a>>b>>c;a--;b--;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        pair<int, int> p;
        int res=INT_MAX, resi;
        for (int i = 0; i < I; ++i) {
            //if(stations[i])continue;
            fill_n(dist, I, INT_MAX);
            for (auto station: stvec) {
                dist[station] = 0;
                pq.push({0, station});
            }
            dist[i] = 0;
            pq.push({0, i});
            while(!pq.empty()){
                p = pq.top();pq.pop();
                if(p.first>dist[p.second])
                    continue;
                for (auto v: adj[p.second]) {
                    if(dist[v.first]>dist[p.second]+v.second){
                        dist[v.first]=dist[p.second]+v.second;
                        pq.push({dist[v.first], v.first});
                    }
                }
            }
            int mx=-1;
            for (int j = 0; j < I; ++j) {
                mx = max(mx, dist[j]);
            }
            if(res>mx){
                res = mx;
                resi = i+1;
            }
        }
        cout<<resi<<endl;
        if(t)
            cout<<endl;
    }
    return 0;
}

