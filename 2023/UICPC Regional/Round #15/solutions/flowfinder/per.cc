#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    int n;
    scanf("%d", &n);
    vector<int> par(n);
    vector<ll> flow(n);
    for (int i = 1; i < n; ++i) scanf("%d", &par[i]), --par[i];
    for (auto &f: flow) scanf("%lld", &f);

    vector<vector<int>> children(n);
    for (int i = 1; i < n; ++i) 
        children[par[i]].push_back(i);

    vector<ll> minflow(n, 1);
    function<ll(int)> find_min = [&](int u) -> ll {
        ll c_sum = 0;
        for (int v: children[u])
            c_sum += find_min(v);
        return minflow[u] = max(1LL, max(flow[u], c_sum));
    };
    find_min(0);

    vector<ll> c_minrem(n), c_unknown(n), c_sum(n);
    for (int u = 0; u < n; ++u)
        for (int v: children[u]) {
            if (flow[v] <= 0) {
                c_minrem[u] += minflow[v];
                ++c_unknown[u];
            } else
                c_sum[u] += flow[v];
        }
    
    vector<int> Q;
    auto assign = [&](int u, ll f) {
        flow[u] = f;
        if (u) {
            --c_unknown[par[u]];
            c_minrem[par[u]] -= minflow[u];
            c_sum[par[u]] += flow[u];
        }
        Q.push_back(u);
    };
    
    auto check = [&](int u) {
        if (flow[u] <= 0 && c_unknown[u] == 0 && !children[u].empty())
            assign(u, c_sum[u]);
        if (flow[u] > 0 && c_unknown[u] > 0 &&
            (c_unknown[u] == 1 || flow[u] - c_sum[u] == c_minrem[u])) {
            for (int v: children[u])
                if (flow[v] <= 0)
                    assign(v, (flow[u] - c_sum[u]) * minflow[v] / c_minrem[u]);
        }
    };
    for (int u = 0; u < n; ++u) check(u);
    while (!Q.empty()) {
        int u = Q.back(); Q.pop_back();
        check(u);
        if (u > 0) check(par[u]);
    }

    bool impossible = false;
    for (int u = 0; !impossible && u < n; ++u)
        impossible |= c_unknown[u] || flow[u] <= 0 || !children[u].empty() && c_sum[u] != flow[u];
    
    if (impossible)
        printf("impossible\n");
    else
        for (int u = 0; u < n; ++u)
            printf("%lld\n", flow[u]);
}
