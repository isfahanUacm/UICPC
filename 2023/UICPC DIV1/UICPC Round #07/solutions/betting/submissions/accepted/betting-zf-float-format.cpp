#include <bits/stdc++.h>

using namespace std;

int main() {
  float a, b;
  cin >> a;
  b = 100-a;
  cout << fixed << setprecision(10) << (a+b)/a << endl << (a+b)/b << endl;

  return 0;
}
