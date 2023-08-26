// [BAPC'12] Black out
// by: Jan Kuipers
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <string>

using namespace std;

int main () {

  int runs;
  cin >> runs;

  while (runs--) {

    cout << "3 1 3 6" << endl;

    while (true) {
      string s;
      cin >> s;

      if (s == "GAME") break;

      int y1, x1, y2, x2;
      cin >> y1 >> x1 >> y2 >> x2;
      cout << 6-y2 << " " << 7-x2 << " " << 6-y1 << " " << 7-x1 << endl;
    }
  }

  return 0;
}
