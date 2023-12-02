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
  std::string first; std::cin >> first;
  int n; std::cin >> n;

  std::vector<std::string> all;
  std::vector<std::string> buckets[26];
  rep(i,0,n) {
    std::string w; std::cin >> w;
    all.push_back(w);
    buckets[w[0] - 'a'].push_back(w);
  }

  std::string next;
  for (std::string& x : buckets[first.back() - 'a']) {
    int end = x.back() - 'a';
    if (buckets[end].empty() || (end == first.back() - 'a' && buckets[end].size() == 1)) {
      std::cout << x << "!" << std::endl;
      return 0;
    }
    if (next.empty()) next = x;
  }
  if (next.empty()) {
    std::cout << "?" << std::endl;
  } else {
    std::cout << next << std::endl;
  }
}
