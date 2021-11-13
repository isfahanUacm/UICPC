#include <bits/stdc++.h>
using namespace std;

// Arctic Network

int d, n, cnt, x[503], y[503], par[503], ran[503];

inline double dist(int i, int j){
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
}

vector<pair<double, pair<int, int>>> edges;

int ufind(int u){
    return (u == par[u]) ? u : (par[u] = ufind(par[u]));
}

bool umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return false;
    cnt--;
    if(ran[i] > ran[j])
        par[j] = i;
    else{
        par[i] = j;
        if(ran[i] == ran[j])
            ran[j]++;
    }
    return true;
}

int main(){
    cout << fixed << setprecision(2);
    int t;
    cin >> t;
    while(t--){
        cin >> d >> n;
        cnt = n;
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        iota(par, par + n, 0);
        fill_n(ran, n, 0);
        edges.clear();
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                edges.push_back({dist(i, j), {i, j}});
        sort(edges.begin(), edges.end());
        double ans = 0;
        for(auto e : edges){
            if(cnt == d)
                    break;
            if(umerge(e.second.first, e.second.second))
                ans = max(ans, e.first);
        }
        cout << ans << endl;
    }
}