#include <bits/stdc++.h>
using namespace std;

// Conservation

int n, m;
int lab[100003];
int cnt[100003];
int indeg[100003];
vector<int> adj[100003];
queue<int> a, b;

inline void push(int i){
    if(lab[i] == 1)
        a.push(i);
    else b.push(i);
}

int solve(int turn){
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(!indeg[i])
            push(i);
    while(!a.empty() || !b.empty()){
        if(turn == 1 && a.empty())
            turn = 2, ans++;
        else if(turn == 2 && b.empty())
            turn = 1, ans++;
        int u;
        if(turn == 1){
            u = a.front();
            a.pop();
        }
        else{
            u = b.front();
            b.pop();
        }
        for(int v : adj[u]){
            indeg[v]--;
            if(!indeg[v])
                push(v);
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> lab[i];
        for(int i = 0; i < n; i++)
            adj[i].clear();
        fill_n(cnt, n, 0);
        int x, y;
        while(m--)
            cin >> x >> y, adj[x-1].push_back(y-1), cnt[y-1]++;
        copy_n(cnt, n, indeg);
        int ans = solve(1);
        copy_n(cnt, n, indeg);
        ans = min(ans, solve(2));
        cout << ans << endl;
    }
}