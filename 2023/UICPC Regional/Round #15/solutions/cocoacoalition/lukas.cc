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
  int64_t n, m, a;
  std::cin >> n >> m >> a;
  if (a * 2 < n * m) a = n * m - a;

  if (a % n == 0 || a % m == 0) {
    std::cout << 1 << std::endl;
    return 0;
  }

  int64_t b = n * m - a;
  rep(i,1,n) {
    if (b % i == 0 && b / i < m) {
      std::cout << 2 << std::endl;
      return 0;
    }
    if (a % i == 0 && a / i < m) {
      std::cout << 2 << std::endl;
      return 0;
    }
  }

  rep(i,1,m) {
    if (b % i == 0 && b / i < n) {
      std::cout << 2 << std::endl;
      return 0;
    }
    if (a % i == 0 && a / i < n) {
      std::cout << 2 << std::endl;
      return 0;
    }
  }

  std::cout << 3 << std::endl;
}
