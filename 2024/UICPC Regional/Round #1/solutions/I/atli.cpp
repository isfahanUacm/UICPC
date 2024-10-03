#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, u, v; cin >> n >> m;
    vvi g(n, vi());
    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    vi red, blue;
    set<int> todo;
    for(int i = 1; i < n; ++i) todo.insert(i);
    if(g[0].size() > 0) {
        red.push_back(g[0][0]);
        todo.erase(g[0][0]);
    } else {
        blue.push_back(1);
        todo.erase(1);
    }
    while(todo.size() > 0) {
        while(red.size() > 0) {
            int cur = red.back();
            for(int x : g[cur]) {
                if(todo.count(x)) {
                    red.push_back(x);
                    todo.erase(x);
                    break;
                }
            }
            if(cur == red.back()) break;
        }
        if(todo.empty()) break;
        if(blue.empty()) {
            blue.push_back(*todo.begin());
            todo.erase(todo.begin());
        }
        while(blue.size() > 0) {
            int cur = blue.back();
            for(int x : todo) {
                auto it = lower_bound(g[cur].begin(), g[cur].end(), x);
                if(it == g[cur].end() || *it != x) {
                    blue.push_back(x);
                    todo.erase(x);
                    break;
                }
            }
            if(cur == blue.back()) break;
        }
        if(todo.empty()) break;
        if(red.empty()) {
            red.push_back(*todo.begin());
            todo.erase(todo.begin());
        }
        int rlst = red.back(), blst = blue.back();
        auto it = lower_bound(g[rlst].begin(), g[rlst].end(), blst);
        bool conn = it != g[rlst].end() && *it == blst;
        if(conn) {
            red.push_back(blue.back());
            blue.pop_back();
        } else {
            blue.push_back(red.back());
            red.pop_back();
        }
    }
    cout << "1 ";
    if(red.empty()) {
        for(int x : blue) cout << x + 1 << ' ';
    } else {
        auto it = lower_bound(g[0].begin(), g[0].end(), red[0]);
        if(it != g[0].end() && *it == red[0]) {
            for(int x : red) cout << x + 1 << ' ';
            for(int x : blue) cout << x + 1 << ' ';
        } else {
            for(int x : blue) cout << x + 1 << ' ';
            for(int x : red) cout << x + 1 << ' ';
        }
    }
    cout << '\n';
}
