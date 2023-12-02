// Solution by lukasP (Lukáš Poláček)
#include <iostream>

const int32_t kMod = 1000000007;
int64_t pow(int64_t x, int32_t n) {
  if (n == 0) {
    return 1;
  }

  int64_t res = pow(x, n / 2);
  res = res * res % kMod;
  if ((n & 1) == 1) {
    res = res * x % kMod;
  }
  return res;
}

int main() {
  int32_t n, k;
  std::cin >> n >> k;
  int64_t res = 0;
  int64_t binom = 1;

  for (int i = 1; i <= k; ++i) {
    binom = binom * (k - i + 1) % kMod;
    binom = binom * pow(i, kMod - 2) % kMod;

    int64_t cur_count = pow(i - 1, n - 1) * i % kMod;
    cur_count = binom * cur_count % kMod;
    res = ((k - i) & 1) == 0 ? (res + cur_count) % kMod : (res - cur_count + kMod) % kMod;
  }

  std::cout << res << std::endl;
}
