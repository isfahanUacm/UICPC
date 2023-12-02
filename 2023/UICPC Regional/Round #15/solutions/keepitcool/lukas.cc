//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <bitset>
#include <utility>
#include <list>
#include <numeric>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>

#define rep(i,a,b) for(__typeof(b) i=(a); (i)<(b); ++(i))

int main() {
  int n, m, s, d;
  std::cin >> n >> m >> s >> d;
  std::vector<int> c(s);
  std::vector<std::pair<int, int>> q;
  rep(i,0,s) {
    std::cin >> c[i];
    q.emplace_back(c[i], i);
  }

  std::sort(q.begin(), q.end());
  std::vector<std::pair<int, int>> res;
  int cold = 0;
  rep(i,0,s) {
    int cap = std::min(d - q[i].first, n);
    n -= cap;
    if (cap == 0) {
      cold += q[i].first;
    }
    res.emplace_back(q[i].second, cap);
  }

  if (cold >= m) {
    std::sort(res.begin(), res.end());
    rep(i,0,s) {
      std::cout << res[i].second;
      if (i + 1 < s) std::cout << " ";
      else std::cout << std::endl;
    }
  } else {
    std::cout << "impossible" << std::endl;
  }
}
