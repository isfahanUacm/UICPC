#include <bits/stdc++.h>
using namespace std;

// Joint Excavation

const int maxn = 2e5 + 3;

int n, m;
vector<int> adj[maxn];

enum state{
    A,
    PATH,
    B
} vis[maxn];

int countA, countB = 0;
bool foundAns = false;
vector<int> path;

void checkAndPrintAns(){
    if(countA == countB && !foundAns){
        foundAns = true;
        cout << n - 2 * countA << " " << countA << endl;
        for(int i : path)
            cout << i + 1 << " ";
        cout << endl;
        for(int i = 0; i < n; i++)
            if(vis[i] == A)
                cout << i + 1 << " ";
        cout << endl;
        for(int i = 0; i < n; i++)
            if(vis[i] == B)
                cout << i + 1 << " ";
        cout << endl;
    }
}

void dfs(int u){
    for(int v : adj[u]){
        if(vis[v] == A){
            vis[v] = PATH;
            path.push_back(v);
            countA--;
            checkAndPrintAns();
            dfs(v);
            vis[v] = B;
            path.pop_back();
            countB++;
            checkAndPrintAns();
        }
    }
}

int main(){
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vis[0] = PATH;
    path.push_back(0);
    countA = n-1;
    checkAndPrintAns();
    dfs(0);
}