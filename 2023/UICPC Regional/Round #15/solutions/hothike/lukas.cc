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
  int n; std::cin >> n;
  int best_t = 47, best_d = -1;
  std::vector<int> t(n);
  rep(i,0,n) std::cin >> t[i];

  rep(i,0,n - 2) {
    int cur = std::max(t[i], t[i + 2]);
    if (cur < best_t) {
      best_t = cur;
      best_d = i + 1;
    }
  }
  std::cout << best_d << " " << best_t << std::endl;
}
