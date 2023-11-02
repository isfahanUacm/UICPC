#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const double epsilon = 1e-6;

int compare(const double a, const double b) {
  if (fabs(a - b) <= epsilon) return 0;
  if (a < b) {
    return -1;
  } else {
    return 1;
  }
}

int main() {
  double tf, tr;
  cin >> tf >> tr;
  double curr;
  cin >> curr;
  cout << 0 << endl;
  double prev = 0.0;
  while (cin >> curr) {
    int inte = (int)curr;
    double frac = curr - inte;
    int ans;
    if (curr > prev) {
      if (compare(frac, tr) == 1) {
        ans = inte + 1;
      } else {
        ans = inte;
      }
    } else {
      if (compare(frac, tf) == -1) {
        ans = inte;
      } else {
        ans = inte + 1;
      }
    }
    cout << ans << endl;
    prev = ans;
  }
  return 0;
}