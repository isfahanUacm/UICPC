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
  std::string line; std::getline(std::cin, line);
  std::stringstream s(line);
  std::string trash;
  int count = 0; while (s >> trash) ++count;

  int n; std::cin >> n;
  std::vector<std::string> names(n);
  rep(i,0,n) std::cin >> names[i];

  int pos = 0;
  std::vector<std::string> teams[2];
  rep(i,0,n) {
    pos = (pos + count - 1) % names.size();
    teams[i & 1].push_back(names[pos]);
    names.erase(names.begin() + pos);
  }

  rep(k,0,2) {
    std::cout << teams[k].size() << std::endl;
    for (std::string& x : teams[k]) {
      std::cout << x << std::endl;
    }
  }
}
