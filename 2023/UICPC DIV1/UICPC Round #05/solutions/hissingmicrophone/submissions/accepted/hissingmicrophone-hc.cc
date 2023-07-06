#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  cin >> s;

  if (s.find("ss") == string::npos) {
    cout << "no ";
  }
  cout << "hiss" << endl;
  return 0;
}
