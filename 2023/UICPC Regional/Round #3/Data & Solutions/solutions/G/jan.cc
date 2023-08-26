// [BAPC'12] Good coalitions
// by: Jan Kuipers
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <iomanip>
#include <vector>

const int X = 150;

using namespace std;

int main () {

  int runs;
  cin >> runs;

  while (runs--) {
    int n;
    cin >> n;

    vector<int> x(n);
    vector<double> p(n);
    for (int i=0; i<n; i++) {
      cin >> x[i] >> p[i];
      p[i] /= 100;
    }

    vector<double> best(X+1, 0);
    best[0] = 1;

    for (int i=0; i<n; i++)
      for (int j=X; j>=x[i]; j--)
        best[j] = max(best[j], best[j-x[i]] * p[i]);

    double res=0;
    for (int i=X/2+1; i<=X; i++)
      res = max(res, best[i]);

    cout << setprecision(10) << 100 * res << endl;
  }

  return 0;
}
