#include <iostream>

using namespace std;

const char* solve() {
  char str[31];
  cin >> str;
  for (int i = 0; str[i]; ++i)
    if (str[i] == 's' && str[i+1] == 's')
      return "hiss";
  return "no hiss";
}

int main() {
  cout << solve() << endl;
  return 0;
}
