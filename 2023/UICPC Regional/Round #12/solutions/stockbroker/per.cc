#include <bits/stdc++.h>
typedef long long ll;

int main(void) {
  ll money = 100, days, prev = 1<<30, cur;
  std::cin >> days;
  for (int i = 0; i < days; ++i, prev=cur) {
    std::cin >> cur;
    if (cur > prev)
      money += std::min(money/prev, 100000LL)*(cur-prev);
  }
  std::cout << money << std::endl;
  return 0;
}
