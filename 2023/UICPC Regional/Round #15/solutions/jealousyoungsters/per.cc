#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m, b, r;
    scanf("%d%d%d%d", &n, &m, &b, &r);
    if (m < n) {
        printf("impossible\n");
        return 0;
    }
    vector<vector<int>> totplay(n, vector<int>(m, 0));
    vector<vector<int>> firstplay(n, vector<int>(m, b+1));
    vector<pair<int, int>> curtoy(n, make_pair(-1, 0));
    for (int i = 0; i < r; ++i) {
        int s, k, t;
        scanf("%d%d%d", &s, &k, &t);
        --k; --t;
        if (t != -1) firstplay[k][t] = min(firstplay[k][t], s);
        auto p = curtoy[k];
        if (p.first != -1) totplay[k][p.first] += s - p.second;
        curtoy[k] = make_pair(t, s);
    }
    for (int i = 0; i < n; ++i)
        if (curtoy[i].first != -1)
            totplay[i][curtoy[i].first] += b - curtoy[i].second;
    vector<vector<int>> wish(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        iota(wish[i].begin(), wish[i].end(), 0);
        sort(wish[i].begin(), wish[i].end(), [&](int a, int b) {
                return firstplay[i][a] > firstplay[i][b];
            });
        assert(wish[i].size() == m);
    }
    vector<int> kid(m, -1), toy(n, 0);
    for (int _k = 0; _k < n; ++_k) {
        int k = _k;
        while (k >= 0) {
            assert(!wish[k].empty());
            int t = wish[k].back(); wish[k].pop_back();
            if (kid[t] < 0 || totplay[k][t] < totplay[kid[t]][t]) {
                toy[k] = t+1;
                swap(k, kid[t]);
            }
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%d\n", toy[i]);
}
