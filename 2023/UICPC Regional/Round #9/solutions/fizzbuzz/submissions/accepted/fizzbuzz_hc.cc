#include <bits/stdc++.h>

using namespace std;

int main()
{
  int X, Y, N;
  cin >> X >> Y >> N;
  for (int i = 1; i <= N; i++) {
    int rx = i % X, ry = i % Y;
    if (rx && ry) {
      cout << i << endl;
      continue;
    }
    if (!rx) {
      cout << "Fizz";
    }
    if (!ry) {
      cout << "Buzz";
    }
    cout << endl;
      
  }
  
  return 0;
}
