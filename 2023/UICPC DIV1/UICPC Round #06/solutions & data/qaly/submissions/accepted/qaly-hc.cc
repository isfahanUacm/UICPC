#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int N;
  cin >> N;

  double ans = 0.0;
  for (int i = 0; i < N; i++) {
    double q, len;
    cin >> q >> len;
    ans += q*len;
  }
  cout << fixed << setprecision(3) << ans << endl;

  return 0;
}
