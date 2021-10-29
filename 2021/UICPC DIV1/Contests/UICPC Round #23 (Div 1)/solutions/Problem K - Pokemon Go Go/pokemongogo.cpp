#include <bits/stdc++.h>
using namespace std;

// Pokemon Go Go

#define num long long int

int n = 0;
map<string, int> m;
inline int id(string s){
    if(m.find(s) != m.end())
        return m[s];
    return m[s] = n++;
}

pair<int, int> nodes[23];
vector<int> pokemons[18];
int np[23];

inline num dist(int i, int j){
    return abs(nodes[i].first-nodes[j].first) + abs(nodes[i].second-nodes[j].second);
}

num dp[(1<<15)+3][23];

num cdp(int mask, int node){
    if(dp[mask][node] != -1)
        return dp[mask][node];
    int cnt = 0;
    for(int j = 0; j < n; j++)
        if(mask & (1<<j))
            cnt++;
    if(cnt == 1)
        return dp[mask][node] = dist(0, node);
    num ans = LLONG_MAX;
    int pokeid = np[node];    
    for(int j = 0; j < n; j++)
        if(j != pokeid && (mask & (1<<j)))
            for(int prev : pokemons[j])
                ans = min(ans, cdp(mask - (1<<pokeid), prev) + dist(prev, node));
    return dp[mask][node] = ans;
}

int main(){
    int m;
    string pokemon;
    cin >> m;
    nodes[0] = {0, 0};
    for(int i = 1; i <= m; i++){
        cin >> nodes[i].first >> nodes[i].second >> pokemon;
        int pokeid = id(pokemon);
        np[i] = pokeid;
        pokemons[pokeid].push_back(i);
    }
    for(int i = 0; i < (1<<15)+3; i++)
        for(int j = 0; j < 23; j++)
            dp[i][j] = -1;
    num ans = LLONG_MAX;
    for(int i = 1; i <= m; i++)
        ans = min(ans, cdp((1<<n)-1, i) + dist(i, 0));
    cout << ans << endl;
}