#include <stdio.h>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN 200000
#define MAXK 1000000000
#define MAXC 1000000000

vector< pair<int, int> > adj[MAXN + 3];
long long ans;
long long dfs(int now, int parent) {
    long long current = 0;
    long long max1 = 0, max2 = 0;
    for (int i = 0; i < adj[now].size(); ++i) {
        if (adj[now][i].first == parent) {
            continue;
        }
        current = adj[now][i].second + dfs(adj[now][i].first, now);
        if (current >= max1) {
            max2 = max1;
            max1 = current;
        } else if (current > max2) {
            max2 = current;
        }
    }
    if (max1 + max2 > ans) {
        ans = max1 + max2;
    }
    return max1;
}

int main() {
    int n, k, u, v, c;
    
    long long sum = 0;
    scanf("%d%d", &n, &k);
    assert(1 <= n && n <= MAXN);
    assert(1 <= k && k <= MAXK);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        assert(1 <= u && u <= n);
        assert(1 <= v && v <= n);
        assert(u != v);
        assert(1 <= c && c <= MAXC);

        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
        sum += c;
    }

    if (k >= 2) {
        cout << sum << endl;
    } else {
        ans = 0;
        long long temp = dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}