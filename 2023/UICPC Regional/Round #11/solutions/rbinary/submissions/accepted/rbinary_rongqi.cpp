#include <iostream>
#include <vector>

using namespace std;

long long n;
int t;
vector<int> d;
vector<vector<long long> > f;

const long long m = 998244353LL;

int main() {
  cin >> n >> t;
  if (n == 0) {
    cout << 1 << endl;
    return 0;
  }
  d.push_back(0);
  while (n > 0) {
    d.push_back(n % 2);
    n = n / 2;
  }
  f = vector<vector<long long> >(d.size(), vector<long long>(t + 1, 0));
  f[0][0] = 1;
  for (int i = 1; i < d.size(); ++i) {
    for (int j = 0; j <= t; ++j) {
      for (int k = 0; k <= t; ++k) {
        if (j * 2 + d[i] - k > t) continue;
        if (j * 2 + d[i] - k < 0) continue;
        f[i][j] += f[i - 1][j * 2 + d[i] - k];
        f[i][j] = f[i][j] % m;
      }
    }
  }
  cout << f[d.size() - 1][0] << endl;
  return 0;
}