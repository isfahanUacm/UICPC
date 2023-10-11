#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if(n == 1) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 2; i * i < n; i++) {
    if(n % i == 0) {
      while(n % i == 0)
        n /= i;
      if(n == 1) {
        cout << "YES" << endl;
        return 0;
      }
      else {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
