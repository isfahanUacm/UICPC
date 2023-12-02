//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
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
  int n; scanf("%d", &n);
  std::vector<std::bitset<5000>> orig(n);
  rep(i,1,n) {
    std::string s;
    std::cin >> s;
    rep(j,0,i) {
      orig[i][j] = s[j] - '0';
      orig[j][i] = !orig[i][j];
    }
  }

  std::vector<int> count(n);
  rep(i,0,n) {
    count[i] = n - 1 - orig[i].count();
  }

  std::vector<bool> winners(n, false);
  int current = 0, worst = 0;
  rep(i,0,n) {
    int best = -1;
    rep(j,0,n) if (!winners[j]) {
      if (best == -1 || count[j] < count[best]) {
        best = j;
      }
    }

    winners[best] = true;
    current += count[best];
    rep(j,0,n) if (!winners[j]) {
      --count[j];
    }
    worst = std::max(current, worst);
  }
  std::cout << worst << std::endl;
}
