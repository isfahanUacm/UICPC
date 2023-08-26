// [BAPC'12] Digit sum
// by: Jan Kuipers
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>

using namespace std;

long long digit_sum (long long x) {
  int res=0;
  while (x > 0) { res += x%10; x /= 10; }
  return res;
}

long long total_sum (long long x) {
  int d = x%10;
  return x==0 ? 0 : d*(d-1)/2 + d*digit_sum(x/10) + 10*total_sum(x/10) + (x/10) * 45;
}

int main () {

  int runs;
  cin >> runs;

  while (runs--) {
    long long lo,hi;
    cin >> lo >> hi;
    cout << total_sum(hi+1) - total_sum(lo) << endl;
  }

  return 0;
}
