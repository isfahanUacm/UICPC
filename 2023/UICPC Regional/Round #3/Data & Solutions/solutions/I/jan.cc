// [BAPC'12] Integer lists
// by: Jan Kuipers
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <deque>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>

using namespace std;

int main () {

  int runs;
  cin >> runs;

  while (runs--) {
    string c,s;
    int n;
    cin >> c >> n >> s;
    for (int i=0; i<s.size(); i++)
      if (!isdigit(s[i])) s[i]=' ';

    istringstream ss(s);
    deque<int> x(n);
    for (int i=0; i<n; i++)
      ss>>x[i];

    int dir=0;
    for (int i=0; i<c.size(); i++)
      if (c[i]=='R') {
        dir=1-dir;
      }
      else {
        if (x.size()==0) {
          dir=-1;
          break;
        }
        if (dir==0)
          x.pop_front();
        else
          x.pop_back();
      }

    if (dir==-1) {
      cout << "error" << endl;
      continue;
    }

    if (dir==1)
      reverse(x.begin(),x.end());

    cout << "[";
    for (int i=0; i<x.size(); i++) {
      if (i>0) cout << ",";
      cout << x[i];
    }
    cout << "]" << endl;

  }

  return 0;
}
