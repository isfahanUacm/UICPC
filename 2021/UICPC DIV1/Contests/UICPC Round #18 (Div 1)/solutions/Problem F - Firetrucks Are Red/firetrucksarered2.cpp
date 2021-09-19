#include <bits/stdc++.h>
using namespace std;

// Firetrucks Are Red

const int maxn = 2e5;

int n, cnt, par[maxn + 3], ran[maxn + 3];
map<int, vector<int>> people;
vector<pair<pair<int, int>, int>> ans;

int ufind(int u){
    return (par[u] == u) ? u : (par[u] = ufind(par[u]));
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
    cin >> n;
    cnt = n;
    iota(par, par + n, 0);
    fill_n(ran, n, 0);
    for(int i = 0; i < n; i++){
        int m, x;
        cin >> m;
        while(m--)
            cin >> x, people[x].push_back(i);
    }
    for(auto e : people){
        if(cnt == 1)
            break;
        for(int i = 0; i < e.second.size() - 1; i++){
            if(cnt == 1)
                break;
            if(umerge(e.second[i], e.second[i + 1]))
                    ans.push_back({{e.second[i], e.second[i + 1]}, e.first});
        }
    }
    if(cnt != 1)
        cout << "impossible" << endl;
    else for(auto e : ans)
            cout << e.first.first + 1 << " " << e.first.second + 1<< " " << e.second << endl;
}