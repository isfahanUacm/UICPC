#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
#define inf 0x7fffffff
const int maxn = 2510;
int vis[maxn];
int n;
int mp[maxn][maxn];
int dis[maxn];
class node {
public :
    int u, v;
} ans[maxn];

bool cmp(node a, node b) {
    if (a.u != b.u) {
        return a.u < b.u;
    } else {
        return a.v < b.u;
    }
}

void prim() {
    int i, j, k, tmp;
    for (i = 1; i <= n; i++) {
        dis[i] = inf;
    }
    dis[1] = 0;
    for (i = 1; i <= n; i++) {
        tmp = inf;
        for (j = 1; j <= n; j++) {
            //find the node with the smallest distance
            if (!vis[j] && tmp > dis[j]) {
                tmp = dis[j];
                k = j;
            }
        }
      // mark the visited node
        vis[k] = 1;
        for (j = 1; j <= n; j++) {
            //update the shortest distance
            if (!vis[j] && dis[j] > mp[k][j]) {
                dis[j] = mp[k][j];
                ans[j].u = min(k, j);
                ans[j].v = max(k, j);
            }
        }
    }
}

int main() {
    memset(vis, 0, sizeof(vis));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
           cin >> mp[i][j];
        }
    }
    prim();
    sort(ans + 1, ans + 1 + n, cmp);
    for (int i = 2; i <= n; i++) {
     cout <<  ans[i].u << " " <<  ans[i].v << "\n";
    }
    return 0;
}