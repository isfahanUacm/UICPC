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
long int vis[maxn];
long int n;
long int mp[maxn][maxn];
long int dis[maxn];
struct node {
    long int u, v;
} ans[maxn];

bool cmp(node a, node b) {
    if (a.u != b.u) {
        return a.u < b.u;
    } else {
        return a.v < b.u;
    }
}
void do1(int &k,int &j){
    k = j;
}
void prim() {
    int i, j, k, tmp;
    i = 1;
    while(i <= n) {
        dis[i] = inf;
        i++;
    }
    dis[1] = 0;
    i = 1;
    while(i <= n) {
        tmp = inf;
        int j = 1;
        while(j <= n) {
            if (!vis[j] && tmp > dis[j]) {
                tmp = dis[j];
                do1(k,j);
            }
            j++;
        }
        vis[k] = 1;
        j = 1;
        while(j <= n) {
            if (!vis[j] && dis[j] > mp[k][j]) {
                dis[j] = mp[k][j];
                ans[j].u = min(k, j);
                ans[j].v = max(k, j);
            }
            j++;
        }
        i++;
    }
}
void get1(int long &n){
    cin >> n;
}
void get2(int &i,int &j){
    scanf("%d", &mp[i][j]);
}
void do2(){
    int i = 2;
    while (i <= n) {
        printf("%d %d\n", ans[i].u, ans[i].v);
        i++;
    }
}
int main() {
    memset(vis, 0, sizeof(vis));
    get1(n);
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
             get2(i,j);
             j++;
        }
        i++;
    }
    prim();
    sort(ans + 1, ans + 1 + n, cmp);
    do2();
    return 0;
}