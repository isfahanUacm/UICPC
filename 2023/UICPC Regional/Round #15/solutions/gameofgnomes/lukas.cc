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

int64_t comb(int64_t count) {
  return count * (count + 1) / 2;
}

int main() {
  int64_t n, m, k;
  std::cin >> n >> m >> k;
  int64_t full = n - m * (k - 1);
  if (full < 0) full = 0;
  if (full % k != 0) {
    full += k - full % k;
  }

  int64_t best_total = 0;
  rep(l,0,m) {
    if (full > n) {
      break;
    }

    int64_t total = 0;
    int64_t times = full / k;
    total += (times + 1) * full / 2;

    int64_t reminders = n - full;
    total += times * reminders;
    int64_t bigger = reminders % m;
    total += (reminders / m + 1) * comb(bigger);
    int64_t smaller = m - bigger;
    total += reminders / m * (bigger * smaller + comb(smaller));

    best_total = std::max(total, best_total);

    full += k;
  }

  std::cout << best_total << std::endl;
}
