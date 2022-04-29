#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX

int n, d, a1, a2;
struct state{
    int node, a;
    bool box;

    bool operator<(const state & o) const{
        return this->a < o.a;
    }
};
vector<pair<pair<int, int>, int>> adjs[1003];
priority_queue<pair<int, state>, vector<pair<int, state>>, greater<pair<int, state>>> pq;
int dis[1003][363][2 + 3];

int mat[1003][1003];

int main(){
    cin >> n >> d >> a1 >> a2;
    d--;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        while(x--){
            int v, t, deg;
            cin >> v >> t >> deg;
            v--;
            adjs[i].push_back({{t, deg}, v});
            mat[i][v] = deg;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 360; j++)
            for(int k = 0; k < 2; k++)
                dis[i][j][k] = inf;
    for(int i = 0; i < 360; i++){
        state st;
        st.a = i, st.box = (d == 0), st.node = 0;
        dis[0][i][(d == 0)] = 0, pq.push({0, st}); 
    }
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int w = p.first;
        state st = p.second;
        if(dis[st.node][st.a][st.box] < w)
            continue;
        for(auto x : adjs[st.node]){
            int v = x.second, t = x.first.first, deg = x.first.second;
            int at1 = (deg - st.a + 360) % 360, at2 = 360 - at1;
            if(at1 <= a1 || at2 <= a2){
                int deg2 = (mat[v][st.node] + 180) % 360;
                if(dis[v][deg2][((v == d) || st.box)] > w + t){
                    state st2;
                    st2.a = deg2, st2.box = ((v == d) || st.box), st2.node = v;
                    dis[v][deg2][((v == d) || st.box)] = w + t, pq.push({w + t, st2});
                }
            }
        }
    }
    int ans = inf;
    for(int i = 0; i < 360; i++)
        ans = min(ans, dis[0][i][1]);
    if(ans != inf)
        cout << ans << endl << endl;
    else
        cout << "impossible" << endl << endl;
}
