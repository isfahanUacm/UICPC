#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  cin >> n;
  if (n&1) cout << "still running" << endl;
  else {
    int tot = 0;
    while (cin >> a >> b) tot += b-a;
    cout << tot << endl;
  }
  return 0;
}
