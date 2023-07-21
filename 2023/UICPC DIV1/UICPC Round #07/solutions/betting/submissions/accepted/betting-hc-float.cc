#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, b;
  
  cin >> a;
  b = 100 - a;

  cout << fixed << setprecision(10) << float(100.0)/float(a) << endl;
  cout << fixed << setprecision(10) << float(100.0)/float(b) << endl;

  return 0;
}
