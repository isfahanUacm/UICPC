#include <bits/stdc++.h>

using namespace std;

vector<int> L;

int main()
{
  for (int i = 100; i <= 999; i++) {
    string s = to_string(i);
    string r = s;
    reverse(r.begin(), r.end());
    L.push_back(stoi(s+r));
  }
  sort(L.begin(), L.end());

  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x;
    auto it = lower_bound(L.begin(), L.end(), x);
    int ans = 10000000;
    if (it != L.end()) {
      ans = *it;
    }
    if (it != L.begin()) {
      it--;
      if (x - *it <= ans - x) {
	ans = *it;
      }
    }
    cout << ans << endl;
  }

  
  return 0;
}
