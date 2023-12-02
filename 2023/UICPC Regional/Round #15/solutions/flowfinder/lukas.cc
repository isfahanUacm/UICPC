// Solution by lukasP (Lukáš Poláček)
#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>

#define rep(i, a, b) for (__typeof(b) i = (a); (i) < (b); ++(i))

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int64_t> flow(n), min_flow(n);
  std::vector<std::vector<int>> g(n);
  rep(i, 1, n) {
    int p;
    scanf("%d", &p);
    g[p - 1].push_back(i);
  }
  rep(i, 0, n) { scanf("%lld", &flow[i]); }
  std::vector<int64_t> orig = flow;

  for (int i = n - 1; i >= 0; --i) {
    if (!g[i].empty() &&
        std::all_of(g[i].begin(), g[i].end(), [&flow](int x) { return flow[x] != 0; })) {
      flow[i] = std::accumulate(g[i].begin(), g[i].end(), 0ll,
                                [&flow](int64_t a, int x) { return a + flow[x]; });
    }
    if (flow[i] != 0) {
      min_flow[i] = flow[i];
    } else {
      for (int x : g[i]) {
        min_flow[i] += min_flow[x];
      }
      min_flow[i] = std::max(int64_t{1}, min_flow[i]);
    }
  }

  int broken = 0;
  rep(i, 0, n) {
    int64_t rest =
        flow[i] - std::accumulate(g[i].begin(), g[i].end(), 0ll,
                                  [&min_flow](int64_t a, int x) { return a + min_flow[x]; });
    if (rest == 0 ||
        std::count_if(g[i].begin(), g[i].end(), [&flow](int x) { return flow[x] == 0; }) == 1) {
      for (int x : g[i])
        if (flow[x] == 0) {
          flow[x] = min_flow[x] + rest;
        }
    }
    broken += orig[i] > 0 && flow[i] != orig[i] || flow[i] == 0;
  }

  if (broken > 0) {
    std::cout << "impossible" << std::endl;
  } else {
    rep(i, 0, n) {
      printf("%lld", flow[i]);
      if (i + 1 < n)
        printf(" ");
      else
        printf("\n");
    }
  }
}
