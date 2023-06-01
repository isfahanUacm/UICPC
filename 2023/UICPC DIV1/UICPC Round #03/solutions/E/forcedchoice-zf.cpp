#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, p, s;
  cin >> n >> p >> s;

  while (s--) {
    int x, y, seen = 0;
    cin >> x;
    while (x--) {
      cin >> y;
      seen |= (y == p);
    }
    cout << (seen?"KEEP":"REMOVE") << endl;
  }
  return 0;
}
