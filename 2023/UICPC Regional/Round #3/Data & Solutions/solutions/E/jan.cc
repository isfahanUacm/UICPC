// [BAPC'12] Encoded Message
// by: Jan Kuipers
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main () {

  int runs;
  cin >> runs;

  while (runs--) {

    string s;
    cin >> s;

    int n = (int)sqrt(1.0*s.size());

    vector<string> m;
    for (int i=0; i<n; i++)
      m.push_back(s.substr(i*n,n));

    vector<string> r(m);
    for (int y=0; y<n; y++) {
      for (int x=0; x<n; x++)
        r[y][x] = m[x][n-1-y];
      cout << r[y];
    }

    cout << endl;
  }

  return 0;
}
