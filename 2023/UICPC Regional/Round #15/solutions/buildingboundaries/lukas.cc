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
  int t; std::cin >> t;
  rep(i,0,t) {
    std::vector<std::array<int64_t, 2>> s(3);
    rep(i,0,3) {
      std::cin >> s[i][0] >> s[i][1];
    }

    int64_t best = 1LL<<62;
    rep(i,0,3) rep(j,0,i) {
      int other = 0;
      while (other == i || other == j) {
        ++other;
      }

      rep(k,0,2) rep(l,0,2) {
        int64_t width = s[i][k] + s[j][l];
        int64_t height = std::max(s[i][!k], s[j][!l]);

        rep(o,0,2) {
          int64_t mw = std::max(width, s[other][o]);
          int64_t mh = height + s[other][!o];
          best = std::min(best, mw * mh);

          mh = std::max(height, s[other][o]);
          mw = width + s[other][!o];
          best = std::min(best, mw * mh);
        }
      }
    }

    std::cout << best << std::endl;
  }

}
