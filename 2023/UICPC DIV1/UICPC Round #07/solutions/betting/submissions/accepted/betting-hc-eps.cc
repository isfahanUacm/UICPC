#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, b;
  
  cin >> a;
  b = 100 - a;

  cout << fixed << setprecision(10) << 100.0/a + 9e-4 << endl;
  cout << fixed << setprecision(10) << 100.0/b - 9.9e-4 << endl;

  return 0;
}
